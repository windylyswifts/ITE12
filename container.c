#include <stdio.h>
#include <string.h>

//typedef char user[25];

typedef struct 
{
    char name[25];
    char password[25];
    int id;
}user; //this is the username, this how to use typedef in structs


int main()
{
    //typedef = reserved keyword that gives an existing datatype a "nickname"

   // char user1[25] = "Isiah"; //writing the datatype might be tedious so we can use typedef instead to make it
                              //easy to allocate and more efficient
   // user user1 = "Isiah"; //the typedef char "User" Became a datatype.
    user user1 = {"Isiah", "Password123", 2131}; 
    user user2 = {"saisai", "Pasdasord123", 2183}; 


    printf("%s\n", user1.name);
    printf("%s\n", user1.password);



    return 0;
}