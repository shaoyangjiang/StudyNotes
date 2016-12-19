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

void __fastcall TForm1::Button1Click(TObject *Sender)
{

//11.2
    /*    Table1->Close();
        Table1->IndexFieldNames = "Population";
        Table1->Open();
        Table1->SetRangeStart();
        Table1Population->Value = 5300000;
        Table1->SetRangeEnd();
        Table1Population->Value = 33000000;
        Table1->ApplyRange();
                                   */
 //11.3
        if(Table1->Active == false)
        Table1->Open();
        Table1->First();
        while(!(Table1->Eof))
         {
                Table1->Edit();
                Table1->FieldByName("Area")->Value/=1000;
               Table1->Post();
                Table1->Next();
         }

}
//---------------------------------------------------------------------------
 