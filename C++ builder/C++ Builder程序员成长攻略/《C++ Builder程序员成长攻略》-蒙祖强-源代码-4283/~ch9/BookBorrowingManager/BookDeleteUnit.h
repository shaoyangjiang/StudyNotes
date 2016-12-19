//---------------------------------------------------------------------------

#ifndef BookDeleteUnitH
#define BookDeleteUnitH
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
class TBookDelete : public TForm
{
__published:	// IDE-managed Components
        TDBGrid *DBGrid1;
        TDataSource *DataSource1;
        TBitBtn *BitBtn1;
        TQuery *BookDeleteQuery;
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TBookDelete(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBookDelete *BookDelete;
//---------------------------------------------------------------------------
#endif
