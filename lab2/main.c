#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    float f;
    if (argc == 1)
        fprintf(stderr, "please provide numerical for calculation\n");
    else if (argc > 2)
        fprintf(stderr, "too many arguments\n");
    else if (sscanf(argv[1], "%f", &f) != 1)
        fprintf(stderr, "argument is not a valid float\n");
    else {
        float b = atof(argv[1]);
        if (b < 2) {
            fprintf(stderr, "value can't be less than 2");
            return 1;
        }

        float z1 = sqrt(2 * b + 2 * sqrt(b * b - 4));
        float z2 = 1 / sqrt(b + 2);

        printf("z1 = %f\nz2 = %f\n", z1, z2);
    }

    return 0;
}