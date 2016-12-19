//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TRichEdit *RichEdit1;
        TMenuItem *NFile;
        TMenuItem *NOpen;
        TMenuItem *open1;
        TMenuItem *NExit;
        TMenuItem *Nnew;
        TMenuItem *NSave;
        TMenuItem *Edit1;
        TOpenDialog *OpenDialog1;
        void __fastcall NOpenClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
