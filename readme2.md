another thing written
voidFuncPtr //pointer to the function
remember pointers (*variable) pointer points to the other variable 
uint16_t ledState = HIGH;
 
void switchLEDState() {
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState);
}
 
void stepXAxis() {
  digitalWrite(LED_PIN, !state);
}
 
void checkAndRefresh(unsigned long previousMillis, unsigned long interval, voidFuncPtr fnToExecute) {
  unsigned long currentMillis = millis();
  // Intentially subtracting and comparing this way to ensure millis rollover doesn't cause problems
  if ((unsigned long) (currentMillis - *previousMillis) >= interval) {
    fnToExecute();
    *previousMillis = currentMillis;
  }
}
 
unsigned long ledPreviousMillis = 0;
unsigned long led2PreviousMillis = 0;
static const unsigned long ledInterval = 1000;
static const unsigned long led2Interval = 200;
static const uint8_t LED_PIN = 21;
static const uint8_t LED2_PIN = 22;
 
void loop() {
 
  checkAndRefresh(ledPreviousMillis, ledInterval, switchLEDState);
  checkAndRefresh(led2PreviousMillis, led2Interval, stepXAcis);