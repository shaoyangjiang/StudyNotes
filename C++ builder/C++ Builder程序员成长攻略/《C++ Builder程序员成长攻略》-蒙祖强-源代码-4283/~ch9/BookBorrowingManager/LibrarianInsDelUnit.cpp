//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LibrarianInsDelUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLibrarianInsDel *LibrarianInsDel;
//---------------------------------------------------------------------------
__fastcall TLibrarianInsDel::TLibrarianInsDel(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLibrarianInsDel::BitBtn2Click(TObject *Sender)
{
  if(MessageDlg("ȷ��Ҫɾ���ü�¼��",mtWarning,mbOKCancel,0)==2) return; //��ɾ��
  LibrarianInsDelTable->Delete();
}
//---------------------------------------------------------------------------
void __fastcall TLibrarianInsDel::BitBtn1Click(TObject *Sender)
{
  LibrarianInsDelTable->Insert();
  LibrarianInsDelTable->FieldByName("LibrarianId")->AsString = LibrarianIdEdit->Text;
  LibrarianInsDelTable->FieldByName("Name")->AsString = NameEdit->Text;
  LibrarianInsDelTable->FieldByName("Password")->AsString = LibrarianIdEdit->Text;  //����Ĭ��Ϊ��Ա���
  LibrarianInsDelTable->Post();
  LibrarianInsDelTable->Refresh();
}
//---------------------------------------------------------------------------

