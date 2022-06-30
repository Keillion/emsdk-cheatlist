#include "EM_array_bounds_check_error.h"

#include <emscripten.h>

extern "C" {

EM_JS(void, EM_array_bounds_check_error, (size_t idx, size_t size), {
  throw 'Array index ' + idx + ' out of bounds: [0,' + size + ')';
});

}

