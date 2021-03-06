//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BookDeleteUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBookDelete *BookDelete;
//---------------------------------------------------------------------------
__fastcall TBookDelete::TBookDelete(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBookDelete::BitBtn1Click(TObject *Sender)
{
  String strSQL,strField;
  strField = BookDeleteQuery->FieldByName("Stutate")->AsString;
  if(strField=="借出")
  {
    ShowMessage("该书已经被借阅，现在还不能删除");
    return;
  }
  strField = BookDeleteQuery->FieldByName("ISBN")->AsString;
  strSQL = "Delete from BookTable where ISBN = "+strField;
  if(MessageDlg("确认要删除下列的书吗？\n\n《" + BookDeleteQuery->FieldByName("BookName")->AsString + "》",mtWarning,mbOKCancel,0)==2) return; //不删除
  BookDeleteQuery->SQL->Text = strSQL;
  BookDeleteQuery->ExecSQL();
  BookDeleteQuery->SQL->Text = "Select * from BookTable";
  BookDeleteQuery->Active = true;
}
//---------------------------------------------------------------------------
