//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include  "stdio.h"
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
        if(SaveDialog1->Execute())
       {
         FILE* fp = fopen(SaveDialog1->FileName.c_str(),"w");
         if(fp == NULL)
         {
                MessageBox(NULL,"打开文件出错","信息",MB_OK);
                return;
         }
         for(int i = 0;i<Memo1->Lines->Count;i++)
         {
                fputs(Memo1->Lines->Strings[i].c_str(),fp);
                fputc('\n',fp);
         }
         fclose(fp);
       }
}
//---------------------------------------------------------------------------
 