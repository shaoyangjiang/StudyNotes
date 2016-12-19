/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#ifndef fmSharePropUH
  #define fmSharePropUH
  //---------------------------------------------------------------------------
  #include <Classes.hpp>
  #include <Controls.hpp>
  #include <StdCtrls.hpp>
  #include <Forms.hpp>
  #include <Buttons.hpp>
  #include <ExtCtrls.hpp>
  #include <Grids.hpp>
  #include <QRCtrls.hpp>
  #include <QuickRpt.hpp>
  #include <ActnList.hpp>
  #include <ADODB.hpp>
  #include <ComCtrls.hpp>
  #include <DB.hpp>
  #include <DBGrids.hpp>
  #include <ImgList.hpp>
  #include <ToolWin.hpp>
  //---------------------------------------------------------------------------
  class TfmShareProp: public TForm
  {
      __published:  // IDE-managed Components
      TPanel *panPaperNo;
      TSplitter *Splitter1;
      TToolBar *tbMain;
      TToolButton *ToolButton1;
      TToolButton *ToolButton2;
      TToolButton *ToolButton3;
      TToolButton *ToolButton5;
      TToolButton *UpdateBtn;
      TToolButton *ToolButton7;
      TPanel *plLeft;
      TPanel *plLeftTop;
      TDBGrid *dgrdIndex;
      TPanel *plMain;
      TPanel *Panel1;
      TLabel *Label3;
      TLabel *Label2;
      TLabel *Label1;
      TEdit *edtShare;
      TEdit *edtOwner;
      TActionList *actlMain;
      TAction *actAdd;
      TAction *actEdit;
      TAction *actDelete;
      TAction *actSearch;
      TAction *actPost;
      TAction *actCancle;
      TImageList *imglMain;
      TADOQuery *qryIndex;
      TADOQuery *qryMain;
      TDataSource *dscIndex;
      TDataSource *dscMain;
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
      TAutoIncField *qryIndexRID;
      TStringField *qryIndexRNO;
      TStringField *qryIndexK_Paper_NO;
      TStringField *qryIndexShareProperty_Paper_NO;
      TStringField *qryIndexK_Owner_NO;
      TBCDField *qryIndexShare;
      TIntegerField *qryIndexBuilding;
      TIntegerField *qryIndexRoom;
      TBCDField *qryIndexArea;
      TIntegerField *qryIndexK_Maker_ID;
      TIntegerField *qryIndexK_Checker_ID;
      TIntegerField *qryIndexK_ManageUnit_ID;
      TDateTimeField *qryIndexSendOutDate;
      TDateTimeField *qryIndexAcceptDate;
      TStringField *qryIndexField;
      TMemo *memRemark;
        TStringField *qryIndexremark;
      void __fastcall FormCreate(TObject *Sender);
      void __fastcall qryIndexAfterScroll(TDataSet *DataSet);
      void __fastcall actAddExecute(TObject *Sender);
      void __fastcall actEditExecute(TObject *Sender);
      void __fastcall actPostExecute(TObject *Sender);
      void __fastcall actDeleteExecute(TObject *Sender);
      void __fastcall actCancleExecute(TObject *Sender);
    private:
      // User declarations
    public:
      // User declarations
      __fastcall TfmShareProp(TComponent *Owner);
      int m_nEditFlag;

      void __fastcall EditRecordFun();
      void __fastcall InsertRecordFun();
      void __fastcall UpdateMainFormInfoFun();
      void __fastcall ControlWriteFun();
      void __fastcall ControlReadOnlyFun();

  };
  //---------------------------------------------------------------------------
  extern PACKAGE TfmShareProp *fmShareProp;
  //---------------------------------------------------------------------------
#endif
