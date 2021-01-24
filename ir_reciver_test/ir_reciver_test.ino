#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


const int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  Serial.println("Code Start");
}

void loop(){
  if (irrecv.decode(&results))
  {
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
  else
  {
   // Serial.println("Monitoring");
  }
  }
