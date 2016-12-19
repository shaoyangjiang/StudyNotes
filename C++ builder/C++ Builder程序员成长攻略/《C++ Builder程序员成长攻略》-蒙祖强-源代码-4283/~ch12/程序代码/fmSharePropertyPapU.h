//---------------------------------------------------------------------------

#ifndef fmSharePropertyPapUH
#define fmSharePropertyPapUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "fmVBaseU.h"
#include <ActnList.hpp>
#include <ADODB.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
//#include "DBCtrlsEh.hpp"
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TfmSharePropertyPap : public TfmVBase
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label9;
        TEdit *edtPaper_No;
        TLabel *Label10;
        TLabel *Label14;
        TEdit *edtPosition;
        TLabel *Label15;
        TEdit *edtGround_No;
        TLabel *Label2;
        TEdit *edtBuildingNum;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *edtRoomNum;
        TLabel *Label5;
        TEdit *edtAreaNum;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *edtOwnerList;
        TLabel *Label8;
        TLabel *Label11;
        TEdit *edtOwner;
        TLabel *Label12;
        TEdit *edtShare;
        TLabel *Label16;
        TEdit *edtFile;
        TLabel *Label13;
        TEdit *edtPaperNo;
        TLabel *Label17;
        TEdit *edtMainOwner;
        TLabel *Label18;
        TEdit *edtOwnerName;
        TLabel *Label19;
        TQRShape *QRShape3;
        TQRShape *QRShape4;
        TQRShape *QRShape1;
        TQRShape *QRShape2;
        TLabel *Label20;
        TComboBox *cmbMaker;
        TLabel *Label21;
        TComboBox *cmbChecker;
        TAutoIncField *qryIndexRID;
        TStringField *qryIndexFNO;
        TStringField *qryIndexNO_Head;
        TStringField *qryIndexPaper_NO;
        TStringField *qryIndexK_App_NO;
        TStringField *qryIndexK_Owner_NO;
        TStringField *qryIndexOwnerList;
        TStringField *qryIndexHouse_Position;
        TStringField *qryIndexGround_NO;
        TIntegerField *qryIndexK_PropertyRight_ID;
        TIntegerField *qryIndexK_Status_ID;
        TIntegerField *qryIndexK_ManageUnit_ID;
        TIntegerField *qryIndexK_Maker_ID;
        TIntegerField *qryIndexK_Checker_ID;
        TDateTimeField *qryIndexSendOutDate;
        TDateTimeField *qryIndexAcceptDate;
        TStringField *qryIndexRemark;
        TADOTable *tableOwner;
        TAutoIncField *tableOwnerRID;
        TIntegerField *tableOwnerRNO;
        TStringField *tableOwnerOwnerName;
        TStringField *qryIndexName;
        TDataSource *dsShare;
        TADOQuery *qryShareOwner;
        TAutoIncField *qryShareOwnerRID;
        TStringField *qryShareOwnerRNO;
        TStringField *qryShareOwnerK_Paper_NO;
        TStringField *qryShareOwnerShareProperty_Paper_NO;
        TStringField *qryShareOwnerK_Owner_NO;
        TBCDField *qryShareOwnerShare;
        TIntegerField *qryShareOwnerBuilding;
        TIntegerField *qryShareOwnerRoom;
        TBCDField *qryShareOwnerArea;
        TIntegerField *qryShareOwnerK_Maker_ID;
        TIntegerField *qryShareOwnerK_Checker_ID;
        TIntegerField *qryShareOwnerK_ManageUnit_ID;
        TDateTimeField *qryShareOwnerSendOutDate;
        TDateTimeField *qryShareOwnerAcceptDate;
        TStringField *qryShareOwnerremark;
        TADOTable *tableShareOwner;
        TStringField *qryShareOwnerName;
        TComboBox *cmbManageUnit;
        TLabel *Label22;
        TDateTimePicker *dataSendOutDate;
        TLabel *Label56;
        TGroupBox *GroupBox1;
        TDBGrid *DBGrid1;
        TToolButton *ToolButton8;
        TToolButton *ToolButton9;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
        TSpeedButton *SpeedButton10;
        void __fastcall qryIndexAfterScroll(TDataSet *DataSet);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall actAddExecute(TObject *Sender);
        void __fastcall actPostExecute(TObject *Sender);
        void __fastcall qryShareOwnerAfterScroll(TDataSet *DataSet);
        void __fastcall edtOwnerExit(TObject *Sender);
        void __fastcall actEditExecute(TObject *Sender);
        void __fastcall actDeleteExecute(TObject *Sender);
        void __fastcall edtOwnerChange(TObject *Sender);
        void __fastcall actCancleExecute(TObject *Sender);
        void __fastcall cmbMakerKeyPress(TObject *Sender, char &Key);
        void __fastcall cmbCheckerKeyPress(TObject *Sender, char &Key);
        void __fastcall cmbManageUnitKeyPress(TObject *Sender, char &Key);
        void __fastcall ToolButton8Click(TObject *Sender);
        void __fastcall ToolButton10Click(TObject *Sender);
        void __fastcall edtLocateKeyPress(TObject *Sender, char &Key);
        void __fastcall SpeedButton10Click(TObject *Sender);
private:	// User declarations
       AnsiString g_sPaper_No;
public:		// User declarations
       AnsiString sOwnerID;
       int nInsertModifyFlag;
        __fastcall TfmSharePropertyPap(TComponent* Owner);
        void __fastcall ShowProperty_PaperFun()  ;
       
        void __fastcall InsertShareFun();
        void __fastcall UpdateShareFun();
        void __fastcall UpdateOwnerListFun();
        void __fastcall EdtReadFun();
        void __fastcall EdtWriteFun();
        void __fastcall EdtNullFun();
        void __fastcall EdtColorToClWindowFun();
        void __fastcall EdtColorToClBtnFaceFun();
        void __fastcall ClearFormFun();
        bool __fastcall EnsureDatAvalidFun();
         void __fastcall SetButtonFun();
         void __fastcall EnableButtonFun();
         void __fastcall PrintShareFun();

       // int __fastcall InsertOwnerFun(AnsiString sOwnerName, intnPropertyFlag);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmSharePropertyPap *fmSharePropertyPap;
//---------------------------------------------------------------------------
#endif
