//---------------------------------------------------------------------------

#ifndef frmADOH
#define frmADOH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TADOTable *ADOTable1;
        TDBGrid *DBGrid1;
        TDataSource *DataSource1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *ID;
        TEdit *Name;
        TEdit *Age;
        TEdit *Salary;
        TEdit *Sex;
        TButton *Add;
        TLabel *Label6;
        TLabel *Label7;
        TButton *Find;
        TButton *Delete;
        TEdit *FindValue;
        TComboBox *ComboBox1;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TComboBox *ComboBox2;
        TComboBox *ComboBox3;
        TEdit *FilterValue;
        TButton *Filter;
        TButton *Prior;
        TButton *Next;
        TButton *ShowAll;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall AddClick(TObject *Sender);
        void __fastcall FindClick(TObject *Sender);
        void __fastcall DeleteClick(TObject *Sender);
        void __fastcall FilterClick(TObject *Sender);
        void __fastcall ADOTable1FilterRecord(TDataSet *DataSet,
          bool &Accept);
        void __fastcall PriorClick(TObject *Sender);
        void __fastcall NextClick(TObject *Sender);
        void __fastcall ShowAllClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
