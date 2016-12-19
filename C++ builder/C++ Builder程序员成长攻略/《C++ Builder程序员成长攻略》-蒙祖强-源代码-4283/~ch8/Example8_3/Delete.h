//---------------------------------------------------------------------------
#ifndef DeleteH
#define DeleteH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TdeleteForm : public TForm
{
__published:	// IDE-managed Components
        TDataSource *DataSource1;
        TQuery *Query1;
        TDBGrid *DBGrid1;
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TdeleteForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TdeleteForm *deleteForm;
//---------------------------------------------------------------------------
#endif
