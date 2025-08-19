#include <stdio.h>
#include <string.h>

void menu(int *contianer, int *count,int stocks[], int ID[], char name[][25], int quantities[]);
void addstock(int *container, int *count, int stocks[], int ID[], char name[][25], int quantities[]);
void removestock( int *count, int stocks[], int ID[], char name[][25], int quantities[]);
void update(int *count,int ID[], int quantities[]);
void display(int ID[], char name[][25], int quantities[], int *count);
void Save(int *contianer, int *count,int stocks[], int ID[], char name[][25], int quantities[]);
void removedata();


void addstock(int *container, int *count,int stocks[], int ID[], char name[][25], int quantities[]){
    if(*count == 0){
        for (int i = 0; i < *container; i++){
            printf("\nItem number %d\n", i+1);
            printf("\nAssign ID:");
            scanf("%d", &ID[i]);
            getchar();
            printf("\nWhats the name of this stock?:");
            fgets(name[i], 25, stdin);
            printf("\nHow many Quantity?:");
            scanf("%d", &quantities[i]);
        }   
        *count = *container;
    }
    else{
        for (int i = *count; i < *count + *container; i++){
            printf("\nItem number %d\n", i+1);
            printf("\nAssign ID:");
            scanf("%d", &ID[i]);
            getchar();
            printf("\nWhats the name of this stock?:");
            fgets(name[i], 25, stdin);
            printf("\nHow many Quantity?:");
            scanf("%d", &quantities[i]);
            }
    }
}
void menu(int *contianer, int *count,int stocks[], int ID[], char name[][25], int quantities[]) {
    int n = 0;
    do {
        printf("\n---------MENU----------\n");
        printf("1. Add New Stock\n");
        printf("2. Remove Stock from Menu\n");
        printf("3. Update Quantities\n");
        printf("4. Display Stock Levels\n");
        printf("5. Save information\n");
        printf("6. Remove Saved Data\n");
        printf("7. Resume to previos data\n");
        printf("8. Exit\n");
        printf("Enter Option:");
        scanf("%d", &n);            

        if (n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6){
            printf("\nInvalid Value\n");
        }
        
        switch (n){
        case 1:
            printf("How many individual stocks will you be adding?");
            scanf("%d", contianer);
            addstock(contianer, count, stocks, ID,name, quantities);
            break;
        case 2:
            printf("Note: Once A stock is removed, any stocks proceeding from that stock will be moved accordingly");
            removestock(count, stocks, ID,name, quantities);
            break;
        case 3:
            update(count, ID, quantities);
            break;
        case 4:
            display(ID, name, quantities, count);
            break;
        case 5:
            Save(contianer, count, stocks, ID,name, quantities);
            break;
        case 6:
            removedata();
            break;



        default:
            break;
        }
    } while (n != 6);
}
void removestock(int *count, int stocks[], int ID[], char name[][25], int quantities[]){
    int counter = 0, target, temp, temp2, temp3, verify = 0;
    char temp4[25];
    
    if (*count == 0){
        printf("\nNo Current Stock in this warehouse\n");
    }
    else{
        printf("\nEnter the ID of the stock:");
        scanf("%d", &target);
    }

    for (int i = 0; i < *count; i++){
        if (ID[i] ==  target){
            for (int j = counter-1; j < *count; j++){
                temp = ID[counter];
                ID[counter] = ID[counter+1];
                ID[counter+1] = temp;

                temp2 = stocks[counter];
                stocks[counter] = stocks[counter+1];
                stocks[counter+1] = temp2;

                temp3 = quantities[counter];
                quantities[counter] = quantities[counter+1];
                quantities[counter+1] = temp3;
                
                strcpy(temp4, name[counter]);
                strcpy(name[counter], name[counter+1]);
                strcpy(name[counter+1], temp4);
            }
            (*count)--;
            printf("\nPrinting the newly updated list:");
            for (int j = 0; j < *count; j++)
            {
                printf("\nItem number %d\n", j+1);
                printf("ID:%d\n", ID[j]);
                printf("Name:%s", name[j]);
                printf("Quantity:%d\n", quantities[j]);
            }
            break;
        }
        else
            counter++;
        if (verify != 0){
            printf("\nCouldn't find the ID");
        }
    }
}
void update(int *count,int ID[], int quantities[]){
    int temp;
    if (*count == 0){
        printf("No Current Stock in this warehouse\n");
    }
    else{
        scanf("%d", &temp);
        printf("\nWhat is the ID for this stock:\n");        
    }


    for (int i = 0; i < *count; i++){
        if (temp == ID[i]){
            printf("ID match!\n");
            printf("Current Quantities:%d\n", quantities[i]);
            printf("Enter new value:\n");
            scanf("%d", &quantities[i]);
        }
        else{
            printf("Couldn't find the ID\nSORRY!\n");
            break;
        }
    }
}
void display(int ID[], char name[][25], int quantities[], int *count){
    printf("\nPrinting the current stocks in this warehouse:\n");
    if (*count == 0){
        printf("No Current Stock in this warehouse\n");
    }

    for (int i = 0; i < *count; i++){
        printf("Stock number #%d\n", i+1);
        printf("ID:%d\n", ID[i]);
        printf("name:%s\n", name[i]);
        printf("quantities:%d\n", quantities[i]);
    }
}
void Save(int *contianer, int *count,int stocks[], int ID[], char name[][25], int quantities[]){
    FILE *pF = fopen("Information.txt", "w");

    if (*count == 0){
        printf("No Current Stock in this warehouse\n");
    }
    else
        fprintf(pF, "//Note that this is according to ordered stocks");

    for (int i = 0; i < *count; i++){
        fprintf(pF, "//Stock %d", i);
        fprintf(pF, "%d\n", ID[i]);
        fprintf(pF,"%d\n", *count);
        fprintf(pF,"%s", name[i]);
        fprintf(pF,"%d\n", quantities[i]);
    }
    fclose(pF);
}
void removedata(){
    int inf = 0;
    while (inf != 1){
        printf("Are you sure you want ");
        
    }
    
    
}


int main(){
    int container = 0, count = 0, stocks[25], quantities[25], ID[25];
    char name[25][25];

    printf("WELCOME TO THE WAREHOUSE STOCK CONTROL SYSTEM\n");

    menu(&container, &count,  stocks, ID, name, quantities);

    return 0;
}
