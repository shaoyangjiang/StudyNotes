//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "SysFuncs.h"
#include "dmDataU.h"
#include "fmManageUnitU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmManageUnit *fmManageUnit;
//---------------------------------------------------------------------------
__fastcall TfmManageUnit::TfmManageUnit(TComponent *Owner): TForm(Owner){}
//---------------------------------------------------------------------------

void __fastcall TfmManageUnit::actAddExecute(TObject *Sender)
{
   bool nEnableFlagArray[4];

    edtMarker->Text = "";

    //判断按钮是否可用
    nEnableFlagArray[0] = false;
    nEnableFlagArray[1] = true;

   nEnableFlagArray[2] = false;

    nEnableFlagArray[3] =true;
    EnableButtonFun(nEnableFlagArray);
}

//---------------------------------------------------------------------------

void __fastcall TfmManageUnit::actPostExecute(TObject *Sender)
{
    int nid =1;
    bool nEnableFlagArray[4];
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    //判断添加内容是否为空
    if(edtMarker->Text =="")
    {
       MessageDlg("你所添加的内容不能为空！ ", mtError,
        TMsgDlgButtons() << mbOK , 0);
        return;
    }

    for(int i = 0 ; i<tabIndex->RecordCount; i++)
    {
       if(nid < tabIndex->FieldByName("K_ManageUnit_ID")->AsInteger)
       {
           nid = tabIndex->FieldByName("K_ManageUnit_ID")->AsInteger ;
       }
    }
    nid++;
    sSql = "insert into  A_ManageUnit  values("+IntToStr(nid) + ",'" + edtMarker->Text + "')";
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

void __fastcall TfmManageUnit::actCancleExecute(TObject *Sender)
{
    bool nEnableFlagArray[4];
   // tabIndex->Cancel();
    edtMarker->Text = "";
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
void __fastcall TfmManageUnit::tabIndexAfterScroll(TDataSet *DataSet)
{
    bool nEnableFlagArray[4];
    edtMarker->Text = tabIndex->FieldByName("ManageUnit")->AsString;
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
void __fastcall TfmManageUnit::FormActivate(TObject *Sender)
{
    bool nEnableFlagArray[4];
    tabIndex->Open();
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



void __fastcall TfmManageUnit::actDeleteExecute(TObject *Sender)
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
void __fastcall TfmManageUnit::ToolButton4Click(TObject *Sender)
{
    Close();        
}
//---------------------------------------------------------------------------
 void __fastcall TfmManageUnit::EnableButtonFun(bool nEnableFlagArray[4])
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


