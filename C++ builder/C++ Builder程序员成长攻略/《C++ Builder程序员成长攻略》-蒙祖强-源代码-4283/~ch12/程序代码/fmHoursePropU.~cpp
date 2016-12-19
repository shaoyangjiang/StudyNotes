/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

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
    this->panPaperNo->Caption = "桂房证字第：" + fmPPaper->edtPaper_No->Text +
        "号";
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


    //for循环判断在 gridPropertyHourse中一共有多少栋房子
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

    //获取房子栋数
    //把每一栋房子添加到数据库表   P_HouseProperty屋状况表   中去
    for (int i = 0; i < nHourseNum; i++)
    {
        sSql = "insert into P_HouseProperty values(";
        sSql += "'0',"; //ID
        sSql += "'" + fmPPaper->edtPaper_No->Text + "',"; //房产证号
        sSql += "'" + gridPropertyHourse->Cells[0][i] + "',"; //栋号
        sSql += "'" + gridPropertyHourse->Cells[1][i] + "',"; //房号
        sSql += gridPropertyHourse->Cells[2][i] + ","; //间数
        sSql += "'" + gridPropertyHourse->Cells[3][i] + "',"; //建筑结构
        sSql += gridPropertyHourse->Cells[4][i] + ","; //层数
        sSql += gridPropertyHourse->Cells[5][i] + ","; //建筑面积
        sSql += "'" + gridPropertyHourse->Cells[6][i] + "')"; //备注
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
//---------------------------------------------------------------------------
