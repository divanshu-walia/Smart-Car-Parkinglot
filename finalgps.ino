#include <SoftwareSerial.h>
#include <stdio.h>
#include <TinyGPS.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define MAX 100
#define SIZE 8

/* This sample code demonstrates the normal use of a TinyGPS object.
   It requires the use of SoftwareSerial, and assumes that you have a
   4800-baud serial GPS device hooked up on pins 4(rx) and 3(tx).
*/

TinyGPS gps;
SoftwareSerial ss(4, 5);//(d1,d2)
SoftwareSerial da(13, 15);//(rx, tx)
const char* ssid = "abc";
const char* password = "12345678";

int data;

static void smartdelay(unsigned long ms);

WiFiServer server(80);
void setup()
{
  Serial.begin(115200);
  ss.begin(9600);
  da.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

}

void loop()
{
  float flat, flon;
  gps.f_get_position(&flat, &flon);
  Serial.println(flat, 8);
  Serial.println(flon, 8);
  
  String latitude,longitude;
  latitude=String(flat);
  longitude=String(flon);
  smartdelay(1000);

  data=da.read();
  if(data<=3 && data>=0)
  {
    
    if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status


      HTTPClient http;  //Declare an object of class HTTPClient

      http.begin("https://myprojiot.000webhostapp.com/www/putParkingPoint.php?lat=" + latitude + "&lng=" + longitude + "&space=" + data ); //Specify request destination
      Serial.println("https://myprojiot.000webhostapp.com/www/putParkingPoint.php?lat=" + latitude + "&lng=" + longitude + "&space=" + data );
      int httpCode = http.GET();//Send the request
      Serial.println("Server connected");
      if (httpCode > 0) { //Check the returning code

        String payload = http.getString();   //Get the request response payload
        Serial.print(payload);                     //Print the response payload
        Serial.print("payload successfull");

      }

      http.end();   //Close connection
    }
  
  
  }

}

static void smartdelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}
