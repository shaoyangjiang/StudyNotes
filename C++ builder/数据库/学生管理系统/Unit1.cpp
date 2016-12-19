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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        ADOQuery1->Active=false;
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add("Select * from test");
   ADOQuery1->Active=true;
   for(int i=0;i<ADOQuery1->Fields->Count;i++)
   {
     FindNameComboBox->Items->Add(ADOQuery1->Fields->Fields[i]->FieldName);
   }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        ADOQuery1->Active=false;
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add("Select * from test");
   ADOQuery1->Active=true;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddClick(TObject *Sender)
{
   AnsiString StuId=StuIdEdit->Text;
   AnsiString name=NameEdit->Text;
   AnsiString gender=GenderEdit->Text;
   AnsiString brithday=BirthdayEdit->Text;
   AnsiString address=AddressEdit->Text;
   AnsiString remark=RemarkEdit->Text;
   ADOQuery1->SQL->Clear();
   AnsiString sql;
   sql="insert into test values('"+StuId+"','"+name+"','"+gender+"',"+brithday+",'"+address+"','"+remark+"');" ;
   ADOQuery1->SQL->Add(sql);
   ADOQuery1->ExecSQL();
   ADOQuery1->Active=false;
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add("Select * from test");
   ADOQuery1->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FindClick(TObject *Sender)
{
  if(FindEdit->Text == "")
  {
    ShowMessage("����������ҹؼ���!");
    return;
  }
  ADOQuery1->Active=false;
  ADOQuery1->SQL->Clear();
  ADOQuery1->SQL->Add( "select * from test where "+FindNameComboBox->Text+" like '%"+FindEdit->Text+"%'");
  ADOQuery1->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   AnsiString no=Edit1->Text;
   ADOQuery1->SQL->Clear();
   AnsiString sql="delete from test where StuId='"+no+"'";
   ADOQuery1->SQL->Add(sql);
   ADOQuery1->ExecSQL();
   ADOQuery1->Active=false;
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add("Select * from test");
   ADOQuery1->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        //����Ҫ����ý���ļ����ͣ���ý���������ݼ�ý�����ݴ洢��TMemoryStream ����ms ��
        if(FileStyle==".JPG" || FileStyle==".JPEG" || FileStyle==".JPE" )
      {
        TJPEGImage *jpeg = new TJPEGImage();
        ms->Position=0;
        int fs=1;
        ms->Write(&fs,1);
        ms->Position=1;
        jpeg->LoadFromFile(Form1->OpenPictureDialog1->FileName);
        jpeg->SaveToStream(ms);
        jpeg->Free();
       }

       //��ms �е����ݴ洢�����ݿ��image ���͵��ֶ���
       ADOQuery1->Close();
       ADOQuery1->SQL->Clear();
       ADOQuery1->SQL->Add("update test set picture=:picture where pictureid=1");
       ADOQuery1->Parameters->ParamByName("picture")->LoadFromStream(ms,ftBlob);
       ADOQuery1->ExecSQL();

       //�����ݿ��image ���͵��ֶ��е����ݴ洢��TStream �Ķ���stream ��
       TStream *stream;
       ADOQuery1->Close();
       ADOQuery1->SQL->Clear();
       ADOQuery1->SQL->Add("select picture from test where pictureid=1");
       ADOQuery1->Open();
       stream=ADOQuery1->CreateBlobStream((TBlobField*)ADOQuery1->FieldByName("picture"), bmRead);

       //ѡ����ʵ�ý��ؼ�����stream �е�����
       stream->Position=0;
       __int8 FileStyle;
       stream->Read(&FileStyle,1);
       stream->Position=1;
       if(FileStyle==1) //JPEG
       {
       TJPEGImage *jpeg = new TJPEGImage();
       jpeg->LoadFromStream(stream);
       Image1->Picture->Bitmap->Assign(jpeg);
       }

}
//---------------------------------------------------------------------------

