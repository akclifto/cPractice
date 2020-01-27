#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {

    char *name = "John Smith";
    printf("String length of \"John Smith\":  %d\n", strlen(name)); // length 10
    printf("\n");

    printf("Let's do some factorials!\n\n");

    printf("1! : %d\n", factorial(1)); //1
    printf("3! : %d\n", factorial(3)); //6
    printf("5! : %d\n", factorial(5)); //120
    printf("10!: %d\n", factorial(10)); //362880
}

/*factorials with recursive function:
        n = n * (n - 1)
        until terminating condition of n == 1;
        return n;
*/
int factorial(int n) {

    //terminating case
    if(n == 1) {
        return n;
    } else {
        return n * factorial(n - 1);
    }
    //if fail
    return 0;
}