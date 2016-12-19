//---------------------------------------------------------------------------

#ifndef fmAboutUH
#define fmAboutUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TfmAbout : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfmAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmAbout *fmAbout;
//---------------------------------------------------------------------------
#endif
