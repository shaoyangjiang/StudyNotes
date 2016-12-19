//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", MainForm);
USEFORM("Browse.cpp", BrowseForm);
USEFORM("Insert.cpp", InsertForm);
USEFORM("update.cpp", updateForm);
USEFORM("Delete.cpp", deleteForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try    
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TBrowseForm), &BrowseForm);
                 Application->CreateForm(__classid(TInsertForm), &InsertForm);
                 Application->CreateForm(__classid(TupdateForm), &updateForm);
                 Application->CreateForm(__classid(TdeleteForm), &deleteForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
