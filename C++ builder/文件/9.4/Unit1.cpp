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
       m_fpOut = fopen("F:\\C++ builder\\文件\\9.3\\student.dat","rb");
        if(m_fpOut == NULL)
        {
                MessageBox(NULL,"打开出错文件！","信息",MB_OK);
                Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if(Edit1->Text == "")
        return;
        try
        {
              int code = StrToInt(Edit1->Text);
                int result = fseek(m_fpOut,(code-1)*sizeof(STUDENT),SEEK_SET);
                if(result!=0)
                {
                        MessageBox(NULL,"此学号不存在","提示信息",MB_OK);
                        return;
                }

                STUDENT student;
                ZeroMemory(&student,sizeof(STUDENT));
                fread(&student,sizeof(STUDENT),1,m_fpOut);
                Edit2->Text = student.name;
                Edit3->Text = IntToStr(student.math);
                Edit4->Text = IntToStr(student.chinese);
                Edit5->Text = IntToStr(student.english);
                AnsiString temp = "男";
                if(strcmp(student.sex,temp.c_str())==0)
                        RadioButton1->Checked = true;
                else
                        RadioButton2->Checked = true;
          }
         catch(...)
          {
               MessageBox(NULL,"输入有误","出错信息",MB_OK);
          }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        if(Edit2->Text == "")
                return;
        rewind(m_fpOut);
        STUDENT student;
        while(!feof(m_fpOut))
        {
          fread(&student,sizeof(STUDENT),1,m_fpOut);
          if(strcmp(student.name,Edit2->Text.c_str())==0)
          {
            Edit1->Text = StrToInt(student.code);
            Edit3->Text = IntToStr(student.math);
            Edit4->Text = IntToStr(student.chinese);
            Edit5->Text = IntToStr(student.english);
            AnsiString temp = "男";
            if(strcmp(student.sex,temp.c_str())==0)
                RadioButton1->Checked = true;
            else
                RadioButton2->Checked = true;
            break;
          }
        }
}
//---------------------------------------------------------------------------



