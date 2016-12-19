/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

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
