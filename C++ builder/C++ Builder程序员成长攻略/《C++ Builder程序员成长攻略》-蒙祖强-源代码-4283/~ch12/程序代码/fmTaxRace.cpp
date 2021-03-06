/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmTaxRace.h"
#include "SysFuncs.h"
#include "dmDataU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent *Owner): TForm(Owner){}
//---------------------------------------------------------------------------


void __fastcall TForm1::actPostExecute(TObject *Sender)
{
    int nId;
    TADOQuery *q(dmData->qry);
    nId = GetMaxRecId(q, "A_TaxRace", "K_TaxRace_ID", "0") + 1;
        //产生一个产权人ID
    tabIndex->FieldByName("K_TaxRace_ID")->AsInteger = nId;
    tabIndex->FieldByName("TaxRace")->AsString = edtMarker->Text;
    tabIndex->Post();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::actCancleExecute(TObject *Sender)
{
    tabIndex->Cancel();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::actAddExecute(TObject *Sender)
{
    tabIndex->Append();
    edtMarker->Text = "";
}

//---------------------------------------------------------------------------
void __fastcall TForm1::tabIndexAfterScroll(TDataSet *DataSet)
{
    edtMarker->Text = tabIndex->FieldByName("TaxRace")->AsString;
}

//---------------------------------------------------------------------------
