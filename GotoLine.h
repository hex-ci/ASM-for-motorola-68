//---------------------------------------------------------------------------

#ifndef GotoLineH
#define GotoLineH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TGotoForm : public TForm
{
__published:	// IDE-managed Components
    TEdit *txtLine;
    TLabel *Label1;
    TButton *OKButton;
    TButton *CancelButton;
    void __fastcall OKButtonClick(TObject *Sender);
private:	// User declarations
public:
    int LineNumber;		// User declarations
    __fastcall TGotoForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGotoForm *GotoForm;
//---------------------------------------------------------------------------
#endif
