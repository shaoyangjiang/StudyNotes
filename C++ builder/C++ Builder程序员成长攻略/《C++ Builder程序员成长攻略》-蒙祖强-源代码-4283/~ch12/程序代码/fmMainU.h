/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#ifndef fmMainUH
  #define fmMainUH
  //---------------------------------------------------------------------------
  #include <Classes.hpp>
  #include <Controls.hpp>
  #include <StdCtrls.hpp>
  #include <Forms.hpp>
  #include <ActnList.hpp>
  #include <ComCtrls.hpp>
  #include <ImgList.hpp>
  #include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
  //---------------------------------------------------------------------------
  class TfmMain: public TForm
  {
      __published:  // IDE-managed Components
      TStatusBar *StatusBar1;
      TMainMenu *MainMenu1;
      TMenuItem *N1;
      TMenuItem *E1;
      TActionList *actlMain;
      TAction *actExit;
      TAction *actHelp;
      TImageList *imglMain;
      TMenuItem *yewuguanli1;
    TMenuItem *MenuPaper;
      TMenuItem *N4;
      TMenuItem *N5;
      TMenuItem *N6;
      TMenuItem *N7;
      TMenuItem *N8;
      TMenuItem *N9;
    TMenuItem *MenuShare;
    TMenuItem *MenuOther;
        TImage *Image1;
        TMenuItem *N12;
        TMenuItem *N13;
        TAction *actABout;
        TMenuItem *H1;
        TMenuItem *N2;
        TMenuItem *N14;
        TMenuItem *N15;
        TMenuItem *N16;
        TMenuItem *N17;
      void __fastcall actExitExecute(TObject *Sender);
      void __fastcall MenuPaperClick(TObject *Sender);
      void __fastcall N5Click(TObject *Sender);
      void __fastcall N6Click(TObject *Sender);
      void __fastcall N9Click(TObject *Sender);
      void __fastcall N7Click(TObject *Sender);
      void __fastcall N8Click(TObject *Sender);
        void __fastcall MenuShareClick(TObject *Sender);
        void __fastcall MenuOtherClick(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    private:
      // User declarations
    public:
      // User declarations
      __fastcall TfmMain(TComponent *Owner);
      void __fastcall EnsureMenu();


  };
  //---------------------------------------------------------------------------
  extern PACKAGE TfmMain *fmMain;
  //---------------------------------------------------------------------------
#endif
