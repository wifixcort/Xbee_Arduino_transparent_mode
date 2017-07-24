#include <SoftwareSerial.h>

const byte interruptPin = 0;//In arduino MEGA RX 19. TX 18
String msg = "";//Incomming message

SoftwareSerial dbSerial(2, 3);//Used for debug

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dbSerial.begin(9600);
  //  attachInterrupt(digitalPinToInterrupt(interruptPin), serial_read, HIGH);
  for(uint8_t i = 4; i < 12; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }//end for
}//end loop

void loop() {
  serial_read();
}

void emu_plc(String msg){
  if(msg == "D4 OFF\n"){
    digitalWrite(4, HIGH);
  }else if(msg == "D4 ON\n"){
    digitalWrite(4, LOW);
  }else   if(msg == "D5 OFF\n"){
    digitalWrite(5, HIGH);
  }else if(msg == "D5 ON\n"){
    digitalWrite(5, LOW);
  }else   if(msg == "D6 OFF\n"){
    digitalWrite(6, HIGH);
  }else if(msg == "D6 ON\n"){
    digitalWrite(6, LOW);
  }else   if(msg == "D7 OFF\n"){
    digitalWrite(7, HIGH);
  }else if(msg == "D7 ON\n"){
    digitalWrite(7, LOW);
  }else  if(msg == "D8 OFF\n"){
    digitalWrite(8, HIGH);
  }else if(msg == "D8 ON\n"){
    digitalWrite(8, LOW);
  }else  if(msg == "D9 OFF\n"){
    digitalWrite(9, HIGH);
  }else if(msg == "D9 ON\n"){
    digitalWrite(9, LOW);
  }else   if(msg == "D10 OFF\n"){
    digitalWrite(10, HIGH);
  }else if(msg == "D10 ON\n"){
    digitalWrite(10, LOW);
  }else   if(msg == "D11 OFF\n"){
    digitalWrite(11, HIGH);
  }else if(msg == "D11 ON\n"){
    digitalWrite(11, LOW);
  }else{
    dbSerial.print("Known command = ");
//    String msd = "HOLA\n";
    for(uint8_t i = 0; i<7; i++){
      dbSerial.println(msg[i], HEX);      
    }
    //dbSerial.println(msg.c_str());
    
    msg = "";
  }//end if
}

void serial_read(){
  char _bite;
//  sei();//Disable hardware interrupts for a moment
  while(Serial.available()> 0){
    delay(1);//Do not delet this delay
    if(Serial.available()>0){
      _bite = (char)Serial.read();
      msg += _bite;
      if(_bite == '\n'){
//        msg += "\0";
        //dbSerial.println(msg);//Do what you whant whit your message
        emu_plc(msg);//Call custom function for do something
        msg = "";//Clean message for new one
        break;
      }//end if
    }//end if
  }//end while
//  cli();//reenabling hardware interrupts
}//end serial_read
