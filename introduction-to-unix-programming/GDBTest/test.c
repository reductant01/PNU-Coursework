// add(a,b) main x, y, z
#include <stdio.h>

int add(int a, int b) {
    int result = a + b;
    return result;
}

int main() {
    // char *str = "Hello, World!";
    // printf("str = %s\n", str);
    // str[0] = 'h'; // This will cause a segmentation fault 

    int x = 3;
    int y = 4;
    int z = add(x, y);
    printf("z = %d\n", z);
    return 0;
}