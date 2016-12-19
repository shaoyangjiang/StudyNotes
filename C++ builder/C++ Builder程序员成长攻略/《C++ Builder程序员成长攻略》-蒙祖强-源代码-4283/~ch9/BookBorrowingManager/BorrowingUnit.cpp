//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BorrowingUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBorrowingBook *BorrowingBook;

String LibrarianId = "L1260";   //��Ա��ţ�Ĭ��ֵΪ "L1260"
int MaxBookNumber = 15;   //Ĭ�Ͽ��Խ�15����
//---------------------------------------------------------------------------
__fastcall TBorrowingBook::TBorrowingBook(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBorrowingBook::BitBtn1Click(TObject *Sender)
{
  int BookNumber;
  ReaderTableQuery1->SQL->Text = "Select * from ReaderTable where ReaderId = '" + ReaderIdEdit->Text + "'";
  ReaderTableQuery1->ExecSQL();
  ReaderTableQuery1->Active = true;
  if(ReaderTableQuery1->RecordCount==1)
  {
    ReaderNameEdit->Text = ReaderTableQuery1->Fields->FieldByName("Name")->AsString;
    BookNumber = ReaderTableQuery1->Fields->FieldByName("Number")->AsInteger;
    leavingBookNumLabel->Caption = "�������Խ� " + IntToStr(MaxBookNumber - BookNumber) + "���顣";
    if(BookNumber >= MaxBookNumber)
    {
      ShowMessage("�ö����ѽ�����");
      return;
    }
  }
  else
  {
    ShowMessage("�ö���û��ע��,���Ĳ���ʧ�ܣ�");
    return;
  }
  BookTableQuery2->SQL->Text = "Select * from BookTable where ISBN = '" + ISBNEdit->Text + "'";
  BookTableQuery2->ExecSQL();
  BookTableQuery2->Active = true;
  if(BookTableQuery2->RecordCount==1)
  {
    BookNameEdit->Text = BookTableQuery2->Fields->FieldByName("BookName")->AsString;
    EditorEdit->Text = BookTableQuery2->Fields->FieldByName("Editor")->AsString;
    if(BookTableQuery2->Fields->FieldByName("Stutate")->AsString == "���")
    {
      ShowMessage("�����ѱ����,����ʧ�ܣ�");
      return;
    }
  }
  else
  {
    ShowMessage("û���Ȿ��,���Ĳ���ʧ�ܣ�");
    return;
  }
  BorrowDateEdit->Text = DateToStr(Date());
  ReturnDateEdit->Text = DateToStr(Date()+30);
  LibrarianIdEdit->Text = LibrarianId;
  String strSQL = "";
  strSQL = "Insert into BorrowingTable(ReaderId,ReaderName,ISBN,BookName,Editor,BorrowDate,ReturnDate,LibrarianId)   values(";
  strSQL = strSQL + "'" + ReaderIdEdit->Text;
  strSQL = strSQL + "', '" + ReaderNameEdit->Text;
  strSQL = strSQL + "', '" + ISBNEdit->Text;
  strSQL = strSQL + "', '" + BookNameEdit->Text;
  strSQL = strSQL + "', '" + EditorEdit->Text;
  strSQL = strSQL + "', '" + BorrowDateEdit->Text;
  strSQL = strSQL + "', '" + ReturnDateEdit->Text;
  strSQL = strSQL + "', '" + LibrarianIdEdit->Text + "')";
  BorrowingTableQuery3->SQL->Text = strSQL;
  BorrowingTableQuery3->ExecSQL();
  strSQL = "Update BookTable set Stutate = '���' where ISBN = '" + ISBNEdit->Text + "'"; //�����״̬��Ϊ�������
  BorrowingTableQuery3->SQL->Text = strSQL;
  BorrowingTableQuery3->ExecSQL();
  strSQL = "Update ReaderTable set Number = Number + 1  where ReaderId = '" + ReaderIdEdit->Text + "'"; //�ܽ��������1
  BorrowingTableQuery3->SQL->Text = strSQL;
  BorrowingTableQuery3->ExecSQL();
  leavingBookNumLabel->Caption = "�������Խ� " + IntToStr(MaxBookNumber - BookNumber - 1) + "���顣";
  ShowMessage("���ĳɹ���");
  BorrowingTableQuery3->SQL->Text = "select * from BorrowingTable";
  BorrowingTableQuery3->Active = true;
  BorrowingTableQuery3->Last();
}
//---------------------------------------------------------------------------

