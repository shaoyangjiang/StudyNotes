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

void __fastcall TForm1::FileListBox1Click(TObject *Sender)
{
        AnsiString filename;
                filename=FileListBox1->FileName.UpperCase();
                if((filename.Pos(".BMP"))>0||(filename.Pos(".WMF"))>0||(filename.Pos(".ICO"))>0||(filename.Pos(".jpg"))>0)
               {
                Image1->Visible=True;
                Image1->Picture->LoadFromFile(FileListBox1->FileName);
               }
               else
                Image1->Visible=False;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
        Image1->Center = CheckBox1->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
        Image1->Stretch = CheckBox1->Checked;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
        Image1->Transparent = CheckBox1->Checked;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        FileListBox1->Mask = FilterComboBox1->Mask;        
}
//---------------------------------------------------------------------------
