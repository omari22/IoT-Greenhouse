
#include <Wire.h>

#define SI7021_ADDR 0x40

// ===== RAK3172 UART =====
#define RAK_SERIAL Serial2

// =============================
// LECTURE TEMPERATURE
// =============================
float readTemperature() {
  Wire.beginTransmission(SI7021_ADDR);
  Wire.write(0xF3);
  Wire.endTransmission();
  delay(25);

  Wire.requestFrom(SI7021_ADDR, 2);
  uint16_t raw = Wire.read() << 8 | Wire.read();

  return ((175.72 * raw) / 65536.0) - 46.85;
}

// =============================
// LECTURE HUMIDITE
// =============================
float readHumidity() {
  Wire.beginTransmission(SI7021_ADDR);
  Wire.write(0xF5);
  Wire.endTransmission();
  delay(25);

  Wire.requestFrom(SI7021_ADDR, 2);
  uint16_t raw = Wire.read() << 8 | Wire.read();

  return ((125.0 * raw) / 65536.0) - 6.0;
}

// =============================
void setup() {

  Serial.begin(115200);
  RAK_SERIAL.begin(115200);
  Wire.begin();

  delay(2000);

  Serial.println("SI7021 + RAK3172 Ready");
}

// =============================
void loop() {

  float temp = readTemperature();
  float hum  = readHumidity();

  // Sécurité valeurs
  temp = constrain(temp, -40, 125);
  hum  = constrain(hum, 0, 100);

  // ===== Création payload TEXTE =====
  String payload = "temp=";
  payload += String(temp, 1);
  payload += "&hum=";
  payload += String(hum, 1);

  int len = payload.length();

  // ===== Commande AT =====
  String cmd = "AT+SEND=1,0,";
  cmd += String(len);
  cmd += ",0,";
  cmd += payload;

  RAK_SERIAL.println(cmd);

  Serial.println("Envoye : " + cmd);

  delay(3000);  // envoi toutes les 60 secondes
}
