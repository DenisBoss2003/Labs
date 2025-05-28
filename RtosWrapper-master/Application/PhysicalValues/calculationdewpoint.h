#ifndef DEWPOINT
#define DEWPOINT

#include "IDewPointUpdate.h" // for IDewPointUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 

class DewPoint: public IFloatDataProvider, public IDewPointUpdate
{
public:
  DewPoint(IFloatDataProvider& dataT, IFloatDataProvider& dataH) : mdataT(dataT), mdataH(dataH) {}
  void Calculation() override;
  float GetData() override;
private:
  float value; 
  IFloatDataProvider& mdataT;
  IFloatDataProvider& mdataH;
};
#endif