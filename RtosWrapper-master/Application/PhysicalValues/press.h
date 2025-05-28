#ifndef PRESS
#define PRESS
#include "idatanotifyp.h" // for IDataNotifyp
#include "IDewPointUpdate.h" // for IDewPointUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider       

class Press: public IFloatDataProvider, public IDewPointUpdate, public IDataNotifyP
{
public:
  void OnUpdate(int32_t registerCodeP)  override;  
  float GetData() override;

private:
   int32_t adcP;
   float value;
  void Calculation();  

};
#endif