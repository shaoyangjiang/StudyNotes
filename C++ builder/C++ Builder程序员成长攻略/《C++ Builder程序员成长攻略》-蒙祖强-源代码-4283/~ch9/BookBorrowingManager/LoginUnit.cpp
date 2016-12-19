//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoginUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLoginForm *LoginForm;
//---------------------------------------------------------------------------
__fastcall TLoginForm::TLoginForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::FormCreate(TObject *Sender)
{
  UserEdit->Text = "myname1";
  PassEdit->Text = "123456";
  IdentityComboBox->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::BitBtn1Click(TObject *Sender)
{
ShowMessage("sssssssssssssssssss");
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::Button1Click(TObject *Sender)
{
 ModalResult2 = mrYes; 
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::Button2Click(TObject *Sender)
{
  UserEdit->Text = "";
  PassEdit->Text = "";
  IdentityComboBox->ItemIndex = 0;
}
//---------------------------------------------------------------------------
