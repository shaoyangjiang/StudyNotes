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
  CheckBox1->AllowGrayed = false;
  Button1->Enabled = false;
  Button2->Enabled = true;
  Label3->Caption = "������ĵ�ǰ״̬����״̬��";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  CheckBox1->AllowGrayed = true;
  Button1->Enabled = true;
  Button2->Enabled = false;
  Label3->Caption = "������ĵ�ǰ״̬����״̬��";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
  if(CheckBox1->Checked) Edit1->Text = "True";
  else Edit1->Text = "False";

  if(CheckBox1->State==cbChecked) Edit2->Text = "cbChecked";//ѡ��
  else if(CheckBox1->State==cbUnchecked) Edit2->Text = "cbUnchecked";//δ��ѡ��
  else Edit2->Text = "cbGrayed"; //��ѡ�е����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  Button1->Enabled = false;        
}
//---------------------------------------------------------------------------

