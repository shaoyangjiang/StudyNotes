//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall DisplayHint(TObject *Sender);                         
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
