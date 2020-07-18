//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
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
#include <GanttCh.hpp>
//---------------------------------------------------------------------------
class TF3 : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart_AIU;
        TGanttSeries *Series1;
        void __fastcall On_Resize(TObject *Sender);
        void __fastcall Series1GetMarkText(TChartSeries *Sender, int ValueIndex, AnsiString &MarkText);
        void __fastcall Series1AfterDrawValues(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TF3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF3 *F3;
//---------------------------------------------------------------------------
#endif
