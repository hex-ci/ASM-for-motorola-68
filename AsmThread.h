//---------------------------------------------------------------------------

#ifndef AsmThreadH
#define AsmThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include "AsmAnalyze.h"

//---------------------------------------------------------------------------
class TAsmThread : public TThread
{
  typedef struct tagTHREADNAME_INFO
  {
    DWORD dwType;     // must be 0x1000
    LPCSTR szName;    // pointer to name (in user addr space)
    DWORD dwThreadID; // thread ID (-1=caller thread)
    DWORD dwFlags;    // reserved for future use, must be zero
  } THREADNAME_INFO;
private:
    String FileName;
    TAsmAnalyze Asm;
    int TotalError;
    int TotalLine;
    int TotalSize;
    int BaseAddress;
    TListView *ErrorList;

    void SetName();
    void __fastcall UpdateList(void);
protected:
    void __fastcall Execute();
public:
    __fastcall TAsmThread(bool CreateSuspended, String Name, TListView *List);
    int Error(void) {return TotalError;}
    int LineNum(void) {return TotalLine;}
    int Size(void) {return TotalSize;}
    int BeginAddress(void) {return BaseAddress;}
};
//---------------------------------------------------------------------------
#endif
