//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DLLFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void test()
{
   TForm1 *Form1 = new TForm1(NULL);
   Form1->Show();
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  double r = Edit1->Text.ToDouble();
  Edit2->Text = 3.14*r*r;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  double a = Edit3->Text.ToDouble();
  Edit4->Text = a*a;
}
//---------------------------------------------------------------------------

