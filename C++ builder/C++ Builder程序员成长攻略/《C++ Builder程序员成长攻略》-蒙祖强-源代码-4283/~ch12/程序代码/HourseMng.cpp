/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

//---------------------------------------------------------------------------

#include <vcl.h>
#include "fmStartU.h"
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("fmMainU.cpp", fmMain);
USEFORM("fmVBaseU.cpp", fmVBase);
USEFORM("fmPPaperU.cpp", fmPPaper);
USEFORM("dmDataU.cpp", dmData); /* TDataModule: File Type */
USEFORM("fmUpdateU.cpp", fmUpdate);
USEFORM("fmUpdatePropU.cpp", fmUpdateProp);
USEFORM("fmHoursePropU.cpp", fmHourseProp);
USEFORM("fmSharePropU.cpp", fmShareProp);
USEFORM("fmUpdateTaxU.cpp", fmUpdateTax);
USEFORM("fmUpdateOtherPropU.cpp", fmUpdateOtherProp);
USEFORM("fmUpDateGroundPropU.cpp", fmUpDateGroundProp);
USEFORM("fmMarkermanageU.cpp", fmMarkermanage);
USEFORM("fmCheckermanageU.cpp", fmCheckermanage);
USEFORM("fmManageUnitU.cpp", fmManageUnit);
USEFORM("fmTaxTypeU.cpp", fmTaxType);
USEFORM("fmTaxRaceU.cpp", fmTaxRace);
USEFORM("fmInitFileNoU.cpp", fmInitFileNo);
USEFORM("fmSharePropertyPapU.cpp", fmSharePropertyPap);
USEFORM("fmOtherPropU.cpp", fmOtherProp);
USEFORM("fmStartU.cpp", StartupForm);
USEFORM("fmAboutU.cpp", fmAbout);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TfmMain), &fmMain);
                 Application->CreateForm(__classid(TfmPPaper), &fmPPaper);
                 Application->CreateForm(__classid(TfmSharePropertyPap), &fmSharePropertyPap);
                 Application->CreateForm(__classid(TfmOtherProp), &fmOtherProp);
                 Application->CreateForm(__classid(TdmData), &dmData);
                 Application->CreateForm(__classid(TStartupForm), &StartupForm);
                 Application->CreateForm(__classid(TfmAbout), &fmAbout);
                 TStartupForm* StartupForm = new TStartupForm(NULL);
                 StartupForm->ShowModal();
                 delete StartupForm;
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




