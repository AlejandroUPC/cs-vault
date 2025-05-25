
tags: [weekly-session, c50, week 0] 

---

# Week 0

Scratch, intro week. Too much show imo.

## 📚 Notes

- Notes:
  -  CS -> Study of information how to process and represent it, its just problem solving thinking computationally.
  -  input -> computer -> output.
  -  Information can be presented in multiple ways (example of hand)
  - BITS (represent number)
	  - Unary -> 5
	  - Biggest is 31 doing base 2 (binary), what computers use.
	  - bit -> binary digit 1/0.
	  - In computers this is done using electric current (transistors) that go on and off to store information (like bulbs, does example with 3 bulbs, 2^n ).
	  - Bits grouped in a byte = 8 bits (from 128 to 1 -> 256 values incl 0).
	  - Ternary computers use three values instead of two.
  - Represent letters
	  - map letters to numbers A -> 01000001 = 65
	  - lower case changes
	  - They are contiguous A -> 65, B -> 66.
	  - ASCII had initially only 8 bits (256 characters), enough for english and some others.
	  - ASCII is not enough for all languages, 32 bits is 4 (american)billion characters is unicode.
	  - Unicode is backwards compatible w/ ASCII, all past and future language (even emojis).
  - RGB; representing colors
	  - Every pixel has allocated a series of bits, 3 bytes (0-255) to combine the single color of a pixel.
  - Music
	  - Similar to ASCII letters, a sequence of bits representing a sound with additional information:
		  - peach, volume and duration (similar to RGB, 3 bytes) for example.
  - Information is just 1 and 0, the interpretation is what matters 
- Algorithms
	- A precise (finite) description on how to do something.
	- E.g for a phonebook
		- Look for someone step by step (page per page), eventually ends and finds someone you are looking for, not efficient.
		- Double the pace, will go faster but you could miss.
		- How this actually works in your phone, assuming the phonebook is ordered alphabetically (assume we look for a J) is it will open the book in the middle, M, and see if he has to go left or right, (left in this case) and throw the non used side, and iteratively do the same until reaching the person in J. Keep dividing and for 1000 items you can divide up to around 2^9 times, so in 9 steps you could find the person.
		- Time requiered to solve problems is always a metric to optimize (closer to 0).
		- The first algorithm (page per page) shown as n, the one we start from the middle is n/2 (where n is the number of pages scanned), to keep dividing is log2(n)
		  ![[Pasted image 20250406135013.png]]
		- The pseudocde would be:
			- 1. Pick phonebook
			- 2.Open by n/2 pages
			- 3.look page
				- 3.1person found
					- call
				- 3.1look current letter and pick the n/2 where the half is (aka point 2)
			- 4. if not found after all pages, exit.
	- branching -> if/else
	- boolean true(1)/false(0)
	- dude says divide and conquer(no spoiler) 10000 times.
	- A.I
		- LLMS -> neural networks -> "just" statistics and probability.
	- Rubber duck history, talk to the duck and ask questions, the mirror act of explaining could provide some clarity.
	- I am not going to do the scratch stuff
	- 
---