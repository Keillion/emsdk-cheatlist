
#include <emscripten.h>
#include "EM_array_bounds_check_error.h"

// Not using size_t for array indices as the values used by the javascript code are signed.

//EM_JS(void, array_bounds_check_error, (size_t idx, size_t size), {
//  throw 'Array index ' + idx + ' out of bounds: [0,' + size + ')';
//});

void array_bounds_check(const int array_size, const int array_idx) {
  if (array_idx < 0 || array_idx >= array_size) {
    EM_array_bounds_check_error(array_idx, array_size);
  }
}

// VoidPtr

void EMSCRIPTEN_KEEPALIVE emscripten_bind_VoidPtr___destroy___0(void** self) {
  delete self;
}

// MainModule

MainModule* EMSCRIPTEN_KEEPALIVE emscripten_bind_MainModule_MainModule_2(char* name, char* birthday) {
  return new MainModule(name, birthday);
}

char* EMSCRIPTEN_KEEPALIVE emscripten_bind_MainModule_getInfo_0(MainModule* self) {
  return self->getInfo();
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_MainModule___destroy___0(MainModule* self) {
  delete self;
}

