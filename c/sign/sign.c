#include <stdio.h>
int sign(int x) {
    return (x>>31) | !!x;
}
int main() {

    printf("%d\n", sign(0));
    printf("%d\n", sign(10));
    printf("%d\n", sign(-100));

    return 0;

}