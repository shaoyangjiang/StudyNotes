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


void __fastcall TForm1::NOpenClick(TObject *Sender)
{
   OpenDialog1->Execute();
   RichEdit1->Lines->LoadFromFile(OpenDialog1->FileName);
}
//---------------------------------------------------------------------------

 