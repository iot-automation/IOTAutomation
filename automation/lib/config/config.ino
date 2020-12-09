#include "config.h"

void setup()
{
  Serial.begin(9600);

  // Wait
  delay(5000);

  Serial.println("TIME_WAIT");
  Serial.println(TIME_WAIT);
  Serial.println("----------");

  Serial.println("TCP_CLUSTER_DOMAIN");
  Serial.println(TCP_CLUSTER_DOMAIN);
  Serial.println("----------");

  Serial.println("TCP_CLUSTER_DOMAIN_PORT");
  Serial.println(TCP_CLUSTER_DOMAIN_PORT);
  Serial.println("----------");

  Serial.println("TCP_CLUSTER_DOMAIN_USER");
  Serial.println(TCP_CLUSTER_DOMAIN_USER);
  Serial.println("----------");

  Serial.println("TCP_CLUSTER_DOMAIN_PASSWORD");
  Serial.println(TCP_CLUSTER_DOMAIN_PASSWORD);
  Serial.println("----------");

  Serial.println("BROKER_CLUSTER_MQTT_DOMAIN");
  Serial.println(BROKER_CLUSTER_MQTT_DOMAIN);
  Serial.println("----------");

  Serial.println("BROKER_CLUSTER_MQTT_PORT");
  Serial.println(BROKER_CLUSTER_MQTT_PORT);
  Serial.println("----------");

  Serial.println("BROKER_CLUSTER_MQTT_USER");
  Serial.println(BROKER_CLUSTER_MQTT_USER);
  Serial.println("----------");

  Serial.println("BROKER_CLUSTER_MQTT_PASSWORD");
  Serial.println(BROKER_CLUSTER_MQTT_PASSWORD);
  Serial.println("----------");

  Serial.println("SIGNAL_CHANNEL");
  Serial.println(SIGNAL_CHANNEL);
  Serial.println("----------");

  Serial.println("SIGNAL_SUBSCRIPTIONS");
  Serial.println(SIGNAL_SUBSCRIPTIONS);
  Serial.println("----------");

  Serial.println("SIGNAL_MESSAGE");
  Serial.println(SIGNAL_MESSAGE);
  Serial.println("----------");
}

void loop()
{
}
