
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

The **Fermat's Last Theorem** has a proposition that $x^n + y^n = z ^2 for n>1$.  Took a while and this was proven to hold true for values up to 4.000.000 (but we cannot trust a limited sample, see Eulre's case that ended up being false) ended up being proved as true and became a Theorem.

The **Goldbach Conjecture** says that every integer greater than 2 is the sum of two primes, from 1742 holds true for all numbers up to $10^{18}$, up to this day no one can prove it.

In the computer world the most important things to prove are usually the correctness of programs and systems (whether if they do what they are supposed to do).

#### 1.2 Predicates
A proposition whoe truth depends on the value of one or more variables, n is a perfect square is a  predicate, but it depends on its values (4-> ok, 5->nok), they follow the notation $P(n) ::=$ "n is a perfect square


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
ZFC are important for studying and justifying the foundations of mats but too primitive as well, in computer science can be understood as writing byte code instead of a scripting language, where the formal ZFC proof of $2+2=4$ is 20.000 steps, so we accept a lot of axioms when proving.

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

In order to prove that P IMPLIES q:
1. Write, "Assume P"
2. Show that Q logically follows

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
So with this table it should be enough, but lets refactor a little bit by refactoring the relevant terms:
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
$\sqrt{r}=\frac{m}{n}$ if we square we get $r=\frac{m^2}{n^2}$ , so since $m$ and $n$ are integers(square of integers is always an integer), $r$ is also rational as we defined it as a division of integers (rational) 