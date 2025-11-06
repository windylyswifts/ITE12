#include <stdio.h>

void swap( int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

    printf("\n%d\n", *a);

}

int main(){
    int num =2, num2 = 3;

    swap(&num, &num2);

    printf("%d", num);
    return 0;
}