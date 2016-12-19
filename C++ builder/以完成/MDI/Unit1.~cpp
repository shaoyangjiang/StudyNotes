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

void __fastcall TForm1::NewClick(TObject *Sender)
{
        TMDIClientForm* clientForm;
        clientForm = new TMDIClientForm(Application);
        clientForm->Caption = "Î´ÃüÃû" + IntToStr(MDIChildCount);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CLOSEClick(TObject *Sender)
{
        if(ActiveMDIChild != NULL)
           ActiveMDIChild->Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CloseAllClick(TObject *Sender)
{
        int i;
        for(i=0;i<MDIChildCount;i++)
          MDIChildren[i]->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CASCADEClick(TObject *Sender)
{
        Cascade();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TILEClick(TObject *Sender)
{
        Tile();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ARRANGEICONSClick(TObject *Sender)
{
        ArrangeIcons();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitClick(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------
