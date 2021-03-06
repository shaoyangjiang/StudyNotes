//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BookBrowsingUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBrowsingBook *BrowsingBook;
//---------------------------------------------------------------------------
__fastcall TBrowsingBook::TBrowsingBook(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBrowsingBook::SearchingBtnClick(TObject *Sender)
{
  String strField,strMatchType, strSQL;
  strField = SearchType->Text;
  if(strField=="题名")
  {
    strField = "BookName";  //按书名检索
  }
  else if(strField=="作者")
  {
     strField = "Editor"; 
  }
  else if(strField=="ISBN")
  {
    strField = "ISBM";
  }
  else if(strField=="出版社")
  {
     strField = "Publisher";
  }
  else if(strField=="索书号")
  {
     strField = "BookIndex";
  }

  strMatchType = MatchType->Text;
  if(strMatchType=="模糊匹配")
  {
    strSQL = "Select * from BookTable where " + strField + " like '%" + SearchingText->Text + "%'";
  }
  else
  {
       //Select * from BookTable where Publisher like '%月%';
    strSQL = "Select * from BookTable where " + strField + " = '" + SearchingText->Text + "'";

  }
  if(strMatchType=="") strSQL = "Select * from BookTable"; //检索词为空，则默认浏览所有的数目

  BrowsingBookQuery->SQL->Text = strSQL;
  BrowsingBookQuery->ExecSQL();
  BrowsingBookQuery->Active = true;

  DBGrid1->Visible = true;  

}
//---------------------------------------------------------------------------
