//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TFindDialog *FindDialog1;
        TRichEdit *RichEdit1;
        TReplaceDialog *ReplaceDialog1;
        TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FindDialog1Find(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ReplaceDialog1Find(TObject *Sender);
        void __fastcall ReplaceDialog1Replace(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
