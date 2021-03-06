//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReaderInsertUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TReaderInsert *ReaderInsert;
//---------------------------------------------------------------------------
__fastcall TReaderInsert::TReaderInsert(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TReaderInsert::Button1Click(TObject *Sender)
{
  


  /*
ReaderId 	Char(7)  NOT NULL Primary Key,
Name 		Varchar(8) 		NOT NULL ,
UserName	Varchar(12)		NOT NULL,
Password		Varchar(12)		NOT NULL ,
Gender 		Char(2) ,
Unit 		Varchar(50) , 
Ident 		Varchar (10) ,
Number 		Integer 			NOT NULL,
Remark 		Varchar(500) );

  */
}
//---------------------------------------------------------------------------
void __fastcall TReaderInsert::BitBtn1Click(TObject *Sender)
{
  ReaderInsertTable->Append();
  ReaderInsertTable->FieldByName("ReaderId")->AsString = ReaderIdEdit->Text;
  ReaderInsertTable->FieldByName("Name")->AsString = NameEdit->Text;
  ReaderInsertTable->FieldByName("UserName")->AsString = ReaderIdEdit->Text;
  ReaderInsertTable->FieldByName("Password")->AsString = ReaderIdEdit->Text;
  ReaderInsertTable->FieldByName("Gender")->AsString = GenderEdit->Text;
  ReaderInsertTable->FieldByName("Unit")->AsString = UnitEdit->Text;
  ReaderInsertTable->FieldByName("Ident")->AsString = IdentEdit->Text;
  ReaderInsertTable->FieldByName("Number")->AsInteger = 0;
  ReaderInsertTable->FieldByName("Remark")->AsString = RemarkMemo->Text;
  ReaderInsertTable->Post();
  ReaderInsertTable->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TReaderInsert::DBGrid1CellClick(TColumn *Column)
{
ReaderIdEdit->Text = ReaderInsertTable->FieldByName("ReaderId")->AsString;
  NameEdit->Text = ReaderInsertTable->FieldByName("Name")->AsString;

  GenderEdit->Text = ReaderInsertTable->FieldByName("Gender")->AsString;
  UnitEdit->Text = ReaderInsertTable->FieldByName("Unit")->AsString;
  IdentEdit->Text = ReaderInsertTable->FieldByName("Ident")->AsString;
  RemarkMemo->Text = ReaderInsertTable->FieldByName("Remark")->AsString;

        
}
//---------------------------------------------------------------------------


