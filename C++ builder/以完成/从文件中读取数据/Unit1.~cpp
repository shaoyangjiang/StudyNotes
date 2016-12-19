//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "stdio.h"
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
        Memo1->Clear();
        if(OpenDialog1->Execute())
        {
                FILE* fp = fopen(OpenDialog1->FileName.c_str(),"r");
                if(fp == NULL)
                {
                        MessageBox(NULL,"打开文件出错！","出错信息",MB_OK);
                        return;
                }
                while(!feof(fp))
                {
                        char buff[100];
                        fgets(buff,100,fp);
                        Memo1->Lines->Add(buff);
                }
                fclose(fp);

        }
}
//---------------------------------------------------------------------------
 