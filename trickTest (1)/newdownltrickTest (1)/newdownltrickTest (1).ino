#include<Wire.h>

byte pins[] = {13, 12, 11};
const int MPU = 0x69;
int16_t AcX[5], AcY[5], AcZ[5], Tmp[5], GyX[5], GyY[5], GyZ[5];

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  for (int i = 0; i <= 2; i++)
    pinMode(pins[i], OUTPUT);

  Serial.begin(9600);
}
void loop() {
  for (int i = 0; i <= 2; i++) {
    switch (i) {
      case 0: digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);
        Wire.beginTransmission(MPU);
        Wire.write(0x3B);
        Wire.endTransmission(false);
        Wire.requestFrom(MPU, 14, true);
        AcX[i] = Wire.read() << 8 | Wire.read();
        AcY[i] = Wire.read() << 8 | Wire.read();
        AcZ[i] = Wire.read() << 8 | Wire.read();
        Tmp[i] = Wire.read() << 8 | Wire.read();
        GyX[i] = Wire.read() << 8 | Wire.read();
        GyY[i] = Wire.read() << 8 | Wire.read();
        GyZ[i] = Wire.read() << 8 | Wire.read();
        
      case 1: digitalWrite(13, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(11, LOW);
        Wire.beginTransmission(MPU);
        Wire.write(0x3B);
        Wire.endTransmission(false);
        Wire.requestFrom(MPU, 14, true);
        AcX[i] = Wire.read() << 8 | Wire.read();
        AcY[i] = Wire.read() << 8 | Wire.read();
        AcZ[i] = Wire.read() << 8 | Wire.read();
        Tmp[i] = Wire.read() << 8 | Wire.read();
        GyX[i] = Wire.read() << 8 | Wire.read();
        GyY[i] = Wire.read() << 8 | Wire.read();
        GyZ[i] = Wire.read() << 8 | Wire.read();
        
      case 2: digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, HIGH);
        Wire.beginTransmission(MPU);
        Wire.write(0x3B);
        Wire.endTransmission(false);
        Wire.requestFrom(MPU, 14, true);
        AcX[i] = Wire.read() << 8 | Wire.read();
        AcY[i] = Wire.read() << 8 | Wire.read();
        AcZ[i] = Wire.read() << 8 | Wire.read();
        Tmp[i] = Wire.read() << 8 | Wire.read();
        GyX[i] = Wire.read() << 8 | Wire.read();
        GyY[i] = Wire.read() << 8 | Wire.read();
        GyZ[i] = Wire.read() << 8 | Wire.read();
    }

    Serial.println();
    Serial.print("Sensor 1");
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print("Sensor 2");
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.println("Sensor 3");
    
    Serial.print("  AcX = ");
    Serial.print(AcX[0]);
    Serial.print('\t');
    Serial.print("Tmp = ");
    Serial.print(Tmp[0] / 340.00 + 36.53);
    Serial.print('\t');
    Serial.print("GyX = "); Serial.print(GyX[0]);
    Serial.print('\t');
    Serial.print("  AcX = ");
    Serial.print(AcX[1]);
    Serial.print('\t');
    Serial.print("Tmp = ");
    Serial.print(Tmp[1] / 340.00 + 36.53);
    Serial.print('\t');
    Serial.print("GyX = "); Serial.print(GyX[1]);
    Serial.print('\t');
    Serial.print("  AcX = ");
    Serial.print(AcX[2]);
    Serial.print('\t');
    Serial.print("Tmp = ");
    Serial.print(Tmp[2] / 340.00 + 36.53);
    Serial.print('\t');
    Serial.print("GyX = "); Serial.println(GyX[2]);
    
    Serial.print("  AcY = "); Serial.print(AcY[0]);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print("GyY = "); Serial.print(GyY[0]);
    Serial.print('\t');
    Serial.print("  AcY = "); Serial.print(AcY[1]);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print("GyY = "); Serial.print(GyY[1]);
    Serial.print('\t');
    Serial.print("  AcY = "); Serial.print(AcY[2]);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print("GyY = "); Serial.println(GyY[2]);
    
    Serial.print("  AcZ = "); Serial.print(AcZ[0]);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print("GyZ = "); Serial.print(GyZ[0]);
    Serial.print('\t');
    Serial.print("  AcZ = "); Serial.print(AcZ[1]);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print("GyZ = "); Serial.print(GyZ[1]);
    Serial.print('\t');
    Serial.print("  AcZ = "); Serial.print(AcZ[2]);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print("GyZ = "); Serial.println(GyZ[2]);

    delay(333);
  }
}
