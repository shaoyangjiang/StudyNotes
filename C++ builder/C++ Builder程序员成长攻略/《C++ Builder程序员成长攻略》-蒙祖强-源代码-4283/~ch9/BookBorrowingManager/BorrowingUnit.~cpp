//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BorrowingUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBorrowingBook *BorrowingBook;

String LibrarianId = "L1260";   //馆员编号，默认值为 "L1260"
int MaxBookNumber = 15;   //默认可以借15本书
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
    leavingBookNumLabel->Caption = "您还可以借 " + IntToStr(MaxBookNumber - BookNumber) + "本书。";
    if(BookNumber >= MaxBookNumber)
    {
      ShowMessage("该读者已借满！");
      return;
    }
  }
  else
  {
    ShowMessage("该读者没有注册,借阅操作失败！");
    return;
  }
  BookTableQuery2->SQL->Text = "Select * from BookTable where ISBN = '" + ISBNEdit->Text + "'";
  BookTableQuery2->ExecSQL();
  BookTableQuery2->Active = true;
  if(BookTableQuery2->RecordCount==1)
  {
    BookNameEdit->Text = BookTableQuery2->Fields->FieldByName("BookName")->AsString;
    EditorEdit->Text = BookTableQuery2->Fields->FieldByName("Editor")->AsString;
    if(BookTableQuery2->Fields->FieldByName("Stutate")->AsString == "借出")
    {
      ShowMessage("该书已被借出,操作失败！");
      return;
    }
  }
  else
  {
    ShowMessage("没有这本书,借阅操作失败！");
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
  strSQL = "Update BookTable set Stutate = '借出' where ISBN = '" + ISBNEdit->Text + "'"; //把书的状态置为“借出”
  BorrowingTableQuery3->SQL->Text = strSQL;
  BorrowingTableQuery3->ExecSQL();
  strSQL = "Update ReaderTable set Number = Number + 1  where ReaderId = '" + ReaderIdEdit->Text + "'"; //能借的数量减1
  BorrowingTableQuery3->SQL->Text = strSQL;
  BorrowingTableQuery3->ExecSQL();
  leavingBookNumLabel->Caption = "您还可以借 " + IntToStr(MaxBookNumber - BookNumber - 1) + "本书。";
  ShowMessage("借阅成功！");
  BorrowingTableQuery3->SQL->Text = "select * from BorrowingTable";
  BorrowingTableQuery3->Active = true;
  BorrowingTableQuery3->Last();
}
//---------------------------------------------------------------------------

