Note: This problem shares similarities with Chapters 1 and 3. The solution to any chapter may help with solving the others, so please consider reading all of them first.
Timmy the toddler is training to be a top typist. His teacher has assigned some homework in the form of a list of TT string exercises to be typed, consisting of only the uppercase letters "F", "O", and "X".
Timmy is eating a popsicle on a hot summer afternoon, but still hopes to complete his homework. He would like to hold the popsicle with one hand, and type with the other. Unfortunately, Timmy is still a growing boy, and each of his hands is a tad too small to reach all the way across the keyboard. He can only reach the letters "F" and "X" with his left hand, and the letters "F" and "O" with his right.
Consider a string WW which Timmy must type. Timmy may start typing with any hand of his choice (with the other holding the popsicle). He must then switch hands as necessary to type out the |W|∣W∣ letters in order, ending on any hand of his choice.
Let F(W)F(W) be the minimum number of times Timmy must switch hands to type such a string WW.
Given an exercise string SS of length NN, let G(S)G(S) be the sum of F(W)F(W) over all substrings WW of SS. Note that there are N*(N+1)/2N∗(N+1)/2 such substrings. Please help Timmy compute the value of G(S)G(S) modulo 1{,}000{,}000{,}0071,000,000,007.
Constraints
1 \le T \le 751≤T≤75
1 \le N \le 800{,}0001≤N≤800,000
Each string consists only of the letters "F", "O", and "X".
The sum of NN across all exercises is at most 4{,}000{,}0004,000,000.
Input
Input begins with an integer TT, the number of exercises that Timmy has been assigned. For each exercise, there is first a line containing the single integer NN, followed by a second line containing the string SS of length NN.
Output
For the iith exercise, output a line containing "Case #i: " followed by a single integer, G(S)G(S) modulo 1{,}000{,}000{,}0071,000,000,007.
Sample Explanation
In the first exercise, the only substring of "O" is "O" itself. F(``O") = 0F(‘‘O")=0, as if Timmy begins with his right hand, he can type "O" without needing to switch to his left hand. The answer is therefore 00 modulo 1{,}000{,}000{,}007 = 01,000,000,007=0.
In the second exercise, there are 66 substrings to consider: "X", "F", "O", "XF", "FO", and "XFO". FF has a value of 00 when evaluated on any of the first 5 of these, while F(``XFO") = 1F(‘‘XFO")=1, as if Timmy begins with his left hand, he can type all 33 letters in order with 11 hand switch (for example, by switching to his right hand after typing the first letter). The answer is therefore (0 + 0 + 0 + 0 + 0 + 1)(0+0+0+0+0+1) modulo 1{,}000{,}000{,}007 = 11,000,000,007=1.
In the third exercise, FF has a value of 00 when evaluated on any of the 1515 substrings of "FFOFF", as Timmy can type each of them using only his right hand.
In the fourth exercise, FF has a value of 00 for 2929 of the substrings of SS, a value of 11 for another 1616 of them, and a value of 22 for the remaining 1010 of them. The answer is therefore (0 * 29 + 1 * 16 + 2 * 10)(0∗29+1∗16+2∗10) modulo 1{,}000{,}000{,}007 = 361,000,000,007=36.
