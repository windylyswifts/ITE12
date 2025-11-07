#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int stocks;
    int quantities;
    int ID;
    char name[25];
}units;

int counter = 0;

int main(){
    int n;

    printf("how many products do you plan to add(rough estimation): ");
    scanf("%d", &n);

    units *container = malloc(n * sizeof(units));
    if(container == NULL){
        printf("THERE WAS AN ERROR WHEN ALLOCATING MEMORY");
        return 0;
    }

    counter = n;

    menu(n, &container);

    return 0;
}

void menu(int n, units **container){
    int choice = 0, newRealloc;
    char choiceRealloc;

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
        scanf("%d", &n);            
        
        if (n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6){
            printf("\nInvalid Value\n");
            continue;
        }

        getchar();
        
        switch (choice){
        case 1:
            if (counter != 0){
                printf("Current available slots %d\n", counter);

            }
            else{
                printf("It seems that you run out of avaiable slot\n");
                printf("Do you wish to allocate more slots?: (y/n)");
                scanf("%c", &choiceRealloc);
                if (choiceRealloc == "y" || "Y"){
                    printf("How much you do want to allocate?: ");
                    scanf("%d", &newRealloc);
                    *container = realloc(*container, newRealloc * sizeof(units));
                }
                

            }
            

        
            break;
        
        default:
            break;
        }

    } while (choice != 7);
    

    
}