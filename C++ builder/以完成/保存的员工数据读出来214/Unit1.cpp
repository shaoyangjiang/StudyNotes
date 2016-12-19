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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
         m_fpIn = fopen("F:\\C++ builder\\以完成\\将员工信息保存到磁盘210\\faculity.txt","r");
         if(m_fpIn == NULL)
         {
                MessageBox(NULL,"打开文件出错","出错文件",MB_OK);
                Close();
         }
         Button1Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        rewind(m_fpIn);
        Button2Click(Sender);
        Button1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        char* name = new char;
        char* phone = new char;
        int age,salary;
        if(!feof(m_fpIn))
        {
                fscanf(m_fpIn,"%s%d%d%s",name,&age,&salary,phone);
                EditName->Text = name;
                EditAge->Text = IntToStr(age);
                EditSalary->Text = IntToStr(salary);
                EditPhone->Text = phone;
        }
        else
        {
                Button1->Enabled = true;
                Button2->Enabled = false;
        }
        delete name;
        delete phone;
}
//---------------------------------------------------------------------------
