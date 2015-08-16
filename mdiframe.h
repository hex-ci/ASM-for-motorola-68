//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef MDIFrameH
#define MDIFrameH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include "XPMenu.hpp"
//---------------------------------------------------------------------------
class TFrameForm : public TForm
{
__published:	// IDE-managed Components 
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *New1;
    TMenuItem *Open1;
    TMenuItem *N1;
    TMenuItem *Exit1;
    TMenuItem *Window1;
    TMenuItem *TileH;
    TMenuItem *Cascade1;
    TMenuItem *Arrangeicons1;
    TOpenDialog *OpenFileDialog;
    TMenuItem *Help1;
    TMenuItem *HelpAbout1;
    TStatusBar *StatusBar1;
    TToolBar *MainToolBar;
    TToolButton *tbtnNew;
    TToolButton *tbtnOpen;
    TToolButton *tbtnSave;
    TToolButton *ToolButton3;
    TToolButton *tbtnCut;
    TToolButton *tbtnCopy;
    TToolButton *tbtnPaste;
    TToolButton *ToolButton7;
    TToolButton *tbtnTileH;
    TToolButton *tbtnTileV;
    TToolButton *tbtnCascade;
    TImageList *ImageList1;
    TMenuItem *TileV;
    TToolButton *ToolButton1;
    TToolButton *tbtnFind;
    TToolButton *tbtnFindNext;
    TToolButton *tbtnReplace;
    TToolButton *ToolButton6;
    TToolButton *tbtnAsm;
    TMenuItem *History;
    TMenuItem *HistoryFile;
    TCoolBar *FileBar;
    TTabControl *FileTab;
    TToolButton *tbtnFindLast;
    TXPMenu *XPMenu1;
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall TileHClick(TObject *Sender);
    void __fastcall Cascade1Click(TObject *Sender);
    void __fastcall Arrangeicons1Click(TObject *Sender);
    
    
    void __fastcall New1Click(TObject *Sender);
    void __fastcall Open1Click(TObject *Sender);
    void __fastcall HelpAbout1Click(TObject *Sender);
    void __fastcall TileVClick(TObject *Sender);
    void __fastcall tbtnSaveClick(TObject *Sender);
    void __fastcall tbtnCutClick(TObject *Sender);
    void __fastcall tbtnCopyClick(TObject *Sender);
    void __fastcall tbtnPasteClick(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall tbtnFindClick(TObject *Sender);
    void __fastcall tbtnFindNextClick(TObject *Sender);
    void __fastcall tbtnReplaceClick(TObject *Sender);
    void __fastcall tbtnAsmClick(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FileTabChange(TObject *Sender);
    void __fastcall tbtnFindLastClick(TObject *Sender);
private:
    bool bIsStart;
    void __fastcall UpdateHistoryMenu(void);
    bool __fastcall OpenEditor(String Filename);
public:
    TEditForm *ActivedEditor;		// User declarations
    int NewFileNumber;
    String SourcePath;
    String HistoryFileList[8];	// User declarations

    virtual __fastcall TFrameForm(TComponent* Owner);
    void __fastcall AsmAll(void);
    void __fastcall AddToFileList(String Filename);
    void __fastcall HistoryClick(TObject * Sender);
    bool __fastcall CloseAllEditor(bool ExceptCurrent = false);
    bool __fastcall SaveAllEditor(void);
    void __fastcall SetStatusBarText(String);
    void __fastcall SetStatusBarCaret(TBufferCoord);
};
//---------------------------------------------------------------------------
extern TFrameForm *FrameForm;
//---------------------------------------------------------------------------
#endif
