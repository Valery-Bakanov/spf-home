//---------------------------------------------------------------------------

#ifndef Unit3cH
#define Unit3cH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class MyThread : public TThread
{
  typedef struct tagTHREADNAME_INFO
  {
    DWORD dwType;     // must be 0x1000
    LPCSTR szName;    // pointer to name (in user addr space)
    DWORD dwThreadID; // thread ID (-1=caller thread)
    DWORD dwFlags;    // reserved for future use, must be zero
  } THREADNAME_INFO;
private:
  void SetName();
  void __fastcall Work();
protected:
        void __fastcall Execute();
public:
        __fastcall MyThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
