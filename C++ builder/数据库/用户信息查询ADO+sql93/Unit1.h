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
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TADOConnection *ADOConnection1;
        TADOQuery *ADOQuery1;
        TStringField *ADOQuery1DSDesigner;
        TStringField *ADOQuery1DSDesigner2;
        TStringField *ADOQuery1DSDesigner3;
        TStringField *ADOQuery1DSDesigner4;
        TStringField *ADOQuery1DSDesigner5;
        TStringField *ADOQuery1DSDesigner6;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *search_value;
        TComboBox *search_field;
        TButton *search;
        TDBNavigator *DBNavigator1;
        TLabel *Label3;
        TDBEdit *DBEdit1;
        TDataSource *DataSource1;
        TLabel *Label4;
        TDBEdit *DBEdit2;
        TLabel *Label5;
        TDBEdit *DBEdit3;
        TLabel *Label6;
        TDBEdit *DBEdit4;
        TLabel *Label7;
        TDBEdit *DBEdit5;
        TLabel *Label8;
        TDBEdit *DBEdit6;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall searchClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
