/* ���Դ�����ļ��ѱ�δע���SourceFormatX��ʽ���� */
/* ������벻����Ӵ�����Ϣ������ע������������  */
/* ���������Ϣ�������վ: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmUpDateGroundPropU.h"
#include "fmPPaperU.h"
#include "dmDataU.h"
#include "SysFuncs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmUpDateGroundProp *fmUpDateGroundProp;
//---------------------------------------------------------------------------
__fastcall TfmUpDateGroundProp::TfmUpDateGroundProp(TComponent *Owner): TForm
    (Owner){}
//---------------------------------------------------------------------------
void __fastcall TfmUpDateGroundProp::BitBtn1Click(TObject *Sender)
{
    AnsiString sSql;
    AnsiString sDate;
    TADOQuery *q(dmData->qry);

    try
    {
        StrToFloat(edtUsedAreaM2->Text);
    }
    catch (EConvertError *E)
    {

        ::MessageBox(this->Handle, "�������ֻ��ΪС����������", "����",
            MB_ICONERROR);
        return ;
    }
     try
    {
        StrToFloat(edtUsedArea->Text);
    }
    catch (EConvertError *E)
    {

        ::MessageBox(this->Handle, "�������ֻ��ΪС����������", "����",
            MB_ICONERROR);
        return ;
    }
    if(edtFileNo->Text == "")
    {
        ::MessageBox(this->Handle, "����ʹ�����Ų���Ϊ�գ�", "����",
            MB_ICONERROR);
        return ;
    }

    if (m_bInsertFlag == true)
    {
        if (edtUsedAreaM2->Text == "" || edtUsedArea->Text == "" || edtFileNo
            ->Text == "")
        {
            return ;
        }
        sDate = FormatDateTime("YYYY.MM.DD",dataSendOutDate->DateTime);

        sSql = "insert into P_GroundProperty values(";
        sSql += "'0',"; // Ψһ���ڲ����
        sSql += "'" + fmPPaper->edtPaper_No->Text + "',"; // ����Ȩ֤���
        sSql += "'��֤',"; // ����ʹ��֤��
        sSql += "'" + edtFileNo->Text + "',"; // ����ʹ��֤��
        sSql += "'" + edtUsedAreaM2->Text + "',"; // ʹ�ù������������ƽ���ף�
        sSql += "'" + edtUsedArea->Text + "',"; // ʹ�ù������������Ķ��
        sSql += "'" + sDate + "')";
        ExecuteSql(q, sSql);
    }
    else
    {   sDate = FormatDateTime("YYYY.MM.DD",dataSendOutDate->DateTime);
        sSql = "update P_GroundProperty set ";
        sSql += "File_NO='" + edtFileNo->Text + "',";
        sSql += "UsedAreaM2='" + edtUsedAreaM2->Text + "',";
        sSql += "UsedArea='" + edtUsedArea->Text + "',";
        sSql += "SendDate='" + sDate + "'";
        sSql += " where Paper_NO='" + fmPPaper->edtPaper_No->Text + "'";
        ExecuteSql(q, sSql);

    }
    fmPPaper->edtUsedAreaM2->Text = edtUsedAreaM2->Text;
    fmPPaper->edtUsedArea->Text = edtUsedArea->Text;
    fmPPaper->edtFileNo->Text = edtFileNo->Text;
}

//---------------------------------------------------------------------------
void __fastcall TfmUpDateGroundProp::FormActivate(TObject *Sender)
{


    edtUsedAreaM2->Text = fmPPaper->edtUsedAreaM2->Text;
    edtUsedArea->Text = fmPPaper->edtUsedArea->Text;
    edtFileNo->Text = fmPPaper->edtFileNo->Text;
    dataSendOutDate->DateTime = fmPPaper->dataSendOutDate->DateTime;
    if (edtUsedAreaM2->Text == "" || edtUsedArea->Text == "" || edtFileNo->Text
        == "")
    {
        m_bInsertFlag = true;
    }
    this->panPaperNo->Caption = "��֤�ֵڣ�" + fmPPaper->edtPaper_No->Text +
        "��";


}

//---------------------------------------------------------------------------

