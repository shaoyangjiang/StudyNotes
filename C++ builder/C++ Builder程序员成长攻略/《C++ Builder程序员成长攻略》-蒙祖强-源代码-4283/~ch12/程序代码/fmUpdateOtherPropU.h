/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#ifndef fmUpdateOtherPropUH
  #define fmUpdateOtherPropUH
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
  //---------------------------------------------------------------------------
  class TfmUpdateOtherProp: public TForm
  {
      __published:  // IDE-managed Components
      TPanel *Panel1;
      TPanel *panPaperNo;
      TPanel *Panel3;
      TQRShape *QRShape2;
      TLabel *Label26;
      TLabel *Label36;
      TLabel *Label28;
      TLabel *Label29;
      TLabel *Label30;
      TLabel *Label31;
      TLabel *Label33;
      TLabel *Label32;
      TLabel *Label35;
      TLabel *Label34;
      TStringGrid *gridOtherProperty;
      TQRShape *QRShape11;
      TQRShape *QRShape15;
      TLabel *Label27;
      TQRShape *QRShape17;
      TQRShape *QRShape18;
      TPanel *Panel4;
      TBitBtn *BitBtn1;
      TBitBtn *BitBtn2;
      TLabel *Label25;
      TQRShape *QRShape1;
      TQRShape *QRShape3;
      TQRShape *QRShape4;
      TQRShape *QRShape5;
      TQRShape *QRShape20;
      TQRShape *QRShape6;
      TQRShape *QRShape7;
      TQRShape *QRShape8;
      void __fastcall BitBtn1Click(TObject *Sender);
      void __fastcall FormActivate(TObject *Sender);
    private:
      // User declarations
    public:
      // User declarations
      __fastcall TfmUpdateOtherProp(TComponent *Owner);
      bool __fastcall EnsureDatAvalidFun(int);
  };
  //---------------------------------------------------------------------------
  extern PACKAGE TfmUpdateOtherProp *fmUpdateOtherProp;
  //---------------------------------------------------------------------------
#endif
