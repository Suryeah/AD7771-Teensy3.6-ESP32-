#include <SPI.h>
#include <SoftwareSerial.h>
#include <math.h>
#include <pins.h>
using namespace pins;

#define ESTART 27  //23 
#define ECHS 10   //15  // PTC4 
#define SCLK 13   //14
#define ESDI 11   //13
#define ESDO 12   //12
#define ECONVST 26 //22
#define EMODE0 32
#define EMODE1 33
#define EMODE2 25
#define EMODE3 26
#define EDOUT0 36
#define EDOUT1 39
#define EDOUT2 34
#define EDOUT3 35
#define RESET 7     //4
pin<9>EDRDY(INPUT);

uint16_t stat1, stat2, stat3, stat4, stat5, stat6, stat7, stat8, stat9, stat10;
uint16_t head1, head2, head3, head4, head5;
uint8_t temp, temp2, temp3, temp4, oct1;
long int CH1, CH2, CH3, CH4, oct2;

SPISettings settingsA(8192000, MSBFIRST, SPI_MODE0);

void setup() {
  delay(8000);
  pinMode(ESTART, OUTPUT);
  pinMode(ECHS, OUTPUT);
  pinMode(SCLK, OUTPUT);
  pinMode(ESDI, OUTPUT);
  pinMode(ESDO, OUTPUT);
  pinMode(ECONVST, OUTPUT);
  pinMode(EMODE0, OUTPUT);
  pinMode(EMODE1, OUTPUT);
  pinMode(EMODE2, OUTPUT);
  pinMode(EMODE3, OUTPUT);
  pinMode(EDOUT0, INPUT);
  pinMode(EDOUT1, INPUT);
  pinMode(EDOUT2, INPUT);
  pinMode(EDOUT3, INPUT);
  pinMode(RESET, OUTPUT);

  Serial.begin(115200);
  Serial4.begin(115200);
  SPI.begin();

  digitalWrite(RESET, LOW); delay(1);
  digitalWrite(RESET, HIGH); // RESET
  digitalWrite(ESTART, LOW);
  digitalWrite(ECONVST, HIGH);

  digitalWrite(ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X00);
  SPI.transfer(0XC0);
  SPI.endTransaction();
  digitalWrite (ECHS, HIGH);

  digitalWrite(ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X00);
  SPI.transfer(0XC0);
  SPI.endTransaction();
  digitalWrite (ECHS, HIGH);

  digitalWrite(ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X01);
  SPI.transfer(0XC0);
  SPI.endTransaction();
  digitalWrite(ECHS, HIGH);

  digitalWrite(ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X02);
  SPI.transfer(0XC0);
  SPI.endTransaction();
  digitalWrite(ECHS, HIGH);

  digitalWrite(ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X03);
  SPI.transfer(0xC0);
  SPI.endTransaction();
  digitalWrite(ECHS, HIGH);

  digitalWrite (ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X04);
  SPI.transfer(0xC0);
  SPI.endTransaction();
  digitalWrite (ECHS, HIGH);

  digitalWrite (ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X05);
  SPI.transfer(0xC0);
  SPI.endTransaction();
  digitalWrite (ECHS, HIGH);

  digitalWrite (ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X06);
  SPI.transfer(0xC0);
  SPI.endTransaction();
  digitalWrite (ECHS, HIGH);

  digitalWrite (ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X07);
  SPI.transfer(0xC0);
  SPI.endTransaction();
  digitalWrite (ECHS, HIGH);

  digitalWrite(ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X08);
  SPI.transfer(0X60);
  SPI.endTransaction();
  digitalWrite(ECHS, HIGH);

  digitalWrite(ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X11);
  SPI.transfer(0X34);
  SPI.endTransaction();
  digitalWrite(ECHS, HIGH);

  digitalWrite(ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X14);
  SPI.transfer(0X00);
  SPI.endTransaction();
  digitalWrite(ECHS, HIGH);

  digitalWrite (ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X15);
  SPI.transfer(0X58);
  SPI.endTransaction();
  digitalWrite (ECHS, HIGH);

  digitalWrite (ECHS, LOW);
  SPI.beginTransaction(settingsA);
  SPI.transfer(0X13);        //SPI out
  SPI.transfer(0X91);
  SPI.endTransaction();
  digitalWrite (ECHS, HIGH);

  digitalWrite (ECHS, LOW);
}

void loop() {
  while (1) {
    if (EDRDY == HIGH) {

      digitalWrite (ECHS, LOW);
      SPI.beginTransaction(settingsA);
      stat1 = SPI.transfer16(0x8000);
      SPI.endTransaction();
      digitalWrite(ECHS, HIGH);

      digitalWrite(ECHS, LOW);
      SPI.beginTransaction(settingsA);
      stat2 = SPI.transfer16(0x8000);
      SPI.endTransaction();
      digitalWrite(ECHS, HIGH);

      digitalWrite(ECHS, LOW);
      SPI.beginTransaction(settingsA);
      stat3 = SPI.transfer16(0x8000);
      SPI.endTransaction();
      digitalWrite(ECHS, HIGH);

      digitalWrite(ECHS, LOW);
      SPI.beginTransaction(settingsA);
      stat4 = SPI.transfer16(0x8000);
      SPI.endTransaction();
      digitalWrite(ECHS, HIGH);

      digitalWrite(ECHS, LOW);
      SPI.beginTransaction(settingsA);
      stat5 = SPI.transfer16(0x8000);
      SPI.endTransaction();
      digitalWrite(ECHS, HIGH);

      digitalWrite(ECHS, LOW);
      SPI.beginTransaction(settingsA);
      stat6 = SPI.transfer16(0x8000);
      SPI.endTransaction();
      digitalWrite(ECHS, HIGH);

      digitalWrite(ECHS, LOW);
      SPI.beginTransaction(settingsA);
      stat7 = SPI.transfer16(0x8000);
      SPI.endTransaction();
      digitalWrite(ECHS, HIGH);

      digitalWrite(ECHS, LOW);
      SPI.beginTransaction(settingsA);
      stat8 = SPI.transfer16(0x8000);
      SPI.endTransaction();
      digitalWrite(ECHS, HIGH);

      digitalWrite(ECHS, LOW);
      SPI.beginTransaction(settingsA);
      stat9 = SPI.transfer16(0x8000);
      SPI.endTransaction();
      digitalWrite(ECHS, HIGH);

      digitalWrite(ECHS, LOW);
      SPI.beginTransaction(settingsA);
      stat10 = SPI.transfer16(0x8000);
      SPI.endTransaction();
      digitalWrite(ECHS, HIGH);


      //---------------------CH1--------------------

      temp = stat1 & 0x00FF;
      oct2 = (temp << 16);
      CH1 = oct2 + stat2;

      head1 = (stat1 & 0xFF00);
      head1 = (head1 >> 8);
      Serial4.print('*');
      Serial4.print(111, DEC);

      if (stat1 & (1 << 7))
      {
        CH2 = ~CH1;
        CH2 = CH2 + 1;
        CH3 = (CH2 & 0x7FFFFF);
        Serial4.print("-");
        Serial4.print((CH3 * 0.000000148), DEC);
        Serial4.print("#");
      } else
      {
        Serial4.print("+");
         Serial4.print((CH1 * 0.000000148), DEC);
         Serial4.print("#");
      }
      CH1, CH2, CH3, oct2, temp = 0;

      //---------------------CH2--------------------

      temp = stat3 & 0x00FF;
      oct2 = (temp << 16);
      CH1 = oct2 + stat4;

      head2 = (stat3 & 0xFF00);
      head2 = (head2 >> 8);
      Serial4.print('*');
      Serial4.print(222 , DEC);

      if (stat3 & (1 << 7))
      {
        CH2 = ~CH1;
        CH2 = CH2 + 1;
        CH3 = (CH2 & 0x7FFFFF);
        Serial4.print("-");
        Serial4.print((CH3 * 0.000000148), DEC);
        Serial4.print("#");
      } else
      {
        Serial4.print("+");
         Serial4.print((CH1 * 0.000000148), DEC);
         Serial4.print("#");
      }
      CH1, CH2, CH3, oct2, temp = 0;

      //---------------------CH3--------------------

      temp = stat5 & 0x00FF;
      oct2 = (temp << 16);
      CH1 = oct2 + stat6;

      head3 = (stat5 & 0xFF00);
      head3 = (head3 >> 8);
      Serial4.print('*');
      Serial4.print(333 , DEC);

      if (stat5 & (1 << 7))
      {
        CH2 = ~CH1;
        CH2 = CH2 + 1;
        CH3 = (CH2 & 0x7FFFFF);
        Serial4.print("-");
        Serial4.print((CH3 * 0.000000148), DEC);
        Serial4.print("#");
      } else
      {
        Serial4.print("+");
         Serial4.print((CH1 * 0.000000148), DEC);
         Serial4.print("#");
      }
      CH1, CH2, CH3, oct2, temp = 0;

      //---------------------CH4--------------------

      head4 = (stat7 & 0xFF00);
      head4 = (head4 >> 8);
      Serial4.print('*');
      Serial4.print(444 , DEC);

      temp = stat7 & 0x00FF;
      oct2 = (temp << 16);
      CH1 = oct2 + stat8;

      if (stat7 & (1 << 7))
      {
        CH2 = ~CH1;
        CH2 = CH2 + 1;
        CH3 = (CH2 & 0x7FFFFF);
        Serial4.print("-");
        Serial4.print((CH3 * 0.000000148), DEC);
        Serial4.print("#");
      } else
      {
        Serial4.print("+");
         Serial4.print((CH1 * 0.000000148), DEC);
         Serial4.print("#");
      }
      CH1, CH2, CH3, oct2, temp = 0;

      //---------------------CH5--------------------

      head5 = (stat9 & 0xFF00);
      head5 = (head5 >> 8);
      Serial4.print('*');
      Serial4.print(555 , DEC);

      temp = stat9 & 0x00FF;
      oct2 = (temp << 16);
      CH1 = oct2 + stat10;

      if (stat9 & (1 << 7))
      {
        CH2 = ~CH1;
        CH2 = CH2 + 1;
        CH3 = (CH2 & 0x7FFFFF);
        Serial4.print("-");
        Serial4.print((CH3 * 0.000000148), DEC);
        Serial4.println("#");
      } else
      {
         Serial4.print("+");
         Serial4.print((CH1 * 0.000000148), DEC);
         Serial4.println("#");
      }
      CH1, CH2, CH3, oct2, temp = 0;


      stat1, stat2, stat3, stat4, stat5, stat6, stat7, stat8, stat9, stat10 = 0;
      temp, temp2, temp2, temp2, CH1, CH2, CH3, CH4, oct2, head1, head2, head3, head4 = 0;
    }
    else;
  };
}
