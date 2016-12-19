/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#ifndef fmTaxRaceH
  #define fmTaxRaceH
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
  class TForm1: public TForm
  {
      __published:  // IDE-managed Components
      TSplitter *Splitter1;
      TToolBar *tbMain;
      TToolButton *ToolButton1;
      TToolButton *ToolButton5;
      TToolButton *ToolButton6;
      TToolButton *ToolButton7;
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
      TADOTable *tabIndex;
      TAutoIncField *tabIndexRID;
      TIntegerField *tabIndexK_TaxRace_ID;
      TStringField *tabIndexTaxRace;
      void __fastcall actPostExecute(TObject *Sender);
      void __fastcall actCancleExecute(TObject *Sender);
      void __fastcall actAddExecute(TObject *Sender);
      void __fastcall tabIndexAfterScroll(TDataSet *DataSet);
    private:
      // User declarations
    public:
      // User declarations
      __fastcall TForm1(TComponent *Owner);
  };
  //---------------------------------------------------------------------------
  extern PACKAGE TForm1 *Form1;
  //---------------------------------------------------------------------------
#endif
