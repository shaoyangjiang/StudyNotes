//---------------------------------------------------------------------------

#ifndef fmOtherPropUH
#define fmOtherPropUH
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
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include "DBCtrlsEh.hpp"
//#include "DBCtrlsEh.hpp"
//---------------------------------------------------------------------------
class TfmOtherProp : public TfmVBase
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TQRShape *QRShape3;
        TQRShape *QRShape4;
        TQRShape *QRShape2;
        TQRShape *QRShape1;
        TLabel *Label9;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label2;
        TLabel *Label36;
        TQRShape *QRShape17;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TQRShape *QRShape8;
        TQRShape *QRShape9;
        TQRShape *QRShape11;
        TQRShape *QRShape12;
        TQRShape *QRShape14;
        TQRShape *QRShape16;
        TLabel *Label30;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label10;
        TQRShape *QRShape18;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TQRShape *QRShape20;
        TQRShape *QRShape21;
        TQRShape *QRShape22;
        TQRShape *QRShape23;
        TQRShape *QRShape24;
        TQRShape *QRShape25;
        TQRShape *QRShape26;
        TQRShape *QRShape27;
        TLabel *Label16;
        TQRShape *QRShape28;
        TQRShape *QRShape29;
        TQRShape *QRShape30;
        TLabel *Label17;
        TLabel *Label18;
        TQRShape *QRShape31;
        TQRShape *QRShape32;
        TLabel *Label19;
        TQRShape *QRShape33;
        TLabel *Label20;
        TComboBox *cmbMaker;
        TLabel *Label21;
        TComboBox *cmbChecker;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label24;
        TLabel *Label25;
        TQRShape *QRShape19;
        TQRShape *QRShape5;
        TQRShape *QRShape6;
        TQRShape *QRShape7;
        TQRShape *QRShape10;
        TQRShape *QRShape13;
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
        TStringField *tableOwnerSex;
        TIntegerField *tableOwnerAge;
        TStringField *tableOwnerNativePlace;
        TStringField *tableOwnerAddress;
        TStringField *tableOwnerCompany;
        TStringField *tableOwnerEmployment;
        TStringField *tableOwnerRelation;
        TBCDField *tableOwnerShare;
        TIntegerField *tableOwnerK_OwnerType_ID;
        TStringField *qryIndexName;
        TADOQuery *qryOther;
        TDataSource *dsShare;
        TDBEdit *dbEdtObligee;
        TDBText *dbTxtPosition;
        TDBText *dbTxtGround_No;
        TDBEdit *dbEdtPropertyType;
        TDBEdit *dbEdtBuilding;
        TDBEdit *dbEdtDoorplate;
        TDBEdit *dbTxtOwnerList;
        TLabel *txtAllBuilding;
        TLabel *txtAllRoom;
        TLabel *txtAllArea;
        TDBMemo *dbMemReamrk;
        TLabel *Label26;
        TEdit *edtPaper_No;
        TAutoIncField *qryOtherRID;
        TStringField *qryOtherRNO;
        TStringField *qryOtherFileHead;
        TStringField *qryOtherPaper_NO;
        TStringField *qryOtherK_P_Paper_NO;
        TStringField *qryOtherPropertyType;
        TStringField *qryOtherObligee;
        TStringField *qryOtherK_House_NO;
        TStringField *qryOtherBuilding;
        TStringField *qryOtherDoorplate;
        TIntegerField *qryOtherRoom;
        TBCDField *qryOtherStructureArea;
        TBCDField *qryOtherR_Value;
        TDateTimeField *qryOtherAvailable;
        TBCDField *qryOtherTaxRace;
        TBCDField *qryOtherTax;
        TDateTimeField *qryOtherCheckOffDate;
        TIntegerField *qryOtherK_Maker_ID;
        TIntegerField *qryOtherK_check_ID;
        TDateTimeField *qryOtherReceiptDate;
        TStringField *qryOtherRemark;
        TGroupBox *GroupBox1;
        TDBGrid *gridOther;
        TToolButton *ToolButton8;
        TImage *imgLog;
        TImage *imgUnlog;
        TLabel *LabLogFlag;
        TToolButton *ToolButton9;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
        TToolButton *ToolButton12;
        TSpeedButton *SpeedButton10;
        TLabel *Label27;
        TLabel *Label28;
        TLabel *Label29;
        TLabel *Label31;
        TLabel *Label32;
    TDBEdit *dbEdtTaxRace;
    TDBDateTimeEditEh *dbEdtAvailable;
    TDBNumberEditEh *dbEdtArea;
    TDBNumberEditEh *dbEdtValue;
    TDBNumberEditEh *dbedtTax;
    TDBNumberEditEh *dbEdtRoom;
        void __fastcall qryIndexAfterScroll(TDataSet *DataSet);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall actAddExecute(TObject *Sender);
        void __fastcall actPostExecute(TObject *Sender);
        void __fastcall actCancleExecute(TObject *Sender);
        void __fastcall actEditExecute(TObject *Sender);
        void __fastcall qryOtherAfterScroll(TDataSet *DataSet);
        void __fastcall actDeleteExecute(TObject *Sender);
        void __fastcall cmbMakerKeyPress(TObject *Sender, char &Key);
        void __fastcall cmbCheckerKeyPress(TObject *Sender, char &Key);
        void __fastcall ToolButton8Click(TObject *Sender);
        void __fastcall ToolButton9Click(TObject *Sender);
        void __fastcall ToolButton11Click(TObject *Sender);
        void __fastcall SpeedButton10Click(TObject *Sender);
        void __fastcall edtLocateKeyPress(TObject *Sender, char &Key);

private:	// User declarations
        AnsiString g_sPaper_No;  
public:		// User declarations
        __fastcall TfmOtherProp(TComponent* Owner);
        void __fastcall EdtColorToClWindowFun();
        void __fastcall EdtColorToClBtnFaceFun();
        void __fastcall EdtReadFun();
        void __fastcall EdtWriteFun();
        bool __fastcall EnsureDatAvalidFun();
        void __fastcall EnableButtonFun();
        void __fastcall SetButtonFun();
        void __fastcall PrintPaper1Fun();
};
//---------------------------------------------------------------------------
extern PACKAGE TfmOtherProp *fmOtherProp;
//---------------------------------------------------------------------------
#endif
