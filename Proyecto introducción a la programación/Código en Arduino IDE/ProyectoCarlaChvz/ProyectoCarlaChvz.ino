int LED1 = 12; //azul
int LED2 = 10; //rojo
int LED3 = 8; //amarillo
int pot=A1;
int mic=2;
int valor;

void setup() {

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(mic, INPUT);
  Serial.begin(9600);
}

void loop() {
valor=digitalRead(mic);
if  (valor==LOW)
  {  
      pot=analogRead(A1);
      Serial.println(pot);
     
   if (pot < 100) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);}
  
    if (pot>=100 && pot < 145)
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);}
   
    if (pot>=145 && pot < 290)
      { digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);}

    if (pot>=290 && pot < 435)
     { digitalWrite(LED1, LOW);
       digitalWrite(LED2, LOW);
       digitalWrite(LED3, HIGH);}
     
    if (pot>=435 && pot < 580)
     { digitalWrite(LED1, HIGH);
       digitalWrite(LED2, HIGH);
       digitalWrite(LED3, LOW);}
     
    if (pot>=580 && pot < 725) 
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);}
    
    if (pot>=725 && pot<870)
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);}
    
    if (pot>=870 && pot<1020){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);}
    }

}
