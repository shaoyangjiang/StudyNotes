//---------------------------------------------------------------------------
                                   
#include <vcl.h>                   
#pragma hdrstop            
//---------------------------------------------------------------------------
USEFORM("MainUnit.cpp", MainForm);
USEFORM("BookInsertUnit.cpp", BookInsert);
USEFORM("BookDeleteUnit.cpp", BookDelete);
USEFORM("ReaderInsertUnit.cpp", ReaderInsert);
USEFORM("ReaderDeleteUnit.cpp", ReaderDelete);
USEFORM("LibrarianInsDelUnit.cpp", LibrarianInsDel);
USEFORM("BorrowingUnit.cpp", BorrowingBook);
USEFORM("ReturningUnit.cpp", ReturningBook);
USEFORM("LoginUnit.cpp", LoginForm);
USEFORM("BookBrowsingUnit.cpp", BrowsingBook);
USEFORM("AlterUserNameUnit.cpp", AlterUserNameForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
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
