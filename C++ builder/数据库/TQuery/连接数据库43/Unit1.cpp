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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        DBGrid1->DataSource = DataSource1;
        DataSource1->DataSet = Query1;

        Query1->Active = false;
        Query1->SQL->Clear();
        Query1->SQL->Add("select* from employee.db");
        Query1->ExecSQL();
        Query1->Active = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        int i;
       // AnsiString str = "";
        if(Edit1->Text== "")
                {
                        ShowMessage("ÇëÊäÈë±àºÅ");
                        return;
                }
        else
                {
                        Query1->Active = false;
                        Query1->SQL->Clear();
                        Query1->SQL->Add("select* from employee.db where EmpNo = "+ Edit1->Text);
                        Query1->ExecSQL();
                        Query1->Active = true;
                }
}
//---------------------------------------------------------------------------
