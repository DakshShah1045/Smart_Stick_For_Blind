const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;
void setup()
{ 

 Serial.begin(9600); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

 pinMode(6, OUTPUT); // Connect LED Pin D6
 pinMode(5, OUTPUT); // Connect Buzzer Pin D5

}
void loop()
{
 digitalWrite(5, HIGH); 
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
Serial.println("Distance: ");
Serial.println(distanceCm);
delay (100);
// See the Ultrasonic Sensor Value in Serial Monitor



if(distanceCm < 25)  // You can Change the value 
{
  
  digitalWrite(5, HIGH);  // Buzzer ON
  digitalWrite(6, HIGH);  // LED ON 
  
}

else
{
    
    digitalWrite(6,LOW);  // LED OFF 
}
}
