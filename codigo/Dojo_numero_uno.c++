// C++ code
//
#define led_rojo_uno 13
#define led_rojo_dos 12
#define led_rojo_tres 11
#define led_amarillo_uno 10
#define led_amarillo_dos 9
#define led_amarillo_tres 8
#define led_verde_uno 7
#define led_verde_dos 6
#define led_verde_tres 5
#define buzzer 3
#define capacitor_pin 4

void setup()
{
  pinMode(led_rojo_uno, OUTPUT);
  pinMode(led_rojo_dos, OUTPUT);
  pinMode(led_rojo_tres, OUTPUT);
  pinMode(led_amarillo_uno, OUTPUT);
  pinMode(led_amarillo_dos, OUTPUT);
  pinMode(led_amarillo_tres, OUTPUT);
  pinMode(led_verde_uno, OUTPUT);
  pinMode(led_verde_dos, OUTPUT);
  pinMode(led_verde_tres, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(capacitor_pin, OUTPUT);
  digitalWrite(capacitor_pin, HIGH);
  Serial.begin(9600);
}

//Serial.println

void prender_apagar(long ms,int led_uno,int led_dos,int led_tres)
{
  digitalWrite(led_uno, HIGH);
  digitalWrite(led_dos, HIGH);
  digitalWrite(led_tres, HIGH);
  determinar_si_suena(led_uno,ms);
  digitalWrite(led_uno, LOW);
  digitalWrite(led_dos, LOW);
  digitalWrite(led_tres, LOW);
  delay(100);
}

void sonar(int hz,int frecuencia,int ms)
{
  for(int i=0; i<=ms; i+=frecuencia)
  {
  	tone(buzzer,hz,50);
  	delay(frecuencia);
  }
}

void determinar_si_suena(int led, long ms)
{
    switch(led)
  {
    case led_amarillo_uno:
    	sonar(260,2000,ms);
    break;
    case led_rojo_uno:
    	sonar(500,1000,ms);
    break;
    default:
    	delay(ms);
    break;
  }
}

void loop()
{
  prender_apagar(45000,led_verde_uno,led_verde_dos,led_verde_tres);
  prender_apagar(5000,led_amarillo_uno,led_amarillo_dos,led_amarillo_tres);
  prender_apagar(30000,led_rojo_uno,led_rojo_dos,led_rojo_tres);
  prender_apagar(5000,led_amarillo_uno,led_amarillo_dos,led_amarillo_tres);
}
