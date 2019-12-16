// Compile to wasm using the following command
// emcc test.c -s EXPORTED_FUNCTIONS=['_testing','_main'] -s WASM=1 -O3 -o test.js

#include <stdio.h>
#include <string.h>

void testing(int start_pos, int end_pos) {

    // Note that the
    char buf[200];
    char secret_password[256] = "P@ssw0rd";
    char msg[256] = "This is some unimportant user message";
    printf("Msg = %s\n", msg);

    unsigned char e = end_pos;
    if (e > strlen(msg)) {
        printf("Do not try to read past the end.\n");
    } else {
        printf("Secret = %s \t [should not be leaked]\n",secret_password);
        snprintf(buf,(end_pos - start_pos) + 1,"%s",&msg[start_pos]);
        printf("Contents Leaked: %s\n",buf);
    }


    // This doesn't compile to wasm - Emscripten doesn't allow this to compile, throws warnings
//    printf("Explicit values-> %c,%c,%c,%c", msg[0], msg[255], msg[256], msg[270]);

}

int main(void) {
    return 0;
}

