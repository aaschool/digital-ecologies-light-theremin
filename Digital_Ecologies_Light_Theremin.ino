/* Digital Ecologies Light Theremin */

#define analogPin A0 // ESP8266 Analog Pin ADC0 = A0 used for the analogue light sensor
#define LEDPin D0 // ESP8266 Digital Pin used for the LED
#define buzzer D1 // ESP8266 Digital PWM Pin used for the buzzer

int val = 0;  // Variable to store analogue utput 
int ledval = 0;

void setup()
{
  Serial.begin(115200); // Initialize serial communication at 115200 
  pinMode(buzzer, OUTPUT);
  tone(buzzer, 1000); // Send 1KHz sound signal to the buzzer
  delay(1000);        // for 1 second
  noTone(buzzer);     // Stop sound
  delay(1000);        // Wait for 1 second
}

void loop()
{
  val = analogRead(analogPin); // Read the Analog Input value 

  ledval = map(val, 150, 850, 0, 50);

  analogWrite(LEDPin, ledval);
  delay(10);

  if (val<700) {
    tone(buzzer, val);
  } else {
    noTone(buzzer);
  }
 
  // Print the output in the Serial Monitor 
  Serial.print("Value = ");
  Serial.println(val);
  
}