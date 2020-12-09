
#include <ESP8266WiFi.h>

// Ports
#define LED D0
#define LED_ERROR D1
#define LED_SEND D2
#define LED_RECEVID D3

// Timer
const int delayTime = 100;
const int watchdog = 5000;
const int time_wait = 5000;

// IoT Hub
const char *host = "device.azmisahin.com";
const int port = 443;
const char *clientID = "AS0000000001001";

// Connection Configuration
const char *conn = "*CONN,";
const char *venn = "AS,";
const char *ssid = "iot-automation";
const char *sspass = "iot-automation";

// Core Define
unsigned long previousMillis = millis();
unsigned long count = 1;
unsigned long SEQUENCE = 1;

// Initalize
void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LED_ERROR, OUTPUT);
  pinMode(LED_SEND, OUTPUT);
  pinMode(LED_RECEVID, OUTPUT);

  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, sspass);

  Serial.println(host);
  Serial.println(clientID);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(delayTime);
    Serial.print(".");
    blinkLed();
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

// Cleaning
void clearLED()
{
  digitalWrite(LED, LOW);
  digitalWrite(LED_ERROR, LOW);
  digitalWrite(LED_SEND, LOW);
  digitalWrite(LED_RECEVID, LOW);
}

// Recevid
void recevidLed()
{
  digitalWrite(LED_RECEVID, LOW);
  delay(delayTime);
  digitalWrite(LED_RECEVID, HIGH);
  delay(delayTime);
}

// Send
void sendLed()
{
  digitalWrite(LED_SEND, LOW);
  delay(delayTime);
  digitalWrite(LED_SEND, HIGH);
  delay(delayTime);
}

// Error
void errorLed()
{
  digitalWrite(LED_ERROR, LOW);
  delay(delayTime);
  digitalWrite(LED_ERROR, HIGH);
  delay(delayTime);
  digitalWrite(LED_ERROR, LOW);
  delay(delayTime);
  digitalWrite(LED_ERROR, HIGH);
  delay(delayTime);
  digitalWrite(LED_ERROR, LOW);
  delay(delayTime);
  digitalWrite(LED_ERROR, HIGH);
  delay(delayTime);
}

// Blink
void blinkLed()
{
  digitalWrite(LED, LOW);
  delay(delayTime);
  digitalWrite(LED, HIGH);
  delay(delayTime);
}

// Main
void loop()
{
  clearLED();

  // define
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > watchdog)
  {
    previousMillis = currentMillis;
    WiFiClient client;

    Serial.println("**************************************************decive-CYCLE*************************"); //
    Serial.println("");

    Serial.print("SERVER : ");
    Serial.print(host);

    Serial.print(" CLIENT : ");
    Serial.print(clientID);
    Serial.println("");

    if (!client.connect(host, port))
    {
      Serial.println("connection failed");
      errorLed();
      return;
    }
    String clientIP = WiFi.localIP().toString();
    String singing = "";

    /// -------------------------------------------------- Pulse
    blinkLed();

    singing = String(singing + conn);
    singing = String(singing + venn);
    singing = String(singing + clientID);
    singing = String(singing + ",H0,1,398,16,39,1#");

    count = count + 1;

    Serial.println("==================================================decive-CONENCTION====================");

    Serial.print("SEQUENCE    : ");
    SEQUENCE = SEQUENCE + 1;
    Serial.print(SEQUENCE);

    Serial.println("");
    Serial.print("COMMANDSET  : ");
    Serial.println(singing);

    // Send Command
    client.println(singing);
    Serial.println("");
    Serial.println("");

    singing = "";

    sendLed();

    delay(1000);

    /// --------------------------------------------------

    /// -------------------------------------------------- Position
    blinkLed();

    singing = String(singing + conn);
    singing = String(singing + venn);
    singing = String(singing + clientID);
    singing = String(singing + ",D0,0,124458.00,A,2237.7514,N,11408.6214,E,6,0.21,151216,10,M,A#");
    singing = String(singing + ",D0,0,124458.00,A,2237.7545,N,11408.6214,E,6,0.21,151216,10,M,A#");

    count = count + 1;

    Serial.println("==================================================decive-CONENCTION===================="); //

    Serial.print("SEQUENCE    : ");
    SEQUENCE = SEQUENCE + 1;
    Serial.print(SEQUENCE);

    Serial.println("");
    Serial.print("COMMANDSET  : ");
    Serial.println(singing);

    // Send Command
    client.println(singing);
    Serial.println("");
    Serial.println("");

    singing = "";

    sendLed();

    delay(1000);

    /// --------------------------------------------------

    /// -------------------------------------------------- Event
    blinkLed();

    singing = String(singing + conn);
    singing = String(singing + venn);
    singing = String(singing + clientID);
    singing = String(singing + ",S1,2#");

    count = count + 1;

    Serial.println("==================================================decive-CONENCTION====================");

    Serial.print("SEQUENCE    : ");
    SEQUENCE = SEQUENCE + 1;
    Serial.print(SEQUENCE);

    Serial.println("");
    Serial.print("COMMANDSET  : ");
    Serial.println(singing);

    // Send Command
    client.println(singing);
    Serial.println("");
    Serial.println("");

    singing = "";

    sendLed();

    delay(1000);

    /// --------------------------------------------------

    // define
    unsigned long timeout = millis();

    while (client.available() == 0)
    {
      if (millis() - timeout > time_wait)
      {
        Serial.println(" >>> Client Timeout !");
        Serial.println(time_wait);
        client.stop();
        Serial.println("Close");
        return;
      }
    }

    while (client.available())
    {

      // Define
      String str = client.readStringUntil('\r');

      // Length (with one extra character for the null terminator)
      int str_len = str.length() + 1;

      // Prepare the character array (the buffer)
      char char_array[str_len];

      // Copy it over
      str.toCharArray(char_array, str_len);

      // Convert command set
      char *ptr = strtok(char_array, "#");

      byte i = 0;

      /// -------------------------------------------------- Message

      while (ptr)
      {

        Serial.println("--------------------------------------------------decive-MESSAGE-----------------------"); //
        Serial.print(ptr);
        Serial.println("");
        Serial.println("");
        Serial.println("");

        Serial.print(i);
        Serial.print(F("\t\""));

        /// -------------------------------------------------- Split

        ptr = strtok(NULL, "*");
        i++;
        Serial.println("");
      }

      /// -------------------------------------------------- End

      recevidLed();
    }
  }
}
