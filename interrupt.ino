#define LED_PIN 13
volatile bool trigerred = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  digitalWrite(LED_PIN, LOW);
  cli();
  EICRA |= (1 << ISC11) | (1 << ISC10);
  EIMSK |= (1 << INT1);
  sei();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(trigerred){
    digitalWrite(LED_PIN, HIGH );
    delay(500);
    digitalWrite(LED_PIN, LOW);
    trigerred = false;
  }

}
ISR(INT1_vect){
  trigerred = true;
}
