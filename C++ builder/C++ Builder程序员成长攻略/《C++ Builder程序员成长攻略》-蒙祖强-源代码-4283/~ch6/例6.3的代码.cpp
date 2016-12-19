//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//TPoint GPoints[1000];  //最多可画有1000个顶点的多边形
//int pGPoints = 0;
int IsTheFistPoint = 1;
int FistPointX,FistPointY;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
 
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  if(IsTheFistPoint==1)
  {
    FistPointX = X;
    FistPointY = Y;
    Form1->Canvas->MoveTo(X,Y);
    IsTheFistPoint = 2;
  }
  else
  {
    Form1->Canvas->LineTo(X,Y);
    IsTheFistPoint++;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDblClick(TObject *Sender)
{
  Form1->Canvas->LineTo(FistPointX,FistPointY);
  IsTheFistPoint = 0;
}
//---------------------------------------------------------------------------





