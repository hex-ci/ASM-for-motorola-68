//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SearchForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSearch *FormSearch;
//---------------------------------------------------------------------------
__fastcall TFormSearch::TFormSearch(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormSearch::SetSearchBackwards(bool value)
{
    //TODO: Add your source code here
    rgSearchDirection->ItemIndex = (int)value;
}
bool __fastcall TFormSearch::GetSearchBackwards()
{
    //TODO: Add your source code here
    return (rgSearchDirection->ItemIndex == 1);
}

void __fastcall TFormSearch::SetSearchCaseSensitive(bool value)
{
    //TODO: Add your source code here
    cbSearchCaseSensitive->Checked = value;
}
bool __fastcall TFormSearch::GetSearchCaseSensitive()
{
    //TODO: Add your source code here
    return cbSearchCaseSensitive->Checked;
}

void __fastcall TFormSearch::SetSearchFromCursor(bool value)
{
    //TODO: Add your source code here
    cbSearchFromCursor->Checked = value;
}
bool __fastcall TFormSearch::GetSearchFromCursor()
{
    //TODO: Add your source code here
    return cbSearchFromCursor->Checked;
}

void __fastcall TFormSearch::SetSearchInSelectionOnly(bool value)
{
    //TODO: Add your source code here
    cbSearchSelectedOnly->Checked = value;
}
bool __fastcall TFormSearch::GetSearchInSelectionOnly()
{
    //TODO: Add your source code here
    return cbSearchSelectedOnly->Checked;
}

void __fastcall TFormSearch::SetSearchText(String value)
{
    //TODO: Add your source code here
    cbSearchText->Text = value;
}
String __fastcall TFormSearch::GetSearchText()
{
    //TODO: Add your source code here
    return cbSearchText->Text;
}

void __fastcall TFormSearch::SetSearchTextHistory(String value)
{
    //TODO: Add your source code here
    cbSearchText->Items->Text = value;
}
String __fastcall TFormSearch::GetSearchTextHistory()
{
    //TODO: Add your source code here
    int i;
    String Temp;

    for (i=0;i<cbSearchText->Items->Count;i++)
    {
        if (i >= 10) break;
        if (i > 0) Temp += "\n";
        Temp += cbSearchText->Items->Strings[i];
    }
    return Temp;
}

void __fastcall TFormSearch::SetSearchWholeWords(bool value)
{
    //TODO: Add your source code here
    cbSearchWholeWords->Checked = value;
}
bool __fastcall TFormSearch::GetSearchWholeWords()
{
    //TODO: Add your source code here
    return cbSearchWholeWords->Checked;
}

void __fastcall TFormSearch::FormCloseQuery(TObject *Sender,
      bool &CanClose)
{
  int i;
  String s;

  if (ModalResult == mrOk)
  {
    s = cbSearchText->Text;
    if (s != "")
    {
      i = cbSearchText->Items->IndexOf(s);
      if (i > -1)
      {
        cbSearchText->Items->Delete(i);
        cbSearchText->Items->Insert(0, s);
        cbSearchText->Text = s;
      }
      else
      {
        cbSearchText->Items->Insert(0, s);
      }
    }
  }
}
//---------------------------------------------------------------------------

