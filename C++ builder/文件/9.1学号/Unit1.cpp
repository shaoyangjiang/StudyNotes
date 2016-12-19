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
        m_fpFile = fopen("F:\\C++ builder\\文件\\9.1学号\\student.dat","w");
        if(m_fpFile == NULL)
        {
                MessageBox(NULL,"打开出错文件！","信息",MB_OK);
                Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
          if(m_fpFile)
                fclose(m_fpFile);
          Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
      try
      {
      int number = StrToInt(Edit1->Text);
      AnsiString name = Edit2->Text;
      int math = StrToInt(Edit3->Text);
      int chinese = StrToInt(Edit4->Text);
      int english = StrToInt(Edit5->Text);
      String sex = "男";
      if(RadioButton2->Checked)
        sex = "女";
      fprintf(m_fpFile,"%d%s%s%d%d%d",number,name,sex,math,chinese,english);
      Edit1->Text = "";
      Edit2->Text = "";
      Edit3->Text = "";
      Edit4->Text = "";
      Edit5->Text = "";
      RadioButton1->Checked = true;
      }
      catch(...)
      {
      }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        m_fpFile = fopen("F:\\C++ builder\\文件\\9.1学号\\student.dat","r");
        if(m_fpFile == NULL)
        {
                MessageBox(NULL,"打开出错文件！","信息",MB_OK);
               return;
        }

        AnsiString firstLine = "学号   姓名   性别   数学  语文   英语   平均分 ";
        AnsiString secondLine = "**************************************************";
        Memo1->Lines->Add(firstLine);
        Memo1->Lines->Add(secondLine);
        int number,math,chinese,english;
        char* name = new char;
        char* sex = new char;
        while(!feof(m_fpFile))
        {
                AnsiString str;
                fscanf(m_fpFile,"%d%s%s%d%d%d",&number,name,sex,&math,&chinese,&english);
                str +=IntToStr(number) + "   ";
                str +=name;
                str +="   ";
                str +=sex;
                str +="   ";
                str +=IntToStr(math) + "   ";
                str +=IntToStr(chinese) + "   ";
                str +=IntToStr(english) + "   ";
                str += FloatToStr((math+english+chinese)/3);
                Memo1->Lines->Add(str);
        }
       // delete name;
       // delete sex;
        fclose(m_fpFile);
}
//---------------------------------------------------------------------------
