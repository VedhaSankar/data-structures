/* 
gcc queue.c -o "queue"
./queue
*/

#include <stdio.h> 

#include <stdlib.h> 

#define MAX 10  

 

int queue[MAX]; 

int front = -1, rear = -1; 

void insert(void); 

int delete_element(void); 

int peek(void); 

void display(void); 

 

int main() 

{ 
printf("Register Number: \t 312320104\n");

int option, val; 

printf("\n\n ***** MAIN MENU *****"); 

printf("\n1. Insertion"); 

printf("\n2. Deletion"); 

printf("\n3. Peek"); 

printf("\n4. Display the queue"); 

printf("\n5. Exit"); 

do 

{ 

printf("\nEnter your option : "); 

scanf("%d", &option); 

switch(option) 

{ 

case 1: 

insert(); 

break; 

case 2: 

val = delete_element(); 

if (val != -1) 

printf("\nThe number deleted is : %d", val); 

break; 

case 3: 

val = peek(); 

if (val != -1) 

printf("\nThe first value in queue is : %d", val); 

break; 

case 4: 

display(); 

break; 

case 5: 

exit(0); 

default: 

printf("\nWrong option. Try again"); 

break; 

} 

}while(option != 5); 

return 0; 

} 

 

void insert() 

{ 

int num; 

if(rear == MAX-1) 

{ 

printf("\nOVERFLOW"); 

return; 

} 

else if(front == -1 && rear == -1) 

front = rear = 0; 

else 

rear++; 

printf("\nEnter the number to be inserted in the queue : "); 

        scanf("%d", &num); 

queue[rear] = num; 

} 

 

int delete_element() 

{ 

int val; 

if(front == -1 || front>rear) 

{ 

printf("\nUNDERFLOW"); 

return -1; 

} 

else 

{ 

val = queue[front]; 

front++; 

if(front > rear) 

front = rear = -1; 

return val; 

} 

} 

 

int peek() 

{ 

if(front==-1 || front>rear) 

{ 

printf("\nQUEUE IS EMPTY"); 

return -1; 

} 

else 

{ 

return queue[front]; 

} 

} 

 

void display() 

{ 

int i; 

printf("\n"); 

if(front == -1 || front > rear) 

printf("\nQUEUE IS EMPTY"); 

else 

{ 

for(i = front;i <= rear;i++) 

printf("\t %d", queue[i]); 

} 

} 