//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReaderDeleteUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TReaderDelete *ReaderDelete;
//---------------------------------------------------------------------------
__fastcall TReaderDelete::TReaderDelete(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TReaderDelete::BitBtn1Click(TObject *Sender)
{
  String strSQL,strField;
  strField = ReaderDeleteQuery->FieldByName("Number")->AsString;
  if(StrToInt(strField)!=0) //还有书没还
  {
    ShowMessage("该读者还有书没还，现在还不能删除");
    return;
  }
  strField = ReaderDeleteQuery->FieldByName("ReaderId")->AsString;
  strSQL = "Delete from ReaderTable where ReaderId = '"+strField+"'";
  if(MessageDlg("确认要删除该记录吗？",mtWarning,mbOKCancel,0)==2) return; //不删除
  ReaderDeleteQuery->SQL->Text = strSQL;
  ReaderDeleteQuery->ExecSQL();
  ReaderDeleteQuery->SQL->Text = "Select * from ReaderTable";
  ReaderDeleteQuery->Active = true;
}
//---------------------------------------------------------------------------
