//Is debugging enabled?
#define __d3bug true
//What is the SDCard Pin? Standard for Ethernet Shield is 4.
#define __sdcardpin 4

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
const char HTDocsRegular[ ] = "/htdocs/";
const char HTDocsCPanel[ ] = "/system/webpanel/";


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
    int numberoftexts = 0;
    boolean mstrlck = false;
    boolean lock = true;
    char Buffer[129];
    while (pone.connected()) 
    {
      if (pone.available()) 
      {
        char c = pone.read();
        if (c == ' ' && !mstrlck)
        {
          lock = false;        
        }
        else if (c != '\n' && !lock)
        {
          numberoftexts++;
          Buffer[numberoftexts - 1] = c;
        }
        else if (!lock)
        {
          lock = true;
          mstrlck = true;
          Buffer[numberoftexts] = '\0';
        }
        
        String filesource = Buffer;
        filesource = filesource.substring(4);
        String fileext = filesource;
        fileext = fileext.substring(fileext.length() - 3);
        char filesourcefix[filesource.length() + 1];
        filesource.toCharArray(filesourcefix, filesource.length() + 1);
        char CompleteFileSource[filesource.length() + sizeof(HTDocsRegular)];
        strcpy(CompleteFileSource, HTDocsRegular);
        strcat(CompleteFileSource, filesourcefix);
        
        if (c == '\n' && currentLineIsBlank) 
        {
          // send a standard http response header
          pone.println("HTTP/1.1 200 OK");
          pone.println("Server: CloudServer (Arduino - Unix)");
          if (fileext == "htm")
          {
            pone.println("Content-Type: text/html");
          }
          pone.println("Connnection: close");
          pone.println();
          pone.println(ReadFile(CompleteFileSource));
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
    pone.stop();
  }
  if (admin_pone)
  {
    boolean currentLineIsBlank = true;
    int numberoftexts = 0;
    boolean mstrlck = false;
    boolean lock = true;
    char Buffer[129];
    while (admin_pone.connected()) 
    {
      if (admin_pone.available()) 
      {
        char c = admin_pone.read();
        if (c == ' ' && !mstrlck)
        {
          lock = false;        
        }
        else if (c != '\n' && !lock)
        {
          numberoftexts++;
          Buffer[numberoftexts - 1] = c;
        }
        else if (!lock)
        {
          lock = true;
          mstrlck = true;
          Buffer[numberoftexts] = '\0';
        }
        
        String filesource = Buffer;
        filesource = filesource.substring(4);
        String fileext = filesource;
        fileext = fileext.substring(fileext.length() - 3);
        char filesourcefix[filesource.length() + 1];
        filesource.toCharArray(filesourcefix, filesource.length() + 1);
        char CompleteFileSource[filesource.length() + sizeof(HTDocsCPanel)];
        strcpy(CompleteFileSource, HTDocsCPanel);
        strcat(CompleteFileSource, filesourcefix);
        
        if (c == '\n' && currentLineIsBlank) 
        {
          // send a standard http response header
          admin_pone.println("HTTP/1.1 200 OK");
          admin_pone.println("Server: CloudServer (Arduino - Unix)");
          if (fileext == "htm")
          {
            admin_pone.println("Content-Type: text/html");
          }
          admin_pone.println("Connnection: close");
          admin_pone.println();
          admin_pone.println(ReadFile(CompleteFileSource));
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
    return "404 File Not Found";
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

