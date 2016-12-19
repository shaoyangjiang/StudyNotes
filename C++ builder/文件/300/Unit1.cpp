//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "stdio.h"
#include "systdate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct STUDENT
{
        int studentNo;
        char name[20];
        char nation[20];
        bool sex;
        TDateTime birthday;
        int classNo;
};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        m_pFile = NULL;
        m_nTotalRecord = 0;
        m_nCurRecordIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        ComboBox1->Items->Add("汉族");
        ComboBox1->Items->Add("回族");
        ComboBox1->Items->Add("土家族");
        ComboBox1->Items->Add("维吾尔族");
        ComboBox1->Items->Add("朝鲜族");
        ComboBox1->Items->Add("");

        //打开文件
        m_pFile = fopen("F:\\C++ builder\\文件\\300\\student.lgf","a+b");
        if(m_pFile == NULL)
        {
                MessageBox(NULL,"打开失败","信息",MB_OK);
                exit(0);
        }

        //确定文件长度
        fseek(m_pFile,0,SEEK_END);
        int length = ftell(m_pFile);
        if(length == 0)
        {
                First->Enabled = false;
                Prior->Enabled = false;
                Next->Enabled  = false;
                Last->Enabled  = false;
                Edit->Enabled  = false;
                Delete->Enabled = false;
                return;
        }
        m_nTotalRecord = length / sizeof(STUDENT);
        //如果文件中有内容，则读第一个内容
        rewind(m_pFile);
        STUDENT Student;
        fread(&Student,sizeof(STUDENT),1,m_pFile);
        //显示
        Edit1->Text = IntToStr(Student.studentNo);
        Edit2->Text = Student.name;
        Edit3->Text = DateTimeToStr(Student.birthday);
        Edit4->Text = IntToStr(Student.classNo);
        ComboBox1->Text = Student.nation;
        if(Student.sex)
                RadioButton1->Checked = true;
        else
                RadioButton2->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FirstClick(TObject *Sender)
{
        //读文件中第一个学生的记录
        rewind(m_pFile);
        STUDENT Student;
        fread(&Student,sizeof(STUDENT),1,m_pFile);
        //显示
        Edit1->Text = IntToStr(Student.studentNo);
        Edit2->Text = Student.name;
        Edit3->Text = DateTimeToStr(Student.birthday);
        Edit4->Text = IntToStr(Student.classNo);
        ComboBox1->Text = Student.nation;
        if(Student.sex)
                RadioButton1->Checked = true;
        else
                RadioButton2->Checked = true;
        Prior->Enabled = false;
        m_nCurRecordIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PriorClick(TObject *Sender)
{
        //如果已经到达第一个记录
        if(m_nCurRecordIndex == 0)
        {
                Prior->Enabled = false;
                First->Enabled = false;
                Next->Enabled = true;
                Last->Enabled = true;
                return;
        }
        m_nCurRecordIndex --;
        //如果向前移动一个距离后达到第一个
        if(m_nCurRecordIndex == 0)
        {
                Prior->Enabled = false;
                First->Enabled = false;
        }
        Next->Enabled = true;
        Last->Enabled = true;
        //读当前位置的前一个学生记录
        fseek(m_pFile,m_nCurRecordIndex * sizeof(STUDENT),SEEK_SET);
        STUDENT Student;
        fread(&Student,sizeof(STUDENT),1,m_pFile);
        //显示
        Edit1->Text = IntToStr(Student.studentNo);
        Edit2->Text = Student.name;
        Edit3->Text = DateTimeToStr(Student.birthday);
        Edit4->Text = IntToStr(Student.classNo);
        ComboBox1->Text = Student.nation;
        if(Student.sex)
                RadioButton1->Checked = true;
        else
                RadioButton2->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NextClick(TObject *Sender)
{
        if(m_nCurRecordIndex == m_nTotalRecord - 1)
        {
                Next->Enabled = false;
                Last->Enabled = false;
                Prior->Enabled = true;
                First->Enabled = true;
        }
        //当当前位置的下一个学生
        STUDENT Student;
        fread(&Student,sizeof(STUDENT),1,m_pFile);
        //显示
        Edit1->Text = IntToStr(Student.studentNo);
        Edit2->Text = Student.name;
        Edit3->Text = DateTimeToStr(Student.birthday);
        Edit4->Text = IntToStr(Student.classNo);
        ComboBox1->Text = Student.nation;
        if(Student.sex)
                RadioButton1->Checked = true;
        else
                RadioButton2->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LastClick(TObject *Sender)
{
        m_nCurRecordIndex = m_nTotalRecord - 1;
        //读最后一个学生记录
        fseek(m_pFile,m_nCurRecordIndex * sizeof(STUDENT),SEEK_SET);
        STUDENT Student;
        fread(&Student,sizeof(STUDENT),1,m_pFile);
        //显示
        Edit1->Text = IntToStr(Student.studentNo);
        Edit2->Text = Student.name;
        Edit3->Text = DateTimeToStr(Student.birthday);
        Edit4->Text = IntToStr(Student.classNo);
        ComboBox1->Text = Student.nation;
        if(Student.sex)
                RadioButton1->Checked = true;
        else
                RadioButton2->Checked = true;
        Next->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddClick(TObject *Sender)
{
        STUDENT Student;
        Student.studentNo = StrToInt(Edit1->Text);
        strcpy(Student.name,Edit2->Text.c_str());
        Student.birthday = StrToDateTime(Edit3->Text);
        Student.classNo = StrToInt(Edit4->Text);
        strcpy(Student.nation,ComboBox1->Text.c_str());
        if(RadioButton1->Checked)
                Student.sex = true;
        else
                Student.sex = false;
        //写到文件最后
        fseek(m_pFile,m_nTotalRecord * sizeof(STUDENT),SEEK_SET);
        fwrite(&Student,sizeof(STUDENT),1,m_pFile);
        First->Enabled = true;
        Prior->Enabled = true;
        Next->Enabled = false;
        Last->Enabled = false;
        m_nTotalRecord ++;
        m_nCurRecordIndex = m_nTotalRecord - 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditClick(TObject *Sender)
{
        //修改当前记录
        STUDENT Student;
        Student.studentNo = StrToInt(Edit1->Text);
        strcpy(Student.name,Edit2->Text.c_str());
        Student.birthday = StrToDateTime(Edit3->Text);
        Student.classNo = StrToInt(Edit4->Text);
        strcpy(Student.nation,ComboBox1->Text.c_str());
        if(RadioButton1->Checked)
                Student.sex = true;
        else
                Student.sex = false;
        //将文件指针移动到当前记录最前面
        fseek(m_pFile,m_nCurRecordIndex * sizeof(STUDENT),SEEK_SET);
        fwrite(&Student,sizeof(STUDENT),1,m_pFile);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteClick(TObject *Sender)
{
        m_nTotalRecord --;
        //要删除当前记录，加是要将所有后面的记录数据向前移动
        //要读当前记录后所有的数据，就必须先确定后面记录的数目
        int curLen = ftell(m_pFile);
        fseek(m_pFile,0,SEEK_END);
        int endLen = ftell(m_pFile);
        int recordNum = (endLen - curLen)/sizeof(STUDENT);
        //如果当前记录是最后一个
        if(recordNum == 0)
        {
                Next->Enabled = false;
                Edit1->Text = "";
                Edit2->Text = "";
                Edit3->Text = "";
                Edit4->Text = "";
                ComboBox1->Text = "";
                return;
        }
        fseek(m_pFile,curLen,SEEK_SET);
        STUDENT* pStudent = NULL;
        pStudent = new STUDENT[recordNum];
        if(pStudent == NULL)
                return;
        fread(pStudent,sizeof(STUDENT),recordNum,m_pFile);
        //显示下一个记录的内容
        Edit1->Text = IntToStr(pStudent[0].studentNo);
        Edit2->Text = pStudent[0].name;
        Edit3->Text = DateTimeToStr(pStudent[0].birthday);
        Edit4->Text = IntToStr(pStudent[0].classNo);
        ComboBox1->Text = pStudent[0].nation;
        if(pStudent[0].sex)
                RadioButton1->Checked = true;
        else
                RadioButton2->Checked = true;
        //释放资源
        delete pStudent;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        //由于在前面删除操作中我们并没有真正删除内容，
        //只是将m_nTotalRecord减了1，因此需要重新写入
        STUDENT* pStudent = new STUDENT[m_nTotalRecord];
        rewind(m_pFile);
        fread(pStudent,sizeof(STUDENT),m_nTotalRecord,m_pFile);
        fclose(m_pFile);
        //然后用覆盖的方式重新打开文件
        m_pFile = fopen("F:\\C++ builder\\文件\\300\\student.lgf","w+b");
        fwrite(pStudent,sizeof(STUDENT),m_nTotalRecord,m_pFile);
        fclose(m_pFile);
}
//---------------------------------------------------------------------------

