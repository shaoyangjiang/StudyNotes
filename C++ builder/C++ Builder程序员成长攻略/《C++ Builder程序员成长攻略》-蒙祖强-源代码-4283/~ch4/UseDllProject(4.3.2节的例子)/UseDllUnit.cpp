//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UseDllUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
extern "C" __declspec(dllimport) double CircleArea(double r);

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
  double s,r;
  r = Edit1->Text.ToDouble();
  s = CircleArea(r);
  Edit2->Text = s;
}
//---------------------------------------------------------------------------

