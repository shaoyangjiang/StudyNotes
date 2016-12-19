//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmSharePropU.h"
#include "fmPPaperU.h"
#include "dmDataU.h"
#include "SysFuncs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmShareProp *fmShareProp;
//---------------------------------------------------------------------------
__fastcall TfmShareProp::TfmShareProp(TComponent *Owner): TForm(Owner){}
//---------------------------------------------------------------------------

void __fastcall TfmShareProp::FormCreate(TObject *Sender)
{
    AnsiString sSql;

    this->panPaperNo->Caption = "桂房证字第：" + fmPPaper->edtPaper_No->Text +
        "号";
    sSql = "select * from ShareProperty_Paper where  K_Paper_NO ='" + fmPPaper
        ->edtPaper_No->Text + "'";
    sSql =sSql + " and RNO ='0'";
    ResultSql(qryIndex, sSql);
    ControlReadOnlyFun();

}

//---------------------------------------------------------------------------
void __fastcall TfmShareProp::qryIndexAfterScroll(TDataSet *DataSet)
{
    AnsiString sOwnerId;
    AnsiString sOwnerName;
    TADOQuery *q(dmData->qry);

    sOwnerId = (qryIndex->FieldByName("K_Owner_NO")->AsString); //获得ID
    sOwnerName = GetNameFieldFromIDFieldS(q, "P_Owner", "OwnerName", "RNO",
        sOwnerId);
    edtOwner->Text = sOwnerName;
    edtShare->Text = qryIndex->FieldByName("Share")->AsFloat;
    memRemark->Text =qryIndex->FieldByName("remark")->AsString;
}

//---------------------------------------------------------------------------

void __fastcall TfmShareProp::actAddExecute(TObject *Sender)
{
    UpdateBtn->Enabled = true; //提交按钮
    ControlWriteFun();
    edtOwner->Text = "";
    edtShare->Text = "";
    memRemark->Text = "";
    edtOwner->ReadOnly = false;
    edtShare->ReadOnly = false;
    memRemark->ReadOnly = false;
    m_nEditFlag = 1;
}

//---------------------------------------------------------------------------

void __fastcall TfmShareProp::actEditExecute(TObject *Sender)
{
    
    if (qryIndex->RecordCount == 0)
    {
        ::MessageBox(this->Handle, "不存在共有权人，添加后才能修改！", "警告",
            MB_ICONERROR);
        return ;
    }
    UpdateBtn->Enabled = true; //提交按钮
    ControlWriteFun();
    edtOwner->ReadOnly = false;
    edtShare->ReadOnly = false;
    memRemark->ReadOnly = false;
    m_nEditFlag = 2;
}

//---------------------------------------------------------------------------

void __fastcall TfmShareProp::EditRecordFun()
{
    //
    AnsiString sOwnerId;
    AnsiString sShare_Paper_NO;
    AnsiString sOwnerName;
    TADOQuery *q(dmData->qry);
    AnsiString sSql;

    //获取共有人ID
    sOwnerId = (qryIndex->FieldByName("K_Owner_NO")->AsString); //获得ID
    sShare_Paper_NO = (qryIndex->FieldByName("ShareProperty_Paper_NO")
        ->AsString);

    //插入共有人姓名到共有人表
    sSql = "update P_Owner set OwnerName ='" + edtOwner->Text + "'" +
        " where RNO=" + IntToStr(StrToInt(sOwnerId));
    ExecuteSql(q, sSql);
    //更新共有人权利表信息
    sSql = "update ShareProperty_Paper set Share =" + edtShare->Text +
        ",Remark='" + memRemark->Text + "'" + " where ShareProperty_Paper_NO='"
        + sShare_Paper_NO + "'";
       

    ExecuteSql(q, sSql);
}

//------------------------------------------------------------------------------
void __fastcall TfmShareProp::InsertRecordFun()
{
    //

    AnsiString sSql;
    int nBuildingNum;
    int nHourseNum;
    float fHourseArea;
    int nMarkerID;
    int nCheckerID;
    int nManageUnitID;
    int nID = 0; //共有权人ID
    AnsiString sDate;
    TADOQuery *q(dmData->qry);
    //获取缮证人 ID
    nMarkerID = GetID(q, "A_Marker", "RID", "Marker", fmPPaper->cmbMaker->Text);

    //获取校对人ID
    nCheckerID = GetID(q, "A_Checker", "RID", "Checker", fmPPaper->cmbMaker
        ->Text);

    //获取填发机关ID
    nManageUnitID = GetID(q, "A_ManageUnit", "RID", "ManageUnit", fmPPaper
        ->cmbManageUnit->Text);

    //获取栋数
    nBuildingNum = fmPPaper->getBuildingNumFun();
    //获取间数
    nHourseNum = fmPPaper->getHourseNumFun();


    //获取建筑面积
    fHourseArea = fmPPaper->getHourseAreaFun();

    //获取日期
    sDate = FormatDateTime("YYYY.MM.DD", fmPPaper->dataSendOutDate->Date);

    nID = InsertOwnerFun(q, edtOwner->Text, 2);
    //插入共有人信息输入到产权人表  p_Owner  中去

    //产生共有权证号 ,把共有权证号列表存在SListShareList中
    AnsiString sShare_ID;
    sShare_ID = CreateShareProperty_NOFun(q);
    //把每一个共有权证信息保存到ShareProperty_Paper 共有权证表。
    sSql = "insert into ShareProperty_Paper values(";
    sSql += "'0',"; //ID
    sSql += "'" + fmPPaper->edtPaper_No->Text + "',"; //所有权证编号
    sSql += "'" + sShare_ID + "',"; //共有权证号
    sSql += "'" + IntToStr(nID) + "',"; // 共有人编号
    sSql += edtShare->Text + ","; //共有份额
    sSql += IntToStr(nBuildingNum) + ","; //栋数
    sSql += IntToStr(nHourseNum) + ","; //间数
    sSql += FloatToStr(fHourseArea) + ","; //建筑面积
    sSql += IntToStr(nMarkerID) + ","; //缮证人
    sSql += IntToStr(nCheckerID) + ","; //校对人
    sSql += IntToStr(nManageUnitID) + ","; //填发机关
    sSql +=  + "'" + sDate + "',"; //填发日期
    sSql +=  + "'" + sDate + "',"; //领证日期
    sSql +=  + "'" + memRemark->Text + "')"; //备注

    ExecuteSql(q, sSql);
}

void __fastcall TfmShareProp::actPostExecute(TObject *Sender)
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);

    tableOwner->Active = false;
    if (edtOwner->Text == "")
    {
        ::MessageBox(this->Handle, "共有权人姓名不能为空！", "警告",
            MB_ICONERROR);
        return ;
    }
    if (edtShare->Text == "")
    {
        ::MessageBox(this->Handle, "共有份额不能为空！", "警告", MB_ICONERROR);
        return ;
    }
    try
    {
        StrToFloat(edtShare->Text);
    }
    catch (EConvertError *E)
    {

        ::MessageBox(this->Handle, "共有份额只能为小数或整数！", "警告",
            MB_ICONERROR);
        return ;
    }
    switch (m_nEditFlag)
    {
        case 1:
            {
                InsertRecordFun();
                sSql = "select * from ShareProperty_Paper where  K_Paper_NO ='"
                    + fmPPaper->edtPaper_No->Text + "'";
                ResultSql(qryIndex, sSql);
            }
            break;
        case 2:
            {
                if (qryIndex->FieldCount == 0)
                {
                    return ;
                }
                EditRecordFun();
                sSql = "select * from ShareProperty_Paper where  K_Paper_NO ='"
                    + fmPPaper->edtPaper_No->Text + "'";
                ResultSql(qryIndex, sSql);

            }
            break;
    }
    //在主窗口更新共有权信息
    UpdateMainFormInfoFun();
    tableOwner->Active = true;
    UpdateBtn->Enabled = false; //提交按钮
    ControlReadOnlyFun();


}

//---------------------------------------------------------------------------



void __fastcall TfmShareProp::actDeleteExecute(TObject *Sender)
{
    if (qryIndex->FieldCount == 0)
    {
        return ;
    }
    if (MessageDlg("删除记录不可恢复，你确定要删除吗？ ", mtError,
        TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk)
    {
        qryIndex->Delete();
    }
    UpdateMainFormInfoFun();

}

//---------------------------------------------------------------------------
/*自定义函数
函数说明：更新主窗口中共有权信息
 */
void __fastcall TfmShareProp::UpdateMainFormInfoFun()
{
    TStringList *sListOwnerName = new TStringList();
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    sListOwnerName = fmPPaper->ShowShareProperty_PaperFun();
    fmPPaper->edtOwnerList->Text = "";
    for (int i = 0; i < sListOwnerName->Count; i++)
    {
        fmPPaper->edtOwnerList->Text = fmPPaper->edtOwnerList->Text +
            sListOwnerName->Strings[i] + " ";
    }


    sSql = "update Property_Paper  set OwnerList ='" + fmPPaper->edtOwnerList
        ->Text + "' where Paper_NO='" + fmPPaper->edtPaper_No->Text + "'";
    ExecuteSql(q, sSql);

}


void __fastcall TfmShareProp::actCancleExecute(TObject *Sender)
{
    qryIndex->First();
    UpdateBtn->Enabled = false; //提交按钮
    ControlReadOnlyFun();
}

//---------------------------------------------------------------------------
void __fastcall TfmShareProp::ControlWriteFun()
{
    edtOwner->ReadOnly = false;
    edtOwner->Color = clWindow;
    edtShare->ReadOnly = false;
    edtShare->Color = clWindow;
    memRemark->ReadOnly = false;
    memRemark->Color = clWindow;

}

//----------------------------------------------------------------------------
void __fastcall TfmShareProp::ControlReadOnlyFun()
{
    edtOwner->ReadOnly = true;
    edtOwner->Color = clBtnFace;
    edtShare->ReadOnly = true;
    edtShare->Color = clBtnFace;
    memRemark->ReadOnly = true;
    memRemark->Color = clBtnFace;
}




