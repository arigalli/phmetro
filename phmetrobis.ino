/**
  *  Full example for PH4502C_Sensor.h
  *  By: Nathanne Isip
  *  27/06/2024
  */


// Define the pH level pin and temperature pin
#define ph A0  //ph

float mvfinal,psmedia;
int arrayps[500];
char mesage;

void setup() {
    Serial.begin(115200);
    Serial.println("Starting PH4502C Sensor...");
    Serial.println("para medir oprima 1");
    }

void loop() {

  while(Serial.available()>0){
mesage=Serial.read();  //queda esperando el numero 1 para medir
Serial.println(mesage);
if(mesage=='1'){
      mvfinal=0;
      for(int n=1;n<100;n++){
        for(int l=1;l<500;l++){
        int ps=analogRead(ph);
        arrayps[l]=ps;
        }
        psmedia=0;
        for(int a=0;a<500;a++){
        psmedia=psmedia+arrayps[a];
        }
        psmedia=psmedia/500;
      float vph=1000*(psmedia*5.000/1023.000);
      mvfinal=mvfinal+vph;
      delay(1000);
      Serial.println(n);
      }
    Serial.print("Medición");  
    Serial.print(" ");
    Serial.println(mvfinal/1000);
}
Serial.println("para medir oprima 1");
  }
}
