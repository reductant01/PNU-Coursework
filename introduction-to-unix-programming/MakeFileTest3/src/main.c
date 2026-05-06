#include <stdio.h>
#include "add.h"

int main() {
    int a = 10;
    int b = 10;

    printf(" a + b = %d\n", add(a, b));
    printf(" a - b = %d\n", sub(a, b));
    
    return 0;
}