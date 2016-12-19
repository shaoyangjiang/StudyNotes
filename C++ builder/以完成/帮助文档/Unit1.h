//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *HELP;
        TMenuItem *CONTENT;
        TMenuItem *INDEX;
        TMenuItem *HELPONHELP;
        void __fastcall CONTENTClick(TObject *Sender);
        void __fastcall HELPONHELPClick(TObject *Sender);
        void __fastcall INDEXClick(TObject *Sender);
       

private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
