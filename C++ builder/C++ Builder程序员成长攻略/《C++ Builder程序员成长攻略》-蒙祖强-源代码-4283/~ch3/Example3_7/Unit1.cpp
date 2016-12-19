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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 FindDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FindDialog1Find(TObject *Sender)
{
  TSearchTypes sch;
  TFindDialog *fd;
  int schPos;

  fd = dynamic_cast<TFindDialog *> (Sender);  //获取TFindDialog对象的指针
  if(fd->Options.Contains(frMatchCase)) sch<<stMatchCase; //区分大小写
  if(fd->Options.Contains(frWholeWord)) sch<<stWholeWord; //全字匹配
  //if(fd->Options.Contains(frDown)) sch<<//
  if(RichEdit1->SelLength) RichEdit1->SelStart++;  //为了能够连续寻找
  schPos = RichEdit1->FindText(fd->FindText, RichEdit1->SelStart, RichEdit1->Text.Length(),sch);
  if(schPos!=-1) //如果找到
  {
    RichEdit1->SelStart = schPos;
    RichEdit1->SelLength = fd->FindText.Length();
  }
  else   //如果找不到
  {
    MessageBox(NULL, "查找结束！", "查找", MB_OK);
    RichEdit1->SelStart = 0;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  ReplaceDialog1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ReplaceDialog1Find(TObject *Sender)
{
  TSearchTypes sch;
  TFindDialog *fd;
  int schPos;

  fd = dynamic_cast<TFindDialog *> (Sender);  //获取TFindDialog对象的指针
  if(fd->Options.Contains(frMatchCase)) sch<<stMatchCase; //区分大小写
  if(fd->Options.Contains(frWholeWord)) sch<<stWholeWord; //全字匹配
  //if(fd->Options.Contains(frDown)) sch<<//
  if(RichEdit1->SelLength) RichEdit1->SelStart++;  //为了能够连续寻找
  schPos = RichEdit1->FindText(fd->FindText, RichEdit1->SelStart, RichEdit1->Text.Length(),sch);
  if(schPos!=-1) //如果找到
  {
    RichEdit1->SelStart = schPos;
    RichEdit1->SelLength = fd->FindText.Length();
  }
  else   //如果找不到
  {
    MessageBox(NULL, "查找与替换结束！", "查找与替换", MB_OK);
    RichEdit1->SelStart = 0;
  }
  /**/
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ReplaceDialog1Replace(TObject *Sender)
{
  if(RichEdit1->SelLength == 0) ReplaceDialog1Find(Sender);
  else
  {
     RichEdit1->SelText = ReplaceDialog1->ReplaceText;
     ReplaceDialog1Find(Sender);
     if(ReplaceDialog1->Options.Contains(frReplaceAll))
        while(RichEdit1->SelLength!=0)  ReplaceDialog1Replace(Sender);
  }
}
//---------------------------------------------------------------------------
