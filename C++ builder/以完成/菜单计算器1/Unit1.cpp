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

void __fastcall TForm1::OperClick(TObject *Sender)
{
      if(Edit1->Text == "" ||Edit2->Text == "")
          {
                Add->Enabled = false ;
                Sub->Enabled = false ;
                Mul->Enabled = false ;
                Div->Enabled = false ;
                return;
          }
          else
          {
               Add->Enabled = true ;
               Sub->Enabled = true ;
               Mul->Enabled = true ;
               Div->Enabled = true ;
          }

          int div ;
          try
          {
                div= StrToInt(Edit2->Text);
          }
          catch(EConvertError *E)
          {
                MessageBox(NULL,"输入不是数字","信息",MB_OK);
          }
          if(div==0)
          Div->Enabled = false;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddClick(TObject *Sender)
{
         try
        {
                int first = StrToInt(Edit1->Text);
                int second = StrToInt(Edit2->Text);
                Edit3->Text = IntToStr(first+second);
        }
        catch(EConvertError *E)
          {
                MessageBox(NULL,"输入不是数字","信息",MB_OK);
          }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SubClick(TObject *Sender)
{
           try
          {
                int first = StrToInt(Edit1->Text);
                int second = StrToInt(Edit2->Text);
                Edit3->Text = IntToStr(first-second);
          }
        catch(EConvertError *E)
          {
                MessageBox(NULL,"输入不是数字","信息",MB_OK);
          }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MulClick(TObject *Sender)
{
        try
          {
                int first = StrToInt(Edit1->Text);
                int second = StrToInt(Edit2->Text);
                Edit3->Text = IntToStr(first*second);
          }
        catch(EConvertError *E)
          {
                MessageBox(NULL,"输入不是数字","信息",MB_OK);
          }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DivClick(TObject *Sender)
{
          try
          {
                int first = StrToInt(Edit1->Text);
                int second = StrToInt(Edit2->Text);
                Edit3->Text = FloatToStr((float)first/second);
          }
        catch(EConvertError *E)
          {
                MessageBox(NULL,"输入不是数字","信息",MB_OK);
          }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitClick(TObject *Sender)
{
       Close();
}
//---------------------------------------------------------------------------
