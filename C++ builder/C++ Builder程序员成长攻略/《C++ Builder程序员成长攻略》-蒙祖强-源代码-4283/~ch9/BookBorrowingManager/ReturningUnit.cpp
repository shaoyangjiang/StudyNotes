//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReturningUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TReturningBook *ReturningBook;
//---------------------------------------------------------------------------
__fastcall TReturningBook::TReturningBook(TComponent* Owner)
        : TForm(Owner)
{
}
 void TReturningBook::ShowBorrowingTable()
 {
   ReturningTableQuery1->Active = false;
   ReturningTableQuery1->SQL->Text = "Select * from BorrowingTable";
   ReturningTableQuery1->ExecSQL();
   ReturningTableQuery1->Active = true;
 }
//---------------------------------------------------------------------------
void __fastcall TReturningBook::BitBtn1Click(TObject *Sender)
{
  ReturningTableQuery1->SQL->Text = "Select * from BorrowingTable where ISBN = '" + ISBNEdit->Text + "'";
  ReturningTableQuery1->ExecSQL();
  ReturningTableQuery1->Active = true;

  ReaderIdEdit->Text = ReturningTableQuery1->Fields->FieldByName("ReaderId")->AsString;

  if(ReturningTableQuery1->RecordCount > 1) {ShowBorrowingTable();ShowMessage("���ݿⲻһ�£�"); return;}
  if(ReturningTableQuery1->RecordCount == 0) {ShowBorrowingTable();ShowMessage("���鲻�Ǳ����е���,�����˻���"); return;}
  //������ ReturningTableQuery1->RecordCount = 1

  BookTableQuery2->SQL->Text = "Select * from BookTable where ISBN = '" + ISBNEdit->Text + "'";
  BookTableQuery2->ExecSQL();
  BookTableQuery2->Active = true;
 

  BookNameEdit->Text = BookTableQuery2->Fields->FieldByName("BookName")->AsString;
  EditorEdit->Text = BookTableQuery2->Fields->FieldByName("Editor")->AsString;
  PublisherEdit->Text = BookTableQuery2->Fields->FieldByName("Publisher")->AsString;
  PubDateEdit->Text = BookTableQuery2->Fields->FieldByName("PubDate")->AsString;
  PriceEdit->Text = BookTableQuery2->Fields->FieldByName("Price")->AsFloat;


  //NameEdit->Text = BookTableQuery2->Fields->FieldByName("Price")->AsFloat;

  //---------------------------------------------
  ReaderTableQuery3->SQL->Text = "Select * from ReaderTable where ReaderId = '" + ReaderIdEdit->Text + "'";
  ReaderTableQuery3->ExecSQL();
  ReaderTableQuery3->Active = true;

  NameEdit->Text = ReaderTableQuery3->Fields->FieldByName("Name")->AsString;
  GenderEdit->Text = ReaderTableQuery3->Fields->FieldByName("Gender")->AsString;
  UnitEdit->Text = ReaderTableQuery3->Fields->FieldByName("Unit")->AsString;
  IdentEdit->Text = ReaderTableQuery3->Fields->FieldByName("Ident")->AsString;
  NumberEdit->Text = ReaderTableQuery3->Fields->FieldByName("Number")->AsString;
  GenderEdit->Text = ReaderTableQuery3->Fields->FieldByName("Gender")->AsString;

  //---------------------------------------------
  ReturningTableQuery1->SQL->Text = "Delete from BorrowingTable where ISBN = '" + ISBNEdit->Text + "'";
  ReturningTableQuery1->ExecSQL();  //ɾ��
  //ReturningTableQuery1->Active = true;
   
  BookTableQuery2->SQL->Text = "Update BookTable set Stutate = '�ڹ�' where ISBN = '" + ISBNEdit->Text + "'";
  BookTableQuery2->ExecSQL();
  

  ReaderTableQuery3->SQL->Text = "Update ReaderTable set Number = Number - 1 where ReaderId = '" + ReaderIdEdit->Text + "'";
  ReaderTableQuery3->ExecSQL();


  NumberEdit->Text = StrToInt(NumberEdit->Text) + 1;

   ShowBorrowingTable();
  ShowMessage("�ѳɹ��黹�� -- "+ NameEdit->Text +" -- ����");

}
