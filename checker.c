#include <stdio.h>
#include <assert.h>

//Battery Temperature check
int BatteryTemperatureIsOk(float temperature) 
{
  if(temperature < 0 || temperature > 45) 
  {
    printf("Temperature out of range!\n");
    return 0;
  } 
  else 
  {
    return 1;
  }
}

//Battery SOC check
int BatterySOCIsOk(float soc)
{
  if(soc < 20 || soc > 80) 
  {
    printf("State of Charge out of range!\n");
    return 0;
  }
  else
  {
    return 1;
  }
}

//Battery Chargerate check
int BatteryChargeRateIsOk(float chargeRate)
{
  if(chargeRate > 0.8) 
  {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  else
  {
    return 1;
  }
}

int BatteryIsOk(float temperature, float soc, float chargeRate)
{
  return (BatteryTemperatureIsOk(temperature) && BatterySOCIsOk(soc) && BatteryChargeRateIsOk(chargeRate));
}

int BatteryIsNotOk(float temperature, float soc, float chargeRate)
{
  return (BatteryTemperatureIsOk(temperature) || BatterySOCIsOk(soc) || BatteryChargeRateIsOk(chargeRate));
}

//Test Battery
void TestBatteryStatus()
{
  assert(BatteryIsOk(25, 70, 0.7));
  assert(BatteryIsNotOk(50, 85, 0));
}

int main() 
{
  TestBatteryStatus();
}
