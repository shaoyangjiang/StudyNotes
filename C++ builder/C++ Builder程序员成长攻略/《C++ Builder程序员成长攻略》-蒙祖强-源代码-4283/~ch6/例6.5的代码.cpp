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

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  int x = MediaPlayer1->Position*100.0 / MediaPlayer1->Length;
  ProgressBar1->Position = (double)MediaPlayer1->Position*ProgressBar1->Max / MediaPlayer1->Length;
  Label1->Caption = "播放进程：" + IntToStr(x) + " %                 剩余时间：" + IntToStr(x) + " 秒";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
  int voice;  
  voice = TrackBar1->Position;
  waveOutSetVolume(0,(voice<<8));  
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  //C:\Program Files\Borland\CBuilder6\Projects\avi\waiting.avi
  MediaPlayer1->Display = Panel1;
  OpenDialog1->Filter = "avi文件(*.avi)|*.avi|所有文件(*.*)|*.*";
  if(!OpenDialog1->Execute()) return;
  Edit1->Text = OpenDialog1->FileName;
  MediaPlayer1->FileName = Edit1->Text;  //"C:\\Program Files\\Borland\\CBuilder6\\Projects\\avi\\weidao.mp3"; //
  MediaPlayer1->Open();
  MediaPlayer1->DisplayRect = Panel1->ClientRect;
  Timer1->Enabled = true;
  waveOutSetVolume(0,130<<8);         
}
//---------------------------------------------------------------------------





