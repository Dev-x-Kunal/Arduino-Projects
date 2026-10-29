#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Eye positions
int leftEyeX = 34;
int rightEyeX = 84;
int eyeY = 32;

// Eye sizes
int eyeRadius = 12;   // Circle
int eyeWidth = 24;    // Blink rect width
int eyeHeight = 12;   // Blink rect height

// State variables
bool blinking = false;
int glanceOffset = 0;   // -6 = left, 0 = center, +6 = right

// Timing
unsigned long lastBlinkTime = 0;
unsigned long blinkInterval = 5000;   // first blink after 5s
unsigned long lastGlanceTime = 0;
unsigned long glanceInterval = 3000;  // every 3s try glance
unsigned long glanceDuration = 2000;  // glance hold time
bool isGlancing = false;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

  randomSeed(analogRead(A0));
  lastBlinkTime = millis();
  lastGlanceTime = millis();
}

void loop() {
  unsigned long now = millis();

  // ---- Blink Logic ----
  if (!blinking && now - lastBlinkTime > blinkInterval) {
    blinkEyes();
    lastBlinkTime = now;
    blinkInterval = random(4000, 8000); // randomize next blink
  }

  // ---- Glance Logic ----
  if (!isGlancing && now - lastGlanceTime > glanceInterval) {
    // choose direction
    int r = random(0, 100);
    if (r < 40) glanceOffset = -6;      // look left
    else if (r < 80) glanceOffset = +6; // look right
    else glanceOffset = 0;              // stay center

    isGlancing = true;
    lastGlanceTime = now;
    glanceDuration = random(1500, 3000); // hold glance 1.5–3s
  }

  // Return eyes straight after glance
  if (isGlancing && now - lastGlanceTime > glanceDuration) {
    glanceOffset = 0; // back to straight at you
    isGlancing = false;
    lastGlanceTime = now;
    glanceInterval = random(2000, 5000); // wait 2–5s before next glance
  }

  // ---- Draw Normal Eyes (if not blinking) ----
  if (!blinking) {
    drawCircleEyes();
  }

  delay(60); // smooth update
}

// ---------------- DRAW CIRCLE EYES ----------------
void drawCircleEyes() {
  display.clearDisplay();

  display.fillCircle(leftEyeX + glanceOffset, eyeY, eyeRadius, WHITE);
  display.fillCircle(rightEyeX + glanceOffset, eyeY, eyeRadius, WHITE);

  display.display();
}

// ---------------- BLINK ANIMATION ----------------
void blinkEyes() {
  blinking = true;

  // Closing animation (rect shrinking)
  for (int h = eyeHeight; h >= 2; h -= 2) {
    display.clearDisplay();

    display.fillRect(leftEyeX + glanceOffset - eyeWidth / 2, eyeY - h / 2, eyeWidth, h, WHITE);
    display.fillRect(rightEyeX + glanceOffset - eyeWidth / 2, eyeY - h / 2, eyeWidth, h, WHITE);

    display.display();
    delay(40);
  }

  delay(120); // closed pause

  // Opening → back to circles
  drawCircleEyes();
  delay(60);

  blinking = false;
}
