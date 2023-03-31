#include "c.h"

//#include <cstdio>
#include <emscripten/emscripten.h>

void EMSCRIPTEN_KEEPALIVE cPrint(){
    //printf("print c\n");
    emscripten_log(EM_LOG_CONSOLE, "print c\n");
}
