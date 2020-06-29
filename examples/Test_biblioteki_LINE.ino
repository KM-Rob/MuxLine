#include<MuxLine.h>

#define A 5
#define B 6
#define C 7
#define LINES 6
#define L_MAX 8

MuxLine Line;

void setup() {
  // put your setup code here, to run once:
  Line.begin(LINES, A0, A, B, C, L_MAX,2);
  Serial.begin(9600);
  delay(1000);
  Line.Reset();
}

void loop() {
  // put your main code here, to run repeatedly:
Line.Reset();
for(int j=0; j<LINES; j++)
{
  for(int i=0; i<L_MAX-1; i++) //było L_MAX-1
  {
    Serial.print(Line.readStep());
    Serial.print(" ");  
  }
  Serial.print(Line.readStep());
  Serial.print(" : ");            // koniec pojedynczej linii
}
  Serial.println(" ");
  delay(500);

}
