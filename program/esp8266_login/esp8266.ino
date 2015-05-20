//Working with original firmware of esp8266
//Need to add given library for successfull compilation.

#include <SoftwareSerial.h>

#include "ESP8266.h"

SoftwareSerial esp8266Serial = SoftwareSerial(10, 11);
ESP8266 wifi = ESP8266(esp8266Serial);
char statConnection = GET_REQUEST;
#define DEBUG true

void setup()
{
    Serial.begin(9600);

    // ESP8266
    esp8266Serial.begin(9600);
    wifi.begin();
    wifi.setTimeout(1000);

    /****************************************/
    /******       Basic commands       ******/
    /****************************************/
    // test
    Serial.print("test: ");
    Serial.println(getStatus(wifi.test()));
    
    // restart
    /*Serial.print("restart: ");
    Serial.println(getStatus(wifi.restart()));*/
    Serial.print("ESP8266 Config\n");
    // getVersion
    char version[16] = {};
    Serial.print("getVersion: ");
    Serial.print(getStatus(wifi.getVersion(version, 16)));
    Serial.print(" : ");
    Serial.println(version);

    // deepSleep
    /*Serial.print("deepSleep: ");
    Serial.println(wifi.deepSleep(5000));*/

    // setBaudrate
    /*Serial.print("setBaudrate: ");
    Serial.println(wifi.setBaudrate(9600));*/

    /****************************************/
    /******        WiFi commands       ******/
    /****************************************/
    // setWifiMode
    Serial.print("setWifiMode: ");
    Serial.println(getStatus(wifi.setMode(ESP8266_WIFI_BOTH)));

    // getWifiMode
    ESP8266WifiMode mode;
    Serial.print("getWifiMode: ");
    Serial.println(getStatus(wifi.getMode(&mode)));
    Serial.print("Mode :");
    Serial.println(mode);
    // joinAP
/*    Serial.print("joinAP: ");
    Serial.println(getStatus(wifi.joinAP("RatneshNet", "Libra1919")));*/

    // getAP
    /*char ap[32] = {};
    Serial.print("getAP: ");
    Serial.print(getStatus(wifi.getAP(ap)));
    Serial.print(" : ");
    Serial.println(ap);*/

    // quitAP
    /*Serial.print("quitAP: ");
    Serial.println(getStatus(wifi.quitAP()));*/

    // setAPConfiguration
    Serial.print("setAPConfiguration: ");
    Serial.println(getStatus(wifi.setAPConfiguration("esp", "12345678", 10, ESP8266_ENCRYPTION_WPA_WPA2_PSK)));
    //wifi.restart();

    // getAPConfiguration
    char ssid[32] = {};
    char password[63] = {};
    uint8_t channel;
    ESP8266Encryption encryption;
    Serial.print("getAPConfiguration: ");
    Serial.print(getStatus(wifi.getAPConfiguration(ssid, password, channel, encryption)));
    Serial.print(" : ");
    Serial.print(ssid);
    Serial.print(" - ");
    Serial.print(password);
    Serial.print(" - ");
    Serial.print(channel);
    Serial.print(" - ");
    Serial.println(encryption);

    // setDHCP
    /*Serial.print("setDHCP STA: ");
    Serial.println(getStatus(wifi.setDHCP(ESP8266_WIFI_STATION, false)));
    Serial.print("setDHCP AP: ");
    Serial.println(getStatus(wiXfi.setDHCP(ESP8266_WIFI_ACCESSPOINT, true)));*/

    // setMAC
    /*byte mac[6] = {0x11, 0x11, 0x11, 0x11, 0x11, 0x11};
    Serial.print("setMAC AP: ");
    Serial.println(getStatus(wifi.setMAC(ESP8266_WIFI_ACCESSPOINT, mac)));*/

    // getMAC
    /*mac[6] = {};
    Serial.print("getMAC STA: ");
    Serial.print(getStatus(wifi.getMAC(ESP8266_WIFI_STATION, mac)));
    Serial.print(" : ");
    for (uint8_t i = 0; i < 6; i++) {
      Serial.print(mac[i], HEX);
      if (i < 5)
        Serial.print(":");
    }
    Serial.println();
    Serial.print("getMAC AP: ");
    Serial.print(getStatus(wifi.getMAC(ESP8266_WIFI_ACCESSPOINT, mac)));
    Serial.print(" : ");
    for (uint8_t i = 0; i < 6; i++) {
      Serial.print(mac[i], HEX);
      if (i < 5)
        Serial.print(":");
    }
    Serial.println();*/

    // setIP
    /*IPAddress ipAP = IPAddress(10, 0, 4, 1);
    Serial.print("setIP AP: ");
    Serial.print(getStatus(wifi.setIP(ESP8266_WIFI_ACCESSPOINT, ipAP)));
    Serial.print(" : ");
    Serial.println(ipAP);*/

    // getIP
+    /*IPAddress ip;
    Serial.print("getIP STA: ");
    Serial.print(getStatus(wifi.getIP(ESP8266_WIFI_STATION, ip)));
    Serial.print(" : ");
    Serial.println(ip);
    Serial.print("getIP AP: ");
    Serial.print(getStatus(wifi.getIP(ESP8266_WIFI_ACCESSPOINT, ip)));
    Serial.print(" : ");
    Serial.println(ip);*/

    /****************************************/
    /******       TCP/IP commands      ******/
    /****************************************/
    // connect
    /*Serial.print("connect: ");
    Serial.println(getStatus(wifi.connect(ESP8266_PROTOCOL_TCP, IPAddress(192,168,4,100), 4000)));*/

    // send
    /*Serial.print("send: ");
    Serial.println(getStatus(wifi.send("Hello World\n")));*/

    // close
    /*Serial.print("close: ");
    Serial.println(getStatus(wifi.close()));*/

    // setMultipleConnections
    Serial.print("setMultipleConnections: ");
    Serial.println(getStatus(wifi.setMultipleConnections(true)));

    // getMultipleConnections
    /*bool multipleConnections;
    Serial.print("getMultipleConnections: ");
    Serial.print(getStatus(wifi.getMultipleConnections(multipleConnections)));
    Serial.print(" : ");
    Serial.println(multipleConnections);*/

    // createServer
    Serial.print("createServer: ");
    Serial.println(getStatus(wifi.createServer(80)));

    // deleteServer
/*    Serial.print("deleteServer: ");
    Serial.println(getStatus(wifi.deleteServer()));*/

    // setServerTimeout
    /*Serial.print("setServerTimeout: ");
    Serial.println(getStatus(wifi.setServerTimeout(10)));*/

    // getServerTimeout
    /*unsigned int timeout;
    Serial.print("getServerTimeout: ");
    Serial.print(getStatus(wifi.getServerTimeout(timeout)));
    Serial.print(" : ");
    Serial.println(timeout);*/
}

void loop()
{
#if 0
  //send command via serial monitor
   if (esp8266Serial.available())
    Serial.write(esp8266Serial.read()); 
   if (Serial.available())
    esp8266Serial.write(Serial.read());
    
   if(esp8266Serial.available()) // check if the esp is sending a message 
  {
    
    while(esp8266Serial.available())
    {
      // The esp has data so display its output to the serial window 
      char c = esp8266Serial.read(); // read the next character.
      Serial.write(c);
    }
    
    if(esp8266Serial.find("+IPD,"))
    {
     delay(1000);
 
     int connectionId = esp8266Serial.read()-48; // subtract 48 because the read() function returns 
                                           // the ASCII decimal value and 0 (the first decimal number) starts at 48
     
     String webpage = "";
 
     String cipSend = "AT+CIPSEND=";
     cipSend += connectionId;
     cipSend += ",";
     cipSend +=webpage.length();
     cipSend +="\r\n";
     
     sendData(cipSend,1000,DEBUG);
     sendData(webpage,1000,DEBUG);
     
     webpage="<button>LED2</button>";
     
     cipSend = "AT+CIPSEND=";
     cipSend += connectionId;
     cipSend += ",";
     cipSend +=webpage.length();
     cipSend +="\r\n";
     
     sendData(cipSend,1000,DEBUG);
     sendData(webpage,1000,DEBUG);
 
     String closeCommand = "AT+CIPCLOSE="; 
     closeCommand+=connectionId; // append connection id
     closeCommand+="\r\n";
     
     sendData(closeCommand,3000,DEBUG);
    }
  } 
#else
  if (statConnection == GET_REQUEST)
  {
    if(esp8266Serial.available()) // check if the esp is sending a message 
    {
      statConnection = GET_REQUEST;
      /*
      while(esp8266Serial.available())
      {
        // The esp has data so display its output to the serial window 
        char c = esp8266Serial.read(); // read the next character.
        Serial.write(c);
      } */
      
      if(esp8266Serial.find("+IPD,"))
      {
       delay(1000);
   
       int connectionId = esp8266Serial.read()-48; // subtract 48 because the read() function returns 
                                             // the ASCII decimal value and 0 (the first decimal number) starts at 48
       
       String webpage = "<h1>Hello</h1><h2>World!</h2><button>LED1</button>";
       String cipSend = "AT+CIPSEND=";
       cipSend += connectionId;
       cipSend += ",";
       cipSend +=webpage.length();
       cipSend +="\r\n";
       
       sendData(cipSend,1000,DEBUG);
       sendData(webpage,1000,DEBUG);
/*
       webpage = "<head><script language=\"JavaScript\">function createJSON(){";
       cipSend = "AT+CIPSEND=";
       cipSend += connectionId;
       cipSend += ",";
       cipSend +=webpage.length();
       cipSend +="\r\n";
       
       sendData(cipSend,1000,DEBUG);
       sendData(webpage,1000,DEBUG);

       webpage = "var JSONObj = '{\"SSID\":\"' + document.getElementById(\"SSID\").value +'\",\"passwd\":\"' + document.getElementById(\"passwd\").value";
       cipSend = "AT+CIPSEND=";
       cipSend += connectionId;
       cipSend += ",";
       cipSend +=webpage.length();
       cipSend +="\r\n";
       
       sendData(cipSend,1000,DEBUG);
       sendData(webpage,1000,DEBUG);

       webpage = "+ '\"}';document.write(JSONObj);}</script></head>";
       cipSend = "AT+CIPSEND=";
       cipSend += connectionId;
       cipSend += ",";
       cipSend +=webpage.length();
       cipSend +="\r\n";
       
       sendData(cipSend,1000,DEBUG);
       sendData(webpage,1000,DEBUG);
  */
       webpage = "<form name=\"login\" method=\"post\" accept-charset=\"utf-8\"><input type=\"text\" id=\"SSID\" name=\"SSID\" placeholder=\"your router SSID\">";
       cipSend = "AT+CIPSEND=";
       cipSend += connectionId;
       cipSend += ",";
       cipSend +=webpage.length();
       cipSend +="\r\n";
       
       sendData(cipSend,1000,DEBUG);
       sendData(webpage,1000,DEBUG);
       
       webpage="<label for=\"passwd\">Password</label> <input type=\"password\" id=\"passwd\" name=\"password\" placeholder=\"password\" required>";
       
       cipSend = "AT+CIPSEND=";
       cipSend += connectionId;
       cipSend += ",";
       cipSend +=webpage.length();
       cipSend +="\r\n";
       
       sendData(cipSend,1000,DEBUG);
       sendData(webpage,1000,DEBUG);
  
       webpage="<div id=\"lower\"><input type=\"checkbox\"><label class=\"check\" for=\"checkbox\">Keep me logged in</label><input id=\"btnClickMe\" type=\"submit\" value=\"Login Here\" onclick=\"createJSON()\" /></div></form>";
       
       cipSend = "AT+CIPSEND=";
       cipSend += connectionId;
       cipSend += ",";
       cipSend +=webpage.length();
       cipSend +="\r\n";
       
       sendData(cipSend,1000,DEBUG);
       sendData(webpage,1000,DEBUG);
   
       String closeCommand = "AT+CIPCLOSE="; 
       closeCommand+=connectionId; // append connection id
       closeCommand+="\r\n";
       
       sendData(closeCommand,3000,DEBUG);
       statConnection = GET_AUTHENTIC;
      }
    }
    esp8266Serial.flush();
  }

if (statConnection == GET_AUTHENTIC)
  {
    ////////////////
    if(esp8266Serial.available()) // check if the esp is sending a message 
    {
      statConnection = CONNECTED;
      /*
      while(esp8266Serial.available())
      {
        // The esp has data so display its output to the serial window 
        char c = esp8266Serial.read(); // read the next character.
        Serial.write(c);
      } */
      Serial.println("Getting submit form.");

      if(esp8266Serial.find("SSID"))
      {
       delay(1000);
       int connectionId = esp8266Serial.read()-48; // subtract 48 because the read() function returns 
                                             // the ASCII decimal value and 0 (the first decimal number) starts at 48    
      Serial.println("Form found: ");
      Serial.print("SSID: ");
      while(1)
      {
        // The esp has data so display its output to the serial window 
        char c = esp8266Serial.read(); // read the next character.
        if(c == '&')
        {
          break;
        }
        Serial.write(c);
      }
      while(1)
      {
        char c = esp8266Serial.read(); // read the next character.
        if(c == '=')
        {
          break;
        }
      }
      Serial.write('\n');
      Serial.print("password: ");
      while(1)
      {
      // The esp has data so display its output to the serial window 
      char c = esp8266Serial.read(); // read the next character.
      if(c == -1)
      {
        break;
      }
      Serial.write(c);
      }
      Serial.println("Submit complete.!!!");  
    }
    }
  }
  \

    /****************************************/
    /******        WiFi commands       ******/
    /****************************************/
    // getConnectedStations
    /*ESP8266Station stations[5];
    unsigned int stationCount;
    Serial.print("getConnectedStations: ");
    Serial.print(getStatus(wifi.getConnectedStations(stations, stationCount, 5)));
    Serial.print(" : ");
    Serial.println(stationCount);
    for (uint8_t i = 0; i < stationCount; i++) {
      Serial.print(" - ");
      Serial.print(stations[i].ip);
      Serial.print(" - ");
      for (uint8_t j = 0; j < 6; j++) {
        Serial.print(stations[i].mac[j], HEX);
        if (j < 5)
          Serial.print(":");
      }
      Serial.println();
    }
    delay(5000);*/

    /****************************************/
    /******       TCP/IP commands      ******/
    /****************************************/
    // getConnectionStatus
    /*ESP8266ConnectionStatus connectionStatus;
    ESP8266Connection connections[5];
    unsigned int connectionCount;
    Serial.print("getConnectionStatus: ");
    Serial.print(getStatus(wifi.getConnectionStatus(connectionStatus, connections, connectionCount)));
    Serial.print(" : ");
    Serial.println(connectionCount);
    for (int i = 0; i < connectionCount; i++) {
      Serial.print(" - Connection: ");
      Serial.print(connections[i].id);
      Serial.print(" - ");
      Serial.print(getProtocol(connections[i].protocol));
      Serial.print(" - ");
      Serial.print(connections[i].ip);
      Serial.print(":");
      Serial.print(connections[i].port);
      Serial.print(" - ");
      Serial.println(getRole(connections[i].role));
    }
    delay(5000);*/


    // read data
    /*unsigned int id;
    int length;
    int totalRead;
    char buffer[11] = {};

    if ((length = wifi.available()) > 0) {
      id = wifi.getId();
      totalRead = wifi.read(buffer, 10);

      if (length > 0) {
        Serial.print("Received ");
        Serial.print(totalRead);
        Serial.print("/");
        Serial.print(length);
        Serial.print(" bytes from client ");
        Serial.print(id);
        Serial.print(": ");
        Serial.println((char*)buffer);
      }
    }*/
#endif
}

String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    
    esp8266Serial.print(command); // send the read character to the esp8266
    
    long int time = millis();
    
    while( (time+timeout) > millis())
    {
      while(esp8266Serial.available())
      {
        // The esp has data so display its output to the serial window 
        char c = esp8266Serial.read(); // read the next character.
        response+=c;
      }  
    }
    
    if(debug)
    {
      Serial.print(response);
    }
    
    return response;
}

String getStatus(bool status)
{
    if (status)
        return "OK";

    return "KO";
}

String getStatus(ESP8266CommandStatus status)
{
    switch (status) {
    case ESP8266_COMMAND_INVALID:
        return "INVALID";
        break;

    case ESP8266_COMMAND_TIMEOUT:
        return "TIMEOUT";
        break;

    case ESP8266_COMMAND_OK:
        return "OK";
        break;

    case ESP8266_COMMAND_NO_CHANGE:
        return "NO CHANGE";
        break;

    case ESP8266_COMMAND_ERROR:
        return "ERROR";
        break;

    case ESP8266_COMMAND_NO_LINK:
        return "NO LINK";
        break;

    case ESP8266_COMMAND_TOO_LONG:
        return "TOO LONG";
        break;

    case ESP8266_COMMAND_FAIL:
        return "FAIL";
        break;

    default:
        return "UNKNOWN COMMAND STATUS";
        break;
    }
}

String getRole(ESP8266Role role)
{
    switch (role) {
    case ESP8266_ROLE_CLIENT:
        return "CLIENT";
        break;

    case ESP8266_ROLE_SERVER:
        return "SERVER";
        break;

    default:
        return "UNKNOWN ROLE";
        break;
    }
}

String getProtocol(ESP8266Protocol protocol)
{
    switch (protocol) {
    case ESP8266_PROTOCOL_TCP:
        return "TCP";
        break;

    case ESP8266_PROTOCOL_UDP:
        return "UDP";
        break;

    default:
        return "UNKNOWN PROTOCOL";
        break;
    }
}      
