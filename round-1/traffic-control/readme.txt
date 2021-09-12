In the rapidly growing towns of Silicon Valley, traffic congestion is becoming a major problem. The governor has contracted Travis, the rock star traffic engineer, to come up with some solutions.
A town consists of NN horizontal streets and MM vertical avenues, making up N*MN∗M intersections. Each intersection has some wait time, which is an integer number of seconds between 11 and 1{,}0001,000, inclusive. The town's wait times can thus be represented as a grid with NN rows and MM columns of integers.
A route within the grid consists of a sequence of one or more intersections, such that each pair of consecutive intersections are either horizontally or vertically adjacent to one another. The duration of a route is the sum of all of its intersections' wait times.
Travis is tasked with assigning valid wait times for all N*MN∗M intersections. However, he must be careful in his choices. Routes too slow will lead to congestion, and routes too fast will lead to accidents. After careful calculations, Travis has determined that that an optimal grid must simultaneously satisfy the following two benchmark conditions based off the four corners of the town:
The duration of the fastest route starting in the top-left intersection and ending in the bottom-right one is exactly AA seconds, and
the duration of the fastest route starting in the top-right intersection and ending in the bottom-left one is exactly BB seconds.
Please help Travis generate any such valid grid, or determine that no such grid exists.
Constraints
1 \le T \le 401≤T≤40
2 \le N, M \le 502≤N,M≤50
1 \le A, B \le 10001≤A,B≤1000
The sum of N*MN∗M across all towns is at most 40{,}00040,000.
Input
Input begins with an integer TT, the number of towns that Travis is contracted for. For each town, there is a single line containing the 44 space-separated integers NN, MM, AA, and BB.
Output
For the iith town, first print a line containing "Case #i: " followed by either the string "Possible" or "Impossible". If possible, this should be followed NN rows of MM space-separated integers each, comprising your chosen grid of intersection wait times in seconds.
Sample Explanation
In the first town, the following is one possible grid for which the minimum durations of routes from the top-left to the bottom-right intersection, as well as from the top-right to the bottom-left intersection, are each equal to 333 + 333 + 333 = 999333+333+333=999 seconds (as required):
  333 333
  333 333
In the second town, the following is one possible grid satisfying the requirements:
  5 3 1
  3 4 3
For example, the fastest route from the top-left to the bottom-right intersection involves moving right, then right, then down, for a total duration of 5 + 3 + 1 + 3 = 125+3+1+3=12 seconds. Meanwhile, the fastest route from the top-right to the bottom-left intersection has a duration of 1 + 3 + 4 + 3 = 111+3+4+3=11 seconds.
For each of the first 33 towns, other outputs would also be accepted.
