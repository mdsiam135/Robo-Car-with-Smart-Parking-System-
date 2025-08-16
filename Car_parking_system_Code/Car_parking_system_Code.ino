#include <Wire.h> // Library use for I2C communiation
#include <LiquidCrystal_I2C.h> // Library for interfacing with LCD Display  
LiquidCrystal_I2C lcd(0x27,16,2);   // Address iniatialize for LCD Display
#include <Servo.h> 
Servo myservo; 
int IR1 = 2; 
int IR2 = 3; 

int Slot = 3 
int flag1 = 0; 
int flag2 = 0;
void setup() {
  Serial.begin(9600); // Iniatialize serial communiation with 9600 buads rate
    lcd.init(); 
    lcd.backlight(); 
pinMode(IR1, INPUT); 
pinMode(IR2, INPUT); 

myservo.attach(4); 
myservo.write(140);  // normal position

lcd.setCursor (0,0);
lcd.print("     Team-2 ");
lcd.setCursor (0,1);
lcd.print("  Topic name: ");
delay (5000); // 5000 ms = 5s

lcd.setCursor (0,0);
lcd.print("    SMART CAR ");
lcd.setCursor (0,1);
lcd.print(" PARKING SYSTEM ");

delay (5000);
lcd.setCursor (0,0);
lcd.print("  Team members");
lcd.setCursor (0,1);
lcd.print("Siam,Afroza,Emon ");
delay (5000);

lcd.setCursor (0,0);
lcd.print("  STUDENTS OF ");
lcd.setCursor (0,1);
lcd.print("  R.P.SHAHA UV  ");
delay (5000);
lcd.setCursor (0,0);
lcd.print(" COURSE TEACHER ");
lcd.setCursor (0,1);
lcd.print(" TANJINA AKTER  ");
delay (5000);
lcd.clear();  
}
void loop(){ 
if(digitalRead (IR1) == LOW && flag1==0){
if(Slot>0){
flag1=1;
if(flag2==0){
myservo.write(0); /// Gate on
Slot = Slot-1; 
}
}else{
lcd.setCursor (0,0);
lcd.print("    SORRY :(    ");  
lcd.setCursor (0,1);
lcd.print("  Parking Full  "); 
delay (3000);
lcd.clear(); 
}
}
if(digitalRead (IR2) == LOW && flag2==0) {
flag2=1;
if(flag1==0) {
myservo.write(0); 
Slot = Slot+1;
    }
}
if(flag1==1 && flag2==1){
delay (1000);
myservo.write(140);  // Normal position 
flag1=0, flag2=0;
}
lcd.setCursor (0,0);
lcd.print("    WELCOME!    ");
lcd.setCursor (0,1);
lcd.print("Slot Left: ");
lcd.print(Slot);
}
