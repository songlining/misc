//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn
 pin 11 is connected to the CLK
 pin 10 is connected to LOAD
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=1000;

int Button1 = 7;
int Button2 = 6;
int Val1 = 0;
int Val2 = 0;

void setup() {

  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);

  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix.
 (you need at least 5x7 leds to see the whole chars)
 */
void smiley() {
  /* here is the data for the characters */
  byte smiley[8]={
    B00000000,
    B00000000,
    B00100100,
    B00000000,
    B10000001,
    B01000010,
    B00111100,
    B00000000
  };
    /* now display them one by one with a small delay */
  for (int i=0; i<8; i++) {
    lc.setRow(0,i,smiley[i]);
  }
}

void plain() {
  byte plain[8]={
    B00000000,
    B00000000,
    B00100100,
    B00000000,
    B00000000,
    B11111111,
    B00000000,
    B00000000
  };
  /* now display them one by one */
  for (int i=0; i<8; i++) {
    lc.setRow(0,i,plain[i]);
  }
}

void sad() {
  byte sad[8]={
    B00000000,
    B00000000,
    B00100100,
    B00000000,
    B00111100,
    B01000010,
    B10000001,
    B00000000
  };
  /* now display them one by one */
  for (int i=0; i<8; i++) {
    lc.setRow(0,i,sad[i]);
  }
}

void shock() {
  byte shock[8]={
    B00000000,
    B00000000,
    B00100100,
    B00000000,
    B00011000,
    B00100100,
    B00100100,
    B00011000
  };
  /* now display them one by one */
  for (int i=0; i<8; i++) {
    lc.setRow(0,i,shock[i]);
  }
}

void loop() {
  Val1 = digitalRead(Button1);
  Val2 = digitalRead(Button2);
  if ((Val1 == HIGH) && (Val2 == HIGH)) {
    plain();
  } else if ((Val1 == LOW) && (Val2 == HIGH)) {
    smiley();
  } else if ((Val1 == HIGH) && (Val2 == LOW)) {
    sad();
  } else if ((Val1 == LOW) && (Val2 == LOW)) {
    shock();
  }
}
