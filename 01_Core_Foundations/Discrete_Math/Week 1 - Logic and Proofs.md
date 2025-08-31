
## 1. What is a proof?

#### 1.1 Proposition

**Definition** A statement that is either true or false.

**Proposition 1.1.1** -> 2+3=5 is True
**Proposition 1.1.2** -> 1+1=3 is False

Its not always that simple to decide whether a proposition is true.

**Claim 1.1.3** *For every nonnegative integer n the value of $n^2 + n + 41$* is prime, this seems to be initially true

| n   | p(n) |
| --- | ---- |
| 0   | 41   |
| 1   | 43   |
| 2   | 47   |
| 3   | 53   |
| 20  | 261  |
What happens in $p(40) = 40^2 + 40 + 41 = 1681$ which is not prime as it can also be then divided by 41. So the previous claim is false as we have just proved. The relevant part here is that the claim defined a set of infinite numbers (every nonnegative) and you can't check such a claim with a defined number of samples, if we stoped at 3 we would have assumed this was a valid claim.
The previous notation can also be defined as $∀n∈ℕ. p(n)$  is prime.

Another few examples is **Euler's equation** $a^4 + b^4 + c^4 = d^4$ has no solution when a,b,c and d are positive integers, from 1769 was proved false 218 years later for $a=95800, b=217519, c=414560, d=442481$.
Some are very hard to prove such as $313 (x^3 + y^3)=z^3$  has no solution for all positive integers, as the smallest value to prove this to ve true (so the proposition is false) have each more than 1000 digits.

There is also the **Four Color Theorem** that says that every map can be coloured w/ 4 colors so that the adjacent (share boundary) regions have different colours.
There has been several proofs presented for this theorem until in 1976 with the help of computers they managed to asses it but no one would check if it was really true, and a few decades later a proof was presented ([very hard to read](https://thomas.math.gatech.edu/FC/fourcolor.html)).

The **Fermat's Last Theorem** has a proposition that $x^n + y^n = z ^2$ for $n>1$.  Took a while and this was proven to hold true for values up to 4.000.000 (but we cannot trust a limited sample, see Euler's case that ended up being false) ended up being proved as true and became a Theorem.

The **Goldbach Conjecture** says that every integer greater than 2 is the sum of two primes, from 1742 holds true for all numbers up to $10^{18}$, up to this day no one can prove it.

In the computer world the most important things to prove are usually the correctness of programs and systems (whether if they do what they are supposed to do).

#### 1.2 Predicates

A proposition whole truth depends on the value of one or more variables, $n$ is a perfect square is a  predicate, but it depends on its values (4-> ok, 5->nok), they follow the notation $P(n) ::=$ "n is a perfect square


#### 1.3 The Axiomatic Method

Standard method to establish truth in mathematics, by Euclid 300 BC, being his starting point five assumptions about geometry which seemed undeniable based on personal experience such as a there is a straight line segment between every pair of points. Widely accepted propositions are called axioms.
From those axioms Euclid establishes the truth of many additional propositions by providing proofs. 
A **proof** is a sequence of logical deductions from axioms and previously probed statements that concludes with the proposition question.
A proposition that has been proved can be also called, based on some details:
- Important true propositions are called theorems.
- A lemma is a preliminary proposition useful for proving later propositions.
- A corollary is a proposition that follows in just a few logical steps from a theorem.
All of these definitions are not precise (a lemma can be more important than a theorem).
Euclid's axiom-and-proof is now called axiomatic method and is widely accepted in mathematics.
In fact, the Zeremlo-Fraenkel with Choice Axioms(ZFC) (lol what is this),with a few logical deduction rules seem to be sufficient to derive all of mathematics. 



#### 1.4 Our Axioms

ZFC are important for studying and justifying the foundations of maths but too primitive as well, in computer science can be understood as writing byte code instead of a scripting language, where the formal ZFC proof of $2+2=4$ is 20.000 steps, so we accept a lot of axioms when proving.

###### 1.4.1 Logical Deductions

Or inference rules are used to prove new propositions using old ones.
A fundamental one is *modus ponens*, that says if a that a proof of $P$ together with a proof that $P$ IMPLIES $Q$ is a proof of $Q$. This deductions must be *sound*, **which means you can assign truth values that make all the antecedents true must also make the consequent true, A->B is False ONLY if A is True and B is False**.
It can be written as (if P is true, then p and q then q is true)

$\frac{P, P -> Q}{Q}$ 


If the antecedents (numerator) are proved then the denominator(conclusion or consequent) $Q$ in this case can be considered proved.
There are a few other inference rules
$\frac{P -> Q, Q ->R}{P->R}$

```
| P | Q | R | P -> Q | Q -> R | P -> R |
|---|---|---|--------|--------|--------|
| T | T | T | T      | T      | T      |
| T | T | F | T      | F      | F      |
| T | F | T | F      | T      | T      |
| T | F | F | F      | T      | F      |
| F | T | T | T      | T      | T      |
| F | T | F | T      | F      | T      |
| F | F | T | T      | T      | T      |
| F | F | F | T      | T      | T      |

```

Per parts, based in the rule of **soundness that A->B is false only if A is true and B is False.**
P->Q is false in 3,4.
Q->R is false in 2,6.
P->R is false in 2,4.

So because the rows where the premises  P->Q and Q->R are True all of the P->R is also True.

or
$\frac{NOT(P)->NOT(Q)}{Q ->P}$

We check negated values
```plaintext
| P | Q | NOT P | NOT Q | Premise: NOT P -> NOT Q | Conclusion: Q -> P |
|---|---|-------|-------|-------------------------|--------------------|
| T | T |   F   |   F   |           T             |         T          |
| T | F |   F   |   T   |           T             |         T          |
| F | T |   T   |   F   |           F             |         F          |
| F | F |   T   |   T   |           T             |         T          |
```

The only **soundness** where NOT(P) -> NOT(Q) (True to False) happens on row 3 but the conclusion is also False, so we can assume that for all the premises where NOT P -> NOT Q the conclusion Q->P is TRUE.


There is the contrarian, non rules such as
$\frac{NOT(P) -> NOT(Q)}{P->Q}$ see the difference in denominator of the previous rule, this is because if P is True and Q is False, then the antecedent is True and the consequent False, the the antecedent is True and the consequent not (see sound requierement written before.)

```plaintext
| P | Q | NOT P | NOT Q | Premise: NOT P -> NOT Q | Conclusion: P -> Q |
|---|---|-------|-------|-------------------------|--------------------|
| T | T |   F   |   F   |           T             |         T          |
| T | F |   F   |   T   |           T             |         F          |  <-- Counterexample
| F | T |   T   |   F   |           F             |         T          |
| F | F |   T   |   T   |           T             |         T          |

```
Here we have the issue where the premise is True but the conclusion is false again, soundness is only False if first element is true and second is False, so NOT P NOT Q in the second row , which is F->T = True but T->F which is False, so if we do (F->T) -> (T->F) we have T->F which is not sound.


> [!NOTE] LLM help example
>  Below




Yacht example, based on the proposition that if I win the lottery I will buy a Yacht:
```plaintext
Truth table for implication (A → B) with yacht example
------------------------------------------------------

Let:
A = "I win the lottery"
B = "I buy a yacht"

Case 1: A = True,  B = True
"If I win the lottery, then I buy a yacht."
- I DO win the lottery, and I DO buy a yacht → statement is TRUE.
- The 'if' part happened, and the 'then' part also happened.

Case 2: A = True,  B = False
"If I win the lottery, then I buy a yacht."
- I DO win the lottery, but I DO NOT buy a yacht → statement is FALSE.
- The 'if' part happened, but the 'then' part failed → only case that makes it false.

Case 3: A = False, B = True
"If I win the lottery, then I buy a yacht."
- I DO NOT win the lottery, but I DO buy a yacht anyway → statement is TRUE.
- The 'if' part did not happen, so the promise isn't broken (vacuously true).

Case 4: A = False, B = False
"If I win the lottery, then I buy a yacht."
- I DO NOT win the lottery, and I DO NOT buy a yacht → statement is TRUE.
- The 'if' part did not happen, so we don't care what happens after; promise isn't broken.

Summary rule:
A → B is FALSE only when A is True and B is False.
In all other cases, it is TRUE.

```


###### 1.4.2 Patterns of Proof

A proof can be any sequence of logical deductions from axioms, which starting point to pick? There are some different patterns and recipes on how to structure and size your proofs. 

#### 1.5 Proving an implication

Propositions of the form "if P then Q" are implications, "P IMPLIES Q", a few examples (see the pattern if XXXX then YYY)

**Quadratic formula** if $ax^2 + bx + c = 0; a!=0$ then $x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$ 
**Goldbachs conjecture** if $n$ is an even integer greater than 2, then $n$ is a sum of two primes.
**Random example** if $0 \leq x \leq 2$ then $-x^3 + 4x + 1 \ge 0$ .
There are a few standard methods for proving an implication

###### 1.5.1 Method #1

In order to prove that $P$ IMPLIES $Q$:
1. Write, "Assume $P$"
2. Show that $Q$ logically follows

Example

**Theorem 1.5.1** if $0 \leq x \leq 2, then -x^3+4x+1 > 0$ 
Before the proof we can see that for example the value holds true for $x=0$ where $1>0$. As x grows it seems that the $4x$ value has a bigger impact than $-x^3$ but this does not hold true form $x>2$ 

```plaintext
| x | f(x)  |
|---|-------|
| 0 |   1   |
| 1 |   4   |
| 2 |   1   |
| 3 | -14   |
| 4 | -47   |
| 5 | -104  |

```
So with this table it should be enough, but lets refactor a little bit by refactoring the relevant terms (remove +1):
$-x^3 + 4x = x(2-x)(2+x)$ , so if we check the limits between 0 and 2:
(note same as table w/o +1)
$0(2-0)(2+0)=0$
$1(2-1)(2+1)=3$
$2(2-2)(2+2)$=0

So we can assert the claim that $x(2-x)(2+x)+1 = -x^3+4x+1 > 0$.
For all the proofs usually:
- Need t do some computations.
- Profs usually begin with "Proof" and end with a delimiter like [] or "QED".

###### 1.5.2 Method #2 - Prove the contrapositive
An implication "P IMPLIES Q" is logically equivalent to its contrapositive "NOT Q IMPLIES NOT Q".
Proving one is as good as the other but sometimes one is much easier, we can proceed as:
1. "We prove the contrapositive:"
2. And then we proceed as method 1

Example
**Theorem 1.5.2** If $r$ is irrational, then $\sqrt{r}$ is also irrational.
A number is rational if it can be defined as a fraction of integers and the denominator is not 0, so we want to prove that if $r$ is **not** a ratio of integers, then $\sqrt{r}$ is also not a ratio of integers

Proof: We prove the contrapositive, if $\sqrt{r}$ is rational, then $r$ is rational. If we assume that $\sqrt{r}$ is rational, then there must be a se of integers that:
$\sqrt{r}=\frac{m}{n}$ if we square we get $r=\frac{m^2}{n^2}$ , so since $m$ and $n$ are integers(square of integers is always an integer), $r$ is also rational as we defined it as a division of integers (rational).


#### 1.6 Proving if and only if

Many math theorems assert two statements can be logically equivalent, if one is true the other also:
> Two triangles have the same side lengths **if and only** if two of the side lengths and the angle between them are the same.

Here the **if and only if** part is relevant, usually abbreviated as "iff".

###### 1.6.1 Method #1: Prove Each Statement Implies the Other

The statement $P$ $IFF$ $Q$ its a merge of the statement $P$ $IMPLIES$ $Q$ and $Q$ $IMPLIES$ $P$, so we can write:
1. "We prove P implies Q and vice-versa".
2. "First we show P implies Q", using methods from section 1.5.
3. "Now we should Q implies P", also 1.5.

###### 1.6.2 Construct a chain of Iffs
To prove $P$ is true iff $Q$ is true, we write:
1. "We construct a chain of if-and-only-if implications".
2. Prove $P$ is equivalent to a second statement which is equivalent to a third statement... and so on until reaching $Q$.

For example

The standard deviation of a sequence of values $x_1, x_2, ..., x_n$ can be defined as
$$
\sqrt{\frac{(x_1 - \mu)^2 + (x_2 - \mu)^2 + ... + (x_n - \mu)^n}{n}}
$$
Where $\mu$ is:
$$
\mu ::= \frac{x_1 + x_2 + ... + x_n}{n}
$$

**Theorem 1.6.1**  The standard derivation of a sequence of values $x_1, ..., x_n$ is zero **iff** all the values are equal to the mean.

**Proof** We construct a chain of **iff** implications, starting with the statement that the standard deviation is 0:

$$
\sqrt{\frac{(x_1 - \mu)^2 + (x_2 - \mu)^2 + ... + (x_n - \mu)^n}{n}} = 0
$$
Now since zero is the only number whose square root is zero and 0/n = 0, the equation above holds:
$$
(x_1 - \mu)^2 + (x_2 - \mu)^2 + ... + (x_n - \mu)^n = 0
$$
Squares of real numbers are always non negative (any number at square is positive), means that any of the squared sums will be positives... what number can we keep adding infinitely to obtain 0 that is positive? 0, this means that the equation above holds **iff** every term on the left side is 0, 
but a term $(x_i - \mu)^2$ is zero, **iff** $x_i = \mu$, so every $x_i$ equals the mean.

(this above was freakin cool)


#### 1.7 Proof by Cases

Breaking a prof into cases and proving each one is a common. We agree given any two people, either they have met or not. If every pair of people in a group has met, they are a club. The opposite, if every pair of group in a people has not met its a group of strangers.

**Theorem** Every collection of 6 people includes a club of 3 people or a group of 3 strangers.

**Proof** The proof is by case analysis, let $x$ be one of the six people, there are two cases:
1. Among 5 other people, besides $x$ at least $3$ have met $x$.
2. Among 5 other people, besides $x$ at least 3 have not met $x$.

**Pigeon principle** If you put more pigeons than boxes, at least one box must contain more than one pigeon.

This problems is easy to visualise represent as nodes and edges, if you manage to close a triangle of any color (met/not met) then you have a club/strangers group.

So the first case where three people have independently met $x$ you can divide two subcases:
	1.1. One of those three people also met each other, so you have a club; theorem still holds true.
	1.2 Any of those have ever met, you have strangers, theorem still holds true.

In the second case, where three of those people have not met $x$ we also have the two options:
	1.1 Every pair among those met each other, then its a club; theorem holds true.
	1.2 Some pair among those two have not met, so again its strangers; theorem holds true.

So it holds for all the sub cases, we only need those subcases because the number is 6 and we are looking at triangles to decide if its a club or not.

Some LLM ASCII:

```plaintext
Pick person x
│
├── Case 1: At least 3 people HAVE met x
│      (say a, b, c)
│
│   ├── Subcase 1a: At least one pair among {a,b,c} met each other
│   │       → x + that pair = 3 mutual friends ✅
│   │
│   └── Subcase 1b: None of {a,b,c} met each other
│           → {a,b,c} = 3 mutual strangers ✅
│
└── Case 2: At least 3 people have NOT met x
       (say d, e, f)
│
    ├── Subcase 2a: At least one pair among {d,e,f} have NOT met
    │       → x + that pair = 3 mutual strangers ✅
    │
    └── Subcase 2b: All of {d,e,f} have met each other
            → {d,e,f} = 3 mutual friends ✅

```

#### 1.8 Proof by Contradiction
Or indirect proof, if a proposition were false, then some false fact would be true. And since a false fact can't be true, the proposition must be true. ( a bit of a clusetrfuck of words). Better to use direct proofs when possible.

**Method**: In order to prove a proposition $P$ by contradiction:
1. Write, "We use proof by contradiction"
2. Write, "Suppose $P$ is false"
3. Deduce something known to be false (a logical contradiction)
4. Write, "This is a contradiction. Therefore, $P$ must be true"

**Example**
We will prove $\sqrt{2}$  is irrational, a number is irrational if its equal to a ratio of integers, e.g $3.5 = 7/2$ and $0.111... = 1/9$ are rational numbers.

**Theorem 1.8.1**: $\sqrt{2}$ is irrational.

*Proof*: We can proof by contradiction, if we assume the claim is false, and $\sqrt{2}$ is rational, then we can write $\sqrt{2}$ in lower terms $\frac{n}{d}$  in lowest terms, where $n$ and $d$ are integers.
We can go and develop the following:
$$
\sqrt{2} = \frac{n}{d}
$$
$$
2 = \frac{n^2}{d^2}
$$

We end up with $2d^2 = n^2$ which implies $n$ is a multiple of 2 (Problems 1.14 and 1.15). So we can say that $n^2$ must be a multiple of $4$ (we just multiply the 2 in front of $d^2$). If $2d^2$ is a multiple of 4, $d^2$ is a multiple of 2, so that implies that $d$ is a multiple of $2$. So the numerator and denominator have $2$ as common factor, which contradicts that $n/d$ is in lowest terms. Thus 2, must be irrational.

> [!NOTE] LLM halp
> This was a bit of a clusterfuck for me (maybe tried learning late at night), previous assumptions might be wrong so read from below rather

Claim: $\sqrt{2}$ is irrational, cannot be written as the fraction of two integers.
Review concepts:
1.  Rational: Can be written as $\frac{p}{q}$ where $q$ is not 0.
2. Irrational: Cannot be written this way.
3. Lowest terms of a fraction, when it cant be any longer reduced (e.g $\frac{6}{8}$ is no lower terms but $\frac{3}{4}$ is )

Proof by contradiction is to try and prove that we assume the opposite of our claim, that $\sqrt{2}$ is rational and look for to prove it, so we can write:
$$
\sqrt{2} = \frac{p}{q}
$$
Where $\frac{p}{q}$ is it lowest terms, we can square both sides and isolate:
$$
p^2 = 2q^2
$$
Now we have to make some assumptions on $p^2$:
- It is even since its 2 times something ($2q^2$)
- $p$ must also be even (square of an odd number is odd)

If we write $p = 2k$, for some integer $k$:
$$
(2k)^2 = 2q^2
$$
$$
4k^2 = 2q^2
$$
$$
q^2 = 2k^2
$$

We now can also assume that if $k$ is an integer then $q$ also is even, it means that they are now in its lowest terms, hence we can conclude $\sqrt{2}$ is rational.

#### 1.9 Good Proofs in Practice

A proof should establish the truth of an assertion with absolute certainity, and mechanically checkable proofs of enormous length can accomplish this.
A good proof must also be clear and well structured, as easy to read as possible.
Some general tips on writting good proofs:

1. State your game plan: A good proof begins what explaining the main line of reasoning; "We use case analysis" or "We argue by contradiction".
2. Keep a linear flow: Avoid having to jump to different parts of the proof, keep it easy to follow.
3. Avoid excessive symbolism: Use words instead of symbols whenever you can.
4. Revise and simplify: Readers will be grateful.
5. Introduce notation thoughtfully: Define the meaning of new variables, terms or notations.
6. Structure long proofs: Long programs are usually broken into a hierarchy of small proofs.
7. Be way of the "obvious": Might not be obvious for the reader, avoid words like "clearly" or "obviously".
8. Finish: At some point you will need to draw the conclusion, try to tie all together what you explained.
A bogus proof is a proof that is mostly not correct dure to some failure on reasoning or its correct but not rightly justified.
The analogy for good proofs translates to good programs.

#### Problems for Section 1.1

###### Problem 1.1
Skipping

###### Problem 1.2
See the following claim:

$$
1 = \sqrt{1} = \sqrt{(-1)(-1)} = \sqrt{-1} \sqrt{-1} = (\sqrt{-1})^2 = -1
$$
Can we assume that $1=-1$?

a) Precisely identify and explain the mistake(s) in this bogus proof.

The issue in this bogus proof seems to happen in the following equality:
$$
\sqrt{(-1)(-1)} = \sqrt{-1} \sqrt{-1}
$$
1. The square root of a product its not the product of its squared roots when < 0.
2. The square root of $-1$ is $i$, we get into the complex numbers realm, which is a bit complex.

b) We have to prove that if $1=-1$ then $2 = 1$

We can use some of the logical deductions, we know clearly that the premise is false but its not relevant here.
If we define the proof $P$ as $1=-1$ and $Q$ as $2=1$  and remember the soundness principle:
>This deductions must be *sound*, **which means you can assign truth values that make all the antecedents true must also make the consequent true, A->B is False ONLY if A is True and B is False**

We can write a truth table such as

| P (1=-1) | Q(2=1) | P->Q |
| -------- | ------ | ---- |
| F        | F      | F    |
| F        | T      | F    |
| T        | F      | F    |
| T        | T      | T    |
This feels kind of stupid? But I guess its the danger to start from a (clearly) bad premise that $1=-1$.

c) Every positive real number $r$ has two square roots, positive and negative, prove that  for a positive real number $r$ and $s$, $\sqrt{rs} = \sqrt{r} \sqrt{s}$  the positive root.

We assume $\sqrt{rs} = \sqrt{r} \sqrt{s}$ for  $r,s \geq 0$ and define $X:=\sqrt{rs}$ and $Y:= \sqrt{r} \sqrt{s}$ , where both are $\geq 0$ (a square root of a positive real number will be always 0 or bigger).

Next, we square both $X$ and $Y$:
$$
X^2:= (\sqrt{rs})^2
$$
$$
Y^2:= (\sqrt{r} \sqrt{s})^2 
$$

Which can be then defined on the right as separate squares:

$$
X^2: = rs
$$
And:
$$
Y^2:= rs
$$

So we can prove our initial claim that $X=Y$ so $\sqrt{rs} = \sqrt{r} \sqrt{s}$  **for $r,s \geq 0$.


**Provlem 1.3**

Identify exactly where the bugs are in each of the following proofs

a) Bogus claim: $1/8 > 1/4$

The bogus proof that follows:
$$
3 > 2
$$
$$
3\log_{10}{(1/2)} > 2\log_{10}(1/2)
$$
$$
\log_{10}(1/2)^3 > \log_{10}(1/2)^2
$$
$$
(1/2)^3 > (1/2)^2
$$
$$
1/8 > 1/4
$$

This proof fails to notice that the value of $\log_{10}(r)$ when $r={0...1}$ is negative (all logs between $0$ and $1$  are negative). What happens to an equality (or greater) expression when we multiply both sides for a negative number?
Let $a=2$ and $b=1$ so we can define
$$
a > b = 2 > 1
$$
If we do multiply for $-1$ on both sides though we obtain:
$$
-a > -b = -2 > -1
$$

Which is false, whenever we multiply both sides of an inequality we need to swap the inequality's direction, so:
$$
a > b
$$
When multiplying:
$$
a < b
$$

If we go back to the original example and we sap from the moment logarithms are introduced, we end up with:
$$
3\log_{10}{(1/2)} < 2\log_{10}(1/2)
$$
$$
\log_{10}(1/2)^3 < \log_{10}(1/2)^2
$$
$$
(1/2)^3 < (1/2)^2
$$
$$
1/8 < 1/4
$$

Which holds true.

b) Bogus proof: $1 \textcent =\$0.01 = (\$0.1)^2 = (10\textcent)^2 = 100\textcent = 1\$$ 

This proof is bogus given that we are operating in different units, and in the following step (reversed the equality for comprehension):
$$
($0.1)^2 = $0.01
$$
Whenever doing a square of a number and its units, we need to square the units also, so it should be:
$$
($0.1)^2 = $^2 0.01
$$
 Now the $\$^2$ is a bit confusing and this can seen as false if we maintain just $\$$ in all the process
 $1\textcent = \frac{1}{100}\$ = 0.01\$ = (\$0.1)^2 = (\frac{1}{100})^2\$ = \frac{1}{10000} \$$ 
 And conclude that:
 $$
\frac{1}{10000}$ \neq 1$
$$
c) Bogus Claim: If $a$ and $b$ are two equal real numbers, then $a = 0$

Bogus proof:

$$
a = b
$$
$$
a^2 = ab
$$
$$
a^2 - b^2 = ab - b^2
$$
$$
(a-b)(a+b) = (a-b)b
$$
$$
a+b = b
$$
$$
a = 0
$$
The claim in this bogus proof is easily understood if we pick a value for $a,b$ for example $3$, we develop, the first step which is true
$$
3 = 3
$$
Still fine:
$$
3^2 = 3 \times 3
$$
Still fine after subtracting $b^2$  from both places:
$$
a^2 - b^2 = ab - b^2
$$
Here the equation (split the products and extract common factor) still remains valid:
$$
(a-b)\times(a+b) = (a-b)\times b
$$
The issue comes now when we assume that we can remove $(a-b)$ from both sides (aka divide), this is not valid because if $a=b$ then $(a-b) = 0$ and we cannot divide by 0, so from this point the proof is not valid.

**Problem 1.4**

Is it known that the Arithmetic Mean is at least as large as the Geometric Mean:
$$
\frac{a+b}{2} \geq \sqrt{ab}
$$
for all non negative real numbers a and b, but there is something objectionable about this proof. Whats the objection and how would you fix it?

Bogus proof:
(picture cuz idk how to make the >=?)
![[Pasted image 20250831013651.png]]