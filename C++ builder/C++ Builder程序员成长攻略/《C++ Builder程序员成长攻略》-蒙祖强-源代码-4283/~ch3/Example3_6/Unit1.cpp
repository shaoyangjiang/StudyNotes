//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
 
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  String PicName;
  for(int i=0;i<ListBox1->Items->Count;i++)
  {
    if(ListBox1->Selected[i])
    {
      PicName = ListBox1->Items->Strings[i];
       //Edit1->Text = ListBox1->Items[0].operator[](i);
      Image1->Picture->LoadFromFile(Edit1->Text+"\\"+PicName);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  String picPath = Edit1->Text;
  Label2->Caption = Edit1->Text+"目录下的所有jpg文件：";
  TSearchRec s;
  FindFirst(picPath+"\\*.jpg",0,s);
  ListBox1->Clear();
  while(FindNext(s)==0)
    if(s.Attr == 32) ListBox1->Items->Add(s.Name);
}
//---------------------------------------------------------------------------


