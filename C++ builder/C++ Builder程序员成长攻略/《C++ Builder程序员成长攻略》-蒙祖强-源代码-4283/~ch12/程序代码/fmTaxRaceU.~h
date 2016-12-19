//---------------------------------------------------------------------------

#ifndef fmTaxRaceUH
  #define fmTaxRaceUH
  //---------------------------------------------------------------------------
  #include <Classes.hpp>
  #include <Controls.hpp>
  #include <StdCtrls.hpp>
  #include <Forms.hpp>
  #include <ActnList.hpp>
  #include <ADODB.hpp>
  #include <ComCtrls.hpp>
  #include <DB.hpp>
  #include <DBGrids.hpp>
  #include <ExtCtrls.hpp>
  #include <Grids.hpp>
  #include <ImgList.hpp>
  #include <ToolWin.hpp>
  //---------------------------------------------------------------------------
  class TfmTaxRace: public TForm
  {
      __published:  // IDE-managed Components
      TSplitter *Splitter1;
      TToolBar *tbMain;
        TToolButton *ToolButton0;
      TToolButton *ToolButton5;
        TToolButton *ToolButton1;
        TToolButton *ToolButton3;
      TPanel *plLeft;
      TPanel *plLeftTop;
      TDBGrid *dgrdIndex;
      TPanel *plMain;
      TLabel *Label2;
      TEdit *edtMarker;
      TActionList *actlMain;
      TAction *actAdd;
      TAction *actEdit;
      TAction *actDelete;
      TAction *actSearch;
      TAction *actPost;
      TAction *actCancle;
      TImageList *imglMain;
      TDataSource *dscIndex;
      TToolButton *ToolButton2;
        TADOQuery *tabIndex;
        TAutoIncField *tabIndexRID;
        TIntegerField *tabIndexK_TaxRace_ID;
        TStringField *tabIndexTaxRace;
        TToolButton *ToolButton4;
        TToolButton *ToolButton6;
        TToolButton *ToolButton7;
        TToolButton *ToolButton8;
      void __fastcall actPostExecute(TObject *Sender);
      void __fastcall actCancleExecute(TObject *Sender);
      void __fastcall actAddExecute(TObject *Sender);
      void __fastcall tabIndexAfterScroll(TDataSet *DataSet);
      void __fastcall FormActivate(TObject *Sender);
      void __fastcall actDeleteExecute(TObject *Sender);
        void __fastcall ToolButton4Click(TObject *Sender);
    private:
      // User declarations
    public:
      // User declarations
      __fastcall TfmTaxRace(TComponent *Owner);
      void __fastcall EnableButtonFun(bool nEnableFlagArray[4]);
  };
  //---------------------------------------------------------------------------
  extern PACKAGE TfmTaxRace *fmTaxRace;
  //---------------------------------------------------------------------------
#endif
