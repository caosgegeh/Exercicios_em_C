#include <stdio.h>

void main() {
    for (int i = 1; i < 11; i++) {
        printf("\n Tabuada do %d\n", i);
        for (int j = 1; j < 11; j++) {
            printf("%d * %d = %d\n", i,j,i*j);
        }
        printf("\n");
    }
}
