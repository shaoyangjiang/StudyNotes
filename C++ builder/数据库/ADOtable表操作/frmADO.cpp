//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmADO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString myfield,myval;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        //��ADOTable1����ʾ��¼
        ADOTable1->Active = true;
        for(int i=0;i<=(ADOTable1->Fields->Count-1);i++)
        {       //Ϊ���ҹ��ܵ�CombeBox������ֶ�����
                ComboBox1->Items->Add(ADOTable1->Fields->Fields[i]->FieldName);
        }
        for(int i=0;i<=(ADOTable1->Fields->Count-1);i++)
        {        //Ϊɸѡ���ܵ�CombeBox������ֶ�����
               ComboBox2->Items->Add(ADOTable1->Fields->Fields[i]->FieldName);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddClick(TObject *Sender)
{
        TLocateOption Opts;
        Opts<<loPartialKey;
        if(ID->Text=="" || Name->Text=="" || Age->Text=="" || Sex->Text == "")
        {
                ShowMessage("ѧ����Ϣ��ȫ���������루���ʳ����");
                return;
        }
        ADOTable1->First();
        while(!ADOTable1->Eof)
        {
                if(ADOTable1->FieldValues["ѧ��"]==ID->Text)
                {       //ѧ��Ψһ�������ظ����
                        ShowMessage("��ѧ���Ѿ����ڣ�ѧ��Ψһ");
                        return;
                }
                else
                        ADOTable1->Next();
        }
        ADOTable1->Insert();   //׼�����
        ADOTable1->FieldValues["ѧ��"]=ID->Text;
        ADOTable1->FieldValues["����"]=Name->Text;
        ADOTable1->FieldValues["����"]=Age->Text;
        ADOTable1->FieldValues["����"]=Salary->Text;
        ADOTable1->FieldValues["�Ա�"]=Sex->Text;
        if(MessageDlg("ȷ���Ƿ����",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
                ADOTable1->Post();  //ȷ�����
        else
                ADOTable1->Cancel();   //ȡ�����
        ID->Text="";
        Name->Text="";
        Age->Text="";
        Salary->Text="����";
        Sex->Text="";
}
//---------------------------------------------------------------------------
//virtual bool __fastcall Locate(const AnsiString KeyField,const System::Variant &KeyValues,Db::TLocateOptions Options);
void __fastcall TForm1::FindClick(TObject *Sender)
{
        TLocateOptions Opts;
        Opts<<loPartialKey;
        if(ADOTable1->Locate(ComboBox1->Text,FindValue->Text,Opts))
        {
                ShowMessage("���ҳɹ����Ѿ���λ");
        }
        else
        {
                ShowMessage("�Ҳ�������");
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteClick(TObject *Sender)
{
        if(MessageDlg("ȷ���Ƿ�ɾ��",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
                ADOTable1->Delete();
}
//---------------------------------------------------------------------------
//ɸѡ��ť�Ĺ���ֻ�����ô�ֵ������Ȼ�󴥷�ADOTable1��OnFilterRecord�¼�
void __fastcall TForm1::FilterClick(TObject *Sender)
{
        ADOTable1->Filtered = false;
        myfield=ComboBox2->Text;    //�ֶ�����
        myval=FilterValue->Text;    //����ֵ
        ADOTable1->Filtered = true;  //����OnfilterRecord�¼�
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ADOTable1FilterRecord(TDataSet *DataSet,
      bool &Accept)
{
        switch(ComboBox3->ItemIndex)
        {
                case 0:
                        Accept=ADOTable1->FieldValues[myfield]>myval;
                        break;
                case 1:
                        Accept=ADOTable1->FieldValues[myfield]<myval;
                        break;
                case 2:
                        Accept=ADOTable1->FieldValues[myfield]>=myval;
                        break;
                case 3:
                        Accept=ADOTable1->FieldValues[myfield]<=myval;
                        break;
                case 4:
                        Accept=ADOTable1->FieldValues[myfield]==myval;
                        break;
                case 5:
                        Accept=ADOTable1->FieldValues[myfield]!=myval;
                        break;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PriorClick(TObject *Sender)
{
        ADOTable1->Prior();
        if(ADOTable1->Bof==true)    //�ж��Ƿ��˿�ʼ��¼
                ADOTable1->First();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NextClick(TObject *Sender)
{
        ADOTable1->Next();
        if(ADOTable1->Eof==true)    //�ж��Ƿ�������¼
                ADOTable1->Last();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ShowAllClick(TObject *Sender)
{
        ADOTable1->Filtered = false;   //�ر�ADOTable�Ĺ������ԣ���ʾȫ��
}
//---------------------------------------------------------------------------

