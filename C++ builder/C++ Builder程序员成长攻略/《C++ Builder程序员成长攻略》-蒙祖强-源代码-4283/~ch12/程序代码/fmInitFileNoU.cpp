/* ���Դ�����ļ��ѱ�δע���SourceFormatX��ʽ���� */
/* ������벻����Ӵ�����Ϣ������ע������������  */
/* ���������Ϣ�������վ: http://cn.textrush.com  */

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
        ::MessageBox(this->Handle, "��ʼ����Ϊ�գ����������룡 ", "����", MB_OK)
            ;
        return ;
    }
    if (edtFileNo->Text == "")
    {
        ::MessageBox(this->Handle, "���볤��Ϊ�գ����������룡 ", "����", MB_OK)
            ;
        return ;
    }
    AnsiString sSql;
    TADOQuery *q(dmData->qry);
    sSql = "insert into InitFileNo  values(" + edtFileLength->Text + ",'" +
        edtFileNo->Text + "')";
    ExecuteSql(q, sSql);
    sSql = "insert into A_PropertyRight  values(1,'������')";
    ExecuteSql(q, sSql);
    sSql = "insert into A_PropertyRight  values(2,'������')";
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


