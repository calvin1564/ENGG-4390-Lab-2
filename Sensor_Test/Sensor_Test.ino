#include <SparkFunBME280.h>
#include <SparkFunLSM6DS3.h>
#include <SPI.h>
#include <Wire.h>

LSM6DS3 IMU ( SPI_MODE, 10);
BME280 ATMOSPHERIC_SENSOR;

void setup(){
  Serial.begin(115200);
  delay(500);
  Wire.begin();
  Serial.println("Testing Sensor Connections");

  if(ATMOSPHERIC_SENSOR.beginI2C() != 1){
    Serial.println("Error connecting to Atmospheric Sensor via i2c, check connections");
  }
  else{
    Serial.println("Atmospheric sensor available!");
  }

  if(IMU.begin() != 0){
    Serial.println("Error connecting to the IMU via SPI at CS=10, check connections");
  }
  else{
    Serial.println("IMU Available!");
  }

}

void loop(){}
