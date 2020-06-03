#include <FastLED.h>

#define LED_PIN  5
#define COLOR_ORDER GRB
#define CHIPSET     WS2812
#define BRIGHTNESS 200
#define MATRIX_HEIGHT 72
#define MATRIX_WIDTH 8
#define HSV 3

// Param for different pixel layouts
const bool    kMatrixSerpentineLayout = false;

uint16_t XY( uint8_t x, uint8_t y)
{
  uint16_t i;
  
  if( kMatrixSerpentineLayout == false) {
    i = (y * MATRIX_WIDTH) + x;
  }

  if( kMatrixSerpentineLayout == true) {
    if( y & 0x01) {
      // Odd rows run backwards
      uint8_t reverseX = (MATRIX_WIDTH - 1) - x;
      i = (y * MATRIX_WIDTH) + reverseX;
    } else {
      // Even rows run forwards
      i = (y * MATRIX_WIDTH) + x;
    }
  }
  
  return i;
}


#define NUM_LEDS (MATRIX_WIDTH * MATRIX_HEIGHT)
CRGB leds_plus_safety_pixel[ NUM_LEDS + 1];
CRGB* const leds( leds_plus_safety_pixel + 1);

int matrixValue[MATRIX_WIDTH][MATRIX_HEIGHT][HSV];
int line[MATRIX_WIDTH];
int pcnt = 0;
//int x    = matrix.width();
int pass = 0;
int color;
int H_waarde ;
int S_waarde ;
int B_waarde ;

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  FastLED.setBrightness( BRIGHTNESS );

}

void drawFrame() {

  for (unsigned char y=0; y<MATRIX_HEIGHT; y++) {
    for (unsigned char x=0; x<MATRIX_WIDTH; x++) {
      H_waarde = matrixValue[x][y][0]; 
      if (H_waarde < 0) { H_waarde = 10;}
      S_waarde = matrixValue[x][y][1]; 
      if (S_waarde < 0) { S_waarde = 0;}
      B_waarde = matrixValue[x][y][2]; 
      if (B_waarde < 0) { B_waarde = 0;}
      leds[ XY(x, y)]= CHSV(H_waarde,S_waarde,B_waarde);
    }
  }
}

void loop() {
      shiftUp();
      flame();
      sparkle();
  //    shake_flame();
    if (random(0,2) == 1){  rotate();}
      generateLine();
      drawFrame();
    FastLED.show();
 //   delay(100);
}
