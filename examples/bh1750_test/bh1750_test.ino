#include <MentorBitBH1750.h>

MentorBit_BH1750 Luxometro;

void setup() {

  Serial.begin(9600);
  Luxometro.begin();

}

void loop() {

  Serial.print("Luz: ");
  Serial.print(Luxometro.leerLux());
  Serial.println(" lx");

  delay(500);

}
