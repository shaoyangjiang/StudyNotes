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
        Canvas->TextOut(20,20,"随机产生十个数，其中有如下的数小于60");
        Canvas->TextOut(20,40,"=====================================");
       int sjs[10];
       randomize();
       for(int i=0;i<10;i++)
        {
                sjs[i]=random(100);
        }

       int count=0;
       for(int i=0;i<10;i++)
        {
                if(sjs[i]<60)
                {
                        Canvas->TextOut(20,60+count*20,sjs[i]);
                        count++;
                }
        }


}
//---------------------------------------------------------------------------
