//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
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
        if(Form2)
         Form2->ShowModal();
        else
         MessageBox(NULL,"form2不存在","信息",MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
         if(Form3)
         Form3->ShowModal();
        else
         //MessageBox(NULL,"form3不存在","信息",MB_OK);
         {
                Form3 = new TForm3(this);
                Form3->ShowModal();
                delete Form3;
         }
}
//---------------------------------------------------------------------------
