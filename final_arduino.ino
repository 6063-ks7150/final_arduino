#include <ArduinoJson.h>
int v2 = 2;
int v3 = 3;
int v4 = 4;
int v5 = 6;
int v6 = 7;
int v7 = 8;
void sendData() {
  StaticJsonDocument<96> resJson;
  JsonObject data = resJson.createNestedObject("data");

  data["v2"] = v2;
  data["v3"] = v3;
  data["v4"] = v4;
  data["v5"] = v5;
  data["v6"] = v6;
  data["v7"] = v7;
  String resTxt = ""; 
  serializeJson(resJson, resTxt);

  Serial.println(resTxt);
}

void setup() {
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
Serial.begin(9600);

}

void loop() {
  v2 = digitalRead (2);
  v3 =  digitalRead (3);
  v4 =  digitalRead (4);
  v5 = digitalRead (5);
  v6 =  digitalRead (6);
  v7 =  digitalRead (7);
//  Serial.println (String (v2) + " " + (v3) + " " + (v4) + " ");
  delay(10);


   if (Serial.available() > 0) {
    int byteIn = Serial.read();
    if (byteIn == 0xAB) {
      Serial.flush();
      sendData();
    }
  }
}


