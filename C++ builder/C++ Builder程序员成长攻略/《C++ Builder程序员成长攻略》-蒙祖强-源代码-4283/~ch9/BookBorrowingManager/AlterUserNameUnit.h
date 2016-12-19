//---------------------------------------------------------------------------

#ifndef AlterUserNameUnitH
#define AlterUserNameUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TAlterUserNameForm : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TEdit *OldUserNameEdit;
        TLabel *Label1;
        TEdit *OldPassEdit;
        TLabel *Label2;
        TGroupBox *GroupBox2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *NewUserNameEdit;
        TEdit *NewPassEdit;
        TEdit *ReNewPassEdit;
        TBitBtn *ConfirBtn;
        TBitBtn *RetryBtn;
        TQuery *ConfirQuery;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        void __fastcall ConfirBtnClick(TObject *Sender);
        void __fastcall RetryBtnClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAlterUserNameForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAlterUserNameForm *AlterUserNameForm;
//---------------------------------------------------------------------------
#endif
