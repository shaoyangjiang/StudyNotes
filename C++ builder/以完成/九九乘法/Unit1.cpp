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

void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
        if(ListBox1->ItemIndex>=0 && ListBox2->ItemIndex>=0)
        {
                AnsiString strFirst = ListBox1->Items->Strings[ListBox1->ItemIndex];
                AnsiString strSecond = ListBox2->Items->Strings[ListBox2->ItemIndex];
                try
                {
                        int first = StrToInt(strFirst);
                        int second = StrToInt(strSecond);
                        ListBox3->Items->Add(strFirst + "*" + strSecond + "=" + IntToStr(first*second));
                }
                catch(EConvertError *E)
                {
                        MessageBox(NULL,"输入的不是数字","信息",MB_OK);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox3Click(TObject *Sender)
{
        ListBox3->Items->Delete(ListBox3->ItemIndex);
}
//---------------------------------------------------------------------------
