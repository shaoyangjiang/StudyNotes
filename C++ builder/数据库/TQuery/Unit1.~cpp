//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TabSet1Change(TObject *Sender, int NewTab,
      bool &AllowChange)
{
        AnsiString S;
        S=UpperCase(TabSet1->Tabs->Strings[NewTab]+"%");
        Query1->Close();
        Query1->Prepare();
        Query1->ParamByName("NameStr")->AsString=S;
        Query1->Open();        
}
//---------------------------------------------------------------------------
 