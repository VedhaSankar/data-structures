/* 
gcc list_adt_using_array.c -o "list_adt_using_array"
./list_adt_using_array
*/

#include <stdio.h> 

#include <stdlib.h> 

#define MAX 10 

 

int list[MAX]; 

int n=0, i, val, pos, flag=0; 

void create(void); 

void append(void); 

void insert(void); 

void delete_element(void); 

void search(void); 

void display(void); 

 

int main() 

{ 

int option; 

printf("Register Number: \t \n");

printf("\n\n ***** MAIN MENU *****"); 

printf("\n 1. Create the list"); 

printf("\n 2. Append an element at the end of list"); 

printf("\n 3. Insert an element in the middle of the list"); 

printf("\n 4. Delete an element"); 

printf("\n 5. Search an element"); 

printf("\n 6. Display the list"); 

printf("\n 7. EXIT"); 

do 

{ 

printf("\n Enter your option : "); 

scanf("%d", &option); 

switch(option) 

{ 

case 1: 

if (n==0) 

create(); 

else 

printf("\n List already exists"); 

break; 

case 2: 

if(n<MAX)  

append(); 

else 

printf("\n Overflow"); 

break; 

case 3: 

if(n<MAX) 

insert(); 

else 

printf("\n Overflow"); 

break; 

case 4: 

if (n==0) 

printf("\n Underflow"); 

else 

delete_element(); 

break; 

case 5: 

if (n==0) 

printf("\n The list is empty"); 

else 

search(); 

break; 

case 6: 

display(); 

break; 

case 7: 

exit(0); 

default: 

printf("\n Wrong option. Try again"); 

break;	 

} 

}while(option != 7); 

return 0; 

} 

 

void create() 

{ 

printf("\n Enter the number of elements to create the list: "); 

scanf("%d", &n); 

if (n<=MAX) 

{	 

for(i=0;i<n;i++) 

{ 

printf("\n Enter the  Element[%d]: ",i); 

scanf("%d", &list[i]); 

}	 

} 

else 

{ 

n=0; 

printf("\n Number of elements exceeds MAX. Try Again"); 

} 

} 

 

void append() 

{ 

printf("\n Enter the element to be appended: "); 

        scanf("%d", &val); 

list[n]=val; 

n++; 

} 

 

void insert() 

{ 

 	printf("\n Enter the element to be inserted: "); 

        scanf("%d", &val); 

 	printf("\n Enter the index position: "); 

        scanf("%d", &pos); 

if(pos < 0 || pos > n-1) 

{ 

printf("\n Illegal index position"); 

return; 

} 

i=n-1; 

while(i>=pos) 

{ 

list[i+1] = list[i]; 

i--; 

} 

n++; 

list[pos]=val; 

} 

 

void delete_element() 

{ 

printf("\n Enter the index position: "); 

scanf("%d", &pos); 

if(pos < 0 || pos > n-1) 

{ 

printf("\n Illegal index position"); 

return; 

} 

if(pos==n) 

n--; 

else 

{ 

i=pos; 

while(i<=n-1) 

{ 

list[i]=list[i+1]; 

i++; 

} 

n--; 

} 

} 

void search() 

{ 

printf("\n Enter the element to be searched: "); 

scanf("%d", &val); 

for(i=0;i<n;i++) 

{ 

if(list[i]==val) 

{ 

flag=1; 

break; 

} 

} 

if(flag ==1) 

printf("\n The element %d is found at index position %d",val,i); 

    	else 

printf("\n The element is not found in the list");	 

} 

 

void display() 

{ 

if(n==0) 

printf("\n The list is empty"); 

else 

{ 

for (i=0;i<n;i++) 

printf(" %d\t", list[i]); 

} 

} 