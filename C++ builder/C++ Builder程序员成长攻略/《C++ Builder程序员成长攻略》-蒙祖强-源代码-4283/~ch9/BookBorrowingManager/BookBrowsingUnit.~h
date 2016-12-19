//---------------------------------------------------------------------------

#ifndef BookBrowsingUnitH
#define BookBrowsingUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TBrowsingBook : public TForm
{
__published:	// IDE-managed Components
        TComboBox *SearchType;
        TComboBox *MatchType;
        TEdit *SearchingText;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label4;
        TButton *SearchingBtn;
        TQuery *BrowsingBookQuery;
        TDataSource *DataSource1;
        TScrollBox *ScrollBox1;
        TDBGrid *DBGrid1;
        void __fastcall SearchingBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TBrowsingBook(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBrowsingBook *BrowsingBook;
//---------------------------------------------------------------------------
#endif
