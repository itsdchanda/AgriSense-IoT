
#include <DHT.h>

#define DHTPIN 2     // Pin where the DHT12 is connected
#define DHTTYPE DHT12   // DHT12 sensor
#define RELAYPIN 3    // Pin connected to the relay

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, HIGH); // Initialize relay to off
}

void loop() {
  delay(2000);  // Delay between sensor readings
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %	");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  // If humidity is greater than 60%, turn on fan (relay)
  if (h > 60) {
    digitalWrite(RELAYPIN, LOW); // Activate relay
    Serial.println("Fan ON");
  } else {
    digitalWrite(RELAYPIN, HIGH); // Deactivate relay
    Serial.println("Fan OFF");
  }
}
