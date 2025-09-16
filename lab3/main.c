#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char* buf = malloc(2000 * sizeof(char));

    printf("Please enter string (up to 2000 chars): ");
    scanf("%s", buf);

    int len = strlen(buf);
    int k = 1;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0 && i > 0) {
            buf[i-k] = buf[i];
            k++;
        }
    }

    int m = ceil((float)len / 2); 
    buf[m] = 0;

    printf("Result: %s\n", buf);
    return 0;
}