//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMDIClientForm *MDIClientForm;
//---------------------------------------------------------------------------
__fastcall TMDIClientForm::TMDIClientForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMDIClientForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
            Action =caFree;
}
//---------------------------------------------------------------------------
