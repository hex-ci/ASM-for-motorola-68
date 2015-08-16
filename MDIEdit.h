//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef MDIEditH
#define MDIEditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <Printers.hpp>
#include <Clipbrd.hpp>
#include "SynEdit.hpp"
#include "SynEditPrint.hpp"
#include <ExtCtrls.hpp>
#include "SynEditMiscClasses.hpp"
#include "SynEditRegexSearch.hpp"
#include "XPMenu.hpp"
#include "SynEditOptionsDialog.hpp"
#include "SynCompletionProposal.hpp"
//---------------------------------------------------------------------------
class TEditForm : public TForm
{
__published:	// IDE-managed Components 
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *New1;
    TMenuItem *Open1;
    TMenuItem *Close1;
    TMenuItem *Save1;
    TMenuItem *Saveas1;
    TMenuItem *Print1;
    TMenuItem *Printersetup1;
    TMenuItem *N2;
    TMenuItem *Exit1;
    TMenuItem *Edit1;
    TMenuItem *Cut1;
    TMenuItem *Copy1;
    TMenuItem *Paste1;
    TMenuItem *Delete1;
    TMenuItem *N3;
    TMenuItem *Selectall1;
    TPopupMenu *EditorMenu;
    TMenuItem *Cut2;
    TMenuItem *Copy2;
    TMenuItem *Paste2;
    TSaveDialog *SaveFileDialog;
    TPrinterSetupDialog *PrinterSetupDialog1;
    TPrintDialog *PrintDialog1;
    TMenuItem *N1;
    TMenuItem *N6;
    TMenuItem *Project1;
    TMenuItem *ProjectAsm1;
    TMenuItem *Find1;
    TMenuItem *N4;
    TListView *MsgList;
    TMenuItem *GotoLine;
    TPopupMenu *MsgMenu;
    TMenuItem *G1;
    TMenuItem *Undo;
    TMenuItem *N7;
    TMenuItem *Replace1;
    TMenuItem *FindNext1;
    TMenuItem *AsmAll;
    TSynEdit *Editor;
    TSynEditPrint *EditorPrint;
    TMenuItem *FindLast1;
  TMenuItem *FileCloseAll;
  TMenuItem *FileCloseAllNot;
  TMenuItem *FileSaveAll;
  TSplitter *EditorSplitter;
    TSynEditRegexSearch *RegexSearchEngine;
    TXPMenu *XPMenu1;
    TSynEditOptionsDialog *SynEditOptionsDialog1;
    TMenuItem *N5;
    TSynAutoComplete *SynAutoComplete1;
    void __fastcall New1Click(TObject *Sender);
    void __fastcall Open1Click(TObject *Sender);
    void __fastcall Close1Click(TObject *Sender);
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall Save1Click(TObject *Sender);
    void __fastcall Saveas1Click(TObject *Sender);
    void __fastcall Print1Click(TObject *Sender);
    void __fastcall Printersetup1Click(TObject *Sender);
    void __fastcall Cut1Click(TObject *Sender);
    void __fastcall Copy1Click(TObject *Sender);
    void __fastcall Paste1Click(TObject *Sender);
    void __fastcall Delete1Click(TObject *Sender);
    void __fastcall Selectall1Click(TObject *Sender);
    void __fastcall Edit1Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ProjectAsm1Click(TObject *Sender);
    void __fastcall EditorChange(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall MsgListDblClick(TObject *Sender);
    void __fastcall GotoLineClick(TObject *Sender);
    void __fastcall MsgListContextPopup(TObject *Sender, TPoint &MousePos,
          bool &Handled);
    void __fastcall UndoClick(TObject *Sender);
    void __fastcall AsmAllClick(TObject *Sender);
    void __fastcall EditorStatusChange(TObject *Sender,
          TSynStatusChanges Changes);
    void __fastcall Find1Click(TObject *Sender);
    void __fastcall FindNext1Click(TObject *Sender);
    void __fastcall Replace1Click(TObject *Sender);
    void __fastcall EditorReplaceText(TObject *Sender,
          const AnsiString ASearch, const AnsiString AReplace, int Line,
          int Column, TSynReplaceAction &Action);
    void __fastcall FindLast1Click(TObject *Sender);
    void __fastcall EditorSpecialLineColors(TObject *Sender, int Line,
          bool &Special, TColor &FG, TColor &BG);
  void __fastcall FileCloseAllClick(TObject *Sender);
  void __fastcall FileCloseAllNotClick(TObject *Sender);
  void __fastcall FileSaveAllClick(TObject *Sender);
    void __fastcall N5Click(TObject *Sender);
private:	// User declarations
    String PathName;
    String DefaultFileName;
    bool gbSearchBackwards;
    bool gbSearchCaseSensitive;
    bool gbSearchFromCaret;
    bool gbSearchSelectionOnly;
    bool gbSearchTextAtCaret;
    bool gbSearchWholeWords;
    String gsSearchText;
    String gsSearchTextHistory;
    String gsReplaceText;
    String gsReplaceTextHistory;
    bool fSearchFromCaret;
    int CurrentLine;

    String gsLastStatusBarText;
    
    void __fastcall ShowSearchReplaceDialog(bool AReplace);
    void __fastcall DoSearchReplaceText(bool AReplace, bool ABackwards);
public:
    bool bAutoMode;		// User declarations
    void    __fastcall Open(const AnsiString AFileName);
    String __fastcall GetFilename(void) {return PathName;}
    virtual __fastcall TEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TEditForm *EditForm;
//---------------------------------------------------------------------------

#endif
