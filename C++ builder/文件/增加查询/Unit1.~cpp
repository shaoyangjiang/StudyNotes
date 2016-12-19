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
        char name[20];
        int chinese;
        int english;
        int math;
};

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
        m_fpFile = fopen("F:\\C++ builder\\文件\\增加查询\\faculity.txt","a+b");
        if(m_fpFile == NULL)
        {
                MessageBox(NULL,"打开出错文件！","信息",MB_OK);
                Close();
        }

        m_nTotalRecord = 0;
        STUDENT student;
        fread(&student,sizeof(STUDENT),1,m_fpFile);
        while(!feof(m_fpFile))
        {
                fread(&student,sizeof(STUDENT),1,m_fpFile);
                m_nTotalRecord ++;
        }
        rewind(m_fpFile);
        m_nRecordIndex = -1;

        if(m_nTotalRecord >0)
        {
                NextClick(Sender);
                if(m_nRecordIndex == m_nTotalRecord-1)
                        Next->Enabled = false;
                Prev->Enabled = false;
        }
        else
        {
                Prev->Enabled = false;
                Next->Enabled = false;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(m_fpFile)
                fclose(m_fpFile);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddClick(TObject *Sender)
{
        if(NameEdit->Text == "")
        return;

        fseek(m_fpFile,0,SEEK_END);
        STUDENT student;
        strcpy(student.name,NameEdit->Text.c_str());

        try
        {
                student.chinese = StrToInt(ChineseEdit->Text);
                student.english = StrToInt(EnglishEdit->Text);
                student.math = StrToInt(MathEdit->Text);
                fwrite(&student,sizeof(STUDENT),1,m_fpFile);
                m_nTotalRecord ++;
        }
        catch(...)
        {
                return;
        }

        fseek(m_fpFile,m_nRecordIndex * sizeof(STUDENT),SEEK_SET);
        ChineseEdit->Text = "";
        EnglishEdit->Text = "";
        MathEdit->Text = "";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::NextClick(TObject *Sender)
{
        if(!feof(m_fpFile))
        {
                STUDENT student;

                ZeroMemory(&student,sizeof(STUDENT));
                fread(&student,sizeof(STUDENT),1,m_fpFile);
                NameEdit->Text = student.name;
                ChineseEdit->Text = IntToStr(student.chinese);
                EnglishEdit->Text = IntToStr(student.english);
                MathEdit->Text = IntToStr(student.math);
                m_nRecordIndex ++;
                if(m_nRecordIndex > 0)
                        Prev->Enabled = true;
        }
        else
        {
                Next->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PrevClick(TObject *Sender)
{
        fseek(m_fpFile,sizeof(STUDENT),SEEK_CUR);
        STUDENT student;
        fread(&student,sizeof(STUDENT),1,m_fpFile);
        NameEdit->Text = student.name;
        ChineseEdit->Text = IntToStr(student.chinese);
        EnglishEdit->Text = IntToStr(student.english);
        MathEdit->Text = IntToStr(student.math);
        m_nRecordIndex --;
        if(m_nRecordIndex <=0)
                Prev->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::QueryClick(TObject *Sender)
{
        if(NameEdit->Text == "")
                return;

        rewind(m_fpFile);
        int currentIndex = -1;
        STUDENT student;
        while(!feof(m_fpFile))
        {
                fread(&student,sizeof(STUDENT),1,m_fpFile);
                currentIndex ++;
                if(strcmp(student.name,NameEdit->Text.c_str())==0)
                {
                         ChineseEdit->Text = IntToStr(student.chinese);
                         EnglishEdit->Text = IntToStr(student.english);
                         MathEdit->Text = IntToStr(student.math);
                         m_nRecordIndex = currentIndex;
                         return;
                }
        }
        ChineseEdit->Text = "";
        EnglishEdit->Text = "";
        MathEdit->Text = "";
        m_nRecordIndex = -1;
}
//---------------------------------------------------------------------------

