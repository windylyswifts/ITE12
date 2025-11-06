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