//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TStringList *StrList = new TStringList();  //����TStringList�����StrList
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  String filename,path;
  if(OpenDialog1->Execute())
  {
     path = OpenDialog1->FileName;
  }
  StrList->Add(path);
  filename = path.SubString(ExtractFilePath(path).Length()+1,path.Length() - ExtractFilePath(path).Length()); //ȡ�ļ���

  ListBox1->Items->Add(filename);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
  Edit1->Text = RadioGroup1->ItemIndex;
  Animate1->Enabled = false;
  Animate1->Active = false;
  switch(RadioGroup1->ItemIndex)
  {

    case 0:
      Animate1->CommonAVI = aviDeleteFile;
      break;
    case 1:
      Animate1->CommonAVI = aviFindFolder;
      break;
    case 2:
      Animate1->CommonAVI = aviFindFile;
      break;
    case 3:
      Animate1->CommonAVI = aviFindComputer;
      break;
    case 4:
      Animate1->CommonAVI = aviCopyFiles;
      break;
    case 5:
      Animate1->CommonAVI = aviCopyFile;
      break;
    case 6:
      Animate1->CommonAVI = aviRecycleFile;
      break;
    case 7:
      Animate1->CommonAVI = aviEmptyRecycle;
  }
  Animate1->Enabled = true;
  Animate1->Play(0, 15, 0);
  Edit1->Text = Animate1->FrameCount; //֡��
  Edit2->Text = "��:"+IntToStr(Animate1->FrameHeight)+", ��:"+IntToStr(Animate1->FrameWidth); //�ߴ�
  Edit3->Text = Animate1->StartFrame; //��ʼ֡
  Edit4->Text = Animate1->StopFrame; //ֹͣ֡
}
//---------------------------------------------------------------------------





void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
  String path;
  for(int i=0;i<ListBox1->Items->Count;i++)
  {
     if(ListBox1->Selected[i]) path = StrList->Strings[i];
  }
  Animate1->Enabled = false;
  Animate1->Active = false;
  Animate1->FileName = path; // path�в��ܺ�������
  Animate1->Enabled = true;
  Animate1->Active = true;
  Edit1->Text = Animate1->FrameCount; //֡��
  Edit2->Text = "��:"+IntToStr(Animate1->FrameHeight)+", ��:"+IntToStr(Animate1->FrameWidth); //�ߴ�
  Edit3->Text = Animate1->StartFrame; //��ʼ֡
  Edit4->Text = Animate1->StopFrame; //ֹͣ֡
}
//---------------------------------------------------------------------------





