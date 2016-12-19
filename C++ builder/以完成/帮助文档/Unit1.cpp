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


void __fastcall TForm1::CONTENTClick(TObject *Sender)
{
        Application->HelpCommand (HELP_CONTENTS,0);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::HELPONHELPClick(TObject *Sender)
{
         Application->HelpCommand (HELP_HELPONHELP,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::INDEXClick(TObject *Sender)
{
         Application->HelpCommand (HELP_PARTIALKEY,0);        
}
//---------------------------------------------------------------------------

