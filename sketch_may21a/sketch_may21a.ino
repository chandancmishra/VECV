// demo: CAN-BUS Shield, send data
// loovee@seeed.cc

#include <mcp_can.h>
#include <SPI.h>

const int SPI_CS_PIN = 10;

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup()
{
    Serial.begin(115200);

    while (CAN_OK != CAN.begin(CAN_250KBPS))              // init can bus : baudrate = 250k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");
}
unsigned long temp;
unsigned byte
vehicleSpeed[8] = {0, 0x32, 0, 0, 0, 0, 0, 0},
engineSpeed[8] = {0, 0, 0, 0, 0, 0, 0, 0};
void loop()
{
  temp=millis();
    vehicleSpeed[7] = vehicleSpeed[7]+1;
    if(vehicleSpeed[7] == 100)
    {
        vehicleSpeed[7] = 0;
        vehicleSpeed[6] = vehicleSpeed[6] + 1;
        
        if(vehicleSpeed[6] == 100)
        {
            vehicleSpeed[6] = 0;
            vehicleSpeed[5] = vehicleSpeed[6] + 1;  
        }
    }
    Serial.println(vehicleSpeed[7]);
    send();
    /*CAN.sendMsgBuf(0xcf00400, 0, 8, engineSpeed);
    CAN.sendMsgBuf(0x18fef111,0,8, vehicleSpeed);
    delay(20);*/
}
void send()
{
  int t=5;
  CAN.sendMsgBuf(0x18fef111,1,8, vehicleSpeed);
  while(t--)
  {
     CAN.sendMsgBuf(0xcf00400, 1, 8, engineSpeed);
     delay(20);
  } 
}
