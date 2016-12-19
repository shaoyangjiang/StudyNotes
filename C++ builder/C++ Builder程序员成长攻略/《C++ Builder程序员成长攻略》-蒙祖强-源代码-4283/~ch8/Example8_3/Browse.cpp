//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Browse.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBrowseForm *BrowseForm;
//---------------------------------------------------------------------------
__fastcall TBrowseForm::TBrowseForm(TComponent* Owner)
        : TForm(Owner)
{
}
 
//---------------------------------------------------------------------------
void __fastcall TBrowseForm::Button1Click(TObject *Sender)
{
  Query1->Active = false;
  Query1->DatabaseName = "MyCBuilderOdbc";
  Query1->SQL->Text = "Select * from StuTable";
  Query1->Active = true;
  ComboBox1->Items->Clear();
  for(int i=0;i<Query1->RecordCount;i++)    //Query1->RecordCount
  {
     ComboBox1->Items->Add(Query1->Fields->Fields[i]->FieldName);     //Query1->Fields->Fields[i]->FieldName
  }
  ComboBox1->ItemIndex = 1;//默认是按名字查询        
}
//---------------------------------------------------------------------------
void __fastcall TBrowseForm::Button2Click(TObject *Sender)
{
  Query1->First();
}
//---------------------------------------------------------------------------
void __fastcall TBrowseForm::Button3Click(TObject *Sender)
{
  Query1->Next();

}
//---------------------------------------------------------------------------
void __fastcall TBrowseForm::Button4Click(TObject *Sender)
{
  Query1->Prior();
}
//---------------------------------------------------------------------------
void __fastcall TBrowseForm::Button5Click(TObject *Sender)
{
  Query1->Last();        
}
//---------------------------------------------------------------------------
void __fastcall TBrowseForm::Button6Click(TObject *Sender)
{
  String strSQL,strField,strValue;
  strField = ComboBox1->Text;
  strValue = Edit1->Text;
  strSQL = "select * from StuTable where "+ strField +" = '"+strValue+"'"; 
  Query1->SQL->Text = strSQL;
  Query1->Active = true;
}
//---------------------------------------------------------------------------
