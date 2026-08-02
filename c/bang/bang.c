#include <stdio.h>

int bang(int x){

    return ((x | (~x + 1)) >> 31) + 1;

}
int main() {

    printf("%d\n", bang(0));
    printf("%d\n", bang(3));
    printf("%d\n", bang(-100));

    return 0;
}