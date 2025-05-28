#ifndef HUMIDITY
#define HUMIDITY
#include "idatanotifyh.h" // for IDataNotifyH
#include "ifloatdataprovider.h" // for IFloatDataProvider 

class Humidity: public IFloatDataProvider, public IDataNotifyH
{
public:
  
  void  OnUpdate(int16_t registerCodeH)  override;
  float GetData()  override;
  
private:
   int16_t adcH;
   float value;  
   void Calculation() ;
};
#endif