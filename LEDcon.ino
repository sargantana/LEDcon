
    /*
    Bluetooth RGB LED Controller
    sargantana 2017
    define pins for the color channels below
    define default paring BT Pin for HC-05
    */

   #include <EEPROM.h> 			//include EEPROM libary
 
    int LED_R = 10; 			//define pin for RED Channel 1
    int LED_G=11; 				//define pin for GREEN Channel 1
    int LED_B=9;  				//define pin for BLUE Channel 1
    int LED_R2 = 5; 			//define pin for RED Channel 2
    int LED_G2=6; 				//define pin for GREEN Channel 2
    int LED_B2=3; 				//define pin for BLUE Channel 2
    int standard_pin=1234;		//define BT Pairing PIN (if needed)
    int red;
    int green;
    int blue;
    int accion=0;
    int bluetooth=2;			
    int port=0;
    int first_start;
//_______________________________
 
    void setup() 
    {
      pinMode(bluetooth,OUTPUT); 
      digitalWrite(bluetooth,HIGH);
      
      Serial.begin(9600);
      
      first_start=EEPROM.read(0);
      
      if(first_start!=1){
        color(0,255,255);			//LED Channel 1 is red: setup phase
        programer(standard_pin);	//Stuff happens
        EEPROM.write(0,1);			
        color(255,0,255);			//LED Channel 1 is green: ready to use
      }
    }
//_______________________________

    void color(int red, int green, int blue){
        
        if(port==1){
          analogWrite(LED_R, red);
          analogWrite(LED_G, green);
          analogWrite(LED_B, blue);
        }
        if(port==2){
          analogWrite(LED_R2, red);
          analogWrite(LED_G2, green);
          analogWrite(LED_B2, blue);
        }
        if(port==3){
          analogWrite(LED_R, red);
          analogWrite(LED_R2, red);
          analogWrite(LED_G, green);
          analogWrite(LED_G2, green);
          analogWrite(LED_B, blue);
          analogWrite(LED_B2, blue);
        
        }
        
    }
//_______________________________

    void programer(int pin){
        digitalWrite(bluetooth,LOW);
        delay(250);
        digitalWrite(bluetooth,HIGH);
        delay(5000);
        Serial.print("AT");
        delay(1000);
        Serial.print("AT+NAME"+btname);
        delay(1000);
        Serial.print("AT+PIN"+pin);
        delay(1000);
        digitalWrite(bluetooth,LOW);
        delay(250);
        digitalWrite(bluetooth,HIGH);
    }
//_______________________________
    void loop() 
    {          
      
      while (Serial.available() > 0) {
        
        accion = Serial.parseInt();

           if(accion==1){
              port=Serial.parseInt();
              red = Serial.parseInt();
              green = Serial.parseInt();
              blue = Serial.parseInt();
           }
           if (Serial.read() == '\n') {
               color(red,green,blue);
           }
      }
      if(accion==2){
              color(0,255,255);
              delay(500);
              color(255,0,255);
              delay(500);
              color(255,255,0);
              delay(500);
      }
      if(accion==3){
        int pin = Serial.parseInt();
        
        if (Serial.read() == '\n') {
          color(255,0,0);
          programer(pin);
          accion=0;
          color(0,255,0);
        }  
        
      }
      
     
    }