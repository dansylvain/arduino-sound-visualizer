const int buttonPin = 13;
const int potPin = A0;
const int ledPins[] = {2, 3, 4, 5, 6, 7};
const int ledCount = 6;

int buttonState;
int lastButtonState = HIGH;
int mode = 0;

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    int val = Serial.parseInt();
    Serial.print("Reçu : ");
    Serial.println(val);
    // tu peux ajouter ton traitement ici avec val
  }

  // Lecture bouton
  buttonState = digitalRead(buttonPin);
  if (lastButtonState == HIGH && buttonState == LOW) {
    mode = (mode + 1) % 5;
    Serial.print("Mode : ");
    Serial.println(mode);
    delay(200); // anti-rebond simple
  }
  lastButtonState = buttonState;

  // Lecture potentiomètre
  int val = analogRead(potPin);


  int potValue = map(Serial.parseInt(), 0, 100, 0, 1023);


  // Comportement selon le mode
  if (mode == 0) {
    // Mode 0 : tout éteint
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(ledPins[i], LOW);
    }

  } else if (mode == 1) {
    // Mode 1 : allume LEDs selon le potentiomètre
    int seuil = 1023 / ledCount;
    for (int i = 0; i < ledCount; i++) {
      if (val > i * seuil) {
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }

  } else if (mode == 2) {
    // Mode 2 : clignotement
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
    delay(200);
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    delay(200);
  }  else if (mode == 3) {
  int vitesse = map(val, 0, 1023, 50, 500); // vitesse réglée par le pot

  // Aller
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(vitesse);
    digitalWrite(ledPins[i], LOW);
  }

  // Retour
  for (int i = ledCount - 2; i > 0; i--) { // on évite de rallumer les extrémités deux fois
    digitalWrite(ledPins[i], HIGH);
    delay(vitesse);
    digitalWrite(ledPins[i], LOW);
  }
} else if (mode == 4) {
    int seuil = 1023 / ledCount;
    for (int i = 0; i < ledCount; i++) {
      if (potValue > i * seuil) {
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }

  } 

}