//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "update.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TupdateForm *updateForm;
//---------------------------------------------------------------------------
__fastcall TupdateForm::TupdateForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TupdateForm::Button1Click(TObject *Sender)
{
  Table1->Edit();
  Table1->Post();
  Table1->Refresh();
}
//---------------------------------------------------------------------------

