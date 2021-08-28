You're playing a game against an opponent on a grid of cells with N rows and N
columns. All of the cells are initially empty, and both players normally take
turns placing symbols in empty cells (with one player placing Xs and the other
placing Os) until a row and/or column becomes entirely filled with one player's
symbols (at which point the game ends with that player winning) or all of the
cells have been filled without either player winning (in which case the game
ends in a draw). Note that a player filling an entire diagonal with their
symbols does not cause them to win.

This particular game is in the process of being played, with you placing Xs and
your opponent placing Os. The current state of the cell in the ith row from the
top and jth column from the left is one of the following: If C_{i,j} = ".", the
cell is still empty If C_{i,j} = "X", an X has been placed in the cell
Otherwise, if C_{i,j} = "O", an O has been placed in the cell

In the game's current state, both players have made an equal number of turns (in
other words, the number of Xs is the same as the number of Os), neither player
has won yet, and the game has not yet ended in a draw (meaning that at least one
cell is still empty).

Your opponent has just turned their back, giving you the opportunity to
immediately place as many additional Xs on the board as you'd like, in any set
of empty cells. Determine the minimum number of additional Xs you must place
such that placing them would cause you to immediately win (due to a row and/or a
column becoming entirely filled with Xs), if this is possible at all. If it is
possible, you should also determine the number of different sets of cells in
which those Xs could be placed. Two sets of cells are considered to be different
if either of them includes at least one cell which the other doesn't.

Constraints
1 ≤ T ≤ 70
2 ≤ N ≤ 50
C_{i,j} ∈ {., X, O}

The sum of N across all test cases is at most 2,000.

Input

Input begins with an integer T, the number of games you play against your
opponent. For each game, there is first a line containing the integer N. Then,
N lines follow, the ith of which contains the N characters C_i,1..N

Output

For the ith string, print a line containing "Case #i: " follow by "Impossible"
if you cannot immediately win, or two integers if you can: the minimum number of
additional Xs you must place to do so, and the number of different sets of cells
in which those Xs could be placed.

Sample Explanation

In the first case, there's one way to place just 1 additional X and win. You
can place it in the bottom-left corner (thus filling the entire left column):

  XO
  X.

In the second case, there are two possible ways to place 1 additional X and win:

  X.  XX
  XO  .O

In the third case, you'll need to place 3 Xs to win, and you could choose any
of the following 6 sets of cells to place them in:

  XXX  ...  ...  X..  .X.   ..X
  ...  XXX  ...  X..  .X.   ..X
  ...  ...  XXX  X..  .X.   ..X

In the fourth case, you could place 2 additional Xs to form either of the
following 2 configurations:

  XOX  .OX
  X..  XXX
  X.O  ..O

In the sixth case, even if you place Xs in all 3 remaining empty cells, you
cannot win.
