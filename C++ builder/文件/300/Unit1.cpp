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
        ComboBox1->Items->Add("����");
        ComboBox1->Items->Add("����");
        ComboBox1->Items->Add("������");
        ComboBox1->Items->Add("ά�����");
        ComboBox1->Items->Add("������");
        ComboBox1->Items->Add("");

        //���ļ�
        m_pFile = fopen("F:\\C++ builder\\�ļ�\\300\\student.lgf","a+b");
        if(m_pFile == NULL)
        {
                MessageBox(NULL,"��ʧ��","��Ϣ",MB_OK);
                exit(0);
        }

        //ȷ���ļ�����
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
        //����ļ��������ݣ������һ������
        rewind(m_pFile);
        STUDENT Student;
        fread(&Student,sizeof(STUDENT),1,m_pFile);
        //��ʾ
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
        //���ļ��е�һ��ѧ���ļ�¼
        rewind(m_pFile);
        STUDENT Student;
        fread(&Student,sizeof(STUDENT),1,m_pFile);
        //��ʾ
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
        //����Ѿ������һ����¼
        if(m_nCurRecordIndex == 0)
        {
                Prior->Enabled = false;
                First->Enabled = false;
                Next->Enabled = true;
                Last->Enabled = true;
                return;
        }
        m_nCurRecordIndex --;
        //�����ǰ�ƶ�һ�������ﵽ��һ��
        if(m_nCurRecordIndex == 0)
        {
                Prior->Enabled = false;
                First->Enabled = false;
        }
        Next->Enabled = true;
        Last->Enabled = true;
        //����ǰλ�õ�ǰһ��ѧ����¼
        fseek(m_pFile,m_nCurRecordIndex * sizeof(STUDENT),SEEK_SET);
        STUDENT Student;
        fread(&Student,sizeof(STUDENT),1,m_pFile);
        //��ʾ
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
        //����ǰλ�õ���һ��ѧ��
        STUDENT Student;
        fread(&Student,sizeof(STUDENT),1,m_pFile);
        //��ʾ
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
        //�����һ��ѧ����¼
        fseek(m_pFile,m_nCurRecordIndex * sizeof(STUDENT),SEEK_SET);
        STUDENT Student;
        fread(&Student,sizeof(STUDENT),1,m_pFile);
        //��ʾ
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
        //д���ļ����
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
        //�޸ĵ�ǰ��¼
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
        //���ļ�ָ���ƶ�����ǰ��¼��ǰ��
        fseek(m_pFile,m_nCurRecordIndex * sizeof(STUDENT),SEEK_SET);
        fwrite(&Student,sizeof(STUDENT),1,m_pFile);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteClick(TObject *Sender)
{
        m_nTotalRecord --;
        //Ҫɾ����ǰ��¼������Ҫ�����к���ļ�¼������ǰ�ƶ�
        //Ҫ����ǰ��¼�����е����ݣ��ͱ�����ȷ�������¼����Ŀ
        int curLen = ftell(m_pFile);
        fseek(m_pFile,0,SEEK_END);
        int endLen = ftell(m_pFile);
        int recordNum = (endLen - curLen)/sizeof(STUDENT);
        //�����ǰ��¼�����һ��
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
        //��ʾ��һ����¼������
        Edit1->Text = IntToStr(pStudent[0].studentNo);
        Edit2->Text = pStudent[0].name;
        Edit3->Text = DateTimeToStr(pStudent[0].birthday);
        Edit4->Text = IntToStr(pStudent[0].classNo);
        ComboBox1->Text = pStudent[0].nation;
        if(pStudent[0].sex)
                RadioButton1->Checked = true;
        else
                RadioButton2->Checked = true;
        //�ͷ���Դ
        delete pStudent;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        //������ǰ��ɾ�����������ǲ�û������ɾ�����ݣ�
        //ֻ�ǽ�m_nTotalRecord����1�������Ҫ����д��
        STUDENT* pStudent = new STUDENT[m_nTotalRecord];
        rewind(m_pFile);
        fread(pStudent,sizeof(STUDENT),m_nTotalRecord,m_pFile);
        fclose(m_pFile);
        //Ȼ���ø��ǵķ�ʽ���´��ļ�
        m_pFile = fopen("F:\\C++ builder\\�ļ�\\300\\student.lgf","w+b");
        fwrite(pStudent,sizeof(STUDENT),m_nTotalRecord,m_pFile);
        fclose(m_pFile);
}
//---------------------------------------------------------------------------

