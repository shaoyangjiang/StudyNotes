/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------
  #ifndef SysFuncsH
  #define SysFuncsH
  #include <vcl.h>
  #include <classes.hpp>
  #include <Db.hpp>
  #include <dbtables.hpp>
  #include <comctrls.hpp>
  #include <Grids.hpp>
  #include <alloc.h>
  #include <ADODB.hpp>


  //定义单引号
  #define dyh AnsiString(char(39))
  //定义双引号
  //#define syh AnsiString(char(34))
  #define syh "'"

  typedef struct NodeInfos
  {
    AnsiString notes;
    int id;
  } TNodeInfos;

  typedef TNodeInfos *PNodeInfos;

  //---------------------------------------------------------------------------
  void __fastcall ExecuteSql(TADOQuery *Que, AnsiString sSQL);
  void __fastcall ExecuteSql(TADOQuery *Que, TStringList *sSQL);
  void __fastcall ResultSql(TADOQuery *Que, AnsiString sSQL); //返回数据集
  int __fastcall GetMaxRecId(TADOQuery *Que, AnsiString TableName, AnsiString
    IdFieldName, AnsiString sInitIDCModel);
  int __fastcall GetMaxRecId(TADOQuery *Que, AnsiString TableName, AnsiString
    IdFieldName, AnsiString sInitIDCModel, AnsiString sSql);
  bool __fastcall InputText(const System::AnsiString ACaption, const System
    ::AnsiString APrompt, System::AnsiString &Value); //经改造的输入对话框

  bool __fastcall InputText(const System::AnsiString ACaption, const System
    ::AnsiString ALabel1, const System::AnsiString ALabel2, System::AnsiString
    &Value1, System::AnsiString &Value2, int LimitLen1, int LimitLen2, bool
    bIsPwd); //经改造的可以输入双项值的输入对话框

  bool __fastcall SelectList(const System::AnsiString ACaption, const System
    ::AnsiString APrompt, TStringList *sList, int nDefaultIdx, System
    ::AnsiString &Value); //新型列表选择对话框
  bool __fastcall SelectDate(const System::AnsiString ACaption, const System
    ::AnsiString APrompt, System::AnsiString &Value); //新型日期选择对话框
  bool __fastcall InputPwd(const System::AnsiString ACaption, const System
    ::AnsiString APrompt, System::AnsiString &Value); //密码输入对话框

  AnsiString __fastcall DelDec(AnsiString Str); //删除字符串中的小数点

  AnsiString __fastcall LeftFillStr(AnsiString Str, AnsiString c, int nLength);
    //左边填充指定的字符
  AnsiString __fastcall RightFillStr(AnsiString Str, AnsiString c, int nLength)
    ; //右边填充指定的字符
  AnsiString __fastcall FStr(double x, int nDec);
    //将浮点数格式化为nDec位小数的固定格式的字符串
  TTreeNode *__fastcall AddRootInfoNode(TTreeView *TreeView, AnsiString Text,
    AnsiString snotes, int nid);
  TTreeNode *__fastcall AddSubInfoNode(TTreeView *TreeView, TTreeNode *Node,
    AnsiString Text, AnsiString snotes, int nid);

  AnsiString __fastcall CurrentYear(); //获取当前四位年份
  AnsiString __fastcall CurrentMonth(); //获取当前月份
  AnsiString __fastcall CurrentDay(); //获取当前日

  void __fastcall LockDesk(); //锁桌面
  void __fastcall UnLockDesk(); //桌面开锁

  void __fastcall ReadGrdColW(TStringGrid *grd, AnsiString sFileName);
    //读网格列宽
  void __fastcall WriteGrdColW(TStringGrid *grd, AnsiString sFileName);
    //写网格列宽

  void __fastcall ReadLVColW(TListView *grd, AnsiString sFileName); //读网格列宽
  void __fastcall WriteLVColW(TListView *grd, AnsiString sFileName);
    //写网格列宽


  //void __fastcall HelpCodeFind(TEdit *E,int nFlag,TEdit *E1=NULL);
  //void __fastcall HelpCodeFind(TComboBox *E,int nFlag,TEdit *E1=NULL);

  AnsiString __fastcall Cypher(System::AnsiString Value);
  AnsiString __fastcall Decrypt(System::AnsiString Value);

  bool __fastcall ChkPower(AnsiString sPowerStr, int nPowerPlace);

  AnsiString __fastcall GetPY(String sSrc);

  AnsiString GetRec(TADOQuery *Que, AnsiString sTableName, AnsiString
    sFieldName, AnsiString sSql);
  void FillCB(TComboBox *cb, TADOQuery *Que, AnsiString sTableName, AnsiString
    sFieldName, AnsiString sSql = "", int nSelected =  - 1);
  void FillLB(TListBox *lb, TADOQuery *Que, AnsiString sTableName, AnsiString
    sFieldName, AnsiString sSql = "");
  TDate MakeDate(AnsiString strDate);
  void LockInputLen(TEdit *edit, int nLen);
  void MakeOperateLog(TADOQuery *Que, AnsiString sOperator, AnsiString
    sTableName, AnsiString sTableIdValue);
  AnsiString __fastcall GetMaxRecAddOne(TADOQuery *Que, AnsiString TableName,
    AnsiString IdFieldName, AnsiString sInitIDCModel, AnsiString sSql);


  int __fastcall GetID(TADOQuery *Que, AnsiString TableName, AnsiString
    getIdName, AnsiString getIdFrom, AnsiString sValue);

  AnsiString __fastcall GetNameFieldFromIDFieldN(TADOQuery *Que, AnsiString
    sTableName, AnsiString sIDField, AnsiString sNameField, int nValue);

  AnsiString __fastcall GetNameFieldFromIDFieldS(TADOQuery *Que, AnsiString
    sTableName, AnsiString sIDField, AnsiString sNameField, AnsiString sValue);
  int __fastcall InsertOwnerFun(TADOQuery * q,AnsiString sOwnerName, int
    nPropertyFlag) ;
    AnsiString __fastcall CreatePaper_NOFun(TADOQuery *q);
    AnsiString __fastcall CreateShareProperty_NOFun(TADOQuery *q);
 
#endif
