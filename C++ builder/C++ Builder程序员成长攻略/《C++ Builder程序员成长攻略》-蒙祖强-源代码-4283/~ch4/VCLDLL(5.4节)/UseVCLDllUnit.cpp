//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UseVCLDllUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

extern "C" __declspec(dllimport) double CircleArea(double r); //   �ⲿ�����Ӿ�
extern "C" __declspec(dllimport)void test();
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{  
  test();
}
//---------------------------------------------------------------------------
