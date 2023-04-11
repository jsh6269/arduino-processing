int buttonPin = 2, ledPin = 13;
int ledState = HIGH;     
int buttonState;             
int lastButtonState = LOW;   
unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 50;
void setup() {
  pinMode(buttonPin, INPUT);       //그냥 INPUT으로 되어있으면 회로에서는 PULLDOWN방식으로 연결되어야 한다.
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}
void loop() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState)
    lastDebounceTime = millis();
  if ((millis() - lastDebounceTime) > debounceDelay) 
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH)
        ledState = !ledState;
    }
  digitalWrite(ledPin, ledState);
  lastButtonState = reading;
}
