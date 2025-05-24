#ifndef HUMIDITY
#define HUMIDITY
#include "idatanotifyh.h" // for IDataNotifyH
#include "IDewPointUpdate.h" // for IDewPointUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 

class Humidity: public IFloatDataProvider, public IDewPointUpdate, public IDataNotifyH
{
public:
  void Calculation() override;
  void  OnUpdate(int16_t registerCodeH)  override;
  float GetData()  override;
  
private:
   int16_t adcH;
   float value;  
};
#endif