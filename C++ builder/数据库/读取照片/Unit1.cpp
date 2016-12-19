//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include   <Jpeg.hpp>

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
   ADOQuery1->SQL->Add("Select * from test1");
   ADOQuery1->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
          if(OpenDialog1->Execute())
        {
       //将ms 中的数据存储到数据库的image 类型的字段中
       ADOQuery1->Close();
       ADOQuery1->SQL->Clear();
       ADOQuery1->SQL->Add("insert into test1 values(3,null)");
       ADOQuery1->ExecSQL();
       ADOQuery1->Close();
       ADOQuery1->SQL->Clear();
       ADOQuery1->SQL->Add("update test1 set picture=:picture where pictureid=3");
       //ADOQuery1->Parameters->ParamByName("picture")->LoadFromStream(ms,ftBlob);
       ADOQuery1->Parameters->ParamByName("picture")->LoadFromFile(OpenDialog1->FileName,ftBlob);
       ADOQuery1->ExecSQL();
       }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        TStream *stream;
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add("select picture from test1 where pictureid=1");
        ADOQuery1->Open();
        stream=ADOQuery1->CreateBlobStream((TBlobField*)ADOQuery1->FieldByName("picture"), bmRead);
        stream->Position=0;
__int8 FileStyle;
stream->Read(&FileStyle,1);
stream->Position=1;
TJPEGImage *jpeg = new TJPEGImage();
jpeg->LoadFromStream(stream);
Image1->Picture->Bitmap->Assign(jpeg);
}
//---------------------------------------------------------------------------
