/*
 * Shinyei PPD42NS Particle Sensor.    
 * 
 * Sensor Pin 1 => Arduino GND   
 * Sensor Pin 3 => Arduino +5VDC   
 * Sensor Pin 4 => Arduino Digital Pin 3 
 http://www.seeedstudio.com/depot/grove-dust-sensor-p-1050.html
 http://www.sca-shinyei.com/pdf/PPD42NS.pdf
*/

#define PPD42NS_PIN 6

unsigned long sampletime_ms = 15000;
unsigned long starttime;
unsigned long duration = 0;
unsigned long elapsedtime = 0;
unsigned long timestamp = 0;

float ratio = 0;
float concentration = 0;

String output = "";

/*
 * GP2Y1010AU0F Dust Sensor.    
 * 
 *
 * http://www.waveshare.com  
*/
#define        COV_RATIO                       0.2            //ug/mmm / mv
#define        NO_DUST_VOLTAGE                 400            //mv
#define        SYS_VOLTAGE                     5000   

#define GP2Y1010AU0F_ILED 7
#define GP2Y1010AU0F_VOUT A1

float density, voltage;
int   adcvalue;

/*
 * LDR
*/
#define LIGHT_SENSOR A0

void setup() {
  Serial.begin(115200);
  initPPD42NS();
  starttime = millis(); 
}

void loop() {
  updatePPD42NS();
  if (elapsedtime > sampletime_ms) {
    starttime = millis();

   output = "";
   output.concat(getPPD42NS());
   output.concat(",");
   output.concat(getGP2Y1010AU0F());
   output.concat(analogRead(LIGHT_SENSOR));
   output.concat("F");
   //Serial.print(concentration);
   Serial.print(output);// particles per .01 cu ft
  }
   
}
