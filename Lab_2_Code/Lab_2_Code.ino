#include <SdFat.h>

//Declare Datalogging variables
SdFatSdioEX sdEx;
SdFile data_file;
#define BASE_FILE_NAME "TRIAL"
char filename[13] = BASE_FILE_NAME "00.csv";

// A comment to demonstrate git

void create_file(){
  /*
  Inspect and run this code. What does it do and why?
  */

  if (!sdEx.begin()){
    sdEx.initErrorHalt("SD Card Failed to Initialize");
  }

  const uint8_t BASE_FILE_NAME_SIZE = sizeof(BASE_FILE_NAME) - 1;

  while(sdEx.exists(filename)){
    if (filename[BASE_FILE_NAME_SIZE + 1] != '9'){
      filename[BASE_FILE_NAME_SIZE + 1]++;
    }
    else if (filename[BASE_FILE_NAME_SIZE] != '9'){
      filename[BASE_FILE_NAME_SIZE + 1] = '0';
      filename[BASE_FILE_NAME_SIZE]++;
    }
    else{
      Serial.println("SD Error: Can't Create Filename!");
    }
  }

  if(!data_file.open(filename, O_CREAT | O_WRITE | O_EXCL)){
    Serial.println("SD Error: Failed to open file");
  }
  else{
    delay(500);
    Serial.print("SD Card initialized, logging data in: ");
    Serial.println(filename);
    delay(500);
  }

  data_file.close();

}

void record_data(long timestamp, float AX, float AY, float AZ, float RX,
float RY, float RZ, float temperature, float humidity, float altitude,
float pressure){
  /*
  Inspect and run this code. What does it do and why?
  */

  if(!data_file.open(filename, FILE_WRITE)){
    Serial.println("Error opening file during record_data");
  }
  else{
    Serial.println("SAVING DATA");

    data_file.print(timestamp);
    data_file.write(',');
    data_file.print(AX);
    data_file.write(',');
    data_file.print(AY);
    data_file.write(',');
    data_file.print(AZ);
    data_file.write(',');
    data_file.print(RX);
    data_file.write(',');
    data_file.print(RY);
    data_file.write(',');
    data_file.print(RZ);
    data_file.write(',');
    data_file.print(temperature);
    data_file.write(',');
    data_file.print(humidity);
    data_file.write(',');
    data_file.print(altitude);
    data_file.write(',');
    data_file.print(pressure);    
    data_file.println();

  }
  data_file.close();
}

void setup() {
  Serial.begin(115200);
  create_file();
}

void loop() {


}
