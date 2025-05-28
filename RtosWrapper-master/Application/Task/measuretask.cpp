#include "measuretask.h"

void MeasureTask :: Execute() 
{
  for (;;) 
    {
      mController.Update();
      dewpoint.Calculation();
      Sleep(100ms);
    }
};