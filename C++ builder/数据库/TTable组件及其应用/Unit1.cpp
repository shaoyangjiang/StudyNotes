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
                MessageBox(NULL,"程序出现错误","出错信息",MB_OK);
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
        if(MessageDlg("记录"+Table1->FieldByName("Name")->AsString + "将被删除，确定吗？",mtWarning,TMsgDlgButtons()<<mbYes<<mbNo,NULL) == mbYes)
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
        //使用Setkey方法和GotoKey方法相结合查找数据记录
        Table1->IndexFieldNames = "Name";
        Table1->SetKey();
        Table1->FieldByName("Name")->Value = "china";
        if(!Table1->GotoKey())
                MessageBox(NULL,"不能找到","信息",MB_OK);

      /*  //使用FindKey方法来查找数据表中的记录
        AnsiString queryString = InputBox("查询","你输入你要查询的国家","");
        if(!Table1->FindKey(ARRAYOFCONST(queryString)))
                MessageBox(NULL,"没有找到符合的记录！","信息",MB_OK);*/
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit6KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      /*  //实现模糊查找
        if(Key==VK_RETURN)
                Table1->FindNearest(ARRAYOFCONST(Edit6->Text));      */
}
//---------------------------------------------------------------------------
