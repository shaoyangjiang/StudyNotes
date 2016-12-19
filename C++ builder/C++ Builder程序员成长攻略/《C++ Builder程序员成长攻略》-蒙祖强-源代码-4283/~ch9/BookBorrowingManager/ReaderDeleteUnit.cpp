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
  if(StrToInt(strField)!=0) //������û��
  {
    ShowMessage("�ö��߻�����û�������ڻ�����ɾ��");
    return;
  }
  strField = ReaderDeleteQuery->FieldByName("ReaderId")->AsString;
  strSQL = "Delete from ReaderTable where ReaderId = '"+strField+"'";
  if(MessageDlg("ȷ��Ҫɾ���ü�¼��",mtWarning,mbOKCancel,0)==2) return; //��ɾ��
  ReaderDeleteQuery->SQL->Text = strSQL;
  ReaderDeleteQuery->ExecSQL();
  ReaderDeleteQuery->SQL->Text = "Select * from ReaderTable";
  ReaderDeleteQuery->Active = true;
}
//---------------------------------------------------------------------------
