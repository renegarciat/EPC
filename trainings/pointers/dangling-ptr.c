#include <stdio.h>
#include <stdlib.h>

void print_10_values(void);
int* create_ptr();
char *create_string(char ch, int num);
int main() {
    // Declare a pointer to an integer
    int* p;
 
    // Create a local variable
    int x = 15;
 
    // Make the pointer point to the local variable
    p = &x;
 
    // Print the value of x and the address of x
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);
 
    // Print the value of the pointer p
    printf("Value of p: %p\n", (void*)p);
 
    // Print the value pointed to by p
    printf("Value pointed to by p: %d\n", *p);
 
    // Function for creating an array
    p = create_ptr(); //Here the pointer p is no longer reliable, it is dangling. Nonetheless, no one has written on the stack (yet).

    // Print the value of the pointer p
    printf("Value of p: %p\n", (void*)p);
    printf("Value pointed to by p: %d\n", *p); 

    //Create an array in the stack, see how it potentially impacts to pointer p
    print_10_values();

    // Print the value of the pointer p
    printf("Value of p: %p\n", (void*)p);
    // Print the value pointed to by p
    printf("Value pointed to by p: %d\n", *p); // Is here what you were expecting?


    printf("-----------------------------\n");
    char *str = create_string('a', 4);
    printf("%s\n", str); // Attempt to print the created string. Do we get an error? Why?
    return EXIT_SUCCESS;
}


void print_10_values(void){
    int zeros[10];
    for (size_t i = 0; i < 10; i++)
    {
        zeros[i] = i+1;
        printf("value %d stored in %p\n",zeros[i],(void *)&zeros[i]);
    }
    return;
}

int* create_ptr(){
    int a = 25;
    int* ptr_a= &a;
    return ptr_a;
}

/**
 * Create a string of ch times num
 */
char *create_string(char ch, int num) {
char new_str[num + 1];
for (int i = 0; i < num; i++) {
new_str[i] = ch;
}
new_str[num] = '\0';
printf("%s\n", new_str); // Print the created string.
return new_str;
}