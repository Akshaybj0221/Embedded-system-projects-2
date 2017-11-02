#include <SoftwareSerial.h>
 #include <stdlib.h>
 #include <string.h>
SoftwareSerial mySerial(2, 3);

void setup() {
  mySerial.begin(9600);               // the GPRS baud rate
  Serial.begin(9600);
}

void loop() 
{
  char pos;
  int Status=0;
  char c = '\0';
  char p = '\0';
  int count = 0;
  char ma[20] = "";
  char msg[50] = "";
  
  if (mySerial.available()) 
  {
    c = (char)mySerial.read();
    if (c >= 48 && c <= 57)
    {
      delay(200);
      mySerial.println("AT+CMGL=\"REC UNREAD\"");
      delay(200);
      int j = 0, n = 0;
      boolean moniter = 0;
      while (moniter == 0)
      {
        p = (char)mySerial.read();
        if (p == 10 || (p >= 32 && p <= 125))
        {
          
          if (p == 'O')
            moniter = 1;
          else if (p == '\"')
            count ++;
          if (count == 5) {
            ma[j] = p;
            j++;
          }
          else if (count == 10) {
            msg[n] = p;
            n++;
          }
          else if (count == 2 && p>48) {
            pos = p;
          }
            
          else;
        }
      }
     
      Serial.println(ma);
      Serial.println(msg);
       Serial.println(pos);
      if(strstr(ma,"7835020049"))
      {
        Status=1;
      }
      delete_SMS(pos,Status);
      if(strstr(msg,"Job"))      //check message and take action
      {
        Serial.print("GOoD");
      }
    }
  }
}



void delete_SMS(char pos, int Status)      //pos is location of current SMS in sim
{
  if (Status == 0)
  {
    mySerial.print("AT+CMGD=");
    mySerial.println(pos);
    delay(200);
  }
  if (pos >= 49 && pos <= 52)
  {
    pos=pos+1
    mySerial.print("AT+CMGD=");
    mySerial.println((char)pos);
    delay(200);
  }
  if (pos > 53)
  {
    mySerial.println("AT+CMGD=1");
    delay(200);
  }
}
