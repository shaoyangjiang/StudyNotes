//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmSharePropertyPapU.h"
#include "dmDataU.h"
#include "SysFuncs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "fmVBaseU"
#pragma link "DBCtrlsEh"
#pragma resource "*.dfm"
TfmSharePropertyPap *fmSharePropertyPap;
//---------------------------------------------------------------------------
__fastcall TfmSharePropertyPap::TfmSharePropertyPap(TComponent* Owner)
        : TfmVBase(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmSharePropertyPap::ShowProperty_PaperFun()
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
    AnsiString sSql;
    AnsiString sPaperNO;

    //获得所有权人姓名
    sOwnerId = (qryIndex->FieldByName("K_Owner_NO")->AsString); //获得ID
    sOwnerName = GetNameFieldFromIDFieldS(q, "P_Owner", "OwnerName", "RNO",
        sOwnerId);
    //显示信息
    edtPosition->Text = qryIndex->FieldByName("House_Position")->AsString;
    edtMainOwner->Text = sOwnerName;
    edtPaperNo->Text = qryIndex->FieldByName("Paper_NO")->AsString;
    edtOwnerList->Text = qryIndex->FieldByName("OwnerList")->AsString;
    edtPosition->Text = qryIndex->FieldByName("House_Position")->AsString;
    edtGround_No->Text = qryIndex->FieldByName("Ground_NO")->AsString;

    qryShareOwner->Active = false;
    sPaperNO = qryIndex->FieldByName("Paper_NO")->AsString;

    sSql = "select * from ShareProperty_Paper where K_Paper_NO='" +sPaperNO +"'";
    sSql =sSql + " and RNO ='0'";

    ResultSql(qryShareOwner, sSql);
}
//-----------------------------------------------------------------------------
void __fastcall TfmSharePropertyPap::qryIndexAfterScroll(TDataSet *DataSet)
{
        ClearFormFun();
        ShowProperty_PaperFun();
        if(qryShareOwner->RecordCount==0 )
        {
           ToolButton2->Enabled = false;
           ToolButton3->Enabled = false;
        }
        else
        {
           ToolButton2->Enabled = true;
           ToolButton3->Enabled = true;
        }

        

}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::FormActivate(TObject *Sender)
{    //激活主表
     AnsiString sSql;
     TADOQuery *q(dmData->qry);
    //填充组合框
     qryIndex->Active = true;
     tableOwner->Active = true;
     FillCB(cmbMaker, q, "A_Marker", "Marker");
     
     FillCB(cmbChecker, q, "A_Checker", "Checker");
     
     FillCB(cmbManageUnit, q, "A_ManageUnit", "ManageUnit");

     
     EdtReadFun();
     EdtColorToClBtnFaceFun();
     if(qryIndex->RecordCount == 0)
     {
           ToolButton1->Enabled = false;
           ToolButton2->Enabled = false;
           ToolButton3->Enabled = false;
           ToolButton4->Enabled = false;
           ToolButton5->Enabled = false;
           ToolButton6->Enabled = false;
           ToolButton7->Enabled = false;
     }
}
//---------------------------------------------------------------------------



void __fastcall TfmSharePropertyPap::actAddExecute(TObject *Sender)
{
        TADOQuery *q(dmData->qry);
        edtPaper_No->Text = CreatePaper_NOFun(q);
        g_sPaper_No = edtPaper_No->Text;
        nInsertModifyFlag = 1;

        EdtColorToClWindowFun();
        EdtWriteFun();
        EdtNullFun();
        SetButtonFun();

        
        cmbMaker->Text = cmbMaker->Items->Strings[0];
        cmbChecker->Text = cmbChecker->Items->Strings[0];
        cmbManageUnit->Text = cmbManageUnit->Items->Strings[0];
        
        ToolButton6->Enabled = true;
        ToolButton7->Enabled = true;

        ToolButton1->Enabled = false;
        ToolButton2->Enabled = false;
        ToolButton3->Enabled = false;
        ToolButton4->Enabled = false;
        edtBuildingNum->SetFocus();

        

       

}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::actPostExecute(TObject *Sender)
{

      if(!EnsureDatAvalidFun())
      {
         return;
      }
      if(nInsertModifyFlag == 1)
      {
         InsertShareFun();
      }

         
      if(nInsertModifyFlag == 2)
         UpdateShareFun();

      nInsertModifyFlag = 0;
      tableShareOwner->Active = false;
      tableShareOwner->Active = true;
      qryIndex->Active = false;
      qryIndex->Active = true;

      EdtReadFun();
      EdtColorToClBtnFaceFun();
      EnableButtonFun();
      




}
//---------------------------------------------------------------------------

//插入共有权人信息
void __fastcall TfmSharePropertyPap::InsertShareFun()
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
    nMarkerID = GetID(q, "A_Marker", "RID", "Marker", cmbMaker->Text);

    //获取校对人ID
    nCheckerID = GetID(q, "A_Checker", "RID", "Checker", cmbMaker->Text);

    //获取填发机关ID
    nManageUnitID = GetID(q, "A_ManageUnit", "RID", "ManageUnit",cmbManageUnit->Text);

    //获取栋数
    nBuildingNum = StrToInt(edtBuildingNum->Text);
    //获取间数
    nHourseNum = StrToInt(edtRoomNum->Text);;


    //获取建筑面积
    fHourseArea = StrToFloat(edtAreaNum->Text);

    //获取日期
    sDate = FormatDateTime("YYYY.MM.DD", dataSendOutDate->Date);

    nID = InsertOwnerFun(q,edtOwner->Text, 2);
    //插入共有人信息输入到产权人表  p_Owner  中去

      //把每一个共有权证信息保存到ShareProperty_Paper 共有权证表。
    sSql = "insert into ShareProperty_Paper values(";
    sSql += "'0',"; //ID
    sSql += "'" + edtPaperNo->Text + "',"; //所有权证编号
    sSql += "'" + edtPaper_No->Text + "',"; //共有权证号
    sSql += "'" + IntToStr(nID) + "',"; // 共有人编号
    sSql += edtShare->Text + ","; //共有份额
    sSql += IntToStr(nBuildingNum) + ","; //栋数
    sSql += IntToStr(nHourseNum) + ","; //间数
    sSql += FloatToStr(fHourseArea) + ","; //建筑面积
    sSql += IntToStr(nMarkerID) + ","; //缮证人
    sSql += IntToStr(nCheckerID) + ","; //校对人
    sSql += IntToStr(nManageUnitID) + ","; //填发机关
    sSql +=  "'" + sDate + "',"; //填发日期
    sSql +=  "'" + sDate + "',"; //领证日期
    sSql +=  "'')"; //备注
    ExecuteSql(q, sSql);

    sSql = "update InitFileNo set FileNoStart='" + g_sPaper_No +"'";
    ExecuteSql(q, sSql);

    UpdateOwnerListFun();
}
//-----------------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::qryShareOwnerAfterScroll(
      TDataSet *DataSet)
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    AnsiString sOwnerID;
    int nMarker;
    int nChecker;
    int nManageUnit;
    AnsiString sChecker;
    AnsiString sMarker;
    AnsiString sManageUnit;

    //显示共有权证号
    edtPaper_No->Text = qryShareOwner->FieldByName("ShareProperty_Paper_NO")->AsString;
   //显示栋数
    edtBuildingNum->Text = IntToStr(qryShareOwner->FieldByName("Building")->AsInteger);
    //显示间数
    edtRoomNum->Text = IntToStr(qryShareOwner->FieldByName("Room")->AsInteger);
    //显示面积
    edtAreaNum->Text = FloatToStr(qryShareOwner->FieldByName("Area")->AsFloat);
    //显示占有份额
    edtShare->Text = FloatToStr(qryShareOwner->FieldByName("Share")->AsFloat);

    //显示所有权人姓名
    sOwnerID = qryShareOwner->FieldByName("K_Owner_NO")->AsString ;
    sSql = "select OwnerName from P_Owner where RNO = '" + sOwnerID+"'";
    ResultSql(q, sSql);
    edtOwnerName->Text =q->FieldByName("OwnerName")->AsString;
    edtOwner->Text = edtOwnerName->Text;

    //显示缮证人
    nMarker = qryIndex->FieldByName("K_Maker_ID")->AsInteger;
    sMarker = GetNameFieldFromIDFieldN(q, "A_Marker", "Marker", "RID", nMarker);
    cmbMaker->Text = sMarker;

    //获取校对人
    nChecker = qryIndex->FieldByName("K_Checker_ID")->AsInteger;
    sChecker = GetNameFieldFromIDFieldN(q, " A_Checker", "Checker", "RID",
        nChecker);
    cmbChecker->Text = sChecker;

    //获取日期
    dataSendOutDate->DateTime = qryIndex->FieldByName("SendOutDate")
        ->AsDateTime;

    //获取填发机关
    nManageUnit = qryIndex->FieldByName("K_ManageUnit_ID")->AsInteger;
    sManageUnit = GetNameFieldFromIDFieldN(q, "A_ManageUnit", "ManageUnit",
        "RID", nManageUnit);
    cmbManageUnit->Text = sManageUnit;

}
//--------------------------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::edtOwnerExit(TObject *Sender)
{
      edtOwnerName->Text = edtOwner->Text;
}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::UpdateShareFun()
{
    //

    AnsiString sSql;
    AnsiString sPaperNO;
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
    nMarkerID = GetID(q, "A_Marker", "RID", "Marker", cmbMaker->Text);

    //获取校对人ID
    nCheckerID = GetID(q, "A_Checker", "RID", "Checker", cmbMaker->Text);

    //获取填发机关ID
    nManageUnitID = GetID(q, "A_ManageUnit", "RID", "ManageUnit",cmbManageUnit->Text);

    //获取栋数
    nBuildingNum = StrToInt(edtBuildingNum->Text);
    //获取间数
    nHourseNum = StrToInt(edtRoomNum->Text);;


    //获取建筑面积
    fHourseArea = StrToFloat(edtAreaNum->Text);

    //获取日期
    sDate = FormatDateTime("YYYY.MM.DD", dataSendOutDate->Date);

    //把共有权人姓名更新到P_Owner表中去
    nID = StrToInt(qryShareOwner->FieldByName("K_Owner_NO")->AsString);
    sSql = "update P_Owner set  OwnerName='" + edtOwner->Text+ "'"+ " where RNO="+IntToStr(nID);

    ExecuteSql(q, sSql);

    //共有权人列表更新到所有权证人表中去
   // sPaperNO = qryIndex->FieldByName("Paper_NO")->AsString;
    //sSql = "update Property_Paper set  OwnerList='" + edtOwnerList->Text+ "'"+ " where Paper_NO='" + sPaperNO +"'";
   // ExecuteSql(q, sSql);

    //把每一个共有权证信息保存到ShareProperty_Paper 共有权证表。
    sSql = "update ShareProperty_Paper set ";
    sSql = sSql + "RNO='" + "0" + "',"; //ID
    sSql = sSql + "K_Paper_NO=" + "'" + edtPaperNo->Text + "',"; //所有权证编号
    sSql = sSql + "ShareProperty_Paper_NO=" + "'" + edtPaper_No->Text + "',"; //共有权证号
    sSql = sSql + "K_Owner_NO=" + "'" + IntToStr(nID) + "',"; // 共有人编号
    sSql = sSql + "Share=" + edtShare->Text + ","; //共有份额
    sSql = sSql + "Building=" + IntToStr(nBuildingNum) + ","; //栋数
    sSql = sSql + "Room=" + IntToStr(nHourseNum) + ","; //间数
    sSql = sSql + "Area=" + FloatToStr(fHourseArea) + ","; //建筑面积
    sSql = sSql + "K_Maker_ID=" + IntToStr(nMarkerID) + ","; //缮证人
    sSql = sSql + "K_Checker_ID=" + IntToStr(nCheckerID) + ","; //校对人
    sSql = sSql +  "K_ManageUnit_ID=" + IntToStr(nManageUnitID) + ","; //填发机关
    sSql = sSql +  "SendOutDate=" + "'" + sDate + "',"; //填发日期
    sSql = sSql +  "AcceptDate=" + "'" + sDate + "',"; //领证日期
    sSql = sSql +  "remark="+ "''"; //备注
    sSql = sSql +  "  where  ShareProperty_Paper_NO="+ "'" + edtPaper_No->Text + "'";
    ExecuteSql(q, sSql);

    //sSql = "update Property_Paper  set OwnerList ='" + edtOwnerList
    //    ->Text + "' where Paper_NO='" + edtPaperNo->Text + "'";
    // ShowMessage(sSql);
   // ExecuteSql(q, sSql);
    UpdateOwnerListFun();
}



void __fastcall TfmSharePropertyPap::actEditExecute(TObject *Sender)
{
       nInsertModifyFlag = 2;
       EdtColorToClWindowFun();
       EdtWriteFun();

       SetButtonFun();
       ToolButton6->Enabled = true;
       ToolButton7->Enabled = true;

       ToolButton1->Enabled = false;
       ToolButton2->Enabled = false;
       ToolButton3->Enabled = false;
       ToolButton4->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::actDeleteExecute(TObject *Sender)
{
      AnsiString sSql ;
      AnsiString sPaperNO;
      if (MessageDlg("删除记录不可恢复，你确定要删除吗？ ", mtError,
      TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk)
      {
      sPaperNO = qryShareOwner->FieldByName("ShareProperty_Paper_NO")->AsString;
      TADOQuery *q(dmData->qry);
      sSql = "update ShareProperty_Paper set RNO=";
      sSql = sSql + "'"+"1"+"'" + "where ShareProperty_Paper_NO='"+sPaperNO+"'";
 
      ExecuteSql(q, sSql);

      UpdateOwnerListFun();

      tableShareOwner->Active = false;
      tableShareOwner->Active = true;
      qryIndex->Active = false;
      qryIndex->Active = true;
      }

}
//---------------------------------------------------------------------------





void __fastcall TfmSharePropertyPap::edtOwnerChange(TObject *Sender)
{
      edtOwnerName->Text = edtOwner->Text;        
}
//---------------------------------------------------------------------------
void __fastcall TfmSharePropertyPap::UpdateOwnerListFun()

{
    AnsiString sSql;
    int nOwnerName;
    AnsiString sOwnerName;

    TStringList *sListOwnerNameId = new TStringList();
    //TStringList *sListOwnerName = new TStringList();
    AnsiString sListOwnerName;
    TADOQuery *q(dmData->qry);
    sSql = "select * from ShareProperty_Paper where K_Paper_NO='" + edtPaperNo
        ->Text + "'";

    sSql =sSql + " and RNO ='0'";
    ResultSql(q, sSql);
    q->First();
    for (int i = 0; i < q->RecordCount; i++)
    {
        //获取共有人编号
        nOwnerName = StrToInt((q->FieldByName("K_Owner_NO")->AsString));
        sListOwnerNameId->Add(IntToStr(nOwnerName));
        q->Next();
    }
    sListOwnerName = "";
     for (int i = 0; i < sListOwnerNameId->Count; i++)
    {
        nOwnerName = StrToInt(sListOwnerNameId->Strings[i]);
        sOwnerName = GetNameFieldFromIDFieldN(q, "P_Owner", "OwnerName", "RNO",
            nOwnerName);
       // sListOwnerName->Add(sOwnerName);
        sListOwnerName = sListOwnerName + sOwnerName+" ";
    }
    sSql = "update Property_Paper  set OwnerList ='" + sListOwnerName + "' where Paper_NO='" + edtPaperNo->Text + "'";

    ExecuteSql(q, sSql);
}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::EdtReadFun()
{
    edtBuildingNum->ReadOnly = true;
    edtRoomNum->ReadOnly = true;
    edtAreaNum->ReadOnly = true;
    edtOwner->ReadOnly = true;
    edtShare->ReadOnly = true;
    //cmbMaker->ReadOnly = true;
    //cmbChecker->ReadOnly = true;
    //cmbManageUnit->ReadOnly = true;
    //dataSendOutDate->ReadOnly = true;

}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::EdtWriteFun()
{
    edtBuildingNum->ReadOnly = false;
    edtRoomNum->ReadOnly = false;
    edtAreaNum->ReadOnly = false;
    edtOwner->ReadOnly = false;
    edtShare->ReadOnly = false;
   // cmbMaker->ReadOnly = false;
   // cmbChecker->ReadOnly = false;
    //cmbManageUnit->ReadOnly = false;
    //dataSendOutDate->ReadOnly = false;
}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::EdtNullFun()
{
    edtBuildingNum->Text = "";
    edtRoomNum->Text = "";
    edtAreaNum->Text = "";
    edtOwner->Text = "";
    edtShare->Text = "";
    cmbMaker->Text = "";
    cmbChecker->Text = "";
    cmbManageUnit->Text = "";
    
}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::EdtColorToClWindowFun()
{
    edtBuildingNum->Color = clWindow;
    edtRoomNum->Color = clWindow;
    edtAreaNum->Color = clWindow;
    edtOwner->Color = clWindow;
    edtShare->Color = clWindow;
    cmbMaker->Color = clWindow;
    cmbChecker->Color = clWindow;
    cmbManageUnit->Color = clWindow;
    dataSendOutDate->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::EdtColorToClBtnFaceFun()
{
    edtBuildingNum->Color = clBtnFace;
    edtRoomNum->Color = clBtnFace;
    edtAreaNum->Color = clBtnFace;
    edtOwner->Color = clBtnFace;
    edtShare->Color = clBtnFace;
    cmbMaker->Color = clBtnFace;
    cmbChecker->Color = clBtnFace;
    cmbManageUnit->Color = clBtnFace;
    dataSendOutDate->Color = clBtnFace;
}

void __fastcall TfmSharePropertyPap::ClearFormFun()
{
     edtPaper_No->Text = "";
     edtPosition->Text = "";
     edtGround_No->Text = "";
     edtBuildingNum->Text = "";
     edtRoomNum->Text = "";
     edtAreaNum->Text = "";
     edtOwnerList->Text = "";
     edtOwner->Text = "";
     edtShare->Text = "";
     edtPaperNo->Text = "";
     edtMainOwner->Text = "";
     edtOwnerName->Text = "";
     cmbMaker->Text = "";
     cmbChecker->Text = "";
     cmbManageUnit->Text = "";
}

void __fastcall TfmSharePropertyPap::actCancleExecute(TObject *Sender)
{
      EdtReadFun();
      EdtColorToClBtnFaceFun();
      EnableButtonFun();
}
//---------------------------------------------------------------------------

bool __fastcall TfmSharePropertyPap::EnsureDatAvalidFun()
{
            try
            {
                StrToInt(edtBuildingNum->Text);
            }
            catch (EConvertError *E)
            {
                ::MessageBox(this->Handle, "房屋的幢数必须是一个整数！", "警告", MB_ICONERROR);
                return false;
            }

            try
            {
                StrToInt(edtRoomNum->Text);
            }
            catch (EConvertError *E)
            {
                ::MessageBox(this->Handle, "房屋的间数必须是一个整数！", "警告", MB_ICONERROR);
                return false;
            }

            try
            {
                StrToFloat(edtAreaNum->Text);
            }
            catch (EConvertError *E)
            {
                ::MessageBox(this->Handle, "建筑面积必须是整数或小数！", "警告", MB_ICONERROR);
                return false;
            }

            try
            {
                StrToFloat(edtShare->Text);
            }
            catch (EConvertError *E)
            {
                ::MessageBox(this->Handle, "份额必须是一个整数或小数！", "警告", MB_ICONERROR);
                return false;
            }


            if(cmbMaker->Text =="" )
            {
                ::MessageBox(this->Handle, "必须选择缮证人！", "警告", MB_ICONERROR);

                return false;
            }
            if(cmbChecker->Text =="" )
            {
                ::MessageBox(this->Handle, "必须选择校对人！", "警告", MB_ICONERROR);

                return false;
            }
            if(cmbManageUnit->Text =="" )
            {
                ::MessageBox(this->Handle, "必须选择填发机关！", "警告", MB_ICONERROR);

                return false;
            }

            return true;

}

void __fastcall TfmSharePropertyPap::cmbMakerKeyPress(TObject *Sender,
      char &Key)
{
       Key = 0;        
}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::cmbCheckerKeyPress(TObject *Sender,
      char &Key)
{
           Key = 0;        
}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::cmbManageUnitKeyPress(TObject *Sender,
      char &Key)
{
     Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::SetButtonFun()
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
void __fastcall TfmSharePropertyPap::EnableButtonFun()
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


void __fastcall TfmSharePropertyPap::ToolButton8Click(TObject *Sender)
{
   Close();        
}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::PrintShareFun()
{
  TStringList *ListShare = new TStringList;
  AnsiString sDate;
  AnsiString sPath;
  ListShare->Add(edtPaper_No->Text);
  ListShare->Add(edtPosition->Text);
  ListShare->Add(edtGround_No->Text);
  ListShare->Add(edtBuildingNum->Text);
  ListShare->Add(edtRoomNum->Text);
  ListShare->Add(edtAreaNum->Text);
  ListShare->Add(edtOwnerList->Text);
  ListShare->Add(edtOwner->Text);
  ListShare->Add(edtShare->Text);
  ListShare->Add(edtFile->Text);
  ListShare->Add(edtPaperNo->Text);
  ListShare->Add(edtMainOwner->Text);
  ListShare->Add(edtOwnerName->Text);
  ListShare->Add(cmbMaker->Text);
  ListShare->Add(cmbChecker->Text);
  ListShare->Add(cmbManageUnit->Text);
  sDate = FormatDateTime("YYYY-MM-DD", dataSendOutDate->Date);
  ListShare->Add(sDate.SubString(1,4) );
  ListShare->Add(sDate.SubString(6,2) );
  ListShare->Add(sDate.SubString(9,2) );
  sPath = ExtractFilePath(Application->ExeName);
  sPath = sPath + "outShare\\txt\\SharePaper1.txt";
  ListShare->SaveToFile(sPath);


}


void __fastcall TfmSharePropertyPap::ToolButton10Click(TObject *Sender)
{ AnsiString sPath;
  PrintShareFun();
  sPath = ExtractFilePath(Application->ExeName);
  sPath = sPath + "outShare\\PrintPaperMain.exe";
  //ShowMessage(sPath);
  ShellExecute(Handle,"open",sPath.c_str(),0,0,SW_SHOWDEFAULT	);

}
//---------------------------------------------------------------------------

void __fastcall TfmSharePropertyPap::edtLocateKeyPress(TObject *Sender,
      char &Key)
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

void __fastcall TfmSharePropertyPap::SpeedButton10Click(TObject *Sender)
{
    TLocateOptions Opts;
    Opts.Clear();
    Opts << loPartialKey;
    bool a = qryIndex->Locate("Paper_NO", edtLocate->Text, Opts);

}
//---------------------------------------------------------------------------



