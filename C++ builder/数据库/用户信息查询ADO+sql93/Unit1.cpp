
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
        //������������
        int i;
        //�����ѯ�ֶ�����
        for(i=0;i<ADOQuery1->Fields->Count;i++)
                search_field->Items->Add(ADOQuery1->Fields->Fields[i]->FieldName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::searchClick(TObject *Sender)
{
        //����Locate�����Ĳ���
        TLocateOptions Opts;
        Opts<<loPartialKey;
        //����Location������ѯ����
        if(!ADOQuery1->Locate(search_field->Text,search_value->Text,Opts))
                ShowMessage("û�з��ϵ�����");
}
//---------------------------------------------------------------------------
