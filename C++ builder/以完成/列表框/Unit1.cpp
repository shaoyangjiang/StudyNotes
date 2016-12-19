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
        int n = 0;
        for(int i = ListBox1->Items->Count -1;i>=0;i--)
        {
                if(ListBox1->Selected[i])
                {
                        ListBox2->Items->Insert(n,ListBox1->Items->Strings[i]);
                        ListBox1->Items->Delete(i);
                        n++;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
         int n = 0;
        for(int i = ListBox2->Items->Count -1;i>=0;i--)
        {
                if(ListBox2->Selected[i])
                {
                        ListBox1->Items->Insert(n,ListBox2->Items->Strings[i]);
                        ListBox2->Items->Delete(i);
                        n++;
                }
        }
}
//---------------------------------------------------------------------------
