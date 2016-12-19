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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        TColor startColor = clBlue;
        initialRed = GetRValue(startColor);
        initialGreen = GetGValue(startColor);
        initialBlue = GetBValue(startColor);
        Label1->Font->Color = startColor;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
        TColor startColor = (TColor)RGB(ScrollBar1->Position,ScrollBar1->Position,ScrollBar1->Position);
        initialRed = GetRValue(startColor);
        initialGreen = GetGValue(startColor);
        initialBlue = GetBValue(startColor);
        Label1->Font->Color = startColor;
}
//---------------------------------------------------------------------------
