//---------------------------------------------------------------------------

#ifndef AsmStatusH
#define AsmStatusH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TAsmForm : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label2;
    TEdit *txtLine;
    TLabel *Label3;
    TLabel *Label4;
    TButton *CancelButton;
    TLabel *Label1;
    TEdit *txtAsmFile;
    TEdit *txtWarning;
    TEdit *txtError;
    TLabel *Label5;
    TEdit *txtSize;
    TLabel *Label6;
    TEdit *txtBegin;
    TLabel *Label7;
    TEdit *txtEnd;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall CancelButtonClick(TObject *Sender);
private:	// User declarations
    TAsmThread *m_pAsm;
    int ThreadsRunning;
    TEditForm *Parent;
    void __fastcall ThreadDone(TObject * Sender);	// User declarations

public:		// User declarations
    String FileName;
    bool bAutoMode;

    __fastcall TAsmForm(TComponent* Owner);
    void __fastcall StartAsm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TAsmForm *AsmForm;
//---------------------------------------------------------------------------
#endif
