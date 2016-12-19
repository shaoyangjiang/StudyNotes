//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SysFuncs.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
/*
自定义函数
函数说明：
产生一个共有权证号  共有权的长度为10：
 */
AnsiString __fastcall CreateShareProperty_NOFun(TADOQuery *q)
{

    AnsiString sSql;
    AnsiString sShareProperty_NO;
    sSql = "select ShareProperty_Paper_NO from ShareProperty_Paper";
    ResultSql(q, sSql);
    q->First();
    sShareProperty_NO = "0000000000";
    while (!q->Eof)
    {
        AnsiString sNO_Buf;

        sNO_Buf = q->FieldByName("ShareProperty_Paper_NO")->AsString;

        if (strcmp(sNO_Buf.c_str(), sShareProperty_NO.c_str()))
        {
            sShareProperty_NO = sNO_Buf;
        }
        q->Next();
    }
    while (sShareProperty_NO.Length() > 0 && sShareProperty_NO.SubString(1, 1)
        != "0")
    {
        sShareProperty_NO = sShareProperty_NO.SubString(2,
            sShareProperty_NO.Length());
    }
    sShareProperty_NO = IntToStr((StrToInt(sShareProperty_NO) + 1));
    while (sShareProperty_NO.Length() < 10)
    {
        sShareProperty_NO = "0" + sShareProperty_NO;
    }
    return sShareProperty_NO;
}




/*
自定义函数
函数说明：
产生一个房产证号  房产证的长度为10：
 */
AnsiString __fastcall CreatePaper_NOFun(TADOQuery *q)
{
    AnsiString sSql;
    AnsiString sPaper_NO;
    int nFileNoLength;
    sSql = "select * from InitFileNo";
    ResultSql(q, sSql);

    if (q->RecordCount > 0)
    {
        sPaper_NO = q->FieldByName("FileNoStart")->AsString;
        nFileNoLength = q->FieldByName("FileNoLength")->AsInteger;
        sPaper_NO = sPaper_NO.Trim();
        sPaper_NO = IntToStr((StrToInt(sPaper_NO) + 1));
        while (sPaper_NO.Length() < nFileNoLength)
        {
                sPaper_NO = "0" + sPaper_NO;
        }
    }
     else
     {
         sPaper_NO = "0000000001";
         nFileNoLength = 10;
         sSql = "update InitFileNo set FileNoLength="+IntToStr(nFileNoLength)+ ",FileNoStart='" + sPaper_NO +"'";
         ExecuteSql(q, sSql);
     }
     return sPaper_NO;
       /* sSql = "select Paper_NO from Property_Paper";
        ResultSql(q, sSql);
        q->First();
        if (q->Eof)
        {
            while (sPaper_NO.Length() < nFileNoLength)
            {
                sPaper_NO = "0" + sPaper_NO;
            }
            return sPaper_NO;

        } */
    
    /*
    else
    {
        sPaper_NO = "0000000000";
        nFileNoLength = 10;
    }

    q->First();
    while (!q->Eof)
    {
        AnsiString sNO_Buf;
        sNO_Buf = q->FieldByName("Paper_NO")->AsString;
        if (strcmp(sNO_Buf.c_str(), sPaper_NO.c_str()))
        {
            sPaper_NO = sNO_Buf;
        }
        q->Next();
    }

    while (sPaper_NO.Length() > 0 && sPaper_NO.SubString(1, 1) != "0")
    {
        sPaper_NO = sPaper_NO.SubString(2, sPaper_NO.Length());
    }

    sPaper_NO = IntToStr((StrToInt(sPaper_NO) + 1));
    while (sPaper_NO.Length() < nFileNoLength)
    {
        sPaper_NO = "0" + sPaper_NO;
    }
    return sPaper_NO;
    */

}
//---------------------------------------------------------------------------

int __fastcall InsertOwnerFun(TADOQuery *q,AnsiString sOwnerName, int
    nPropertyFlag)
{
    int nPropertyRightID; //所有权性质ID
    int nOwnerID; //所有权人ID
    AnsiString sSql;

    nOwnerID = GetMaxRecId(q, "P_Owner", "RNO", "0") + 1; //产生一个产权人ID

    //获取所有权性质
    if (nPropertyFlag == 1)
    {
        sSql =
            "select K_PropertyRight_ID from A_PropertyRight where PropertyRight='" + sOwnerName.Trim() + "'";
    }
    if (nPropertyFlag == 2)
    {
        sSql =
            "select K_PropertyRight_ID from A_PropertyRight where PropertyRight='共有人'";
    }
    ResultSql(q, sSql);
    if (q->RecordCount > 0)
    {
        nPropertyRightID = q->FieldByName("K_PropertyRight_ID")->AsInteger;
    }
    //把产权人加入到产权人表中去
    sSql = "insert into P_Owner values(";
    sSql += IntToStr(nOwnerID) + ","; //ID
    sSql += "'" + sOwnerName + "',"; //产权人姓名
    sSql += "'#',"; //产权人性别
    sSql += "0,"; //产权人年龄
    sSql += "'#',"; //产权人籍贯
    sSql += "'#',"; //产权人住址
    sSql += "'#',"; //产权人工作单位
    sSql += "'#',"; //产权人职业
    sSql += "'#',"; //产权人关系
    sSql += "0.0,"; //应占份数
    sSql += IntToStr(nPropertyRightID) + ")"; //所有权性质
    ExecuteSql(q, sSql);
    return nOwnerID;
}
void __fastcall ExecuteSql(TADOQuery *Que, AnsiString sSQL)
{
    if (Que->Active)
        Que->Active = false;

    if (Que->Filter != "")
    {
        Que->Filter = "";
    }
    if (Que->Filtered)
    {
        Que->Filtered = false;
    }
    Que->SQL->Clear();
    Que->SQL->Add(sSQL);
    //Que->Prepare();
    Que->ExecSQL();
    //Que->UnPrepare();
} //executeSql(TQuery *Que,AnsiString sSQL)
//---------------------------------------------------------------------------
void __fastcall ExecuteSql(TADOQuery *Que, TStringList *sSQL)
{
    if (Que->Active)
        Que->Active = false;

    if (Que->Filter != "")
    {
        Que->Filter = "";
    }
    if (Que->Filtered)
    {
        Que->Filtered = false;
    }
    Que->SQL->Clear();
    Que->SQL->Assign(sSQL);
    //Que->Prepare();
    Que->ExecSQL();
    //Que->UnPrepare();
} //executeSql(TQuery *Que,TStringList *sSQL)
//---------------------------------------------------------------------------
void __fastcall ResultSql(TADOQuery *Que, AnsiString sSQL) //返回数据集
{
    if (Que->Active)
    {
        Que->Active = FALSE;
    }
    if (Que->Filter != "")
    {
        Que->Filter = "";
    }
    if (Que->Filtered)
    {
        Que->Filtered = false;
    }
    Que->SQL->Clear();
    Que->SQL->Add(sSQL);
    Que->ExecSQL();

    try
    {
        Que->Active = true;
    }
    
    catch (...)
    {
        return ;
    }
} //ResultSql()
//---------------------------------------------------------------------------
int __fastcall GetMaxRecId(TADOQuery *Que, AnsiString TableName, AnsiString
    IdFieldName, AnsiString sInitIDCModel)
{
    AnsiString sSQL;
    sSQL = "select * from " + TableName;
    ExecuteSql(Que, sSQL);
    Que->Active = true;
    if (Que->FieldCount == 0)
    {
        return StrToInt(sInitIDCModel);
    }
    sSQL = "select max(" + IdFieldName + ") from " + TableName;
    ExecuteSql(Que, sSQL);
    Que->Active = true;
    if (Que->Fields->Fields[0]->AsInteger < StrToInt(sInitIDCModel))
        return StrToInt(sInitIDCModel);
    else
        return Que->Fields->Fields[0]->AsInteger;




}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int __fastcall GetMaxRecId(TADOQuery *Que, AnsiString TableName, AnsiString
    IdFieldName, AnsiString sInitIDCModel, AnsiString sSql)
{
    AnsiString sSQL;
    sSQL = "select max(" + IdFieldName + ") from " + TableName + " " + sSql;
    ExecuteSql(Que, sSQL);
    Que->Active = true;
    if (!Que->Fields->Fields[0]->IsNull)
    {
        if (Que->Fields->Fields[0]->AsInteger < StrToInt(sInitIDCModel))
            return StrToInt(sInitIDCModel);
        else
            return Que->Fields->Fields[0]->AsInteger;
    }
    else
        return StrToInt(sInitIDCModel);
} //GetMaxRecId()
//---------------------------------------------------------------------------
AnsiString __fastcall GetMaxRecAddOne(TADOQuery *Que, AnsiString TableName,
    AnsiString IdFieldName, AnsiString sInitIDCModel, AnsiString sSql)
{
    AnsiString sSQL;
    sSQL = "select max(" + IdFieldName + ") from " + TableName + " " + sSql;
    ExecuteSql(Que, sSQL);
    Que->Active = true;
    if (!Que->Fields->Fields[0]->IsNull)
    {
        if (Que->Fields->Fields[0]->AsString < sInitIDCModel)
            return sInitIDCModel;
        else
            return AnsiString(Que->Fields->Fields[0]->AsFloat + 1);
    }
    else
        return sInitIDCModel;

} // GetMaxRec

//---------------------------------------------------------------------------

bool __fastcall InputText(const System::AnsiString ACaption, const System
    ::AnsiString APrompt, System::AnsiString &Value)
{
    TForm *Form = new TForm(Application);
    try
    {
        Form->Font->Name = "宋体";
        Form->Font->Size = 9;
        Form->Height = 127;
        Form->BorderStyle = bsDialog;
        Form->Caption = ACaption;
        Form->Position = poScreenCenter;

        TLabel *Label = new TLabel(Form);
        Label->Parent = Form;
        Label->AutoSize = true;
        Label->Left = 24;
        Label->Top = 8;
        Label->Caption = APrompt;

        TEdit *Edit = new TEdit(Form);
        Edit->Parent = Form;
        Edit->Left = 24;
        Edit->Top = 26;
        Edit->MaxLength = 255;
        Edit->Text = Value;
        Edit->SelectAll();
        if (Label->Width < 233)
            Edit->Width = 233;
        else
            Edit->Width = Label->Width + 26;

        Form->Width = Edit->Width + 56;

        TButton *btnOK = new TButton(Form);
        btnOK->Parent = Form;
        btnOK->Caption = "&O 确定";
        btnOK->ModalResult = mrOk;
        btnOK->Default = true;
        btnOK->Top = 64;
        btnOK->Left = Form->ClientWidth / 2-btnOK->Width - 10;

        TButton *btnCancel = new TButton(Form);
        btnCancel->Parent = Form;
        btnCancel->Caption = "&C 取消";
        btnCancel->ModalResult = mrCancel;
        btnCancel->Cancel = true;
        btnCancel->Top = 64;
        btnCancel->Left = Form->ClientWidth / 2+10;

        if (Form->ShowModal() == mrOk)
        {
            Value = Edit->Text;
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        Form->Free();
        return false;
    }
} //InputText()输入单文本
//---------------------------------------------------------------------------
bool __fastcall InputText(const System::AnsiString ACaption, const System
    ::AnsiString ALabel1, const System::AnsiString ALabel2, System::AnsiString
    &Value1, System::AnsiString &Value2, int LimitLen1, int LimitLen2, bool
    bIsPwd)
{
    TForm *Form = new TForm(Application);
    try
    {
        Form->Font->Name = "宋体";
        Form->Font->Size = 9;
        Form->Height = 165;
        Form->BorderStyle = bsDialog;
        Form->Caption = ACaption;
        Form->Position = poScreenCenter;

        TLabel *Label1 = new TLabel(Form);
        Label1->Parent = Form;
        Label1->AutoSize = true;
        Label1->Left = 24;
        Label1->Top = 8;
        Label1->Caption = ALabel1;

        TLabel *Label2 = new TLabel(Form);
        Label2->Parent = Form;
        Label2->AutoSize = true;
        Label2->Left = 24;
        Label2->Top = 56;
        Label2->Caption = ALabel2;

        TEdit *Edit1 = new TEdit(Form);
        Edit1->Parent = Form;
        Edit1->Left = 24;
        Edit1->Top = 24;
        Edit1->Width = 296;
        Edit1->MaxLength = 255;
        Edit1->Text = Value1;
        Edit1->SelectAll();

        TEdit *Edit2 = new TEdit(Form);
        Edit2->Parent = Form;
        Edit2->Left = 24;
        Edit2->Top = 72;
        Edit2->Width = 296;
        Edit2->MaxLength = 255;
        Edit2->Text = Value2;
        Edit2->SelectAll();

        Form->Width = Edit1->Width + 60;

        TButton *btnOK = new TButton(Form);
        btnOK->Parent = Form;
        btnOK->Caption = "&O 确定";
        btnOK->ModalResult = mrOk;
        btnOK->Default = true;
        btnOK->Top = 104;
        btnOK->Left = Form->ClientWidth / 2-btnOK->Width - 10;

        TButton *btnCancel = new TButton(Form);
        btnCancel->Parent = Form;
        btnCancel->Caption = "&C 取消";
        btnCancel->ModalResult = mrCancel;
        btnCancel->Cancel = true;
        btnCancel->Top = 104;
        btnCancel->Left = Form->ClientWidth / 2+10;

        if (Form->ShowModal() == mrOk)
        {
            Value1 = Edit1->Text;
            Value2 = Edit2->Text;
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        Form->Free();
        return false;
    }
} //InputText()//输入双文本
//---------------------------------------------------------------------------
bool __fastcall SelectList(const System::AnsiString ACaption, const System
    ::AnsiString APrompt, TStringList *sList, int nDefaultIdx, System
    ::AnsiString &Value) //新型列表选择对话框
{
    TForm *Form = new TForm(Application);
    try
    {
        Form->Font->Name = "宋体";
        Form->Font->Size = 9;
        Form->Height = 127;
        Form->BorderStyle = bsDialog;
        Form->Caption = ACaption;
        Form->Position = poScreenCenter;

        TLabel *Label = new TLabel(Form);
        Label->Parent = Form;
        Label->AutoSize = true;
        Label->Left = 24;
        Label->Top = 8;
        Label->Caption = APrompt;

        TComboBox *cb_1 = new TComboBox(Form);
        cb_1->Parent = Form;
        cb_1->Left = 24;
        cb_1->Top = 26;
        cb_1->MaxLength = 255;
        cb_1->Style = Stdctrls::csDropDownList;
        if (Label->Width < 233)
            cb_1->Width = 233;
        else
            cb_1->Width = Label->Width + 26;
        cb_1->Items->Assign(sList);
        cb_1->ItemIndex = nDefaultIdx;

        Form->Width = cb_1->Width + 56;

        TButton *btnOK = new TButton(Form);
        btnOK->Parent = Form;
        btnOK->Caption = "&O 确定";
        btnOK->ModalResult = mrOk;
        btnOK->Default = true;
        btnOK->Top = 64;
        btnOK->Left = Form->ClientWidth / 2-btnOK->Width - 10;

        TButton *btnCancel = new TButton(Form);
        btnCancel->Parent = Form;
        btnCancel->Caption = "&C 取消";
        btnCancel->ModalResult = mrCancel;
        btnCancel->Cancel = true;
        btnCancel->Top = 64;
        btnCancel->Left = Form->ClientWidth / 2+10;

        if (Form->ShowModal() == mrOk)
        {
            Value = cb_1->Items->Strings[cb_1->ItemIndex];
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        Form->Free();
        return false;
    }
} //SelectList()
//---------------------------------------------------------------------------
bool __fastcall SelectDate(const System::AnsiString ACaption, const System::AnsiString APrompt, System::AnsiString &Value) //新型日期选择对话框
{
    TForm *Form = new TForm(Application);
    try
    {
        Form->Font->Name = "宋体";
        Form->Font->Size = 9;
        Form->Height = 127;
        Form->BorderStyle = bsDialog;
        Form->Caption = ACaption;
        Form->Position = poScreenCenter;

        TLabel *Label = new TLabel(Form);
        Label->Parent = Form;
        Label->AutoSize = true;
        Label->Left = 24;
        Label->Top = 8;
        Label->Caption = APrompt;

        TDateTimePicker *dtp = new TDateTimePicker(Form);
        dtp->Parent = Form;
        dtp->Left = 24;
        dtp->Top = 26;
        dtp->DateFormat = dfLong;
        dtp->Date = Date();
        if (Label->Width < 233)
            dtp->Width = 233;
        else
            dtp->Width = Label->Width + 26;
        Form->Width = dtp->Width + 56;

        TButton *btnOK = new TButton(Form);
        btnOK->Parent = Form;
        btnOK->Caption = "&O 确定";
        btnOK->ModalResult = mrOk;
        btnOK->Default = true;
        btnOK->Top = 64;
        btnOK->Left = Form->ClientWidth / 2-btnOK->Width - 10;

        TButton *btnCancel = new TButton(Form);
        btnCancel->Parent = Form;
        btnCancel->Caption = "&C 取消";
        btnCancel->ModalResult = mrCancel;
        btnCancel->Cancel = true;
        btnCancel->Top = 64;
        btnCancel->Left = Form->ClientWidth / 2+10;

        if (Form->ShowModal() == mrOk)
        {
            Value = FormatDateTime("yyyy.mm.dd", dtp->Date);
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        Form->Free();
        return false;
    }
} //SelectDate()
//---------------------------------------------------------------------------
bool __fastcall InputPwd(const System::AnsiString ACaption, const System
    ::AnsiString APrompt, System::AnsiString &Value) //密码输入对话框
{
    TForm *Form = new TForm(Application);
    try
    {
        Form->Font->Name = "宋体";
        Form->Font->Size = 9;
        Form->Height = 127;
        Form->BorderStyle = bsDialog;
        Form->Caption = ACaption;
        Form->Position = poScreenCenter;

        TLabel *Label = new TLabel(Form);
        Label->Parent = Form;
        Label->AutoSize = true;
        Label->Left = 24;
        Label->Top = 8;
        Label->Caption = APrompt;

        TEdit *Edit = new TEdit(Form);
        Edit->Parent = Form;
        Edit->Left = 24;
        Edit->Top = 26;
        Edit->MaxLength = 255;
        Edit->Text = "";
        Edit->PasswordChar = '*';
        Edit->SelectAll();
        if (Label->Width < 233)
            Edit->Width = 233;
        else
            Edit->Width = Label->Width + 26;

        Form->Width = Edit->Width + 56;

        TButton *btnOK = new TButton(Form);
        btnOK->Parent = Form;
        btnOK->Caption = "&O 确定";
        btnOK->ModalResult = mrOk;
        btnOK->Default = true;
        btnOK->Top = 64;
        btnOK->Left = Form->ClientWidth / 2-btnOK->Width - 10;

        TButton *btnCancel = new TButton(Form);
        btnCancel->Parent = Form;
        btnCancel->Caption = "&C 取消";
        btnCancel->ModalResult = mrCancel;
        btnCancel->Cancel = true;
        btnCancel->Top = 64;
        btnCancel->Left = Form->ClientWidth / 2+10;

        if (Form->ShowModal() == mrOk)
        {
            Value = Edit->Text;
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        Form->Free();
        return false;
    }
}

//---------------------------------------------------------------------------
AnsiString __fastcall DelDec(AnsiString Str)
{
    if (Str.Length() > 0)
    {
        int i = Str.Pos('.');
        if (i > 0)
            return Str.SubString(1, i - 1) + Str.SubString(i + 1, Str.Length());
        else
            return Str;
    }
    else
        return "";
} //DelDec
//---------------------------------------------------------------------------

AnsiString __fastcall LeftFillStr(AnsiString Str, AnsiString c, int nLength)
{
    int l = Str.Length();

    AnsiString s = Str;

    if (s.Length() < nLength)
        for (int i = 0; i < (nLength - l); i++)
            s = c + s;

    return s;
} //LeftFillStr
//---------------------------------------------------------------------------

AnsiString __fastcall RightFillStr(AnsiString Str, AnsiString c, int nLength)
{
    int l = Str.Length();

    AnsiString s = Str;

    if (s.Length() < nLength)
        for (int i = 0; i < (nLength - l); i++)
            s = s + c;

    return s;
} //RightFillStr
//---------------------------------------------------------------------------

AnsiString __fastcall FStr(double x, int nDec)
{
    return FloatToStrF(x, ffFixed, 20, nDec);
    //return FormatFloat("0.00",x);
} //FStr

//---------------------------------------------------------------------------
//添加根节点
TTreeNode *__fastcall AddRootInfoNode(TTreeView *TreeView, AnsiString Text,
    AnsiString snotes, int nid)
{
    PNodeInfos NodeInfo;
    NodeInfo = new TNodeInfos;
    NodeInfo->notes = snotes;
    NodeInfo->id = nid;
    return TreeView->Items->AddObject(NULL, Text, NodeInfo);
} //AddRootInfoNode
//---------------------------------------------------------------------------
//添加子节点
TTreeNode *__fastcall AddSubInfoNode(TTreeView *TreeView, TTreeNode *Node,
    AnsiString Text, AnsiString snotes, int nid)
{
    PNodeInfos NodeInfo;
    NodeInfo = new TNodeInfos;
    NodeInfo->notes = snotes;
    NodeInfo->id = nid;
    return TreeView->Items->AddChildObject(Node, Text, NodeInfo);
} //AddSubInfoNode
//---------------------------------------------------------------------------
AnsiString __fastcall CurrentYear() //获取当前四位年份
{
    return FormatDateTime("yyyy", Date());
}

//---------------------------------------------------------------------------
AnsiString __fastcall CurrentMonth() //获取当前月份
{
    return FormatDateTime("mm", Date());
}

//---------------------------------------------------------------------------
AnsiString __fastcall CurrentDay() //获取当前日
{
    return FormatDateTime("dd", Date());
}

//---------------------------------------------------------------------------
void __fastcall LockDesk() //锁桌面
{
    SystemParametersInfo(SPI_SCREENSAVERRUNNING, true, (void*)1, 0);
        //禁用系统热键

    //隐藏任务条
    HWND dh;
    dh = FindWindow("Shell_TrayWnd", NULL);
    if (dh != 0)
        ShowWindow(dh, SW_HIDE);
}

//---------------------------------------------------------------------------
void __fastcall UnLockDesk() //桌面开锁
{
    SystemParametersInfo(SPI_SCREENSAVERRUNNING, false, (void*)1, 0);
        //启用系统热键

    //恢复显示任务条
    HWND dh;
    dh = FindWindow("Shell_TrayWnd", NULL);
    if (dh != 0)
        ShowWindow(dh, SW_RESTORE);
} //UnLockDesk()
//---------------------------------------------------------------------------
void __fastcall ReadGrdColW(TStringGrid *grd, AnsiString sFileName) //读网格列宽
{
    //网格列宽文件的记录格式：
    //      父容器名.网格名     列宽
    //  例如:frmStadndard.Grid1               020000040120
    //网格全名长度为30字符,每列宽整数位数为3位
    AnsiString s, scw;
    int gcidx;
    int grdmarklen = 30;
    int nStep;
    TStringList *csl = new TStringList();

    gcidx =  - 1;
    s = "";
    scw = "";
    s = RightFillStr(grd->Parent->Name + "." + grd->Name, " ", grdmarklen);

    if (FileExists(sFileName))
    {
        csl->LoadFromFile(sFileName);
        if (csl->Count > 0)
            for (int i = 0; i < csl->Count; i++)
        if (csl->Strings[i].SubString(1, grdmarklen) == s)
        {
            gcidx = i;
            break;
        }
        if (gcidx >  - 1)
        {
            s = csl->Strings[gcidx];
            scw = s.SubString(grdmarklen + 1, s.Length() - grdmarklen);
            nStep = (scw.Length() / 3 >= grd->ColCount) ? grd->ColCount:
                scw.Length() / 3;
            for (int i = 0; i < nStep; i++)
            {
                try
                {
                    grd->ColWidths[i] = StrToInt(scw.SubString(3 *i + 1, 3));
                }
                catch (...)
                {
                    continue;
                }
            }
        }
    }
    delete csl;
}

//---------------------------------------------------------------------------
void __fastcall WriteGrdColW(TStringGrid *grd, AnsiString sFileName)
    //写网格列宽
{
    //网格列宽文件的记录格式：
    //      父容器名.网格名     列宽
    //  例如:frmStadndard.Grid1               020000040120
    //网格全名长度为30字符,每列宽整数位数为3位
    AnsiString s, scw;
    int gcidx, ncw;
    int grdmarklen = 30;
    TStringList *csl = new TStringList();

    gcidx =  - 1;
    s = "";
    scw = "";
    s = RightFillStr(grd->Parent->Name + "." + grd->Name, " ", grdmarklen);

    for (int j = 0; j < grd->ColCount; j++)
    {
        ncw = grd->ColWidths[j];
        if (ncw > 999)
        {
            ncw = 999;
        }
        scw += LeftFillStr(IntToStr(ncw), "0", 3);
    }

    if (FileExists(sFileName))
    {
        csl->LoadFromFile(sFileName);
        if (csl->Count > 0)
            for (int i = 0; i < csl->Count; i++)
        if (csl->Strings[i].SubString(1, grdmarklen) == s)
        {
            gcidx = i;
            break;
        }
        if (gcidx ==  - 1)
            csl->Add(s + scw);
        else
            csl->Strings[gcidx] = s + scw;
    }
    else
        csl->Add(s + scw);

    if (sFileName.Length() > 0)
    try
    {
        csl->SaveToFile(sFileName);
    }
    catch (...)
    {
        csl->Clear();
    }
    delete csl;
}

//---------------------------------------------------------------------------
AnsiString __fastcall Cypher(System::AnsiString Value)
{
    int l;
    char *x;
    l = Value.Length();
    x = (char*)malloc(l + 1);
    strcpy(x, Value.c_str());
    for (int i = 0; i < l; i++)
        x[i] = char((int)x[i] + 70);
    return AnsiString(x);
} //Cypher()
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
AnsiString __fastcall Decrypt(System::AnsiString Value)
{
    int l;
    char *x;
    l = Value.Length();
    x = (char*)malloc(l + 1);
    strcpy(x, Value.c_str());
    for (int i = 0; i < l; i++)
        x[i] = char((int)x[i] - 70);
    return AnsiString(x);
} //Decrypt()
//---------------------------------------------------------------------------
bool __fastcall ChkPower(AnsiString sPowerStr, int nPowerPlace) //检查权限
{
    AnsiString p;
    p = sPowerStr.SubString(nPowerPlace, 1);
    if (p == "1")
        return true;
    else
        return false;
} //ChkPower()
//---------------------------------------------------------------------------
/*
void __fastcall HelpCodeFind(TEdit *E,int nFlag,TEdit *E1)
{
AnsiString sTmp=Trim(E->Text.UpperCase());
if (sTmp.Length()<=0)
return;
char sChar;
sChar=sTmp[1];//.SubString(i,1);
if ((sChar<='A')|| (sChar>='Z'))
return;

Application->CreateForm(__classid(TfrmHelpCode),&frmHelpCode);
frmHelpCode->FindHelpCode(E->Text,nFlag);
frmHelpCode->ShowModal();
int nResult=frmHelpCode->Tag;
if(nResult==mrYes)
{
if (E1!=NULL)
E1->Text=frmHelpCode->GetSelName();
else
E->Text=frmHelpCode->GetSelName();

if (frmHelpCode->GetnSelType()==1)
{
DataServer->sSupplyName=frmHelpCode->GetSelName();
DataServer->nSupplyId=StrToInt(frmHelpCode->GetSelid());

}else
{
DataServer->sGuestName=frmHelpCode->GetSelName();
DataServer->nGuestId=StrToInt(frmHelpCode->GetSelid());

}

}
delete frmHelpCode;
//ActiveControl=E;

}
//--------------------------------------------------------------------------
void __fastcall HelpCodeFind(TFlatEdit *E,int nFlag,TEdit *E1)
{
AnsiString sTmp=Trim(E->Text.UpperCase());
if (sTmp.Length()<=0)
return;
char sChar;
sChar=sTmp[1];//.SubString(i,1);
if ((sChar<='A')|| (sChar>='Z'))
return;

Application->CreateForm(__classid(TfrmHelpCode),&frmHelpCode);
frmHelpCode->FindHelpCode(E->Text,nFlag);
frmHelpCode->ShowModal();
int nResult=frmHelpCode->Tag;
if(nResult==mrYes)
{
if (E1!=NULL)
E1->Text=frmHelpCode->GetSelName();
else
E->Text=frmHelpCode->GetSelName();

if (frmHelpCode->GetnSelType()==1)
{
DataServer->sSupplyName=frmHelpCode->GetSelName();
DataServer->nSupplyId=StrToInt(frmHelpCode->GetSelid());

}else
{
DataServer->sGuestName=frmHelpCode->GetSelName();
DataServer->nGuestId=StrToInt(frmHelpCode->GetSelid());

}

}
delete frmHelpCode;
//ActiveControl=E;

}
//-------------------------------------------------------------------------
void __fastcall HelpCodeFind(TComboBox *E,int nFlag,TEdit *E1)
{
AnsiString sTmp=Trim(E->Text.UpperCase());
if (sTmp.Length()<=0)
return;
char sChar;
sChar=sTmp[1];//.SubString(i,1);
if ((sChar<='A')|| (sChar>='Z'))
return;

Application->CreateForm(__classid(TfrmHelpCode),&frmHelpCode);
frmHelpCode->FindHelpCode(E->Text,nFlag);
frmHelpCode->ShowModal();
int nResult=frmHelpCode->Tag;
if(nResult==mrYes)
{
if (E1!=NULL)
E1->Text=frmHelpCode->GetSelName();
else
E->Text=frmHelpCode->GetSelName();

if (frmHelpCode->GetnSelType()==1)
{
DataServer->sSupplyName=frmHelpCode->GetSelName();
DataServer->nSupplyId=StrToInt(frmHelpCode->GetSelid());

}else
{
DataServer->sGuestName=frmHelpCode->GetSelName();
DataServer->nGuestId=StrToInt(frmHelpCode->GetSelid());

}

}
delete frmHelpCode;
//ActiveControl=E;

}
//-------------------------------------
void __fastcall HelpCodeFind(TFlatComboBox *E,int nFlag,TEdit *E1)
{
AnsiString sTmp=Trim(E->Text.UpperCase());
if (sTmp.Length()<=0)
return;
char sChar;
sChar=sTmp[1];//.SubString(i,1);
if ((sChar<='A')|| (sChar>='Z'))
return;

Application->CreateForm(__classid(TfrmHelpCode),&frmHelpCode);
frmHelpCode->FindHelpCode(E->Text,nFlag);
frmHelpCode->ShowModal();
int nResult=frmHelpCode->Tag;
if(nResult==mrYes)
{
if (E1!=NULL)
E1->Text=frmHelpCode->GetSelName();
else
E->Text=frmHelpCode->GetSelName();

if (frmHelpCode->GetnSelType()==1)
{
DataServer->sSupplyName=frmHelpCode->GetSelName();
DataServer->nSupplyId=StrToInt(frmHelpCode->GetSelid());

}else
{
DataServer->sGuestName=frmHelpCode->GetSelName();
DataServer->nGuestId=StrToInt(frmHelpCode->GetSelid());

}

}
delete frmHelpCode;
//ActiveControl=E;

} */
//-------------------------------------
AnsiString __fastcall GetPY(String sSrc)
{
    AnsiString sPy = "";
    unsigned c, c1, t;
    sSrc = Trim(sSrc);
    int n = sSrc.Length();
    for (int i = 1; i <= n; i++)
    {
        if (((sSrc[i] <= '9') && (sSrc[i] >= '0')) || ((sSrc[i] <= 'z') &&
            (sSrc[i] >= 'a')) || ((sSrc[i] <= 'Z') && (sSrc[i] >= 'A')))
            continue;

        if ((sSrc[i] == '(') || (sSrc[i] == ' ') || (sSrc[i] == ')') ||
            (sSrc[i] == '-') || (sSrc[i] == '（') || (sSrc[i] == '）') ||
            (sSrc[i] == '?') || (sSrc[i] == '*') || (sSrc[i] == '.') ||
            (sSrc[i] == ',') || (sSrc[i] == '/') || (sSrc[i] == '\\') ||
            (sSrc[i] == '#') || (sSrc[i] == ':'))
            continue;

        c = sSrc[i];
        c1 = sSrc[i + 1];
        i++;


        t = ((c &255) << 8) + (c1 &255);

        if ((t >= 0xB0A1) && (t <= 0xB0C4))
            sPy += 'A';
        if ((t >= 0xB0C5) && (t <= 0xB2C0))
            sPy += 'B';
        if ((t >= 0xB2C1) && (t <= 0xB4ED))
            sPy += 'C';
        if ((t >= 0xB4EE) && (t <= 0xB6E9))
            sPy += 'D';
        if ((t >= 0xB6EA) && (t <= 0xB7A1))
            sPy += 'E';
        if ((t >= 0xB7A2) && (t <= 0xB8C0))
            sPy += 'F';
        if ((t >= 0xB8C1) && (t <= 0xB9FD))
            sPy += 'G';
        if ((t >= 0xB9FE) && (t <= 0xBBF6))
            sPy += 'H';
        if ((t >= 0xBBF7) && (t <= 0xBFA5))
            sPy += 'J';
        if ((t >= 0xBFA6) && (t <= 0xC0AB))
            sPy += 'K';
        if ((t >= 0xC0AC) && (t <= 0xC2E7))
            sPy += 'L';
        if ((t >= 0xC2E8) && (t <= 0xC4C2))
            sPy += 'M';
        if ((t >= 0xC4C3) && (t <= 0xC5B5))
            sPy += 'N';
        if ((t >= 0xC5B6) && (t <= 0xC5BD))
            sPy += 'O';
        if ((t >= 0xC5BE) && (t <= 0xC6D9))
            sPy += 'P';
        if ((t >= 0xC6DA) && (t <= 0xC8BA))
            sPy += 'Q';
        if ((t >= 0xC8BB) && (t <= 0xC8F5))
            sPy += 'R';
        if ((t >= 0xC8F6) && (t <= 0xCBF9))
            sPy += 'S';
        if ((t >= 0xCBFA) && (t <= 0xCDD9))
            sPy += 'T';
        if ((t >= 0xCDDA) && (t <= 0xCEF3))
            sPy += 'W';
        if ((t >= 0xCEF4) && (t <= 0xD188))
            sPy += 'X';
        if ((t >= 0xD1B9) && (t <= 0xD4D0))
            sPy += 'Y';
        if ((t >= 0xD4D1) && (t <= 0xD7F9))
            sPy += 'Z';

    }

    return sPy;
}

//----------------------------------------

//---------------------------------------------------------------------------
void __fastcall ReadLVColW(TListView *grd, AnsiString sFileName) //读网格列宽
{
    //网格列宽文件的记录格式：
    //      父容器名.网格名     列宽
    //  例如:frmStadndard.Grid1               020000040120
    //网格全名长度为30字符,每列宽整数位数为3位
    AnsiString s, scw;
    int gcidx;
    int grdmarklen = 30;
    int nStep;
    TStringList *csl = new TStringList();

    gcidx =  - 1;
    s = "";
    scw = "";
    s = RightFillStr(grd->Parent->Name + "." + grd->Name, " ", grdmarklen);

    if (FileExists(sFileName))
    {
        csl->LoadFromFile(sFileName);
        if (csl->Count > 0)
            for (int i = 0; i < csl->Count; i++)
        if (csl->Strings[i].SubString(1, grdmarklen) == s)
        {
            gcidx = i;
            break;
        }
        if (gcidx >  - 1)
        {
            s = csl->Strings[gcidx];
            scw = s.SubString(grdmarklen + 1, s.Length() - grdmarklen);
            nStep = (scw.Length() / 3 >= grd->Columns->Count) ? grd->Columns
                ->Count: scw.Length() / 3;
            for (int i = 0; i < nStep; i++)
            {
                try
                {
                    grd->Columns->Items[i]->Width = StrToInt(scw.SubString(3 *i
                        + 1, 3));
                }
                catch (...)
                {
                    continue;
                }
            }
        }
    }
    delete csl;
}

//---------------------------------------------------------------------------
void __fastcall WriteLVColW(TListView *grd, AnsiString sFileName) //写网格列宽
{
    //网格列宽文件的记录格式：
    //      父容器名.网格名     列宽
    //  例如:frmStadndard.Grid1               020000040120
    //网格全名长度为30字符,每列宽整数位数为3位
    AnsiString s, scw;
    int gcidx, ncw;
    int grdmarklen = 30;
    TStringList *csl = new TStringList();

    gcidx =  - 1;
    s = "";
    scw = "";
    s = RightFillStr(grd->Parent->Name + "." + grd->Name, " ", grdmarklen);

    for (int j = 0; j < grd->Columns->Count; j++)
    {
        //ncw=grd->ColWidths[j];
        ncw = grd->Columns->Items[j]->Width;
        if (ncw > 999)
        {
            ncw = 999;
        }
        scw += LeftFillStr(IntToStr(ncw), "0", 3);
    }

    if (FileExists(sFileName))
    {
        csl->LoadFromFile(sFileName);
        if (csl->Count > 0)
            for (int i = 0; i < csl->Count; i++)
        if (csl->Strings[i].SubString(1, grdmarklen) == s)
        {
            gcidx = i;
            break;
        }
        if (gcidx ==  - 1)
            csl->Add(s + scw);
        else
            csl->Strings[gcidx] = s + scw;
    }
    else
        csl->Add(s + scw);

    if (sFileName.Length() > 0)
    try
    {
        csl->SaveToFile(sFileName);
    }
    catch (...)
    {
        csl->Clear();
    }
    delete csl;
}

//---------------------------------------------------------------------------
AnsiString GetRec(TADOQuery *Que, AnsiString sTableName, AnsiString sFieldName,
    AnsiString sSql)
{
    AnsiString sSQL;
    if (sSql.Length() == 0)
        sSQL = "select " + sFieldName + " from " + sTableName;
    else
        sSQL = "select " + sFieldName + " from " + sTableName + " where " +
            sSql;

    ExecuteSql(Que, sSQL);

    Que->Active = true;
    if (!Que->Fields->Fields[0]->IsNull)
    {
        return Que->Fields->Fields[0]->AsString;
    }
    else
        return "";   
}

//-----------------------------------------------------------------------
AnsiString __fastcall GetNameFieldFromIDFieldN(TADOQuery *Que, AnsiString
    sTableName, AnsiString sNameField, AnsiString sIDField, int nValue)
{
    AnsiString sSql;
    sSql = "select " + sNameField + " from " + sTableName + " where " +
        sIDField + "=" + IntToStr(nValue);
    ExecuteSql(Que, sSql);
    Que->Active = true;

    if (!Que->Eof)
    {
        return Que->FieldByName(sNameField)->AsString;
    }
}

AnsiString __fastcall GetNameFieldFromIDFieldS(TADOQuery *Que, AnsiString
    sTableName, AnsiString sNameField, AnsiString sIDField, AnsiString sValue)
{
    AnsiString sSql;
    sSql = "select " + sNameField + " from " + sTableName + " where " +
        sIDField + "=" + "'" + sValue + "'";
    ExecuteSql(Que, sSql);
    Que->Active = true;

    if (!Que->Eof)
    {
        return Que->FieldByName(sNameField)->AsString;
    }

}

//-----------------------------------------------------------------------
void FillCB(TComboBox *cb, TADOQuery *Que, AnsiString sTableName, AnsiString
    sFieldName, AnsiString sSql, int nSelected)
{
    AnsiString sSQL;
    if (sSql.Length() == 0)
        sSQL = "select distinct " + sFieldName + " from " + sTableName +
            " order by " + sFieldName;
    else
        sSQL = "select distinct " + sFieldName + " from " + sTableName +
            " where " + sSql + " order by " + sFieldName;
    // ShowMessage(sSQL);
    ExecuteSql(Que, sSQL);

    Que->Active = true;
    cb->Items->Clear();
    while (!Que->Eof)
    {
        cb->Items->Add(Que->Fields->Fields[0]->AsString);
        Que->Next();
    }
    if (nSelected < Que->RecordCount)
        cb->ItemIndex = nSelected;
}

//------------------------------------------------------------------
void FillLB(TListBox *lb, TADOQuery *Que, AnsiString sTableName, AnsiString
    sFieldName, AnsiString sSql)
{
    AnsiString sSQL;
    if (sSql.Length() == 0)
        sSQL = "select " + sFieldName + " from " + sTableName + " order by " +
            sFieldName;
    else
        if (sSql.Pos("order by") > 0)
            sSQL = "select " + sFieldName + " from " + sTableName + " where " +
                sSql;
        else
            sSQL = "select " + sFieldName + " from " + sTableName + " where " +
                sSql + " order by " + sFieldName;

    ExecuteSql(Que, sSQL);

    Que->Active = true;
    lb->Items->Clear();
    while (!Que->Eof)
    {
        lb->Items->Add(Que->Fields->Fields[0]->AsString);
        Que->Next();
    }

}

//---------------------------------------------------------------------------
int __fastcall GetID(TADOQuery *Que, AnsiString TableName, AnsiString getIdName,
    AnsiString getIdFrom, AnsiString sValue)
{
    AnsiString sSQL;
    sSQL = "select " + getIdName + " from " + TableName + " where " + getIdFrom
        + "='" + sValue + "'";

    ExecuteSql(Que, sSQL);
    Que->Active = true;
    return Que->Fields->Fields[0]->AsInteger;

}

//----------------------------------------------------------------------
TDate MakeDate(AnsiString strDate)
{
    return StrToDate(strDate.SubString(0, 4) + "-" + strDate.SubString(6, 2) +
        "-" + strDate.SubString(9, 2));

}

//---------------------------------------
void LockInputLen(TEdit *edit, int nLen)
{
    AnsiString tmp = "请输入" + IntToStr(nLen) + "位数！";
    if ((edit->Text.Length() != nLen) && (edit->Text.Length() != 0))
    {
        Application->MessageBoxA(tmp.c_str(), "提示", MB_OK | MB_ICONSTOP);
        //ActiveControl=edit;
        edit->SetFocus();

    }
}

//---------------------------------------------
void MakeOperateLog(TADOQuery *Que, AnsiString sOperator, AnsiString sTableName,
    AnsiString sTableIdValue)
{
    AnsiString sSql = "";
    int nId = GetMaxRecId(Que, "OperatorLog", "id", "0") + 1;
    sSql =
        "insert into OperatorLog (Id,operator,operatedate,operatetime,optablename,optableid) "" values(" + IntToStr(nId) + ",'" + sOperator + "','" + DateToStr(Date()) + "','" + TimeToStr(Time()) + "','" + sTableName + "'," + sTableIdValue + ")";
    ExecuteSql(Que, sSql);

}

//---------------------------------------------

