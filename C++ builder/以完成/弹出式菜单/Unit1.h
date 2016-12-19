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
        TPopupMenu *PopupMenu1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TMenuItem *Add;
        TMenuItem *Sub;
        TMenuItem *Mul;
        TMenuItem *Div;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        void __fastcall AddClick(TObject *Sender);
        void __fastcall SubClick(TObject *Sender);
        void __fastcall MulClick(TObject *Sender);
        void __fastcall DivClick(TObject *Sender);
        void __fastcall PopupMenu1Popup(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
