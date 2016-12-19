//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BookInsertUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBookInsert *BookInsert;
//---------------------------------------------------------------------------
__fastcall TBookInsert::TBookInsert(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBookInsert::BitBtn1Click(TObject *Sender)
{
  String strSQL;
  strSQL = "Insert into BookTable values(";    
  strSQL = strSQL + "'" + ISBNEdit->Text;
  strSQL = strSQL + "', '" + BookNameEdit->Text;
  strSQL = strSQL + "', '" + EditorEdit->Text;
  strSQL = strSQL + "', '" + PublisherEdit->Text;
  strSQL = strSQL + "', '" + PubDateEdit->Text;
  strSQL = strSQL + "', '" + BookIndexEdit->Text; 
  strSQL = strSQL + "', " + PriceEdit->Text + ", 'ÔÚ¹Ý'" + ")";

  BookInsertQuery->SQL->Text = strSQL;
  BookInsertQuery->ExecSQL();
  BookInsertQuery->SQL->Text = "select * from BookTable";
  BookInsertQuery->Active = true;
  BookInsertQuery->Last();
}
//---------------------------------------------------------------------------


void __fastcall TBookInsert::DataSource1DataChange(TObject *Sender,
      TField *Field)
{ 
  ISBNEdit->Text = BookInsertQuery->FieldByName("ISBN")->AsString;
  BookNameEdit->Text = BookInsertQuery->FieldByName("BookName")->AsString;
  EditorEdit->Text = BookInsertQuery->FieldByName("Editor")->AsString;
  PublisherEdit->Text = BookInsertQuery->FieldByName("Publisher")->AsString;
  PubDateEdit->Text = BookInsertQuery->FieldByName("PubDate")->AsString;
  PriceEdit->Text = BookInsertQuery->FieldByName("Price")->AsString; 
}
//---------------------------------------------------------------------------



