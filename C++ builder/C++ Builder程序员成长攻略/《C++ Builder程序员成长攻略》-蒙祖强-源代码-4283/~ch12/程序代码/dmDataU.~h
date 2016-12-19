/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

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
