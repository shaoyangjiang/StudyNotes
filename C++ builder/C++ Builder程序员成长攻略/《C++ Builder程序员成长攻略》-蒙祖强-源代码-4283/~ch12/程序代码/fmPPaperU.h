//---------------------------------------------------------------------------

#ifndef fmPPaperUH
    #define fmPPaperUH
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
    #include <Dialogs.hpp>
    #include <ExtDlgs.hpp>
    #include <DBCtrls.hpp>
#include <Buttons.hpp>
    //---------------------------------------------------------------------------
    class TfmPPaper: public TfmVBase
    {
            __published:  // IDE-managed Components
            TPageControl *pcMain;
            TTabSheet *tab1;
            TLabel *Label1;
            TLabel *Label2;
            TLabel *Label3;
            TLabel *Label4;
            TLabel *Label5;
            TLabel *Label6;
            TLabel *Label8;
            TLabel *Label24;
            TLabel *Label25;
            TLabel *Label26;
            TLabel *Label27;
            TLabel *Label28;
            TLabel *Label29;
            TLabel *Label30;
            TLabel *Label31;
            TLabel *Label32;
            TLabel *Label33;
            TLabel *Label34;
            TLabel *Label35;
            TLabel *Label36;
            TLabel *Label44;
            TLabel *Label45;
            TLabel *Label46;
            TLabel *Label47;
            TLabel *Label48;
            TLabel *Label49;
            TLabel *Label50;
            TLabel *Label51;
            TLabel *Label52;
            TLabel *Label53;
            TLabel *Label54;
            TLabel *Label55;
            TLabel *Label56;
            TQRShape *QRShape1;
            TQRShape *QRShape2;
            TQRShape *QRShape11;
            TQRShape *QRShape13;
            TQRShape *QRShape14;
            TDateTimePicker *dataStartData;
            TEdit *EdtPrice;
            TComboBox *cmbTaxType;
            TComboBox *cmbTaxRace;
            TEdit *edtTax;
            TQRShape *QRShape15;
            TQRShape *QRShape16;
            TQRShape *QRShape17;
            TQRShape *QRShape18;
            TQRShape *QRShape20;
            TQRShape *QRShape21;
            TQRShape *QRShape22;
            TQRShape *QRShape23;
            TQRShape *QRShape24;
            TQRShape *QRShape25;
            TQRShape *QRShape26;
            TQRShape *QRShape27;
            TQRShape *QRShape34;
            TQRShape *QRShape35;
            TQRShape *QRShape36;
            TQRShape *QRShape37;
            TQRShape *QRShape38;
            TQRShape *QRShape41;
            TQRShape *QRShape42;
            TQRShape *QRShape43;
            TEdit *edtUsedAreaM2;
            TEdit *edtUsedArea;
            TEdit *edtFile;
            TEdit *edtFileNo;
            TDateTimePicker *dataSendOutDate;
            TTabSheet *tab2;
            TLabel *Label9;
            TLabel *Label10;
            TLabel *Label11;
            TLabel *Label12;
            TLabel *Label13;
            TLabel *Label14;
            TLabel *Label15;
            TLabel *Label16;
            TLabel *Label17;
            TLabel *Label18;
            TLabel *Label19;
            TLabel *Label20;
            TLabel *Label21;
            TLabel *Label22;
            TLabel *Label23;
            TLabel *Label57;
            TEdit *edtPaper_No;
            TQRShape *QRShape3;
            TQRShape *QRShape4;
            TQRShape *QRShape5;
            TQRShape *QRShape6;
            TEdit *edtOwner;
            TEdit *edtOwnerList;
            TEdit *edtPosition;
            TEdit *edtGround_No;
            TQRShape *QRShape7;
            TQRShape *QRShape8;
            TPanel *Panel1;
            TLabel *Label37;
            TLabel *Label38;
            TLabel *Label39;
            TLabel *Label40;
            TLabel *Label41;
            TLabel *Label42;
            TLabel *Label43;
            TStringGrid *gridPropertyHourse;
            TQRShape *QRShape28;
            TQRShape *QRShape29;
            TQRShape *QRShape30;
            TQRShape *QRShape31;
            TQRShape *QRShape32;
            TQRShape *QRShape33;
            TQRShape *QRShape9;
            TQRShape *QRShape10;
            TQRShape *QRShape12;
            TMemo *memRemark;
            TQRShape *QRShape19;
            TEdit *edtNote;
            TTabSheet *tab3;
            TLabel *Label58;
            TQRShape *QRShape39;
            TQRShape *QRShape40;
            TQRShape *QRShape44;
            TQRShape *QRShape45;
            TQRShape *QRShape46;
            TTabSheet *tab4;
            TQRShape *QRShape47;
            TQRShape *QRShape48;
            TQRShape *QRShape49;
            TLabel *Label59;
            TQRShape *QRShape50;
            TQRShape *QRShape51;
            TOpenPictureDialog *openDgPic;
            TADOTable *tableOwner;
            TStringField *qryIndexPaper_NO;
            TStringField *qryIndexK_Owner_NO;
            TStringField *qryIndexName;
            TLabel *Label60;
            TComboBox *cmbManageUnit;
            TComboBox *cmbMaker;
            TComboBox *cmbChecker;
            TAutoIncField *qryIndexRID;
            TStringField *qryIndexFNO;
            TStringField *qryIndexNO_Head;
            TStringField *qryIndexK_App_NO;
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
            TEdit *edtPropertyRight;
            TADOQuery *qryPicture;
        TDBImage *dimgPicture1;
            TDataSource *dsPicture;
            TDBImage *dimgPicture2;
        TStringGrid *gridOwnerList;
        TStringGrid *gridOtherProperty;
        TToolButton *ToolButton8;
        TToolButton *ToolButton9;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
        TSpeedButton *SpeedButton10;
            void __fastcall FormActivate(TObject *Sender);
            void __fastcall actAddExecute(TObject *Sender);
            void __fastcall actPostExecute(TObject *Sender);
            void __fastcall actCancleExecute(TObject *Sender);
            void __fastcall qryIndexAfterScroll(TDataSet *DataSet);
            void __fastcall actEditExecute(TObject *Sender);
            void __fastcall actDeleteExecute(TObject *Sender);
            void __fastcall edtLocateKeyPress(TObject *Sender, char &Key);
            void __fastcall cmbMakerKeyPress(TObject *Sender, char &Key);
            void __fastcall cmbCheckerKeyPress(TObject *Sender, char &Key);
            void __fastcall cmbPropertyRightKeyPress(TObject *Sender, char &Key)
                ;
            void __fastcall cmbPropertyRightChange(TObject *Sender);
            void __fastcall cmbTaxTypeKeyPress(TObject *Sender, char &Key);
            void __fastcall cmbTaxRaceKeyPress(TObject *Sender, char &Key);
            void __fastcall cmbManageUnitKeyPress(TObject *Sender, char &Key);
            void __fastcall edtFileKeyPress(TObject *Sender, char &Key);
            void __fastcall actSearchExecute(TObject *Sender);
            void __fastcall dimgPicture1DblClick(TObject *Sender);
            void __fastcall dimgPicture2DblClick(TObject *Sender);
        void __fastcall ToolButton8Click(TObject *Sender);
        void __fastcall ToolButton11Click(TObject *Sender);
        void __fastcall SpeedButton10Click(TObject *Sender);
        private:
           AnsiString g_sPaper_No;
            // User declarations
        public:
            // User declarations
            AnsiString m_sOwnerID;
            int m_nHourseNum;

            AnsiString sFileNo;
            int nFileNoLength;

            __fastcall TfmPPaper(TComponent *Owner);
           // int __fastcall InsertOwnerFun(AnsiString sOwnerName, int
          //      nPropertyFlag);
            TStringList *__fastcall GetOwnerNames(AnsiString sOwnerNames);
            void __fastcall InsertHoursePropertyFun();
            void __fastcall InsertSharePropertyFun();
            void __fastcall InsertContract_TaxFun();
            void __fastcall InsertOtherPropertyFun();
            void __fastcall InsertGroundPropertyFun();
            void __fastcall InsertPropertyPaperFun();
           // AnsiString __fastcall CreatePaper_NOFun();

            void __fastcall ShowProperty_PaperFun();
            void __fastcall ShowP_Contract_TaxFun();
            TStringList *__fastcall ShowShareProperty_PaperFun();
            //AnsiString __fastcall CreateShareProperty_NOFun();
            void __fastcall ShowP_OtherPropertyFun();
            void __fastcall ShowP_PropertyHouseFun();
            void __fastcall ShowGroundPropertyFun();
            int __fastcall getBuildingNumFun();
            int __fastcall getHourseNumFun();
            float __fastcall getHourseAreaFun();
            bool __fastcall EnsureDatAvalidFun();
            void __fastcall ControlReadOnlyFun();
            void __fastcall ControlWriteFun();
            void __fastcall ClearFormFun();
            void __fastcall EnableButtonFun();
            void __fastcall SetButtonFun();
            void __fastcall SavePaper1Fun();
            void __fastcall SavePaper2Fun();
            void __fastcall SavePaper3Fun();
            void __fastcall SavePaper4Fun();
            void __fastcall SavePaper5Fun();
            bool EnsureHourseInfoFun();
            bool EnsureTaxInfoFun();
            bool EnsureGroundInfoFun();


    };
    //---------------------------------------------------------------------------
    extern PACKAGE TfmPPaper *fmPPaper;
    //---------------------------------------------------------------------------
#endif

