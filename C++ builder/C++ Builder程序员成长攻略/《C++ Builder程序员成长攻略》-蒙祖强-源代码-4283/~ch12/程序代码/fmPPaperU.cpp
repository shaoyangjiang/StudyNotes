//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmPPaperU.h"
#include "dmDataU.h"
#include "SysFuncs.h"
#include "fmUpdateU.h"
#include <string.h>
#include "fmMainU.h"
#include "fmInitFileNoU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "fmVBaseU"
#pragma resource "*.dfm"
TfmPPaper *fmPPaper;
//---------------------------------------------------------------------------
__fastcall TfmPPaper::TfmPPaper(TComponent *Owner): TfmVBase(Owner){}
//---------------------------------------------------------------------------
void __fastcall TfmPPaper::FormActivate(TObject *Sender)
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);

    TADOQuery *qryPropertry(dmData->qry);
    FillCB(cmbTaxType, qryPropertry, "A_TaxType", "TaxType", "");
        //���   ��˰����   ��Ͽ�
   
    FillCB(cmbTaxRace, qryPropertry, "A_TaxRace", "TaxRace", "");
        //���   ��˰˰�� ��Ͽ�
    FillCB(cmbMaker, qryPropertry, "A_Marker", "Marker");

    FillCB(cmbChecker, qryPropertry, "A_Checker", "Checker");

    FillCB(cmbManageUnit, qryPropertry, "A_ManageUnit", "ManageUnit");
    
    ToolButton6->Enabled = false; //�ύ��ť
    qryIndex->Active = true;
    qryMain->Active = true;
    qryPicture->Open();
    tableOwner->Active = true;
    ControlReadOnlyFun();

    if(qryIndex->RecordCount == 0)
     {

           ToolButton2->Enabled = false;
           ToolButton3->Enabled = false;
           ToolButton4->Enabled = false;
           ToolButton5->Enabled = false;
           ToolButton6->Enabled = false;
           ToolButton7->Enabled = false;
     }
     
    sSql = "select * from InitFileNo";
    ResultSql(q, sSql);
    if (q->RecordCount > 0)
    {
        return ;
    }
    Application->CreateForm(__classid(TfmInitFileNo), &fmInitFileNo);
    fmInitFileNo->ShowModal();
}

//---------------------------------------------------------------------------
//ִ����Ӱ�ť����
void __fastcall TfmPPaper::actAddExecute(TObject *Sender)
{
    AnsiString sSql;
    AnsiString sPaper_NO;
    TADOQuery *q(dmData->qry);
    ClearFormFun();
    //����һ������֤��  ����֤�ĳ���Ϊ10
    sPaper_NO = CreatePaper_NOFun(q);
    g_sPaper_No = sPaper_NO;
    edtPaper_No->Text = sPaper_NO;

    SetButtonFun();
    ToolButton6->Enabled = true; //�ύ��ť
    ToolButton7->Enabled = true; //�ύ��ť

    ToolButton1->Enabled=false;
    ToolButton2->Enabled=false;
    ToolButton3->Enabled=false;
    ToolButton4->Enabled=false;
    ControlWriteFun();

    cmbTaxRace->Text = cmbTaxRace->Items->Strings[0];
    cmbTaxType->Text = cmbTaxType->Items->Strings[0];
    cmbMaker->Text = cmbMaker->Items->Strings[0];
    cmbChecker->Text = cmbChecker->Items->Strings[0];
    cmbManageUnit->Text = cmbManageUnit->Items->Strings[0];

    dimgPicture1->Picture->Bitmap= NULL;
    dimgPicture2->Picture->Bitmap= NULL;
   //edtOwner->SetFocus();
}

//---------------------------------------------------------------------------
//ִ���ύ��ť����
void __fastcall TfmPPaper::actPostExecute(TObject *Sender)
{
    int nOwnerID; //����Ȩ��ID
    int nPropertyRightID; //����Ȩ����ID
    int nTaxTypeID; // ��˰����ID
    int nTaxRaceID; //��˰˰��ID
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    //�����Ϣ�Ƿ�����ӵ����ݿ���ȥ
    if (EnsureDatAvalidFun() == false)
    {
        return ;
    }
    if(EnsureHourseInfoFun() == false)
    {
        return;
    }
    if(EnsureTaxInfoFun() == false)
    {
      return;
    }
    if(EnsureGroundInfoFun() == false)
    {
     return;
    }
    //�Ѳ�Ȩ����Ϣ���뵽��Ȩ�˱�  p_Owner  ��ȥ
    tableOwner->Active = false;

    InsertOwnerFun(q,edtOwner->Text, 1);

    //�ѷ���״����ӵ�����״������ȥ
    InsertHoursePropertyFun();
    //����˰ժҪ��Ϣ���뵽 ��˰ժҪ�� P_Contract_Tax  ��ȥ
    InsertContract_TaxFun();

     //�ѹ���������Ϣ���뵽��������ʹ�ñ�  GroundProperty ��ȥ
    InsertGroundPropertyFun();

    //�ѷ�������Ȩ֤��Ϣ���뵽��������Ȩ֤��  Property_Paper  �С�
    InsertPropertyPaperFun();
    sSql = "update InitFileNo set FileNoStart='" + g_sPaper_No +"'";
    ExecuteSql(q, sSql);

    ToolButton6->Enabled = false; //�ύ��ť
    ControlReadOnlyFun();
    qryIndex->Close();
    qryIndex->Open();
    tableOwner->Active = true;

    EnableButtonFun();



}

//--------------------------------------------------------------------------
/*�Զ��庯��*/
/*��������: �ѹ���Ȩ�������ַ�����ֳ������б�*/
/*����˵����
AnsiString sOwnerNames��������Ȩ�˵������ַ���
 */
TStringList *__fastcall TfmPPaper::GetOwnerNames(AnsiString sOwnerNames)
{
    int nNamesLength;
    int nPos;
    AnsiString sName;
    TStringList *SListNameList = new TStringList();

    while (sOwnerNames.Length() > 0)
    {
        sOwnerNames = sOwnerNames.TrimLeft();
        sOwnerNames = sOwnerNames.TrimRight();
        nPos = sOwnerNames.Pos(" ");
        if (nPos == 0)
        {
            SListNameList->Add(sOwnerNames);
            break;
        }
        sName = sOwnerNames.SubString(1, nPos);
        sName = sName.Trim();
        SListNameList->Add(sName);
        sOwnerNames = sOwnerNames.SubString(nPos, sOwnerNames.Length());
    }
    return SListNameList;


}

//---------------------------------------------------------------------------
/*�Զ��庯��
��������: ������Ȩ�ˡ�����Ȩ����Ϣ���뵽��Ȩ�˱�P_Owner��ȥ
����˵����
AnsiString sOwnerName ---����Ȩ�˵�����
int nPropertyFlag     ---����Ȩ�˵�����
nPropertyFlag=1;��������Ȩ��
nPropertyFlag=2��������Ȩ��
����ֵ˵����
��������Ȩ�˻���Ȩ�˵�ID
 */


/*
�Զ��庯��
�������ܣ��ѷ���״����ӵ�����״������ȥ
�ж���gridPropertyHourse�ؼ��еķ���״��������������е�����Ϊ�գ�����Ϊ�����ڸ÷���---gridPropertyHourse�ؼ�

 */
void __fastcall TfmPPaper::InsertHoursePropertyFun()

{
    int nHourseNum = 0;
    AnsiString sSql;
    TADOQuery *q(dmData->qry);

    //��ȡ���Ӷ���
    nHourseNum = getBuildingNumFun();


    //��ÿһ��������ӵ����ݿ��   P_HouseProperty��״������ȥ
    for (int i = 0; i < nHourseNum; i++)
    {
        sSql = "insert into P_HouseProperty values(";
        sSql += "'0',"; //ID
        sSql += "'" + edtPaper_No->Text + "',"; //����֤��
        sSql += "'" + gridPropertyHourse->Cells[0][i] + "',"; //����
        sSql += "'" + gridPropertyHourse->Cells[1][i] + "',"; //����
        sSql += gridPropertyHourse->Cells[2][i] + ","; //����
        sSql += "'" + gridPropertyHourse->Cells[3][i] + "',"; //�����ṹ
        sSql += gridPropertyHourse->Cells[4][i] + ","; //����
        sSql += gridPropertyHourse->Cells[5][i] + ","; //�������
        sSql += "'" + gridPropertyHourse->Cells[6][i] + "')"; //��ע
        ExecuteSql(q, sSql);
    }
}

//---------------------------------------------------------------------------
/*
�Զ��庯��
�������ܣ��ѹ���Ȩ֤��Ϣ��ӵ�    ShareProperty_Paper����Ȩ֤��     ��ȥ
 */
void __fastcall TfmPPaper::InsertSharePropertyFun()
{
    int nOwnerNum = 0;
    AnsiString sSql;
    TStringList *SListIDList = new TStringList();
    TStringList *SListShareList = new TStringList();
    int nBuildingNum;
    int nHourseNum;
    float fHourseArea;
    int nMarkerID;
    int nCheckerID;
    int nManageUnitID;
    AnsiString sDate;

    TADOQuery *q(dmData->qry);
    //��鹲��Ȩ������
    for (int i = 0; i < gridOwnerList->RowCount; i++)
    {
        if (gridOwnerList->Cells[0][i] != "")
        {
            nOwnerNum++;
        }
        else
        {
            break;
        }
    }

    //�ѹ���Ȩ����ӵ�����ȨȨ�˱���ȥ��
    //ͬʱ���ع���Ȩ��ID��Ϊһ��ID�б����SListIDList��
    for (int i = 0; i < nOwnerNum; i++)
    {
        int nID = 0;
        nID = InsertOwnerFun(q,gridOwnerList->Cells[0][i], 2);
            //���빲������Ϣ���뵽��Ȩ�˱�  p_Owner  ��ȥ

        SListIDList->Add(IntToStr(nID));
        edtOwnerList->Text = edtOwnerList->Text + gridOwnerList->Cells[0][i] +
            "   ";

    }




    //��ȡ��֤�� ID
    nMarkerID = GetID(q, "A_Marker", "RID", "Marker", cmbMaker->Text);
    //��ȡУ����ID
    nCheckerID = GetID(q, "A_Checker", "RID", "Checker", cmbMaker->Text);
    //��ȡ�����ID
    nManageUnitID = GetID(q, "A_ManageUnit", "RID", "ManageUnit", cmbManageUnit
        ->Text);
    //��ȡ����
    nBuildingNum = getBuildingNumFun();
    //��ȡ����
    nHourseNum = getHourseNumFun();
    //��ȡ�������
    fHourseArea = getHourseAreaFun();
    //��ȡ����
    sDate = FormatDateTime("YYYY.MM.DD", dataSendOutDate->Date);
    //��ÿһ������Ȩ֤��Ϣ���浽ShareProperty_Paper ����Ȩ֤��
    for (int i = 0; i < nOwnerNum; i++)
    {
        //��������Ȩ֤�� ,�ѹ���Ȩ֤���б����SListShareList��
        AnsiString sShare_ID;
        sShare_ID = CreateShareProperty_NOFun(q);

        SListShareList->Add(sShare_ID);
        sSql = "insert into ShareProperty_Paper values(";
        sSql += "'0',"; //ID
        sSql += "'" + edtPaper_No->Text + "',"; //����Ȩ֤���
        sSql += "'" + SListShareList->Strings[i] + "',"; //����Ȩ֤��
        sSql += "'" + SListIDList->Strings[i] + "',"; // �����˱��
        sSql += gridOwnerList->Cells[1][i] + ","; //���зݶ�
        sSql += IntToStr(nBuildingNum) + ","; //����
        sSql += IntToStr(nHourseNum) + ","; //����
        sSql += FloatToStr(fHourseArea) + ","; //�������
        sSql += IntToStr(nMarkerID) + ","; //��֤��
        sSql += IntToStr(nCheckerID) + ","; //У����
        sSql += IntToStr(nManageUnitID) + ","; //�����
        sSql +=  + "'" + sDate + "',"; //�����
        sSql +=  + "'" + sDate + "',"; //��֤����
        sSql +=  + "'" + gridOwnerList->Cells[3][i] + "')"; //��ע

        ExecuteSql(q, sSql);
    }

}

//---------------------------------------------------------------------------

/*
�Զ��庯����
����˵����
����˰ժҪ��Ϣ���뵽 ��˰ժҪ�� P_Contract_Tax  ��ȥ
 */
void __fastcall TfmPPaper::InsertContract_TaxFun()
{
    int nTaxType_ID = 0;
    int nTaxRace_ID = 0;
    int nRNO;
    AnsiString sSql;
    AnsiString sDate;
    TADOQuery *q(dmData->qry);
    if ((EdtPrice->Text == "") || (cmbTaxType->Text == "") || (cmbTaxRace->Text
        == "") || (edtTax->Text == ""))
    {
        return ;
    }
    //��ȡ��˰����ID
    nTaxType_ID = GetID(q, "A_TaxType", "RID", "TaxType", cmbTaxType->Text);

    //��ȡ��˰˰��ID
    nTaxRace_ID = GetID(q, "A_TaxRace", "RID", "TaxRace", cmbTaxRace->Text);

    //��ȡ����
    sDate = FormatDateTime("YYYY.MM.DD", dataStartData->Date);
    sSql = "insert into P_Contract_Tax values(";
    sSql += "'0',"; //Ψһ���ڲ����
    sSql += "'" + edtPaper_No->Text + "',"; //����Ȩ֤���
    sSql += "'" + sDate + "',"; //��������
    sSql += EdtPrice->Text + ","; //����
    sSql += IntToStr(nTaxType_ID) + ","; //�������˰����
    sSql += IntToStr(nTaxRace_ID) + ","; //�������˰˰��
    sSql += edtTax->Text + ","; //���
    sSql += "'" + edtNote->Text + "')"; //��ע

    ExecuteSql(q, sSql);

}

//---------------------------------------------------------------------------

/*
�Զ��庯��
����˵����
������Ȩ����Ϣ���뵽 P_OtherProperty ����Ȩ��ժҪ��
 */
void __fastcall TfmPPaper::InsertOtherPropertyFun()
{
    int nOtherPropertyNum = 0;
    AnsiString sSql;
    AnsiString sDate;
    TADOQuery *q(dmData->qry);

    //�������Ȩ����������
    for (int i = 0; i < gridOtherProperty->RowCount; i++)
    {
        if (gridOtherProperty->Cells[0][i] != "")
        {
            nOtherPropertyNum++;
        }
        else
        {
            break;
        }
    }

    //������Ȩ����Ϣ���뵽 P_OtherProperty ����Ȩ��ժҪ��
    for (int i = 0; i < nOtherPropertyNum; i++)
    {
        sDate = FormatDateTime("YYYY.MM.DD", StrToDateTime(gridOtherProperty
            ->Cells[7][i]));
        sSql = "insert into P_OtherProperty values(";
        sSql += "'0',"; //Ψһ���ڲ����
        sSql += "'" + edtPaper_No->Text + "',"; //����Ȩ֤���
        sSql += "'" + gridOtherProperty->Cells[1][i] + "',"; //Ȩ������
        sSql += "'" + gridOtherProperty->Cells[0][i] + "',"; //Ȩ����
        sSql += "'0',"; //���ݱ��
        sSql += "'" + gridOtherProperty->Cells[2][i] + "',"; //����
        sSql += "'" + gridOtherProperty->Cells[3][i] + "',"; //����
        sSql += "'" + gridOtherProperty->Cells[4][i] + "',";
        ; //�������
        sSql += gridOtherProperty->Cells[5][i] + ",";
        ; //Ȩ����ֵ
        sSql += "'" + gridOtherProperty->Cells[6][i] + "',";
        ; //��������
        sSql += "'" + sDate + "')";
        ; //ע������

        ExecuteSql(q, sSql);

    }

}

//-------------------------------------------------------------------------
/*
�Զ��庯��
����˵����
//�ѹ���������Ϣ���뵽��������ʹ�ñ�  GroundProperty ��ȥ
 */
void __fastcall TfmPPaper::InsertGroundPropertyFun()
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    AnsiString sDate;
    sDate = FormatDateTime("YYYY-MM-DD", dataSendOutDate->DateTime);
    if (edtUsedAreaM2->Text == "" || edtUsedArea->Text == "" || edtFileNo->Text
        == "")
    {
        return ;
    }
    sSql = "insert into P_GroundProperty values(";
    sSql += "'0',"; // Ψһ���ڲ����
    sSql += "'" + edtPaper_No->Text + "',"; // ����Ȩ֤���
    sSql += "'��֤',"; // ����ʹ��֤��
    sSql += "'" + edtFileNo->Text + "',"; // ����ʹ��֤��
    sSql += "'" + edtUsedAreaM2->Text + "',"; // ʹ�ù������������ƽ���ף�
    sSql += "'" + edtUsedArea->Text + "',"; // ʹ�ù������������Ķ��
    sSql += "'" + sDate + "')";
   
    ExecuteSql(q, sSql);



}

//-------------------------------------------------------------------------
/*
�Զ��庯��
����˵����
//�ѹ���������Ϣ���뵽��������ʹ�ñ�  GroundProperty ��ȥ
 */
void __fastcall TfmPPaper::InsertPropertyPaperFun()
{
    int nOwnerID; //����Ȩ��ID
    int nPropertyRightID;
    int nManageUnitID;
    int nMarkerID;
    int nCheckerID;
    AnsiString sSql;
    AnsiString sDate;
    TADOQuery *q(dmData->qry);

    //��ȡ����Ȩ����
    sSql =
        "select K_PropertyRight_ID from A_PropertyRight where PropertyRight='"
        + edtPropertyRight->Text + "'";
    ResultSql(q, sSql);
    if (q->RecordCount > 0)
    {
        nPropertyRightID = q->FieldByName("K_PropertyRight_ID")->AsInteger;
    }
    //��ȡ�����ID
    nManageUnitID = GetID(q, "A_ManageUnit", "RID", "ManageUnit", cmbManageUnit
        ->Text);

    //��ȡ��֤�� ID
    nMarkerID = GetID(q, "A_Marker", "RID", "Marker", cmbMaker->Text);
    //��ȡУ����ID
    nCheckerID = GetID(q, "A_Checker", "RID", "Checker", cmbChecker->Text);
    //��ȡ����
    sDate = FormatDateTime("YYYY.MM.DD", Now());
    nOwnerID = GetMaxRecId(q, "P_Owner", "RNO", "0") + 1; //����һ����Ȩ��ID
    InsertOwnerFun(q,edtOwner->Text, 1);
    sSql = "insert into Property_Paper values(";
    sSql += "'0',";
    sSql += "'��֤',";

    sSql += "'" + edtPaper_No->Text + "',"; // ����֤��;

    sSql += "'0',"; // ������������
    sSql += "'" + IntToStr(nOwnerID) + "',"; // ����Ȩ�˱��
    sSql += "'" + edtOwnerList->Text + "',"; //������
    sSql += "'" + edtPosition->Text + "',"; //��������;
    sSql += "'" + edtGround_No->Text + "',"; //�غ�
    sSql += IntToStr(nPropertyRightID) + ","; // ����Ȩ����
    sSql += "'0',"; // ״̬
    sSql += IntToStr(nManageUnitID) + ","; // �����
    sSql += IntToStr(nMarkerID) + ","; //��֤��
    sSql += IntToStr(nCheckerID) + ","; //У����
    sSql +=  + "'" + sDate + "',"; //�����
    sSql +=  + "'" + sDate + "',"; //��֤����
    sSql +=  + "'" + memRemark->Text + "')"; //����

    ExecuteSql(q, sSql);
}

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

/*
�Զ��庯��
����˵����������ȡ���Ӷ���
����ֵ˵��:���ط��Ӷ���
 */
int __fastcall TfmPPaper::getBuildingNumFun()
{
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
    return nBuildingNum;
}

//---------------------------------------------------------------------------
/*
�Զ��庯��
����˵����������ȡ���Ӽ���
����ֵ˵��:���ط��Ӽ���
 */
int __fastcall TfmPPaper::getHourseNumFun()
{
    int nHourseNum = 0;
    int nBuildingNum = 0;
    //��ȡ���Ӷ���
    nBuildingNum = getBuildingNumFun();
    //���㷿�ӵ��ܼ���

    for (int i = 0; i < nBuildingNum; i++)
    {
        nHourseNum += StrToInt(gridPropertyHourse->Cells[1][i]);

    }
    return nHourseNum;
}

/*
�Զ��庯��
����˵����������ȡ���������
����ֵ˵��:���ط��������
 */
//----------------------------------------------------------------------
float __fastcall TfmPPaper::getHourseAreaFun()
{
    float fHourseArea = 0.0;
    int nBuildingNum = 0;
    //��ȡ���Ӷ���
    nBuildingNum = getBuildingNumFun();
    //���㷿�ӵ��ܼ���
    for (int i = 0; i < nBuildingNum; i++)
    {

        fHourseArea += StrToFloat(gridPropertyHourse->Cells[5][i]);
    }
    return fHourseArea;
}

//---------------------------------------------------------------------------

void __fastcall TfmPPaper::actCancleExecute(TObject *Sender)
{
    if(ToolButton1->Enabled == false)
    {   ToolButton6->Enabled = false; //�ύ��ť
       ClearFormFun();
       ControlReadOnlyFun();
       EnableButtonFun();
    }
}

//---------------------------------------------------------------------------

/*
/*
�Զ��庯��
����˵������ʾ����Ȩ֤*/
//---------------------------------------------------------------------------
void __fastcall TfmPPaper::ShowProperty_PaperFun()
{
    int nOwnerName;
    int nPropertyRight;
    int nManageUnit;
    int nMarker;
    int nChecker;
    AnsiString sOwnerId;
    AnsiString sOwnerName;
    AnsiString sPropertyRight;
    AnsiString sManageUnit;
    AnsiString sMarker;
    AnsiString sChecker;
    TADOQuery *q(dmData->qry);

    //�������Ȩ������
    sOwnerId = (qryIndex->FieldByName("K_Owner_NO")->AsString); //���ID
    m_sOwnerID = sOwnerId;
    sOwnerName = GetNameFieldFromIDFieldS(q, "P_Owner", "OwnerName", "RNO",
        sOwnerId);

    //�������Ȩ����
    nPropertyRight = qryIndex->FieldByName("K_PropertyRight_ID")->AsInteger;
    sPropertyRight = GetNameFieldFromIDFieldN(q, "A_PropertyRight",
        "PropertyRight", "K_PropertyRight_ID", nPropertyRight);

    //��ȡ�����
    nManageUnit = qryIndex->FieldByName("K_ManageUnit_ID")->AsInteger;

    sManageUnit = GetNameFieldFromIDFieldN(q, "A_ManageUnit", "ManageUnit",
        "RID", nManageUnit);

    //��ȡ��֤��
    nMarker = qryIndex->FieldByName("K_Maker_ID")->AsInteger;

    sMarker = GetNameFieldFromIDFieldN(q, "A_Marker", "Marker", "RID", nMarker);
    //��ȡУ����
    nChecker = qryIndex->FieldByName("K_Checker_ID")->AsInteger;

    sChecker = GetNameFieldFromIDFieldN(q, " A_Checker", "Checker", "RID",
        nChecker);

    //��ʾ����Ȩ������
    edtOwner->Text = sOwnerName;
    edtPaper_No->Text = qryIndex->FieldByName("Paper_NO")->AsString;
    //��ʾ����Ȩ����

    edtPropertyRight->Text = sPropertyRight;

    edtOwnerList->Text = qryIndex->FieldByName("OwnerList")->AsString;
    edtPosition->Text = qryIndex->FieldByName("House_Position")->AsString;
    edtGround_No->Text = qryIndex->FieldByName("Ground_NO")->AsString;
    memRemark->Text = qryIndex->FieldByName("Remark")->AsString;
    cmbMaker->Text = sMarker;
    cmbChecker->Text = sChecker; //SendOutDate
    cmbManageUnit->Text = sManageUnit;
}

/*
�Զ��庯��
����˵������ʾ��˰ժҪ
 */
void __fastcall TfmPPaper::ShowP_Contract_TaxFun()
{
    int nTaxType;
    int nTaxRace;
    AnsiString sTaxType;
    AnsiString sTaxRace;
    AnsiString sSql;
    TADOQuery *q(dmData->qry);


    sSql = "select * from P_Contract_Tax where Paper_NO='" + edtPaper_No->Text
        + "'";
    ResultSql(q, sSql);
    if (!q->IsEmpty())
    {
        //��ȡ��˰����ID
        nTaxType = q->FieldByName("K_TaxType_ID")->AsInteger;
        //��ȡ��˰˰��ID
        nTaxRace = q->FieldByName("K_TaxRace_ID")->AsInteger;
        EdtPrice->Text = q->FieldByName("Price")->AsFloat;
        edtTax->Text = q->FieldByName("Tax")->AsFloat;
        edtNote->Text = q->FieldByName("Note")->AsString;
        //��ȡ��˰����
        sTaxType = GetNameFieldFromIDFieldN(q, "A_TaxType", "TaxType", "RID",
            nTaxType);
        //��ȡ��˰˰��
        sTaxRace = GetNameFieldFromIDFieldN(q, "A_TaxRace", "TaxRace", "RID",
            nTaxRace);
        cmbTaxType->Text = sTaxType;
        cmbTaxRace->Text = sTaxRace;
    }
}

//---------------------------------------------------------------------
/*
�Զ��庯��:
����˵��:
//��ʾ����Ȩ֤
 */
TStringList *__fastcall TfmPPaper::ShowShareProperty_PaperFun()
{
    int nOwnerName;
    AnsiString sOwnerName;
    AnsiString sSql;
    TStringList *sListOwnerNameId = new TStringList();
    TStringList *sListOwnerName = new TStringList();
    TADOQuery *q(dmData->qry);
    sSql = "select * from ShareProperty_Paper where K_Paper_NO='" + edtPaper_No
        ->Text + "'";
    sSql =sSql + " and RNO ='0'";
    ResultSql(q, sSql);
    gridOwnerList->RowCount = 5;
    if(q->RecordCount >5)
    {
        gridOwnerList->RowCount = q->RecordCount;
    }

    for (int i = 0; i < gridOwnerList->RowCount; i++)
    {
        for (int j = 0; j < gridOwnerList->ColCount; j++)
        {
            gridOwnerList->Cells[j][i] = "";
        }

    }
    q->First();
    for (int i = 0; i < q->RecordCount; i++)
    {
        //��ȡ�����˱��
        nOwnerName = StrToInt((q->FieldByName("K_Owner_NO")->AsString));
        sListOwnerNameId->Add(IntToStr(nOwnerName));
        gridOwnerList->Cells[1][i] = FloatToStr(q->FieldByName("Share")
            ->AsFloat);
        gridOwnerList->Cells[2][i] = q->FieldByName("ShareProperty_Paper_NO")
            ->AsString;
        gridOwnerList->Cells[3][i] = q->FieldByName("Remark")->AsString;
        q->Next();
    }
    for (int i = 0; i < sListOwnerNameId->Count; i++)
    {
        nOwnerName = StrToInt(sListOwnerNameId->Strings[i]);
        sOwnerName = GetNameFieldFromIDFieldN(q, "P_Owner", "OwnerName", "RNO",
            nOwnerName);
        gridOwnerList->Cells[0][i] = sOwnerName;
        sListOwnerName->Add(sOwnerName);
    }
    return sListOwnerName;
}

/*
�Զ��庯��:
����˵��:
//��ʾ����Ȩ��ժҪ
 */
/*void __fastcall TfmPPaper::ShowP_OtherPropertyFun()
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    sSql = "select * from P_OtherProperty where Paper_NO='" + edtPaper_No->Text
        + "'";
    ResultSql(q, sSql);
    //�������Ȩ��ժҪStringGrid�ؼ�
    for (int i = 0; i < gridOtherProperty->RowCount; i++)
    {
        for (int j = 0; j < gridOtherProperty->ColCount; j++)
        {
            gridOtherProperty->Cells[j][i] = "";
        }
    }
    q->First();
    for (int i = 0; i < q->RecordCount; i++)
    {
        gridOtherProperty->Cells[0][i] = q->FieldByName("Obligee")->AsString;
            //Ȩ����
        gridOtherProperty->Cells[1][i] = q->FieldByName("PropertyType")
            ->AsString; //Ȩ������
        gridOtherProperty->Cells[2][i] = q->FieldByName("K_House_NO")
            ->AsString; //����
        gridOtherProperty->Cells[3][i] = q->FieldByName("Room")->AsInteger;
            //����
        gridOtherProperty->Cells[4][i] = q->FieldByName("Structure_Area")
            ->AsFloat; //�������
        gridOtherProperty->Cells[5][i] = q->FieldByName("Pro_Value")->AsFloat;
            //Ȩ����ֵ
        gridOtherProperty->Cells[6][i] = DateToStr(q->FieldByName("Available")
            ->AsDateTime); //��������
        gridOtherProperty->Cells[7][i] = DateToStr(q->FieldByName("CheckOff")
            ->AsDateTime); //ע������
        q->Next();
    }
}
  */
//------------------------------------------------------------------------
/*
�Զ��庯��:
����˵��:
//��ʾ����״��
 */
void __fastcall TfmPPaper::ShowP_PropertyHouseFun()
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    sSql = "select * from P_HouseProperty where Paper_NO='" + edtPaper_No->Text
        + "'";
    ResultSql(q, sSql);
    //��շ���״��StringGrid�ؼ�
    for (int i = 0; i < gridPropertyHourse->RowCount; i++)
    {
        for (int j = 0; j < gridPropertyHourse->ColCount; j++)
        {
            gridPropertyHourse->Cells[j][i] = "";
        }
    }
    q->First();
    m_nHourseNum = q->RecordCount;
    for (int i = 0; i < q->RecordCount; i++)
    {
        gridPropertyHourse->Cells[0][i] = q->FieldByName("Building_NO")
            ->AsString; //����
        gridPropertyHourse->Cells[1][i] = q->FieldByName("Doorplate_NO")
            ->AsString; //����
        gridPropertyHourse->Cells[2][i] = q->FieldByName("Room")->AsInteger;
            //����
        gridPropertyHourse->Cells[3][i] = q->FieldByName("Structure")
            ->AsString; //�ṹ
        gridPropertyHourse->Cells[4][i] = q->FieldByName("Floor")->AsInteger;
            //����
        gridPropertyHourse->Cells[5][i] = q->FieldByName("Structure_Area")
            ->AsFloat; //�ṹ���
        gridPropertyHourse->Cells[6][i] = q->FieldByName("Note")->AsString;
            //��ע
        q->Next();
    }
}

/*
�Զ��庯��:
����˵��:
��ȡ�������
 */
void __fastcall TfmPPaper::ShowGroundPropertyFun()
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    sSql = "select * from P_GroundProperty where Paper_NO='" + edtPaper_No
        ->Text + "'";
    ResultSql(q, sSql);
    if (!q->IsEmpty())
    {
        edtFile->Text = q->FieldByName("File_NO_Head")->AsString; //������
        edtFileNo->Text = q->FieldByName("File_NO")->AsString; //���غ�
        edtUsedAreaM2->Text = q->FieldByName("UsedAreaM2")->AsFloat; //�������
        edtUsedArea->Text = q->FieldByName("UsedArea")->AsFloat; //����Ķ
        
        dataSendOutDate->DateTime = q->FieldByName("SendDate")->AsDateTime;
    }
}

//-------------------------------------------------------------------------
void __fastcall TfmPPaper::qryIndexAfterScroll(TDataSet *DataSet)
{
    ClearFormFun();
    //��ʾ����Ȩ
    ShowProperty_PaperFun();

    //��ʾ����״��
    ShowP_PropertyHouseFun();
    //��ʾ����Ȩ��ժҪ
    ShowP_OtherPropertyFun();
    //��ʾ��˰ժҪ
    ShowP_Contract_TaxFun();
    //��ʾ����Ȩ��ժҪ
    ShowShareProperty_PaperFun();
    //��ʾ������Ϣ
    ShowGroundPropertyFun();

    if (DataSet->FieldByName("Paper_NO")->AsString != "")
    {
        qryPicture->Close();
        qryPicture->SQL->Text =
            "select top 1 * from P_HousePicture where Paper_NO='" + DataSet
            ->FieldByName("Paper_NO")->AsString + "'";
        qryPicture->Open();
        
    }

  
    if(qryIndex->RecordCount >0)
    {
           ToolButton1->Enabled = true;
           ToolButton2->Enabled = true;
           ToolButton3->Enabled = true;
           ToolButton4->Enabled = true;
           //ToolButton6->Enabled = false;
           //ToolButton7->Enabled = true;
    }
}

//---------------------------------------------------------------------------

void __fastcall TfmPPaper::actEditExecute(TObject *Sender)
{
    Application->CreateForm(__classid(TfmUpdate), &fmUpdate);
    fmUpdate->ShowModal();
}

//---------------------------------------------------------------------------

void __fastcall TfmPPaper::actDeleteExecute(TObject *Sender)
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    sSql = "update Property_Paper  set FNO ='1' where Paper_NO='" + edtPaper_No
        ->Text + "'";
    ExecuteSql(q, sSql);
    sSql = "select * from Property_Paper where FNO ='0'";
    ExecuteSql(qryIndex, sSql);
    qryIndex->Active = true;
    if(qryIndex->RecordCount ==0)
    {
           ToolButton1->Enabled = true;
           ToolButton2->Enabled = false;
           ToolButton3->Enabled = false;
           ToolButton4->Enabled = false;
           ToolButton6->Enabled = false;
           ToolButton7->Enabled = false;
    }
}

//---------------------------------------------------------------------------
void __fastcall TfmPPaper::edtLocateKeyPress(TObject *Sender, char &Key)
{
    TLocateOptions Opts;
    Opts.Clear();
    Opts << loPartialKey;
    if (Key == 13)
    {
        bool a = qryIndex->Locate("Paper_NO", edtLocate->Text, Opts);

    }
}

//---------------------------------------------------------------------------


void __fastcall TfmPPaper::cmbMakerKeyPress(TObject *Sender, char &Key)
{
    Key = 0;
}

//---------------------------------------------------------------------------

void __fastcall TfmPPaper::cmbCheckerKeyPress(TObject *Sender, char &Key)
{
    Key = 0;
}

//---------------------------------------------------------------------------

void __fastcall TfmPPaper::cmbPropertyRightKeyPress(TObject *Sender, char &Key)
{
    // Key = 0;
}

//---------------------------------------------------------------------------

void __fastcall TfmPPaper::cmbPropertyRightChange(TObject *Sender)
{
    //  cmbPropertyRight->Text = "������";
}

//---------------------------------------------------------------------------

void __fastcall TfmPPaper::cmbTaxTypeKeyPress(TObject *Sender, char &Key)
{
    Key = 0;
}

//---------------------------------------------------------------------------

void __fastcall TfmPPaper::cmbTaxRaceKeyPress(TObject *Sender, char &Key)
{
    Key = 0;
}

//---------------------------------------------------------------------------

void __fastcall TfmPPaper::cmbManageUnitKeyPress(TObject *Sender, char &Key)
{
    Key = 0;
}

//---------------------------------------------------------------------------

void __fastcall TfmPPaper::edtFileKeyPress(TObject *Sender, char &Key)
{
    Key = 0;
}

//---------------------------------------------------------------------------
/*
�Զ��庯��
����˵����
�����ж����ύ��֮ǰ������ݵ���Ч��
 */

bool __fastcall TfmPPaper::EnsureDatAvalidFun()
{
    if (edtOwner->Text == "")
    {
        ::MessageBox(this->Handle, "����Ȩ����������Ϊ�գ�", "����",
            MB_ICONERROR);
        return false;
    }
    if (cmbMaker->Text == "")
    {
        ::MessageBox(this->Handle, "��֤����������Ϊ�գ�", "����", MB_ICONERROR)
            ;
        return false;
    }
    if (cmbChecker->Text == "")
    {
        ::MessageBox(this->Handle, "У������������Ϊ�գ�", "����", MB_ICONERROR)
            ;
        return false;
    }
    if (cmbManageUnit->Text == "")
    {
        ::MessageBox(this->Handle, "����ز���Ϊ�գ�", "����", MB_ICONERROR);
        return false;
    }
}

void __fastcall TfmPPaper::ControlReadOnlyFun()
{
    edtPaper_No->ReadOnly = true;
    edtPaper_No->Color = clBtnFace;
    edtOwner->ReadOnly = true; //����Ȩ��
    edtOwner->Color = clBtnFace;
    edtPropertyRight->ReadOnly = true;
    edtPropertyRight->Color = clBtnFace; //����Ȩ����
    edtOwnerList->ReadOnly = true; //������
    edtOwnerList->Color = clBtnFace;
    edtPosition->ReadOnly = true; //��������
    edtPosition->Color = clBtnFace;
    edtGround_No->ReadOnly = true; //�غ�
    edtGround_No->Color = clBtnFace;
    //����״��
    gridPropertyHourse->Options >> goEditing;
    gridPropertyHourse->Color = clBtnFace;
    memRemark->ReadOnly = true;
    memRemark->Color = clBtnFace; //����
    cmbMaker->Color = clBtnFace;
    cmbChecker->Color = clBtnFace; //У �� ��

     /*----------------------------*/ //����Ȩ���б�
   // gridOwnerList->Options >> goEditing;
    gridOwnerList->Color = clBtnFace;

    EdtPrice->ReadOnly = true; //����
    EdtPrice->Color = clBtnFace;
    //��������
    cmbTaxRace->Color = clBtnFace; //��˰˰��
    edtTax->Color = clBtnFace;
    edtTax->ReadOnly = true; //��˰���
    edtNote->Color = clBtnFace; //�� ע
    //����Ȩ��ժҪ
    //gridOtherProperty->Options >> goEditing;
    gridOtherProperty->Color = clBtnFace;
    edtUsedAreaM2->ReadOnly = true; //ʹ���������
    edtUsedAreaM2->Color = clBtnFace;
    edtUsedArea->ReadOnly = true; //ƽ���׺�  Ķ

    edtUsedArea->Color = clBtnFace;
    // edtFile->Text = "";       //����ʹ��֤�ֺ�
    edtFileNo->ReadOnly = true;
    edtFileNo->Color = clBtnFace;
    cmbManageUnit->Color = clBtnFace;

    cmbTaxType->Color = clBtnFace;
    cmbTaxRace->Color = clBtnFace;
    dataStartData->Color = clBtnFace;
    dataSendOutDate->Color = clBtnFace;
    edtFile->Color = clBtnFace;
    



}

//----------------------------------------------------------------
void __fastcall TfmPPaper::ControlWriteFun()
{
    edtOwner->ReadOnly = false; //����Ȩ��
    edtOwner->Color = clWindow;


    edtPosition->ReadOnly = false; //��������
    edtPosition->Color = clWindow;
    edtGround_No->ReadOnly = false; //�غ�
    edtGround_No->Color = clWindow;
    //����״��
    //gridPropertyHourse->Options << goEditing;
    //gridPropertyHourse->Color = clWindow;
    memRemark->ReadOnly = false;
    memRemark->Color = clWindow; //����
    cmbMaker->Color = clWindow;
    cmbChecker->Color = clWindow; //У �� ��

     /*----------------------------*/ //����Ȩ���б�
    //gridOwnerList->Options << goEditing;
    //gridOwnerList->Color = clWindow;
    EdtPrice->ReadOnly = false; //����
    EdtPrice->Color = clWindow;
    //��������

    cmbTaxRace->Color = clWindow; //��˰˰��
    cmbTaxType->Color = clWindow;
    cmbTaxRace->Color = clWindow;
    edtTax->ReadOnly = false; //��˰���
    edtTax->Color = clWindow;
    edtNote->Color = clWindow; //�� ע
    //����Ȩ��ժҪ
    gridPropertyHourse->Color = clWindow;
    gridPropertyHourse->Options << goEditing;
    //gridOtherProperty->Color = clWindow;

    edtUsedAreaM2->ReadOnly = false; //ʹ���������
    edtUsedAreaM2->Color = clWindow;

    edtUsedArea->ReadOnly = false; //ƽ���׺�  Ķ
    edtUsedArea->Color = clWindow;

    edtFileNo->Color = clWindow;
    edtFileNo->ReadOnly = false;
    cmbManageUnit->Color = clWindow;
    dataStartData->Color = clWindow;
    dataSendOutDate->Color = clWindow;
}


void __fastcall TfmPPaper::actSearchExecute(TObject *Sender)
{
    TLocateOptions Opts;
    Opts.Clear();
    Opts << loPartialKey;
    Variant locvalue;
    locvalue = Variant(edtLocate->Text);
    qryIndex->Locate("Paper_NO", locvalue, Opts);

}

//---------------------------------------------------------------------------





void __fastcall TfmPPaper::ClearFormFun()
{

    //�������
    edtPaper_No->Text = ""; //��֤�ֺ����
    edtOwner->Text = ""; //����Ȩ��
    //cmbPropertyRight->Text = "";      //����Ȩ����
    edtOwnerList->Text = ""; //������
    edtPosition->Text = ""; //��������
    edtGround_No->Text = ""; //�غ�
    //����״��
    for (int i = 0; i < gridPropertyHourse->RowCount; i++)
    {
        for (int j = 0; j < gridPropertyHourse->ColCount; j++)
        {
            gridPropertyHourse->Cells[j][i] = "";
        }
    }
    memRemark->Lines->Clear(); //����
    cmbMaker->Text = ""; //�� ֤ ��
    cmbChecker->Text = ""; //У �� ��

     /*----------------------------*/ //����Ȩ���б�
    for (int i = 0; i < gridOwnerList->RowCount; i++)
    {
        for (int j = 0; j < gridOwnerList->ColCount; j++)
        {
            gridOwnerList->Cells[j][i] = "";
        }
    }
    EdtPrice->Text = ""; //����
    cmbTaxType->Text = ""; //��������
    cmbTaxRace->Text = ""; //��˰˰��
    edtTax->Text = ""; //��˰���
    edtNote->Text = ""; //�� ע
    //����Ȩ��ժҪ
    for (int i = 0; i < gridOtherProperty->RowCount; i++)
    {
        for (int j = 0; j < gridOtherProperty->ColCount; j++)
        {
            gridOtherProperty->Cells[j][i] = "";
        }
    }
    edtUsedAreaM2->Text = ""; //ʹ���������
    edtUsedArea->Text = ""; //ƽ���׺�  Ķ
    // edtFile->Text = "";       //����ʹ��֤�ֺ�
    edtFileNo->Text = "";
    cmbManageUnit->Text = "";


}

//---------------------------------------------------------------------------
void __fastcall TfmPPaper::dimgPicture1DblClick(TObject *Sender)
{
    if (qryPicture->IsEmpty())
    {
        qryPicture->Append();
        qryPicture->FieldByName("Paper_NO")->Value = qryIndex->FieldByName(
            "Paper_NO")->AsString;
    }
    else
    {
        qryPicture->Edit();
    }

    if (openDgPic->Execute())
    {
        try
        {
            TBlobField *Field = (TBlobField*)qryPicture->FieldByName("Picture1");
            Field->LoadFromFile(openDgPic->FileName);
            qryPicture->Post();
        }
        __finally{}
    }
}

//---------------------------------------------------------------------------

void __fastcall TfmPPaper::dimgPicture2DblClick(TObject *Sender)
{
    if (qryPicture->IsEmpty())
    {
        qryPicture->Append();
        qryPicture->FieldByName("Paper_NO")->Value = qryIndex->FieldByName(
            "Paper_NO")->AsString;
    }
    else
    {
        qryPicture->Edit();
    }
    if (openDgPic->Execute())
    {
        try
        {
            TBlobField *Field = (TBlobField*)qryPicture->FieldByName("Picture2");
            Field->LoadFromFile(openDgPic->FileName);
            qryPicture->Post();
        }
        __finally{}
    }
}

//---------------------------------------------------------------------------
void __fastcall TfmPPaper::ShowP_OtherPropertyFun()
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    sSql = "select * from OtherProperty_Paper where K_P_Paper_NO='" + edtPaper_No->Text
        + "'";
    ResultSql(q, sSql);
    //�������Ȩ��ժҪStringGrid�ؼ�
    gridOtherProperty->RowCount =3;
    if(q->RecordCount > 3 )
    {
        gridOtherProperty->RowCount = q->RecordCount;
    }
    for (int i = 0; i < gridOtherProperty->RowCount; i++)
    {
        for (int j = 0; j < gridOtherProperty->ColCount; j++)
        {
            gridOtherProperty->Cells[j][i] = "";
        }
    }
    q->First();
    for (int i = 0; i < q->RecordCount; i++)
    {
        gridOtherProperty->Cells[0][i] = q->FieldByName("Obligee")->AsString;
            //Ȩ����
        gridOtherProperty->Cells[1][i] = q->FieldByName("PropertyType")
            ->AsString; //Ȩ������
        gridOtherProperty->Cells[2][i] = q->FieldByName("K_House_NO")
            ->AsString; //����
        gridOtherProperty->Cells[3][i] = q->FieldByName("Room")->AsInteger;
            //����
        gridOtherProperty->Cells[4][i] = q->FieldByName("StructureArea")
            ->AsFloat; //�������
        gridOtherProperty->Cells[5][i] = q->FieldByName("R_Value")->AsFloat;
            //Ȩ����ֵ
        gridOtherProperty->Cells[6][i] = DateToStr(q->FieldByName("Available")
            ->AsDateTime); //��������
        AnsiString sCheckDate = DateToStr(q->FieldByName("CheckOffDate")->AsDateTime); //ע������
        if(sCheckDate=="1899-12-30")
               sCheckDate = "";
        gridOtherProperty->Cells[7][i] =sCheckDate;
        q->Next();
    }
}

void __fastcall TfmPPaper::SetButtonFun()
{
    if(ToolButton1->Enabled == true )
    {
           ToolButton1->Tag = 0;
    }
    else
    {
           ToolButton1->Tag = 1;
    }
    if(ToolButton2->Enabled == true )
    {
           ToolButton2->Tag = 0;
    }
    else
     {
           ToolButton2->Tag = 1;
    }
    if(ToolButton3->Enabled == true )
    {
           ToolButton3->Tag = 0;
    }
    else
     {
           ToolButton3->Tag = 1;
    }
    if(ToolButton5->Enabled == true )
    {
           ToolButton5->Tag = 0;
    }
    else
     {
           ToolButton5->Tag = 1;
    }
     if(ToolButton6->Enabled == true )
    {
           ToolButton6->Tag = 0;
    }
    else
     {
           ToolButton6->Tag = 1;
     }
      if(ToolButton7->Enabled == true )
    {
           ToolButton7->Tag = 0;
    }
    else
     {
           ToolButton7->Tag = 1;
    }
}
//-------------------------------------------------------------------------
void __fastcall TfmPPaper::EnableButtonFun()
{
     if(ToolButton1->Tag  ==  0 )
    {
           ToolButton1->Enabled = true;
    }
    else
    {
           ToolButton1->Enabled = false;
    }
    if(ToolButton2->Tag  ==  0 )
    {
           ToolButton2->Enabled = true;
    }
    else
    {
           ToolButton2->Enabled = false;
    }
    if(ToolButton3->Tag  ==  0 )
    {
           ToolButton3->Enabled = true;
    }
    else
    {
           ToolButton3->Enabled = false;
    }
    if(ToolButton5->Tag  ==  0 )
    {
           ToolButton5->Enabled = true;
    }
    else
    {
           ToolButton5->Enabled = false;
    }
    if(ToolButton6->Tag  ==  0 )
    {
           ToolButton6->Enabled = true;
    }
    else
    {
           ToolButton6->Enabled = false;
    }
    if(ToolButton7->Tag  ==  0 )
    {      
           ToolButton7->Enabled = true;
    }
    else
    {
           ToolButton7->Enabled = false;
    }

}





void __fastcall TfmPPaper::ToolButton8Click(TObject *Sender)
{
   Close();        
}
//---------------------------------------------------------------------------




void __fastcall TfmPPaper::ToolButton11Click(TObject *Sender)
{
   AnsiString sPath;
   SavePaper1Fun();
   SavePaper2Fun();
   sPath = ExtractFilePath(Application->ExeName);
   sPath = sPath + "outprint\\bmp\\1.bmp";
   dimgPicture1->Picture->SaveToFile(sPath);
   sPath = ExtractFilePath(Application->ExeName);
   sPath = sPath + "outprint\\bmp\\2.bmp";
   dimgPicture2->Picture->SaveToFile(sPath);
   sPath = ExtractFilePath(Application->ExeName);
   sPath = sPath + "outprint\\PrintPaperMain.exe";
   ShellExecute(Handle,"open",sPath.c_str(),0,0,SW_SHOWDEFAULT	);


}
//---------------------------------------------------------------------------
void __fastcall TfmPPaper::SavePaper1Fun()
{
  TStringList *ListPaper1 = new TStringList;
  AnsiString sDate;
  AnsiString sPath;
  for(int i = 0 ; i<5;i++)
  {
     ListPaper1->Add(gridOwnerList->Cells[0][i]);
     ListPaper1->Add(gridOwnerList->Cells[1][i]);
     ListPaper1->Add("��֤");
     ListPaper1->Add(gridOwnerList->Cells[2][i]);
     ListPaper1->Add(gridOwnerList->Cells[3][i]);
  }
  ListPaper1->Add(FormatDateTime("YYYY-MM-DD", dataSendOutDate->Date));
  ListPaper1->Add(EdtPrice->Text);
  ListPaper1->Add(cmbTaxType->Text);
  ListPaper1->Add(cmbTaxRace->Text);
  ListPaper1->Add(edtTax->Text);
  ListPaper1->Add(edtNote->Text);
  for(int i = 0 ; i<3;i++)
  {
     for(int j = 0 ;j < 8; j++)
     {
         ListPaper1->Add(gridOtherProperty->Cells[j][i]);
     }

  }
  ListPaper1->Add(edtUsedAreaM2->Text);
  ListPaper1->Add(edtUsedArea->Text);
  ListPaper1->Add(edtFile->Text);
  ListPaper1->Add(edtFileNo->Text);
  sDate = FormatDateTime("YYYY-MM-DD", dataSendOutDate->Date);
  ListPaper1->Add(sDate.SubString(1,4) );
  ListPaper1->Add(sDate.SubString(6,2) );
  ListPaper1->Add(sDate.SubString(9,2) );
  sPath = ExtractFilePath(Application->ExeName);
  sPath = sPath + "outprint\\txt\\ListPaper1.txt";
  ListPaper1->SaveToFile(sPath);
 

}
//----------------------------------------------------------------
void __fastcall TfmPPaper::SavePaper2Fun()
{
  TStringList *ListPaper1 = new TStringList;
  AnsiString sDate;
  AnsiString sPath;
  ListPaper1->Add(edtOwner->Text);
  ListPaper1->Add(edtPropertyRight->Text);
  ListPaper1->Add(edtOwnerList->Text);
  ListPaper1->Add(edtPosition->Text);
  ListPaper1->Add(edtGround_No->Text );
  for(int i=0;i<14;i++)
  {
     for(int j = 0; j<7;j++)
     {
         ListPaper1->Add(gridPropertyHourse->Cells[j][i] );
     }
  }
  ListPaper1->Add(memRemark->Text);
  ListPaper1->Add(cmbMaker->Text);
  ListPaper1->Add(cmbChecker->Text);
  sDate = FormatDateTime("YYYY-MM-DD", dataSendOutDate->Date);
  ListPaper1->Add(sDate);
  ListPaper1->Add(edtPaper_No->Text);
  ListPaper1->Add(cmbManageUnit->Text);
  sPath = ExtractFilePath(Application->ExeName);
  sPath = sPath + "outprint\\txt\\ListPaper2.txt";
  ListPaper1->SaveToFile(sPath);
  //ListPaper1->SaveToFile(ExtractFilePath(Application->ExeName)+"\\ListPaper2.txt");
}
//------------------------------------------------------------
bool TfmPPaper::EnsureHourseInfoFun()
{
    ////////
    int nHourseNum;
    nHourseNum = getBuildingNumFun();
    int nRoom;
    int nFloor;
    float fArea;
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
bool TfmPPaper::EnsureTaxInfoFun()
{
  if ((EdtPrice->Text != "") && (cmbTaxType->Text != "") && (cmbTaxRace->Text
        != "") && (edtTax->Text != ""))
  {
       try
       {
            float fBuf = StrToFloat(EdtPrice->Text);
       }
       catch (EConvertError *E)
       {

            ::MessageBox(this->Handle, "����˰ժҪ������ֻ��ΪС����������", "����",
            MB_ICONERROR);
           return false;
       }
       try
       {
            float fBuf = StrToFloat(edtTax->Text);
       }
       catch (EConvertError *E)
       {

            ::MessageBox(this->Handle, "����˰ժҪ����˰���ֻ��ΪΪС����������", "����",
            MB_ICONERROR);
            return false;
       }

   }
    return true;
}
//------------------------------------------------------------
bool TfmPPaper::EnsureGroundInfoFun()
{   if (edtUsedAreaM2->Text != "" && edtUsedArea->Text != "" && edtFileNo->Text
        != "")
    {
       try
       {
            float fBuf = StrToFloat(edtUsedAreaM2->Text);
       }
       catch (EConvertError *E)
       {

            ::MessageBox(this->Handle, "�ڹ�������ժҪ���������ΪС����������", "����",
            MB_ICONERROR);
            return false;
       }
       try
       {
            float fBuf = StrToFloat(edtUsedArea->Text);
       }
       catch (EConvertError *E)
       {

            ::MessageBox(this->Handle, "�ڹ�������ժҪ���������ΪС����������", "����",
            MB_ICONERROR);
            return false;
       }
    }
       return true;

}

void __fastcall TfmPPaper::SpeedButton10Click(TObject *Sender)
{
   TLocateOptions Opts;

    Opts.Clear();
    Opts << loPartialKey;

        bool bFind = qryIndex->Locate("Paper_NO", edtLocate->Text, Opts);
        
}
//---------------------------------------------------------------------------





