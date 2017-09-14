#include <ESP8266WiFi.h>

//#include "password.h"

// add a password.h file in your folder with two variables
 const char* ssid = "iPhone";      //  your network SSID (name)
 const char* pass = "00001111";

int keyIndex = 0;                 // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

//WiFiServer server(8080); //at the moment we don't need a server

#define PIN 13

void setup() {
  
  Serial.begin(115200);      // initialize serial communication
  Serial.println("start");

  //connect to wifi
  Serial.println("check wifi");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  //check wifi-conexion status, while we are not connected... wait printing "."
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
 /* server.begin();                           // start the web server on port 80
 at the moment we don't need a server */
  
  printWifiStatus();                        // you're connected now, so print out the status

}

void loop() {
  // put your main code here, to run repeatedly:

}


void printWifiStatus() {

  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");

  // print where to go in a browser:
  //Serial.print("To see this page in action, open a browser to http://");
  //Serial.println(ip);

}
