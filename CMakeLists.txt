cmake_minimum_required(VERSION 3.10)

# set the project name
project(A VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
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
add_compile_options(-Oz -sDISABLE_EXCEPTION_CATCHING=1 -flto -fPIC)# -fno-rtti

# set link options
#add_link_options(-Oz) # require cmake >= 3.13
# -mnontrapping-fptoint # safari in ios not support it
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Oz -sDISABLE_EXCEPTION_CATCHING=1 -flto -fPIC -sALLOW_MEMORY_GROWTH=1 --closure 0 -g1") # -fno-rtti

# https://emscripten.org/docs/compiling/Dynamic-Linking.html

add_executable(a a.cpp EM_array_bounds_check_error.cpp)
#target_include_directories(a PUBLIC  ~/dockerplayground/include/opencv4/)# ~/dockerplayground/include/opencv4/opencv2)
#set_target_properties(a PROPERTIES COMPILE_FLAGS " -s MAIN_MODULE=2 -fPIC" LINK_FLAGS " -s MAIN_MODULE=2 -fPIC -s ERROR_ON_UNDEFINED_SYMBOLS=0")
set_target_properties(a PROPERTIES COMPILE_FLAGS " -sMAIN_MODULE=2 " LINK_FLAGS " ${CMAKE_EXE_LINKER_FLAGS} -sMAIN_MODULE=2 --post-js ../glue.js b.wasm c.wasm -L.")# -sMAIN_MODULE=2 -sERROR_ON_UNDEFINED_SYMBOLS=0 -sNO_FILESYSTEM=0 -sFILESYSTEM=1 -sFORCE_FILESYSTEM=1
#target_link_libraries(a ~/dockerplayground/emsdk-cheatlist-1/build/libc.a)
#target_link_libraries(a libc.a ~/dockerplayground/build_dlr_opencv_js/lib/libopencv_world.a ~/dockerplayground/build_dlr_opencv_js/3rdparty/lib/liblibprotobuf.a ~/dockerplayground/build_dlr_opencv_js/3rdparty/lib/libquirc.a ~/dockerplayground/build_dlr_opencv_js/3rdparty/lib/libzlib.a)

# add the executable for b
add_executable(b b.cpp)
#target_include_directories(b PUBLIC  ~/dockerplayground/include/opencv4/)# ~/dockerplayground/include/opencv4/opencv2)
set_target_properties(b PROPERTIES COMPILE_FLAGS " -sSIDE_MODULE=2" LINK_FLAGS " ${CMAKE_EXE_LINKER_FLAGS} -sSIDE_MODULE=2 -sERROR_ON_UNDEFINED_SYMBOLS=0 c.wasm -L." SUFFIX ".wasm")# -sNO_FILESYSTEM=0 -sFILESYSTEM=1 -sFORCE_FILESYSTEM=1 
#target_link_libraries(b ~/dockerplayground/emsdk-cheatlist-1/build/libc.a)
#target_link_libraries(b libc.a ~/dockerplayground/build_dlr_opencv_js/lib/libopencv_world.a ~/dockerplayground/build_dlr_opencv_js/3rdparty/lib/liblibprotobuf.a ~/dockerplayground/build_dlr_opencv_js/3rdparty/lib/libquirc.a ~/dockerplayground/build_dlr_opencv_js/3rdparty/lib/libzlib.a)


# # add the executable for c
#add_library(c STATIC c.cpp)
add_executable(c c.cpp)
set_target_properties(c PROPERTIES COMPILE_FLAGS " -sSIDE_MODULE=2" LINK_FLAGS " ${CMAKE_EXE_LINKER_FLAGS} -sSIDE_MODULE=2 -sERROR_ON_UNDEFINED_SYMBOLS=0" SUFFIX ".wasm")# -sNO_FILESYSTEM=0 -sFILESYSTEM=1 -sFORCE_FILESYSTEM=1

#add_dependencies(a b)
add_dependencies(a b c)#
add_dependencies(b c)
#add_dependencies(a c)

