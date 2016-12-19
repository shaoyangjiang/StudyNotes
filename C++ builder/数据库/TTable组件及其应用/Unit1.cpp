//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InsertClick(TObject *Sender)
{
        try
        {
                Table1->Insert();
                Table1->FieldByName("Name")->Value = Edit1->Text;
                Table1->FieldByName("Capital")->Value = Edit2->Text;
                Table1->FieldByName("Continent")->Value = Edit3->Text;
                Table1->FieldByName("Area")->Value =StrToInt(Edit4->Text);
                Table1->FieldByName("Population")->Value = StrToInt(Edit5->Text);
                Table1->Post();
        }
        catch(...)
        {
                MessageBox(NULL,"������ִ���","������Ϣ",MB_OK);
        }
        Edit1->Text = "";
        Edit2->Text = "";
        Edit3->Text = "";
        Edit4->Text = "";
        Edit5->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteClick(TObject *Sender)
{
        if(MessageDlg("��¼"+Table1->FieldByName("Name")->AsString + "����ɾ����ȷ����",mtWarning,TMsgDlgButtons()<<mbYes<<mbNo,NULL) == mbYes)
        Table1->Delete();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
      /*  Table1->Edit();
        Table1->Insert();
        Table1->SetRecord(ARRAYOFCONST(("china","beijing","Asia",9600000,130000000)));
        Table1->Post();   */

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        //ʹ��Setkey������GotoKey�������ϲ������ݼ�¼
        Table1->IndexFieldNames = "Name";
        Table1->SetKey();
        Table1->FieldByName("Name")->Value = "china";
        if(!Table1->GotoKey())
                MessageBox(NULL,"�����ҵ�","��Ϣ",MB_OK);

      /*  //ʹ��FindKey�������������ݱ��еļ�¼
        AnsiString queryString = InputBox("��ѯ","��������Ҫ��ѯ�Ĺ���","");
        if(!Table1->FindKey(ARRAYOFCONST(queryString)))
                MessageBox(NULL,"û���ҵ����ϵļ�¼��","��Ϣ",MB_OK);*/
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit6KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      /*  //ʵ��ģ������
        if(Key==VK_RETURN)
                Table1->FindNearest(ARRAYOFCONST(Edit6->Text));      */
}
//---------------------------------------------------------------------------
