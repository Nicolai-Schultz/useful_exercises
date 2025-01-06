#include <stdio.h>
#include <stdlib.h>

char* copy_string(char* from, char* to) {
    int i;
    for (i = 0; i < 99 && from[i] != '\0'; i++) {
        to[i] = from[i];
    }
    to[i] = '\0';
    return to;
}

char* foo(char* a) {
    char b[99];
    char c[99];
    copy_string(a, b);
    return copy_string(b, c);
}

void bar() {
    char d[99];
    scanf("%99s", d);
    char* e;
    e = foo(d);
    printf("%s", e);
}

int main() {
    bar();
    return 0;
}