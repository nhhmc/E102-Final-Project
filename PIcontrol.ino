 
/* 
 Step response of RC circuit and PI controller after  
 a switched 2.5V step reference input.  
 
 The circuit: 
 * switch connected from pin 2 to GND 
 * input Vin from pin 9  
 * output of circuit read at analog pin A0   
*/ 
 
//PIN SETTINGS 
const int yPin = A0;  // Analog read pin   
const int uPin = 9;    // Analog write pin (PWM) 
const int switchPin = 2;     // input pin for the switch  
boolean switchVal = HIGH;    // declare initial switch pin state 
 
// Parameter Settings 
int time = 0;  // initialize time 
const float r = 2.5; //2.5V  input, equal to yss


// PI controller coeff
const float b0 = 2.435; 
const float b1 = -2.349;

 
// Initial Values for internal signals 
float y=0; 
float e_init =0.0;
float u_init =0.0;
 
void setup() {  
  pinMode(switchPin, INPUT);  //set switch pin to input mode 
  digitalWrite(switchPin,HIGH); //initialize to start with pull up voltage      
  Serial.begin(9600);  
} 
 
void loop() { 
  //WAIT FOR SWITCH 
   while(switchVal == HIGH)  // repeat this loop until switch is turned on 
                            // (switchVal will go LOW when switch is turned on) 
  {    
    e_init =0.0;
    u_init =0.0;
    time = 0.0;
    analogWrite(uPin,0);   
    switchVal = digitalRead(switchPin);  // read switch state 
  } 
   
 // READ CIRCUIT OUTPUT 
     int sensorVal = analogRead(yPin); 
      // convert to volts 
      y=sensorVal*(5.0/1023.0); 

// Find e and u
float e = r-y;
float u = u_init + (b0*e) + (b1*e_init);

if  (u > 5) u=5;
else if (u<0) u =0;
      
// WRITE feedback 
     int uVal=u*(255/5); 
     analogWrite(uPin,uVal); 

// Update e and u values 
e_init = e;
u_init = u;
   
 // print the results to the serial monitor:  
  Serial.print(time++);   
  Serial.print(" "); Serial.print (y, 4); // limit to 4 decimal points 
  Serial.print(" "); Serial.println (u, 4);  

   
  // WAIT FOR NEXT SAMPLE 
  delay(100); //sample frequency 10Hz 
  switchVal = digitalRead(switchPin);
}
    // read switch state