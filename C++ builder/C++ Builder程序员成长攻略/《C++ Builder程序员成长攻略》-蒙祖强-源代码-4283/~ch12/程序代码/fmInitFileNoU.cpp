/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "fmInitFileNoU.h"
#include "dmDataU.h"
#include "SysFuncs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmInitFileNo *fmInitFileNo;
//---------------------------------------------------------------------------
__fastcall TfmInitFileNo::TfmInitFileNo(TComponent *Owner): TForm(Owner){}
//---------------------------------------------------------------------------



void __fastcall TfmInitFileNo::btnYesClick(TObject *Sender)
{
    if (edtFileNo->Text == "")
    {
        ::MessageBox(this->Handle, "初始号码为空，请重新输入！ ", "警告", MB_OK)
            ;
        return ;
    }
    if (edtFileNo->Text == "")
    {
        ::MessageBox(this->Handle, "号码长度为空，请重新输入！ ", "警告", MB_OK)
            ;
        return ;
    }
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    sSql = "insert into InitFileNo  values(" + edtFileLength->Text + ",'" +
        edtFileNo->Text + "')";
    ExecuteSql(q, sSql);
    sSql = "insert into A_PropertyRight  values(1,'所有人')";
    ExecuteSql(q, sSql);
    sSql = "insert into A_PropertyRight  values(2,'共有人')";
    ExecuteSql(q, sSql);

    this->Close();

}

//---------------------------------------------------------------------------

void __fastcall TfmInitFileNo::edtFileNoKeyPress(TObject *Sender, char &Key)
{
    if (Key >= '0' && Key <= '9')
    {
        return ;
    }
    else
    {
        Key == 0;
    }
}

//---------------------------------------------------------------------------
void __fastcall TfmInitFileNo::edtFileLengthKeyPress(TObject *Sender, char &Key)
{

    if (Key >= '0' && Key <= '9')
    {
        return ;
    }
    else
    {
        Key == 0;
    }
}

//---------------------------------------------------------------------------
void __fastcall TfmInitFileNo::btnNoClick(TObject *Sender)
{
Close();
exit(0);
}
//---------------------------------------------------------------------------


