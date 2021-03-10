//
int outGlobal = 0; // глобал для запоминания, из какого MenuItem вызван CD0
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void ShowSearchNotFound() // будет использована в SearcExecute,ReplaceExecute,SearchNextExecute
{
 AnsiString s = F1->LMD_EV0->SearchLastArgs.Search; // взяли строку последнего поиска
 MessageDlg( Format("Строка поиска '%s' не найдена...",
             ARRAYOFCONST(( s )) ), mtInformation, TMsgDlgButtons() << mbOK, -1 );
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SearcInScriptText(TObject *Sender)
{ // найти в тексте скрипта
 if ( LMDEditExecFindDialog("Поиск в тексте скрипта Lua", LMD_EV0, FSearchOptions) == srNotFound )
  ShowSearchNotFound();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::ReplaceInScriptText(TObject *Sender)
{ // заменить в тексте скрипта
 if (LMD_EV0->SelAvail)
   FSearchOptions.ReplaceAllBounds = rbSelection;
 else
   FSearchOptions.ReplaceAllBounds = rbAllText;

 TLMDEditSearchResult Res =
  LMDEditExecReplaceDialog("Замена в тексте скрипта Lua", LMD_EV0, FSearchOptions);

 if (Res == srNotFound)
 {
  ShowSearchNotFound();
 }
 else if (( Res == srFound )                     &&
          ( FSearchOptions.WasReplaceAllChosen ) &&
          ( FSearchOptions.LastNumberOfReplacements > 0 ) )
 {
  MessageDlg(Format("Число замен: %d",
             ARRAYOFCONST(( FSearchOptions.LastNumberOfReplacements ))),
             mtInformation, TMsgDlgButtons() << mbOK, -1);
 }
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::FinfReplaceRepeat(TObject *Sender)
{ // найти или заменить в тексте скрипта
 bool Ok = true;

 switch ( LMD_EV0->SearchState ) // какой режим - поиск или замена ?
 {
  case stInSearch: // режим поиска (Ctrl+F)
       Ok = LMD_EV0->SearchNext();
       break;
  case stInReplace: // режим замены (Ctrl+R)
       Ok = LMD_EV0->ReplaceNext();
       break;
  default:
       Beep();
 }

 if ( !Ok )
  ShowSearchNotFound();

} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::PrintExecute(TObject *Sender)
{ // вызывает окно Print
 PrintTask->View = LMD_EV0; // настроим на EditView

 PrintTask->PreparePages();

 try
 {
  PrintTask->ExecPrintDlg();
 }
 __finally
 {
  PrintTask->FinalizePages();
 }
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::PrintPreview(TObject *Sender)
{ // вызывает PrintPreview
 PrintTask->View = LMD_EV0; // настроим на EditView

 PrintTask->PreparePages();

 try
 {
  PrintTask->ExecPrintPreviewDlg();
 }
 __finally
 {
  PrintTask->FinalizePages();
 }
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::PageSetupExecute(TObject *Sender)
{ // вызывает PageSetup
 Printer->ExecPageSetupDlg();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::PrinterSetupExecute(TObject *Sender)
{ // вызывает PrintSetup
 Printer->ExecPrintSetupDlg();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::actBreakSetExecute(TObject *Sender)
{ // установить точку проверки (Breakpoint)
 int Ph = LMD_EV0->ScrollToPhysical(LMD_EV0->CursorPos.y); // перейти на строку y
 _di_ILMDMark Brk = LMD_EV0->Document->Breakpoints->CreateMarkAtLine(Ph); // создать
//mkBreakDisabled; mkBreakInactive; mkBreakActive;
 LMD_EV0->Document->SetBreakpointKind(Brk, mkBreakActive); // показать
} // ----- конец actBreakSetExecute --------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::actBreakDeleteAllExecute(TObject *Sender)
{  // очистить все точки проверки (Breakpoint)
 LMD_EV0->Document->Breakpoints->Clear();
} // ----- конец actBreakDeleteAllExecute --------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::UndoExecute(TObject *Sender)
{ // фуекция Undo
 if( LMD_ED0->CanUndo )
  LMD_ED0->Undo();
 else
  Beep();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::RedoExecute(TObject *Sender)
{ // функция Redo
 if( LMD_ED0->CanRedo )
  LMD_ED0->Redo();
 else
  Beep();
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::SelectColors(TObject *Sender)
{ // выбор цветов окна редактора Lua
 outGlobal = ((TComponent *)Sender)->Tag; // какой из 8 вариантов MenuItem вызвал эту процедуру
//
 switch( outGlobal ) // выбор по значению outGlobal
 {
  case 1: CD0->Color = LMD_EV0->Gutter->LinesBarBg;
          if( CD0->Execute() )
           LMD_EV0->Gutter->LinesBarBg = CD0->Color;
          break;
  case 2: CD0->Color = LMD_EV0->Gutter->LinesBarTextColor;
          if( CD0->Execute() )
           LMD_EV0->Gutter->LinesBarTextColor = CD0->Color;
          break;
  case 3: CD0->Color = LMD_EV0->Gutter->FoldsBarBg;
          if( CD0->Execute() )
           LMD_EV0->Gutter->FoldsBarBg = CD0->Color;
          break;
  case 4: CD0->Color = LMD_EV0->Gutter->FoldsBarLineColor;
          if( CD0->Execute() )
           LMD_EV0->Gutter->FoldsBarLineColor = CD0->Color;
          break;
  case 5: CD0->Color = LMD_EV0->Gutter->CustomBarBg;
          if( CD0->Execute() )
           LMD_EV0->Gutter->CustomBarBg = CD0->Color;
          break;
  case 6: CD0->Color = LMD_EV0->SelectionBg;
          if( CD0->Execute() )
           LMD_EV0->SelectionBg = CD0->Color;
          break;
  case 7: CD0->Color = LMD_EV0->SelectionColor;
          if( CD0->Execute() )
           LMD_EV0->SelectionColor = CD0->Color;
          break;
  case 8: CD0->Color = LMD_EV0->Color;
          if( CD0->Execute() )
           LMD_EV0->Color = CD0->Color;
          break;
  default:Beep();
          break;
 }
//
 Write_Config(); // сохранили изменения цветов
//
} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::CD0_Show(TObject *Sender)
{ // вызывается при отрисовке окна ColorDialog
 switch( outGlobal ) // выбор по значению outGlobal
 {
  case 1: SetWindowText( CD0->Handle, "Выбрать цвет фона столбца нумерации строк");
          break;
  case 2: SetWindowText( CD0->Handle, "Выбрать цвет символов нумерации строк");
          break;
  case 3: SetWindowText( CD0->Handle, "Выбрать цвет фона столбца свёртки синтаксиса");
          break;
  case 4: SetWindowText( CD0->Handle, "Выбрать цвет символов свёртки синтаксиса");
          break;
  case 5: SetWindowText( CD0->Handle, "Выбрать цвет столбца-разделителя");
          break;
  case 6: SetWindowText( CD0->Handle, "Выбрать цвет фона выделенных символов");
          break;
  case 7: SetWindowText( CD0->Handle, "Выбрать цвет выделенных символов");
          break;
  case 8: SetWindowText( CD0->Handle, "Выбрать цвет фона окна редактирования");
          break;
  default:break;
 }

} //----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TF1::ED0_Changed(TLMDEditDocument *Sender,
                                 TLMDDocStatusChanges AChanges)
{ // ????????? ? ????????? ED0
 if( LMD_ED0->CanUndo )
  SB_UndoExecute->Enabled = TRUE;
//  SB_CopyToNotepad->Enabled = TRUE;
 else
  SB_UndoExecute->Enabled = FALSE;
//  SB_CopyToNotepad->Enabled = FALSE;

 if( LMD_ED0->CanRedo )
  SB_RedoExecute->Enabled = TRUE;
 else
  SB_RedoExecute->Enabled = FALSE;

// MessageBeep( MB_OK ); // ???????? ??????????????...

} //----------------------------------------------------------------------------
