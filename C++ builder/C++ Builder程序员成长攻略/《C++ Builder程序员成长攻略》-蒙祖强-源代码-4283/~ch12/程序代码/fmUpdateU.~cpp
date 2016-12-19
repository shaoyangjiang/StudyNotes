/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmUpdateU.h"
#include "fmUpdatePropU.h"
#include "fmHoursePropU.h"
#include "fmSharePropU.h"
#include "fmUpdateTaxU.h"
#include "fmUpDateGroundPropU.h"
#include "fmUpdateOtherPropU.h"
#include "fmUpdateTaxU.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmUpdate *fmUpdate;
//---------------------------------------------------------------------------
__fastcall TfmUpdate::TfmUpdate(TComponent *Owner): TForm(Owner){}
//---------------------------------------------------------------------------














void __fastcall TfmUpdate::SpeedButton4Click(TObject *Sender)
{
    Application->CreateForm(__classid(TfmUpdateTax), &fmUpdateTax);
    fmUpdateTax->ShowModal();
}

//---------------------------------------------------------------------------

void __fastcall TfmUpdate::SpeedButton1Click(TObject *Sender)
{
    Application->CreateForm(__classid(TfmUpdateTax), &fmUpdateTax);
    fmUpdateTax->ShowModal();
}

//---------------------------------------------------------------------------





void __fastcall TfmUpdate::SpeedButton10Click(TObject *Sender)
{     Application->CreateForm(__classid(TfmUpdateProp), &fmUpdateProp);
    fmUpdateProp->ShowModal();
}

//---------------------------------------------------------------------------


void __fastcall TfmUpdate::Panel3Click(TObject *Sender)
{
    Application->CreateForm(__classid(TfmUpDateGroundProp), &fmUpDateGroundProp)
        ;
    fmUpDateGroundProp->ShowModal();
}

//---------------------------------------------------------------------------

void __fastcall TfmUpdate::SpeedButton12Click(TObject *Sender)
{
    Application->CreateForm(__classid(TfmHourseProp), &fmHourseProp);
    fmHourseProp->ShowModal();

}

//---------------------------------------------------------------------------

void __fastcall TfmUpdate::SpeedButton14Click(TObject *Sender)
{
    Application->CreateForm(__classid(TfmUpDateGroundProp), &fmUpDateGroundProp)
        ;
    fmUpDateGroundProp->ShowModal();
}

//---------------------------------------------------------------------------
void __fastcall TfmUpdate::Image1DblClick(TObject *Sender)
{
    Close();        
}
//---------------------------------------------------------------------------

