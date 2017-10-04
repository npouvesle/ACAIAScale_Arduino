#ifndef SCALE_H
#define SCALE_H

#include <CurieBLE.h>
#include "Buffer.h"

class Scale {

  float weight;
  bool weightHasChanged;

  Buffer * buffer;
  int state;
  
  BLEDevice peripheral;
  BLECharacteristic characteristic;
  
  unsigned char battery;
  unsigned char minutes;
  unsigned char seconds;
  unsigned char mseconds;
  
  bool connected;
  bool ready;
  bool notificationRequestSent;
  unsigned long lastHeartbeat;

  void printf(const char *format, ...);
  void sendMessage(char msgType, const unsigned char *payload, size_t len);
  void sendEvent(unsigned char *payload, size_t len);
  void sendHeartbeat();
  void sendTare();
  void sendId();
  void sendNotificationRequest();
  void sendTimerCommand(unsigned char command);
  int parseAckEvent(unsigned char *payload, size_t len);
  int parseWeightEvent(unsigned char *payload, size_t len);
  int parseBatteryEvent(unsigned char *payload, size_t len);
  int parseTimerEvent(unsigned char *payload, size_t len);
  int parseScaleEvent(unsigned char *payload, size_t len);
  int parseScaleEvents(unsigned char *payload, size_t len);
  int parseInfo(unsigned char *payload, size_t len);
  int parseScaleData(int msgType, unsigned char *payload, size_t len);
  bool isConnected();
  bool reset(const char * message);
  
public:
  bool hasWeightChanged();
  float getWeight();
  unsigned char getBattery();
  unsigned char getSeconds();
  void update();
  void connect();
  void disconnect();
  bool tare();
  bool startTimer();
  bool stopTimer();
  Scale();
  ~Scale();
};

#endif

