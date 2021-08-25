/* 
gcc stack_linked_list.c -o "stack_linked_list"
./stack_linked_list
*/


#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 

struct stack 
{ 
int data; 
struct stack *next; 
}; 

 

struct stack *top = NULL; 
struct stack *push(struct stack *); 
struct stack *display(struct stack *); 
struct stack *pop(struct stack *); 

void peek(struct stack *); 

 

int main(int argc, char *argv[])  
{ 
    int val, option; 


    printf("Register Number: \t 312320104167\n");
    printf("\n ***** STACK ADT USING LINKED LIST *****"); 
    printf("\n 1. PUSH"); 
    printf("\n 2. POP");
    printf("\n 3. PEEK"); 
    printf("\n 4. DISPLAY"); 
    printf("\n 5. EXIT"); 


    do 
    {
        printf("\n Enter your option: "); 
        scanf("%d", &option); 
        switch(option) 
        { 
            case 1: 
                top = push(top); 
                break;
            case 2: 
                top = pop(top); 
                break; 
            case 3: 
                peek(top); 
                break; 
            case 4: 
                top = display(top); 
                break; 
            case 5: 
                exit(0); 
            default: 
                printf("\n Wrong option. Try again"); 
                break; 
        } 
    }while(option != 5); 


    return 0; 
} 

struct stack *push(struct stack *top) 
{ 
    int val; 
    struct stack *newnode; 

    newnode = (struct stack*)malloc(sizeof(struct stack));  

    printf("\n Enter the number to be pushed on stack: "); 
    scanf("%d", &val);  

    newnode -> data = val; 

    if(top == NULL) 
    { 
        newnode -> next = NULL;  
        top = newnode;  
    } 

    else 
    { 
        newnode -> next = top; 
        top = newnode; 
    }

    return top; 
} 

 

struct stack *display(struct stack *top) 
{ 
    struct stack *ptr; 
    ptr = top; 

    if(top == NULL) 
        printf("\n STACK IS EMPTY"); 

    else 
    { 
        printf(" TOP ->"); 
        while(ptr != NULL) 
        { 
            printf("\t | %d |\n", ptr -> data); 
            ptr = ptr -> next; 
        } 
    } 

    return top; 
} 

 

struct stack *pop(struct stack *top) 
{ 
    struct stack *ptr; 
    ptr = top; 

    if(top == NULL) 
        printf("\n STACK UNDERFLOW"); 

    else 
    { 
        top = top -> next; 
        printf("\n The value being deleted is: %d", ptr -> data); 
        free(ptr); 
    } 

    return top; 
} 

 

void peek(struct stack *top) 
{ 
    if(top==NULL) 
    { 
        printf("\n STACK IS EMPTY"); 
        return; 
    } 

    else 
        printf("\n The value at the top of stack is: %d", top -> data); 
} 