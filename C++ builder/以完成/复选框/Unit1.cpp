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

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
        if(CheckBox1->Checked)
        {
                if(CheckBox2->Checked)

                        Label1->Font->Style = TFontStyles() << fsBold << fsUnderline;
                else
                        Label1->Font->Style = TFontStyles() << fsBold;

        }
        else
        {
                if(CheckBox2->Checked)
                        Label1->Font->Style = TFontStyles() << fsUnderline;
                else
                        Label1->Font->Style = TFontStyles();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
        if(CheckBox1->Checked)
        {
                if(CheckBox2->Checked)

                        Label1->Font->Style = TFontStyles() << fsBold << fsUnderline;
                else
                        Label1->Font->Style = TFontStyles() << fsBold;

        }
        else
        {
                if(CheckBox2->Checked)
                        Label1->Font->Style = TFontStyles() << fsUnderline;
                else
                        Label1->Font->Style = TFontStyles();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
         if(CheckBox1->Checked)
        {
                if(CheckBox2->Checked)

                        Label1->Font->Style = TFontStyles() << fsBold << fsUnderline;
                else
                        Label1->Font->Style = TFontStyles() << fsBold;

        }
        else
        {
                if(CheckBox2->Checked)
                        Label1->Font->Style = TFontStyles() << fsUnderline;
                else
                        Label1->Font->Style = TFontStyles();
        }
}
//---------------------------------------------------------------------------
