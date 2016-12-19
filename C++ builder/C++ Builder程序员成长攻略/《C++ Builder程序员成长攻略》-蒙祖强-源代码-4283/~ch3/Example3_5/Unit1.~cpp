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
{  /*
 char *x;
 //RxRichEdit.SelAttributes.Name := FontDialog1.Font.Name;
 RichEdit1->SelAttributes->Name = "宋体";
 RichEdit1->SelAttributes->Color = clRed;
 RichEdit1->SelAttributes->Size = 18;
 RichEdit1->SelAttributes->Style = TFontStyles() << fsUnderline << fsBold << fsStrikeOut;


 //Edit1->Font->Style = TFontStyles() << fsUnderline << fsStrikeOut << fsBold;
 */
 RadioButton1->Checked = true;
 //RadioButton2->Checked = true; 
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
  RichEdit1->SelAttributes->Name = "宋体";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
  RichEdit1->SelAttributes->Name = "楷体_GB2312";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
  RichEdit1->SelAttributes->Name = "华文彩云";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
  RichEdit1->SelAttributes->Name = "隶书";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
   RichEdit1->SelAttributes->Color = clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton6Click(TObject *Sender)
{
  RichEdit1->SelAttributes->Color = clRed;          
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton7Click(TObject *Sender)
{
  RichEdit1->SelAttributes->Color = clGreen;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton8Click(TObject *Sender)
{
  RichEdit1->SelAttributes->Color = clBlue;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  RichEdit1->SelAttributes->Style = TFontStyles() << fsBold;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  RichEdit1->SelAttributes->Style = TFontStyles() << fsItalic;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
  RichEdit1->SelAttributes->Style = TFontStyles() << fsUnderline;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
  if(SpeedButton1->Flat) SpeedButton1->Flat = false;
  else SpeedButton1->Flat = true;
  if(SpeedButton1->Flat) RichEdit1->SelAttributes->Style = RichEdit1->SelAttributes->Style + (TFontStyles() << fsBold);
  else RichEdit1->SelAttributes->Style = RichEdit1->SelAttributes->Style - (TFontStyles() << fsBold);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RichEdit1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  //
 if(RichEdit1->SelAttributes->Style.Contains(fsBold)) SpeedButton1->Flat = true;
 else SpeedButton1->Flat = false;

 if(RichEdit1->SelAttributes->Style.Contains(fsItalic)) SpeedButton2->Flat = true;
 else SpeedButton2->Flat = false;

 if(RichEdit1->SelAttributes->Style.Contains(fsUnderline)) SpeedButton3->Flat = true;
 else SpeedButton3->Flat = false;

 if(RichEdit1->SelAttributes->Name=="宋体") RadioButton1->Checked = true;
 if(RichEdit1->SelAttributes->Name=="楷体_GB2312") RadioButton2->Checked = true;
 if(RichEdit1->SelAttributes->Name=="华文彩云") RadioButton3->Checked = true;
 if(RichEdit1->SelAttributes->Name=="隶书") RadioButton4->Checked = true;

 if(RichEdit1->SelAttributes->Color==clBlack) RadioButton5->Checked = true;
 if(RichEdit1->SelAttributes->Color==clRed) RadioButton6->Checked = true;
 if(RichEdit1->SelAttributes->Color==clGreen) RadioButton7->Checked = true;
 if(RichEdit1->SelAttributes->Color==clBlue) RadioButton8->Checked = true;

 if(RichEdit1->SelAttributes->Size==12) RadioButton9->Checked = true;
 if(RichEdit1->SelAttributes->Size==18) RadioButton10->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
  if(SpeedButton2->Flat) SpeedButton2->Flat = false;   //[fsBold,fsItalic,fsUnderline]
  else SpeedButton2->Flat = true;
  if(SpeedButton2->Flat) RichEdit1->SelAttributes->Style = RichEdit1->SelAttributes->Style + (TFontStyles() << fsItalic);
  else RichEdit1->SelAttributes->Style = RichEdit1->SelAttributes->Style - (TFontStyles() << fsItalic);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
  if(SpeedButton3->Flat) SpeedButton3->Flat = false;   //[fsBold,fsItalic,fsUnderline]
  else SpeedButton3->Flat = true;
  if(SpeedButton3->Flat) RichEdit1->SelAttributes->Style = RichEdit1->SelAttributes->Style + (TFontStyles() << fsUnderline);
  else RichEdit1->SelAttributes->Style = RichEdit1->SelAttributes->Style - (TFontStyles() << fsUnderline);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton9Click(TObject *Sender)
{
  RichEdit1->SelAttributes->Size = 12;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton10Click(TObject *Sender)
{
  RichEdit1->SelAttributes->Size = 18;        
}
//---------------------------------------------------------------------------
