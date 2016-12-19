//---------------------------------------------------------------------------

#ifndef BookInsertUnitH
#define BookInsertUnitH
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
class TBookInsert : public TForm
{
__published:	// IDE-managed Components
        TQuery *BookInsertQuery;
        TDataSource *DataSource1;
        TDBGrid *DBGrid1;
        TGroupBox *GroupBox1;
        TEdit *ISBNEdit;
        TEdit *BookNameEdit;
        TEdit *EditorEdit;
        TEdit *PublisherEdit;
        TEdit *PubDateEdit;
        TEdit *PriceEdit;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TBitBtn *BitBtn1;
        TEdit *BookIndexEdit;
        TLabel *Label7;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall DataSource1DataChange(TObject *Sender,
          TField *Field);
private:	// User declarations
public:		// User declarations
        __fastcall TBookInsert(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBookInsert *BookInsert;
//---------------------------------------------------------------------------
#endif
