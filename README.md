# emsdk-cheatlist

Use cmake + [emsdk](https://emscripten.org/index.html) to build multiple wasm in one time.

Prepare: emscripten 3.1.30

modify emcc.py: https://github.com/Keillion/emscripten/commit/fc55d8790a55fe3b8976a542e1bde47a5295d103

[Dynamic link](https://emscripten.org/docs/compiling/Dynamic-Linking.html) sideModule.

Use [webidl](https://emscripten.org/docs/porting/connecting_cpp_and_javascript/WebIDL-Binder.html).

Generate idl cpp and js for reference
```shell
$ /emsdk/upstream/emscripten/tools/webidl_binder mainModule.idl mainModuleGlue
```



## How to Build
```shell
$ mkdir build
$ cd build
$ emcmake cmake ../
$ emmake make
``` 

In order to see which system libs are actually needed. [refer](https://emscripten.org/docs/compiling/Dynamic-Linking.html#system-libraries)
```shell
$ emmake make VERBOSE=1
```


## Note

`html` need to be host in an HTTP server. The mimetype of `.wasm` needs to set as `application/wasm`.



## Free memery

Not freeing `char *` return value in webidl will cause a memory leak.

====

## std.js

Most fileds in wasmImport or wasmExport are not needed, I save a slimmed std.js here for reference.

