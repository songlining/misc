
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
int Val1 = 0;

void setup() {

  pinMode(Button1, INPUT_PULLUP);

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
    B01110000,
    B01010100,
    B01010000,
    B01010000,
    B01010100,
    B01110000,
    B00000000
  }; 
    /* now display them one by one with a small delay */
  for (int i=0; i<8; i++) {
    lc.setRow(0,i,smiley[i]);
  }
}

void openplain() {
  byte openplain[8]={
    B00000000,
    B00100000,
    B00100100,
    B00100000,
    B00100000,
    B00100100,
    B00100000,
    B00000000
  };
  /* now display them one by one */
  for (int i=0; i<8; i++) {
    lc.setRow(0,i,openplain[i]);
  }
}

void loop() {
  Val1 = digitalRead(Button1);
  if (Val1 == LOW) {
    openplain();
  } else {
    smiley();
  }
}
