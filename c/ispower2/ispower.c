#include <stdio.h>

int isPower2(int x){
    return !!x & !(x >> 31) & !(x & (x + ~0));
}
int main() {
    printf("%d\n", isPower2(0));
    printf("%d\n", isPower2(16));
    printf("%d\n", isPower2(28));

    return 0;
}
