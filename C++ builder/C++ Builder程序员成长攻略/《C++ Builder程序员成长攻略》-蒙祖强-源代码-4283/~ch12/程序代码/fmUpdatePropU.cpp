/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "fmUpdatePropU.h"
#include "fmPPaperU.h"
#include "dmDataU.h"
#include "SysFuncs.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmUpdateProp *fmUpdateProp;
//---------------------------------------------------------------------------
__fastcall TfmUpdateProp::TfmUpdateProp(TComponent *Owner): TForm(Owner){}
//---------------------------------------------------------------------------

void __fastcall TfmUpdateProp::FormCreate(TObject *Sender)
{
    TADOQuery *q(dmData->qry);
    this->panPaperNo->Caption = "桂房证字第：" + fmPPaper->edtPaper_No->Text +
        "号";
    this->edtOwner->Text = fmPPaper->edtOwner->Text;
    this->edtPosition->Text = fmPPaper->edtPosition->Text;
    this->edtGround_No->Text = fmPPaper->edtGround_No->Text;
    this->memRemark->Text = fmPPaper->memRemark->Text;
    this->cmbMaker->Text = fmPPaper->cmbMaker->Text;
    this->cmbChecker->Text = fmPPaper->cmbChecker->Text;
    this->cmbManageUnit->Text = fmPPaper->cmbManageUnit->Text;


    FillCB(cmbMaker, q, "A_Marker", "Marker");
    FillCB(cmbChecker, q, "A_Checker", "Checker");
    FillCB(cmbManageUnit, q, "A_ManageUnit", "ManageUnit");

}

//---------------------------------------------------------------------------



void __fastcall TfmUpdateProp::BitBtn1Click(TObject *Sender)
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);

    int nManageUnitID;
    AnsiString sManageUnitID;
    int nMarkerID;
    int nCheckerID;
    AnsiString sDate;

    if (cmbMaker->Text == "")
    {
        ::MessageBox(this->Handle, "缮证人姓名不能为空！", "警告", MB_ICONERROR)
            ;
        return ;
    }
    if (cmbChecker->Text == "")
    {
        ::MessageBox(this->Handle, "校对人姓名不能为空！", "警告", MB_ICONERROR)
            ;
        return ;
    }
    if (cmbManageUnit->Text == "")
    {
        ::MessageBox(this->Handle, "填发机关不能为空！", "警告", MB_ICONERROR);
        return ;
    }
    //获取填发机关ID
    nManageUnitID = GetID(q, "A_ManageUnit", "RID", "ManageUnit", cmbManageUnit
        ->Text);
    //获取缮证人 ID
    nMarkerID = GetID(q, "A_Marker", "RID", "Marker", cmbMaker->Text);
    //获取校对人ID
    nCheckerID = GetID(q, "A_Checker", "RID", "Checker", cmbChecker->Text);
    //获取日期
    //sDate = FormatDateTime("YYYY.MM.DD", dataSendOutDate->Date);

    //更新所有权信息
    sSql = "update Property_Paper set ";
    sSql += "House_Position='" + edtPosition->Text + "',";
    sSql += "Ground_NO='" + edtGround_No->Text + "',";
    sSql += "remark='" + memRemark->Text + "',";
    sSql += "K_ManageUnit_ID=" + IntToStr(nManageUnitID) + ",";
    sSql += "K_Maker_ID=" + IntToStr(nMarkerID) + ",";
    sSql += "K_Checker_ID=" + IntToStr(nCheckerID);
    //sSql += "SendOutDate='" + sDate + "'";
    sSql += " where Paper_NO ='" + fmPPaper->edtPaper_No->Text + "'";
    ExecuteSql(q, sSql);
    //更新所有权人共有权人表

    sManageUnitID = fmPPaper->qryIndex->FieldByName("K_Owner_NO")->AsString;
    sSql = "update P_Owner set OwnerName='" + edtOwner->Text + "' where RNO=" +
        IntToStr(StrToInt(sManageUnitID));
    ExecuteSql(q, sSql);
    TBookmark mark = fmPPaper->qryIndex->GetBookmark();
    fmPPaper->tableOwner->Active = false;
    fmPPaper->tableOwner->Active = true;
    fmPPaper->qryIndex->Last();
    fmPPaper->qryIndex->GotoBookmark(mark);
    fmPPaper->qryIndex->FreeBookmark(mark);
}

//---------------------------------------------------------------------------
void __fastcall TfmUpdateProp::cmbCheckerKeyPress(TObject *Sender,
      char &Key)
{
    cmbChecker->Text ="";
    Key =0;
}
//---------------------------------------------------------------------------


void __fastcall TfmUpdateProp::cmbMakerKeyPress(TObject *Sender, char &Key)
{
    cmbMaker->Text = "";
    Key =0;
}
//---------------------------------------------------------------------------

void __fastcall TfmUpdateProp::cmbManageUnitKeyPress(TObject *Sender,
      char &Key)
{
    cmbManageUnit->Text = "";
    Key =0;
}
//---------------------------------------------------------------------------

