//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
//---------------------------------------------------------------------------
class TF2 : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart_IC;
        TAreaSeries *Series1;
        void __fastcall On_Resize(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TF2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF2 *F2;
//---------------------------------------------------------------------------
#endif
