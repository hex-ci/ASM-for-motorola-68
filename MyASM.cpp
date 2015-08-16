//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#include <except.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("mdiframe.cpp", FrameForm);
USEFORM("MDIEdit.cpp", EditForm);
USEFORM("AsmStatus.cpp", AsmForm);
USEFORM("About.cpp", AboutBox);
USEFORM("GotoLine.cpp", GotoForm);
USEFORM("SearchForm.cpp", FormSearch);
USEFORM("ReplaceForm.cpp", FormReplace);
USEFORM("ConfirmReplaceForm.cpp", FormConfirmReplace);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "68 系列汇编系统";

         Application->CreateForm(__classid(TFrameForm), &FrameForm);
         Application->CreateForm(__classid(TAsmForm), &AsmForm);
         Application->CreateForm(__classid(TAboutBox), &AboutBox);
         Application->CreateForm(__classid(TGotoForm), &GotoForm);
         Application->CreateForm(__classid(TFormSearch), &FormSearch);
         Application->CreateForm(__classid(TFormReplace), &FormReplace);
         Application->CreateForm(__classid(TFormConfirmReplace), &FormConfirmReplace);
         Application->Run();
    }
    catch (Exception &e)
    {
        ShowMessage(e.Message + "\n类型: " + __ThrowExceptionName()
                    + "\n文件: " + __ThrowFileName()
                    + "\n行号: " + AnsiString(__ThrowLineNumber()));
    }

    return 0;
}
//---------------------------------------------------------------------------
