/* ���Դ�����ļ��ѱ�δע���SourceFormatX��ʽ���� */
/* ������벻����Ӵ�����Ϣ������ע������������  */
/* ���������Ϣ�������վ: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmHoursePropU.h"
#include "fmPPaperU.h"
#include "dmDataU.h"
#include "SysFuncs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmHourseProp *fmHourseProp;
//---------------------------------------------------------------------------
__fastcall TfmHourseProp::TfmHourseProp(TComponent *Owner): TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TfmHourseProp::FormCreate(TObject *Sender)
{
    this->panPaperNo->Caption = "��֤�ֵڣ�" + fmPPaper->edtPaper_No->Text +
        "��";
    for (int i = 0; i < fmPPaper->gridPropertyHourse->RowCount; i++)
    {
        for (int j = 0; j < fmPPaper->gridPropertyHourse->RowCount; j++)
        {
            gridPropertyHourse->Cells[j][i] = fmPPaper->gridPropertyHourse
                ->Cells[j][i];
        }
    }

}

//---------------------------------------------------------------------------

void __fastcall TfmHourseProp::BitBtn1Click(TObject *Sender)
{

    int nHourseNum = 0;
    AnsiString sSql;
    TADOQuery *q(dmData->qry);

    if(EnsureHourseFun() == false)
    { 
       return;
    }
    sSql = "delete from P_HouseProperty where Paper_NO ='" + fmPPaper
        ->edtPaper_No->Text + "'";
    ExecuteSql(q, sSql);


    //forѭ���ж��� gridPropertyHourse��һ���ж��ٶ�����
    for (int i = 0; i < gridPropertyHourse->RowCount; i++)
    {
        for (int j = 0; j < gridPropertyHourse->ColCount; j++)
        {
            if (gridPropertyHourse->Cells[j][i] != "")
            {
                nHourseNum++;
                break;
            }
        }
        if (nHourseNum != i + 1)
        {
            break;
        }
    }

    //��ȡ���Ӷ���
    //��ÿһ��������ӵ����ݿ��   P_HouseProperty��״����   ��ȥ
    for (int i = 0; i < nHourseNum; i++)
    {
        sSql = "insert into P_HouseProperty values(";
        sSql += "'0',"; //ID
        sSql += "'" + fmPPaper->edtPaper_No->Text + "',"; //����֤��
        sSql += "'" + gridPropertyHourse->Cells[0][i] + "',"; //����
        sSql += "'" + gridPropertyHourse->Cells[1][i] + "',"; //����
        sSql += gridPropertyHourse->Cells[2][i] + ","; //����
        sSql += "'" + gridPropertyHourse->Cells[3][i] + "',"; //�����ṹ
        sSql += gridPropertyHourse->Cells[4][i] + ","; //����
        sSql += gridPropertyHourse->Cells[5][i] + ","; //�������
        sSql += "'" + gridPropertyHourse->Cells[6][i] + "')"; //��ע
        ExecuteSql(q, sSql);
    }
    //fmPPaper->qryIndex ->Active = false;
    //fmPPaper->qryIndex->Active = true;
    TBookmark mark = fmPPaper->qryIndex->GetBookmark();
    fmPPaper->qryIndex->Last();
    fmPPaper->qryIndex->GotoBookmark(mark);
    fmPPaper->qryIndex->FreeBookmark(mark);

}
bool TfmHourseProp::EnsureHourseFun()
{
    ////////
    int nHourseNum;
   int nRoom;
    int nFloor;
    float fArea;

    int nBuildingNum = 0;

    //forѭ���ж��� gridPropertyHourse��һ���ж��ٶ�����
    for (int i = 0; i < gridPropertyHourse->RowCount; i++)
    {
        for (int j = 0; j < gridPropertyHourse->ColCount; j++)
        {
            if (gridPropertyHourse->Cells[j][i] != "")
            {
                nBuildingNum++;
                break;
            }
        }
        if (nBuildingNum != i + 1)
        {
            break;
        }
    }
    //��ÿһ��������ӵ����ݿ��   P_HouseProperty��״������ȥ
    for (int i = 0; i < nHourseNum; i++)
    {
        try
       {
           nRoom  = StrToInt(gridPropertyHourse->Cells[2][i]);
       }
       catch (EConvertError *E)
       {

            ::MessageBox(this->Handle, "�ڷ���״�����з��ӵļ���ֻ��Ϊ������", "����",
            MB_ICONERROR);
           return false;
       }
        try
       {
            nFloor = StrToInt(gridPropertyHourse->Cells[4][i]);
       }
       catch (EConvertError *E)
       {

            ::MessageBox(this->Handle, "�ڷ���״�����з��ӵĲ���ֻ��Ϊ������", "����",
            MB_ICONERROR);
           return false;
       }
        try
       {
            fArea = StrToFloat(gridPropertyHourse->Cells[5][i]);
       }
       catch (EConvertError *E)
       {

            ::MessageBox(this->Handle, "�ڷ���״�����з��ӵĽ������ֻ��ΪС����������", "����",
            MB_ICONERROR);
           return false;
       }

    }
    return true;

}
//---------------------------------------------------------------------------
