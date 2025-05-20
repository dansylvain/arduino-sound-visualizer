import sounddevice as sd
import numpy as np
import time
import serial

arduino = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2)


def get_volume(indata):
    rms = np.sqrt(np.mean(indata**2))
    volume = int(np.clip(rms * 1000, 0, 100))
    if volume < 5:
        volume = 0
    return volume

def audio_callback(indata, frames, time_info, status):
    volume = get_volume(indata)
    print("Volume:", volume)
    arduino.write(f"{volume}\n".encode())


with sd.InputStream(callback=audio_callback, channels=1, samplerate=44100, blocksize=1024):
    print("Écoute... Ctrl+C pour quitter")
    while True:
        time.sleep(0.1)