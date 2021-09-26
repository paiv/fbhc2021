Note: This problem shares similarities with Chapter 2. The solution to either
chapter may help with solving the other, so please consider reading both first.

When not out fighting crime, Shaun works valet at the Fairmont hotel. Recently,
he has been using his new weapon – the ten rings – to secretly help him park
cars among T valet-designated garages.

The layout of a garage is a grid G of R rows (numbered from 1 to R from top to
bottom) and C columns (numbered from 1 to C from left to right) of parking
spaces. Initially, each space in row i and column j contains a car if G_{i,j} =
"X", or is otherwise empty (if G_{i,j} = ".").

Shaun has been tasked to clear out a path for easy garage access, requiring cars
to be rearranged such that a certain row K contains no cars in any of its C
spaces. To that end, the magic of the ten rings supports the following 3 types
of moves:

Levitate any car out of the garage and onto the street, leaving its space empty
(and the position of all other cars unchanged).

Shift all the cars in the garage upwards. For each car in the garage, it moves
from its current parking space to the space just above it, unless there's either
no such space (due to the car being in row 1) or that space is occupied by a
car which is remaining stationary, in which case this car itself remains
stationary.

Shift all the cars in the garage downwards (similarly to #2).

For example, a sequence of two moves of type #2 is illustrated below:

  X..   XXX   XXX
  .XX   ..X   XXX
  ..X   XXX   ..X
  XXX   ...   ...

Please help Shaun determine the minimum number of moves required to clear all
the spaces in row K.

Constraints

1 ≤ T ≤ 55
1 ≤ R,C ≤ 2,000,000
R*C ≤ 2,000,000
1 ≤ K ≤ R
G_{i,j} ∈ {".", "X"}

The sum of R*C across all garages is at most 10,000,000.

Input

Input begins with an integer T, the number of garages in which Shaun must clear
a path. For each garage, there is first a line containing 3 space-separated
integers R, C, and K. Then, R lines follow, the ith of which contains the C
characters G_{i,1..C}.

Output

For the ith garage, print a line containing "Case #i: " followed by a single
integer, the minimum number of moves required to clear row K.

Sample Explanation

In the first garage, there is a single occupied space which must be cleared.
Shaun can simply execute a move of type #1 to clear it.

In the second garage, row 2 is already cleared as required, so no moves are needed.

In the third garage, one optimal strategy is for Shaun to use a move of type #1
to remove the car in row 1 and column 2, followed by a move of type #3 to shift
all cars downwards, resulting in the following valid arrangement:

  ...
  XXX
  XXX

In the fourth garage, one optimal strategy is for Shaun to use a single move of
type #2, resulting in the following valid arrangement:

  XXX
  ..X
  XXX
  ...
