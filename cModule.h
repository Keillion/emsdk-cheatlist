#ifndef __KEILLION_MAIN_MODULE_H__
#define __KEILLION_MAIN_MODULE_H__

#include <string>
#include "sideModule.h"

//class CModule;
//{
using namespace std;

class CModule{
public:
  string name;
  string birthday;
  CModule(const char* name, const char* birthday);
  char* getInfo();
};

//}
#endif
