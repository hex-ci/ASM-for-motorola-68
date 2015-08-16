//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MDIEdit.h"
#include "MDIFrame.h"

#include "AsmThread.h"
#include "AsmStatus.h"
#include "GotoLine.h"

#include "Syn68AsmSyn.hpp"
#include "SearchForm.h"
#include "ReplaceForm.h"
#include "ConfirmReplaceForm.h"
//---------------------------------------------------------------------------
#pragma link "SynEdit"
#pragma link "SynEditPrint"
#pragma link "SynEditMiscClasses"
#pragma link "SynEditRegexSearch"
#pragma link "XPMenu"
#pragma link "SynEditOptionsDialog"
#pragma link "SynCompletionProposal"
#pragma resource "*.dfm"
TEditForm *EditForm;

//---------------------------------------------------------------------------

//const AnsiString DefaultFileName = AnsiString("无标题");

__fastcall TEditForm::TEditForm(TComponent* Owner)
    : TForm(Owner)
{
    DefaultFileName = "代码" + IntToStr(FrameForm->NewFileNumber);
    PathName = DefaultFileName;
    gsLastStatusBarText = "";
    CurrentLine = 0;
    MsgList->Height = 0;
    FrameForm->FileTab->Tabs->AddObject(PathName, this);
}
//---------------------------------------------------------------------------
void __fastcall TEditForm::Open(const AnsiString AFileName)
{
  try
  {
    PathName = AFileName;
    Editor->Lines->LoadFromFile(PathName);
    //Editor->Lines->Delete(Editor->Lines->Count);
    Editor->SelStart = 0;
    Editor->Modified = false;
    Caption = ExtractFileName(AFileName);
    FrameForm->FileTab->Tabs->Strings[FrameForm->FileTab->Tabs->IndexOfObject(this)] = Caption;
  }
  catch (Exception &e)
  {
    ShowMessage(e.Message);
    Close1Click(this); 
  }
}
void __fastcall TEditForm::New1Click(TObject *Sender)
{
  FrameForm->New1Click(Sender);
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Open1Click(TObject *Sender)
{
  FrameForm->Open1Click(Sender);
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Close1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Exit1Click(TObject *Sender)
{
  FrameForm->Exit1Click(Sender);
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Save1Click(TObject *Sender)
{
  if (PathName == DefaultFileName)
  {
    Saveas1Click(Sender);
  }
  else
  {
    //TStringList *strs = new TStringList;
    //strs->Append(Editor->Text);
    //strs->SaveToFile(PathName);
    //delete strs;
    Editor->Lines->SaveToFile(PathName);
    Editor->Modified = false;
    Caption = ExtractFileName(PathName);
    FrameForm->tbtnSave->Enabled = false;
  }
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Saveas1Click(TObject *Sender)
{
  SaveFileDialog->InitialDir = FrameForm->SourcePath;
  SaveFileDialog->FileName = PathName;
  if (SaveFileDialog->Execute())
  {
    PathName= SaveFileDialog->FileName;
    FrameForm->SourcePath = ExtractFilePath(PathName);
    Caption = ExtractFileName(PathName);
    Save1Click(Sender);
  }
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Print1Click(TObject *Sender)
{
  if (PrintDialog1->Execute())
  {
    try
    {
        EditorPrint->Lines = Editor->Lines; 
        EditorPrint->Print();
    }
    catch(...)
    {
        Printer()->EndDoc();
        throw;
    }
  }
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Printersetup1Click(TObject *Sender)
{
  PrinterSetupDialog1->Execute();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Cut1Click(TObject *Sender)
{
  Editor->CutToClipboard();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Copy1Click(TObject *Sender)
{
  Editor->CopyToClipboard();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Paste1Click(TObject *Sender)
{
  Editor->PasteFromClipboard();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Delete1Click(TObject *Sender)
{
  Editor->ClearSelection();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Selectall1Click(TObject *Sender)
{
  Editor->SelectAll();
}
//---------------------------------------------------------------------
void __fastcall TEditForm::Edit1Click(TObject *Sender)
{
  bool HasSelection;
  Paste1->Enabled = Clipboard()->HasFormat(CF_TEXT);
  Paste2->Enabled = Paste1->Enabled;
  HasSelection = (Editor->SelEnd - Editor->SelStart) > 0;
  Cut1->Enabled = HasSelection;
  Cut2->Enabled = HasSelection;
  Copy1->Enabled = HasSelection;
  Copy2->Enabled = HasSelection;
  Delete1->Enabled = HasSelection;
}
//---------------------------------------------------------------------
void __fastcall TEditForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    FrameForm->FileTab->Tabs->Delete(FrameForm->FileTab->Tabs->IndexOfObject(this));
    Action=caFree;
}
//---------------------------------------------------------------------
void __fastcall TEditForm::FormCloseQuery(TObject *Sender,
    bool &CanClose)
{
  if (Editor->Modified)
  {
      TMsgDlgButtons temp_set;
      temp_set<< mbYes<<mbNo <<mbCancel;
      String buffer = "保存更改到 " + PathName + " 吗?";

      switch(MessageDlg(buffer, mtConfirmation,temp_set,0))
      {
        case mrYes:
          Save1Click(this);
        break;
        case mrCancel:
          CanClose=false;
        break;
      }
  }
  if (CanClose)
  {
      if (FrameForm->ActivedEditor == this)
        FrameForm->ActivedEditor = NULL;
      FrameForm->tbtnCut->Enabled = false;
      FrameForm->tbtnCopy->Enabled = false;
      FrameForm->tbtnPaste->Enabled = false;
      FrameForm->tbtnSave->Enabled = false;
      FrameForm->tbtnFind->Enabled = false;
      FrameForm->tbtnFindLast->Enabled = false;
      FrameForm->tbtnFindNext->Enabled = false;
      FrameForm->tbtnReplace->Enabled = false;
      FrameForm->tbtnAsm->Enabled = false;
  }
}
//---------------------------------------------------------------------
void __fastcall TEditForm::FormCreate(TObject *Sender)
{
    DefaultFileName = "代码" + IntToStr(FrameForm->NewFileNumber);
    PathName = DefaultFileName;
    Caption = DefaultFileName;
    TSyn68AsmSyn *AsmSyn = new TSyn68AsmSyn(this);
    Editor->Highlighter = AsmSyn;
}
//---------------------------------------------------------------------
void __fastcall TEditForm::ProjectAsm1Click(TObject *Sender)
{
    if (!bAutoMode || (bAutoMode && PathName != DefaultFileName))
        Save1Click(this);
    if (Editor->Modified || PathName == DefaultFileName)
    {
        TListItem *pItem;

        MsgList->Items->Clear();
        pItem = MsgList->Items->Add();
        pItem->Caption = "1";
        pItem->SubItems->Add("汇编错误！请先保存文件！");
        //EditorSplitter->Visible = true;
        //MsgList->Visible = true;
        MsgList->Height = 100;
        //MsgList->Align = alBottom;
        //EditorSplitter->Align = alNone;
        //EditorSplitter->Align = alBottom;
        Editor->Repaint();
    }
    else
    {
        AsmForm = new TAsmForm(this);

        AsmForm->FileName = PathName;
        AsmForm->bAutoMode = bAutoMode;
        CurrentLine = 0;
        Editor->InvalidateLine(CurrentLine);
        if (bAutoMode)
            AsmForm->StartAsm();
        else
            AsmForm->ShowModal();

        delete AsmForm;
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::EditorChange(TObject *Sender)
{
    if (Editor->Modified)
    {
        Caption = ExtractFileName(PathName) + "*";
        FrameForm->tbtnSave->Enabled = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::FormActivate(TObject *Sender)
{
    // 设置当前活动的编辑窗口
    FrameForm->FileTab->TabIndex = FrameForm->FileTab->Tabs->IndexOfObject(this);
    FrameForm->ActivedEditor = this;
    FrameForm->tbtnCut->Enabled = true;
    FrameForm->tbtnCopy->Enabled = true;
    FrameForm->tbtnPaste->Enabled = true;
    FrameForm->tbtnFind->Enabled = true;
    FrameForm->tbtnFindLast->Enabled = true;
    FrameForm->tbtnFindNext->Enabled = true;
    FrameForm->tbtnReplace->Enabled = true;
    FrameForm->tbtnAsm->Enabled = true;

    EditorStatusChange(Sender, TSynStatusChanges()); //EditorSelectionChange(Sender);

    // 设置上次的状态栏文本
    FrameForm->SetStatusBarText(gsLastStatusBarText);

    if (Editor->Modified)
    {
        FrameForm->tbtnSave->Enabled = true;
    }
    else
    {
        FrameForm->tbtnSave->Enabled = false;
    }
}
//---------------------------------------------------------------------------



void __fastcall TEditForm::MsgListDblClick(TObject *Sender)
{
    if (MsgList->Selected == NULL) return;

    int NLine = StrToInt(MsgList->Selected->Caption);

    if (NLine < 0) return;
    Editor->SetFocus();
    Editor->CaretX = 1;
    Editor->CaretY = 0;
    Editor->CaretY = NLine;
    //Editor->InvalidateLine(CurrentLine);
    CurrentLine = NLine;
    Editor->InvalidateLine(NLine);
    //Editor->SelStart = Editor->CaretXPix();
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::GotoLineClick(TObject *Sender)
{
    if (GotoForm->ShowModal() == mrOk)
    {
        Editor->SelStart = SendMessage(Editor->Handle,EM_LINEINDEX,GotoForm->LineNumber,0);
        SendMessage(Editor->Handle,EM_SCROLLCARET,0,0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::MsgListContextPopup(TObject *Sender,
      TPoint &MousePos, bool &Handled)
{
    if (MsgList->Selected == NULL)
    {
        Handled = true;
        return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::UndoClick(TObject *Sender)
{
    Editor->Undo();    
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::AsmAllClick(TObject *Sender)
{
    FrameForm->AsmAll();    
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::EditorStatusChange(TObject *Sender,
      TSynStatusChanges Changes)
{
    FrameForm->SetStatusBarCaret(Editor->CaretXY);
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::ShowSearchReplaceDialog(bool AReplace)
{
    //TODO: Add your source code here
    TFormSearch *dlg;
    if (AReplace)
        dlg = new TFormReplace(this);
    else
        dlg = new TFormSearch(this);

    dlg->SearchBackwards = gbSearchBackwards;
    dlg->SearchCaseSensitive = gbSearchCaseSensitive;
    dlg->SearchFromCursor = gbSearchFromCaret;
    dlg->SearchInSelectionOnly = gbSearchSelectionOnly;
    // start with last search text
    dlg->SearchText = gsSearchText;
    if (gbSearchTextAtCaret)
    {
      // if something is selected search for that text
      if (Editor->SelAvail && (Editor->BlockBegin.Line == Editor->BlockEnd.Line))
        dlg->SearchText = Editor->SelText;
      else
        dlg->SearchText = Editor->GetWordAtRowCol(Editor->CaretXY);
    }
    dlg->SearchTextHistory = gsSearchTextHistory;
    if (AReplace)
    {
      dynamic_cast<TFormReplace *>(dlg)->ReplaceText = gsReplaceText;
      dynamic_cast<TFormReplace *>(dlg)->ReplaceTextHistory = gsReplaceTextHistory;
    }
    dlg->SearchWholeWords = gbSearchWholeWords;
    if (dlg->ShowModal() == mrOk)
    {
      gbSearchBackwards = dlg->SearchBackwards;
      gbSearchCaseSensitive = dlg->SearchCaseSensitive;
      gbSearchFromCaret = dlg->SearchFromCursor;
      gbSearchSelectionOnly = dlg->SearchInSelectionOnly;
      gbSearchWholeWords = dlg->SearchWholeWords;
      gsSearchText = dlg->SearchText;
      gsSearchTextHistory = dlg->SearchTextHistory;
      if (AReplace)
      {
        gsReplaceText = dynamic_cast<TFormReplace *>(dlg)->ReplaceText;
        gsReplaceTextHistory = dynamic_cast<TFormReplace *>(dlg)->ReplaceTextHistory;
      }
      fSearchFromCaret = gbSearchFromCaret;
      if (gsSearchText != "")
      {
        DoSearchReplaceText(AReplace, gbSearchBackwards);
        fSearchFromCaret = true;
      }
    }
    delete dlg;
}

void __fastcall TEditForm::DoSearchReplaceText(bool AReplace, bool ABackwards)
{
  TSynSearchOptions Options;

  if (AReplace)
    Options<<ssoPrompt<<ssoReplace<<ssoReplaceAll;
  else
    Options.Clear();
  if (ABackwards)
    Options<<ssoBackwards;
  if (gbSearchCaseSensitive)
    Options<<ssoMatchCase;
  if (!fSearchFromCaret)
    Options<<ssoEntireScope;
  if (gbSearchSelectionOnly)
    Options<<ssoSelectedOnly;
  if (gbSearchWholeWords)
    Options<<ssoWholeWord;
  if (Editor->SearchReplace(gsSearchText, gsReplaceText, Options) == 0)
  {
    MessageBeep(MB_ICONASTERISK);
    gsLastStatusBarText = "在当前位置之后找不到 " + gsSearchText;
    if (Options.Contains(ssoBackwards))
      Editor->BlockEnd = Editor->BlockBegin;
    else
      Editor->BlockBegin = Editor->BlockEnd;
    Editor->CaretXY = Editor->BlockBegin;
  }
  else
  {
    gsLastStatusBarText = "";
  }

  FrameForm->SetStatusBarText(gsLastStatusBarText);
  //if (FormConfirmReplace != NULL)
  //  delete FormConfirmReplace;

}
void __fastcall TEditForm::Find1Click(TObject *Sender)
{
    ShowSearchReplaceDialog(false);
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::FindNext1Click(TObject *Sender)
{
    if (gsSearchText != "")
    {
        DoSearchReplaceText(false, false);
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::Replace1Click(TObject *Sender)
{
    ShowSearchReplaceDialog(true);
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::EditorReplaceText(TObject *Sender,
      const AnsiString ASearch, const AnsiString AReplace, int Line,
      int Column, TSynReplaceAction &Action)
{
  TPoint APos;
  TPoint TempPos;
  TRect EditRect;

  if (ASearch == AReplace)
  {
    Action = raSkip;
  }
  else
  {
    APos = Point(Column, Line);
    APos = Editor->ClientToScreen(Editor->RowColumnToPixels(DisplayCoord(APos.x, APos.y)));
    EditRect = ClientRect;
    TempPos = ClientToScreen(Point(EditRect.Left,EditRect.Top));
    EditRect.Left = TempPos.x;
    EditRect.Top = TempPos.y;
    TempPos = ClientToScreen(Point(EditRect.Right,EditRect.Bottom));
    EditRect.Right = TempPos.x;
    EditRect.Bottom = TempPos.y;

    if (FormConfirmReplace == NULL)
      FormConfirmReplace = new TFormConfirmReplace(Application);
    FormConfirmReplace->PrepareShow(EditRect, APos.x, APos.y,
      APos.y + Editor->LineHeight, ASearch);
    switch (FormConfirmReplace->ShowModal())
    {
      case mrYes:
        Action = raReplace;
      break;
      case mrYesToAll:
        Action = raReplaceAll;
      break;
      case mrNo:
        Action = raSkip;
      break;
      default:
        Action = raCancel;
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::FindLast1Click(TObject *Sender)
{
    if (gsSearchText != "")
    {
        DoSearchReplaceText(false, true);
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::EditorSpecialLineColors(TObject *Sender,
      int Line, bool &Special, TColor &FG, TColor &BG)
{
    if (Line == CurrentLine)
    {
        Special = true;
        FG = clWhite;
        BG = clBlue;
    }
}
//---------------------------------------------------------------------------



void __fastcall TEditForm::FileCloseAllClick(TObject *Sender)
{
  FrameForm->CloseAllEditor();  
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::FileCloseAllNotClick(TObject *Sender)
{
  FrameForm->CloseAllEditor(true);  
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::FileSaveAllClick(TObject *Sender)
{
  FrameForm->SaveAllEditor();
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::N5Click(TObject *Sender)
{
//  TSynEditorOptionsContainer *s = new TSynEditorOptionsContainer(this);
//  SynEditOptionsDialog1->Execute(s);
//  delete s;

  SynAutoComplete1->Execute("aaa",Editor);
}
//---------------------------------------------------------------------------

