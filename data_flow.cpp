//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("Unit1.cpp", F1);
USEFORM("Unit2.cpp", F2);
USEFORM("Unit3.cpp", F3);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = " —имул€ци€ DATA-FLOW вычислител€";
                 Application->CreateForm(__classid(TF1), &F1);
                 Application->CreateForm(__classid(TF2), &F2);
                 Application->CreateForm(__classid(TF3), &F3);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
