/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#ifndef fmUpdateTaxUH
  #define fmUpdateTaxUH
  //---------------------------------------------------------------------------
  #include <Classes.hpp>
  #include <Controls.hpp>
  #include <StdCtrls.hpp>
  #include <Forms.hpp>
  #include <Buttons.hpp>
  #include <ComCtrls.hpp>
  #include <ExtCtrls.hpp>
  //---------------------------------------------------------------------------
  class TfmUpdateTax: public TForm
  {
      __published:  // IDE-managed Components
      TPanel *Panel1;
      TPanel *panPaperNo;
      TPanel *Panel3;
      TPanel *Panel4;
      TLabel *Label3;
      TDateTimePicker *dataStartData;
      TLabel *Label4;
      TEdit *EdtPrice;
      TLabel *Label5;
      TComboBox *cmbTaxType;
      TComboBox *cmbTaxRace;
      TLabel *Label6;
      TLabel *Label8;
      TEdit *edtTax;
      TEdit *edtNote;
      TLabel *Label24;
      TLabel *Label2;
      TBitBtn *BitBtn1;
      TBitBtn *BitBtn2;
      void __fastcall BitBtn1Click(TObject *Sender);
      void __fastcall FormCreate(TObject *Sender);
      void __fastcall cmbTaxTypeKeyPress(TObject *Sender, char &Key);
      void __fastcall cmbTaxRaceKeyPress(TObject *Sender, char &Key);
    private:
      // User declarations
    public:
      // User declarations
      bool m_bInsertFlag;
      __fastcall TfmUpdateTax(TComponent *Owner);
      bool __fastcall EnsureDatAvalidFun();
  };
  //---------------------------------------------------------------------------
  extern PACKAGE TfmUpdateTax *fmUpdateTax;
  //---------------------------------------------------------------------------
#endif
