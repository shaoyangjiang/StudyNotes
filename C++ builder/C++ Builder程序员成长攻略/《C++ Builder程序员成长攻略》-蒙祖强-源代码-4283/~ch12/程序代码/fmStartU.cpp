//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmStartU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStartupForm *StartupForm;
int i =0;
//---------------------------------------------------------------------------
__fastcall TStartupForm::TStartupForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TStartupForm::Timer1Timer(TObject *Sender)
{
     i++;
     if(i>4)
     {
        Close();
     }
}
//---------------------------------------------------------------------------
