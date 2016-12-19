//---------------------------------------------------------------------------

#ifndef InsertH
#define InsertH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TInsertForm : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TMemo *Memo1;
        TMaskEdit *MaskEdit1;
        TBitBtn *BitBtn1;
        TTable *Table1;
        TDataSource *DataSource1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TInsertForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInsertForm *InsertForm;
//---------------------------------------------------------------------------
#endif
