/* 
gcc implementation_of_stack_adt_using_array.c -o "implementation_of_stack_adt_using_array"
./implementation_of_stack_adt_using_array
*/

#include<stdio.h>
#define MAX 5

int top = -1;
int arr[MAX];

void push(int arr[],int val){

    if (top == (MAX-1)){
        printf("\nStack Overflow");
    }
    else{
        ++top;
        arr[top] = val;
    }
    
}

int pop(int st[]){
    int val;
    if(top == -1)
    {
        printf("\nStack underflow");
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        return val;
    }
}

int peek(int arr[])

{
    if(top == -1){
        printf("\nStack is empty");
        return -1;
        }
        else
            return (arr[top]);
}

void display(int arr[])
{
    int i;
    if(top == -1)
    printf("\nStack is empty");
    else
    {
        for(i=top;i>=0;i--)
        printf("\n %d",arr[i]);  
        printf("\n");
    }
}

int main()

{
    printf("Register Number:  \n");


    printf("\n---Menu---\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");

    int option, val;
    do
    {

        printf("\nEnter option: ");

        scanf("%d", &option);

        switch(option)
        {

            case 1:

                printf("\nEnter the value to be pushed: ");
                scanf("%d", &val);
                push(arr, val);
                break;

            case 2:

                val = pop(arr);
                if (val != -1)
                    printf("\n%d has been popped\n", val);
                break;

            case 3:

                printf("\nThe top value is: %d\n", peek(arr));
                break;

            case 4:
                display(arr);
                break;

            case 5:

                printf("\nExiting\n");
                break;
        }
    } while (option!=5);

    return 0;
}

// peek returns top value