/*const int led=2;
const int saklar=5;
int state = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode (saklar, INPUT_PULLUP);
  pinMode (led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(saklar);
  if(state==1){
    digitalWrite(led, HIGH);
  }else if(state==0){
    digitalWrite(led, LOW);
  }
}
*/

const int led=3;
int state = 0;
int potensio = A1;
int pwm = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (potensio, INPUT);
  pinMode (led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = analogRead(potensio);
  pwm = map(state, 0, 1023, 0, 255);
  analogWrite(led, pwm);
  Serial.println(pwm);
}
