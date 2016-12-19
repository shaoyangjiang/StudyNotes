//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x1,y1,x2,y2;
int lx2=x2, ly2=y2;
bool IsMouseDown = false,FirstMoveFlag;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void  TForm1::RectangleLine(TCanvas *pCanvas, int x1, int y1, int x2, int y2)
{
    TPoint points[3];
    points[0] = Point(x1,y1);
    points[1] = Point(x1,y2);
    points[2] = Point(x2,y2);
    points[3] = Point(x2,y1);
    pCanvas->Polyline(points,3);
    pCanvas->MoveTo(x1,y1);
    pCanvas->LineTo(x2,y1);
}
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  x1 = X;
  y1 = Y;
  FirstMoveFlag = true;
  IsMouseDown = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
  if(IsMouseDown)
  {
    x2 = X;
    y2 = Y;
    if(lx2!=x2 || ly2!=y2)
    {
      Form1->Canvas->Pen->Color = clBtnFace;
      if(!FirstMoveFlag)
      {
        RectangleLine(Form1->Canvas,x1,y1,lx2,ly2); //察去原矩形
      }
      else FirstMoveFlag = false;
      lx2 = x2;
      ly2 = y2;
      Form1->Canvas->Pen->Color = clBlack;
      RectangleLine(Form1->Canvas,x1,y1,x2,y2);  //画新矩形
    }
  }
  else
  {
    x1 = X;
    y1 = Y;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
   IsMouseDown = false;
}
//---------------------------------------------------------------------------

 



