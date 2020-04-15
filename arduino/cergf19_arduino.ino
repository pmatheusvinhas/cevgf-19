
#include <Ticker.h>

/**************************************/
 /*
  * Só mexer nos DEFINES.
 */
/**************************************/

#define M_RPM 4 //Motor Mabuchi 4RPM
#define M_PIN 3 //Pino do Motor
/*Pinos de Controle Direcional do Driver de Motor. Utilizei o ci L293D" */
#define M_DRIVER_PIN1 4
#define M_DRIVER_PIN2 5

void inhale();
void exhale();

//double a = ;
double cyclePerTime = (double(1)/(M_RPM/double(60)))*double(1000);
double Ti = cyclePerTime/double(2), Te = cyclePerTime/double(2);
int pwmDutyCycle;
int TiTe = 11; //1.1 , 1.2 , 1.3  
int pwmPercent;

/* KEYWORD 2 -> T ms */
Ticker timer1(inhale, Ti);
Ticker timer2(exhale, Te); 

String sdata="";  // Initialised to nothing.
byte test,start;

void setup()
{
  pinMode(M_PIN, OUTPUT);
  pinMode(M_DRIVER_PIN1, OUTPUT); digitalWrite(M_DRIVER_PIN1, LOW);
  pinMode(M_DRIVER_PIN2, OUTPUT); digitalWrite(M_DRIVER_PIN2, HIGH);
  pinMode(LED_BUILTIN, OUTPUT); digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(115200);
  Serial.println("CERGF-19 beta do beta v0.2.");
  //Serial.println(cyclePerTime);
  timer1.start();
}
void loop()
{
  timer1.update();
  timer2.update();

  String valStr;

  if (Serial.available()) {
      sdata = Serial.readString();

         // Process command in sdata.
         switch( sdata.charAt(0) ) {
         case 't':
            //test = 1;
            //Serial.println("Test");
            if (sdata.length()>1){
               TiTe = (sdata.substring(1)).toInt();
            }
            Serial.print("Ti:Te: ");
            Serial.println(TiTe);
            break;
         case 'v':
            if (sdata.length()>1){
               valStr = sdata.substring(1);
               pwmPercent = valStr.toInt();
               pwmDutyCycle = map(pwmPercent,0,100,0,255);
            }
            Serial.print("PWM: ");
            Serial.print(pwmPercent);
            Serial.println("%");
            break;
         default: Serial.println(sdata);
         } 
         sdata = "";
   } 

  
  switch (TiTe) {
    case 11:
      //Serial.println("Ti:Te = 1:1");
      Ti = cyclePerTime/double(2);
      Te = cyclePerTime/double(2);
    break;
    
    case 12:
      //Serial.println("Ti:Te = 1:2");
      Ti = cyclePerTime/double(2);
      Te = cyclePerTime/double(4);
    break;
    
    case 13:
      //Serial.println("Ti:Te = 1:3");
      Ti = cyclePerTime/double(2);
      Te = cyclePerTime/double(6);
    break;

    default:
      //Serial.println("Ti:Te = 1:1");
      Ti = cyclePerTime/double(2);
      Te = cyclePerTime/double(2);
  }

  timer1.interval(Ti);
  timer2.interval(Te);
  
}

void inhale() {
  //Serial.println("750ms... 1" );
  timer1.pause();
  timer2.start();
  //Serial.println(timer1.elapsed());
  analogWrite(M_PIN, pwmDutyCycle);
  digitalWrite(LED_BUILTIN, LOW);
   
}

void exhale() {
  //Serial.println("750ms... 2");
  timer2.pause();
  timer1.start();
  //Serial.println(timer2.elapsed());
  analogWrite(M_PIN, pwmDutyCycle);
  digitalWrite(LED_BUILTIN, HIGH);
}
