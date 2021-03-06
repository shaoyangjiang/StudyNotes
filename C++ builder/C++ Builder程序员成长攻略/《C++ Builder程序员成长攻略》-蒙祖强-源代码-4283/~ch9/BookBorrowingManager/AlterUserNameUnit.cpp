//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AlterUserNameUnit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAlterUserNameForm *AlterUserNameForm;
//---------------------------------------------------------------------------
__fastcall TAlterUserNameForm::TAlterUserNameForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAlterUserNameForm::ConfirBtnClick(TObject *Sender)
{    
  if(MainForm->UserName != OldUserNameEdit->Text)
  {
     ShowMessage("请检查输入的原来用户名（注：只能修改自己的帐号）！");
     return;
  }
  if(MainForm->PassStr!=OldPassEdit->Text)
  {
     ShowMessage("请检查输入的原来密码（注：只能修改自己的帐号）！");
     return;
  }

  if(NewPassEdit->Text != ReNewPassEdit->Text)
  {
     ShowMessage("请检查新设置的密码！");
     return;
  }

  ConfirQuery->SQL->Text = "Update ReaderTable set UserName = '" + NewUserNameEdit->Text + "',Password = '" + NewPassEdit->Text + "' where UserName = '"+OldUserNameEdit->Text+"';";
  ConfirQuery->ExecSQL();

  MainForm->UserName = NewUserNameEdit->Text;
  MainForm->PassStr = NewPassEdit->Text;
  ShowMessage("成功设置密码！");  
}
//---------------------------------------------------------------------------
void __fastcall TAlterUserNameForm::RetryBtnClick(TObject *Sender)
{
  OldUserNameEdit->Text = "";
  OldPassEdit->Text = "";
  NewUserNameEdit->Text = "";
  NewPassEdit->Text = "";
  ReNewPassEdit->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TAlterUserNameForm::FormCreate(TObject *Sender)
{
  ConfirBtn->Enabled = true;
  if(MainForm->IdentityStr=="读书馆工作人员")
  {
    OldUserNameEdit->Text = MainForm->UserName;
    OldUserNameEdit->Enabled = false;
  }
  if(MainForm->IdentityStr=="系统管理员")
  {
    ConfirBtn->Enabled = false; //不提供系统管理员帐号的修改功能
  }
}
//---------------------------------------------------------------------------

