/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#ifndef fmVBaseUH
  #define fmVBaseUH
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
  class TfmVBase: public TForm
  {
      __published:  // IDE-managed Components
      TSplitter *Splitter1;
      TToolBar *tbMain;
      TToolButton *ToolButton1;
      TToolButton *ToolButton2;
      TToolButton *ToolButton3;
      TToolButton *ToolButton4;
      TToolButton *ToolButton5;
      TToolButton *ToolButton6;
      TToolButton *ToolButton7;
      TPanel *plLeft;
      TPanel *plLeftTop;
      TLabel *lblLeftTop;
      TEdit *edtLocate;
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
      TADOQuery *qryIndex;
      TADOQuery *qryMain;
      TDataSource *dscIndex;
      TDataSource *dscMain;
      void __fastcall ToolButton4Click(TObject *Sender);
      void __fastcall actEditExecute(TObject *Sender);
      void __fastcall actDeleteExecute(TObject *Sender);
      void __fastcall actSearchExecute(TObject *Sender);
      void __fastcall actPostExecute(TObject *Sender);
      void __fastcall actCancleExecute(TObject *Sender);
      void __fastcall actAddExecute(TObject *Sender);
    private:
      // User declarations
    public:
      // User declarations
      __fastcall TfmVBase(TComponent *Owner);
  };
  //---------------------------------------------------------------------------
  extern PACKAGE TfmVBase *fmVBase;
  //---------------------------------------------------------------------------
#endif
