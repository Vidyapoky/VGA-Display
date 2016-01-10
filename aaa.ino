#include <Adafruit_GFX.h>
#include <Adafruit_F32C_VGA.h>
Adafruit_F32C_VGA display(1);

#define SCREEN_WIDTH (640-1)
#define SCREEN_HEIGHT (480-1)

const int buttonPin = 0;
const int buttonDOWN = 1;
const int buttonUP = 2;
const int buttonRIGHT = 3;
const int buttonLEFT = 4;
int buttonState=0;
int buttonStated=0;
int buttonStateu=0;
int buttonStater=0;
int buttonStatel=0; 
int vx=35, vy=20;
int uvjetX=0, uvjetY=0;

void mreza(int dx, int dy){
  int m;
  for (m=1; m<3; m++){
     display.drawFastVLine(60*m+dx, dy, 150, WHITE);
     display.drawFastHLine(dx, 50*m+dy, 180, WHITE);
  }
}

int pomicanjeXx(int vx){
  if (buttonStater==HIGH){
    vx+=60;
    delay(250);
  }
  if (buttonStatel==HIGH){
    vx-=60;
    delay(250);
  }
  if (buttonState==HIGH){
    uvjetX=1;
  }
 return(vx);
}
int pomicanjeXy(int vy){
    if (buttonStated==HIGH){
    vy+=50;
    delay(250);
  }
  if (buttonStateu==HIGH){
    vy-=50;
    delay(250);
  }
  if (buttonState==HIGH){
    uvjetY=1;
  }
}


void setup() {
  // put your setup code here, to run once:
  int i, j, pobjeda=0, x, y;
  pinMode(buttonPin, INPUT);
  pinMode(buttonDOWN, INPUT);
  pinMode(buttonUP, INPUT);
  pinMode(buttonRIGHT, INPUT);
  pinMode(buttonLEFT, INPUT);
  display.begin();
  display.clearDisplay();
  display.setTextSize(5);
  display.setCursor(30, 30);
  display.setTextColor(RED);
  display.print("Projekt");
  delay(3000);
  display.clearDisplay();
  for (i=1; i<3; i++){
     display.drawFastVLine(i*SCREEN_WIDTH/3, 0, SCREEN_HEIGHT, RED);
     display.drawFastHLine(0, i*SCREEN_HEIGHT/3, SCREEN_WIDTH, RED);
  }
  for (i=0; i<3; i++){
    for (j=0; j<3; j++){
      mreza(15+i*215,5+j*160);
  }
  }
    buttonState = digitalRead(buttonPin);
    buttonStated = digitalRead(buttonDOWN);
    buttonStateu = digitalRead(buttonUP);
    buttonStater = digitalRead(buttonRIGHT);
    buttonStatel = digitalRead(buttonLEFT);
    x=35; y=20;
    display.setTextColor(WHITE);
    display.setTextSize(4);
}


void loop() {
  // put your main cloode here, to run repeatedly
    buttonState = digitalRead(buttonPin);
    buttonStated = digitalRead(buttonDOWN);
    buttonStateu = digitalRead(buttonUP);
    buttonStater = digitalRead(buttonRIGHT);
    buttonStatel = digitalRead(buttonLEFT);

  display.setCursor(vx,vy);
  display.print("X");
  if (buttonState== LOW && buttonStated==LOW  && buttonStateu==LOW && buttonStater==LOW && buttonStatel==LOW){
    delay(100);
  } else if (buttonState==LOW && buttonStated==LOW && buttonStateu==LOW && buttonStater==HIGH && buttonStatel==LOW){
    vx+=60;
    delay(250);
    display.setCursor(vx,vy);
    display.print("X");
  } 
    if (buttonState== LOW && buttonStated==LOW  && buttonStateu==LOW && buttonStater==LOW && buttonStatel==LOW){
    delay(100);
  } else if (buttonState==LOW && buttonStated==LOW && buttonStateu==LOW && buttonStatel==HIGH && buttonStater==LOW){
    vx-=60;
    delay(250);
    display.setCursor(vx,vy);
    display.print("X");
  }
    if (buttonState== LOW && buttonStated==LOW  && buttonStateu==LOW && buttonStater==LOW && buttonStatel==LOW){
    delay(100);
  } else if (buttonState==LOW && buttonStater==LOW && buttonStateu==LOW && buttonStated==HIGH && buttonStatel==LOW){
    vy-=50;
    delay(250);
    display.setCursor(vx,vy);
    display.print("X");
  }
    if (buttonState== LOW && buttonStated==LOW  && buttonStateu==LOW && buttonStater==LOW && buttonStatel==LOW){
    delay(100);
  } else if (buttonState==LOW && buttonStated==LOW && buttonStater==LOW && buttonStateu==HIGH && buttonStatel==LOW){
    vy+=50;
    delay(250);
    display.setCursor(vx,vy);
    display.print("X");
  }
}
