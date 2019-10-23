#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
int Value = 0;
const int trigPin = 6;
const int echoPin = 7;
float duration, distance;
 
void setup() {
  pinMode(2, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
 
void loop() {
     Value = GetDistance();
     if(GetDistance() < 5){
     	tone(8, NOTE_C4);
     	delay(10);
     }
     else if(GetDistance() <10){
     	tone(8, NOTE_D4);
     	delay(10);
     }
     else if(GetDistance() < 15){
     	tone(8, NOTE_E4);
     	delay(10);
     }

}
int GetDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  if (duration == 0)
  {
    pinMode(echoPin, OUTPUT);
    digitalWrite(echoPin, LOW);
    delay(1);
    pinMode(echoPin, INPUT);
  }
  distance = (duration *.0343) /2;
  delay(100);
  Serial.print("\t");
  Serial.println(distance);
  return distance;
}


/*
TEST MEDIAN CODE


unsigned long NewPing::ping_median(uint8_t it, unsigned int max_cm_distance) {
	unsigned int uS[it], last;
	uint8_t j, i = 0;
	unsigned long t;
	uS[0] = NO_ECHO;

	while (i < it) {
		t = micros();                  // Start ping timestamp.
		last = ping(max_cm_distance);  // Send ping.

		if (last != NO_ECHO) {         // Ping in range, include as part of median.
			if (i > 0) {               // Don't start sort till second ping.
				for (j = i; j > 0 && uS[j - 1] < last; j--) // Insertion sort loop.
					uS[j] = uS[j - 1];                      // Shift ping array to correct position for sort insertion.
			} 
			else j = 0;              // First ping is sort starting point.
			uS[j] = last;              // Add last ping to array in sorted position.
			i++;                       // Move to next ping.
		} else it--;                   // Ping out of range, skip and don't include as part of median.

		if (i < it && micros() - t < PING_MEDIAN_DELAY)
			delay((PING_MEDIAN_DELAY + t - micros()) / 1000); // Millisecond delay between pings.

	}
	return (uS[it >> 1]); // Return the ping distance median.
}
END TEST

*/