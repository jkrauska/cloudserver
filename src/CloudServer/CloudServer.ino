//Is debugging enabled?
#define __d3bug true

//What is the SDCard Pin? Standard for Ethernet Shield is 4.
#define __sdcardpin 4
//What is the IP? Splitted in 4 parts!
#define _0_ip 192
#define _1_ip 168
#define _2_ip 1
#define _3_ip 177

//Includes
#include <SPI.h> 
#include <SD.h>
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <util.h>
#include <stdlib.h>

//Variables
EthernetServer webserver_main = EthernetServer(atoi(ReadFile("/system/settings/PORT")));
EthernetServer webserver_cpanel = EthernetServer(atoi(ReadFile("/system/settings/CPPORT")));

void setup()
{
  setupSD();
  if (__d3bug)
  {
    Serial.begin(9600);
  }
}

void loop()
{
  EthernetClient pone = webserver_main.available();
  EthernetClient admin_pone = webserver_main.available();
  if (pone)
  {
    boolean currentLineIsBlank = true;
    while (pone.connected()) {
      if (pone.available()) {
        char c = pone.read();
        Serial.write(c);
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          pone.println("HTTP/1.1 200 OK");
          pone.println("Content-Type: text/html");
          pone.println("Connnection: close");
          pone.println();
          pone.println(ReadFile("/htdocs/index.htm"));
          break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);
    pone.stop();
  }
  if (admin_pone)
  {
    boolean currentLineIsBlank = true;
    while (admin_pone.connected()) 
    {
      if (admin_pone.available()) 
      {
        char c = admin_pone.read();
        Serial.write(c);
        if (c == '\n' && currentLineIsBlank) 
        {
          // send a standard http response header
          admin_pone.println("HTTP/1.1 200 OK");
          admin_pone.println("Content-Type: text/html");
          admin_pone.println("Connnection: close");
          admin_pone.println();
          admin_pone.println(ReadFile("/system/webpanel/index.htm"));
          break;
        }
        if (c == '\n') 
        {
          currentLineIsBlank = true;
        } 
        else if (c != '\r') 
        {
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);
    admin_pone.stop();
  }
}

void setupSD()
{
  pinMode(10, OUTPUT);
  SD.begin(__sdcardpin);
}

char* ReadFile(char cFile[])
{
  File FileToBuckingRead = SD.open(cFile);
  int numberoftexts = 0;
  char Buffer[33];
  
  if (!FileToBuckingRead)
  {
    return "404";
  }
  while (FileToBuckingRead.available())
  {
    char curcharacter = FileToBuckingRead.read();
    numberoftexts++;
    Buffer[numberoftexts - 1] = curcharacter;
  }
  Buffer[numberoftexts] = '\0';
  FileToBuckingRead.close();
  return Buffer;
}

