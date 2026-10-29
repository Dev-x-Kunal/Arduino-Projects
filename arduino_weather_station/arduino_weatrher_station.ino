#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not detected");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = tempC * 1.8 + 32;

  if (isnan(humidity) || isnan(tempC)) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("DHT11 Error");
    display.display();
    delay(2000);
    return;
  }

  display.clearDisplay();

  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(tempC);
  display.print(" C");

  display.setCursor(0, 16);
  display.print("Temp: ");
  display.print(tempF);
  display.print(" F");

  display.setCursor(0, 32);
  display.print("Humidity: ");
  display.print(humidity);
  display.print(" %");

  display.display();
  delay(2000);
}
