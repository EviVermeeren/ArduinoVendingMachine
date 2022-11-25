int coinDetector = A0;
float coinDetectorNumber = 0;

#define LEDCOIN 11
#define LEDCOLA 8
#define LEDZERO 9

#define buttonCola 5
#define buttonZero 4

boolean insert = false;

int lastButtonState;
int currentButtonState;

int lastButtonState2;
int currentButtonState2;

int yes = 0;

void setup() {
  pinMode(LEDCOIN, OUTPUT);
  pinMode(LEDCOLA, OUTPUT);
  pinMode(LEDZERO, OUTPUT);

  pinMode(buttonCola, INPUT_PULLUP);
  pinMode(buttonZero, INPUT_PULLUP);

  Serial.begin(9600);

  digitalWrite(buttonCola, HIGH);
  digitalWrite(buttonZero, HIGH);

  currentButtonState = digitalRead(buttonCola);
  currentButtonState2 = digitalRead(buttonZero);

}

void loop() {

  coinDetectorNumber = analogRead(coinDetector);

  if (coinDetectorNumber < 100) {
    analogWrite(LEDCOIN, HIGH);

    if (digitalRead(LEDCOIN == HIGH)) {
      yes = 1;
    } else if (digitalRead(LEDCOIN == LOW)) {
      yes = 0;
    }
  }

  switch (yes) {
    case 1:

      lastButtonState = currentButtonState;
      currentButtonState = digitalRead(buttonCola);

      lastButtonState2 = currentButtonState2;
      currentButtonState2 = digitalRead(buttonZero);

      if (lastButtonState == HIGH && currentButtonState == LOW) {
        if (digitalRead(LEDCOLA == LOW)) {
          digitalWrite(LEDCOLA, HIGH);
          Serial.println("COLAPLEASE");
          break;
        }
      } else if (lastButtonState2 == HIGH && currentButtonState2 == LOW) {
        if (digitalRead(LEDZERO == LOW)){
          digitalWrite(LEDZERO, HIGH);
          Serial.println("ZEROPLEASE");
          break;
        }
      }
      break;

    case 0:

      lastButtonState = currentButtonState;
      currentButtonState = digitalRead(buttonCola);

      lastButtonState2 = currentButtonState2;
      currentButtonState2 = digitalRead(buttonZero);

      if (lastButtonState == HIGH && currentButtonState == LOW) {
        Serial.println("NOMONEY");
      } else if (lastButtonState2 == HIGH && currentButtonState2 == LOW) {
        Serial.println("NOMONEY");
      }
      break;
  }


}
