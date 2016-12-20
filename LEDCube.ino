#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NUM_LEDS 9
#define PIN 0
#define BRIGHTNESS 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  //colorWipe(strip.Color(255, 5, 180), 50); // Pink
  //colorWipe(strip.Color(255, 0, 0), 50); // Red
  //colorWipe(strip.Color(255, 150, 0), 50); // Orange
  //colorWipe(strip.Color(255, 255, 5), 50); // Yellow
  //colorWipe(strip.Color(0, 255, 0), 50); // Green
  //colorWipe(strip.Color(0, 0, 255), 50); // Blue
  //colorWipe(strip.Color(135, 10, 215), 50); // Purple
  // Send a theater pixel chase in...
  //theaterChase(strip.Color(127, 127, 127), 50); // White
  //theaterChase(strip.Color(127, 0, 0), 50); // Red
  //theaterChase(strip.Color(0, 0, 127), 50); // Blue

  rainbow(20);
  rainbowCycle(20);
  //theaterChaseRainbow(50);
  rainbowStrip();

  //Testing
  //alternateColor(strip.Color(255, 0, 0), strip.Color(0, 255, 0), 100);
  //randomColorFill(25);
  //randomPositionFill(strip.Color(255, 255, 255), 500);
  //middleFill(strip.Color(0, 255, 0), 100);
  //sideFill(strip.Color(255, 0, 0), 100);
  //RGBLoop();
  //FadeInOut(0xff, 0x00, 0x00); // red
  //FadeInOut(0xff, 0xff, 0xff); // white 
  //FadeInOut(0x00, 0x00, 0xff); // blue
  //Strobe(0xff, 0x77, 0x00, 10, 100, 1000);
  //CylonBounce(0xff, 0, 0, 3, 35, 75);
  //NewKITT(0xff, 0, 0, 4, 35, 75);
  //Twinkle(0xff, 0xff, 0xff, 15, 150, false);
  //TwinkleRandom(20, 100, false);
  //Sparkle(0xff, 0xff, 0xff, 75);
  //Sparkle(random(255), random(255), random(255), 75);
  //SnowSparkle(0x10, 0x10, 0x10, 20, 200);
  //SnowSparkle(0x10, 0x10, 0x10, 20, random(100,1000));
  //RunningLights(0xff,0,0, 50);        // red
  //RunningLights(0xff,0xff,0xff, 50);  // white
  //RunningLights(0,0,0xff, 50);        // blue
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

void rainbowStrip() {
  
  int i = 0;
  while(i<NUM_LEDS*4) {     
    strip.setPixelColor(i%NUM_LEDS, strip.Color(255, 255, 255)); //change RGB color value here
    strip.setPixelColor((i+1)%NUM_LEDS, strip.Color(255, 5, 180)); //change RGB color value here
    strip.setPixelColor((i+2)%NUM_LEDS, strip.Color(255, 0, 0)); //change RGB color value here
    strip.setPixelColor((i+3)%NUM_LEDS, strip.Color(255, 150, 0)); //change RGB color value here
    strip.setPixelColor((i+4)%NUM_LEDS, strip.Color(255, 255, 5)); //change RGB color value here
    strip.setPixelColor((i+5)%NUM_LEDS, strip.Color(0, 255, 0)); //change RGB color value here
    strip.setPixelColor((i+6)%NUM_LEDS, strip.Color(0, 0, 255)); //change RGB color value here
    strip.setPixelColor((i+7)%NUM_LEDS, strip.Color(135, 10, 215)); //change RGB color value here
    strip.setPixelColor((i+8)%NUM_LEDS, strip.Color(255, 255, 255)); //change RGB color value here
    i++;
    strip.show();
    delay(75);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  
}

// alternate between two colors on even and odd LEDs
void alternateColor(uint32_t c1, uint32_t c2, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    if(i%2 == 0) { // set even LED to color 1
      strip.setPixelColor(i, c1);
    } else { // set odd LED to color 2
      strip.setPixelColor(i, c2);
    }
  }

  strip.show(); // apply the colors
  delay(wait);

  for(uint16_t i=0; i<strip.numPixels(); i++) {
    if(i%2 == 0) { // set even LED to color 2
      strip.setPixelColor(i, c2);
    } else { // set odd LED to color 1
      strip.setPixelColor(i, c1);
    }
  }

  strip.show(); // apply the colors
  delay(wait);
}

void clearStrip(){
  for(int i=0;i<NUM_LEDS;i++){
      strip.setPixelColor(i, strip.Color(0, 0, 0)); //change RGB color value here
   }
   strip.show();
}

// gradually fill up the strip with random colors
void randomColorFill(uint8_t wait) {
  clearStrip();

  for(uint16_t i=0; i<strip.numPixels(); i++) { // iterate over every LED of the strip
    int r = random(0,255); // generate a random color
    int g = random(0,255);
    int b = random(0,255);

    for(uint16_t j=0; j<strip.numPixels()-i; j++) { // iterate over every LED of the strip, that hasn't lit up yet
      strip.setPixelColor(j-1, strip.Color(0, 0, 0)); // turn previous LED off
      strip.setPixelColor(j, strip.Color(r, g, b)); // turn current LED on
      strip.show(); // apply the colors
      delay(wait);
    }
  }
}

// pick a random LED to light up until entire strip is lit
void randomPositionFill(uint32_t c, uint8_t wait) {
  clearStrip();

  int used[strip.numPixels()]; // array to keep track of lit LEDs
  int lights = 0; // counter

  for(int i = 0; i<strip.numPixels(); i++){ // fill array with 0
    used[i] = 0;
  }

  while(lights<strip.numPixels()-1) {
    int j = random(0,strip.numPixels()-1); // pick a random LED
    if(used[j] != 1){ // if LED not already lit, proceed
      strip.setPixelColor(j, c);
      used[j] = 1; // update array to remember it is lit
      lights++;
      strip.show(); // display
      delay(wait);
    }
  }
}

// Light up the strip starting from the middle
void middleFill(uint32_t c, uint8_t wait) {
  clearStrip();
  delay(wait);

  for(uint16_t i=0; i<(strip.numPixels()/2); i++) { // start from the middle, lighting an LED on each side
    strip.setPixelColor(strip.numPixels()/2 + i, c);
    strip.setPixelColor(strip.numPixels()/2 - i, c);
    strip.show();
    delay(wait);
  }
  strip.setPixelColor(0, c);
  strip.show();
  delay(wait);

  for(uint16_t i=0; i<(strip.numPixels()/2); i++) { // reverse
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.setPixelColor(strip.numPixels() - i, strip.Color(0, 0, 0));
    strip.show();
    delay(wait);
  }
  clearStrip();
}

// Light up the strip starting from the sides
void sideFill(uint32_t c, uint8_t wait) {
  clearStrip();
  delay(wait);

  for(uint16_t i=0; i<(strip.numPixels()/2); i++) { // fill strip from sides to middle
    strip.setPixelColor(i, c);
    strip.setPixelColor(strip.numPixels() - i, c);
    strip.show();
    delay(wait);
  }

  strip.setPixelColor(strip.numPixels()/2, c);
  strip.show();
  delay(wait);

  for(uint16_t i=0; i<(strip.numPixels()/2); i++) { // reverse
    strip.setPixelColor(strip.numPixels()/2 + i, strip.Color(0, 0, 0));
    strip.setPixelColor(strip.numPixels()/2 - i, strip.Color(0, 0, 0));
    strip.show();
    delay(wait);
  }
  clearStrip();
}

/*Extra stuff*/
void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}

void RGBLoop(){
  for(int j = 0; j < 3; j++ ) { 
    // Fade IN
    for(int k = 0; k < 256; k++) { 
      switch(j) { 
        case 0: setAll(k,0,0); break;
        case 1: setAll(0,k,0); break;
        case 2: setAll(0,0,k); break;
      }
      showStrip();
      delay(3);
    }
    // Fade OUT
    for(int k = 255; k >= 0; k--) { 
      switch(j) { 
        case 0: setAll(k,0,0); break;
        case 1: setAll(0,k,0); break;
        case 2: setAll(0,0,k); break;
      }
      showStrip();
      delay(3);
    }
  }
}

void FadeInOut(byte red, byte green, byte blue){
  float r, g, b;
      
  for(int k = 0; k < 256; k=k+1) { 
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showStrip();
  }
     
  for(int k = 255; k >= 0; k=k-2) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showStrip();
  }
}

void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause){
  for(int j = 0; j < StrobeCount; j++) {
    setAll(red,green,blue);
    showStrip();
    delay(FlashDelay);
    setAll(0,0,0);
    showStrip();
    delay(FlashDelay);
  }
 
 delay(EndPause);
}

void CylonBounce(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay){

  for(int i = 0; i < NUM_LEDS-EyeSize-2; i++) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    showStrip();
    delay(SpeedDelay);
  }

  delay(ReturnDelay);

  for(int i = NUM_LEDS-EyeSize-2; i > 0; i--) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    showStrip();
    delay(SpeedDelay);
  }
  
  delay(ReturnDelay);
}

void NewKITT(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay){
  RightToLeft(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  LeftToRight(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  OutsideToCenter(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  CenterToOutside(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  LeftToRight(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  RightToLeft(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  OutsideToCenter(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  CenterToOutside(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
}

void CenterToOutside(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  for(int i =((NUM_LEDS-EyeSize)/2); i>=0; i--) {
    setAll(0,0,0);
    
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    
    setPixel(NUM_LEDS-i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(NUM_LEDS-i-j, red, green, blue); 
    }
    setPixel(NUM_LEDS-i-EyeSize-1, red/10, green/10, blue/10);
    
    showStrip();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

void OutsideToCenter(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  for(int i = 0; i<=((NUM_LEDS-EyeSize)/2); i++) {
    setAll(0,0,0);
    
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    
    setPixel(NUM_LEDS-i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(NUM_LEDS-i-j, red, green, blue); 
    }
    setPixel(NUM_LEDS-i-EyeSize-1, red/10, green/10, blue/10);
    
    showStrip();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

void LeftToRight(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  for(int i = 0; i < NUM_LEDS-EyeSize-2; i++) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    showStrip();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

void RightToLeft(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  for(int i = NUM_LEDS-EyeSize-2; i > 0; i--) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    showStrip();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

void Twinkle(byte red, byte green, byte blue, int Count, int SpeedDelay, boolean OnlyOne) {
  setAll(0,0,0);
  
  for (int i=0; i<Count; i++) {
     setPixel(random(NUM_LEDS),red,green,blue);
     showStrip();
     delay(SpeedDelay);
     if(OnlyOne) { 
       setAll(0,0,0); 
     }
   }
  
  delay(SpeedDelay);
}

void TwinkleRandom(int Count, int SpeedDelay, boolean OnlyOne) {
  setAll(0,0,0);
  
  for (int i=0; i<Count; i++) {
     setPixel(random(NUM_LEDS),random(0,255),random(0,255),random(0,255));
     showStrip();
     delay(SpeedDelay);
     if(OnlyOne) { 
       setAll(0,0,0); 
     }
   }
  
  delay(SpeedDelay);
}

void Sparkle(byte red, byte green, byte blue, int SpeedDelay) {
  int Pixel = random(NUM_LEDS);
  setPixel(Pixel,red,green,blue);
  showStrip();
  delay(SpeedDelay);
  setPixel(Pixel,0,0,0);
}

void SnowSparkle(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay) {
  setAll(red,green,blue);
  
  int Pixel = random(NUM_LEDS);
  setPixel(Pixel,0xff,0xff,0xff);
  showStrip();
  delay(SparkleDelay);
  setPixel(Pixel,red,green,blue);
  showStrip();
  delay(SpeedDelay);
}

void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position=0;
  
  for(int i=0; i<NUM_LEDS*2; i++)
  {
      Position++; // = 0; //Position + Rate;
      for(int i=0; i<NUM_LEDS; i++) {
        // sine wave, 3 offset waves make a rainbow!
        //float level = sin(i+Position) * 127 + 128;
        //setPixel(i,level,0,0);
        //float level = sin(i+Position) * 127 + 128;
        setPixel(i,((sin(i+Position) * 127 + 128)/255)*red,
                   ((sin(i+Position) * 127 + 128)/255)*green,
                   ((sin(i+Position) * 127 + 128)/255)*blue);
      }
      
      showStrip();
      delay(WaveDelay);
  }
}

void colorWipe2(byte red, byte green, byte blue, int SpeedDelay) {
  for(uint16_t i=0; i<NUM_LEDS; i++) {
      setPixel(i, red, green, blue);
      showStrip();
      delay(SpeedDelay);
  }
}
