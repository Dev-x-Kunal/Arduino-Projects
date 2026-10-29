#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int leftEyeX = 34;
int rightEyeX = 84;
int eyeY = 32;

int eyeRadius = 12;
int eyeWidth = 24;
int eyeHeight = 12;

bool blinking = false;
int glanceOffset = 0;

unsigned long lastBlinkTime = 0;
unsigned long blinkInterval = 5000;
unsigned long lastGlanceTime = 0;
unsigned long glanceInterval = 3000;
unsigned long glanceDuration = 2000;

bool isGlancing = false;

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true) {
    }
  }

  display.clearDisplay();
  display.display();

  randomSeed(analogRead(A0));

  lastBlinkTime = millis();
  lastGlanceTime = millis();
}

void loop() {
  unsigned long now = millis();

  if (!blinking && now - lastBlinkTime >= blinkInterval) {
    blinkEyes();
    lastBlinkTime = millis();
    blinkInterval = random(4000, 8000);
  }

  now = millis();

  if (!isGlancing && now - lastGlanceTime >= glanceInterval) {
    int r = random(0, 100);

    if (r < 40) {
      glanceOffset = -6;
    } else if (r < 80) {
      glanceOffset = 6;
    } else {
      glanceOffset = 0;
    }

    isGlancing = true;
    lastGlanceTime = now;
    glanceDuration = random(1500, 3000);
  }

  if (isGlancing && now - lastGlanceTime >= glanceDuration) {
    glanceOffset = 0;
    isGlancing = false;
    lastGlanceTime = now;
    glanceInterval = random(2000, 5000);
  }

  if (!blinking) {
    drawCircleEyes();
  }

  delay(60);
}

void drawCircleEyes() {
  display.clearDisplay();

  display.fillCircle(
    leftEyeX + glanceOffset,
    eyeY,
    eyeRadius,
    SSD1306_WHITE
  );

  display.fillCircle(
    rightEyeX + glanceOffset,
    eyeY,
    eyeRadius,
    SSD1306_WHITE
  );

  display.display();
}

void blinkEyes() {
  blinking = true;

  for (int h = eyeHeight; h >= 2; h -= 2) {
    display.clearDisplay();

    display.fillRect(
      leftEyeX + glanceOffset - eyeWidth / 2,
      eyeY - h / 2,
      eyeWidth,
      h,
      SSD1306_WHITE
    );

    display.fillRect(
      rightEyeX + glanceOffset - eyeWidth / 2,
      eyeY - h / 2,
      eyeWidth,
      h,
      SSD1306_WHITE
    );

    display.display();
    delay(40);
  }

  delay(120);

  drawCircleEyes();
  delay(60);

  blinking = false;
}
