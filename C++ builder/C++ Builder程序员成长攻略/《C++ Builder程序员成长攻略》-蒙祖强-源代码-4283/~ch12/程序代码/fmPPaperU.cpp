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
        //填充   契税种类   组合框
   
    FillCB(cmbTaxRace, qryPropertry, "A_TaxRace", "TaxRace", "");
        //填充   契税税率 组合框
    FillCB(cmbMaker, qryPropertry, "A_Marker", "Marker");

    FillCB(cmbChecker, qryPropertry, "A_Checker", "Checker");

    FillCB(cmbManageUnit, qryPropertry, "A_ManageUnit", "ManageUnit");
    
    ToolButton6->Enabled = false; //提交按钮
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
//执行添加按钮代码
void __fastcall TfmPPaper::actAddExecute(TObject *Sender)
{
    AnsiString sSql;
    AnsiString sPaper_NO;
    TADOQuery *q(dmData->qry);
    ClearFormFun();
    //产生一个房产证号  房产证的长度为10
    sPaper_NO = CreatePaper_NOFun(q);
    g_sPaper_No = sPaper_NO;
    edtPaper_No->Text = sPaper_NO;

    SetButtonFun();
    ToolButton6->Enabled = true; //提交按钮
    ToolButton7->Enabled = true; //提交按钮

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
//执行提交按钮代码
void __fastcall TfmPPaper::actPostExecute(TObject *Sender)
{
    int nOwnerID; //所有权人ID
    int nPropertyRightID; //所有权性质ID
    int nTaxTypeID; // 契税种类ID
    int nTaxRaceID; //契税税率ID
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    //检查信息是否能添加到数据库中去
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
    //把产权人信息输入到产权人表  p_Owner  中去
    tableOwner->Active = false;

    InsertOwnerFun(q,edtOwner->Text, 1);

    //把房屋状况添加到房屋状况表中去
    InsertHoursePropertyFun();
    //把契税摘要信息插入到 契税摘要表 P_Contract_Tax  中去
    InsertContract_TaxFun();

     //把国有土地信息插入到国有土地使用表  GroundProperty 中去
    InsertGroundPropertyFun();

    //把房屋所有权证信息插入到房屋所有权证表  Property_Paper  中。
    InsertPropertyPaperFun();
    sSql = "update InitFileNo set FileNoStart='" + g_sPaper_No +"'";
    ExecuteSql(q, sSql);

    ToolButton6->Enabled = false; //提交按钮
    ControlReadOnlyFun();
    qryIndex->Close();
    qryIndex->Open();
    tableOwner->Active = true;

    EnableButtonFun();



}

//--------------------------------------------------------------------------
/*自定义函数*/
/*函数功能: 把共有权人姓名字符串拆分出姓名列表*/
/*参数说明：
AnsiString sOwnerNames：共有有权人的姓名字符串
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
/*自定义函数
函数功能: 把所有权人、共有权人信息输入到产权人表P_Owner中去
参数说明：
AnsiString sOwnerName ---所有权人的姓名
int nPropertyFlag     ---所有权人的性质
nPropertyFlag=1;代表所有权人
nPropertyFlag=2；代表共有权人
返回值说明：
返回所有权人或共有权人的ID
 */


/*
自定义函数
函数功能：把房屋状况添加到房屋状况表中去
判断在gridPropertyHourse控件中的房屋状况：如果房屋所有的属性为空，则认为不存在该房屋---gridPropertyHourse控件

 */
void __fastcall TfmPPaper::InsertHoursePropertyFun()

{
    int nHourseNum = 0;
    AnsiString sSql;
    TADOQuery *q(dmData->qry);

    //获取房子栋数
    nHourseNum = getBuildingNumFun();


    //把每一栋房子添加到数据库表   P_HouseProperty屋状况表中去
    for (int i = 0; i < nHourseNum; i++)
    {
        sSql = "insert into P_HouseProperty values(";
        sSql += "'0',"; //ID
        sSql += "'" + edtPaper_No->Text + "',"; //房产证号
        sSql += "'" + gridPropertyHourse->Cells[0][i] + "',"; //幢号
        sSql += "'" + gridPropertyHourse->Cells[1][i] + "',"; //房号
        sSql += gridPropertyHourse->Cells[2][i] + ","; //间数
        sSql += "'" + gridPropertyHourse->Cells[3][i] + "',"; //建筑结构
        sSql += gridPropertyHourse->Cells[4][i] + ","; //层数
        sSql += gridPropertyHourse->Cells[5][i] + ","; //建筑面积
        sSql += "'" + gridPropertyHourse->Cells[6][i] + "')"; //备注
        ExecuteSql(q, sSql);
    }
}

//---------------------------------------------------------------------------
/*
自定义函数
函数功能：把共有权证信息添加到    ShareProperty_Paper共有权证表     中去
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
    //检查共有权人数量
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

    //把共有权人添加到共有权权人表中去，
    //同时返回共有权人ID作为一个ID列表存在SListIDList中
    for (int i = 0; i < nOwnerNum; i++)
    {
        int nID = 0;
        nID = InsertOwnerFun(q,gridOwnerList->Cells[0][i], 2);
            //插入共有人信息输入到产权人表  p_Owner  中去

        SListIDList->Add(IntToStr(nID));
        edtOwnerList->Text = edtOwnerList->Text + gridOwnerList->Cells[0][i] +
            "   ";

    }




    //获取缮证人 ID
    nMarkerID = GetID(q, "A_Marker", "RID", "Marker", cmbMaker->Text);
    //获取校对人ID
    nCheckerID = GetID(q, "A_Checker", "RID", "Checker", cmbMaker->Text);
    //获取填发机关ID
    nManageUnitID = GetID(q, "A_ManageUnit", "RID", "ManageUnit", cmbManageUnit
        ->Text);
    //获取栋数
    nBuildingNum = getBuildingNumFun();
    //获取间数
    nHourseNum = getHourseNumFun();
    //获取建筑面积
    fHourseArea = getHourseAreaFun();
    //获取日期
    sDate = FormatDateTime("YYYY.MM.DD", dataSendOutDate->Date);
    //把每一个共有权证信息保存到ShareProperty_Paper 共有权证表。
    for (int i = 0; i < nOwnerNum; i++)
    {
        //产生共有权证号 ,把共有权证号列表存在SListShareList中
        AnsiString sShare_ID;
        sShare_ID = CreateShareProperty_NOFun(q);

        SListShareList->Add(sShare_ID);
        sSql = "insert into ShareProperty_Paper values(";
        sSql += "'0',"; //ID
        sSql += "'" + edtPaper_No->Text + "',"; //所有权证编号
        sSql += "'" + SListShareList->Strings[i] + "',"; //共有权证号
        sSql += "'" + SListIDList->Strings[i] + "',"; // 共有人编号
        sSql += gridOwnerList->Cells[1][i] + ","; //共有份额
        sSql += IntToStr(nBuildingNum) + ","; //栋数
        sSql += IntToStr(nHourseNum) + ","; //间数
        sSql += FloatToStr(fHourseArea) + ","; //建筑面积
        sSql += IntToStr(nMarkerID) + ","; //缮证人
        sSql += IntToStr(nCheckerID) + ","; //校对人
        sSql += IntToStr(nManageUnitID) + ","; //填发机关
        sSql +=  + "'" + sDate + "',"; //填发日期
        sSql +=  + "'" + sDate + "',"; //领证日期
        sSql +=  + "'" + gridOwnerList->Cells[3][i] + "')"; //备注

        ExecuteSql(q, sSql);
    }

}

//---------------------------------------------------------------------------

/*
自定义函数：
函数说明：
把契税摘要信息插入到 契税摘要表 P_Contract_Tax  中去
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
    //获取契税种类ID
    nTaxType_ID = GetID(q, "A_TaxType", "RID", "TaxType", cmbTaxType->Text);

    //获取契税税率ID
    nTaxRace_ID = GetID(q, "A_TaxRace", "RID", "TaxRace", cmbTaxRace->Text);

    //获取日期
    sDate = FormatDateTime("YYYY.MM.DD", dataStartData->Date);
    sSql = "insert into P_Contract_Tax values(";
    sSql += "'0',"; //唯一的内部编号
    sSql += "'" + edtPaper_No->Text + "',"; //所有权证编号
    sSql += "'" + sDate + "',"; //立契日期
    sSql += EdtPrice->Text + ","; //契价
    sSql += IntToStr(nTaxType_ID) + ","; //外键，契税种类
    sSql += IntToStr(nTaxRace_ID) + ","; //外键，契税税率
    sSql += edtTax->Text + ","; //金额
    sSql += "'" + edtNote->Text + "')"; //备注

    ExecuteSql(q, sSql);

}

//---------------------------------------------------------------------------

/*
自定义函数
函数说明：
把他项权利信息插入到 P_OtherProperty 他项权利摘要表。
 */
void __fastcall TfmPPaper::InsertOtherPropertyFun()
{
    int nOtherPropertyNum = 0;
    AnsiString sSql;
    AnsiString sDate;
    TADOQuery *q(dmData->qry);

    //检查他项权利数量数量
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

    //把他项权利信息插入到 P_OtherProperty 他项权利摘要表
    for (int i = 0; i < nOtherPropertyNum; i++)
    {
        sDate = FormatDateTime("YYYY.MM.DD", StrToDateTime(gridOtherProperty
            ->Cells[7][i]));
        sSql = "insert into P_OtherProperty values(";
        sSql += "'0',"; //唯一的内部编号
        sSql += "'" + edtPaper_No->Text + "',"; //所有权证编号
        sSql += "'" + gridOtherProperty->Cells[1][i] + "',"; //权利种类
        sSql += "'" + gridOtherProperty->Cells[0][i] + "',"; //权利人
        sSql += "'0',"; //房屋编号
        sSql += "'" + gridOtherProperty->Cells[2][i] + "',"; //房号
        sSql += "'" + gridOtherProperty->Cells[3][i] + "',"; //间数
        sSql += "'" + gridOtherProperty->Cells[4][i] + "',";
        ; //建筑面积
        sSql += gridOtherProperty->Cells[5][i] + ",";
        ; //权利价值
        sSql += "'" + gridOtherProperty->Cells[6][i] + "',";
        ; //存续期限
        sSql += "'" + sDate + "')";
        ; //注销日期

        ExecuteSql(q, sSql);

    }

}

//-------------------------------------------------------------------------
/*
自定义函数
函数说明：
//把国有土地信息插入到国有土地使用表  GroundProperty 中去
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
    sSql += "'0',"; // 唯一的内部编号
    sSql += "'" + edtPaper_No->Text + "',"; // 所有权证编号
    sSql += "'桂房证',"; // 土地使用证字
    sSql += "'" + edtFileNo->Text + "',"; // 土地使用证号
    sSql += "'" + edtUsedAreaM2->Text + "',"; // 使用国有土地面积（平方米）
    sSql += "'" + edtUsedArea->Text + "',"; // 使用国有土地面积（亩）
    sSql += "'" + sDate + "')";
   
    ExecuteSql(q, sSql);



}

//-------------------------------------------------------------------------
/*
自定义函数
函数说明：
//把国有土地信息插入到国有土地使用表  GroundProperty 中去
 */
void __fastcall TfmPPaper::InsertPropertyPaperFun()
{
    int nOwnerID; //所有权人ID
    int nPropertyRightID;
    int nManageUnitID;
    int nMarkerID;
    int nCheckerID;
    AnsiString sSql;
    AnsiString sDate;
    TADOQuery *q(dmData->qry);

    //获取所有权性质
    sSql =
        "select K_PropertyRight_ID from A_PropertyRight where PropertyRight='"
        + edtPropertyRight->Text + "'";
    ResultSql(q, sSql);
    if (q->RecordCount > 0)
    {
        nPropertyRightID = q->FieldByName("K_PropertyRight_ID")->AsInteger;
    }
    //获取填发机关ID
    nManageUnitID = GetID(q, "A_ManageUnit", "RID", "ManageUnit", cmbManageUnit
        ->Text);

    //获取缮证人 ID
    nMarkerID = GetID(q, "A_Marker", "RID", "Marker", cmbMaker->Text);
    //获取校对人ID
    nCheckerID = GetID(q, "A_Checker", "RID", "Checker", cmbChecker->Text);
    //获取日期
    sDate = FormatDateTime("YYYY.MM.DD", Now());
    nOwnerID = GetMaxRecId(q, "P_Owner", "RNO", "0") + 1; //产生一个产权人ID
    InsertOwnerFun(q,edtOwner->Text, 1);
    sSql = "insert into Property_Paper values(";
    sSql += "'0',";
    sSql += "'桂房证',";

    sSql += "'" + edtPaper_No->Text + "',"; // 房产证号;

    sSql += "'0',"; // 申请审批表编号
    sSql += "'" + IntToStr(nOwnerID) + "',"; // 所有权人编号
    sSql += "'" + edtOwnerList->Text + "',"; //共有人
    sSql += "'" + edtPosition->Text + "',"; //房屋座落;
    sSql += "'" + edtGround_No->Text + "',"; //地号
    sSql += IntToStr(nPropertyRightID) + ","; // 所有权性质
    sSql += "'0',"; // 状态
    sSql += IntToStr(nManageUnitID) + ","; // 填发机关
    sSql += IntToStr(nMarkerID) + ","; //缮证人
    sSql += IntToStr(nCheckerID) + ","; //校对人
    sSql +=  + "'" + sDate + "',"; //填发日期
    sSql +=  + "'" + sDate + "',"; //领证日期
    sSql +=  + "'" + memRemark->Text + "')"; //附记

    ExecuteSql(q, sSql);
}

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

/*
自定义函数
函数说明：用来获取房子栋数
返回值说明:返回房子栋数
 */
int __fastcall TfmPPaper::getBuildingNumFun()
{
    int nBuildingNum = 0;
    //for循环判断在 gridPropertyHourse中一共有多少栋房子
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
自定义函数
函数说明：用来获取房子间数
返回值说明:返回房子间数
 */
int __fastcall TfmPPaper::getHourseNumFun()
{
    int nHourseNum = 0;
    int nBuildingNum = 0;
    //获取房子栋数
    nBuildingNum = getBuildingNumFun();
    //计算房子的总间数

    for (int i = 0; i < nBuildingNum; i++)
    {
        nHourseNum += StrToInt(gridPropertyHourse->Cells[1][i]);

    }
    return nHourseNum;
}

/*
自定义函数
函数说明：用来获取房子总面积
返回值说明:返回房子总面积
 */
//----------------------------------------------------------------------
float __fastcall TfmPPaper::getHourseAreaFun()
{
    float fHourseArea = 0.0;
    int nBuildingNum = 0;
    //获取房子栋数
    nBuildingNum = getBuildingNumFun();
    //计算房子的总间数
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
    {   ToolButton6->Enabled = false; //提交按钮
       ClearFormFun();
       ControlReadOnlyFun();
       EnableButtonFun();
    }
}

//---------------------------------------------------------------------------

/*
/*
自定义函数
函数说明：显示所有权证*/
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

    //获得所有权人姓名
    sOwnerId = (qryIndex->FieldByName("K_Owner_NO")->AsString); //获得ID
    m_sOwnerID = sOwnerId;
    sOwnerName = GetNameFieldFromIDFieldS(q, "P_Owner", "OwnerName", "RNO",
        sOwnerId);

    //获得所有权性质
    nPropertyRight = qryIndex->FieldByName("K_PropertyRight_ID")->AsInteger;
    sPropertyRight = GetNameFieldFromIDFieldN(q, "A_PropertyRight",
        "PropertyRight", "K_PropertyRight_ID", nPropertyRight);

    //获取填发机关
    nManageUnit = qryIndex->FieldByName("K_ManageUnit_ID")->AsInteger;

    sManageUnit = GetNameFieldFromIDFieldN(q, "A_ManageUnit", "ManageUnit",
        "RID", nManageUnit);

    //获取缮证人
    nMarker = qryIndex->FieldByName("K_Maker_ID")->AsInteger;

    sMarker = GetNameFieldFromIDFieldN(q, "A_Marker", "Marker", "RID", nMarker);
    //获取校对人
    nChecker = qryIndex->FieldByName("K_Checker_ID")->AsInteger;

    sChecker = GetNameFieldFromIDFieldN(q, " A_Checker", "Checker", "RID",
        nChecker);

    //显示所有权人姓名
    edtOwner->Text = sOwnerName;
    edtPaper_No->Text = qryIndex->FieldByName("Paper_NO")->AsString;
    //显示所有权性质

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
自定义函数
函数说明：显示契税摘要
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
        //获取契税种类ID
        nTaxType = q->FieldByName("K_TaxType_ID")->AsInteger;
        //获取契税税率ID
        nTaxRace = q->FieldByName("K_TaxRace_ID")->AsInteger;
        EdtPrice->Text = q->FieldByName("Price")->AsFloat;
        edtTax->Text = q->FieldByName("Tax")->AsFloat;
        edtNote->Text = q->FieldByName("Note")->AsString;
        //获取契税种类
        sTaxType = GetNameFieldFromIDFieldN(q, "A_TaxType", "TaxType", "RID",
            nTaxType);
        //获取契税税率
        sTaxRace = GetNameFieldFromIDFieldN(q, "A_TaxRace", "TaxRace", "RID",
            nTaxRace);
        cmbTaxType->Text = sTaxType;
        cmbTaxRace->Text = sTaxRace;
    }
}

//---------------------------------------------------------------------
/*
自定义函数:
函数说明:
//显示共有权证
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
        //获取共有人编号
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
自定义函数:
函数说明:
//显示他项权利摘要
 */
/*void __fastcall TfmPPaper::ShowP_OtherPropertyFun()
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    sSql = "select * from P_OtherProperty where Paper_NO='" + edtPaper_No->Text
        + "'";
    ResultSql(q, sSql);
    //清空他项权利摘要StringGrid控件
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
            //权利人
        gridOtherProperty->Cells[1][i] = q->FieldByName("PropertyType")
            ->AsString; //权利种类
        gridOtherProperty->Cells[2][i] = q->FieldByName("K_House_NO")
            ->AsString; //房号
        gridOtherProperty->Cells[3][i] = q->FieldByName("Room")->AsInteger;
            //间数
        gridOtherProperty->Cells[4][i] = q->FieldByName("Structure_Area")
            ->AsFloat; //建筑面积
        gridOtherProperty->Cells[5][i] = q->FieldByName("Pro_Value")->AsFloat;
            //权利价值
        gridOtherProperty->Cells[6][i] = DateToStr(q->FieldByName("Available")
            ->AsDateTime); //存续期限
        gridOtherProperty->Cells[7][i] = DateToStr(q->FieldByName("CheckOff")
            ->AsDateTime); //注销期限
        q->Next();
    }
}
  */
//------------------------------------------------------------------------
/*
自定义函数:
函数说明:
//显示房屋状况
 */
void __fastcall TfmPPaper::ShowP_PropertyHouseFun()
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    sSql = "select * from P_HouseProperty where Paper_NO='" + edtPaper_No->Text
        + "'";
    ResultSql(q, sSql);
    //清空房屋状况StringGrid控件
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
            ->AsString; //栋号
        gridPropertyHourse->Cells[1][i] = q->FieldByName("Doorplate_NO")
            ->AsString; //房号
        gridPropertyHourse->Cells[2][i] = q->FieldByName("Room")->AsInteger;
            //间数
        gridPropertyHourse->Cells[3][i] = q->FieldByName("Structure")
            ->AsString; //结构
        gridPropertyHourse->Cells[4][i] = q->FieldByName("Floor")->AsInteger;
            //层数
        gridPropertyHourse->Cells[5][i] = q->FieldByName("Structure_Area")
            ->AsFloat; //结构面积
        gridPropertyHourse->Cells[6][i] = q->FieldByName("Note")->AsString;
            //备注
        q->Next();
    }
}

/*
自定义函数:
函数说明:
获取建筑面积
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
        edtFile->Text = q->FieldByName("File_NO_Head")->AsString; //土地字
        edtFileNo->Text = q->FieldByName("File_NO")->AsString; //土地号
        edtUsedAreaM2->Text = q->FieldByName("UsedAreaM2")->AsFloat; //土地面积
        edtUsedArea->Text = q->FieldByName("UsedArea")->AsFloat; //土地亩
        
        dataSendOutDate->DateTime = q->FieldByName("SendDate")->AsDateTime;
    }
}

//-------------------------------------------------------------------------
void __fastcall TfmPPaper::qryIndexAfterScroll(TDataSet *DataSet)
{
    ClearFormFun();
    //显示所有权
    ShowProperty_PaperFun();

    //显示房屋状况
    ShowP_PropertyHouseFun();
    //显示他项权利摘要
    ShowP_OtherPropertyFun();
    //显示契税摘要
    ShowP_Contract_TaxFun();
    //显示供有权人摘要
    ShowShareProperty_PaperFun();
    //显示土地信息
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
    //  cmbPropertyRight->Text = "所有人";
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
自定义函数
函数说明：
用来判断在提交的之前检查数据的有效性
 */

bool __fastcall TfmPPaper::EnsureDatAvalidFun()
{
    if (edtOwner->Text == "")
    {
        ::MessageBox(this->Handle, "所有权人姓名不能为空！", "警告",
            MB_ICONERROR);
        return false;
    }
    if (cmbMaker->Text == "")
    {
        ::MessageBox(this->Handle, "缮证人姓名不能为空！", "警告", MB_ICONERROR)
            ;
        return false;
    }
    if (cmbChecker->Text == "")
    {
        ::MessageBox(this->Handle, "校对人姓名不能为空！", "警告", MB_ICONERROR)
            ;
        return false;
    }
    if (cmbManageUnit->Text == "")
    {
        ::MessageBox(this->Handle, "填发机关不能为空！", "警告", MB_ICONERROR);
        return false;
    }
}

void __fastcall TfmPPaper::ControlReadOnlyFun()
{
    edtPaper_No->ReadOnly = true;
    edtPaper_No->Color = clBtnFace;
    edtOwner->ReadOnly = true; //所有权人
    edtOwner->Color = clBtnFace;
    edtPropertyRight->ReadOnly = true;
    edtPropertyRight->Color = clBtnFace; //所有权性质
    edtOwnerList->ReadOnly = true; //共有人
    edtOwnerList->Color = clBtnFace;
    edtPosition->ReadOnly = true; //房屋坐落
    edtPosition->Color = clBtnFace;
    edtGround_No->ReadOnly = true; //地号
    edtGround_No->Color = clBtnFace;
    //房屋状况
    gridPropertyHourse->Options >> goEditing;
    gridPropertyHourse->Color = clBtnFace;
    memRemark->ReadOnly = true;
    memRemark->Color = clBtnFace; //附记
    cmbMaker->Color = clBtnFace;
    cmbChecker->Color = clBtnFace; //校 对 人

     /*----------------------------*/ //共有权人列表
   // gridOwnerList->Options >> goEditing;
    gridOwnerList->Color = clBtnFace;

    EdtPrice->ReadOnly = true; //契价
    EdtPrice->Color = clBtnFace;
    //契价种类
    cmbTaxRace->Color = clBtnFace; //契税税率
    edtTax->Color = clBtnFace;
    edtTax->ReadOnly = true; //纳税金额
    edtNote->Color = clBtnFace; //备 注
    //他项权利摘要
    //gridOtherProperty->Options >> goEditing;
    gridOtherProperty->Color = clBtnFace;
    edtUsedAreaM2->ReadOnly = true; //使用土地面积
    edtUsedAreaM2->Color = clBtnFace;
    edtUsedArea->ReadOnly = true; //平方米合  亩

    edtUsedArea->Color = clBtnFace;
    // edtFile->Text = "";       //土地使用证字号
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
    edtOwner->ReadOnly = false; //所有权人
    edtOwner->Color = clWindow;


    edtPosition->ReadOnly = false; //房屋坐落
    edtPosition->Color = clWindow;
    edtGround_No->ReadOnly = false; //地号
    edtGround_No->Color = clWindow;
    //房屋状况
    //gridPropertyHourse->Options << goEditing;
    //gridPropertyHourse->Color = clWindow;
    memRemark->ReadOnly = false;
    memRemark->Color = clWindow; //附记
    cmbMaker->Color = clWindow;
    cmbChecker->Color = clWindow; //校 对 人

     /*----------------------------*/ //共有权人列表
    //gridOwnerList->Options << goEditing;
    //gridOwnerList->Color = clWindow;
    EdtPrice->ReadOnly = false; //契价
    EdtPrice->Color = clWindow;
    //契价种类

    cmbTaxRace->Color = clWindow; //契税税率
    cmbTaxType->Color = clWindow;
    cmbTaxRace->Color = clWindow;
    edtTax->ReadOnly = false; //纳税金额
    edtTax->Color = clWindow;
    edtNote->Color = clWindow; //备 注
    //他项权利摘要
    gridPropertyHourse->Color = clWindow;
    gridPropertyHourse->Options << goEditing;
    //gridOtherProperty->Color = clWindow;

    edtUsedAreaM2->ReadOnly = false; //使用土地面积
    edtUsedAreaM2->Color = clWindow;

    edtUsedArea->ReadOnly = false; //平方米合  亩
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

    //界面清空
    edtPaper_No->Text = ""; //桂房证字号清空
    edtOwner->Text = ""; //所有权人
    //cmbPropertyRight->Text = "";      //所有权性质
    edtOwnerList->Text = ""; //共有人
    edtPosition->Text = ""; //房屋坐落
    edtGround_No->Text = ""; //地号
    //房屋状况
    for (int i = 0; i < gridPropertyHourse->RowCount; i++)
    {
        for (int j = 0; j < gridPropertyHourse->ColCount; j++)
        {
            gridPropertyHourse->Cells[j][i] = "";
        }
    }
    memRemark->Lines->Clear(); //附记
    cmbMaker->Text = ""; //缮 证 人
    cmbChecker->Text = ""; //校 对 人

     /*----------------------------*/ //共有权人列表
    for (int i = 0; i < gridOwnerList->RowCount; i++)
    {
        for (int j = 0; j < gridOwnerList->ColCount; j++)
        {
            gridOwnerList->Cells[j][i] = "";
        }
    }
    EdtPrice->Text = ""; //契价
    cmbTaxType->Text = ""; //契价种类
    cmbTaxRace->Text = ""; //契税税率
    edtTax->Text = ""; //纳税金额
    edtNote->Text = ""; //备 注
    //他项权利摘要
    for (int i = 0; i < gridOtherProperty->RowCount; i++)
    {
        for (int j = 0; j < gridOtherProperty->ColCount; j++)
        {
            gridOtherProperty->Cells[j][i] = "";
        }
    }
    edtUsedAreaM2->Text = ""; //使用土地面积
    edtUsedArea->Text = ""; //平方米合  亩
    // edtFile->Text = "";       //土地使用证字号
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
    //清空他项权利摘要StringGrid控件
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
            //权利人
        gridOtherProperty->Cells[1][i] = q->FieldByName("PropertyType")
            ->AsString; //权利种类
        gridOtherProperty->Cells[2][i] = q->FieldByName("K_House_NO")
            ->AsString; //房号
        gridOtherProperty->Cells[3][i] = q->FieldByName("Room")->AsInteger;
            //间数
        gridOtherProperty->Cells[4][i] = q->FieldByName("StructureArea")
            ->AsFloat; //建筑面积
        gridOtherProperty->Cells[5][i] = q->FieldByName("R_Value")->AsFloat;
            //权利价值
        gridOtherProperty->Cells[6][i] = DateToStr(q->FieldByName("Available")
            ->AsDateTime); //存续期限
        AnsiString sCheckDate = DateToStr(q->FieldByName("CheckOffDate")->AsDateTime); //注销期限
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
     ListPaper1->Add("桂房证");
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
    //把每一栋房子添加到数据库表   P_HouseProperty屋状况表中去
    for (int i = 0; i < nHourseNum; i++)
    {
        try
       {
           nRoom  = StrToInt(gridPropertyHourse->Cells[2][i]);
       }
       catch (EConvertError *E)
       {

            ::MessageBox(this->Handle, "在房屋状况栏中房子的间数只能为整数！", "警告",
            MB_ICONERROR);
           return false;
       }
        try
       {
            nFloor = StrToInt(gridPropertyHourse->Cells[4][i]);
       }
       catch (EConvertError *E)
       {

            ::MessageBox(this->Handle, "在房屋状况栏中房子的层数只能为整数！", "警告",
            MB_ICONERROR);
           return false;
       }
        try
       {
            fArea = StrToFloat(gridPropertyHourse->Cells[5][i]);
       }
       catch (EConvertError *E)
       {

            ::MessageBox(this->Handle, "在房屋状况栏中房子的建筑面积只能为小数或整数！", "警告",
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

            ::MessageBox(this->Handle, "在契税摘要中契价只能为小数或整数！", "警告",
            MB_ICONERROR);
           return false;
       }
       try
       {
            float fBuf = StrToFloat(edtTax->Text);
       }
       catch (EConvertError *E)
       {

            ::MessageBox(this->Handle, "在契税摘要中纳税金额只能为为小数或整数！", "警告",
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

            ::MessageBox(this->Handle, "在国有土地摘要中土地面积为小数或整数！", "警告",
            MB_ICONERROR);
            return false;
       }
       try
       {
            float fBuf = StrToFloat(edtUsedArea->Text);
       }
       catch (EConvertError *E)
       {

            ::MessageBox(this->Handle, "在国有土地摘要中土地面积为小数或整数！", "警告",
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





