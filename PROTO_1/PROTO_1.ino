
#include "led.h"
#include "electrical.h"
#include "system.h"
#include "MemoryFree.h"
#include "logger.h"
#include "prompt.h"
#include "pins.h"
#include "hashmap.h"
#include <stdarg.h>
#include "checks.h"

int pins[] = {8};
int rgb_pins[] = {5,6,9};
int read_pins[] = {A2};
int buzz_pins[]={10};
float rgb_intensities[]={.15f,.85f,.85f};
unsigned int timer = 0;


void setup(){
  Serial.begin(115200);
  while(!Serial);
  delay(1000);
  System::getInfo();
  int test_1[5] = {555,2,3,4,5};
  int test_2 = 5;
  int test_3[2][2] = {{1,2},{3,4}};

  //Template::Checks::ArrayDims* array_data = Template::getArrayData(test_data);

  //Datatypes::Container::MULTI<double(*)[2], double (*)[2]> test_container2(test_data, "double", 2,4,2);
  //double x= test_container2.value()[0][0];
  //Serial.println(x);
  //Serial.println(test_container2.type());
  //Serial.println(test_container2.valueToString());
  //Serial.println(test_container2.value()[0]);
}

int freq = 2000;
int original = getFreeMemory();
void loop()
{
  double test_data[4][1][2]={{{1.0}},{{1.0}},{{1.0}},{{1.0}}};
  Serial.println(getFreeMemory());
  Template::Arrays::ArrayData* data = Template::Arrays::getArrayData(&test_data);
  Serial.println(data->num_dimensions);
  data->printDimensions();
  data->prune(data);
  Serial.println();
  Serial.println(getFreeMemory());
  Serial.println();
  delay(1500);
  /*
  Serial.print("Original Memory: ");
  Serial.print(original);
  Serial.println();
  Structures::Dictionary<const char*, char> dict;
  dict.prune();
  Serial.print("Remaining Memory after Prune: ");
  Serial.print(getFreeMemory());
  Serial.println();
  delay(2000);*/
}