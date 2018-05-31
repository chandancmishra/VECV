                                                                                                                                                                               
// Calibration & Nonlinear curve
#include<EEPROM.h>

const int numReadings = 20;

int readings1[numReadings];      // the readings from the analog input
int readIndex1 = 0;              // the index of the current reading
int total1 = 0;                  // the running total
int average1 = 0;                // the average

//int readings2[numReadings];
int readIndex2 = 0;              // the index of the current reading
int total2 = 0;
int average2=0;

int readings3[numReadings];
int readIndex3 = 0;              // the index of the current reading
int total3 = 0;
int average3=0;

int readings4[numReadings];
int readIndex4 = 0;              // the index of the current reading
int total4 = 0;
int average4=0;

int total_raw=0;
int previous_raw=0;
int raw_val,new_val,data1,value;
int value1,value2,value3,value4;
int init_val1=value1;
int init_val2=value2;
int init_val3=value3;
int init_val4=value4;

word new_A1_val,new_A2_val,new_A3_val,new_A4_val;

int addr1 = 4;
int addr2 = 5;
int addr3 = 6;
int addr4 = 7;
int default0=0;

int val=value;

// CAL
char data = 0;
#define sensorG1 A0
#define sensorG2 A1
#define sensorG3 A3 
#define sensorG4 A4
//Variable for storing received data
//float duration, distance;
word Faxle=0;
word Raxle=0;
word Raxle2=0;
word Raxle3=0;
word FA_distance;
word Faxle_raw,Raxle_raw,Raxle2_raw,Raxle3_raw,Faxle_raw_Avg;
int distance1_raw,distance2_raw,distance3_raw,distance4_raw;
int distance1_raw1,distance2_raw1,distance3_raw1,distance4_raw1;
float distance1,distance2,distance3,distance4,angle1,angle2,angle3,angle4;
int inputPin = sensorG1;

void setup()
{

// CAlibration and Non Linear
val=new_val;


  
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
    pinMode(13, OUTPUT);  //Sets digital pin 13 as output pin

    //pinMode(9,OUTPUT);
 pinMode(sensorG1,INPUT);
 pinMode(sensorG2,INPUT);
 pinMode(sensorG3,INPUT);
 pinMode(sensorG4,INPUT);
 pinMode(A2,INPUT);

 for (int thisReading = 0; thisReading < numReadings; thisReading++) 
 {
    readings1[thisReading] = 0;
    
}

 for (int thisReading = 0; thisReading < numReadings; thisReading++) 
 {
    readings3[thisReading] = 0;
    
}

 for (int thisReading = 0; thisReading < numReadings; thisReading++) 
 {
    readings4[thisReading] = 0;
    
}
}
void loop()
{

 
distance1_raw1=analogRead(sensorG1);
distance2_raw=analogRead(sensorG2);
distance3_raw1=analogRead(sensorG3);
distance4_raw1=analogRead(sensorG4); 
  
delay(10);
  //digitalWrite(9,HIGH);
/////////////////////////////////////////////////////
  //avg of analog values
  // subtract the last reading:
  total1 = total1 - readings1[readIndex1];
  // read from the sensor:
  readings1[readIndex1] = distance1_raw1;
  // add the reading to the total:
  total1 = total1 + readings1[readIndex1];
  // advance to the next position in the array:
  readIndex1 = readIndex1 + 1;

  // if we're at the end of the array...
  if (readIndex1 >= numReadings) {
    // ...wrap around to the beginning:
    readIndex1 = 0;
  }

  // calculate the average:
  average1 = total1 / numReadings;
// distance1_raw = total1 / numReadings;
 //distance1_raw= abs(distance1_raw);
 distance1_raw= average1;
  // send it to the computer as ASCII digits
 // Serial.println(average);
//////////////////////////////////////////////////////////

/////////////////////////////////////////////////////
  //avg of analog values
  // subtract the last reading:
  total3 = total3 - readings3[readIndex3];
  // read from the sensor:
  readings3[readIndex3] = distance3_raw1;
  // add the reading to the total:
  total3 = total3 + readings3[readIndex3];
  // advance to the next position in the array:
  readIndex3 = readIndex3 + 1;

  // if we're at the end of the array...
  if (readIndex3 >= numReadings) {
    // ...wrap around to the beginning:
    readIndex3 = 0;
  }

  // calculate the average:
 // average = total / numReadings;
 average3 = total3 / numReadings;

 distance3_raw= average3; 
 // send it to the computer as ASCII digits
 // Serial.println(average);
//////////////////////////////////////////////////////////


/////////////////////////////////////////////////////
  //avg of analog values
  // subtract the last reading:
  total4 = total4 - readings4[readIndex4];
  // read from the sensor:
  readings4[readIndex4] = distance4_raw1;
  // add the reading to the total:
  total4 = total4 + readings4[readIndex4];
  // advance to the next position in the array:
  readIndex4 = readIndex4 + 1;

  // if we're at the end of the array...
  if (readIndex4 >= numReadings) {
    // ...wrap around to the beginning:
    readIndex4 = 0;
  }

  // calculate the average:
 // average = total / numReadings;
 //distance4_raw = total4 / numReadings;
 average4 = total4 / numReadings;
 distance4_raw= average4;
  // send it to the computer as ASCII digits
 // Serial.println(average);
//////////////////////////////////////////////////////////
//*/

angle1=map(distance1_raw,315,750,40,-40);
angle2=map(distance2_raw,315,750,40,-40);
angle3=map(distance3_raw,315,750,40,-40);
angle4=map(distance4_raw,315,750,40,-40);

//distance3=map(distance3_raw,235,950,10,0);
//distance4=map(distance4_raw,235,950,10,0);
total_raw=distance1_raw+distance3_raw+distance4_raw;

//previous_raw=
//diff_raw=


  //////////// Unloading////////////////

  //Non- Linear Multimap


  // out[] holds the values wanted in cm
  float out1[] = {5000,3825,3600,3400,3200,3100,3050,3000,2700,2360};
//float in1[]  = {345,346,348,350,351,363,365,370};
//float in1[]  = {220,250,270,272,276,280,282,300,303,308};
//float in1[]  = {210,240,250,256,268,262,290,320,323,328};
//float in1[]  = {210,240,250,256,268,262,278,290,295,300};
float in1[]  = {210,240,250,256,268,290,300,319,323,345};
 // float in1[]  = {276,280,282,300,303,315,330,350,370};
Faxle_raw = FmultiMap(distance1_raw, in1, out1, 10);

  float out4[] = {1975,3200,4000,5000,5800,6500,8500,8700};
 // float in4[]  = {634,691,705,748,758,768,790,795,840};
   float in4[]  = {650,680,705,748,758,768,790,810};
  Raxle3_raw = FmultiMap(distance4_raw, in4, out4, 8);
  
  



//Average
//Faxle=(Faxle_raw+Raxle_raw)/2;
//Faxle=Faxle_raw_Avg;

Faxle=Faxle_raw;
//Raxle=(Raxle2_raw+Raxle3_raw)/2;
Raxle=Raxle3_raw;
previous_raw=total_raw;

   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      //Serial.print(data);          //Print Value inside data in Serial monitor
      //Serial.print("\n");        
      if(data == '0')    // Checks whether value of data is equal to 1
         {
//Faxle= 2000;
//Raxle= 1500;
Serial.print((int)Faxle);
Serial.print("|");
Serial.print((int)Raxle);
Serial.print("|");
//Serial.print((int)Raxle2);
//Serial.print("|");
//Serial.print((int)Raxle3);
//Serial.print("|");

Serial.print((int)distance1_raw);
Serial.print("|");
//Serial.print((int)distance2_raw);
Serial.print((int)distance1_raw1);
//Serial.print(default0);
Serial.print("|");
//Serial.print(default0);
Serial.print((int)distance3_raw);
//Serial.print((int)distance4_raw1);
Serial.print("|");
//Serial.print(default0);
Serial.print((int)distance4_raw);
Serial.print("|");

         digitalWrite(13, HIGH);   //If value is 1 then LED turns ON
         delay(10);
         }
      else if(data == '1')
      //  Checks whether value of data is equal to 0
       
         
         {
              //If value is 0 then LED turns OFF
         
//         Faxle= 2000;
//Raxle= 1500;
//Raxle2 = 3000;
Serial.print((int)Faxle);
//Serial.print((int)Faxle);
Serial.print("|");
Serial.print((int)Raxle);
Serial.print("|");
Serial.print((int)Raxle2);
Serial.print("|");


delay(20);
         }

         else if(data == '2'){
          digitalWrite(13, HIGH);    //If value is 0 then LED turns OFF

//Faxle= 2000;
//Raxle= 1500;
//Raxle2 = 3000;
//Raxle3 = 5000;
//if(Faxle>=0&&Faxle<=5000)

Serial.print((int)Faxle_raw);
//Serial.print(data);
Serial.print("|");

//else
//{
//  Serial.print((int)0);
////Serial.print(data);
//Serial.print("|");
//  }
Serial.print((int)Raxle_raw);
Serial.print("|");
Serial.print((int)Raxle2_raw);
Serial.print("|");
Serial.print((int)Raxle3_raw);
Serial.print("|");
delay(200);
          }


          else if(data == 'A')
          {
//            word Faxle=0;
//word Raxle=0;
//word Raxle2=0;
//word Raxle3=0;

    new_val=raw_val;
    raw_val=0;

    new_A1_val=distance1;
    //Faxle_raw=0;
    //emptyVal1=distance1;



          }
   }

   }

//switch (data) {
//    case 0:    // 2Axle
//      Serial.println("dark");

//if(data == '0')
//{
//Faxle=analogRead(Axle1);
//Raxle=analogRead(Axle2);
//Faxle= 2000;
//Raxle= 1500;
//Serial.print((int)Faxle);
//Serial.print("|");
//Serial.print((int)Raxle);
//digitalWrite(13,HIGH);
//delay(10);
//}


//      break;
//    case 1:    // your hand is close to the sensor
     // Serial.println("dim");

//     if(data == '1')
//     {
//Faxle= 2000;
//Raxle= 1500;
//
//Serial.print((int)Faxle);
//Serial.print("|");
//Serial.print((int)Raxle);
//Serial.print("|");
//Serial.print((int)Raxle2);
//     }
//     




 // note: the in array should have increasing values
float FmultiMap(float val, float * _in, float * _out, uint8_t size)
{
  // take care the value is within range
  // val = constrain(val, _in[0], _in[size-1]);
  if (val <= _in[0]) return _out[0];
  if (val >= _in[size-1]) return _out[size-1];

  // search right interval
  uint8_t pos = 1;  // _in[0] allready tested
  while(val > _in[pos]) pos++;

  // this will handle all exact "points" in the _in array
  if (val == _in[pos]) return _out[pos];

  // interpolate in the right segment for the rest
  return (val - _in[pos-1]) * (_out[pos] - _out[pos-1]) / (_in[pos] - _in[pos-1]) + _out[pos-1];
}
