//---------------------------------------------------------------------------

#ifndef ReplaceFormH
#define ReplaceFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SearchForm.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormReplace : public TFormSearch
{
__published:	// IDE-managed Components
    TLabel *Label2;
    TComboBox *cbReplaceText;
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:
    void __fastcall SetReplaceText(String value);
    String __fastcall GetReplaceText();
    void __fastcall SetReplaceTextHistory(String value);
    String __fastcall GetReplaceTextHistory();	// User declarations
public:		// User declarations
    __fastcall TFormReplace(TComponent* Owner);
    __property String ReplaceText  = { read=GetReplaceText, write=SetReplaceText };
    __property String ReplaceTextHistory  = { read=GetReplaceTextHistory, write=SetReplaceTextHistory };
};
//---------------------------------------------------------------------------
extern PACKAGE TFormReplace *FormReplace;
//---------------------------------------------------------------------------
#endif
