#define BTN_NONE 0

#define BTN_MUTE 1
#define BTN_VOL_UP 2
#define BTN_VOL_DOWN 3

#define BTN_UP  4
#define BTN_DOWN 5
#define BTN_SRC 6
#define BTN_PHONE 7



bool enableSerial = false;
int rightInputPin = A0;
int leftInputPin = A1;
int rightLedPin = A2;
int leftLedPin = A3;

void setup() {

  if (enableSerial)
  {
    Serial.begin(9600);
  }
  pinMode(rightLedPin, OUTPUT);
  pinMode(leftLedPin, OUTPUT);

}

void loop() {

  int pressedButton = getPressedButton();

  if (pressedButton == BTN_MUTE ||
      pressedButton == BTN_VOL_UP ||
      pressedButton == BTN_VOL_DOWN)
  {
    digitalWrite(leftLedPin, HIGH);
  }
  else
  {
    digitalWrite(leftLedPin, LOW);
  }

  if (pressedButton == BTN_PHONE ||
      pressedButton == BTN_SRC ||
      pressedButton == BTN_UP ||
      pressedButton == BTN_DOWN)
  {
    digitalWrite(rightLedPin, HIGH);
  }
  else
  {
    digitalWrite(rightLedPin, LOW);
  }
}


int getPressedButton() {

  int rightValue = analogRead(rightInputPin);
  int leftValue = analogRead(leftInputPin);

  if (enableSerial)
  {
    Serial.print("Right value: "); Serial.print(rightValue);  Serial.print("Left value: "); Serial.print(leftValue); Serial.println();
  }

  if (leftValue > 800 && leftValue < 850)
  {
    return BTN_MUTE;
  }
  else if (leftValue > 600 && leftValue < 650)
  {
    return BTN_VOL_UP;
  }
  else if (leftValue > -1 && leftValue < 10)
  {
    return BTN_VOL_DOWN;
  }

  if (rightValue > 930 && rightValue < 980)
  {
    return BTN_PHONE;
  }
  else if (rightValue > 800 && rightValue < 850)
  {
    return BTN_SRC;
  }
  else if (rightValue > 600 && rightValue < 650)
  {
    return BTN_UP;
  }
  else if (rightValue > -1 && rightValue < 10)
  {
    return BTN_DOWN;
  }

  return BTN_NONE;

}

