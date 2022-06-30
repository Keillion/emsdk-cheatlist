#include <string>
#include <emscripten.h>

//using namespace std;

extern "C" {

void EM_array_bounds_check_error(size_t idx, size_t size);

}

