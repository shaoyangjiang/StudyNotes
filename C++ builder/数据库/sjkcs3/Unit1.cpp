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
   ADOQuery1->Active=false;
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add("Select * from test");
   ADOQuery1->Active=true;
   for(int i=0;i<ADOQuery1->Fields->Count;i++)
   {
      ComboBox1->Items->Add(ADOQuery1->Fields->Fields[i]->FieldName);   
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   AnsiString StuId=Edit1->Text;
   AnsiString name=Edit2->Text;
   AnsiString gender=Edit3->Text;
   int brithday=StrToInt(Edit4->Text);
   AnsiString address=Edit5->Text;

   ADOQuery1->SQL->Clear();
   AnsiString sql;
   sql="insert into test values('"+StuId+"','"+name+"','"+gender+"',"+brithday+",'"+address+"');" ;
   ADOQuery1->SQL->Add(sql);
   ADOQuery1->ExecSQL();
   ADOQuery1->Active=false;
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add("Select * from text");
   ADOQuery1->Active=true;
}
//---------------------------------------------------------------------------
  /*
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   ADOQuery1->Active=false;
   ADOQuery1->SQL->Clear();
   AnsiString sql="Select * from stuinfo where ";
   AnsiString ziduan=ComboBox1->Text;
   if(ziduan!="sage")
   {
      AnsiString val=Edit6->Text;
      sql=sql+ziduan+"='"+val+"';";
   }
   else
   {
      int val=StrToInt(Edit6->Text);
      sql=sql+ziduan+"="+val+";";
   }
   ADOQuery1->SQL->Add(sql);
   ADOQuery1->Active=true;
}
//---------------------------------------------------------------------------
   */
void __fastcall TForm1::Button4Click(TObject *Sender)
{
   ADOQuery1->Active=false;
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add("Select * from test");
   ADOQuery1->Active=true;
}
//---------------------------------------------------------------------------
 /*
void __fastcall TForm1::Button3Click(TObject *Sender)
{
   AnsiString no=Edit7->Text;
   ADOQuery1->SQL->Clear();
   AnsiString sql="delete from stuinfo where sno='"+no+"'";
   ADOQuery1->SQL->Add(sql);
   ADOQuery1->ExecSQL();
   ADOQuery1->Active=false;
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add("Select * from stuinfo");
   ADOQuery1->Active=true; 
}
//---------------------------------------------------------------------------

   */
