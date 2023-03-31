#include "b.h"

//#include <cstdio>
#include <emscripten/emscripten.h>
#include "a.h"
#include "c.h"

// #include "EM_array_bounds_check_error.h"

// #include "opencv2/dnn.hpp"
// using namespace cv;
// using namespace dnn;

void bPrint(){
    //printf("print b\n");
    emscripten_log(EM_LOG_CONSOLE, "print b\n");
    cPrint();
}

int main(){
    //printf("print main\n");
    emscripten_log(EM_LOG_CONSOLE, "print main\n");
    aPrint();
    bPrint();
}

// Net myNet;

// extern "C" {

// void EMSCRIPTEN_KEEPALIVE emscripten_bind_mytest(const char* bufferProto, int lenProto, const char* bufferModel, int lenModel){
//     myNet = readNetFromCaffe(bufferProto, lenProto, bufferModel, lenModel);
// }

// }
