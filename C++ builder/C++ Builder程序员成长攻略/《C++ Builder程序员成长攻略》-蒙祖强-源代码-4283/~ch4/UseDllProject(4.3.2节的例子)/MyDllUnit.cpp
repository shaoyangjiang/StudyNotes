//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop  
#pragma argsused
extern "C" __declspec(dllexport) double CircleArea(double r);


int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
        return 1;
}
double CircleArea(double r)
{
  double s;
  s = 3.14*r*r;
  return s;
}


//---------------------------------------------------------------------------
