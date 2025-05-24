#ifndef MEASURETASK
#define MEASURETASK

#include "thread.hpp" // for OsWrapper::Thread<>
#include "imeasurementscontroller.h" // for update register
#include "IDewPointUpdate.h" // for update Calculation
using namespace OsWrapper;

class MeasureTask: public OsWrapper::Thread<512> 
{
public:
  MeasureTask(IMeasurementsController& controller, IDewPointUpdate& updateT, IDewPointUpdate& updateH, IDewPointUpdate& updateP, IDewPointUpdate& updatePoint) : mController(controller), temperature(updateT), humidity(updateH), pressure(updateP), dewpoint(updatePoint) {}
  virtual void Execute() override;
private:
  IMeasurementsController& mController;
  IDewPointUpdate& temperature;
  IDewPointUpdate& humidity;
  IDewPointUpdate& pressure;
  IDewPointUpdate& dewpoint;
};

#endif