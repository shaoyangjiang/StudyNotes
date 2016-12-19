//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define vertical 0
#define horizontal 1 
TForm1 *Form1;
 int PosX,PosY;
 int direction,flag=0;
 int OldPosX,OldPosY;
 bool IsMouseDown = false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm1::ShowBallAt(int x,int y)//x,y为球心座标
{
  Ball->Left = x-20;
  Ball->Top = y-20;
}
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
   if(BitBtn1->Caption=="开  始")
   {
     BitBtn1->Caption = "暂  停";
     Timer1->Enabled = true;
   }
   else
   {
     BitBtn1->Caption="开  始";
     Timer1->Enabled = false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  TColor color;
  if(direction==vertical)
  {
    if(PosY<=20) flag = 1;
    if(PosY>=Shape1->Height-20) flag = 0;
    if(flag==1) PosY = PosY + 1;
    if(flag==0)  PosY = PosY - 1;
  }
  else
  {
    if(PosX<=20) flag = 1;
    if(PosX>=Shape1->Width-20) flag = 0;
    if(flag==1) PosX = PosX + 1;
    if(flag==0)  PosX = PosX - 1;
  }
  color = RGB(random(255),random(255),random(255));
  Ball->Brush->Color = color;
  Ball->Pen->Color = color;
  ShowBallAt(PosX,PosY);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  PosX = Ball->Left + 20;
  PosY = Ball->Top + 20;
  direction==vertical;
  RadioGroup1->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
  if(RadioGroup1->ItemIndex==0) direction = vertical;
  else direction = horizontal;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
    Timer1->Interval = 21 - TrackBar1->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BallMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  Timer1->Enabled = false;
  IsMouseDown = true;
  OldPosX = X;
  OldPosY = Y;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BallMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  Timer1->Enabled = true;
  IsMouseDown = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BallMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
  if(IsMouseDown)
  {
    if(OldPosX != X || OldPosY != Y)
    {
      PosX = PosX+X-20; PosY = PosY+Y-20;
    }
    ShowBallAt(PosX,PosY);
  }
}
//---------------------------------------------------------------------------

