/* ���Դ�����ļ��ѱ�δע���SourceFormatX��ʽ���� */
/* ������벻����Ӵ�����Ϣ������ע������������  */
/* ���������Ϣ�������վ: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#ifndef fmInitFileNoUH
  #define fmInitFileNoUH
  //---------------------------------------------------------------------------
  #include <Classes.hpp>
  #include <Controls.hpp>
  #include <StdCtrls.hpp>
  #include <Forms.hpp>
  #include <ExtCtrls.hpp>
  #include <Graphics.hpp>
  //---------------------------------------------------------------------------
  class TfmInitFileNo: public TForm
  {
      __published:  // IDE-managed Components
      TPanel *Panel1;
      TEdit *edtFileNo;
      TLabel *Label1;
      TLabel *Label2;
      TEdit *edtFileLength;
      TButton *btnYes;
      TButton *btnNo;
      TGroupBox *GroupBox1;
      TLabel *Label4;
      TLabel *Label6;
      void __fastcall btnYesClick(TObject *Sender);
      void __fastcall edtFileNoKeyPress(TObject *Sender, char &Key);
      void __fastcall edtFileLengthKeyPress(TObject *Sender, char &Key);
        void __fastcall btnNoClick(TObject *Sender);
    private:
      // User declarations
    public:
      // User declarations
      __fastcall TfmInitFileNo(TComponent *Owner);
  };
  //---------------------------------------------------------------------------
  extern PACKAGE TfmInitFileNo *fmInitFileNo;
  //---------------------------------------------------------------------------
#endif
