//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AsmThread.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TAsmThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TAsmThread::TAsmThread(bool CreateSuspended, String Name, TListView *Box)
    : TThread(CreateSuspended)
{
    FreeOnTerminate = true;
    FileName = Name;
    ErrorList = Box;
}
//---------------------------------------------------------------------------
void TAsmThread::SetName()
{
    THREADNAME_INFO info;
    info.dwType = 0x1000;
    info.szName = "AsmThread";
    info.dwThreadID = -1;
    info.dwFlags = 0;

    __try
    {
         RaiseException( 0x406D1388, 0, sizeof(info)/sizeof(DWORD),(DWORD*)&info );
    }
    __except (EXCEPTION_CONTINUE_EXECUTION)
    {
    }
}
//---------------------------------------------------------------------------
void __fastcall TAsmThread::Execute()
{
    SetName();

    Asm.Open(FileName);
    Synchronize(UpdateList);
    
    TotalError = Asm.Error();
    TotalLine = Asm.LineNum();
    TotalSize = Asm.Size();
    BaseAddress = Asm.BeginAddress();

    //---- Place thread code here ----
}
//---------------------------------------------------------------------------


void __fastcall TAsmThread::UpdateList(void)
{
    //TODO: Add your source code here
    Asm.Make(ChangeFileExt(FileName,".obj"), ErrorList);
}
