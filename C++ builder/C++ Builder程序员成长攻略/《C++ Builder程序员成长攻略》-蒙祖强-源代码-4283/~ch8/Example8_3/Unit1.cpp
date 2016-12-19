//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Browse.h"
#include "Insert.h"
#include "update.h"
#include "delete.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
TBrowseForm *BrowseForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
 
void __fastcall TMainForm::BitBtn1Click(TObject *Sender)
{
  TBrowseForm *BrowseForm;
  BrowseForm = new TBrowseForm(this);
  BrowseForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn2Click(TObject *Sender)
{
  TInsertForm *InsertForm; //#include "Insert.h"  InsertForm
  InsertForm = new TInsertForm(this);
  InsertForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn3Click(TObject *Sender)
{
  TupdateForm *updateForm; //#include "Insert.h"  InsertForm
  updateForm = new TupdateForm(this);
  updateForm->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::BitBtn4Click(TObject *Sender)
{
  TdeleteForm  *deleteForm;
  deleteForm = new TdeleteForm(this);
  deleteForm->ShowModal();
}
//---------------------------------------------------------------------------

