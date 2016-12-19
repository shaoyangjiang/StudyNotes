//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmTaxRaceU.h"
#include "SysFuncs.h"
#include "dmDataU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmTaxRace *fmTaxRace;
//---------------------------------------------------------------------------
__fastcall TfmTaxRace::TfmTaxRace(TComponent *Owner): TForm(Owner){}
//---------------------------------------------------------------------------


void __fastcall TfmTaxRace::actPostExecute(TObject *Sender)
{
    int nid =1;
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    bool nEnableFlagArray[4];
    //判断添加内容是否为空
    if(edtMarker->Text =="")
    {
       MessageDlg("你所添加的内容不能为空！ ", mtError,
        TMsgDlgButtons() << mbOK , 0);
        return;
    }
    for(int i = 0 ; i<tabIndex->RecordCount; i++)
    {
       if(nid < tabIndex->FieldByName("K_TaxRace_ID")->AsInteger)
       {
           nid = tabIndex->FieldByName("K_TaxRace_ID")->AsInteger ;
       }
    }
    nid++;

    sSql = "insert into A_TaxRace values("+IntToStr(nid) + ",'" + edtMarker->Text + "')";
    ExecuteSql(q, sSql);
    tabIndex->Active = false;
    tabIndex->Active = true;
    edtMarker->Text = "";

    //判断按钮是否可用
    nEnableFlagArray[0] = true;
    nEnableFlagArray[1] = false;

    nEnableFlagArray[2] = true;
    nEnableFlagArray[3] =false;
    EnableButtonFun(nEnableFlagArray);
}

//---------------------------------------------------------------------------

void __fastcall TfmTaxRace::actCancleExecute(TObject *Sender)
{
    tabIndex->Cancel();
     bool nEnableFlagArray[4];
    //判断按钮是否可用
    nEnableFlagArray[0] = true;
    nEnableFlagArray[1] = false;
    if(tabIndex->RecordCount>0)
    {
        nEnableFlagArray[2] = true;
    }
    else
    {
        nEnableFlagArray[2] = false;
    }
    nEnableFlagArray[2] = true;
    nEnableFlagArray[3] =false;
    EnableButtonFun(nEnableFlagArray);
}

//---------------------------------------------------------------------------
void __fastcall TfmTaxRace::actAddExecute(TObject *Sender)
{

    bool nEnableFlagArray[4];
    //tabIndex->Insert();
    edtMarker->Text = "";
    //判断按钮是否可用
    nEnableFlagArray[0] = false;
    nEnableFlagArray[1] = true;

   nEnableFlagArray[2] = false;

    nEnableFlagArray[3] =true;
    EnableButtonFun(nEnableFlagArray);
}

//---------------------------------------------------------------------------
void __fastcall TfmTaxRace::tabIndexAfterScroll(TDataSet *DataSet)
{   bool nEnableFlagArray[4];
    edtMarker->Text = tabIndex->FieldByName("TaxRace")->AsString;
    nEnableFlagArray[0] = true;
    nEnableFlagArray[1] = false;
    if(tabIndex->RecordCount > 0 )
    {
        nEnableFlagArray[2] = true;
    }
    else
    {
        nEnableFlagArray[2] = false;
    }
    nEnableFlagArray[3] = false;
    EnableButtonFun(nEnableFlagArray);
}

//---------------------------------------------------------------------------
void __fastcall TfmTaxRace::FormActivate(TObject *Sender)
{
    tabIndex->Open();
    bool nEnableFlagArray[4];
    nEnableFlagArray[0] = true;
    nEnableFlagArray[1] = false;
    if(tabIndex->RecordCount > 0 )
    {
        nEnableFlagArray[2] = true;
    }
    else
    {
        nEnableFlagArray[2] = false;
    }
    nEnableFlagArray[3] = false;
    EnableButtonFun(nEnableFlagArray);
}

//---------------------------------------------------------------------------

void __fastcall TfmTaxRace::actDeleteExecute(TObject *Sender)
{
    bool nEnableFlagArray[4];
    if (MessageDlg("删除记录不可恢复，你确定要删除吗？ ", mtError,
        TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk)
    {
        tabIndex->Delete();
    }
    nEnableFlagArray[0] = true;
    nEnableFlagArray[1] = false;
    if(tabIndex->RecordCount > 0 )
    {
        nEnableFlagArray[2] = true;
    }
    else
    {
        nEnableFlagArray[2] = false;
    }
    nEnableFlagArray[3] = false;
    EnableButtonFun(nEnableFlagArray);
}

//---------------------------------------------------------------------------
void __fastcall TfmTaxRace::ToolButton4Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TfmTaxRace::EnableButtonFun(bool nEnableFlagArray[4])
{
  if(nEnableFlagArray[0])
  {
      ToolButton0->Enabled = true;
  }
  else
  {
      ToolButton0->Enabled = false;
  }
  if(nEnableFlagArray[1])
  {
      ToolButton1->Enabled = true;
  }
  else
  {
      ToolButton1->Enabled = false;
  }
  if(nEnableFlagArray[2])
  {
      ToolButton2->Enabled = true;
  }
  else
  {
      ToolButton2->Enabled = false;
  }
  if(nEnableFlagArray[3])
  {
      ToolButton3->Enabled = true;
  }
  else
  {
      ToolButton3->Enabled = false;
  }


}
