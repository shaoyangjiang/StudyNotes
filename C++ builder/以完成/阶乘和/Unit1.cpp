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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        int x;
        int ss=0,sum=0,i=1;
        AnsiString aa=InputBox("��������" ,"����һ��������","");
        if(aa=="")
        return;
        x=StrToInt(aa);
        for(int j=0;j<aa;j++)
        {
             ss=ss+sum+i;
             sum=sum+i;
             i++;
        }
      // AnSiString output = "�ܺ�Ϊ��"+IntToStr(ss);
        MessageBox(NULL,IntToStr(ss).c_str(),"�������",MB_OK);
        //ShowMessage("�ܺ�Ϊ��"+IntToStr(ss));
}
//---------------------------------------------------------------------------
 