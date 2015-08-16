//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReplaceForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SearchForm"
#pragma resource "*.dfm"
TFormReplace *FormReplace;
//---------------------------------------------------------------------------
__fastcall TFormReplace::TFormReplace(TComponent* Owner)
    : TFormSearch(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormReplace::SetReplaceText(String value)
{
    //TODO: Add your source code here
    cbReplaceText->Text = value;
}
String __fastcall TFormReplace::GetReplaceText()
{
    //TODO: Add your source code here
    return cbReplaceText->Text;
}

void __fastcall TFormReplace::SetReplaceTextHistory(String value)
{
    //TODO: Add your source code here
    cbReplaceText->Items->Text = value;
}
String __fastcall TFormReplace::GetReplaceTextHistory()
{
    //TODO: Add your source code here
  int i;
  String Temp;

  for (i=0;i<cbReplaceText->Items->Count;i++)
  {
    if (i >= 10) break;
    if (i > 0) Temp += "\n";
    Temp += cbReplaceText->Items->Strings[i];
  }
  return Temp;
}

void __fastcall TFormReplace::FormCloseQuery(TObject *Sender,
      bool &CanClose)
{
  int i;
  String s;
  
  TFormSearch::FormCloseQuery(Sender,CanClose);
  
  if (ModalResult == mrOk)
  {
    s = cbReplaceText->Text;
    if (s != "")
    {
      i = cbReplaceText->Items->IndexOf(s);
      if (i > -1)
      {
        cbReplaceText->Items->Delete(i);
        cbReplaceText->Items->Insert(0, s);
        cbReplaceText->Text = s;
      }
      else
      {
        cbReplaceText->Items->Insert(0, s);
      }
    }
  }
}
//---------------------------------------------------------------------------

