//---------------------------------------------------------------------------

#ifndef fmStartUH
#define fmStartUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TStartupForm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *txtTitle;
        TTimer *Timer1;
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TStartupForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStartupForm *StartupForm;
//---------------------------------------------------------------------------
#endif
