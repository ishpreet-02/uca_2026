#include <stdio.h>
int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}
int main() {
    printf("%d\n", getByte(0x12345678, 0));
    printf("%d\n", getByte(0x12345678, 2));
    printf("%d\n", getByte(0x12345678, 5));
    return 0;
}