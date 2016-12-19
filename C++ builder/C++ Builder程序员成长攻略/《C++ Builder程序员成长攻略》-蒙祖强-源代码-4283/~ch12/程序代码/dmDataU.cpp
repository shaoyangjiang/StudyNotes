/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dmDataU.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TdmData *dmData;
//---------------------------------------------------------------------------
__fastcall TdmData::TdmData(TComponent *Owner): TDataModule(Owner){}
//---------------------------------------------------------------------------
Variant __fastcall TdmData::GetAValue(AnsiString sSQL)
{
    ////
}
void __fastcall TdmData::DataModuleCreate(TObject *Sender)
{
 Conn->Connected = false;
    try
    {
        Conn->ConnectionString = "FILE NAME="
          + ExtractFilePath(Application->ExeName) +  "Conn.UDL";
        Conn->Connected = true;
    }
    catch ( ... )
    {
        MessageDlg("连接数据库失败！请检查配置。", mtError, TMsgDlgButtons() << mbOK, 0);
        Application->Terminate();
    };
}
//---------------------------------------------------------------------------

