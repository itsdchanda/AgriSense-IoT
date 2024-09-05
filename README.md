
# AgriSense IoT Project

AgriSense is an IoT-based solution designed to automate the monitoring and control of environmental conditions in agricultural setups such as hydroponics, greenhouses, and farms. This project ensures optimal crop growth by using sensors to track temperature, humidity, soil moisture, light, and pH levels.

## Project Components
- **DHT12 (Temperature & Humidity Sensor)**: Tracks the temperature and humidity in the environment.
- **Soil Moisture Sensor**: Monitors the moisture level of the soil.
- **Light Sensor (LDR)**: Measures the intensity of light received by the plants.
- **pH Sensor**: Checks the pH of water or nutrient solutions in hydroponics.
- **Relay Module**: Controls actuators like pumps, fans, and lights.
- **Microcontroller**: Central control unit (e.g., Arduino) for processing data and managing actuators.

## How it Works
1. Sensors collect real-time data about the environment.
2. The microcontroller processes the data and compares it against pre-set thresholds.
3. If any conditions fall outside the optimal range, actuators like fans, misters, or pumps are activated to maintain ideal growing conditions.
4. The data can be logged for future analysis or sent to a cloud server for remote monitoring and control.

## Expansion and Scalability
AgriSense is designed to be scalable. Additional sensors, cameras, and weather data integrations can be added to enhance system functionality, making it adaptable to various farming methods.

## Example Code (Arduino)
Below is an example of how to set up the DHT12 sensor and the relay module to monitor humidity and control a fan based on the readings.

```cpp
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
```

## Conclusion
AgriSense is an efficient and scalable solution for smart farming, making agriculture more sustainable and less resource-intensive through automation. This project showcases the use of IoT to enhance agricultural productivity and efficiency.
