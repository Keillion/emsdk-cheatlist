cmake_minimum_required(VERSION 3.10)

# set the project name
project(A VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(EM_BUILD_VERBOSE 1)
#set(CMAKE_VERBOSE_MAKEFILE 1)
#set(VERBOSE 1)

# maybe usefull option for compile and link
# -s ALLOW_TABLE_GROWTH
# -fPIC
# -s DISABLE_EXCEPTION_CATCHING=1
# -s EXCEPTION_CATCHING_ALLOWED=[]
# -msimd128
# -fexceptions
# -fno-PIC
# -s ALLOW_MEMORY_GROWTH=1
# --no-entry
# --closure 1

# set compile options
# when use multiple "-s" in old cmake: https://gitlab.kitware.com/cmake/cmake/-/issues/15826
# or you can use set_target_properties instead
# -mnontrapping-fptoint # safari in ios not support it
add_compile_options(-Oz -s DISABLE_EXCEPTION_CATCHING=1 -flto)

# set link options
#add_link_options(-Oz) # require cmake >= 3.13
# -mnontrapping-fptoint # safari in ios not support it
set(CMAKE_EXE_LINKER_FLAGS "-Oz -s DISABLE_EXCEPTION_CATCHING=1 ${CMAKE_EXE_LINKER_FLAGS} -flto")

# https://emscripten.org/docs/compiling/Dynamic-Linking.html

add_executable(mainModule EM_array_bounds_check_error.cpp)
set_target_properties(mainModule PROPERTIES COMPILE_FLAGS " -s MAIN_MODULE=2 -fPIC" LINK_FLAGS " -s MAIN_MODULE=2 -fPIC -s ERROR_ON_UNDEFINED_SYMBOLS=0 --post-js ../cModuleGlue.js sideModule.wasm cModule.wasm -L.")

# add the executable for sideModule
add_executable(sideModule sideModule.cpp)
set_target_properties(sideModule PROPERTIES COMPILE_FLAGS " -s SIDE_MODULE=2 -fPIC" LINK_FLAGS " -s SIDE_MODULE=2 -fPIC cModule.wasm" SUFFIX ".wasm") # cModule.wasm
#target_link_libraries(sideModule cModule)


# add the executable for cModule
add_executable(cModule cModule.cpp)
set_target_properties(cModule PROPERTIES COMPILE_FLAGS " -s SIDE_MODULE=2 -fPIC" LINK_FLAGS " -s SIDE_MODULE=2 -fPIC -s ERROR_ON_UNDEFINED_SYMBOLS=0" SUFFIX ".wasm")

add_dependencies(mainModule sideModule cModule)
add_dependencies(sideModule cModule)

