//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Delete.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TdeleteForm *deleteForm;
//---------------------------------------------------------------------------
__fastcall TdeleteForm::TdeleteForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TdeleteForm::Button1Click(TObject *Sender)
{
  String strSQL,strField;
  strField = Query1->FieldByName("StuId")->AsString;
  strSQL = "delete from StuTable where StuId = "+strField;
  if(MessageDlg("确认要删除该记录吗？",mtWarning,mbOKCancel,0)==2) return; //不删除
  Query1->SQL->Text = strSQL;
  Query1->ExecSQL();
  Query1->SQL->Text = "select * from StuTable;";
  Query1->Active = true;   
}
//---------------------------------------------------------------------------


