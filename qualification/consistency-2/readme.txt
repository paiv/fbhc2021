Note: This problem shares similarities with Chapter 1. The solution to either
chapter may help with solving the other, so please consider reading both first.

Connie received a string S for her birthday, consisting entirely of uppercase
letters (each between "A" and "Z", inclusive).

However, Connie really only likes nice, consistent strings. She considers a
string to be consistent if and only if all of its letters are the same.

Each second, Connie may choose one letter in S and replace it with a different
letter. There are K different types of replacements she may make, with the ith
one involving choosing letter A_i anywhere in S and replacing it with letter
B_i. No type of replacement (ordered pair of A_i and B_i) is given twice. There
is no limit on how many times she may end up using each type of replacement. If
a letter appears multiple times in S, she may only replace a single occurrence
per second.

Help her determine the minimum number of seconds required to change S into any
consistent string, if possible. If it's impossible to ever do so, output −1
instead. Note that S might already be consistent, in which case 0 seconds
would be required.

Constraints

1 ≤ T ≤ 40
1 ≤ ∣S∣ ≤ 100
0 ≤ K ≤ 300
"A" ≤ S_i, A_i, B_i ≤ "Z"
A_i ≠ B_i

The sum of ∣S∣ across all test cases is at most 4,000.

Input

Input begins with an integer T, the number of birthdays Connie has had. For
each birthday, there is one line containing the string S, then another line
containing the integer K, then K more lines, the ith of which contains the
two characters A_i and B_i.

Output

For the ith string, print a line containing "Case #i: " followed by the minimum
number of seconds required to change S into any consistent string, or −1 if
it's impossible to do so.

Sample Explanation

In the first case, Connie could replace the second and third letters ("B" and
"C") each with "A", yielding the string "AAA" in 2 seconds.

In the second case, Connie cannot apply either available type of replacement to
"ABC", meaning that she cannot change it into a consistent string.

In the third case, "F" is already consistent.

In the fourth case, Connie could replace the first, third, and fifth letters
("B", "N", and "N") each with "A", yielding the string "AAAAAA" in 3 seconds.

In the sixth case, Connie could change "FOXEN" into the string "WWWWW" in 88
seconds. Note that she may apply a sequence of multiple replacements to any of
the letters in S.
