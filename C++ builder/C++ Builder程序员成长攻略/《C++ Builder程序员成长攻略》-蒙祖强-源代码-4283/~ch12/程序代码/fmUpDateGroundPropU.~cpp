/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

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

        ::MessageBox(this->Handle, "土地面积只能为小数或整数！", "警告",
            MB_ICONERROR);
        return ;
    }
     try
    {
        StrToFloat(edtUsedArea->Text);
    }
    catch (EConvertError *E)
    {

        ::MessageBox(this->Handle, "土地面积只能为小数或整数！", "警告",
            MB_ICONERROR);
        return ;
    }
    if(edtFileNo->Text == "")
    {
        ::MessageBox(this->Handle, "土地使用正号不能为空！", "警告",
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
        sSql += "'0',"; // 唯一的内部编号
        sSql += "'" + fmPPaper->edtPaper_No->Text + "',"; // 所有权证编号
        sSql += "'桂房证',"; // 土地使用证字
        sSql += "'" + edtFileNo->Text + "',"; // 土地使用证号
        sSql += "'" + edtUsedAreaM2->Text + "',"; // 使用国有土地面积（平方米）
        sSql += "'" + edtUsedArea->Text + "',"; // 使用国有土地面积（亩）
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
    this->panPaperNo->Caption = "桂房证字第：" + fmPPaper->edtPaper_No->Text +
        "号";


}

//---------------------------------------------------------------------------

