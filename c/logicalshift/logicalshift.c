#include <stdio.h>

int logicalShift(int x, int n) {
    int mask=~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

int main() {

    printf("%d\n", logicalShift(0x12345678, 0));
    printf("%d\n", logicalShift(0x12345678, 4));
    printf("%d\n", logicalShift(0x12345678, 8));

    return 0;
}