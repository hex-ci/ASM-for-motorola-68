//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AsmThread.h"
#include "MDIEdit.h"
#include "AsmStatus.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAsmForm *AsmForm;
//---------------------------------------------------------------------------
__fastcall TAsmForm::TAsmForm(TComponent* Owner)
    : TForm(Owner)
{
    Parent = dynamic_cast<TEditForm *>(Owner);
}
//---------------------------------------------------------------------------
void __fastcall TAsmForm::FormShow(TObject *Sender)
{
    StartAsm();

    /*TAsmAnalyze Asm;

    Asm.Open(FileName);
    Asm.Make(ChangeFileExt(FileName,".obj"), ErrorList);*/

    //TotalError = Asm.Error();
    //TotalLine = Asm.LineNum(); 

}
//---------------------------------------------------------------------------

void __fastcall TAsmForm::ThreadDone(TObject * Sender)
{
    //TODO: Add your source code here
    ThreadsRunning--;
    if (!ThreadsRunning)
    {
        //MessageBox(TransForm->Handle,"线程完成！","线程",0);
        //Close();
        //delete m_pAsm;
        if (m_pAsm->Error() > 0)
            Parent->MsgList->Height = 100;
        else
            Parent->MsgList->Height = 0;
        Parent->Editor->Repaint();

        if (bAutoMode) return;

        txtError->Text = IntToStr(m_pAsm->Error());
        txtLine->Text = IntToStr(m_pAsm->LineNum());
        txtSize->Text = IntToStr(m_pAsm->Size());
        txtBegin->Text = IntToHex(m_pAsm->BeginAddress(), 4);
        txtEnd->Text = IntToHex(m_pAsm->BeginAddress() + m_pAsm->Size() - 1, 4);
        CancelButton->Caption = "完成(&C)";

    }
}

void __fastcall TAsmForm::CancelButtonClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------


void __fastcall TAsmForm::StartAsm(void)
{
    //TODO: Add your source code here
    Parent->MsgList->Items->Clear();
    
    ThreadsRunning=1;
    m_pAsm = new TAsmThread(false, FileName, Parent->MsgList);
    m_pAsm->OnTerminate=ThreadDone;
    txtAsmFile->Text = FileName;
}
