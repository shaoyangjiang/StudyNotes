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

void __fastcall TForm1::FormPaint(TObject *Sender)
{
        int X,Y;
        for(X=0;X<249;X++)
                for(Y=0;Y<249;Y++)
                        Canvas->Pixels[X][Y] = TColor(RGB(X,250-Y,(X+Y)/2));
}
//---------------------------------------------------------------------------
 