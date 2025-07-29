
tags: [weekly-session, c50, week 3] 

---

# Week 3

Algorithms

## 📚 Notes
- Recalling phonebook as algorithm when there is an order, its quite easy to find an object (e.g open right in the middle if your letter is left go that half etc etc each step reduces space to half).
- Also we spoke about complexity (big O notation).
- We spoke about some algorithms to find someone in the phonebook:
	- Go page by page as n (increasing number pages increases complexity)
	- Go page as pairs (potential error if you sandwich the name you find between a two page iteration, then we can go back one), was n/2.
	- Binary search, split by half and pick the correct half recursively as log2n
	  ![[Pasted image 20250729002711.png]]
	  - Most of the algorithms is just searching and/or finding.
	  - Hardware is somewhat also relevant and its memory, again if we imagine memory as a grid we have to remember an array is a continuous in memory cells (very relevant).
	  - E.g an example where we assume computer can only look at one cell at a time and has to find a number in such a memory grid:
	    
	    ```plaintext

	    | 1   | 5   | 10  | 20  | 50  | 100 | 500 |
		| --- | --- | --- | --- | --- | --- | --- |
	    | 0   | 1   | 2   | 3   | 4   | 5   | 6   |
		```
	 - If we want to find `50` going one by one is n, we do need 5 steps `[1,5,10,20,50]`.
	 - If we do the twice jump then we need `4` steps, we see `[5,20,100,50]` because the extra step we need to go back.
	 - Binary search would be `3` steps, where we go `[20,100,50]`.
	 - Difference might not seem big because the array is small.
	 - Running time then its `O(n)`, `O(n/2)` and `O(log2n)`using big O notation, denominators such as constants can be removed so `O(n/2)` and the base 2 of log, we care about big changes such as `O(n)` vs `O(logn)`.
	 - There is a common of run times:
		 - `O(n^2)`
		 - `O(nlogn)`
		 - `O(n)` : Linear search, assuming for the array cases it will be as complex as making it to the last item (maybe you're luck and hit first, we check worse).
		 - `O(logn)` : Binary search
		 - `O(1)` : Direct access, fastest
	 - For best case scenario, instead of worse we use omega notation:
		 - `Ω(n^2)`: Lower bound is 1
		 - `Ω(nlogn)`
		 - `Ω(n)` :  Same as n^2
		 - `Ω(logn)` : Binary search
		 - `Ω(1)` : Direct access, fastest
	 - Theta Θ is used when both omega and big O are the same.
	 - Ugly code for linear search for unordered
		```c
#import <cs50.h>
#import <stdio.h>

int main(void)
{
    int numbers[] = {20, 500, 100, 5, 100, 1, 50};
    int n = get_int("Number: ");
    int steps = 0;
    for (int i = 0, l = sizeof(numbers)/sizeof(numbers[0]); i < l; i++)
    {
        steps += 1;
        if (numbers[i] == n)
        {
            printf("Found value %i at position %i after %i steps!\n", n, i, steps);
            return 0;
        }

    }
    printf("Number %i not in array!\n", n);
}
		```


	- For strings this would give issues when you compare strings using `==` would not work because of its variable length, there is a built in in `string.h` or `cs50.h` there is `strcmp` to compare the strings.
	- Phonebook example
		```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Bar", "Foo", "Xyz"}; //force sorted manually
    string numbers[] = {"1", "2", "3"}; //also as strings to match example
    string name = get_string("Enter name: ");
    int steps = 0;
    for (int i=0, l=sizeof(names)/sizeof(names[0]); i<l; i ++){
        steps += 1;

        if (strcmp(name, names[i]) == 0)
        {
            printf("Found %s w/ phone %s in position %i after %i steps\n", name, numbers[i], i, steps);
            return 0;
        }
    }
    printf("Could not find %s\n", name);
}
		```

-  Some design flaws still such as casing, arrays are "unsynced" (better data structure), maybe we can create Person struct w/ name and phone (better way to init classes??)
	```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    person people[3];

    people[0].name = "Bar";
    people[0].number = "1";
    people[1].name = "Foo";
    people[1].number = "2";
    people[2].name = "Xyz";
    people[2].number = "3";

    string name = get_string("Enter name: ");
    int steps = 0;
    for (int i=0; i<3; i ++){
        steps += 1;
        if (strcmp(name, people[i].name) == 0)
        {
            printf("Found %s w/ phone %s in position %i after %i steps\n", name, people[i].number, i, steps);
            return 0;
        }
    }
    printf("Could not find %s after %i steps.\n", name, steps);
}
	```
	- Sorting, needed for most of the searching algorithms to be effective, plenty of ways to sort stuff like searching.
	- Plenty of ways, e.g go number by number, find min and move to start, swap the rest, and problem becomes smaller( one item has been ordered and can be removed from space). You could also this in pair of numbers, compare index `[0,1]` and order `[1,2]` check and order, etc....
	- Selection sort was the first case where we go 1 by 1 and reduce the space everytime we find the smallest item, not very efficient:
```plaintext
(n-1) first time recursively
(n-1)+(n-2)+ ... + 1
it ends up
n^2/2 - n/2 so its like O(n^2) worst case scenario.
If all its sorted we still need to do same steps to validate.
```
- 
	- Bubble sort is slightly better that was the window of 2 to compare, is it faster?
```plaintext
Repeat n-1 times
	for i from 0 to n-2
		if numbers[i] and numbers[i+1] out of order
			swap
First loop takes n-1 and second loop is (n-1) too, two nested loops.
(n-1)*(n-1) -> n^2 - 2n + 1 so n^2 too, not really good.

We can add a check if we do the first loop and we did not swap at all like

Repeat n-1 times
	for i from 0 to n-2
		if numbers[i] and numbers[i+1] out of order
			swap
	if no swaps:
		quit
Best case scenario lower bound in omega would be omega(n)
```

### Recursion
- binary search can be easily implemented, its the same logic just reducing the size of the array , we need a base case when the algorithm ends and recursive cases.
- Example of a pyramid, we build a layer starting from n and do n-1 until n == 1, got screwed as my draw(n-1) was at the end of pyramid order, function order call is relevant
	```c
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int h = get_int("Height of the pyramid: \n");
    draw(h);
}

void draw(int n)
{
    if (n <= 0)
    {
        return;
    }
    draw(n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");

}
		```


## Back to ordering

- merge sort is faster to order, uses recursion (should be `O(n)`) but uses more space, one to split the arrays in n/m and then the new array of size n
  ```plaintext
	if only one number
		quit
	else
		sort left half
		sort right half
		merge sorted halfs
	```
- Basically order smaller pieces and compare item per item (at index level) and order in the newly merged array.
- Visualization of the steps
  ![[Pasted image 20250729021713.png]]
- We divided each side 3 times ( 8->4, 4->2, 2->1) before we could rearrange to sort, so the merge step was n, so its `O(nlogn)` , lower bound would also be the same.
 