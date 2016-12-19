//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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


//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        float f1 = StrToFloat (Edit1 ->Text);
        float f2 = StrToFloat (Edit2 ->Text);
        float f3 = f1 + f2;
        Edit3->Text = FloatToStr(f3);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        float f1 = StrToFloat (Edit1 ->Text);
        float f2 = StrToFloat (Edit2 ->Text);
        float f3 = f1 - f2;
        Edit3->Text = FloatToStr(f3);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
         float f1 = StrToFloat (Edit1 ->Text);
        float f2 = StrToFloat (Edit2 ->Text);
        float f3 = f1 * f2;
        Edit3->Text = FloatToStr(f3);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
         float f1 = StrToFloat (Edit1 ->Text);
        float f2 = StrToFloat (Edit2 ->Text);
        float f3 = f1 / f2;
        Edit3->Text = FloatToStr(f3);
}
//---------------------------------------------------------------------------

