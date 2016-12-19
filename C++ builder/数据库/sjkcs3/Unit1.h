//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TADOConnection *ADOConnection1;
        TADOQuery *ADOQuery1;
        TStringField *ADOQuery1sno;
        TStringField *ADOQuery1sname;
        TStringField *ADOQuery1ssex;
        TIntegerField *ADOQuery1sage;
        TStringField *ADOQuery1sspecial;
        TDataSource *DataSource1;
        TDBGrid *DBGrid1;
        TLabel *Label1;
        TGroupBox *GroupBox1;
        TLabel *Label2;
        TEdit *Edit1;
        TLabel *Label3;
        TEdit *Edit2;
        TLabel *Label4;
        TEdit *Edit3;
        TLabel *Label5;
        TEdit *Edit4;
        TLabel *Label6;
        TEdit *Edit5;
        TButton *Button1;
        TGroupBox *GroupBox2;
        TLabel *Label7;
        TComboBox *ComboBox1;
        TLabel *Label8;
        TEdit *Edit6;
        TButton *Button2;
        TGroupBox *GroupBox3;
        TLabel *Label9;
        TEdit *Edit7;
        TButton *Button3;
        TButton *Button4;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);

        void __fastcall Button4Click(TObject *Sender);
       
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
