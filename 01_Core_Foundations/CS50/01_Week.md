
tags: [weekly-session, c50, week 1] 

---

# Week 1

C

## 📚 Notes

- Notes:
  - Code has to ultimately convert to 0s and 1s (machine code), we write source code.
  - We write a very simple hello.c, in the snippet, if we inspect the output file `./hello`
    its a weird snippet.
    ![[Pasted image 20250406164149.png]]
  - arguments -> function -> side effects.
  - Top of the file there is this `#include <stdio.h>` is a header file, ends with h also, are libraries that contain functionalities declared already. If you remove it wont compile.
  - Libraries are documented usually in man pages, for this course manual.cs50.io  or cli `main printf`.
  - Now the function must not always have side effects (like print) but also return data arguments ->  function -> return value
  - Taking some user input
```c
#include <cs50.h>
#include <stdio.h>

  

int main(void)

{

	string answer = get_string("whats your name? ");
	printf("Hey %s \n", answer);

}
```
- To print we use placeholders e.g for a string `%s` but there are others such as `%i` for integer.
- Some linux commands.
- A conditional flow
```c
#include <stdio.h>
#include <cs50.h>

int main(void)
{

	int x = get_int("Pick your first number: ");
	int y = get_int("Pick your second number: ");

	if (x < y) {
		printf("The number %d is smaller than %d\n", x, y);
		return 0;
	}
	else if (x > y) {
		printf("The number %d is smaller than %d\n", y, x);
		return 0;
	}
		printf("The nubers are %d and %d are equal\n", x, y); 
}
// this can also be done with if else if and else for equality avoiding the returns
```
  
- How to increment variables in place
- Some cool diagram on how to organize code w/ nodes & arrows.
- Third program agree.c
	- First version quite shitty, compare answer to literals y and n already, does not work.
	  
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree?\n");
    if (c == 'y' || c == 'Y') {
        printf("Agreed\n");
    }
    else if (c == 'n' || c == 'N') {
    printf("Not agreed\n");
    }
}
```
- Cat example, while/for loops, while:
```c
#include <stdio.h>

int main(void){
int i = 3;
while (i > 0) {
	printf("Meow\n");
	i--;
	}
}
```
- while condition is evaluated after every iteration until breaks out
- also for
```c
#include <stdio.h>

int main(void){

for(int i = 0; i < 3; i++)
	{
		printf("Meow\n");
	}

}
```
- Carefully for infinite loops, example stop with control+C.
- Define functions (first void mens return, second one no input)
```c
#include <stdio.h>

void meow(void){
	printf("Meow\n");
}

  

int main(void){
	for(int i = 0; i < 3; i++)
	{
		meow();
	}
}
```
- Ideally keep main on top of file, if in bottom we get undeclared function error, you can just copy paste the signature (prototype)
```c
#include <stdio.h>

void meow(void);
int main(void){
	for(int i = 0; i < 3; i++)
	{
		meow();
	}
}

void meow(void){
	printf("Meow\n");
} 
```
- Make function stronger, pass parameters to function to decide how many times.
```c
#include <stdio.h>

void meow(int n);

int main(void)
{
	meow(10);
}

void meow(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Meow\n");
	}

}
```
- More functions capture user input:
```c
#include <stdio.h>
#include <cs50.h>

void meow(int n);

int main(void)
{
	int n = get_int("How many times should we do it?\n");
	
	meow(n);
}

void meow(int n)
{
for (int i = 0; i < n; i++)
	{
		printf("Meow\n");
	}
}
```
- Note that the `n` captured, and then passed to the function meow and then passed to the function is not the same, we can say `n` has three different values as they only exist in their respective scopes. Thats why we need to pass it along, we capture, we call the function with it and we use it inside the function for the for loop.
- Sanitizing input (e.g negative numbers), do while, really cool.
```c
#include <stdio.h>

#include <cs50.h>

void meow(int n);
int get_positive_int(void);

int main(void)
{
	int times = get_positive_int();
	meow(times);
}

  

int get_positive_int(void){
	int n = 0;

	do{
		n = get_int("How many times should we do it?\n");
	}while(n < 1);
	
		return n;

}

void meow(int n)
{
	
	for (int i = 0; i < n; i++)
		{
		printf("Meow\n");
		}
}
```
- in programming matters
	- correctness: code does what it does
	- design: subjective, kinda.
	- style: aesthetic
- Some comparison regarding super mario games,  build a block:
```c
#include <stdio.h>


int main(void){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("#");
        }
        printf("\n");
    }
}

```
  - using constants (if it does not change) are defined with the keyword `const` , compiler will never let it overwrite.
  - Comments also useful.
  - Calculator code, basically understanding operators.
  - Using a program to understand integer overflow:
```c
#include <stdio.h>
#include <cs50.h>


int main(void){
    int dollars = 1;
    while (true){
        char answer = get_char("Do you want to double %i$ and pass it a long the next person?\n", dollars);
        if (answer == 'y')
        {
            dollars *= 2;
        }
        else{
            break;
        }
    }
    printf("You got %i$ buddy\n", dollars);
}

```
- This happens:
```sh
Do you want to double 536870912$ and pass it a long the next person?
y
Do you want to double 1073741824$ and pass it a long the next person?
y
Do you want to double -2147483648$ and pass it a long the next person?
y
Do you want to double 0$ and pass it a long the next person?
y
Do you want to double 0$ and pass it a long the next person?
```
- This is an integer overflow, teh amount of data of bits to cointans breaks. This can have serious implications, watch out. Best way to avoid it using another type of a variable, maybe a `long`? Example of boeing, a plane had some stuff overflowing and it would just break.
- Truncation is another interesting concept, an integer divided between an integer returns an int , e.g `3/2` is not `1.5` but is 1, it truncates (not rounding)
```c
#include <stdio.h>
#include <cs50.h>


int main(void){
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("Result %i\n", x/y);
}

```

This returns
```sh
$ ./calculator 
x: 3
y: 2
Result 1
```

We can cast results, convert a type so its much cleaner if we change the printf type and cast to float:
```c
#include <stdio.h>
#include <cs50.h>


int main(void){
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("Result %f\n", (float) x/y);
}

```
This returns:
```sh
$ ./calculator 
x: 3
y: 2
Result 1.500000
```
We can even go cleaner and define the number of decimals a float shows using this trick, will return only two decimals `printf("Result %.2f\n", (float) x/y);` 

An additional issue is with decimal precission, similar to integer going to a certain value (integer grows) the growth of decimal precission can also present problems, see if we ask for a lot of decimals:
```sh
$ ./calculator 
x: 1
y: 3
Result 0.33333334326744079589843750000000000000000000000000
```
Its the same issue, the amount of precision is also stored in a limited number to bits, floats use also only `32` bits, so we can go also to double.


---
