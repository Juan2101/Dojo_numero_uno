// C++ code
//
#define led_rojo_uno 13
#define led_rojo_dos 12
#define led_amarillo_uno 11
#define led_amarillo_dos 10
#define led_verde_uno 9
#define led_verde_dos 8
#define buzzer 6

void setup()
{
  pinMode(led_rojo_uno, OUTPUT);
  pinMode(led_rojo_dos, OUTPUT);
  pinMode(led_amarillo_uno, OUTPUT);
  pinMode(led_amarillo_dos, OUTPUT);
  pinMode(led_verde_uno, OUTPUT);
  pinMode(led_verde_dos, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

//Serial.println

void prender_apagar(long ms,int led_uno,int led_dos)
{
  digitalWrite(led_uno, HIGH);
  digitalWrite(led_dos, HIGH);
  determinar_si_suena(led_uno,ms);
  digitalWrite(led_uno, LOW);
  digitalWrite(led_dos, LOW);
  delay(100);
}

void sonar(int hz,int frecuencia,int ms)
{
  for(int i=0; i<=ms; i+=frecuencia)
  {
  	tone(buzzer,hz,200);
  	delay(frecuencia);
  }
}

void determinar_si_suena(int led, long ms)
{
    switch(led)
  {
    case led_amarillo_uno:
    	sonar(261,2000,ms);
    break;
    case led_rojo_uno:
    	sonar(440,1000,ms);
    break;
    default:
    	delay(ms);
    break;
  }
}

void loop()
{
  prender_apagar(4500,led_verde_uno,led_verde_dos);
  prender_apagar(5000,led_amarillo_uno,led_amarillo_dos);
  prender_apagar(30000,led_rojo_uno,led_rojo_dos);
  prender_apagar(5000,led_amarillo_uno,led_amarillo_dos);
}
