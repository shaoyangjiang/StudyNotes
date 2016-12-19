//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "stdio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct STUDENT
{
        int code;
        char name[10];
        char sex[2];
        int math;
        int chinese;
        int english;
};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
       m_fpOut = fopen("F:\\C++ builder\\文件\\9.3\\student.dat","wb");
        if(m_fpOut == NULL)
        {
                MessageBox(NULL,"打开出错文件！","信息",MB_OK);
                Close();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        STUDENT student;
        ZeroMemory(&student,sizeof(STUDENT));
        try
        {
                student.code = StrToInt(Edit1->Text);
                strcpy(student.name,Edit2->Text.c_str());
                if(RadioButton1->Checked)
                        strcpy(student.sex,"男");
                else
                        strcpy(student.sex,"女");
                student.math = StrToInt(Edit3->Text);
                student.chinese = StrToInt(Edit4->Text);
                student.english = StrToInt(Edit5->Text);
                fwrite(&student,sizeof(STUDENT),1,m_fpOut);

                Edit1->Text = "";
                Edit2->Text = "";
                Edit3->Text = "";
                Edit4->Text = "";
                Edit5->Text = "";
                RadioButton1->Checked = true;
        }
        catch(...)
        {
                MessageBox(NULL,"输入有误","信息",MB_OK);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
         if(m_fpOut)
                fclose(m_fpOut);
          Close();
}
//---------------------------------------------------------------------------
