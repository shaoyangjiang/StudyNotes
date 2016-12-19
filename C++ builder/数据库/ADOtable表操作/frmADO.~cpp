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
        //打开ADOTable1，显示记录
        ADOTable1->Active = true;
        for(int i=0;i<=(ADOTable1->Fields->Count-1);i++)
        {       //为查找功能的CombeBox框添加字段名称
                ComboBox1->Items->Add(ADOTable1->Fields->Fields[i]->FieldName);
        }
        for(int i=0;i<=(ADOTable1->Fields->Count-1);i++)
        {        //为筛选功能的CombeBox框添加字段名称
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
                ShowMessage("学生信息不全，必须输入（工资除外项）");
                return;
        }
        ADOTable1->First();
        while(!ADOTable1->Eof)
        {
                if(ADOTable1->FieldValues["学号"]==ID->Text)
                {       //学号唯一，不能重复添加
                        ShowMessage("该学号已经存在，学号唯一");
                        return;
                }
                else
                        ADOTable1->Next();
        }
        ADOTable1->Insert();   //准备添加
        ADOTable1->FieldValues["学号"]=ID->Text;
        ADOTable1->FieldValues["姓名"]=Name->Text;
        ADOTable1->FieldValues["年龄"]=Age->Text;
        ADOTable1->FieldValues["工资"]=Salary->Text;
        ADOTable1->FieldValues["性别"]=Sex->Text;
        if(MessageDlg("确定是否添加",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
                ADOTable1->Post();  //确定添加
        else
                ADOTable1->Cancel();   //取消添加
        ID->Text="";
        Name->Text="";
        Age->Text="";
        Salary->Text="不详";
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
                ShowMessage("查找成功，已经定位");
        }
        else
        {
                ShowMessage("找不到数据");
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteClick(TObject *Sender)
{
        if(MessageDlg("确定是否删除",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
                ADOTable1->Delete();
}
//---------------------------------------------------------------------------
//筛选按钮的功能只是设置传值变量，然后触法ADOTable1的OnFilterRecord事件
void __fastcall TForm1::FilterClick(TObject *Sender)
{
        ADOTable1->Filtered = false;
        myfield=ComboBox2->Text;    //字段名称
        myval=FilterValue->Text;    //条件值
        ADOTable1->Filtered = true;  //触发OnfilterRecord事件
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
        if(ADOTable1->Bof==true)    //判断是否到了开始记录
                ADOTable1->First();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NextClick(TObject *Sender)
{
        ADOTable1->Next();
        if(ADOTable1->Eof==true)    //判断是否到了最后记录
                ADOTable1->Last();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ShowAllClick(TObject *Sender)
{
        ADOTable1->Filtered = false;   //关闭ADOTable的过滤属性，显示全部
}
//---------------------------------------------------------------------------

