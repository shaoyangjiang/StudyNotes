//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <stdio.h>
#include <systdate.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TComboBox *ComboBox1;
        TButton *First;
        TButton *Prior;
        TButton *Next;
        TButton *Last;
        TButton *Add;
        TButton *Edit;
        TButton *Delete;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FirstClick(TObject *Sender);
        void __fastcall PriorClick(TObject *Sender);
        void __fastcall NextClick(TObject *Sender);
        void __fastcall LastClick(TObject *Sender);
        void __fastcall AddClick(TObject *Sender);
        void __fastcall EditClick(TObject *Sender);
        void __fastcall DeleteClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
        FILE* m_pFile;
        int m_nTotalRecord;
        int m_nCurRecordIndex;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
