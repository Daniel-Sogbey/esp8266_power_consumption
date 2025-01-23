/*
Pin where the DHT11 
sensor is connected
*/
#define DHTPIN 2    
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "YourSSID";
const char* password = "YourPassword";

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected.");
}

void loop() {
  // -------- Active Mode --------
  Serial.println("Active Mode: Reading sensor and sending data...");
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print(" °C, Humidity: ");
    Serial.print(hum);
    Serial.println(" %");

    // Simulate sending data to ThingSpeak
    Serial.println("Sending data to ThingSpeak...");
    delay(2000); // Simulate data sending
  }

  // -------- Light Sleep Mode --------
  Serial.println("Entering Light Sleep Mode...");
  WiFi.forceSleepBegin(); // Enable Wi-Fi sleep mode
  delay(4000); // Simulate light sleep duration

  // -------- Deep Sleep Mode --------
  Serial.println("Entering Deep Sleep Mode...");
  ESP.deepSleep(10e6); // Sleep for 10 seconds
}
