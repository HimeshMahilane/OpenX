#include <windows.h>

#include <iostream>
#include <string>

#include "myHeader.h"
using namespace std;

void openApp::open(string appName) {
  this->appName = appName;

  if (OpenClipboard(NULL)) {  // Opens the clipboard
    EmptyClipboard();         // Empty's it's value
    HGLOBAL hGlobal =
        GlobalAlloc(GMEM_MOVEABLE, appName.size() + 1);  // Read Bottom...
    if (hGlobal != NULL) {  // if we have a value entered by user
      char* pGlobal = (char*)GlobalLock(hGlobal);  // Read Bottom...
      strcpy(pGlobal, appName.c_str());  // Copies the appName into pGlobal
      GlobalUnlock(hGlobal);  // Unlocks the memory after copy. To use it
      SetClipboardData(CF_TEXT, hGlobal);  // hGlobal is placed into clipboard.
    }
    CloseClipboard();  // Closes the clipboard.
  }

  keybd_event(VK_LWIN, 0, 0, 0);                // Press Windows key
  keybd_event('S', 0, 0, 0);                    // Press S
  keybd_event('S', 0, KEYEVENTF_KEYUP, 0);      // Release S
  keybd_event(VK_LWIN, 0, KEYEVENTF_KEYUP, 0);  // Release Windows key

  Sleep(300);  // Wait 300ms

  keybd_event(VK_LCONTROL, 0, 0, 0);                // Press Left ctrl
  keybd_event('V', 0, 0, 0);                        // Press V
  keybd_event(VK_LCONTROL, 0, KEYEVENTF_KEYUP, 0);  // Release Left ctrl
  keybd_event('V', 0, KEYEVENTF_KEYUP, 0);          // Release V

  Sleep(100);  // Wait 100ms

  keybd_event(VK_RETURN, 0, 0, 0);                // Press Enter
  keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);  // Release Enter
};

// ~~~ HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, appName.size() + 1); ~~~
// GlobalAlloc() allocates the memory.
// The parameter GMEM_MOVABLE makes memory movable by windows.
// appName.size() is to be allocated to the memory.
// +1 to accomodate for null terminator
// hGlobal is reference to the memory which does the above.
// HGLOBAL is keyword for that.

// ~~~ char* pGlobal = (char*)GlobalLock(hGlobal); ~~~
// GlobalLock(hGlobal) is locking the allocation of memory.