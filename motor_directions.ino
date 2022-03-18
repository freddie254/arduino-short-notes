/*
 * Changing directions in an inexpensive 12v dc motor.
 * there are tons of usage....if one is on a tight budget due to the inexpensive factor                                      
 * As trivial as it is ...the basic rule remain "change polarities change direction"
 *by exploiting two relays we can change polarities.  
 *If another relay is added this will ensure that the motor can be stopped
 *in the code----> this is my_relay3
 *my_relay1 and my_relay2 will be used to change polarities 
 *while my_relay3 will be used to cut power once all motor movements achieved
 *
 *To begin +12v  will be tied to com in my_relay1
 *12v ground to com in my_relay2
 *my_relay3 will be used to cut off the +12v before my_relay1
 *
 *the circuit is as
 *+12v in the motor to  normally closed of my_relay1 and to normally open of my_relay2 
 *the ground in the motor to  normally open of my_relay1 and to normally close of my_relay2 
 *
 */
byte my_relay1 = A1;
byte my_relay2 = A2;
byte my_relay3 = A3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(my_relay2, OUTPUT);
  pinMode(my_relay3, OUTPUT);
  pinMode(my_relay1, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  //to kill motion at any one time my_relay3 will be set to low.
  for(int i = 0; i < 10; i++){
    digitalWrite(my_relay1, LOW);
    digitalWrite(my_relay2, LOW);
    digitalWrite(my_relay3, HIGH);
  
    delay(5000);
  
    digitalWrite(my_relay1, LOW);
    digitalWrite(my_relay2, LOW);
       
    digitalWrite(my_relay3, HIGH);
  }
  digitalWrite(my_relay3, LOW);
}
