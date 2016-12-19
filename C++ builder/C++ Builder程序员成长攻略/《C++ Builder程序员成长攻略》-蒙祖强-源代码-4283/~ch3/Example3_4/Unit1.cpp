//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int M1orM2 = 1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
  String str;
  if(Memo1->Lines->Count>0)
  {
    str = Memo1->Lines[0].operator[](0);
    Memo2->Lines->Add(str);
    Memo1->Lines->Delete(0);
  }
  else ShowMessage("Memo1为空！");
}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  String str;
  if(Memo1->SelLength==0) {ShowMessage("请选择待移动文本！");return;}
  str = Memo1->SelText;
  Memo1->ClearSelection();
  Memo2->Lines->Add(str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  String str;
  if(Memo1->Lines->Count==0) {ShowMessage("Memo1为空！");return;}
  for(int i=0;i<Memo1->Lines->Count;i++)
  {
    str = Memo1->Lines[0].operator[](i);
    Memo2->Lines->Add(str);
  }
  Memo1->Clear();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  if(M1orM2 == 1) Memo1->SelectAll();
  else Memo2->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  if(M1orM2 == 1)
  {
     if(Memo1->SelLength==0) {ShowMessage("请选择待移动文本！");return;}
     Memo1->ClearSelection();
  }
  else
  {
    if(Memo2->SelLength==0) {ShowMessage("请选择待移动文本！");return;}
    Memo2->ClearSelection();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
  if(M1orM2 == 1)
  {
    if(Memo1->SelLength==0) {ShowMessage("请选择待移动文本！");return;}
    Memo1->CopyToClipboard();
  }
  else
  {
    if(Memo2->SelLength==0) {ShowMessage("请选择待移动文本！");return;}
    Memo2->CopyToClipboard();
  }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
  M1orM2 = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
  M1orM2 = 2;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
  if(M1orM2 == 1) Memo1->PasteFromClipboard();
  else Memo2->PasteFromClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
  if(M1orM2 == 1)
  {
    if(Memo1->SelLength==0) {ShowMessage("请选择待移动文本！");return;}
    Memo1->CutToClipboard();
  }
  else
  {
    if(Memo2->SelLength==0) {ShowMessage("请选择待移动文本！");return;}
    Memo2->CutToClipboard();
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Memo1Click(TObject *Sender)
{
  M1orM2 = 1;
  RadioButton1->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo2Click(TObject *Sender)
{
  M1orM2 = 2;
  RadioButton2->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{
  if(M1orM2 == 1) Memo1->Clear();
  else Memo2->Clear();
}
//---------------------------------------------------------------------------


