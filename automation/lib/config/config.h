#ifndef CONFIG_H_
#define CONFIG_H_

//--------------------------------------------------
long TIME_WAIT = 5000;
//--------------------------------------------------

//--------------------------------------------------
#ifndef TCP_CLUSTER_DOMAIN
#define TCP_CLUSTER_DOMAIN "device.azmisahin.com"
#endif /* TCP_CLUSTER_DOMAIN */

#ifndef TCP_CLUSTER_DOMAIN_PORT
#define TCP_CLUSTER_DOMAIN_PORT 1340
#endif /* TCP_CLUSTER_DOMAIN_PORT */

#ifndef TCP_CLUSTER_DOMAIN_USER
#define TCP_CLUSTER_DOMAIN_USER "try"
#endif /* TCP_CLUSTER_DOMAIN_USER */

#ifndef TCP_CLUSTER_DOMAIN_PASSWORD
#define TCP_CLUSTER_DOMAIN_PASSWORD "try"
#endif /* TCP_CLUSTER_DOMAIN_PASSWORD */
//--------------------------------------------------

//--------------------------------------------------
#ifndef BROKER_CLUSTER_MQTT_DOMAIN
#define BROKER_CLUSTER_MQTT_DOMAIN "broker.azmisahin.com"
#endif /* BROKER_CLUSTER_MQTT_DOMAIN */

#ifndef BROKER_CLUSTER_MQTT_PORT
#define BROKER_CLUSTER_MQTT_PORT 1883
#endif /* BROKER_CLUSTER_MQTT_PORT */

#ifndef BROKER_CLUSTER_MQTT_USER
#define BROKER_CLUSTER_MQTT_USER "try"
#endif /* BROKER_CLUSTER_MQTT_USER */

#ifndef BROKER_CLUSTER_MQTT_PASSWORD
#define BROKER_CLUSTER_MQTT_PASSWORD "try"
#endif /* BROKER_CLUSTER_MQTT_PASSWORD */
//--------------------------------------------------

//--------------------------------------------------
#ifndef SIGNAL_CHANNEL
#define SIGNAL_CHANNEL "iot"
#endif /* SIGNAL_CHANNEL */

#ifndef SIGNAL_SUBSCRIPTIONS
#define SIGNAL_SUBSCRIPTIONS "/subscriptions"
#endif /* SIGNAL_SUBSCRIPTIONS */

#ifndef SIGNAL_MESSAGE
#define SIGNAL_MESSAGE "/message"
#endif /* SIGNAL_MESSAGE */
//--------------------------------------------------

#endif /* CONFIG_H_ */
