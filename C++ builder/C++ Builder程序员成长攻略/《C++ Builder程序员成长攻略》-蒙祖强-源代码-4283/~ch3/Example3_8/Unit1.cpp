//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int s = 0, m = 0,h = 0;
int D[10][7];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//实现函数showA
void TForm1::showA(int n)
{
  if(D[n][0]==1) P1->Visible = true; else P1->Visible = false;
  if(D[n][1]==1) P2->Visible = true; else P2->Visible = false;
  if(D[n][2]==1) P3->Visible = true; else P3->Visible = false;
  if(D[n][3]==1) P4->Visible = true; else P4->Visible = false;
  if(D[n][4]==1) P5->Visible = true; else P5->Visible = false;
  if(D[n][5]==1) P6->Visible = true; else P6->Visible = false;
  if(D[n][6]==1) P7->Visible = true; else P7->Visible = false;
}
//实现函数showB
void TForm1::showB(int n)
{
  if(D[n][0]==1) P8->Visible = true; else P8->Visible = false;
  if(D[n][1]==1) P9->Visible = true; else P9->Visible = false;
  if(D[n][2]==1) P10->Visible = true; else P10->Visible = false;
  if(D[n][3]==1) P11->Visible = true; else P11->Visible = false;
  if(D[n][4]==1) P12->Visible = true; else P12->Visible = false;
  if(D[n][5]==1) P13->Visible = true; else P13->Visible = false;
  if(D[n][6]==1) P14->Visible = true; else P14->Visible = false;
}
//实现函数showC
void TForm1::showC(int n)
{
  if(D[n][0]==1) P17->Visible = true; else P17->Visible = false;
  if(D[n][1]==1) P18->Visible = true; else P18->Visible = false;
  if(D[n][2]==1) P19->Visible = true; else P19->Visible = false;
  if(D[n][3]==1) P20->Visible = true; else P20->Visible = false;
  if(D[n][4]==1) P21->Visible = true; else P21->Visible = false;
  if(D[n][5]==1) P22->Visible = true; else P22->Visible = false;
  if(D[n][6]==1) P23->Visible = true; else P23->Visible = false;
}//实现函数showD
void TForm1::showD(int n)
{
  if(D[n][0]==1) P24->Visible = true; else P24->Visible = false;
  if(D[n][1]==1) P25->Visible = true; else P25->Visible = false;
  if(D[n][2]==1) P26->Visible = true; else P26->Visible = false;
  if(D[n][3]==1) P27->Visible = true; else P27->Visible = false;
  if(D[n][4]==1) P28->Visible = true; else P28->Visible = false;
  if(D[n][5]==1) P29->Visible = true; else P29->Visible = false;
  if(D[n][6]==1) P30->Visible = true; else P30->Visible = false;
}

int TForm1::minutes(int m1,int m2)
{
  int m = m1+m2;
  if(m==60) m = 0;
  return m;
}

int TForm1::hours(int h1,int h2)
{
  int h = h1+h2;
  if(h==24) h = 0;
  return h;
}
void TForm1::showMinutes(int m)
{
  String strm = m;
  if(strm.Length()==1)
  {
    showD(strm.ToInt());
    showC(0);
  }
  else     //strm.Length()==2
  {
    showD(strm.SubString(2,1).ToInt());
    showC(strm.SubString(1,1).ToInt());
  }
}
void TForm1::showHours(int h)
{
  String strh = h;
  if(strh.Length()==1)
  {
    showB(strh.ToInt());
    showA(0);
  }
  else     //strm.Length()==2
  {
    showB(strh.SubString(2,1).ToInt());
    showA(strh.SubString(1,1).ToInt());
  }
}

void __fastcall TForm1::Panel1Click(TObject *Sender)
{
 //Panel1->BevelInner


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  int tm,ts;
  if(P15->Visible)
  {
    P15->Visible = false;
    P16->Visible = false;
  }
  else
  {
    P15->Visible = true;
    P16->Visible = true;
  }

  if(s>(ts=minutes(s,1))) //如果秒产生进位
  {
    if(m>(tm=minutes(m,1)))   //如果分产生进位
    {
      h = hours(h, 1);
      showHours(h);
    }
    m = tm;
    showMinutes(m);
  }
  s = ts;






}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  D[0][0] = 1; D[0][1] = 1; D[0][2] = 1; D[0][3] = 0; D[0][4] = 1; D[0][5] = 1; D[0][6] = 1;
  D[1][0] = 0; D[1][1] = 0; D[1][2] = 1; D[1][3] = 0; D[1][4] = 0; D[1][5] = 0; D[1][6] = 1;
  D[2][0] = 0; D[2][1] = 1; D[2][2] = 1; D[2][3] = 1; D[2][4] = 1; D[2][5] = 1; D[2][6] = 0;
  D[3][0] = 0; D[3][1] = 1; D[3][2] = 1; D[3][3] = 1; D[3][4] = 0; D[3][5] = 1; D[3][6] = 1;
  D[4][0] = 1; D[4][1] = 0; D[4][2] = 1; D[4][3] = 1; D[4][4] = 0; D[4][5] = 0; D[4][6] = 1;

  D[5][0] = 1; D[5][1] = 1; D[5][2] = 0; D[5][3] = 1; D[5][4] = 0; D[5][5] = 1; D[5][6] = 1;
  D[6][0] = 1; D[6][1] = 1; D[6][2] = 0; D[6][3] = 1; D[6][4] = 1; D[6][5] = 1; D[6][6] = 1;
  D[7][0] = 0; D[7][1] = 1; D[7][2] = 1; D[7][3] = 0; D[7][4] = 0; D[7][5] = 0; D[7][6] = 1;
  D[8][0] = 1; D[8][1] = 1; D[8][2] = 1; D[8][3] = 1; D[8][4] = 1; D[8][5] = 1; D[8][6] = 1;
  D[9][0] = 1; D[9][1] = 1; D[9][2] = 1; D[9][3] = 1; D[9][4] = 0; D[9][5] = 1; D[9][6] = 1;



}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
showA(3);



 
  /*
  strm = s;
  if(strm.Length()==1)
  {
    showD(strm.ToInt());
    showC(0);
  }
  else     //strm.Length()==2
  {
    showD(strm.SubString(2,1).ToInt());
    showC(strm.SubString(1,1).ToInt());
  }

   */
  
  


          
}
//---------------------------------------------------------------------------
