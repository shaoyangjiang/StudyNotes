//---------------------------------------------------------------------------

#ifndef ReturningUnitH
#define ReturningUnitH
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
//---------------------------------------------------------------------------
class TReturningBook : public TForm
{
__published:	// IDE-managed Components
        TQuery *ReturningTableQuery1;
        TDBGrid *DBGrid1;
        TGroupBox *GroupBox1;
        TBitBtn *BitBtn1;
        TEdit *ISBNEdit;
        TQuery *BookTableQuery2;
        TLabel *Label1;
        TEdit *BookNameEdit;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TEdit *EditorEdit;
        TEdit *PublisherEdit;
        TEdit *PubDateEdit;
        TEdit *PriceEdit;
        TDataSource *DataSource1;
        TQuery *ReaderTableQuery3;
        TEdit *NameEdit;
        TEdit *GenderEdit;
        TEdit *UnitEdit;
        TEdit *IdentEdit;
        TEdit *NumberEdit;
        TLabel *Label12;
        TEdit *ReaderIdEdit;
        TLabel *Label13;
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TReturningBook(TComponent* Owner);
        void ShowBorrowingTable();
     
};
//---------------------------------------------------------------------------
extern PACKAGE TReturningBook *ReturningBook;
//---------------------------------------------------------------------------
#endif
