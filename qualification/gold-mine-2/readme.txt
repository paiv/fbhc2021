Note: This problem shares similarities with Chapter 1. The solution to either
chapter may help with solving the other, so please consider reading both first.

Just like logging, mining is a key industry in Canada's primary sector.
Prospectors use geological tools to find ore deposits, then drill, and blast to
excavate a system of underground tunnels for access to the ores.

Minerva is a contract miner who spends her days extracting gold ore from
underground mines across Ontario. One particular gold mine she's contracting for
consists of N underground caves, numbered from 1 to N, with cave 1 having an
exit to the surface. There are also N−1 tunnels running among the caves, the ith
of which allows one to travel in either direction between caves A_i and B_i.
Each cave is reachable from cave 1 by a sequence of these tunnels.

Cave i is known to contain C_i ounces of gold ore. With her trusty dump truck,
Minerva plans to drive underground starting in cave 1, collect as much gold ore
as possible, and exit back to the surface through cave 1.

There's just one issue: the tunnels are highly unstable, and will cave in after
Minerva drives through them. Therefore, she is only able to traverse each tunnel
at most once. Fortunately, the caves themselves are reinforced with pillars and
will never collapse — she may visit each cave any number of times (though she
can only collect its gold ore at most once).

This safety measure may limit mobility. Thankfully, Minerva's truck is also
equipped to be a drill rig. As she travels through the system of caves, she may
at any point use it to travel from her current cave to any other cave by
drilling a new tunnel. In this chapter, the rig only has the energy to drill at
most K such tunnels. Unfortunately, these new tunnels will be just as unstable
as the existing ones — Minerva will only dare travel through each new tunnel
once.

Please help Minerva determine the maximum weight of gold ore that can be
collected if she begins in cave 1, spends any amount of time exploring the mine
(traveling through tunnels, drilling at most K new tunnels, and collecting ore
from any visited caves), and end up once again in cave 1.

Constraints

1 ≤ T ≤ 30
1 ≤ N ≤ 50
0 ≤ K ≤ 50
0 ≤ C_i ≤20,000,000
1 ≤ A_i, B_i ≤ N

The sum of N across all mines is at most 1,000.

Input

Input begins with an integer T, the number of mines that Minerva is contracted
to work. For each mine, there is first a line containing the space-separated
integers N and K. Then, there is a second line containing N space-separated
integers, C_{1..N}. Then, N−1 lines follow, the ith of which contains the
space-separated integers A_i and B_i.

Output

For the ith mine, output a line containing "Case #i: " followed by a single
integer, the maximum weight of gold ore (in ounces) that Minerva can collect
before leaving the mine.

Sample Explanation

The first mine looks as follows:

1.jpg

It's possible to visit both caves (collecting 30 ounces of ore) and then
return to cave 1, for example by taking the tunnel from cave 1 to cave 2 and
then drilling a tunnel back to cave 1.

In the second mine, the system of caves is the same, but with no ability to
drill, Minerva cannot afford to travel to cave 2 (as she would become stuck
there) and must settle for only collecting 10 ounces of ore from cave 1.

The third mine looks as follows:

3.jpg

It's possible to end up with 3 ounces of ore, but Minerva cannot collect all 4
ounces while still returning to cave 1 and only drilling one tunnel.

In the fourth mine, the system of caves is the same, but with the ability to
drill twice, Minerva can collect ore from all 4 caves. For example, she can take
the tunnel to cave 3, drill to travel to cave 2, drill again to travel to cave
4, and finally take the tunnel back to cave 1.
