/*
 # This Sample code is for testing the Auto flower watering kit.
 # Product: EcoDuino - An auto plant kit
 # SKU    : KIT0003

 # Library:AutoWatering
   Library Functions:
   1.Power a pump to water flowers according to the humidity and temperature
   2.Use the DHT11 Sensor to test the ambient humidity and temperature
   3.Use the Moisture Sensor to test the moisture of the soil

 # Hardwares:
 1. Auto flower watering control board
 2. DHT11 Teaperature and Humidity Sensor
 3. Moisture Sensor
 4. Immersible pump

 # Connection:
 1.DHT11 & Free Life v1.0 board
    S      ---   Digital Pin9
   VCC     ---   VCC
   GND     ---   GND

 2.Moisture Sensor(Humidity) & Free Life v1.0 board
    1S      ---   Analog Pin2
   2GND     ---   GND
   3VCC     ---   VCC
*/

#include <AutoWatering.h>
#include <DHT.h>
#define MaxTemprature 40  //The Maximum Value of the Temperature
#define Sensor 1
#define Carbon 0

AutoWatering flower;

int temperature;
int moisture_dat;
int humidity;

void setup()
{
  flower.Initialization();//Initialization for the watering kit
  Serial.begin(115200);//Buad Rate is set as 115200bps
  Serial.print("Serial started")
}
void loop()
{
  //Obtain the Temperasture from DHT11 Sensor
  temperature = flower.getTemperature();
  Serial.print("Temperature is:" );
  Serial.println(temperature);

 //Obtain the Humidity from DHT11 Sensor
  humidity = flower.getHumidity();
  Serial.print("Humidity is:" );
  Serial.println(humidity);

 //Obtain the Soil Moisture from the Moisture Sensor
  moisture_dat = flower.MoistureSensor();
  Serial.print("Soil Moisture is:" );
  Serial.println(moisture_dat);

  Serial.println();
  Serial.println();
  delay(1500);
}
