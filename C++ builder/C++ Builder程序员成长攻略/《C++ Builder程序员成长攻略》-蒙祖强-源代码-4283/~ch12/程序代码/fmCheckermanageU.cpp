/* ���Դ�����ļ��ѱ�δע���SourceFormatX��ʽ���� */
/* ������벻����Ӵ�����Ϣ������ע������������  */
/* ���������Ϣ�������վ: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmCheckermanageU.h"
#include "SysFuncs.h"
#include "dmDataU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmCheckermanage *fmCheckermanage;
//---------------------------------------------------------------------------
__fastcall TfmCheckermanage::TfmCheckermanage(TComponent *Owner): TForm(Owner){}
//---------------------------------------------------------------------------


void __fastcall TfmCheckermanage::actAddExecute(TObject *Sender)
{
    bool nEnableFlagArray[4];
    //tabIndex->Insert();
    edtMarker->Text = "";
    //�жϰ�ť�Ƿ����
    nEnableFlagArray[0] = false;
    nEnableFlagArray[1] = true;

   nEnableFlagArray[2] = false;

    nEnableFlagArray[3] =true;
    EnableButtonFun(nEnableFlagArray);
}

//---------------------------------------------------------------------------

void __fastcall TfmCheckermanage::actPostExecute(TObject *Sender)
{
    int nid =1;
    bool nEnableFlagArray[4];
    AnsiString sSql;
    TADOQuery *q(dmData->qry);

    //�ж���������Ƿ�Ϊ��
    if(edtMarker->Text =="")
    {
       MessageDlg("������ӵ����ݲ���Ϊ�գ� ", mtError,
        TMsgDlgButtons() << mbOK , 0);
        return;
    }

    for(int i = 0 ; i<tabIndex->RecordCount; i++)
    {
       if(nid < tabIndex->FieldByName("K_Checker_ID")->AsInteger)
       {
           nid = tabIndex->FieldByName("K_Checker_ID")->AsInteger ;
       }
    }
    nid++;
        sSql = "insert into A_Checker values("+IntToStr(nid) + ",'" + edtMarker->Text + "')";
    ExecuteSql(q, sSql);
    tabIndex->Active = false;
    tabIndex->Active = true;
    edtMarker->Text = "";

    //�жϰ�ť�Ƿ����
    nEnableFlagArray[0] = true;
    nEnableFlagArray[1] = false;

    nEnableFlagArray[2] = true;
    nEnableFlagArray[3] =false;
    EnableButtonFun(nEnableFlagArray);


}

//---------------------------------------------------------------------------
void __fastcall TfmCheckermanage::actCancleExecute(TObject *Sender)
{
    bool nEnableFlagArray[4];
    edtMarker->Text = "";
    //�жϰ�ť�Ƿ����
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
void __fastcall TfmCheckermanage::tabIndexAfterScroll(TDataSet *DataSet)
{
    bool nEnableFlagArray[4];
    edtMarker->Text = tabIndex->FieldByName("Checker")->AsString;
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
void __fastcall TfmCheckermanage::FormActivate(TObject *Sender)
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


void __fastcall TfmCheckermanage::actDeleteExecute(TObject *Sender)
{
    bool nEnableFlagArray[4];
    if (MessageDlg("ɾ����¼���ɻָ�����ȷ��Ҫɾ���� ", mtError,
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

void __fastcall TfmCheckermanage::ToolButton4Click(TObject *Sender)
{
     Close();
}
//---------------------------------------------------------------------------

void __fastcall TfmCheckermanage::EnableButtonFun(bool nEnableFlagArray[4])
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

