#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int quantities;
    int ID;
    char name[25];
}units;

int counter = 0;
int deadline = 0;

void menu(int *n, units **container);
void addStock(int *n, units **container);
int main(){
    int n;

    printf("how many products do you plan to add(rough estimation): ");
    scanf("%d", &n);

    units *container = malloc(n * sizeof(units));
    if(container == NULL){
        printf("THERE WAS AN ERROR WHEN ALLOCATING MEMORY");
        return 0;
    }

    deadline = n;

    menu(&n, &container);

    return 0;
}

void menu(int *n, units **container){
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
        scanf("%d", &choice);            
        

        if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6){
            printf("\nInvalid Value\n");
            continue;
        }

        getchar();
        
        switch (choice){
        case 1:
            if (deadline != 0){
                printf("Current available slots %d\n", counter);
                addStock(n, container);

            }
            else{
                printf("It seems that you run out of avaiable slot\n");
                printf("Do you wish to allocate more slots?: (y/n)");
                scanf(" %c", &choiceRealloc);
                if (choiceRealloc == 'y' || choiceRealloc == 'Y'){
                    printf("How much you do want to allocate?: ");
                    scanf("%d", &newRealloc);
                    units *ptr = realloc(*container, (newRealloc * (*n)) *sizeof(units));
                    if (ptr == NULL){
                        printf("There was a problem during reallocating more slots\n");
                        return;
                    }
                }
            }        
            break;
        
        default:
            break;
        }

    } while (choice != 7);
    

    
}

void addStock(int *n, units **container){
    for (int i = counter; i < *n; i++){
        printf("Product Number [%d]:\n",i+1);
        printf("What is the name of the product: ");
        fgets((*container)[i].name, 25, stdin);
        printf("Enter the quantity of %s:", (*container)[i].name);
        scanf("%d", &(*container)[i].quantities);
        printf("Whats the ID for %s", (*container)[i].name);
        scanf("%d", &(*container)[i].ID);
        getchar();
    }

    counter = *n;
}