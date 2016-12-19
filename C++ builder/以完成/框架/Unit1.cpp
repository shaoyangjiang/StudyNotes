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

void __fastcall TForm1::FormClick(TObject *Sender)
{
        if(RadioButton1->Checked)
                nSystem = 0;
        else if(RadioButton2->Checked)
                nSystem = 1;
        else if(RadioButton3->Checked)
                nSystem = 2;
        if(RadioButton4->Checked)
                nLanguage = 0;
        else if(RadioButton5->Checked)
                nLanguage = 1;
        else if(RadioButton6->Checked)
                nLanguage = 2;
        ShowSelection();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
      //  if(RadioButton1->Checked)
                nSystem = 0;
      /*  else if (RadioButton2->Checked)
                nSystem = 1;
        else  if (RadioButton3->Checked)
                nSystem = 2;   */
        ShowSelection();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
       /* if(RadioButton1->Checked)
                nSystem = 0;
        else if (RadioButton2->Checked)    */
                nSystem = 1;
       // else if (RadioButton3->Checked)
     //           nSystem = 2;
        ShowSelection();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
    /*     if(RadioButton1->Checked)
                nSystem = 0;
        else if (RadioButton2->Checked)
                nSystem = 1;
        else  if (RadioButton3->Checked)    */
                nSystem = 2;
        ShowSelection();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
     //    if(RadioButton4->Checked)
                nLanguage = 0;
     /*   else if (RadioButton5->Checked)
                nLanguage = 1;
        else if (RadioButton6->Checked)
                nLanguage = 2;       */
        ShowSelection();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
   /*      if(RadioButton4->Checked)
                 nLanguage = 0;
        else if (RadioButton5->Checked)    */
                 nLanguage = 1;
    /*    else if (RadioButton6->Checked)
                 nLanguage = 2;   */
        ShowSelection();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton6Click(TObject *Sender)
{
  /*       if(RadioButton4->Checked)
                 nLanguage = 0;
        else if (RadioButton5->Checked)
                 nLanguage = 1;
        else if (RadioButton6->Checked)        */
                nLanguage = 2;
        ShowSelection();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ShowSelection()
{
        switch(nSystem)
        {
        case 0:
          switch(nLanguage)
          {
                case 0: Label1->Caption = "你选择的英文Dos系统         "; break;
                case 1: Label1->Caption = "你选择的是中文Dos系统        "; break;
                case 2: Label1->Caption = "你选择的是日文Dos系统         "; break;
          }
          break;
        case 1:
          switch(nLanguage)
          {
                case 0: Label1->Caption = "你选择的英文Windows系统          "; break;
                case 1: Label1->Caption = "你选择的是中文Windows系统        "; break;
                case 2: Label1->Caption = "你选择的是日文Windows系统         "; break;
          }
          break;
        case 2:
          switch(nLanguage)
          {
                case 0: Label1->Caption = "你选择的英文Linux系统           "; break;
                case 1: Label1->Caption = "你选择的是中文Linux系统          "; break;
                case 2: Label1->Caption = "你选择的是日文Linux系统        "; break;
          }
         break;
        }
}
