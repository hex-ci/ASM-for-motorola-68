//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConfirmReplaceForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormConfirmReplace *FormConfirmReplace;

const String SAskReplaceText = "替换这个文本吗？ - %s";
//---------------------------------------------------------------------------
__fastcall TFormConfirmReplace::TFormConfirmReplace(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormConfirmReplace::PrepareShow(TRect AEditorRect, int X, int Y1, int Y2, String AReplaceText)
{
  //TODO: Add your source code here
  int nW;
  int nH;

  lblConfirmation->Caption = Format(SAskReplaceText,ARRAYOFCONST((AReplaceText)));
  nW = AEditorRect.Right - AEditorRect.Left;
  nH = AEditorRect.Bottom - AEditorRect.Top;

  if (nW <= Width)
    X = AEditorRect.Left - (Width - nW) / 2;
  else
  {
    if (X + Width > AEditorRect.Right)
      X = AEditorRect.Right - Width;
  }
  if (Y2 > AEditorRect.Top + MulDiv(nH, 2, 3))
    Y2 = Y1 - Height - 4;
  else
    Y2 += 4;
  SetBounds(X, Y2, Width, Height);
}

void __fastcall TFormConfirmReplace::FormCreate(TObject *Sender)
{
  Image1->Picture->Icon->Handle = LoadIcon(0, IDI_QUESTION);
}
//---------------------------------------------------------------------------


