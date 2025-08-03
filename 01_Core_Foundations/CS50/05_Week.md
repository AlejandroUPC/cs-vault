
tags: [weekly-session, c50, week 5] 

---

# Week 4

Data Structures

## 📚 Notes

#### Stacks and Queues
- World is filled w/ abstract data types, ways of structuring information.
- Queues: Line up for dinner, e.g. They have some kind of ordering. E.g printing documents on a printer the documents are set in queue so they are printed in order.
	- FIFO: First in first out, e.g queue in a restaurant, has two ops:
		- enqueue: add to queue
		- dequeue: remove from queue
	
- Imagine a FIFO representation in code, we need to define to keep track of the capacity but also the size because size is the current number of people in the queue because the array people could be filled with garbage values.
```c
const int CAPACITY = 50;

typedef struct
{
	person people[CAPACITY];
	int size;
} queue;
```
- Stack: Last in first out; imagine a pile of pancakes being built, the last one in (on top) will be the first out, or when pilling up clothes, has different ops:
	- push: to add
	- pop: to remove
- The similar class could be used as queue but just named it stack.
#### Jack learns the facts
Small video https://www.youtube.com/watch?v=ItAG3s6KIEI
#### Resizing Arrays
- Arrays, remember they are continuous, how can we resize them?  Maybe we can copy the old array to a brand new location where there is space? The cons is that takes times, to insert a value means that instead of just add it we have to copy everything and then add.
- Maybe we can have a way to have different way that we do not have back to back data on arrays but pointers to the different chunks of an array when we need to make it bigger?
- A new piece of syntax `->` same as a period and a start together (attribute and pointer).
- Starting with this simple example
```c
#include <stdio.h>

int main(void)
{
    int list[3];

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for (int i = 0; i < 3; i ++)
    {
        printf("%i\n", list[i]);
    }
}
```
- How can we just resize just using arrays? We could do that (not scalable)
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int)); // we just create a pointer atm and take a chunk of mem
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // imagine we need to incr here now?
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
	    free(list);
        return 1; // we should clean up here incase this fails or mem leak
    }
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    tmp[3] = 4;
    list = tmp; // ugly rename

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;
}

```
#### realloc
- A slightly cleaner way we can use `realloc` what does if there is free spaces near (no need to move and extend to the right) it will do that (so same mem address), we also remove the copy part
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int)); // we just create a pointer atm and take a chunk of mem
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // imagine we need to incr here now?
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        return 1;
    }

    tmp[3] = 4;
    list = tmp; // ugly rename

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;
}
```
#### Linked Lists
- Linked list doe indeed solve this by storing the values and the direction where the array continues if there is no contiguous mem spots, using linked lists.
![[Pasted image 20250802200935.png]]
- Pros:
	- More efficient mem usage, dont need to be contiguous.
	- Insert time is now constant (any free spot memory and have the previous item point to the address), similar to remove you just remove the referenced node and point to its next.
- Cons:
	- More complexity (and space to store addresses).
- Each item in a linked list is a node that keeps adding at the begining using this code
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next; // address to the next node
} node;

int main(void)
{
    node *list = NULL;
    for (int i = 0; i < 3; i++)
    {

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = i;
        n->next = list; // list contains the valious of the previous node
        list = n;
    }
}
```
![[Pasted image 20250802202450.png]]
- This is a singly linked list where you can just move one direction, feels like its backwards of the order.
- We could print the data using a pointer `ptr`
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next; // address to the next node
} node;

int main(void)
{
    node *list = NULL;
    for (int i = 0; i < 3; i++)
    {

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = i;
        n->next = list; // list contains the valious of the previous node
        list = n;
    }

    node *ptr = list; // comes out as first item (3) after the loop
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
}

```
- this prints
```plaintext
2
1
0
```
- Lets review the running times for LL:
	- search is `o(n)`
	- add is `o(1)`
	- removing is `o(n)`
- Can we append instead of prepend (add items at the end?) we might lose `o(1)` then.
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next; // address to the next node
} node;

int main(void)
{
    node *list = NULL;
    for (int i = 0; i < 3; i++)
    {

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1; // should we free mem always when panic
        }
        n->number = i;
        n->next = NULL;

        if (list == NULL) // special case list empty
        {
            list = n;
        }
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL) //last item? then we add
                {
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }
    return 0;
}
```
- Again, the complexity
	- searches are `o(n)`
	- Appends are `o(n)` (solvable by having a variable that points at the last address of the list)
- We should also free the entire list also, slightly more complex, carefull when we free memory
```c
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = >next;
    }
```
- Another implementation of LL where we just want sorted order, we might have to add items in between the list (another tmp?) (code copied)
```c
// Frees memory in cases of error too

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

void unload(node *list);

int main(void)
{
    // Memory for numbers
    node *list = NULL;

    // Build list
    for (int i = 0; i < 3; i++)
    {
        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload(list);
            return 1;
        }
        n->number = get_int("Number: ");
        n->next = NULL;

        // If list is empty
        if (list == NULL)
        {
            list = n;
        }

        // If number belongs at beginning of list
        else if (n->number < list->number)
        {
            n->next = list;
            list = n; 
        }

        // If number belongs later in list
        else
        {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }

                // If in middle of list
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    unload(list);
    return 0;
}

void unload(node *list)
{
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
```
#### Trees
- Like a family tree , start at the root and has children.
- Can be understood as a bidimensional data structure.
- Used in binary search tree, (e.g you cant on LL cuz they are strongly linked).
- We can see this representation of an array and the middles, first half split in yellow, second in green and finally in red; we can do binary search btu as an array its hard to resize and grow
![[Pasted image 20250802205331.png]]
- This can also be represented as a tree if we used some pointers
![[Pasted image 20250802205508.png]]
- The downside is that its more memory, each node has two pointers.
- Every node left child is smaller than its root, and the right is bigger.
- Writting a function to find a value in a binary tree could be as easy as
![[Pasted image 20250802205949.png]]
- Inserting and removing data can be difficult (you need to rebalance the tree), e.g imagine an unbalanced tree (everything falls into a branch); eg if you add  1,2,3,4,5 into a tree it goes all toe the right node for each node, a linked list pretty much.
- The notation
	- Insert, search and remove could be `o(n)`, can stay on `o(log n)` if we handle rebalancing.
#### Dictionaries
- Two column data structure with access `o(1)`, uses keys and values.  You use a key to get a value.
- It uses hashing.
#### Hashing and Hash Tables
- Function that given an input produces always the same output.
- It can be that two different inputs provide the same output (dangerous, called collision).
- You can imagine buckets that have the letters of the alphabet to store names, the key is the letter and the value is an linked list of the names (adds an extra operation then on insert items in dict).
	- The hash function could be: key = first_letter(name)
	- And after having the hash we do get value on key -> add name
- The more complex the hash function the lesser the risk of collision.
- The dictionary could be an array of pointers.
#### Tries
- Data structure for retrieving data, its a tree of arrays.
- Should give us true constant time, its an array of pointers that points to another node for the second letter and so on until the nest letter.
- If we wanted to insert TOAD
![[Pasted image 20250802212110.png]]
- Each of this array, is an array of 26 pointers; a lot of arrays but the time of mount required to look or insert a name it does not depend on how many people exists already.
- Insert, delete or search depends on the length of the person name, its constant `o(1)`.
- The cost is memory usage.