//insert a random red-yellow sparkle 
void sparkle() {   
  int x,y;
  x = random(0,MATRIX_WIDTH);
  y = random(0,MATRIX_HEIGHT/3);
      matrixValue[x][y][0] = random(0, 30);
      matrixValue[x][y][1] = random(100, 255);
      matrixValue[x][y][2] = random(0, 255);
 }

 void shiftUp() {
  //schuif alle pixels 1 rij omhoog.
  // shift all pixels 1 row up.
  for (uint8_t y=MATRIX_HEIGHT-1; y>0; y--) {
    for (uint8_t x=0; x<MATRIX_WIDTH; x++) {
      matrixValue[x][y][0] = matrixValue[x][y-1][0]+random(0, 1);
      matrixValue[x][y][1] = matrixValue[x][y-1][1]-random(0, 3); //saturation
      matrixValue[x][y][2] = matrixValue[x][y-1][2]-random(1, 6);  //brightness , fade out speed
    }
  }
}

void shake_flame() {
// this function shake a random row.  use this on flat matrix, not in a cilinder shape
  int shake;
  int y;
  
 // for (uint8_t y=MATRIX_HEIGHT-1; y>0; y--) {
 y = random(4,40);  //between row 4 and 40
 shake = random(0,4); // shake 1 or two pixels left or right
    for (uint8_t x=1; x<MATRIX_WIDTH-1; x++) {
      //hulp=abs(x-(MATRIX_WIDTH/2));
      matrixValue[x][y][0] = matrixValue[x+shake-2][y][0]+random(0, 2);
      matrixValue[x][y][1] = matrixValue[x+shake-2][y][1]+random(0, 0);
      matrixValue[x][y][2] = matrixValue[x+shake-2][y][2]-random(0, 30);
    }
}


void rotate() {
  //this  to rotate 1 row of the colum
 //for (uint8_t y=MATRIX_HEIGHT-1; y>0; y--){
  uint8_t y;
    y = random(10,MATRIX_HEIGHT-1);
      matrixValue[MATRIX_WIDTH-1][y][0] = matrixValue[0][y][0];  //kleur waarde
      matrixValue[MATRIX_WIDTH-1][y][1] = matrixValue[0][y][1]; //saturation
      matrixValue[MATRIX_WIDTH-1][y][2] = matrixValue[0][y][2];   //brightness
    for (uint8_t x=0; x<MATRIX_WIDTH-1; x++) {   
      matrixValue[x][y][0] = matrixValue[x+1][y][0];  //kleur waarde
      matrixValue[x][y][1] = matrixValue[x+1][y][1]; //saturation
      matrixValue[x][y][2] = matrixValue[x+1][y][2];   //brightness
    }
}

void flame() {
  //veroorzaakt een vlam effect door langzaam uit te faden.
  //causes a flame effect by fading out slowly.
//  int hulp;
 // for (uint8_t y=MATRIX_HEIGHT-1; y>0; y--)
 uint8_t y;
  y = random(5,MATRIX_HEIGHT-1);
  {
    for (uint8_t x=0; x<MATRIX_WIDTH; x++) {
      //hulp=abs(x-((MATRIX_WIDTH+1)/2)); //bepaal het midden. kanten moeten eerder uitfaden
      //If you want to create a flame on a flat surface, make sure that the sides fade out earlier than the center. You can do this by adding an auxiliary value to the brightness.
      
      matrixValue[x][y][0] = matrixValue[x][y][0]+random(0, 6)-3;  //kleur waarde
      matrixValue[x][y][1] = matrixValue[x][y][1]-random(0, 6); //saturation
      matrixValue[x][y][2] = matrixValue[x][y][2]-random(5, 10);   //brightness
  //    matrixValue[x][y][2] = matrixValue[x][y][2]-random(2, hulp+2);   //brightness , uncomment this for a flat surface.
    }
  }
}

void generateLine(){
  // maakt een nieuwe regel onderaan de rij.
  //creates a new line on the bottom row.
    CRGB rgb;
    CHSV kleur;
    byte R;
  
  for(uint8_t x=0; x<MATRIX_WIDTH; x++) {
   H_waarde = random(0,35);  //red yellow waarde
  //  H_waarde = random(130,180); //blue    uncomment for a different Color 
 //  H_waarde = random(64,128); //green
 // following the rainbow chart https://github.com/FastLED/FastLED/wiki/Pixel-reference
   S_waarde = random(140, 255);          //saturation
   B_waarde = random(100, 255);  //brightness
    matrixValue[x][0][0] = H_waarde;
    matrixValue[x][0][1] = S_waarde;
    matrixValue[x][0][2] = B_waarde;
    matrixValue[x][4][0] = H_waarde+7;
    matrixValue[x][4][1] = S_waarde;
    matrixValue[x][4][2] = B_waarde;
  }
//I add white to yellow color pixels to the bottom rows.
     for(uint8_t x=0; x<2; x++) {
    R = random(0,8);
    matrixValue[R][0+x][0] = 0; //  kleur.hue;
    matrixValue[R][0+x][1] = 0; //kleur.sat;
    matrixValue[R][0+x][2] = 255; //kleur.val;
    R = random(0,8);
    matrixValue[R][1+x][0] = 52; //  kleur.hue;
    matrixValue[R][1+x][1] = 255; //kleur.sat;
    matrixValue[R][1+x][2] = 255; //kleur.val;
    //Serial.print(" color ");Serial.println(color);
     }
}
