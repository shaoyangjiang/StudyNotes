/* ���Դ�����ļ��ѱ�δע���SourceFormatX��ʽ���� */
/* ������벻����Ӵ�����Ϣ������ע������������  */
/* ���������Ϣ�������վ: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#ifndef dmDataUH
  #define dmDataUH
  //---------------------------------------------------------------------------
  #include <Classes.hpp>
  #include <Controls.hpp>
  #include <StdCtrls.hpp>
  #include <Forms.hpp>
  #include <ADODB.hpp>
  #include <DB.hpp>
  //---------------------------------------------------------------------------
  class TdmData: public TDataModule
  {
      __published:  // IDE-managed Components
      TADOConnection *Conn;
      TADOQuery *qry;
        void __fastcall DataModuleCreate(TObject *Sender);
    private:
      // User declarations
    public:
      // User declarations
      __fastcall TdmData(TComponent *Owner);
      Variant __fastcall GetAValue(AnsiString sSQL);
  };
  //---------------------------------------------------------------------------
  extern PACKAGE TdmData *dmData;
  //---------------------------------------------------------------------------
#endif
