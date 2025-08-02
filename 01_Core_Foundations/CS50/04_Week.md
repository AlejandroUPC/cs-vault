
tags: [weekly-session, c50, week 4] 

---

# Week 4

Memory

## 📚 Notes

#### Pixel Art

- Img is nothing (like everything) 1s and 0s.
- Images are represented (among other ways) as RGB.
#### Hexadecimal 

- Hexadecimal base 16 (like binary, decimal) where you have 16 digits (1-8, A-F), 000000 black FFFFFF white. 
	- Each of the pairs for the six digits are for R G and B.
	- Similar system, we have two digit values and its everything using 16 base so first digit is 16^0 and second one 16^1.
	- The table of values
	  
| 16  | 1   | value           |
| --- | --- | --------------- |
| 0   | 0   | 0               |
| 0   | 1   | 1               |
| 0   | 2   | 2               |
| 0   | 3   | 3               |
| 0   | 4   | 4               |
| 0   | 5   | 5               |
| 0   | 6   | 6               |
| 0   | 7   | 7               |
| 0   | 8   | 8               |
| 0   | 9   | 9               |
| 0   | A   | 10              |
| 0   | B   | 11              |
| 0   | C   | 12              |
| 0   | D   | 13              |
| 0   | E   | 14              |
| 0   | F   | 15              |
| 0   | 16  | 16              |
| ... | ... | ...             |
| F   | F   | 255(16*15 + 15) |
- We can also name a grid of memory using hexadecimal
![[Pasted image 20250802020951.png]]
- When writting some hexadecimal value write a `x0` before to know if a 10 is actual decimal base or hex.
#### Memory
- Computer have addresses where they store data, a simple program like this
```c
#include <stdio.h>


int main(void)
{
    int n = 50;
    printf("%i\n", n);
}

```
- it stores the value fo the variable n somewhere in the mem such as that takes 32 bits, could be 0x123 as an address.
![[Pasted image 20250802021331.png]]
  
#### Pointers
- A pointer is a variable that stores the address of something.
- The characters `&` (address of operator) passed to the compiler will tell you where that variable is in the address, it points where the variable lives in the memory. The `*` is the dereference operator which is going to bring us (having an address before) go into that location in memory and seeing whats there.
- The first tells you the address (addressof operator) and the second how to get there.
- We can print pointers using printf using a datatype `%p`.
```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%i in %p\n", n, p);
}```

```plaintext
$ ./addresses 
50 in 0x7ffecfbbae8c
```
- We could do directly though (different address is fine), without having to store `&n` into `*p`
```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%i in %p\n", n, &n);
}
```
- We can play around with pointers, and access the value using a pointer and the `*` operator
```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%i in %p we access the value %i\n", n, p, *p);
}
```
- There are two different user the starts, when we declare the variable and then again when we want to access the memory address.
- The variable of the value n was store in some cell where we assumed `0x1233` but is the variable `p` also stored? It is, and its usually 64 bits (so much bigger than the actual value it points to), addresses are big:
![[Pasted image 20250802022648.png]]
#### Strings
- String is an array of chars, they dont really exist in c as a data type.
- If we had a `string s = 'HI!';` it would be 4 (the 3 characters + `\0`) in contiguous mem.
![[Pasted image 20250802023414.png]]
- If we print the pointer
```c
#include <stdio.h>
#include <cs50.h>


int main(void)
{
    string s = "HI!";
    printf("%p\n", s);
}
```
- We get the address we can check all the positions
```c
#include <stdio.h>
#include <cs50.h>


int main(void)
{
    string s = "HI!";
    printf("%p\n", s); // coming from future this is already an address no point doing &s
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}

```
- We get the first two prints the same (by default a pointer prints the first position then contiguous)
```plaintext
0x5ea688cdb004
0x5ea688cdb004
0x5ea688cdb005
0x5ea688cdb006
0x5ea688cdb007
```
- The actual variable `s` stores nothing but the address of the first character of a string. It could be understood as `char *s = "HI!";` instead of `string s = "HI!";`.
- When we declared structure (classes) its quite similar, we can define a kind of synonym integers for int `typedef int integer;` so we can access integers as int. We could do the same with strings as `typedef char *string;` (Note we are declaring a type not a variable).
- Strings do not exist as type in c but you can still use the `%s` in printf lol.
#### Pointers arithmetic
- We can do math on addresses, move `n` bytes away, e. here we pick a pointer and keep moving:
```c
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
    printf("%c\n", s[3]);
}
```
- We could also do:
```c
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    printf("%c\n", *(s + 3));
}
```
- We could also print some part of the string (so it will ignore the first n characters and keep printing until `\0`)
```c
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%s\n", s+1);
}
// prints I!
```
#### String comparison
- Comparing integers is kinda easier, if we compare two numbers (32 bit each) are the same if they store the same value
![[Pasted image 20250802025810.png]]
- For strings in prev week we used already `strcmp` so its not that stright forward (with ints we can use `==`), this returns diff
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (s==t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Diff\n");
    }
}
//$ ./compare 
//s: a
//t: a
//Diff
```
- Why? Because if we remember we defined the data type `string` as a pointer to the first position of an array of chars, so we are comparing two addresses of the first position of an array instead, will be diff, kinda this:
![[Pasted image 20250802030328.png]]
- strcmp from `#include <string.h>` solves this when it returns 0 if they are the same.
#### Copying and malloc
- We can manipulate string, and make copies.
- We declare a string s and create a new variable to that equals to s and modify t, but the changs are also reflected on s even when we only changed t?
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s :");
    string t = s;

    t[0] = toupper(t[0]);
    printf("s: %s\n", s);
    printf("t %s\n", t);
}
```
- So it looks like instead creating a new variable it made t a copy of s? Because its just the same address! When we do changes if strings are addresses then s and t will point to the same value
![[Pasted image 20250802031627.png]]
- Primitives data types such as integers and so on it works, but a string is a pointer.
- We can use malloc and free, malloc (memory allocation) is a function that accepts the number of bytes of mem you want and it sends you back the address of the first byte of that mem. Free is the opposite, it just liberates it so it can be used again.
- This now works(the +1 for NULL terminator)
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s :");
    char *t = malloc(strlen(s) + 1);

    for (int i = 0, n = strlen(s); i <= n; i++) // <= so we copy the null
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);
    printf("s: %s\n", s);
    printf("t %s\n", t);
}

```
- Careful when playing w/ memory such as malloc (if no space returns NULL), something went wrong, we can add a check on `t` to return 1 before starting to copy stuff if there is no space.
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s :");
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    for (int i = 0, n = strlen(s); i <= n; i++) // <= so we copy the null
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);
    printf("s: %s\n", s);
    printf("t %s\n", t);
}
```
- We could add als oa check and make sure we only capitalize if its 5 is an actual value (not empty):
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s :");
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    for (int i = 0, n = strlen(s); i <= n; i++) // <= so we copy the null
    {
        t[i] = s[i];
    }
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t %s\n", t);
}
```
- Playing with memory its dangerous, code with a defense mindset. 
- We can save a lot of this and just use `strcpy(destination, source)`.
#### Valgrind
- CLI tool that helps to find memory related errors, e.g see this buggy code
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[1] = 72; // we should start idx 0 error on purpose
    x[2] = 73;
    x[3] = 74;
    // no free of memory
}
```
- We can run and complains about array size and 12 bytes of lost mem:
```plaintext
$ valgrind ./memory 
==37613== Memcheck, a memory error detector
==37613== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==37613== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==37613== Command: ./memory
==37613== 
==37613== Invalid write of size 4
==37613==    at 0x109170: main (memory.c:9)
==37613==  Address 0x4b9f04c is 0 bytes after a block of size 12 alloc'd
==37613==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==37613==    by 0x109151: main (memory.c:6)
==37613== 
==37613== 
==37613== HEAP SUMMARY:
==37613==     in use at exit: 12 bytes in 1 blocks
==37613==   total heap usage: 1 allocs, 0 frees, 12 bytes allocated
==37613== 
==37613== 12 bytes in 1 blocks are definitely lost in loss record 1 of 1
==37613==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==37613==    by 0x109151: main (memory.c:6)
==37613== 
==37613== LEAK SUMMARY:
==37613==    definitely lost: 12 bytes in 1 blocks
==37613==    indirectly lost: 0 bytes in 0 blocks
==37613==      possibly lost: 0 bytes in 0 blocks
==37613==    still reachable: 0 bytes in 0 blocks
==37613==         suppressed: 0 bytes in 0 blocks
==37613== 
==37613== For lists of detected and suppressed errors, rerun with: -s
==37613== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```
- If we solve those two:
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[0] = 72; // we should start idx 0 error on purpose
    x[1] = 73;
    x[2] = 74;
    free(x);
}

```
- And rerun:
```plaintext
$ valgrind ./memory 
==38379== Memcheck, a memory error detector
==38379== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==38379== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==38379== Command: ./memory
==38379== 
==38379== 
==38379== HEAP SUMMARY:
==38379==     in use at exit: 0 bytes in 0 blocks
==38379==   total heap usage: 1 allocs, 1 frees, 12 bytes allocated
==38379== 
==38379== All heap blocks were freed -- no leaks are possible
==38379== 
==38379== For lists of detected and suppressed errors, rerun with: -s
==38379== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
#### Garbage values
- If we first run this code
```c
#include <stdio.h>

int main(void)
{
    int scores[1024];
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}
```
- We are going to print 1024 values, but which? (sample)
```plaintext
0
0
0
1730441540
32767
1061328080
30121
1064990336
30121
1064758188
30121
1459795768
0
1730441912
32767
```
- Those are some weird values if we did not populate anything.
- This code here would crash on y because its a garbage value, it just an address we have not allocated mem
![[Pasted image 20250802034230.png]]
- After that line, if removed the code would run.
#### Blinky
- Some youtube video to learn pointers.
- We declared two pointers that allocate integers but they dont point to anything yet, we need to set up a pointee(something to point to).
- To allocate we need to use malloc, doing a reference to x follows the pointer and sets the value. 
- Two pointers can share the same pointee (point the same address).
#### Swapping
- Swapping values happen often (e.g sorting algorithms) and it can be a common operation. Example with glasses and containing values, if you have two glasses and want to exchange what they contain you probably need an extra glass to temporally hold one.
- We can swap actually reassigning values or maybe just changing addresses might be more efficient + if we swap in a function this would only happen inside the scope of the function (outside it would not swap). This is because we are passing arguments by value, not pointer. So it creates copies of the values it passes.
- This wont swap, only inside the function:
```c
#include <stdio.h>

void swap(int x, int y);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i and y is %i\n", x, y);
    swap(x, y);
    printf("x is %i and y is %i\n", x, y);
}

void swap(int x, int y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
```
- When you run a program it loads the machine code in the top (convention) then globals and then if we are using malloc loads some heap (it can grow) if we do cal it and then the stack. Heap is for malloc stack is for everytime there is a function it uses the stack(not the heap that uses malloc)
![[Pasted image 20250802040034.png]]
- If we focus in stack (grows upwards, heap downards) it contains a list of the functions we call, like in the swap example
![[Pasted image 20250802040147.png]]
- So the changes in x,y do not happen in the main function (happen in the swap), we pass copies of the values not references.
- Why does it works? We are passing the addresses we are common regardless of the stack.
- This works
```c
#include <stdio.h>

void swap(int *x, int *y);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i and y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i and y is %i\n", x, y);
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
```
- There is somewhat an issue of having malloc go down and stack go up, they share a space of memory and they can run into conflict with memory (overflow).
#### Overflow
- There are two types of memory
	- heap overlfow: malloc abuses
	- stack overflow: stack abuses on calls
- Those two are buffer overflow, where there is not enough memory on a buffer.
- Crowdstrike example, very hard in low level to control this and easy to mess up.
#### scanf
- Some of the functions we used in the past `get_int` its simple to get an int, strings are different because they can pass a lot of characters, the rest have a fix size.
- We try to implement get_int
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    printf("n = ");
    scanf("%i", &n);
    printf("n =  %i\n", n);
}
```
- get_int is a bit more and does some type checking, implementing with a string is a bit harder, this might not be the correct version
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *s;
    printf("s: ");
    scanf("%s", s);
    printf("s: %s", s);
}
```
- the `scanf` is somewhat dangerous because it does not know how long is the string or how much memory is available, so far at this point in the code we only a allocated 8 bytes for the pointer address.
- The solution is to initialise the value, not just the address but still would be dangerous if the user adds more than 4
```c
#include <stdio.h>

int main(void)
{
    char *s = malloc(4);
    printf("s: ");
    scanf("%s", s);
    printf("s: %s", s);
    free(s)
}
```
 - Thats why using already written functions like `get_string` that takes care of it.
#### File I/O
- We need pointer syntax to do this in c.
- There are a bunch of functions already fopen, fclose, fprintf, fscanf, fread, fwrite, fseek ...
- Data type called FILE
- Quite simple example
```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");
    fprintf(file, "%s, %s\n", name, number);
}
```
- Like malloc opening files can also go wrong (no mem, file does not exist) so we can check return values, check always if there are addresses involved
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        return 1
    }
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");
    fprintf(file, "%s, %s\n", name, number);
}
```
- To copy files ourselves, we want to use data type BYTE and some hacking around 
```c
#include <stdint.h>
#include <stdio.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "r");
    FILE *dst = fopen(argv[2], "w");

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }
    fclose(src);
    fclose(dst);
}

```
