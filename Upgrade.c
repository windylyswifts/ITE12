#include <stdio.h>

int main(){

    FILE *pF = fopen("test.txt", "w");//the second argument is the modes which are, 'w' for write, or writing or from what i understand its like 
                                      //creating. 'a' is for append. 'r' for read. 
                                      //if we want to add a file but not in the same folder then we can use an absolute file path or relative file path
    //for example:
    //FILE *pF = fopen("C:\\Users\\t495s\\Documents\\Languages\\Cjourney\\test.txt", "w"); //make sure to double slash it to work.

    fprintf(pF, "Hello World!");

    fclose(pF);

    //deleting files using the data type remove("the file that you want to remove") and if it was succesfully its always 0 just like how
    //are main function works if it is succesful then its 0;
    /*
    if(remove("test.txt") == 0){
        printf("that file was removed");
    }
    else(
        printf("didin't work");
    )
    */
    return 0;
}