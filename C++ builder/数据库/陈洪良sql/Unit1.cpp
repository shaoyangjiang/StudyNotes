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
void TForm1::ShowTable()
{
  ADODataSet1->Close();
  ADODataSet1->CommandText =  "select * from test";
  ADODataSet1->Open();
  ADODataSet1->Last();
}

//---------------------------------------------------------------------------
void TForm1::TableToEdit()
{
  StuIdEdit2->Text = ADODataSet1->FieldByName("StuId")->AsInteger;
  NameEdit2->Text = ADODataSet1->FieldByName("name")->AsString;
  GenderEdit2->Text = ADODataSet1->FieldByName("gender")->AsString;
  BirthdayEdit2->Text = ADODataSet1->FieldByName("birthday")->AsString;
  AddressEdit2->Text = ADODataSet1->FieldByName("address")->AsString;
  RemarkMemo2->Text = ADODataSet1->FieldByName("remark")->AsString;
}   

//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  ADODataSet1->Active = true;

  for(int i=0;i<ADODataSet1->Fields->Count-1;i++)
  {
    FindNameComboBox->Items->Add(ADODataSet1->Fields->Fields[i]->FieldName);
  }
  FindNameComboBox->ItemIndex = 0;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
  String strSQL;
  strSQL = "Insert into test values(";
  strSQL = strSQL+StuIdEdit1->Text;
  strSQL = strSQL+", '"+NameEdit1->Text;
  strSQL = strSQL+"', '"+GenderEdit1->Text;
  strSQL = strSQL+"', '"+BirthdayEdit1->Text;
  strSQL = strSQL+"', '"+AddressEdit1->Text;
  strSQL = strSQL+"', '"+RemarkMemo1->Text+"');";
  TADOCommand *ADOC = new TADOCommand(Form1);
  ADOC->Connection = ADOConnection1;
  ADOC->CommandText = strSQL;
  ADOC->Execute();
  ShowTable();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  int msg = MessageDlg("您确认要删除所有的数据吗？\n（一共 "+ IntToStr(ADODataSet1->RecordCount) +" 条记录）", mtConfirmation, TMsgDlgButtons()<<mbYes<<mbNo,0);
  if(msg==6)
  {
    TADOCommand *ADOC = new TADOCommand(Form1);
    ADOC->Connection = ADOConnection1;
    ADOC->CommandText = "Delete from test";
    ADOC->Execute();
    ShowTable();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  TADOCommand *ADOC = new TADOCommand(Form1);
  ADOC->Connection = ADOConnection1;
  ADOC->CommandText = "Delete from test where StuId = '"+ADODataSet1->Fields->FieldByName("StuId")->AsString+"'";
  ADOC->Execute();
  ShowTable();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
  ADODataSet1->Edit();
  ADODataSet1->FieldByName("StuId")->AsInteger = StrToInt(StuIdEdit2->Text);
  ADODataSet1->FieldByName("name")->AsString = NameEdit2->Text; 
  ADODataSet1->FieldByName("gender")->AsString = GenderEdit2->Text;
  ADODataSet1->FieldByName("birthday")->AsString = BirthdayEdit2->Text;
  ADODataSet1->FieldByName("address")->AsString = AddressEdit2->Text;
  ADODataSet1->FieldByName("remark")->AsString = RemarkMemo2->Text;
  ADODataSet1->Post();
  ADODataSet1->Refresh();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button6Click(TObject *Sender)
{
  if(FindEdit->Text == "")
  {
    ShowMessage("请输入待查找关键字!");
    return;
  }
  ADODataSet1->Close();
  ADODataSet1->CommandText =  "select * from test where "+FindNameComboBox->Text+" like '%"+FindEdit->Text+"%'";
  ADODataSet1->Open();
}
//---------------------------------------------------------------------------  

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   ADODataSet1->First();
   TableToEdit();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
  ADODataSet1->Next();
  TableToEdit();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
  ADODataSet1->Prior();
  TableToEdit();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
  ADODataSet1->Last();
  TableToEdit();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DBGrid3CellClick(TColumn *Column)
{
   TableToEdit();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ShowAllClick(TObject *Sender)
{
        //ADODataSet1->Filtered = false;
        ADODataSet1->Close();
        ADODataSet1->CommandText =  "select * from test ";
        ADODataSet1->Open();
}
//---------------------------------------------------------------------------

