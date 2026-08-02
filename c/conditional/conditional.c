#include <stdio.h>

int conditional(int x, int y,int z){
    int mask= ~(!!x)+1;
    return (mask & y) | (~mask & z);
} 
int main() {
    printf("%d\n", conditional(1, 2, 4));
    printf("%d\n", conditional(0, 2, 5));
    printf("%d\n", conditional(10, 2, 4));
}