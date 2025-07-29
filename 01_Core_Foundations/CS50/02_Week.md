
tags: [weekly-session, c50, week 2] 

---

# Week 2

Arrays

## 📚 Notes
- Metaphor on reading levels?
- Cypher text? Letter + 1
- Again, source code -> compiler -> machine code diagram.
- `make` command is not a compiler, there are many, we use clang.
- clang is not so user friendly, `clang hello.c` works the same.
- The command has serval args `clang -o hello hello.c` output a hello program from the file `hello.c`.
- Compile has multiple steps, some before:
	- Preprocessing: E.g check for prototypes at the top of the file, also the # for the imports, it literally copy pastes the file.
	- Compiling: Means that is translated from one language from C to assembly, closer to CPU.
	- Assembling: From assembly to 0's and 1's.
	- Linking: All of the files involved in the process, all files (including imports) in 0's and 1's, all linked together.
- Decompiling is possible, from 0's and 1's to code, some ambiguity at some point and it can't be exact.
- Debugging to find and fix mistakes. Ruberducking, print,...
- We are going to use debug50, instead of print.
  ```sh
- $ debug50 buggy
Looks like you've changed your code. Recompile and then re-run debug50!
```
- First attempt to run we have not added any breakpoint, we do so in the line we want the code to stop and inspect (this is the same as debugging Python in vscode).
- Step over/into/etc...
- Sometimes the values that debugger show (specially before they are used first time) they are garbage values (old values used in the past, can be ignored a soon as reassigned).
- The types, how can the computer know what is what if all is 0 and 1's? (int float bool char string...)
- Example of a grid on top of a chip to represent memory
  ![[Pasted image 20250525163256.png]]
- Imagine we want to store the following variables:
```c
	int score1 = 72;
	int score2 = 73;
	int score3 = 33;
```

To the run:
```c
#include <stdio.h>

int main(void){
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    printf("avg -> %f\n", (score1+score2+score3)/3.0);
}

```
- How are those values stored? They are integers so its going to be 4 bytes(32 bits each), of each cell is a byte:

| **score1** | **score1** | **score1** | **score1** | **score2** | **score2** | **score2** | **score2** |
| ---------- | ---------- | ---------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| **score3** | **score3** | **score3** | **score3** |            |            |            |            |
- The prev program could be better designed if add more values, we probably want an array: Series of contiguous values in memory **that are the same data type**, quite equivalent code
```c
#include <stdio.h>

int main(void){
    int scores[3];
    scores[0] = 72;
    scores[1] = 73;
    scores[2] = 33;

    printf("avg -> %f\n", (scores[0]+scores[1]+scores[2])/3.0);
}

```
Memory distribution should be similar to the prev example.
- The code can still better written to be more dynamic, using constants and delegating the average to a func (also using float cast)
```c
#include <stdio.h>
#include <cs50.h>

const int N = 3;

float average(int length, int array[]);

int main(void){
    int scores[N];
    for (int i = 0; i < N; i++) {
        scores[i] = get_int("Add grade: ");
    }
    printf("avg -> %f\n", average(N, scores));
}


float average(int length, int array[]){
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum/(float)N;
}

```
- In C when you pass an array you dont define the length on the func signature, but then you need to pass the length.
- Now we do strings in mem (reminder sngle quote a char, double is a string); this prints `HI!` as 3 chars.
```c
#include <stdio.h>


int main(void){
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%c%c%c\n", c1, c2, c3);
}

```
- If we change the placeholders from c to i we can see the actual ASCII values:
```c
#include <stdio.h>


int main(void){
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

	printf("%i %i %i\n", c1, c2, c3);
}

```
- This oputputs `72 73 33` , a char is a byte (like an int so in mem):
  

| H   | I   | !   |
| --- | --- | --- |
| c1  | c2  | c3  |
- A string is a sequence of characters, e.g same example (outputs the same)
```c
#include <cs50.h>
#include <stdio.h>


int main(void){
    string s = "HI!";

    printf("%s\n", s);
}
```
- So a string uses contiguous memory positions, so its an array of chars? So we can think of s like `s[0],..,s[n]` where we can access by index. 
- But... if we declare a string without its lenght as we do with arrays, how can a computer know when to start or stop writing? (starts at `H` and ends at `!`?) This is done by spending an extra byte (8 bits) set all to 0 (padding?). So if we declare s as an array of strings:
  
| s[0] | s[1] | s[2] | s[3]     |
| ---- | ---- | ---- | -------- |
| H    | I    | !    | 00000000 |
- We can actually see this if we print a string and access its last byte using integers as placeholder:
```c
#include <cs50.h>
#include <stdio.h>

int main(void){
    string s = "HI!";

    printf("%i %i %i %i \n", s[0], s[1], s[2], s[3]);
}

```
This outputs `72 73 33 0` .
- Currently there is nothing stopping us form going even further and we will start to see values form other "memory cells", see when we add a `s[4]` we see `72 73 33 37`, the 0 is gone and we get a 37.
- The actual 0 we saw used to represent the end of a string its known as `NUL` (one L), and its recognised as an ASCII character.
- We can play around now doing this:
```c
#include <cs50.h>
#include <stdio.h>

int main(void){
    string s = "HI!";
    string t = "BYE!";
    printf("%s - %s", s, t);
}
```
- In memory we can imagine having those chunks:  

| H   | I   | !   | \0  | B   | Y   | E   | !   | \0  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
|     |     |     |     |     |     |     |     |     |
- Single chars do not add a 0, so thats why using single or double quotes is relevant.
- We can also add arrays of strings:
```c
#include <cs50.h>
#include <stdio.h>

int main(void){
    string words[2];
    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%s, %s", words[0], words[1]);
}
```
- Now imagine how we would want to go to the first time of the array `HI!` and access to each of the values of that string (aka characters), like `words[0][0]`? 
```c
#include <cs50.h>
#include <stdio.h>

int main(void){
    string words[2];
    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%c %c %c", words[0][0], words[0][1], words[0][2]);
}
```
- Lets write a program to figure out the length of a string by counting on a string until the `NUL` character shows up
```c
#include <stdio.h>
#include <cs50.h>

int main(void){
    string name = get_string("Enter your name: ");
    int n = 0;
    while (name[n] != '\0'){
        n++;
    }
    printf("%i\n", n);
}
```
- Maybe a function looks better:
```c
#include <stdio.h>
#include <cs50.h>

int string_length(string s);

int main(void){
    string name = get_string("Enter your name: ");
    int length = string_length(name);
    printf("%i\n", length);
}


int string_length(string s){
    int n = 0;
    while (s[n]!='\0'){
        n++;
    }
    return n;
}

```
- There is a function already for this, using a library `int strlen()`, so it looks like:
```c
#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void){
    string name = get_string("Enter your name: ");
    printf("%i\n", (int)strlen(name));
}
```
- We also have `ctype.h` (check https://manual.cs50.io/#ctype.h)
- When checking ASCI we see a lower case letter you can find its upper case by adding 32 (1 bit), maybe we can write a cool function?
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main(void){
    string s = get_string("Input: ");
    for (int i = 0, n = strlen(s); i<n; i ++){
        if (isupper(s[i])){ // this can anslo be done s[i] >= 'a' and s[i] <= 'z' or even numbers directly
            printf("%c", s[i]);
        }
        else{
            printf("%c", toupper(s[i])); // can do ecven s[i] - ('a' - 'A') instead of sub s[i] - 32
        }
    }
    printf("\n");
}
```
- The above snippet could be even improved to remove the isupper check and let toupper cast to upper if its not upper.
- Creaeting code w/ cli arguments by passing params to main like:
```c
#include <stdio.h>

int main(int argc, string argv[]){}
```
- Some fixed values like `argv[0]` being the program name, from index `1` is the rest of args we are passing, for example if this is our snippet
```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]){
    printf("Print argv[0]  as program name %s\n", argv[0]);
    printf("Print argv[1] as first param %s\n", argv[1]);
    printf("Print argc %i\n", argc);
}
```
- The input `./greet foo` seems to return:
```plaintext
Print argv[0]  as program name ./greet
Print argv[1] as first param foo
Print argc 2
```
- But if we do `./greet foo aaa`:
```plaintext
Print argv[0]  as program name ./greet
Print argv[1] as first param foo
Print argc 3
```
- So its seems that indeed `argc` is kinda of the argument counter(argc) and argv is just the argument vector(argv), lol; should be quite easy to for loop over argc (or len argv) to print all of the stuff passed.
- cowsay meme
Exit status:
- Why is main always returning an int based on its signature? `int main(void)`? Codes are overall used for errors or communicate some message (think also for HTTP).
- In c returning 0 is all good, e.g this example to check if at least one arg is passed
```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]){
    if (argc!=2){
        printf("Missing args\n");
        return 1;
    }
    printf("All gucci %s\n", argv[1]);
    return 0;
}
```
- Behaves as:
```plaintext
$ ./status 
Missing args
$ ./status foo
All gucci foo
```
- We dont see the code (the return of the main) when the program runs we can do it running `echo %?` to print the output of the last command from the terminal, see w/ both examples again:
```plaintext
$ ./status 
Missing args
$ echo $?
1
$ ./status foo
All gucci foo
$ echo $?
0
```

Encryption
- Scrambling info in a reversible way, again like an algorithm:
```plaintext
plaintext + (key) -> [ cipher ] -> ciphertext
```
- The key allows a uniqueness to protect the encryption process.
-  Weak key -> brute force.
- Decryption is just the inverse process to go from ciphertext to plaintext.