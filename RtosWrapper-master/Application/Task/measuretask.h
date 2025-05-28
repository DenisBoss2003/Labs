#ifndef MEASURETASK
#define MEASURETASK

#include "thread.hpp" // for OsWrapper::Thread<>
#include "imeasurementscontroller.h" // for update register
#include "IDewPointUpdate.h" // for update Calculation
using namespace OsWrapper;

class MeasureTask: public OsWrapper::Thread<512> 
{
public:
  MeasureTask(IMeasurementsController& controller,  IDewPointUpdate& updatePoint) : mController(controller),  dewpoint(updatePoint) {}
  virtual void Execute() override;
private:
  IMeasurementsController& mController;
  
  IDewPointUpdate& dewpoint;
};

#endif