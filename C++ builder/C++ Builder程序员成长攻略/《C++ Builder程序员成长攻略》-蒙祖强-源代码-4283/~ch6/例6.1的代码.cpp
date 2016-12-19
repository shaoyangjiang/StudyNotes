//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TForm1 *Form1;
int h,w,CurNum=1;
double per;
bool IsFirst = true;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------//---------------------------------------------------------------------------//void __fastcall TextRect(const Windows::TEect& Rect,int X,int Y,const System::AnsiString Text);

//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  h = Image1->Height; w = Image1->Width;
  Image1->Canvas->Pen->Color = clGreen; //clLime;
  Image1->Canvas->Pen->Width = 1;
  Image1->Canvas->Brush->Color = clBtnText;
  Image1->Canvas->FillRect(ClientRect);
  Image2->Canvas->Pen->Color = clGreen; //clLime;
  Image2->Canvas->Pen->Width = 1;
  Image2->Canvas->Brush->Color = clBtnText;
  Image2->Canvas->FillRect(ClientRect);

  for(int i=1;i<=10;i++)
  {
    Image1->Canvas->MoveTo(0, i*h/10);
    Image1->Canvas->LineTo(w, i*h/10);
    Image1->Canvas->MoveTo(i*w/10,0);
    Image1->Canvas->LineTo(i*w/10,w);
    Image2->Canvas->MoveTo(0, i*h/10);
    Image2->Canvas->LineTo(w, i*h/10);
    Image2->Canvas->MoveTo(i*w/10,0);
    Image2->Canvas->LineTo(i*w/10,w);
  }
  Image1->Canvas->Font->Color = clLime;
  Image1->Canvas->TextOutA(0,0,"100%");
  Image1->Canvas->TextOutA(0,h-12,"0%");
  Image2->Canvas->Font->Color = clLime;
  Image2->Canvas->TextOutA(0,0,"100%");
  Image2->Canvas->TextOutA(0,h-12,"0%");
  Timer1->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  MEMORYSTATUS *memory;
  memory = new MEMORYSTATUS();
  memory->dwLength = sizeof(MEMORYSTATUS);
  GlobalMemoryStatus(memory);

  //ListBox1->Items->Add("已用内存空间占总内存空间的百分比："+(String)memory->dwMemoryLoad+"%");

  //StrToFloat(Edit1->Text)/100.0;
  Image1->Canvas->Pen->Color = clLime;
  Image2->Canvas->Pen->Color = clLime;
  if(IsFirst)
  {
    IsFirst = false;
    per = memory->dwMemoryLoad / 100.0;
    Image1->Canvas->MoveTo(0, (1-per)*h);
    per = (double)(memory->dwTotalPhys - memory->dwAvailPhys) / memory->dwTotalPhys; //memory->dwMemoryLoad / 100.0; ？？
    Image2->Canvas->MoveTo(0, (1-per)*h);
  }
  else
  {
    per = memory->dwMemoryLoad / 100.0; 
    Image1->Canvas->LineTo(CurNum++, (1-per)*h);
    per = (double)(memory->dwTotalPhys - memory->dwAvailPhys) / memory->dwTotalPhys; //memory->dwMemoryLoad / 100.0; ？？
    Image2->Canvas->LineTo(CurNum++, (1-per)*h);
  }       
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------



