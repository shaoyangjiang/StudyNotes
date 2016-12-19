//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include "Unit1.h"
#include "Unit2.h"

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
        TMenuItem *File;
        TMenuItem *Window;
        TMenuItem *New;
        TMenuItem *CLOSE;
        TMenuItem *CloseAll;
        TMenuItem *N1;
        TMenuItem *Exit;
        TMenuItem *CASCADE;
        TMenuItem *TILE;
        TMenuItem *ARRANGEICONS;
        void __fastcall NewClick(TObject *Sender);
        void __fastcall CLOSEClick(TObject *Sender);
        void __fastcall CloseAllClick(TObject *Sender);
        void __fastcall CASCADEClick(TObject *Sender);
        void __fastcall TILEClick(TObject *Sender);
        void __fastcall ARRANGEICONSClick(TObject *Sender);
        void __fastcall ExitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
