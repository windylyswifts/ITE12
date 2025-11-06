#include <stdio.h>

typedef struct{
    int stocks[25];
    int quantities[25];
    int ID[25];
    char name[25][25];
}units;

void menu(int *holder, int *count);
void addStock(int *holder, int *count);


int main(){ 
    int holder = 0, count = 0;
    
    printf("WELCOME TO THE ACCOUNT MENU\n");
    
    
    menu(&holder, &count);
    
    
    return 0;
}


void menu(int *holder, int *count){
    int checker;
    
    do{
        printf("\n---------MENU----------\n");
        printf("1. Add New Stock\n");
        printf("2. Remove Stock from Menu\n");
        printf("3. Update Quantities\n");
        printf("4. Display Stock Levels\n");
        printf("5. Save information\n");
        printf("6. Resume to previos data\n");
        printf("7. Exit\n");
        printf("Enter Option:");
        scanf("%d", &checker);
        
        switch (checker){
            case 1:
            addStock(holder, count);
            break;
            
        default:
        break;
        }
        
    } while (checker != 5);
    
    void addStock(int *holder, int *count){



        
    }
    
}
