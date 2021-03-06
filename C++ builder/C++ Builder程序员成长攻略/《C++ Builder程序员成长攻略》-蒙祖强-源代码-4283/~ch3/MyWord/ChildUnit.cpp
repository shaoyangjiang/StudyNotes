//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ChildUnit.h"

 
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChildForm *ChildForm;
 
bool ChangeFlag = false;
//---------------------------------------------------------------------------
__fastcall TChildForm::TChildForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TChildForm::NNewClick(TObject *Sender)
{
  TChildForm *pChildForm;
  pChildForm = new TChildForm(Application);
  pChildForm->Caption = "新建文档";
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::NCloseClick(TObject *Sender)
{
  if(NSave->Enabled)
  {
    int n = MessageDlg("是否保存对下列文件的更改？\n"+OpenDialog1->FileName, mtWarning,TMsgDlgButtons()<<mbYes<<mbNo<<mbCancel,0);
    if(n==6) //需要保存,并关闭
    {
      if(OpenDialog1->FileName!="") RichEdit1->Lines->SaveToFile(OpenDialog1->FileName);
      else
      if(SaveDialog1->Execute())
      {
        RichEdit1->Lines->SaveToFile(SaveDialog1->FileName);
        OpenDialog1->FileName = SaveDialog1->FileName;
      }
      this->Free();
    }
    else if(n==7)  //不需要保存
    {
      this->Free();
    }
    else return;   //不作任何处理，直接返回
  }
  else this->Free();
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::NOpenClick(TObject *Sender)
{
  if(OpenDialog1->Execute())
  {
    RichEdit1->Lines->LoadFromFile(OpenDialog1->FileName);
    NSave->Enabled = false;
    Caption = OpenDialog1->FileName;
  }
}
//---------------------------------------------------------------------------


void __fastcall TChildForm::NSaveClick(TObject *Sender)
{
  if(OpenDialog1->FileName!="")
  {
    RichEdit1->Lines->SaveToFile(OpenDialog1->FileName);
    NSave->Enabled = false;
    return;
  }
  if(SaveDialog1->Execute())
  {
    RichEdit1->Lines->SaveToFile(SaveDialog1->FileName);
    OpenDialog1->FileName = SaveDialog1->FileName;
    NSave->Enabled = false;
  }

}
//---------------------------------------------------------------------------




void __fastcall TChildForm::NSaveasClick(TObject *Sender)
{

  if(SaveDialog1->Execute())
  {
    RichEdit1->Lines->SaveToFile(SaveDialog1->FileName);
    NSave->Enabled = false;
  }
}
//---------------------------------------------------------------------------


void __fastcall TChildForm::RichEdit1Change(TObject *Sender)
{
  NSave->Enabled = true;
 
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::NUndoClick(TObject *Sender)
{
  RichEdit1->Undo();
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::NCutClick(TObject *Sender)
{
  RichEdit1->CutToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::NCopyClick(TObject *Sender)
{
  RichEdit1->CopyToClipboard();

}
//---------------------------------------------------------------------------

void __fastcall TChildForm::NPasteClick(TObject *Sender)
{
  RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::NClearClick(TObject *Sender)
{
  RichEdit1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::NSelectAllClick(TObject *Sender)
{
  RichEdit1->SelectAll();        
}
//---------------------------------------------------------------------------


void __fastcall TChildForm::NEditClick(TObject *Sender)
{
  if(RichEdit1->SelLength!=0)
  {
    NCopy->Enabled = true;
    NCut->Enabled = true;
  }
  else
  {
    NCopy->Enabled = false;
    NCut->Enabled = false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::NFindClick(TObject *Sender)
{
  FindDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::NReplaceClick(TObject *Sender)
{
  ReplaceDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::FindDialog1Find(TObject *Sender)
{
  TSearchTypes sch;
  TFindDialog *fd;
  int schPos;
  fd = dynamic_cast<TFindDialog *> (Sender);
  if(fd->Options.Contains(frMatchCase)) sch<<stMatchCase;
  if(fd->Options.Contains(frWholeWord)) sch<<stWholeWord;
  if(RichEdit1->SelLength) RichEdit1->SelStart++;
  schPos = RichEdit1->FindText(fd->FindText, RichEdit1->SelStart, RichEdit1->Text.Length(),sch);
  if(schPos!=-1)
  {
    RichEdit1->SelStart = schPos;
    RichEdit1->SelLength = fd->FindText.Length();
  }
  else
  {
    MessageBox(NULL, "查找结束！", "查找", MB_OK);
    RichEdit1->SelStart = 0;
  }
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::ReplaceDialog1Find(TObject *Sender)
{
  TSearchTypes sch;
  TFindDialog *fd;
  int schPos;
  fd = dynamic_cast<TFindDialog *> (Sender);
  if(fd->Options.Contains(frMatchCase)) sch<<stMatchCase;
  if(fd->Options.Contains(frWholeWord)) sch<<stWholeWord;
  if(RichEdit1->SelLength) RichEdit1->SelStart++;  		 
  schPos = RichEdit1->FindText(fd->FindText, RichEdit1->SelStart, RichEdit1->Text.Length(),sch);
  if(schPos!=-1)
  {
    RichEdit1->SelStart = schPos;
    RichEdit1->SelLength = fd->FindText.Length();
  }
  else
  {
    MessageBox(NULL, "查找与替换结束！", "查找与替换", MB_OK);
    RichEdit1->SelStart = 0;
  }

}
//---------------------------------------------------------------------------

void __fastcall TChildForm::ReplaceDialog1Replace(TObject *Sender)
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

void __fastcall TChildForm::NFontClick(TObject *Sender)
{
  if(FontDialog1->Execute())
  {
    RichEdit1->SelAttributes->Color = FontDialog1->Font->Color;
    RichEdit1->SelAttributes->Name = FontDialog1->Font->Name;
    RichEdit1->SelAttributes->Style = FontDialog1->Font->Style;
    RichEdit1->SelAttributes->Charset = FontDialog1->Font->Charset;
    RichEdit1->SelAttributes->Pitch =  FontDialog1->Font->Pitch;
    RichEdit1->SelAttributes->Size = FontDialog1->Font->Size;
  }
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::NFormatClick(TObject *Sender)
{
  if(RichEdit1->SelLength!=0)
  {
    NFont->Enabled = true;
    NFColor->Enabled = true;
  }
  else
  {
    NFont->Enabled = false;
    NFColor->Enabled = false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::NBColorClick(TObject *Sender)
{
  if(ColorDialog1->Execute())
    RichEdit1->Color = ColorDialog1->Color;
}
//---------------------------------------------------------------------------


void __fastcall TChildForm::NFColorClick(TObject *Sender)
{
  if(ColorDialog1->Execute())
    RichEdit1->SelAttributes->Color = ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::PUndoClick(TObject *Sender)
{
  RichEdit1->Undo();
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::PCopyClick(TObject *Sender)
{
  RichEdit1->CopyToClipboard();
}
//---------------------------------------------------------------------------


void __fastcall TChildForm::PCutClick(TObject *Sender)
{
  RichEdit1->CutToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::PPasteClick(TObject *Sender)
{
  RichEdit1->PasteFromClipboard();        
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::PClearClick(TObject *Sender)
{
  RichEdit1->Clear();        
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::PSelectallClick(TObject *Sender)
{
  RichEdit1->SelectAll();        
}
//---------------------------------------------------------------------------

void __fastcall TChildForm::RichEdit1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  if(RichEdit1->SelLength!=0)
  {
    PCopy->Enabled = true;
    PCut->Enabled = true;
  }
  else
  {
    PCopy->Enabled = false;
    PCut->Enabled = false;
  }

}
//---------------------------------------------------------------------------



