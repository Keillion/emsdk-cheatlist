#include "cModule.h"

#include <string>
//#include "emscripten/emscripten.h"
//#include "emscripten/bind.h"
//#include "emscripten/val.h"

#include "cModuleGlue.cpp"

using namespace std;
//using namespace emscripten;

CModule::CModule(const char* name, const char* birthday){
  this->name = name;
  this->birthday = birthday;
}
char* CModule::getInfo(){
  auto sideModuleInstance = new SideModule(name.c_str(), birthday.c_str());
  auto strSideModuleInfo = sideModuleInstance->getInfo();
  delete sideModuleInstance;
  auto strInfo = "cModule: " + this->name + ", " + this->birthday + "\n" + strSideModuleInfo;
  auto size = strInfo.size();
  auto pszInfo = new char[size+1];
  pszInfo[size] = '\0';
  strcpy(pszInfo, strInfo.c_str());
  return pszInfo;
}

//EMSCRIPTEN_BINDINGS(CModule){
//  class_<CModule>("CModule")
//    .constructor<string,string>()
//    .function("getInfo", &CModule::getInfo);
//}

