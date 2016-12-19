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
        m_fpOut = fopen("F:\\C++ builder\\以完成\\将员工信息保存到磁盘210\\faculity.txt","w");
        if(m_fpOut == NULL)
        {
                MessageBox(NULL,"创建文件出错","出错信息",MB_OK);
                Close();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
      AnsiString name = EditName->Text;
      int age = StrToInt(EditAge->Text);
      int salary = StrToInt(EditSalary->Text);
      AnsiString phone = EditPhone->Text;
      fprintf(m_fpOut,"%s\n%d\n%d\n%s\n",name,age,salary,phone);
      EditName->Text = "";
      EditAge->Text = "";
      EditSalary->Text = "";
      EditPhone->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        AnsiString name = EditName->Text;
        if(name == "")
        {
                Close();
                return;
        }
        int age = StrToInt(EditAge->Text);
        int salary = StrToInt(EditSalary->Text);
        AnsiString phone = EditPhone->Text;
        fprintf(m_fpOut,"%s%d%d%s",name,age,salary,phone);
        fclose(m_fpOut);
        Close();
}
//---------------------------------------------------------------------------
