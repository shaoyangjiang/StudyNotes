//---------------------------------------------------------------------------
#ifndef updateH
#define updateH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TupdateForm : public TForm
{
__published:	// IDE-managed Components
        TDataSource *DataSource1;
        TDBGrid *DBGrid1;
        TDBEdit *DBEdit1;
        TLabel *Label1;
        TDBEdit *DBEdit2;
        TDBEdit *DBEdit3;
        TDBEdit *DBEdit4;
        TDBEdit *DBEdit5;
        TDBEdit *DBEdit6;
        TDBEdit *DBEdit7;
        TDBMemo *DBMemo1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TButton *Button1;
        TLabel *Label9;
        TTable *Table1;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TupdateForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TupdateForm *updateForm;
//---------------------------------------------------------------------------
#endif
