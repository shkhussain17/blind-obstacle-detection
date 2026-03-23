#include <Wire.h>
#include <Adafruit_VL53L0X.h>

// Create two sensor objects
Adafruit_VL53L0X lox1 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();

#define XSHUT_1 4
#define XSHUT_2 5

#define BUZZER 2

void setup() {
  Serial.begin(115200);

  pinMode(XSHUT_1, OUTPUT);
  pinMode(XSHUT_2, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Start I2C
  Wire.begin(8, 9);

  // Turn OFF both sensors
  digitalWrite(XSHUT_1, LOW);
  digitalWrite(XSHUT_2, LOW);
  delay(10);

  // Turn ON first sensor
  digitalWrite(XSHUT_1, HIGH);
  delay(10);
  if (!lox1.begin(0x30)) {
    Serial.println("Sensor 1 failed");
    while (1);
  }

  // Turn ON second sensor
  digitalWrite(XSHUT_2, HIGH);
  delay(10);
  if (!lox2.begin(0x31)) {
    Serial.println("Sensor 2 failed");
    while (1);
  }

  Serial.println("Both sensors ready");
}

void loop() {
  int d1 = readDistance(lox1);
  int d2 = readDistance(lox2);

  Serial.print("Left: ");
  Serial.print(d1);
  Serial.print(" cm  |  Right: ");
  Serial.println(d2);

  int closest = min(d1, d2);

  // Beeping logic
  if (closest > 100) {
    noTone(BUZZER);
  }
  else if (closest > 60) {
    beep(600);
  }
  else if (closest > 30) {
    beep(300);
  }
  else if (closest > 10) {
    beep(100);
  }
  else {
    tone(BUZZER, 2000); // continuous
  }
}

// Function to read distance
int readDistance(Adafruit_VL53L0X &sensor) {
  VL53L0X_RangingMeasurementData_t measure;
  sensor.rangingTest(&measure, false);

  if (measure.RangeStatus != 4) {
    return measure.RangeMilliMeter / 10;
  }
  return 200; // default if no reading
}

// Beep function
void beep(int delayTime) {
  tone(BUZZER, 1500);
  delay(delayTime);
  noTone(BUZZER);
  delay(delayTime);
}