/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#ifndef fmUpdatePropUH
  #define fmUpdatePropUH
  //---------------------------------------------------------------------------
  #include <Classes.hpp>
  #include <Controls.hpp>
  #include <StdCtrls.hpp>
  #include <Forms.hpp>
  #include <ADODB.hpp>
  #include <DB.hpp>
  #include <Buttons.hpp>
  #include <ExtCtrls.hpp>
  #include <ComCtrls.hpp>
  //---------------------------------------------------------------------------
  class TfmUpdateProp: public TForm
  {
      __published:  // IDE-managed Components
      TPanel *Panel1;
      TLabel *Label11;
      TEdit *edtOwner;
      TEdit *edtPosition;
      TEdit *edtGround_No;
      TLabel *Label14;
      TLabel *Label15;
      TMemo *memRemark;
      TLabel *Label22;
      TLabel *Label23;
      TPanel *panPaperNo;
      TPanel *Panel3;
      TBitBtn *BitBtn1;
      TBitBtn *BitBtn2;
      TComboBox *cmbManageUnit;
      TLabel *Label60;
      TLabel *Label20;
      TComboBox *cmbMaker;
      TLabel *Label21;
      TComboBox *cmbChecker;
      void __fastcall FormCreate(TObject *Sender);
      void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall cmbCheckerKeyPress(TObject *Sender, char &Key);
        void __fastcall cmbMakerKeyPress(TObject *Sender, char &Key);
        void __fastcall cmbManageUnitKeyPress(TObject *Sender, char &Key);
    private:
      // User declarations
    public:
      // User declarations
      __fastcall TfmUpdateProp(TComponent *Owner);
  };
  //---------------------------------------------------------------------------
  extern PACKAGE TfmUpdateProp *fmUpdateProp;
  //---------------------------------------------------------------------------
#endif
