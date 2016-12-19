
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
        //声明计数变量
        int i;
        //加入查询字段名称
        for(i=0;i<ADOQuery1->Fields->Count;i++)
                search_field->Items->Add(ADOQuery1->Fields->Fields[i]->FieldName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::searchClick(TObject *Sender)
{
        //设置Locate方法的参数
        TLocateOptions Opts;
        Opts<<loPartialKey;
        //利用Location方法查询数据
        if(!ADOQuery1->Locate(search_field->Text,search_value->Text,Opts))
                ShowMessage("没有符合的数据");
}
//---------------------------------------------------------------------------
