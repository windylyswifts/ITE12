#include <stdio.h>
struct empty{};


int main(){
    int a = sizeof(struct empty);

    printf("%d", a);


    return 0;
}