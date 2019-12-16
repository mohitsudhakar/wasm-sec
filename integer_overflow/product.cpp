//
// Created by Mohit on 12/5/19.
//

#ifdef __cplusplus
extern "C" {
#endif

/* Declare as: int EMSCRIPTEN_KEEPALIVE myFunction
 * when using emcc to compile to wasm
 */
int product(int a, int b) {
    return a*b;
}

#ifdef __cplusplus
}
#endif
