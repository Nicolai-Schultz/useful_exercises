#include <stdio.h>

int main(void) {
    for(int i = 0; i < 6; i++) {
        printf("%d", i);
        for(int j = 6; j > 0; j--) {
            if(i < j) {
                printf("*");
                continue;
            }
            printf("-");
        }
        printf("\n");
    }
}