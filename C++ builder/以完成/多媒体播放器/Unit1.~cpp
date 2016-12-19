//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "stdio.h"
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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
       mprMain->Notify = true;
       mprMain->Wait = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::miFileOpenClick(TObject *Sender)
{
        OpenFile->InitialDir = GetCurrentDir();
        if(OpenFile->Execute())
        {       //设置文件名称
                mprMain->FileName = OpenFile->FileName;
                //打开文件，等待播放
                mprMain->Open();
                //设置视频播放尺寸
                mprMain->DisplayRect = Display->ClientRect;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miFileEjectCDClick(TObject *Sender)
{
        if(miFunctionCD->Checked == true)
        {
                mprMain->Eject();
                mprMain->Close();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miFileExitClick(TObject *Sender)
{
      Close();  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miFunctionAVIClick(TObject *Sender)
{
        miFunctionAVI->Checked = true;
        mprMain->ShowHint = true;
        mprMain->VisibleButtons.Clear();
        mprMain->VisibleButtons<<btPlay<<btPause<<btStop<<btNext<<btPrev;
        mprMain->DeviceType = dtAVIVideo;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miFunctionCDClick(TObject *Sender)
{
        miFunctionCD->Checked = true;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miFunctionmp3Click(TObject *Sender)
{
        miFunctionmp3->Checked = true;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miFunctionOthersClick(TObject *Sender)
{
        miFunctionOthers->Checked = true;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miControlPlayClick(TObject *Sender)
{
        if(mprMain->Mode == mpPaused)
                mprMain->Resume();
        else
                mprMain->Play();
       mprMain->Notify = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miControlPauseClick(TObject *Sender)
{
        mprMain->Pause();
       mprMain->Notify = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miControlStopClick(TObject *Sender)
{
         mprMain->Stop();
        mprMain->Notify = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miControlStepClick(TObject *Sender)
{
        mprMain->Step();
       mprMain->Notify = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miControlBackClick(TObject *Sender)
{
        mprMain->Back();
       mprMain->Notify = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miControlHomeClick(TObject *Sender)
{
        mprMain->Rewind();
       mprMain->Notify = true;
}
//---------------------------------------------------------------------------
