#include <Arduino.h>

// Config Variables
const long intervall = 3600000;
const long wateringTime = 10000;

const int moistureMinimum = 500;

// System variables
long currentMillis = 0;
short moistureCounter = 0;

// DIGITAL IO variables
const byte pumpRelay = 3;

// ANALOG IO variables
const byte moistureSensor = A0;

void setup(){
  pinMode(pumpRelay, OUTPUT);
}

void ticker(){
// Initialize functions
  if (timer()){
    checkMoisture();
  }
}

bool timer(){
  if (millis() == currentMillis + intervall){
    currentMillis = millis();
    return true;
  } else {
    return false;
  }
}

void checkMoisture(){
// Use moisture sensor to check soil
  int actualMoistureLevel = analogRead(moistureSensor);
  if (actualMoistureLevel < moistureMinimum){
    if (moistureCounter > 3){
      activatePump();
    } else {
      moistureCounter++;
    }
  }
}

void activatePump(){
// activater Pump for wateringTime milliseconds
  moistureCounter = 0;
  // TODO: Activate pump and figure out how to measure time
}

void loop(){

}




/*
const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data

String recievedData = "";
String langDuration = "Duration: ";

boolean newData = false;
boolean blockRead = false;

int dataNumber = 0;             // new for this version
int pump = 13;
int duration = 0;
int secondTimer = 0;
unsigned long interval = 1000;

unsigned long startTimer = 0;
unsigned long curremntTimer = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
  pinMode(pump, OUTPUT);
}

void secondCounter() {
  if ((millis() - curremntTimer) > interval){
    secondTimer ++;
    Serial.println(secondTimer);
    curremntTimer = millis();
  }
}

int getWaterDuration() {
  int dataNumber = 0;             // new for this version
  dataNumber = recievedData.toInt();   // new for this version
  String toPrintDuration = langDuration + dataNumber;
  Serial.println(toPrintDuration);
  return dataNumber;
}

void readData() {
  if (Serial.available() > 0) {
    Serial.println("Data recieved ...");
    recievedData = Serial.readString();
    duration = getWaterDuration();
    newData = true;
    }
  }

void recvWithEndMarker() {
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;

  if (Serial.available() > 0 && blockRead == false) {
    Serial.println("Get new data");
    blockRead = true;
    rc = Serial.read();
    if (rc != endMarker) {
      Serial.println("Read new data ...");
      String langRc = "RC data: ";
      String toPrintRc = langRc + rc;
      Serial.println(toPrintRc);
      receivedChars[ndx] = rc;
      ndx++;
      if (ndx >= numChars) {
          ndx = numChars - 1;
      }
    } else {
        Serial.println("End of data ...");
        receivedChars[ndx] = '\0'; // terminate the string
        ndx = 0;
        blockRead = false;
    }
    newData = true;

    //duration = getWaterDuration();
  }
}

void startWatering() {
  if (newData == true) {
    digitalWrite(pump, HIGH);
    startTimer = millis();
    newData = false;
    Serial.println("---- Pump Started ----");
    secondTimer = 0;
    }
}

void stopWatering() {
  //if (digitalRead(pump) == HIGH && (millis() > (startTimer + duration))){
  if (digitalRead(pump) == HIGH && millis() > startTimer + 5000){    
    digitalWrite(pump, LOW);
    Serial.println("...");
    Serial.println("...");
    Serial.println("---- Pump stopped ----");
  } 
  else if (digitalRead(pump) == HIGH) {
  }
}

void loop() {
  // recvWithEndMarker();
  readData();
  startWatering();
  stopWatering();
  secondCounter();
}
*/