//---------------------------------------------------------------------------

#ifndef ConfirmReplaceFormH
#define ConfirmReplaceFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormConfirmReplace : public TForm
{
__published:	// IDE-managed Components
    TLabel *lblConfirmation;
    TImage *Image1;
    TButton *btnReplace;
    TButton *btnSkip;
    TButton *btnCancel;
    TButton *btnReplaceAll;
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormConfirmReplace(TComponent* Owner);
    void __fastcall PrepareShow(TRect AEditorRect, int X, int Y1, int Y2, String AReplaceText);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormConfirmReplace *FormConfirmReplace;
//---------------------------------------------------------------------------
#endif
