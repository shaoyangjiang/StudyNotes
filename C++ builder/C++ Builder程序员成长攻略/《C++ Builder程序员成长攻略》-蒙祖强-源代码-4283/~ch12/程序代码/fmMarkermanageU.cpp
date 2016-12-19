/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmMarkermanageU.h"
#include "SysFuncs.h"
#include "dmDataU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmMarkermanage *fmMarkermanage;
//---------------------------------------------------------------------------
__fastcall TfmMarkermanage::TfmMarkermanage(TComponent *Owner): TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TfmMarkermanage::tabIndexAfterScroll(TDataSet *DataSet)
{
    bool nEnableFlagArray[4];
    edtMarker->Text = tabIndex->FieldByName("Marker")->AsString;
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
void __fastcall TfmMarkermanage::actAddExecute(TObject *Sender)
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
void __fastcall TfmMarkermanage::actPostExecute(TObject *Sender)
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
       if(nid < tabIndex->FieldByName("K_Marker_ID")->AsInteger)
       {
           nid = tabIndex->FieldByName("K_Marker_ID")->AsInteger ;
       }
    }
    nid++;
    /*tabIndex->FieldByName("K_Marker_ID")->AsInteger = nid;
    tabIndex->FieldByName("Marker")->AsString = edtMarker->Text;
    tabIndex->Post();*/
    sSql = "insert into  A_Marker  values("+IntToStr(nid) + ",'" + edtMarker->Text + "')";
    ExecuteSql(q, sSql);
    tabIndex->Active = false;
    tabIndex->Active = true;
    edtMarker->Text = "";

    edtMarker->Text = "";

    //判断按钮是否可用
    nEnableFlagArray[0] = true;
    nEnableFlagArray[1] = false;

    nEnableFlagArray[2] = true;
    nEnableFlagArray[3] =false;
    EnableButtonFun(nEnableFlagArray);
}

//---------------------------------------------------------------------------
void __fastcall TfmMarkermanage::actCancleExecute(TObject *Sender)
{
    //tabIndex->Cancel();
    bool nEnableFlagArray[4];

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
void __fastcall TfmMarkermanage::FormActivate(TObject *Sender)
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


void __fastcall TfmMarkermanage::actDeleteExecute(TObject *Sender)
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
void __fastcall TfmMarkermanage::EnableButtonFun(bool nEnableFlagArray[4])
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


void __fastcall TfmMarkermanage::ToolButton4Click(TObject *Sender)
{
   Close();        
}
//---------------------------------------------------------------------------



