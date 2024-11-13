/**
 * https://people.duke.edu/~tkb13/courses/ece250-2018su/slides/02-c.pdf
 * https://people.duke.edu/~tkb13/courses/ece250-2018su/recitations/recitation02-C.pdf
 * https://web.stanford.edu/class/archive/cs/cs107/cs107.1222/lectures/07/Lecture07.pdf
 * 
 * The Heap and the Stack.
 * 
 * Author: Renet
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    /* You can find the address of ANY variable with the address operator "&" */
    /* The other way around, you can find the value of any address using the dereference operator "*" */
    auto int x = 5; //By default, variables declared this way allocate automatically at the higher part of the memory, or the "stack". The "auto" keyword can (and usually is) ommited.
    auto int y = 6;
    printf("value of x = %d\n",x); // Print the value of v
    printf("address of x = %p\n",(void *)&x); //Print the address of v
    printf("value of y = %d\n",y); // Print the value of y
    printf("address of y = %p\n",(void *)&y); //Print the address of y
    printf("Memory distance between x and y: %ld bytes.\n",((char*)&x-(char*)&y)); //Using char* cast to override pointer arithmetic.
    printf("----------------------\n\n");
    /**
     * As you can see, addresses of variables allocated in the stack usually grow with 
     * decreasing values. Also notice that because we allocated the two variables consecutively,
     * they are contiguous in memory.
    */

    /* Now, lets allocate in the lower part of the memory (heap) ...*/
    int* a = malloc(1 * sizeof(int)); //Alocate 1 int (usually 4 bytes)
    int* b = malloc(1 * sizeof(int));
    int* c = malloc(1 * sizeof(int));
    /* ... And an array*/
    const int ARRAY_SIZE = 4;
    int* myArray = malloc(ARRAY_SIZE * sizeof(int));
    /**
     * Before proceeding, check if malloc returned non-NULL values (a NULL value would mean the OS didn't borrowed the memory we asked for.)
     */
    if(a==NULL || b==NULL || c==NULL || myArray==NULL) return EXIT_FAILURE;

    printf("value of a = %d\n", *a); // Print the value of a (UNKNOWN!)
    printf("address of a = %p\n",(void *)a); //Print the address of a
    printf("value of b = %d\n", *b); // Print the value of b (UNKNOWN!)
    printf("address of b = %p\n",(void *)b); //Print the address of b
    printf("Memory distance between a and b: %ld bytes.\n",((char*)a-(char*)b)); //Substract address of b to address of a.
    printf("value of c = %d\n",*c); // Print the value of c (UNKNOWN!)
    printf("address of c = %p\n",(void *)c); //Print the address of c

    /**
     * As you can see, variables in the heap usually grow with increasing address' value.
     * Maybe you notice that the pieces of memory in the heap -although they were allocated
     * consecutively- are not contiguous, instead, there is a gap between them (maybe of 32 
     * bytes.) What could be the reason? Hint: Memory alignment and heap management overhead...
     * 
     */

    /*Now lets allocate an array, see how the elements of the array are not separated by padding, instead, they are contiguous*/
    printf("address of myArray = %p\n",(void *)myArray); //Print the address of myArray
    printf("Memory distance between c and myArray: %ld bytes.\n",((char*)c-(char*)myArray)); //Substract address of myArray to address of c.
    printf("----------------------\n\n");
    /**
     * SCARY LINES! Proceed with care.
     * We can also peek onto another piece of memory we didn't allocate. If we are _lucky_, the OS will prevent us from performing that operation.
     * Maybe, in an embedded context, the supplier of some hardware tells you that at a very specific location of memory, an important key
     * is stored. Then peeking at memory out of our program may make sense.
     * 
    */
    // const int* MY_ADDRESS = 0x5598f9636ddd; //Why not trying to access any arbitrary memory location?
    // printf("value in MY_ADDRESS = %d\n", *MY_ADDRESS); // Feel free to use any address you can think of -and likely break the program itself-
    
    /**
     * Free all the non-auto allocated memory before the program ends!
     * (Modern OS will try to perform this deallocation if not done by the program itself, but reaching the end of a program with no memory left on the heap is 
     * a good practice.)
     */
    free(a);
    free(b);
    free(c);
    free(myArray);
    return EXIT_SUCCESS;
}