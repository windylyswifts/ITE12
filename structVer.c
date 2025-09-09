#include <stdio.h>

int amount;

menu();
menu(){
    int choice = 0;
    do{
        printf("\nWelcome to the Movie Ticket booking System!!\n");
        printf("\n1.Book tickets\n");
        printf("\n2.cancel bookings\n");
        printf("\n3.display booking details\n");
        printf("\n4.\n");
    } while (choice !=4);
    
}
typedef struct{
    int count,tickets;
}unit; //This will be what will be in stored for the rest of the system

int main(){
    unit movies[amount];
    menu();

    return 0;
}