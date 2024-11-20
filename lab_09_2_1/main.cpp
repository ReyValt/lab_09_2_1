#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

#define Z_VALUE 11
#define SQR(a) ((a) * (a))
#define CUBE(a) ((a) * (a) * (a))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define MAX(b, c) ((b) > (c) ? (b) : (c))
#define MIN(b, c) ((b) < (c) ? (b) : (c))

#define PRINTI(w) puts("Control output"); \
 printf(#w " = %d\n", w)
#define PRINTR(w) puts("Result:"); \
 printf(#w " = %f\n", (float)w)

int main() {
    puts("Lab 9.2. Using macros and preprocessing directives");
    int x, y, z;
    int x_plus_y_cube, x_kvadr, maxim;
    int abs_x_minus_z, abs_x_plus_z, minim;
    char ch;

    do {
#if Z_VALUE > 10 
        puts("Define maximum of two numbers");
        puts("Input integer numbers");
        scanf("%d", &x);
        PRINTI(x);
        scanf("%d", &y);
        PRINTI(y);
        scanf("%d", &z);
        PRINTI(z);

        x_kvadr = CUBE(x);
        PRINTI(x_kvadr);
        x_plus_y_cube = SQR(x + y);
        PRINTI(x_plus_y_cube);
        maxim = MAX(x_kvadr, x_plus_y_cube);
        maxim = MAX(maxim, z);
        PRINTR(maxim);

#else
        puts("Input 3 integer numbers");
        scanf("%d", &x);
        PRINTI(x);
        scanf("%d", &y);
        PRINTI(y);
        scanf("%d", &z);
        PRINTI(z);

        puts("Define minimum of two numbers");
        abs_x_minus_z = ABS(x - z);
        PRINTI(abs_x_minus_z);
        abs_x_plus_z = ABS(x + z);
        PRINTI(abs_x_plus_z);
        minim = MIN(abs_x_minus_z, abs_x_plus_z);
        minim = MIN(minim, z);
        PRINTR(minim);
#endif
        puts("Repeat? y/n");
        ch = _getch();
    } while (ch == 'y');

    return 0;
}