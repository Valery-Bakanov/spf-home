//---------------------------------------------------------------------------
#ifndef Unit2cH
#define Unit2cH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Menus.hpp>

#include <Clipbrd.hpp>
#include <Graphics.hpp>

//---------------------------------------------------------------------------
class TF2 : public TForm
{
__published:	// IDE-managed Components
        TMemo *M1;
        TLabel *L_TMM;
        TLabel *L_GP;
        TPanel *PN1;
        TImage *IM1;
        TImage *IM_Logo;
        TPopupMenu *M1_PM;
        TMenuItem *N21;
        TMenuItem *N22;
        TMenuItem *N23;
        TMenuItem *NP;
        TLabel *L_OM;
        void __fastcall M1_PM_ClearAll(TObject *Sender);
        void __fastcall M1_PM_CopyAll(TObject *Sender);
        void __fastcall M1_PM_CopyToNotepad(TObject *Sender);
        void __fastcall CopyPictureToClipboard(TObject *Sender);
        void __fastcall OnResize_F2(TObject *Sender);
        void __fastcall M1_OneClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TF2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF2 *F2;
//---------------------------------------------------------------------------
#endif
