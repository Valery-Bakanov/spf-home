//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <jpeg.hpp>
#include "LMDSedView.hpp" // находится в ...LMD2018/lib/b6
#include "LMDSedDocument.hpp"
#include "LMDPrintPageDialog.hpp"
#include "LMDCustomComponent.hpp"
#include "LMDPrinter.hpp"
#include "LMDSedDialogs.hpp"
#include <NMHttp.hpp>
#include <Psock.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
//---------------------------------------------------------------------------
class TF1 : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *SB;
        TMainMenu *MM;
        TMenuItem *mnuFile;
        TMenuItem *mnuRedo;
        TMenuItem *N77;
        TMenuItem *mnu_SPF;
        TMenuItem *mnuGetLua;
        TMenuItem *mnuGetEdg;
        TMenuItem *N88;
        TMenuItem *N7;
        TMenuItem *N10;
        TLabel *L_FNS;
        TOpenDialog *OD_Lua;
        TSaveDialog *SD0;
        TMenuItem *CreateUpperSPF;
        TOpenDialog *OD_Edg;
        TMenuItem *N16;
        TMenuItem *mnuInfo;
        TMenuItem *N18;
        TMenuItem *N19;
        TMenuItem *N20;
        TMenuItem *Lua1;
        TMenuItem *Lua531;
        TMenuItem *Lua2;
        TPanel *PN;
        TSpeedButton *SB_OpenScript;
        TSpeedButton *SB_SaveScripr;
        TSpeedButton *SB_SaveScriptDirect;
        TSpeedButton *SB_StopScript;
        TSpeedButton *SB_StartScript;
        TSpeedButton *SB_CopyToNotepad;
        TSpeedButton *SB_PrintScript;
        TLabel *L_RC;
        TFontDialog *FD0;
        TMenuItem *N21;
        TMenuItem *WEB_AlgoWiki;
        TPopupMenu *PM_SelectColorsEV0;
        TMenuItem *N22;
        TMenuItem *API1;
        TMenuItem *N23;
        TMenuItem *Lua3;
        TMenuItem *N25;
        TMenuItem *N26;
        TMenuItem *N27;
        TMenuItem *N28;
        TMenuItem *N29;
        TLMDEditDocument *LMD_ED0;
        TLMDEditFindDialog *LMD_EFD0;
        TLMDEditReplaceDialog *LMD_ERD0;
        TMenuItem *mnuFind;
        TMenuItem *mnuReplace;
        TMenuItem *N33;
        TMenuItem *N34;
        TMenuItem *mnuSelectFont;
        TMenuItem *mnuColorsEditDocument;
        TMenuItem *mnuColunmNumering;
        TColorDialog *CD0;
        TLMDEditViewPrintTask *PrintTask;
        TPopupMenu *PM_Print;
        TMenuItem *N39;
        TMenuItem *N40;
        TMenuItem *N41;
        TMenuItem *N42;
        TMenuItem *mnuNumberingOdColunms;
        TMenuItem *N14;
        TMenuItem *N37;
        TMenuItem *N43;
        TMenuItem *N44;
        TMenuItem *N45;
        TMenuItem *N46;
        TMenuItem *N47;
        TMenuItem *N48;
        TMenuItem *N49;
        TMenuItem *N50;
        TSpeedButton *SB_UndoExecute;
        TSpeedButton *SB_RedoExecute;
        TMenuItem *mnuScript;
        TMenuItem *N52;
        TMenuItem *N53;
        TMenuItem *N54;
        TMenuItem *N55;
        TMenuItem *N56;
        TMenuItem *N57;
        TMenuItem *N58;
        TMenuItem *mnuColorSyntaxSchemes;
        TMenuItem *mnuColorScheme;
        TMenuItem *mnuSyntaxScheme;
        TLMDEditSyntaxSchemeDialog *LMD_ESSD0;
        TLMDEditColorSchemeDialog *LMD_ECSD0;
        TLMDEditGotoLineDialog *LMD_EGLD0;
        TMenuItem *mnuGoToNumber;
        TMenuItem *N5;
        TMenuItem *Thanks_LMD1;
        TPanel *PN0;
        TSplitter *SPL0;
        TMemo *M0_stdout;
        TLMDEditView *LMD_EV0;
        TMenuItem *mnuGetLua_01;
        TMenuItem *mnuGetGV_01;
        TMenuItem *mnyGetGV_02;
        TMenuItem *N1;
        TMenuItem *mnuGetSPF;
        TLMDPrinter *Printer;
        TMenuItem *N2;
        TIdHTTP *INC0;
        TMenuItem *N4;
        TMenuItem *CreateLowerSPF;
        TMenuItem *CreateTimeLiveData;
        TMenuItem *LoadAndPutIGA;
        TMenuItem *N6;
        TMenuItem *N8;
        TMenuItem *N3;
        TMenuItem *CreateParamsByOp;
        TMenuItem *N9;
        TTimer *Master_Timer;
        void __fastcall OnClose_F1(TObject *Sender, TCloseAction &Action);
        void __fastcall OnClose_1_F1(TObject *Sender, TCloseAction &Action);
        void __fastcall CloseSpfAtHome(TObject *Sender);
        void __fastcall CreateNewScript(TObject *Sender);
        void __fastcall SaveScriptToFile(TObject *Sender);
        void __fastcall OpenFileScript(TObject *Sender);
//        void __fastcall PrintScript(TObject *Sender);
        void __fastcall OnKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall StartLuaScript(TObject *Sender);
        void __fastcall CopyToNotepad(TObject *Sender);
//        void __fastcall CopyToMSWord(TObject *Sender);
        void __fastcall StopLuaScript(TObject *Sender);
        void __fastcall SaveScriptToCurrentFile(TObject *Sender);
        void __fastcall CreateUpperSpfBySelectedIgaFile(TObject *Sender);
        void __fastcall GetWebPage(TObject *Sender);
        void __fastcall GetUserAPI(TObject *Sender);
        void __fastcall AboutLua(TObject *Sender);
        void __fastcall AboutLua53(TObject *Sender);
        void __fastcall AboutLuaDetail(TObject *Sender);
//        void __fastcall CreateSpfByPredifinedIgaFile(TObject *Sender);
        void __fastcall MouseDown(TObject *Sender, TMouseButton Button,
                                  TShiftState Shift, int X, int Y);
        void __fastcall OnShow_F1(TObject *Sender);
        void __fastcall SelectFont(TObject *Sender);
        void __fastcall AboutAlgoWiki(TObject *Sender);
        void __fastcall OnResize_F1(TObject *Sender);
//        void __fastcall OnPaint_F1(TObject *Sender);
        void __fastcall OnCreate_F1(TObject *Sender);
//        void __fastcall SB_ColorsClick(TObject *Sender);
//        void __fastcall CD0_Show(TObject *Sender);
        void __fastcall FD0_Show(TObject *Sender);
        void __fastcall LMD_RD0_Show(TObject *Sender);
        void __fastcall LMD_ERD0_Show(TObject *Sender);
        void __fastcall SelectColorBackGround(TObject *Sender);
        void __fastcall SearcInScriptText(TObject *Sender);
        void __fastcall ReplaceInScriptText(TObject *Sender);
        void __fastcall FinfReplaceRepeat(TObject *Sender);
        void __fastcall PrintExecute(TObject *Sender);
        void __fastcall PrintPreview(TObject *Sender);
        void __fastcall PageSetupExecute(TObject *Sender);
        void __fastcall PrinterSetupExecute(TObject *Sender);
        void __fastcall SelectColors(TObject *Sender);
        void __fastcall CD0_Show(TObject *Sender);
        void __fastcall UndoExecute(TObject *Sender);
        void __fastcall RedoExecute(TObject *Sender);
        void __fastcall ED0_Changed(TLMDEditDocument *Sender, TLMDDocStatusChanges AChanges);
        void __fastcall M0_stdout_KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall SelectSyntaxSheme(TObject *Sender);
        void __fastcall SelectSColorSheme(TObject *Sender);
        void __fastcall GotoLineN(TObject *Sender);
//        void __fastcall Thanks_LMD_General(TObject *Sender);
        void __fastcall About_AW(TObject *Sender);
        void __fastcall SPL0Moved(TObject *Sender);
        void __fastcall OnClickGetLua_01(TObject *Sender);
        void __fastcall OnClickGetEdg_01(TObject *Sender);
        void __fastcall OnClickGetEdg_02(TObject *Sender);
        void __fastcall OnClickGetRar_01(TObject *Sender);
        void __fastcall INC0_OnConnected(TObject *Sender);
        void __fastcall INC0_Disconnected(TObject *Sender);
        void __fastcall INC0_OnWork(TObject *Sender, TWorkMode AWorkMode,
                                    const int AWorkCount);
        void __fastcall INC0_OnWorkEnd(TObject *Sender, TWorkMode AWorkMode);
        void __fastcall INC0_OnWorkBegin(TObject *Sender, TWorkMode AWorkMode,
                                         const int AWorkCountMax);
        void __fastcall INC0_OnStatus(TObject *axSender,
                                      const TIdStatus axStatus, const AnsiString asStatusText);
        void __fastcall EndedUploadFile(TObject *Sender);
        void __fastcall CreateBottomSPFClick(TObject *Sender);
        void __fastcall PutTimeLiveDataToTextFrame_Menu(TObject *Sender);
        void __fastcall ReadEdgesFileAndPutToTextFrame(TObject *Sender);
        void __fastcall PutParamsByOp(TObject *Sender);
//        void __fastcall SelectPrintAction(TObject *Sender);
        void __fastcall actBreakSetExecute(TObject *Sender);
        void __fastcall actBreakDeleteAllExecute(TObject *Sender);
        void __fastcall On_Master_Timer(TObject *Sender);
//
//        void __fastcall OnTimerCallFunc(TObject *Sender); // вызывается по таймеру MyTimer
//
private:	// User declarations
        TLMDEditSearchDlgOptions FSearchOptions;
public:		// User declarations
        __fastcall TF1(TComponent* Owner);
protected:
//
};
//---------------------------------------------------------------------------
extern PACKAGE TF1 *F1;
//---------------------------------------------------------------------------
#endif
