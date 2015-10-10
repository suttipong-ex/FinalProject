#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
 
int count = 10;
static String logPass[] = {"123456#","654321#","987654#","456789#"};
static String ldUser[]  = {"54503260070", "54503160078", "54576556654","54523068754"};
static String nameUser[] ={"Umboon","Suttipog","Mongkol","Eksuwat"};
static String logROw[] = {"0","0","0","0","0"};
char dao = '*';
char sharp = '#';
char tempPass[6];
int flagA = 0;
int flagB = 0;
 
const byte ROWS = 4; // four rows
const byte COLS = 4;  //four Column
char keys[ROWS][COLS] = {
                        {'1','2','3','A'},
                        {'4','5','6','B'},
                        {'7','8','9','C'},  
                        {'*','0','#','D'},
};
byte rowPins[ROWS] = {30,31,32,33};
byte colPins[COLS] = {34,35,36,37};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS,COLS );
LiquidCrystal_I2C lcd(0x27,16,2);// set the LCD address to 0x27 for a 16*2 lines display
                                 // set the LCD address to 0x3F for a 20*4 lines display
void setup() {
            // put your setup code here, to run once:
            lcd.begin();
            Serial.begin(9600);
            lcd.setCursor(1,0); // set cursor to use at 0 row start from 1
            lcd.print("Hello Zad&kao!");
            delay(2000);
}
//This code is controlling when they locking by password
//----------------------------------------------------
void getKeypad(){ 
  String getPassTest = "";
  lcd.setCursor(1,0); // set cursor to use at 0 row start from 1
  lcd.print(" Put your pin : ");
  int i = 0;
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    Serial.print(key);
    if(count <=16){
      //getArrPassTemp();
       lcd.setCursor(count,1);  
       lcd.print(dao); 
       tempPass[count-10] = key; // since column 10-16
       count++;
       if(key == sharp){
          if(count == 17){
            clearScreen();
            Serial.print("Charp Okay"); 
            Serial.println();
            for(int b=0;b<6;b++){
                  Serial.print(tempPass[b]);
             }  
             String strGetPass(tempPass);
             getPassTest = strGetPass;  
             Serial.println(); 
             Serial.println(getPassTest);
             // check password of array here!  
             for(int chkPass=0; chkPass < 4 ;chkPass++){
                  Serial.println(logPass[chkPass]);
                  if(getPassTest == logPass[chkPass]){
                      Serial.println("Password okay");
                  
                 }else{
                      Serial.println("Password fail"); 
  
                 }
             }   
          } 
       }else if(count == 17){
           invalidCode();
           count = 10 ;
       }
    }else{ 
           invalidCode();
           count=10;     
      }
   }
}

void invalidCode(){
           Serial.println();
           lcd.setCursor(0,1);
           lcd.print("     Try again     ");
           delay(1000);
           clearScreen();
           getKeypad();
}
void validCode(){
  
  
}
void unlockBike(){
  
}
//-----------------------------------------------------

void clearScreen(){
  lcd.setCursor(0,0);
  lcd.print("                 ");
  lcd.setCursor(0,1);
  lcd.print("                ");  
}

void loop() {
    // put your main code here, to run repeatedly:
    getKeypad();
    
    
}
