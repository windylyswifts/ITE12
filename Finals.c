#include <stdio.h>

void addstock();
void menu();
void update();
void addmore();
void display();


void addstock(int n,char name[][25],int quantities[], int id[], int sales[] ,float prices[]){
    for (int i = 0; i < n; i++)
    {
        printf("%d product name:\n", i+1);
        fgets(name[i], 25, stdin);
        printf("Enter how much quantities?:\n");
        scanf("%d", &quantities[i]);
        printf("Enter ID:\n");
        scanf("%d", &id[i]);
        printf("Enter its availability, 0 for not available, 1 for available:\n");
        scanf("%d", &sales[i]);
        printf("What is the current price for this?:\n");
        scanf("%f", &prices[i]);
        getchar();
    }
}

void addmore(int *container,int *n,char name[][25],int quantities[], int id[], int sales[] ,float prices[]){
    for(int i = 0 + *n; i < *n + *container ;i++){
        printf("%d product name:\n", i+1);
        fgets(name[i], 25, stdin);
        printf("Enter how much quantities?:\n");
        scanf("%d", &quantities[i]);
        printf("Enter ID:\n");
        scanf("%d", &id[i]);
        printf("Enter its availability, 0 for not available, 1 for available:\n");
        scanf("%d", &sales[i]);
        printf("What is the current price for this?:\n");
        scanf("%f", &prices[i]);
        getchar();
    }

    *n += *container;
}

void update(int id[], int quantities[],int  *n){
    int choice;
    int i = 0, found = 0;
    printf("What is the ID of this product?:");
    scanf("%d", &choice);
    for (; i < *n; i++)
    {
        if (choice ==  id[i])
        {
            printf("ID found\n");
            found = 1;
            printf("Current Quantity of this product:%d\n", quantities[i]);
            printf("Enter the Updated Amount or quantity\n:");
            scanf("%d", &quantities[i]);
            printf("Updated Quantity Complete:%d\n", quantities[i]);
            break;
        }
    }
    if (found != 1)
    {
        printf("No ID was found\n");
    }
}

void display(int *n,char name[][25],int quantities[], int id[], int sales[] ,float prices[]){
    printf("Here is the all the details so far:\n");
    for (int i = 0; i < *n; i++)
    {
        printf("%d Product\n", i+1);
        printf("Name:%s", name[i]);
        printf("Quantities:%d\n", quantities[i]);
        printf("ID:%d\n", id[i]);
        printf("Sales:%d\n", sales[i]);
        printf("Price:%.2f\n", prices[i]);
    }
}

void menu(int *container,int *n,char name[][25],int quantities[], int id[], int sales[] ,float prices[]){
    int choice = 0; 

    do{
        printf("-------MENU-------\n");
        printf("1.Add More products\n");
        printf("2.Update Quantities of a product\n");
        printf("3.Display Current Stock\n");
        printf("4.Exit\n");
        scanf("%d", &choice);
        if (choice != 1 && choice != 2 && choice != 3)
        {
            printf("Input Invalid\n");
        }
        switch (choice)
        {
        case 1:
            printf("How much do you want to add?");
            scanf("%d", container);
            getchar();
            addmore(container,n, name, quantities, id, sales, prices);
            break;
        case 2:
            update(id, quantities, n);
            break;
        case 3:
            display(n, name, quantities, id, sales, prices);
            break;
        default:
            break;
        }
    }while(choice != 4);
}


int main(){ 
    int container,n ,id[25], quantities[25], sales[25];
    char name[25][25];
    float prices[25];

    printf("How much items do you want?:");
    scanf("%d", &n);
    
    getchar();

    addstock(n, name, quantities, id, sales, prices);
    menu(&container,&n, name, quantities, id, sales, prices);
    return 0;
}