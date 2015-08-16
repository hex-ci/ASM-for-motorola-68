//---------------------------------------------------------------------------

#ifndef SearchFormH
#define SearchFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormSearch : public TForm
{
__published:	// IDE-managed Components
    TComboBox *cbSearchText;
    TGroupBox *gbSearchOptions;
    TCheckBox *cbSearchCaseSensitive;
    TCheckBox *cbSearchWholeWords;
    TCheckBox *cbSearchFromCursor;
    TCheckBox *cbSearchSelectedOnly;
    TRadioGroup *rgSearchDirection;
    TButton *btnOK;
    TButton *btnCancel;
    TLabel *Label1;
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:
    void __fastcall SetSearchBackwards(bool value);
    bool __fastcall GetSearchBackwards();
    void __fastcall SetSearchCaseSensitive(bool value);
    bool __fastcall GetSearchCaseSensitive();
    void __fastcall SetSearchFromCursor(bool value);
    bool __fastcall GetSearchFromCursor();
    void __fastcall SetSearchInSelectionOnly(bool value);
    bool __fastcall GetSearchInSelectionOnly();
    void __fastcall SetSearchText(String value);
    String __fastcall GetSearchText();
    void __fastcall SetSearchTextHistory(String value);
    String __fastcall GetSearchTextHistory();
    void __fastcall SetSearchWholeWords(bool value);
    bool __fastcall GetSearchWholeWords();	// User declarations
public:		// User declarations
    __fastcall TFormSearch(TComponent* Owner);
    __property bool SearchBackwards  = { read=GetSearchBackwards, write=SetSearchBackwards };
    __property bool SearchCaseSensitive  = { read=GetSearchCaseSensitive, write=SetSearchCaseSensitive };
    __property bool SearchFromCursor  = { read=GetSearchFromCursor, write=SetSearchFromCursor };
    __property bool SearchInSelectionOnly  = { read=GetSearchInSelectionOnly, write=SetSearchInSelectionOnly };
    __property String SearchText  = { read=GetSearchText, write=SetSearchText };
    __property String SearchTextHistory  = { read=GetSearchTextHistory, write=SetSearchTextHistory };
    __property bool SearchWholeWords  = { read=GetSearchWholeWords, write=SetSearchWholeWords };
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSearch *FormSearch;
//---------------------------------------------------------------------------
#endif
