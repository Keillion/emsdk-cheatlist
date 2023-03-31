#include "a.h"

#include <emscripten/emscripten.h>

#include "EM_array_bounds_check_error.h"

// #include "opencv2/dnn.hpp"
// using namespace cv;
// using namespace dnn;

#include <cstdio>
//#include "c.h"

void aPrint(){
    emscripten_log(EM_LOG_CONSOLE, "print a\n");
    printf("Test if printf works");
    //cPrint();
}

// int main(){
//     aPrint();
// }


// Net myNet;

// extern "C" {

// void EMSCRIPTEN_KEEPALIVE emscripten_bind_mytest(const char* bufferProto, int lenProto, const char* bufferModel, int lenModel){
//     myNet = readNetFromCaffe(bufferProto, lenProto, bufferModel, lenModel);
// }

// }



