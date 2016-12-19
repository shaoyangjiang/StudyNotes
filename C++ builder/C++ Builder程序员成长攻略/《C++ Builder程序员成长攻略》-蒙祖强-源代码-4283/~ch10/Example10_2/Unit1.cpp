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
void TForm1::TableToEdit()
{   
  StuIdEdit2->Text = ADOTable1->FieldByName("StuId")->AsInteger;
  NameEdit2->Text = ADOTable1->FieldByName("name")->AsString;
  GenderEdit2->Text = ADOTable1->FieldByName("gender")->AsString;
  BirthdayEdit2->Text = ADOTable1->FieldByName("birthday")->AsString;
  AddressEdit2->Text = ADOTable1->FieldByName("address")->AsString;
  RemarkMemo2->Text = ADOTable1->FieldByName("remark")->AsString;
}   

//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  for(int i=0;i<ADOTable1->Fields->Count-1;i++)
  {
    FindNameComboBox->Items->Add(ADOTable1->Fields->Fields[i]->FieldName);
  }
  FindNameComboBox->ItemIndex = 0;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
ADOTable1->Insert();
ADOTable1->FieldByName("StuId")->AsInteger = StrToInt(StuIdEdit1->Text);
ADOTable1->FieldByName("name")->AsString = NameEdit1->Text;
ADOTable1->FieldByName("gender")->AsString = GenderEdit1->Text;
ADOTable1->FieldByName("birthday")->AsString = BirthdayEdit1->Text;
ADOTable1->FieldByName("address")->AsString = AddressEdit1->Text;
ADOTable1->FieldByName("remark")->AsString = RemarkMemo1->Text;
ADOTable1->Post();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{   
 while(ADOTable1->RecordCount > 0)
 {
   ADOTable1->Delete();
 }
 ADOTable1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  if((ADOTable1->Bof || ADOTable1->Eof))
  {
     ShowMessage("表中没有数据，或当前记录没有数据！");
     return;
  }
  ADOTable1->Delete();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
ADOTable1->Edit();
ADOTable1->FieldByName("StuId")->AsInteger = StrToInt(StuIdEdit2->Text);
ADOTable1->FieldByName("name")->AsString = NameEdit2->Text; //"8888";      //NameEdit2->Text
ADOTable1->FieldByName("gender")->AsString = GenderEdit2->Text;
ADOTable1->FieldByName("birthday")->AsString = BirthdayEdit2->Text;
ADOTable1->FieldByName("address")->AsString = AddressEdit2->Text;
ADOTable1->FieldByName("remark")->AsString = RemarkMemo2->Text;
ADOTable1->Post();
ADOTable1->Refresh();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button6Click(TObject *Sender)
{
  if(FindEdit->Text == "")
  {
    ShowMessage("请输入待查找关键字!");
    return;
  }
  TLocateOptions Opts;
  Opts<<loCaseInsensitive;

  Variant LocateValues;
  LocateValues = Variant(FindEdit->Text);

  if(ADOTable1->Locate(FindNameComboBox->Text,LocateValues, Opts))
    MessageBox(Handle, "查找成功！","查找结果",MB_OK);
  else
    MessageBox(Handle, "查找失败！","查找结果",MB_OK);  
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button1Click(TObject *Sender)
{
  ADOTable1->First();
  TableToEdit();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
  ADOTable1->Next();
  TableToEdit();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
  ADOTable1->Prior();
  TableToEdit();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
  ADOTable1->Last();
  TableToEdit();          
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DBGrid3CellClick(TColumn *Column)
{
     TableToEdit();        
}
//---------------------------------------------------------------------------


