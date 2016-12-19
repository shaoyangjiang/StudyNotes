//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
float f3=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{

    float f1 = StrToFloat(Edit1->Text);
    float f2 = StrToFloat(Edit2->Text);
    f3 = f3+f1*f2;
    Edit3->Text = FloatToStr(f3);
    Edit1->Text="";
    Edit2->Text="";
}
//---------------------------------------------------------------------------
