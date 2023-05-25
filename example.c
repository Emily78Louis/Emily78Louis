#include <stdio.h>
#include <stdlib.h>

long int pow(long int a, long int b) {
    if (b == 0) {
        return 1;
    } else {
        return a * pow(a, (b - 1));
    }
}

char s[8];
char a[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

void Tiny_Overhead_write(long int* arg1) {
    if (*arg1 >= 4294967296) {
        printf("Error! %ld %s", *arg1, "is larger than 4294967295.");
        exit(1);
    };
    long int x = *arg1;
    for (int i = 8; i > 0; i--) {
        s[i-1] = a[(x % 16)];
        x = x / 16;
    };
}

// Optimization Required here !
long int Tiny_Overhead_read() {
    long int y = 0;
    for (int i = 8; i > 0; i--) {
        for (int j = 0; j < 0x10; j++) {
            if (s[i-1] == a[j]) {
                y = y + (pow(16, (8 - i)) * j);
            }
        }
    };
    return y;
}

int main() {
    // printf("Pass!")
    // Works like a charm
    
    long int x = 0;
    do {
        Tiny_Overhead_write(&x);
        if (x == Tiny_Overhead_read()) {
            printf("Yes! at x: %ld\n", x);
        } else {
            printf("No! at x: %ld\n", x);
            exit(1);
        };
        x++;
    } while (x < 4294967295);
    printf("Finished!\n");
}
