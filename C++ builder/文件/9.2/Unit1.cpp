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
        FILE*  m_fpFile;
         m_fpFile = fopen("F:\\C++ builder\\文件\\9.2\\student.dat","r");
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
        delete name;
        delete sex;
        fclose(m_fpFile);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

