//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include"math.h"
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

void __fastcall TForm1::FormPaint(TObject *Sender)
{
        double A,x1,y1,x2,y2;
        int D=80;
        double E;
        Width = 640;
        Height = 480;
        Canvas->Pen->Color = clBlue;
        Canvas->Brush->Style = bsClear;
        for(int i=0;i<720;i++)
        {
                A=i*3.1415/360;
                E=D*(1+sin(4*A));
                x1=240 + E*cos(A);
                x2=240 + E*cos(A+M_PI/5);
                y1=180 + E*sin(A);
                y2=180 + E*sin(A+M_PI/5);
                Canvas->MoveTo(x1,y1);
                Canvas->LineTo(x2,y2);
        }
}
//---------------------------------------------------------------------------
