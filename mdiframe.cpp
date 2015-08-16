//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "MDIEdit.h"
#include "MDIFrame.h"
#include "about.h"
//---------------------------------------------------------------------------
#pragma link "XPMenu"
#pragma resource "*.dfm"
TFrameForm *FrameForm;
//---------------------------------------------------------------------------
__fastcall TFrameForm::TFrameForm(TComponent* Owner)
    : TForm(Owner)
{
    int i;

    ActivedEditor = NULL;
    NewFileNumber = 1;
    bIsStart = true;

    TIniFile *ini = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));

    SourcePath = ini->ReadString("Options", "Path", "");
    for (i=0;i<8;i++)
    {
        HistoryFileList[i] = ini->ReadString("History", "File"+IntToStr(i+1), "");
        //if (HistoryFileList[i] == "") continue;
    }
    UpdateHistoryMenu();
    delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TFrameForm::Exit1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::TileHClick(TObject *Sender)
{
    TileMode = tbHorizontal;
    Tile();
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::Cascade1Click(TObject *Sender)
{
    Cascade();
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::Arrangeicons1Click(TObject *Sender)
{
    ArrangeIcons();
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::New1Click(TObject *Sender)
{
    bool bIsMaximized = false;

    if (bIsStart || MDIChildCount == 0)
    {
        bIsMaximized = true;
    }

    Perform(WM_SETREDRAW, 0, 0);
    EditForm = new TEditForm(this);
    if (bIsMaximized)
    {
      EditForm->WindowState = wsMaximized;
    }
    Perform(WM_SETREDRAW, 1, 0);
    RedrawWindow(Handle, NULL, 0, RDW_FRAME + RDW_INVALIDATE
                 + RDW_ALLCHILDREN + RDW_NOINTERNALPAINT);

    NewFileNumber++;
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::Open1Click(TObject *Sender)
{
  OpenFileDialog->InitialDir = SourcePath;
  if(OpenFileDialog->Execute())
  {
    SourcePath = ExtractFilePath(OpenFileDialog->FileName);
    OpenEditor(OpenFileDialog->FileName);
    AddToFileList(OpenFileDialog->FileName);
    UpdateHistoryMenu();
  }
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::HelpAbout1Click(TObject *Sender)
{
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::TileVClick(TObject *Sender)
{
    TileMode = tbVertical;
    Tile();
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::tbtnSaveClick(TObject *Sender)
{
    if (ActivedEditor != NULL)
        ActivedEditor->Save1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::tbtnCutClick(TObject *Sender)
{
    if (ActivedEditor != NULL)
        ActivedEditor->Cut1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::tbtnCopyClick(TObject *Sender)
{
    if (ActivedEditor != NULL)
        ActivedEditor->Copy1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::tbtnPasteClick(TObject *Sender)
{
    if (ActivedEditor != NULL)
        ActivedEditor->Paste1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    TIniFile *ini;
    int i;

    ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );

    ini->WriteString( "Options", "Path", SourcePath );
    for (i=0;i<8;i++)
    {
        //if (HistoryFileList[i] == "") continue;
        ini->WriteString("History", "File"+IntToStr(i+1), HistoryFileList[i]);
    }

    delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::tbtnFindClick(TObject *Sender)
{
    if (ActivedEditor != NULL)
        ActivedEditor->Find1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::tbtnFindNextClick(TObject *Sender)
{
    if (ActivedEditor != NULL)
        ActivedEditor->FindNext1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::tbtnReplaceClick(TObject *Sender)
{
    if (ActivedEditor != NULL)
        ActivedEditor->Replace1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::tbtnAsmClick(TObject *Sender)
{
    if (ActivedEditor != NULL)
        ActivedEditor->ProjectAsm1Click(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TFrameForm::AsmAll(void)
{
    //TODO: Add your source code here
    TEditForm *Edit;
    for(int i = MDIChildCount-1; i >= 0; i--)
    {
        Edit = dynamic_cast<TEditForm *>(MDIChildren[i]);
        Edit->bAutoMode = true;
        Edit->ProjectAsm1Click(this);
        Edit->bAutoMode = false;
    }
    ShowMessage("汇编全部完成！\n共处理 " + IntToStr(MDIChildCount) + " 个文件！");
}

void __fastcall TFrameForm::AddToFileList(String Filename)
{
    //TODO: Add your source code here
    int i,j;
    String List[8];
    String Temp;

    for (i=0;i<8;i++)
    {
        Temp = HistoryFileList[i];
        if (Temp != "" && Temp != Filename)
            List[i] = Temp;
    }

    for (i=0;i<7;i++)
    {
        for (j=i+1;j<8;j++)
        {
            if (List[i] == "" && List[j] != "")
            {
                Temp = List[i];
                List[i] = List[j];
                List[j] = Temp;
                break;
            }
        }
    }
    for (i=7;i>=1;i--) List[i] = List[i-1];
    List[0] = Filename;

    for (i=0;i<8;i++) HistoryFileList[i] = List[i];
}

void __fastcall TFrameForm::FormPaint(TObject *Sender)
{
    if (bIsStart)
    {
        New1Click(Sender);
        bIsStart = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::UpdateHistoryMenu(void)
{
    //TODO: Add your source code here
    int i;
    History->Clear();
    for (i=0;i<8;i++)
    {
        if (HistoryFileList[i] == "") break;
        TMenuItem *NewItem = new TMenuItem(History);
        NewItem->Caption = "&"+IntToStr(i)+" "+ExtractFileName(HistoryFileList[i]);
        NewItem->Tag = i;
        NewItem->OnClick = HistoryClick;
        History->Add(NewItem);
    }
    if (i == 0)     // 没有任何历史文件记录
    {
        TMenuItem *NewItem = new TMenuItem(History);
        NewItem->Caption = "最近使用的文件";
        NewItem->Enabled = false;
        History->Add(NewItem);
    }
}

void __fastcall TFrameForm::HistoryClick(TObject *Sender)
{
    //TODO: Add your source code here
    TMenuItem *temp;
    temp = dynamic_cast<TMenuItem *>(Sender);
    SourcePath = ExtractFilePath(HistoryFileList[temp->Tag]);
    if (!OpenEditor(HistoryFileList[temp->Tag]))
    {
      HistoryFileList[temp->Tag] = "";
      UpdateHistoryMenu();
    }
}

bool __fastcall TFrameForm::OpenEditor(String Filename)
{
    //TODO: Add your source code here
    TEditForm *Edit;

    for(int i = MDIChildCount-1; i >= 0; i--)
    {
        Edit = dynamic_cast<TEditForm *>(MDIChildren[i]);
        if (Edit->GetFilename() == Filename)
        {
            //EditForm->Open(Filename);
            Perform(WM_SETREDRAW, 0, 0);
            Edit->Show();
            Perform(WM_SETREDRAW, 1, 0);
            RedrawWindow(Handle, NULL, 0, RDW_FRAME + RDW_INVALIDATE
                         + RDW_ALLCHILDREN + RDW_NOINTERNALPAINT);
            return true;
        }
    }

    bool bIsMaximized = false;

    if (MDIChildCount == 0)
    {
        bIsMaximized = true;
    }

    if (MDIChildCount != 1 || MDIChildren[0]->Caption != "代码1")
    {
        if (FileExists(Filename))
        {
          Perform(WM_SETREDRAW, 0, 0);
          EditForm=new TEditForm(this);
          if (bIsMaximized)
          {
            EditForm->WindowState = wsMaximized;
          }
          EditForm->Open(Filename);
          Perform(WM_SETREDRAW, 1, 0);
          RedrawWindow(Handle, NULL, 0, RDW_FRAME + RDW_INVALIDATE
                       + RDW_ALLCHILDREN + RDW_NOINTERNALPAINT);
        }
        else
        {
          ShowMessage("文件 " + Filename + " 未找到！");

          return false;
        }
    }
    else
    {
        if (FileExists(Filename))
        {
          Perform(WM_SETREDRAW, 0, 0);
          Edit = dynamic_cast<TEditForm *>(MDIChildren[0]);
          if (bIsMaximized)
          {
            EditForm->WindowState = wsMaximized;
          }
          Edit->Open(Filename);
          Perform(WM_SETREDRAW, 1, 0);
          RedrawWindow(Handle, NULL, 0, RDW_FRAME + RDW_INVALIDATE
                       + RDW_ALLCHILDREN + RDW_NOINTERNALPAINT);
        }
        else
        {
          ShowMessage("文件 " + Filename + " 未找到！");

          return false;
        }
    }

    return true;
}

void __fastcall TFrameForm::FileTabChange(TObject *Sender)
{
    TEditForm *Edit;

    Edit = dynamic_cast<TEditForm *>(FileTab->Tabs->Objects[FileTab->TabIndex]);
    if (Edit != NULL)
    {
        //Edit->WindowState = wsMaximized;
        Perform(WM_SETREDRAW, 0, 0);
        Edit->Show();
        Perform(WM_SETREDRAW, 1, 0);
        RedrawWindow(Handle, NULL, 0, RDW_FRAME + RDW_INVALIDATE
                     + RDW_ALLCHILDREN + RDW_NOINTERNALPAINT);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::tbtnFindLastClick(TObject *Sender)
{
    if (ActivedEditor != NULL)
        ActivedEditor->FindLast1Click(Sender);
}
//---------------------------------------------------------------------------

// 关闭所有编辑窗口
bool __fastcall TFrameForm::CloseAllEditor(bool ExceptCurrent)
{
    TEditForm *Edit;
    int i=0;

    while (FileTab->Tabs->Count>0)
    {
      Edit = dynamic_cast<TEditForm *>(FileTab->Tabs->Objects[0+i]);
      if (Edit != NULL)
      {
        if (ExceptCurrent && ActivedEditor == Edit)
        {
          i = 1;
        }
        else
        {
          Edit->Close();
        }
      }
      if (ExceptCurrent && FileTab->Tabs->Count<2)
      {
        break;
      }
    }

    return true;
}


bool __fastcall TFrameForm::SaveAllEditor(void)
{
  //TODO: Add your source code here
    TEditForm *Edit;
    int i;

    for (i=0;i<FileTab->Tabs->Count;++i)
    {
      Edit = dynamic_cast<TEditForm *>(FileTab->Tabs->Objects[i]);
      if (Edit != NULL)
      {
         Edit->Save1Click(this);
      }
    }

    return true;
}


void __fastcall TFrameForm::SetStatusBarText(String Text)
{
    StatusBar1->Panels->Items[2]->Text = Text;
}

void __fastcall TFrameForm::SetStatusBarCaret(TBufferCoord Coord)
{
    StatusBar1->Panels->Items[0]->Text = "行: " + IntToStr(Coord.Line);
    StatusBar1->Panels->Items[1]->Text = "列: " + IntToStr(Coord.Char);
}


