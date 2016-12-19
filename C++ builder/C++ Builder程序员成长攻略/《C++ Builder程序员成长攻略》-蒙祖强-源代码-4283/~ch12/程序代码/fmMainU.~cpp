/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "dmDataU.h"
#include "SysFuncs.h"
#include "fmMainU.h"
#include "fmPPaperU.h"
#include "fmMarkermanageU.h"
#include "fmCheckermanageU.h"
#include "fmManageUnitU.h"
#include "fmTaxTypeU.h"
#include "fmTaxRaceU.h"
#include "fmInitFileNoU.h"
#include "fmSharePropertyPapU.h"
#include "fmOtherPropU.h"
#include "fmAboutU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmMain *fmMain;
//---------------------------------------------------------------------------
__fastcall TfmMain::TfmMain(TComponent *Owner): TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TfmMain::actExitExecute(TObject *Sender)
{
    this->Close();
}

//---------------------------------------------------------------------------

void __fastcall TfmMain::MenuPaperClick(TObject *Sender)
{
    Application->CreateForm(__classid(TfmPPaper), &fmPPaper);
    fmPPaper->ShowModal();
}

//---------------------------------------------------------------------------
void __fastcall TfmMain::N5Click(TObject *Sender)
{
    Application->CreateForm(__classid(TfmMarkermanage), &fmMarkermanage);
    fmMarkermanage->ShowModal();
    EnsureMenu();
}

//---------------------------------------------------------------------------
void __fastcall TfmMain::N6Click(TObject *Sender)
{
    Application->CreateForm(__classid(TfmCheckermanage), &fmCheckermanage);
    fmCheckermanage->ShowModal();
    EnsureMenu();
}

//---------------------------------------------------------------------------
void __fastcall TfmMain::N9Click(TObject *Sender)
{
    Application->CreateForm(__classid(TfmManageUnit), &fmManageUnit);
    fmManageUnit->ShowModal();
    EnsureMenu();
}

//---------------------------------------------------------------------------

void __fastcall TfmMain::N7Click(TObject *Sender)
{

    Application->CreateForm(__classid(TfmTaxType), &fmTaxType);
    fmTaxType->ShowModal();
    EnsureMenu();
}

//---------------------------------------------------------------------------

void __fastcall TfmMain::N8Click(TObject *Sender)
{

    Application->CreateForm(__classid(TfmTaxRace), &fmTaxRace);
    fmTaxRace->ShowModal();
    EnsureMenu();
}

//---------------------------------------------------------------------------
void __fastcall TfmMain::MenuShareClick(TObject *Sender)
{
    Application->CreateForm(__classid(TfmSharePropertyPap), &fmSharePropertyPap);
    fmSharePropertyPap->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::MenuOtherClick(TObject *Sender)
{
    Application->CreateForm(__classid(TfmOtherProp), &fmOtherProp);
    fmOtherProp->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::N2Click(TObject *Sender)
{
     fmAbout->ShowModal();
}
//---------------------------------------------------------------------------








void __fastcall TfmMain::EnsureMenu()
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    sSql = "select * from A_TaxRace" ;
    ResultSql(q, sSql);
    if (q->RecordCount == 0)
    {
          return;

    }
    sSql = "select * from A_TaxType" ;
    ResultSql(q, sSql);
    if (q->RecordCount == 0)
    {

          return;

    }
    sSql = "select * from A_Checker" ;
    ResultSql(q, sSql);
    if (q->RecordCount == 0)
    {

          return;

    }
    sSql = "select * from A_Marker" ;
    ResultSql(q, sSql);
    if (q->RecordCount == 0)
    {

          return;

    }
    sSql = "select * from A_ManageUnit" ;
    ResultSql(q, sSql);
    if (q->RecordCount == 0)
    {

          return;

    }
    MenuPaper->Enabled =  true;
    MenuShare->Enabled = true;
    MenuOther->Enabled = true;

}
void __fastcall TfmMain::FormShow(TObject *Sender)
{
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    sSql = "select * from A_TaxRace" ;
    ResultSql(q, sSql);
    if (q->RecordCount == 0)
    {
          MenuPaper->Enabled =  false;
          MenuShare->Enabled = false;
          MenuOther->Enabled = false;

    }
    sSql = "select * from A_TaxType" ;
    ResultSql(q, sSql);
    if (q->RecordCount == 0)
    {

          MenuPaper->Enabled =  false;
          MenuShare->Enabled = false;
          MenuOther->Enabled = false;

    }
    sSql = "select * from A_Checker" ;
    ResultSql(q, sSql);
    if (q->RecordCount == 0)
    {

          MenuPaper->Enabled =  false;
          MenuShare->Enabled = false;
          MenuOther->Enabled = false;

    }
    sSql = "select * from A_Marker" ;
    ResultSql(q, sSql);
    if (q->RecordCount == 0)
    {

          MenuPaper->Enabled =  false;
          MenuShare->Enabled = false;
          MenuOther->Enabled = false;

    }
    sSql = "select * from A_ManageUnit" ;
    ResultSql(q, sSql);
    if (q->RecordCount == 0)
    {

          MenuPaper->Enabled =  false;
          MenuShare->Enabled = false;
          MenuOther->Enabled = false;

    }


}
//---------------------------------------------------------------------------

