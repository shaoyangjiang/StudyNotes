/* ���Դ�����ļ��ѱ�δע���SourceFormatX��ʽ���� */
/* ������벻����Ӵ�����Ϣ������ע������������  */
/* ���������Ϣ�������վ: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmVBaseU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmVBase *fmVBase;
//---------------------------------------------------------------------------
__fastcall TfmVBase::TfmVBase(TComponent *Owner): TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TfmVBase::ToolButton4Click(TObject *Sender)
{
    ////:
}

//---------------------------------------------------------------------------
void __fastcall TfmVBase::actEditExecute(TObject *Sender)
{
    qryMain->Edit();
}

//---------------------------------------------------------------------------
void __fastcall TfmVBase::actDeleteExecute(TObject *Sender)
{
    qryMain->Delete();
}

//---------------------------------------------------------------------------
void __fastcall TfmVBase::actSearchExecute(TObject *Sender)
{
    ///
}

//---------------------------------------------------------------------------
void __fastcall TfmVBase::actPostExecute(TObject *Sender)
{
    qryMain->Post();
}

//---------------------------------------------------------------------------
void __fastcall TfmVBase::actCancleExecute(TObject *Sender)
{
    qryMain->Cancel();
}

//---------------------------------------------------------------------------
void __fastcall TfmVBase::actAddExecute(TObject *Sender)
{
    qryMain->Append();
}

//---------------------------------------------------------------------------
