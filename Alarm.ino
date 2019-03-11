
#include <TimeLib.h>
#include <TimeAlarms.h>
int ledPin = 13;
int node =0;
int buzzer=9;
AlarmId id;
int melody[] = {
  31, 33, 33, 35, 33, 0, 37, 35
};
void setup() {
  Serial.begin(9600);
    while (!Serial) ; 
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
 setTime(18,20,0,3,10,19); 
  Alarm.alarmRepeat(18,20,15,SetAlarm);  

}
void loop() {
  digitalClockDisplay();
  Alarm.delay(1000); // wait one second between clock display
}
void SetAlarm() {
  Serial.println("!!!!Alarm on!!!!!");
  Serial.println("The alarm will ring for 15 Sec");
   id = Alarm.timerRepeat(1, Repeats);    
  Alarm.timerOnce(10, OnceOnly);                  
}
void Repeats() {
    tone(buzzer,melody[node]);
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
    delay(50);
    node+=1;
    noTone(buzzer);
}

void OnceOnly() {
  Serial.println("Stop Alarm");
  Alarm.free(id);
  id = dtINVALID_ALARM_ID;
  node=0;
}
void digitalClockDisplay() {

  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
}

void printDigits(int digits) {
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
