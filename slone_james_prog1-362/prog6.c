/*Author: James Slone
 * Course: CSC 362
 * Date: 4/27/2016
 * Programming Assignment: #6 main.c
 * Instructor: Richard Fox
 * This program we are implementing a chained hashing. There is 2 arrays of linked
 * list - one has unsorted linked lists and the other has sorted linked lists.
 * There will be 1000 random ints 0 to int max (32767) generated and then hashed by
 * array length.  This will determine what index in the arrays it should go to.
 * Once at the index in the arrays it will insert the random number into the linked
 * list. The insert will be either at the front or sorted until it arrives at the correct
 * spot. Both arrays will have counters to track the average insert time.
 * Next it will search the linked lists for a random number 0 to 999, this will 
 * continue for 5000 iterations. At the end of each cycle it will return the location
 * where the random number was found. Each cycle of searching will increment the counters for both arrays.
 * This will be used to calculate the average search time for each list. It will then
 * search through one of the arrays to find the shortest and longest linked list.
 * A summary will be printed to the console - telling the user the array size,
 * shortest & longest linked list, insert average for unordered and ordered linked list,
 * search average for unordered and ordered linked list, and general average for
 * unordered and ordered linked list. It will then deallocate all heap memory for each array.
 */

//for I/O
#include <stdio.h>
//for srand(time)
#include <time.h>
//for random # generator, malloc and free
#include <stdlib.h>
//for INT_MAX
#include <limits.h>

//Constants defined for certain variables
//array size
#define LENGTH 25
//search length for values
#define SEARCH_LENGTH 5000
//random values length
#define VALUE_SIZE 1000

//defines a node in a linked list
struct node {
    //pointer to the next node
    struct node *next;
    //the datum
    int data;
};

//list struct which will store a pointer to the first element of a linked list
//and the list’s current number of items stored there (an int).
struct list {
    //pointer to the first node in the linked list
    struct node *first;
    //size of the linked list
    int size;
};


//Prototypes
//random values recieves an int array
void randomValues(int []);

//inserts revinew datum at the front of the linked list
void insert(struct list *, int, int *);

//sorted insert receives front pointer, new datum to insert in proper location, counter
void sortedInsert(struct list *, int , int *);

//search recieves the current linked list, datum to search for, and counter
int search(struct list *, int, int *);

//sorted search recieves the current linked list, datum to search for, and counter
int sortedSearch(struct list *, int, int *);

//find size recieves the array holding the linked list and variable for storing smallest & largest linked list size
void findSize(struct list *[], int *, int *);

//print summary recieves 4 counters, smalllest & largest linked list size
void printSummary(int, int, int, int, int, int);

//destroy revieces an array holding the linked lists
void destroy(struct list *[]);

int main(int argc, const char * argv[]) {
    //initializes the size of the array to 1000
    int values[VALUE_SIZE];
    //values array is passed in and returned via reference
    randomValues(values);
    
    //initializes 2 arrays of struct list
    struct list *lists1[LENGTH];
    struct list *lists2[LENGTH];
    
    //counters used for calculating averages
    int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;
    
    //sets smallest to max int
    int smallest = INT_MAX;
    
    //sets largest to
    int longest = -1;
    
    //allocating nodes from heap for each index of the arrays
    for(int i = 0; i < LENGTH; i++) {
        lists1[i] = (struct list *)malloc(sizeof(struct list));
        lists2[i] = (struct list *)malloc(sizeof(struct list));
    }
    
    //inserts values into the linked lists
    for(int i = 0; i < VALUE_SIZE; i++) {
        //hashs the value to be used as an index
        int index = values[i]%LENGTH;
        
        //inserts the value into the linked list at the front of it
        insert(lists1[index], values[i], &counter1);
        
        //inserts the value into the linked list but sorted
        sortedInsert(lists2[index], values[i], &counter2);
    }
    
    // seed random number generator
    srand(time(NULL));
    //searches the linked lists for the said value
    for(int i = 0; i < SEARCH_LENGTH; i++) {
        //randomly generates an int from 0 to 999
        int randomNumber = rand() % 1000;
        
        //hashs the value to be used as an index
        int index = values[randomNumber]%LENGTH;
        
        //searches the linked list for the random number that was generated
        search(lists1[index], values[randomNumber], &counter3);
        
        //searches the sorted linked list for the random number that was generated
        sortedSearch(lists2[index], values[randomNumber], &counter4);
    }
    
    //finds smallest and largests size for linked lists
    findSize(lists1, &smallest, &longest);
    
    //prints summary to console
    printSummary(counter1, counter2, counter3, counter4, smallest, longest);
    
    //destroys every linked lists in the arrays
    destroy(lists1);
    destroy(lists2);
    
    return 0;
}

//generates random values
void randomValues(int values[]) {
    // seed random number generator
    srand(time(NULL));
    for(int i = 0; i < VALUE_SIZE; i++) {
        //random values 0 to 32767
        int r = rand() % 32768;
        values[i] = r;
    }
}

// nsert new value x into a node at the front of the list
void insert(struct list *list, int x, int *counter) {
    //allocate a node from heap
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    
    //add x as data to new node
    temp -> data = x;
    
    //set new node's next pointer to point at current front of list
    temp -> next = list -> first;
    
    //sets the lists front pointer to point at the new node
    list -> first = temp;
    
    //increments the current linked list size by 1
    list -> size++;
    
    //increments the average counter by 1
    *counter = *counter + 1;
}


//sorts the new node into the correct spot in the list
void sortedInsert(struct list *list, int x, int *counter) {
    // temp will point to new node, current and previous used to traverse list
    struct node *temp, *previous,  *current;
    
    //allocate a node from heap
    temp = (struct node *)malloc(sizeof(struct node));
    
    //add x as data to new node
    temp -> data = x;
    
    //and it will be the current last node, so make next NULL
    temp -> next = NULL;
    
    //check if first in the list is null
    if(list -> first == NULL) {
        //sets the lists front pointer to point at the new node
        list -> first = temp;
        
        //increments the current linked list size by 1
        list -> size++;
        
        //increments the average counter by 1
        *counter = *counter + 1;
    }//checks if datum being inserted is less than current first datum
    else if(x < list -> first -> data) {
        //let new node point at rest of list
        temp -> next = list -> first;
        
        //increments the current linked list size by 1
        list -> size++;
        
        //increments the average counter by 1
        *counter = *counter + 1;
    }
    else {
        //initialize our two pointers to work down the list, current always
        //pointing at current node while previous points at its predecessor
        previous = NULL;
        current = list -> first;
        
        // traverse list until we either reach the end of find the right location
        while(current != NULL && current -> data <= temp -> data) {
            previous = current;            // previous always points at prior node
            current = current->next;       // current points at node we are inspecting
            
            //increments the average counter by 1
            *counter = *counter + 1;
        }
        previous -> next = temp;      // attach new node to list by having previous point at it
        temp -> next = current;       // and reattach rest of list to temp's next field
        
        //increments the current linked list size by 1
        list -> size++;
    }
}

//searches the unsorted list and returns the location in the linked list it was found at
int search(struct list *list, int random, int *counter) {
    //initialize location count
    int location = 0;
    
    //search will be used to traverse list and its initialized to point at the front of the list
    struct node *search = list -> first;
   
    //loops until search node is null
    while (search != NULL) {
        //increments the average counter by 1
        *counter = *counter + 1;
        
        //returns location if search data is equal to random
        if(search -> data == random) {
            return location;
        }
        //search points at node we are inspecting
        search = search -> next;
        //increments the location by 1
        location++;
    }
    return -1; //returns -1 if location not found
}

//searches the sorted list and returns the location in the linked list it was found at
int sortedSearch(struct list *list, int random, int *counter) {
    //initialize location count
    int location = 0;
    
    //search will be used to traverse list and its initialized to point at the front of the list
    struct node *search = list -> first;
  
    //traverse list until we either reach the end or find the right location
    while (search != NULL && search -> data < random) {
        //increments the average counter by 1
        *counter = *counter + 1;
        
        //when search data is equal to random return the location
        if (search -> data == random) {
            return location;
        }
        //search points at node we are inspecting
        search = search -> next;
        //increments location by 1
        location++;
    }
    return -1; //returns -1 if location not found
}

//recieves an array of linked lists, shortest and longest variables
//loops through the length of the array and finds shortest and longest linked lists in the said array
void findSize(struct list *list[], int *shortest, int *longest) {
    for (int i = 0; i < LENGTH; i++) {
        //sets shortest to current size if it was smaller than the last list
        if(list[i]->size < *shortest) {
            *shortest = list[i]->size;
        }
        //sets longest to current size if it was longer than the last list
        if(list[i]->size > *longest) {
            *longest = list[i]->size;
        }
    }
}

//prints out to the console the shortest & longest linked lists and a bunch of averages
void printSummary(int count1, int count2, int count3, int count4, int smallest, int largest) {
    printf("Array Size: %d\n", LENGTH);
    printf("Shortest linked list: %3.2d\n", smallest);
    printf("Longest linked list: %4.2d\n", largest);
    printf("Unordered linked list insert average:  %2d\n", (count1/VALUE_SIZE));
    printf("Ordered linked list insert average: %5d\n", (count2/VALUE_SIZE));
    printf("Unordered linked list search average: %3.2d\n", (count3/SEARCH_LENGTH));
    printf("Ordered linked list search average: %5d\n", (count4/SEARCH_LENGTH));
    printf("Average for unordered list: %3.2d\n", ((count1 + count3)/6000));
    printf("Average for ordered list: %5d\n", ((count2 + count4)/6000));
}

//deallocate all heap memory
void destroy(struct list *list[]) {
    struct node *temp = NULL; //need a temp pointer as one pointer will point to next
    struct node *f = NULL;    //need a front pointer
    
    for (int i = 0; i < LENGTH; i++) {
        list[i] -> size = 0;    //sets linked list size to 0
        f = list[i] -> first;   //sets first node to f node
        temp = f;
        while(f!=NULL) {        // while we still have list nodes to deallocate
            f = f->next;        // f now points to the next node in the list
            free(temp);         // so we can deallocate the current node
            temp = f;
        }
    }
}