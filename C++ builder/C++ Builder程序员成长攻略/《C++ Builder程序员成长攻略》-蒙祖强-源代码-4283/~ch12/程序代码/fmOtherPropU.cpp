//---------------------------------------------------------------------------
 
#include <vcl.h>
#pragma hdrstop

#include "fmOtherPropU.h"
#include "dmDataU.h"
#include "SysFuncs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "fmVBaseU"
#pragma link "DBCtrlsEh"
#pragma link "DBCtrlsEh"
#pragma resource "*.dfm"
TfmOtherProp *fmOtherProp;
//---------------------------------------------------------------------------
__fastcall TfmOtherProp::TfmOtherProp(TComponent* Owner)
        : TfmVBase(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfmOtherProp::qryIndexAfterScroll(TDataSet *DataSet)
{
    AnsiString sSql ;
    AnsiString sPaperNO;
    TADOQuery *q(dmData->qry);
    int nAllBuilding = 0;//幢数
    int nAllRoom = 0;   //房间数
    int fAllArea =0.0;    //面积

    cmbMaker->Text = "";
    cmbChecker->Text = "";

    sPaperNO = qryIndex->FieldByName("Paper_NO")->AsString;
    edtPaper_No->Text = sPaperNO;
    sSql = "select * from OtherProperty_Paper where K_P_Paper_NO='" +sPaperNO +"'";
    ResultSql(qryOther, sSql);
     sSql = "select * from  P_HouseProperty where Paper_NO='" +sPaperNO +"'";
    ResultSql(q, sSql);
    q->First();
    for(int i = 0; i < q->RecordCount;i++)
    {
         nAllBuilding++;//  幢数+1
         nAllRoom += q->FieldByName("Room")->AsInteger;//  获取房间数
         fAllArea += q->FieldByName("Structure_Area")->AsFloat;  //获取建筑面积
         q->Next();
    }
    txtAllBuilding->Caption = IntToStr(nAllBuilding);
    txtAllRoom->Caption = IntToStr(nAllRoom);
    txtAllArea->Caption = IntToStr(fAllArea);
   
        if(qryOther->RecordCount==0 )
        {
           ToolButton2->Enabled = false;
           ToolButton3->Enabled = false;
           ToolButton8->Enabled = false;

        }
        else
        {
           ToolButton2->Enabled = true;
           ToolButton3->Enabled = true;
           ToolButton8->Enabled = true;



        }

        if(qryIndex->RecordCount == 0)
        {
           ToolButton1->Enabled = false;
           ToolButton2->Enabled = false;
           ToolButton3->Enabled = false;
           ToolButton4->Enabled = false;
           ToolButton5->Enabled = false;
           ToolButton6->Enabled = false;
           ToolButton7->Enabled = false;
           ToolButton8->Enabled = false;
        }
      if(qryOther->RecordCount == 0)
      {
           imgLog->Visible = false;
           imgUnlog->Visible = false;
           ToolButton8->Enabled = true;
           LabLogFlag->Visible =false;
           return;
      }
      if(qryOther->RecordCount>0)
      {
      AnsiString sCheckDate = DateToStr(qryOther->FieldByName("CheckOffDate")->AsDateTime); //注销期限
      if(sCheckDate=="1899-12-30"||sCheckDate=="1899.12.30")
      {
          imgLog->Visible = true;
          imgUnlog->Visible = false;
          ToolButton8->Enabled = true;
          LabLogFlag->Visible =false;

      }
      else
      {
           imgLog->Visible = false;
           imgUnlog->Visible = true;
           ToolButton8->Enabled = false;
           LabLogFlag->Visible = true;
      }
    }

   gridOther->Visible = true;
   EdtReadFun();
   EdtColorToClBtnFaceFun();
   ToolButton6->Enabled =false;

    if(qryOther->RecordCount ==0)
   {
     ToolButton11->Enabled =false;
   }
   else
   {
     ToolButton11->Enabled =true;
   }

}
//---------------------------------------------------------------------------
void __fastcall TfmOtherProp::FormActivate(TObject *Sender)
{
     AnsiString sSql;
     TADOQuery *q(dmData->qry);
     //激活主表
     tableOwner->Active = true;
     qryIndex->Active = true;

   // sSql = "select TaxRace from A_TaxRace order by TaxRace";
    //ResultSql(q, sSql);
    //dbEdtTaxRace->Items->Clear();
   //while (!q->Eof)
   // {
     //   dbEdtTaxRace->Items->Add(q->Fields->Fields[0]->AsString);
    //    q->Next();
   // }

     //填充组合框
     FillCB(cmbMaker, q, "A_Marker", "Marker");
     
     FillCB(cmbChecker, q, "A_Checker", "Checker");
     
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
           ToolButton8->Enabled = false;
        }

}
//---------------------------------------------------------------------------
void __fastcall TfmOtherProp::actAddExecute(TObject *Sender)
{
        gridOther->Visible = false;
        //获取他项权利证号
        AnsiString sPaper_NO;
        TADOQuery *q(dmData->qry);
        sPaper_NO = CreatePaper_NOFun(q);
        g_sPaper_No =  sPaper_NO;
        edtPaper_No->Text = sPaper_NO;
        qryOther->Insert();

        EdtWriteFun();
        EdtColorToClWindowFun();

        SetButtonFun();
        ToolButton6->Enabled =true;
        ToolButton7->Enabled =true;

        ToolButton1->Enabled = false;
        ToolButton2->Enabled = false;
        ToolButton3->Enabled = false;
        ToolButton4->Enabled = false;
        ToolButton8->Enabled = false;

        Label27->Visible = true;
        Label28->Visible = true;
        Label29->Visible = true;
        //Label30->Visible = true;
        Label31->Visible = true;
        Label32->Visible = true;
        cmbMaker->Text =  cmbMaker->Items->Strings[0];
        cmbChecker->Text =  cmbChecker->Items->Strings[0];
        dbEdtObligee->SetFocus();
        




}
//---------------------------------------------------------------------------

void __fastcall TfmOtherProp::actPostExecute(TObject *Sender)
{
    //插入记录
   //获取所有权证号
   int  nMarkerID;
   int  nCheckerID;
   AnsiString sK_P_Paper_NO;
   AnsiString sSql;
   TADOQuery *q(dmData->qry);

   if(!EnsureDatAvalidFun())
   {
     return;
   }
   
   sK_P_Paper_NO = qryIndex->FieldByName("Paper_NO")->AsString;


   //获取缮证人 ID
    nMarkerID = GetID(q, "A_Marker", "RID", "Marker", cmbMaker->Text);
    //获取校对人ID

    nCheckerID = GetID(q, "A_Checker", "RID", "Checker", cmbChecker->Text);
   //插入记录
   qryOther->FieldByName("RNO")->AsString = "0";
   qryOther->FieldByName("Paper_NO")->AsString = edtPaper_No->Text;
   qryOther->FieldByName("K_P_Paper_NO")->AsString =  sK_P_Paper_NO;

   qryOther->FieldByName("K_Check_ID")->AsInteger =  nCheckerID;
   qryOther->FieldByName("K_Marker_ID")->AsInteger =  nMarkerID;
   if(qryOther->State == dsInsert)
   {
         sSql = "update InitFileNo set FileNoStart='" + g_sPaper_No +"'";
         ExecuteSql(q, sSql);
   }
   //界面整理
   qryOther->Post();
   
   gridOther->Visible = true;
   EdtReadFun();
   EdtColorToClBtnFaceFun();
   EnableButtonFun();
   Label27->Visible = false;
   Label28->Visible = false;
   Label29->Visible = false;
   //Label30->Visible = false;
   Label31->Visible = false;
   Label32->Visible = false;


}
//---------------------------------------------------------------------------

void __fastcall TfmOtherProp::actCancleExecute(TObject *Sender)
{  //取消
   qryOther->Cancel();
   gridOther->Visible = true;
   EdtReadFun();
   EdtColorToClBtnFaceFun();
   EnableButtonFun();
   Label27->Visible = false;
   Label28->Visible = false;
   Label29->Visible = false;
   //Label30->Visible = false;
   Label31->Visible = false;
   Label32->Visible = false;



}
//---------------------------------------------------------------------------


void __fastcall TfmOtherProp::actEditExecute(TObject *Sender)
{
   qryOther->Edit();
   gridOther->Visible = true;
  
   EdtWriteFun();
   EdtColorToClWindowFun();
   SetButtonFun();
   ToolButton6->Enabled =true;
   ToolButton7->Enabled =true;

   ToolButton1->Enabled = false;
   ToolButton2->Enabled = false;
   ToolButton3->Enabled = false;
   ToolButton4->Enabled = false;
   ToolButton8->Enabled = false;
   Label27->Visible = true;
   Label28->Visible = true;
   Label29->Visible = true;
   //Label30->Visible = true;
   Label31->Visible = true;
   Label32->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfmOtherProp::qryOtherAfterScroll(TDataSet *DataSet)
{
  TADOQuery *q(dmData->qry);

    int nMarker = 0;
    int nChecker = 0;

    AnsiString sChecker;
    AnsiString sMarker;
    cmbMaker->Text = "";
    cmbChecker->Text = "";

  //显示缮证人
    nMarker = qryOther->FieldByName("K_Marker_ID")->AsInteger;
    sMarker = GetNameFieldFromIDFieldN(q, "A_Marker", "Marker", "RID", nMarker);
    cmbMaker->Text = sMarker;

   //获取校对人
    nChecker = qryOther->FieldByName("K_Check_ID")->AsInteger;
    sChecker = GetNameFieldFromIDFieldN(q, " A_Checker", "Checker", "RID",nChecker);
    cmbChecker->Text =  sChecker;

   gridOther->Visible = true;
   EdtReadFun();
   EdtColorToClBtnFaceFun();
   ToolButton6->Enabled =false;
   if(qryOther->RecordCount ==0)
   {
     ToolButton11->Enabled =false;
   }
   else
   {
     ToolButton11->Enabled =true;
   }
     // if()
      AnsiString sCheckDate = DateToStr(qryOther->FieldByName("CheckOffDate")->AsDateTime); //注销期限
      if(sCheckDate=="1899-12-30"||sCheckDate=="1899.12.30")
      {
          imgLog->Visible = true;
          imgUnlog->Visible = false;

          if(qryOther->RecordCount == 0)
          {

              LabLogFlag->Visible =false;
              imgLog->Visible = false;
              imgUnlog->Visible = false;
              return;
          }

          if(qryOther->RecordCount>0)
          {
              ToolButton8->Enabled = true;
          }

          LabLogFlag->Visible =false;

      }
      else
      {
           imgLog->Visible = false;
           imgUnlog->Visible = true;
           ToolButton8->Enabled = false;
           LabLogFlag->Visible = true;
      }
   Label27->Visible = false;
   Label28->Visible = false;
   Label29->Visible = false;
   //Label30->Visible = false;
   Label31->Visible = false;
   Label32->Visible = false;
      


}
//---------------------------------------------------------------------------

void __fastcall TfmOtherProp::actDeleteExecute(TObject *Sender)
{
   if (MessageDlg("删除记录不可恢复，你确定要删除吗？ ", mtError,
      TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk)
   {
      qryOther->Edit();
      qryOther->Delete();
      qryIndex->Active ==false;
      qryIndex->Active ==true;
   }

}
//---------------------------------------------------------------------------



void __fastcall TfmOtherProp::EdtColorToClWindowFun()
{
   dbEdtObligee->Color =clWindow;
   dbEdtPropertyType->Color= clWindow;
   dbEdtBuilding->Color= clWindow;
   dbEdtDoorplate->Color= clWindow;
   dbEdtRoom->Color= clWindow;
   dbEdtArea->Color= clWindow;
   dbEdtValue->Color= clWindow;
   dbEdtAvailable->Color= clWindow;
   dbEdtTaxRace->Color= clWindow;
   dbedtTax->Color= clWindow;
   cmbMaker->Color= clWindow;
   cmbChecker->Color= clWindow;
}

//---------------------------------------------------------------------------
void __fastcall TfmOtherProp::EdtColorToClBtnFaceFun()
{
   dbEdtObligee->Color =clBtnFace;
   dbEdtPropertyType->Color= clBtnFace;
   dbEdtBuilding->Color= clBtnFace;
   dbEdtDoorplate->Color= clBtnFace;
   dbEdtRoom->Color= clBtnFace;
   dbEdtArea->Color= clBtnFace;
   dbEdtValue->Color= clBtnFace;
   dbEdtAvailable->Color= clBtnFace;
   dbEdtTaxRace->Color= clBtnFace;
   dbedtTax->Color= clBtnFace;
   cmbMaker->Color= clBtnFace;
   cmbChecker->Color= clBtnFace;
 }

 //----------------------------------------------------------------------------
void __fastcall TfmOtherProp::EdtReadFun()
{
   dbEdtObligee->ReadOnly = true;
   dbEdtPropertyType->ReadOnly = true;
   dbEdtBuilding->ReadOnly = true;
   dbEdtDoorplate->ReadOnly = true;
   dbEdtRoom->ReadOnly = true;
   dbEdtArea->ReadOnly = true;
   dbEdtValue->ReadOnly = true;
   dbEdtAvailable->ReadOnly = true;
   dbEdtTaxRace->ReadOnly = true;
   dbedtTax->ReadOnly = true;
}
//-----------------------------------------------------------------------------
void __fastcall TfmOtherProp::EdtWriteFun()
{
   dbEdtObligee->ReadOnly = false;
   dbEdtPropertyType->ReadOnly = false;
   dbEdtBuilding->ReadOnly = false;
   dbEdtDoorplate->ReadOnly = false;
   dbEdtRoom->ReadOnly = false;
   dbEdtArea->ReadOnly = false;
   dbEdtValue->ReadOnly = false;
   dbEdtAvailable->ReadOnly = false;
   dbEdtTaxRace->ReadOnly = false;
   dbedtTax->ReadOnly = false;
}
//----------------------------------------------------------------------------


bool __fastcall TfmOtherProp::EnsureDatAvalidFun()
{

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
    return true;

}
//-----------------------------------------------------------------------
void __fastcall TfmOtherProp::cmbMakerKeyPress(TObject *Sender, char &Key)
{
     Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfmOtherProp::cmbCheckerKeyPress(TObject *Sender, char &Key)
{
     Key = 0;
}
//---------------------------------------------------------------------------



void __fastcall TfmOtherProp::ToolButton8Click(TObject *Sender)
{
     if (MessageDlg("注销后他项权将失效，你确定要注销吗？ ", mtError,
      TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk)
     {
        qryOther->Edit();
        AnsiString sDate = FormatDateTime("YYYY-MM-DD", Now());
        qryOther->FieldByName("CheckOffDate")->AsString=sDate;
        qryOther->Post();
     }

}
//---------------------------------------------------------------------------
void __fastcall TfmOtherProp::SetButtonFun()
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
void __fastcall TfmOtherProp::EnableButtonFun()
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



void __fastcall TfmOtherProp::ToolButton9Click(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------

void __fastcall TfmOtherProp::PrintPaper1Fun()
{
    TStringList *OtherList = new TStringList;
    AnsiString sNames;
    AnsiString sPath;
    OtherList->Add(qryIndex->FieldByName("House_Position")->Value);

    OtherList->Add(qryIndex->FieldByName("Ground_NO")->Value);

    OtherList->Add(qryOther->FieldByName("Obligee")->Value);

    OtherList->Add(qryOther->FieldByName("PropertyType")->Value);

    OtherList->Add(qryOther->FieldByName("K_House_NO")->Value);

    OtherList->Add(qryOther->FieldByName("Doorplate")->Value);

    OtherList->Add(qryOther->FieldByName("Room")->Value);

    OtherList->Add(qryOther->FieldByName("StructureArea")->Value);

    OtherList->Add(qryOther->FieldByName("R_Value")->Value);

    OtherList->Add(qryOther->FieldByName("Available")->Value);

    OtherList->Add(qryOther->FieldByName("TaxRace")->Value);

    OtherList->Add(qryOther->FieldByName("Tax")->Value);

    sNames = qryIndex->FieldByName("姓名")->Value;
    sNames = sNames+"  ";
    sNames = sNames+qryIndex->FieldByName("OwnerList")->Value;
    OtherList->Add(sNames);
    OtherList->Add(txtAllBuilding->Caption);
    OtherList->Add(txtAllRoom->Caption);
    OtherList->Add(txtAllArea->Caption);
    OtherList->Add(qryIndex->FieldByName("Remark")->Value);
    OtherList->Add(cmbMaker->Text);
    OtherList->Add(cmbChecker->Text);
    OtherList->Add("桂房证");
    OtherList->Add(edtPaper_No->Text);
    sPath = ExtractFilePath(Application->ExeName);
    sPath = sPath + "outother\\txt\\Share.txt";
    OtherList->SaveToFile(sPath);


//
}
void __fastcall TfmOtherProp::ToolButton11Click(TObject *Sender)
{
   AnsiString sPath;
   PrintPaper1Fun();
   sPath = ExtractFilePath(Application->ExeName);
   sPath = sPath + "outother\\PrintPaperMain.exe";
   //sPath ="D:\\房屋管理2\\房屋管理\\房屋管理\\房屋管理\\Otherpaper\\PrintPaperMain.exe";
   ShellExecute(Handle,"open",sPath.c_str(),0,0,SW_SHOWDEFAULT	);


}
//---------------------------------------------------------------------------





void __fastcall TfmOtherProp::SpeedButton10Click(TObject *Sender)
{
   TLocateOptions Opts;
    Opts.Clear();
    Opts << loPartialKey;
    qryIndex->Locate("Paper_NO", edtLocate->Text, Opts);
}
//---------------------------------------------------------------------------

void __fastcall TfmOtherProp::edtLocateKeyPress(TObject *Sender, char &Key)
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












