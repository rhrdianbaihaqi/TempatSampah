// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
#include <Servo.h>
#define TRIGGER_PIN  3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4// Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
Servo myservo;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int suara=12;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  myservo.attach(2);
  pinMode(suara,OUTPUT);
  digitalWrite(suara,HIGH);
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Jarak: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
 int jarak=0;
 jarak=sonar.ping_cm();
 Serial.print("ini jarak : ");
 Serial.println(jarak);
myservo.write(180); 
  if(jarak>0&&jarak<10){
    Serial.println("Membuka tempat sampah");

    myservo.write(0); 
    delay(5000);
    digitalWrite(suara,LOW);
    delay(100);
    digitalWrite(suara,HIGH);
    delay(3000);
  }
}
