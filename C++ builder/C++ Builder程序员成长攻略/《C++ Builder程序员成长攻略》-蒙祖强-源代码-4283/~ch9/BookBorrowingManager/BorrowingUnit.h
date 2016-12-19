//---------------------------------------------------------------------------

#ifndef BorrowingUnitH
#define BorrowingUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TBorrowingBook : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TEdit *ReaderIdEdit;
        TEdit *ReaderNameEdit;
        TEdit *ISBNEdit;
        TEdit *BookNameEdit;
        TEdit *EditorEdit;
        TEdit *BorrowDateEdit;
        TEdit *ReturnDateEdit;
        TEdit *LibrarianIdEdit;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TQuery *ReaderTableQuery1;
        TDataSource *ReaderTableDataSource1;
        TQuery *BookTableQuery2;
        TDataSource *BookTableDataSource2;
        TLabel *leavingBookNumLabel;
        TDBGrid *DBGrid1;
        TDBGrid *DBGrid2;
        TDBGrid *DBGrid3;
        TDataSource *BorrowingTableDataSource3;
        TQuery *BorrowingTableQuery3;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TBitBtn *BitBtn1;
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TBorrowingBook(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBorrowingBook *BorrowingBook;
//---------------------------------------------------------------------------
#endif
