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

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
        Label1->Caption = "��ѡ��Ĳ���ϵͳ�ǣ�DOS    ";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
         Label1->Caption = "��ѡ��Ĳ���ϵͳ�ǣ�Windows ";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
         Label1->Caption = "  ��ѡ��Ĳ���ϵͳ�ǣ�Linux    ";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        if(RadioButton1->Checked)
                Label1->Caption = "��ѡ��Ĳ���ϵͳ�ǣ�DOS";
        else if(RadioButton2->Checked)
                Label1->Caption = "��ѡ��Ĳ���ϵͳ�ǣ�Windows";
        else    if(RadioButton2->Checked)
                Label1->Caption = "  ��ѡ��Ĳ���ϵͳ�ǣ�Linux";
}
//---------------------------------------------------------------------------
