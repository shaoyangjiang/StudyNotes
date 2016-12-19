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
void __fastcall TForm1::DisplayHint(TObject *Sender)
{
        Label1->Caption = GetLongHint(Application->Hint);
}
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Application-> OnHint = DisplayHint;
}
//---------------------------------------------------------------------------
