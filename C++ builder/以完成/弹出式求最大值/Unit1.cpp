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

void __fastcall TForm1::MAXClick(TObject *Sender)
{
        try
        {
                int first = StrToInt (Edit1->Text);
                int second = StrToInt (Edit2->Text);
                int third = StrToInt (Edit3->Text);
                int max= first > second ? first : second;
                max = max > second ? max : third;
                Edit4->Text = IntToStr(max);
        }
        catch(EConvertError *E)
        {
                MessageBox(NULL,"输入的不是数字","信息",MB_OK);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MINClick(TObject *Sender)
{
           try
        {
                int first = StrToInt (Edit1->Text);
                int second = StrToInt (Edit2->Text);
                int third = StrToInt (Edit3->Text);
                int min= first < second ? first : second;
                min = min < second ? min : third;
                Edit4->Text = IntToStr(min);
        }
        catch(EConvertError *E)
        {
                MessageBox(NULL,"输入的不是数字","信息",MB_OK);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AVERAGEClick(TObject *Sender)
{
         try
         {
                int first = StrToInt (Edit1->Text);
                int second = StrToInt (Edit2->Text);
                int third = StrToInt (Edit3->Text);
                float average = (first+second+third)/3.0;
                Edit4->Text = FloatToStr(average);
         }
        catch(EConvertError *E)
        {
                MessageBox(NULL,"输入的不是数字","信息",MB_OK);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PopupMenu1Popup(TObject *Sender)
{
        if(Edit1->Text == ""||Edit2->Text == ""||Edit3->Text =="")
        {
                MAX->Enabled = false;
                MIN->Enabled = false;
                AVERAGE->Enabled =false;
        }
        else
        {
            
                MAX->Enabled = true;
                MIN->Enabled = true;
                AVERAGE->Enabled =true;
        }
}
//---------------------------------------------------------------------------
