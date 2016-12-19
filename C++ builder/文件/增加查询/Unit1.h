//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <stdio.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *NameEdit;
        TEdit *ChineseEdit;
        TEdit *EnglishEdit;
        TEdit *MathEdit;
        TButton *Add;
        TButton *Next;
        TButton *Prev;
        TButton *Query;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall AddClick(TObject *Sender);
        void __fastcall NextClick(TObject *Sender);
        void __fastcall PrevClick(TObject *Sender);
        void __fastcall QueryClick(TObject *Sender);
private:	// User declarations
        FILE* m_fpFile;
        int m_nTotalRecord;
        int m_nRecordIndex;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
