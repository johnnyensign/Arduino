/*
  Web Server
 
 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield. 
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)
 
 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 */

#include <SPI.h>
#include <EthernetV2_0.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 
  0x00, 0x05, 0x02, 0x45, 0x15, 0x15 };
IPAddress ip(192,168,1,45);
byte gateway[] = { 192, 168, 1, 1 };                   // internet access via router
byte subnet[] = { 255, 255, 255, 0 };                  //subnet mask
EthernetServer server(80);                             //server port     
String readString;
EthernetClient client;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  pinMode(2, OUTPUT);
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  // Create a client connection
  client = server.available();
  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();

        //read char by char HTTP request
        if (readString.length() < 100) {
          //store characters to string
          readString += c;
          //Serial.print(c);
        }

        //if HTTP request has ended
        if (c == '\n') {          
          Serial.println(readString); //print to serial monitor for debuging

            client.println("HTTP/1.1 200 OK"); //send new page
          client.println("Content-Type: text/html");
          client.println();     
          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
          client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
          client.println("<link rel='stylesheet' type='text/css' href='http://bootswatch.com/cyborg/bootstrap.min.css' />");
          
          client.println("<br><br>");
          client.println("<p class=\"text-center\">");
          
          if (readString.indexOf("?reboot") >0){
            reboot();
          } else {
            client.println("<a class=\"btn btn-primary btn-lg\" href=\"/?reboot\"\">Reboot</a><br />");   
          }
          
          client.println("</p>");
          
          client.println("</BODY>");
          client.println("</HTML>");

          delay(1);
          //stopping client
          client.stop();
          
          
          //clearing string for next read
          readString="";  

        }
      }
    }
  }
}


void reboot(){
  client.println("Powering down... <br>");
  digitalWrite(2, HIGH);
  delay(10000);
  client.println("Waiting... <br>");
  digitalWrite(2, LOW);
  delay(2000);
  client.println("Powering up... <br>");
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  client.println("Complete. <a href=\"/\">Home</a> <br>");
}


