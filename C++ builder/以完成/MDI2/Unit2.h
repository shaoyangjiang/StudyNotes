//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TMDIClientForm : public TForm
{
__published:	// IDE-managed Components
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TMDIClientForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMDIClientForm *MDIClientForm;
//---------------------------------------------------------------------------
#endif
