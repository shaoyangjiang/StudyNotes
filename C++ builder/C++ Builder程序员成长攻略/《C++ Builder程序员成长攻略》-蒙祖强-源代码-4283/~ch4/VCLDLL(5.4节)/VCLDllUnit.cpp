//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#pragma argsused
extern "C" __declspec(dllexport) double CircleArea(double r);    //�ⲿ�����Ӿ�
extern "C" __declspec(dllexport)void test();

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{
        return 1;
}

double CircleArea(double r)
{
    return 3.14*r*r*1;

}
//---------------------------------------------------------------------------
