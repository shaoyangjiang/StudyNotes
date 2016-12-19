//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//#include<utilcls.h>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MPEGPLAYLib_OCX"
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
        OpenDialog1->Title="请选择一个音乐文件";
        OpenDialog1->DefaultExt = "mp3";
        OpenDialog1->Filter="ALL Files(*.*)|*.*|MP3 Files(*.mp3)|*.mp3";
        Edit1->Enabled=false;
        Edit2->Enabled=false;
        Edit3->Enabled=false;
        Edit4->Enabled=false;
        Edit1->Text="";
        Edit2->Text="";
        Edit3->Text="";
        Edit4->Text="";
        Button2->Enabled=false;
        Button3->Enabled=false;
        Button4->Enabled=false;
        Button5->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        WideString Mp3File;
        OpenDialog1->Execute();
        Edit1->Text=OpenDialog1->FileName;
        Mp3File=OpenDialog1->FileName;
        if(OpenDialog1->FileName!="")
        {
                Mp3Play1->Open(Mp3File,NULL);
                Button2->Enabled=true;
                Button3->Enabled=false;
                Button4->Enabled=false;
                Button5->Enabled=false;
                Edit2->Text=IntToStr(Mp3Play1->TotalTime);
                Edit3->Text=IntToStr(Mp3Play1->GetVolumeLeft());
                Edit4->Text=IntToStr(Mp3Play1->GetVolumeRight());
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
        Edit3->Enabled=false;
        Edit4->Enabled=false;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
        Edit3->Enabled=true;
        Edit4->Enabled=true;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit3KeyPress(TObject *Sender, char &Key)
{
        Mp3Play1->SetVolume(StrToInt(Edit3->Text),StrToInt(Edit4->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit4KeyPress(TObject *Sender, char &Key)
{
         Mp3Play1->SetVolume(StrToInt(Edit3->Text),StrToInt(Edit4->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Mp3Play1->Play();
        Button3->Enabled=true;
        Button4->Enabled=true;
        Button5->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Mp3Play1->Pause();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        Mp3Play1->Stop();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
        Mp3Play1->Close();
        Button2->Enabled=false;
        Button3->Enabled=false;
        Button4->Enabled=false;
        Button5->Enabled=false;
        Edit1->Text="";
        Edit2->Text="";
}
//---------------------------------------------------------------------------
