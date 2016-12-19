//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ParentUnit.h"
#include "ChildUnit.h"
#include "about.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TParentForm *ParentForm;
//---------------------------------------------------------------------------
__fastcall TParentForm::TParentForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TParentForm::NNewClick(TObject *Sender)
{
  TChildForm *pChildForm;
  pChildForm = new TChildForm(Application);
  pChildForm->Caption = "ÐÂ½¨ÎÄµµ";
}
//---------------------------------------------------------------------------



void __fastcall TParentForm::NExitClick(TObject *Sender)
{
  //this->Free();
  this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::Word1Click(TObject *Sender)
{
  Form1->ShowModal();
}
//---------------------------------------------------------------------------








