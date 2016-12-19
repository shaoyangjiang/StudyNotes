/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#ifndef fmMarkermanageUH
  #define fmMarkermanageUH
  //---------------------------------------------------------------------------
  #include <Classes.hpp>
  #include <Controls.hpp>
  #include <StdCtrls.hpp>
  #include <Forms.hpp>
  #include <ADODB.hpp>
  #include <ComCtrls.hpp>
  #include <DB.hpp>
  #include <DBGrids.hpp>
  #include <ExtCtrls.hpp>
  #include <Grids.hpp>
  #include <ToolWin.hpp>
  #include <ActnList.hpp>
  #include <DBCtrls.hpp>
  #include <ImgList.hpp>
  #include <Mask.hpp>
  //---------------------------------------------------------------------------
  class TfmMarkermanage: public TForm
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
      TActionList *actlMain;
      TAction *actAdd;
      TAction *actEdit;
      TAction *actDelete;
      TAction *actSearch;
      TAction *actPost;
      TAction *actCancle;
      TImageList *imglMain;
      TDataSource *dscIndex;
      TLabel *Label2;
      TEdit *edtMarker;
      TToolButton *ToolButton2;
        TADOQuery *tabIndex;
        TAutoIncField *tabIndexRID;
        TIntegerField *tabIndexK_Marker_ID;
        TStringField *tabIndexMarker;
        TToolButton *ToolButton4;
        TToolButton *ToolButton6;
        TToolButton *ToolButton7;
        TToolButton *ToolButton8;
      void __fastcall tabIndexAfterScroll(TDataSet *DataSet);
      void __fastcall actAddExecute(TObject *Sender);
      void __fastcall actPostExecute(TObject *Sender);
      void __fastcall actCancleExecute(TObject *Sender);
      void __fastcall FormActivate(TObject *Sender);
      void __fastcall actDeleteExecute(TObject *Sender);
        void __fastcall ToolButton4Click(TObject *Sender);

    private:
      // User declarations
    public:
      // User declarations
      __fastcall TfmMarkermanage(TComponent *Owner);
      void __fastcall EnableButtonFun(bool nEnableFlagArray[4]);

  };
  //---------------------------------------------------------------------------
  extern PACKAGE TfmMarkermanage *fmMarkermanage;
  //---------------------------------------------------------------------------
#endif
