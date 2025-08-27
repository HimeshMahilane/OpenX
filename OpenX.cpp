#include <windows.h>

#include <iostream>
#include <string>

#include "function.cpp"

using namespace std;

int main() {
  string appName;
  cout << "Enter App Name to Open: " << flush;
  getline(cin, appName);

  openApp openMyApp;
  openMyApp.open(appName);

  return 0;
}