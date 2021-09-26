TFW it's Toronto Fashion Week. There are T fashion shows to be held, during
which runway models will showcase the latest outfits from top designers. Dorothy
the dresser has been designated the difficult duty of dressing them all!

A given fashion show features M models wearing a variety of outfits. Each outfit
has a style, denoted by a positive integer. Before the show begins, each model i
is required to arrive at the venue wearing an outfit of style S_i.

Then, N rounds will follow. A round consists of a lineup of the M models walking
the runway in turn, each showcasing an outfit. The ordering of models can differ
among different rounds' lineups, but must be some permutation of the same M
models each time. The show also has a predetermined program: the jth outfit
showcased in the ith round's lineup must be of style P_{i,j}.

Dorothy's job is to dress all of the models backstage, in accordance to the
program requirements. A model's outfit may be changed into one of any other
style, at any time while the model is not on the runway.

Being resourceful, Dorothy came up with a small trick to make her job less
hectic: She can instruct each model to wear another outfit underneath the
initial outfit they arrive in, making it easy for the model to change into a
different style, just once, without Dorothy's help. In other words, if a model
needs to change n different times throughout the entire show, then Dorothy will
only need to personally change the model max(n−1,0) times.

Now, Dorothy would like to organize models for each round to minimize her own
work. Can you help determine the minimum total number of times that Dorothy will
need to personally change a model, while satisfying the program requirements for
all N rounds?

Constraints

1 ≤ T ≤ 70
1 ≤ N,M ≤ 1,000,000
1 ≤ N*M ≤ 1,000,000
1 ≤ S_i,P_{i,j} ≤ 10^9

The sum of N*M across all test cases is at most 5,000,000.

Input

Input begins with an integer T, the number of fashion shows. For each show, there is first a line containing the space-separated integers N and M. Then, there is a line containing M space-separated integers, S_{1..M}S. Then, N lines follow, the ith of which contains M space-separated integers, P_{i,1..M}.

Output

For the ith fashion show, output a line containing "Case #i: " followed by a
single integer, the minimum number of times that Dorothy must personally change
the models.

Sample Explanation

In the first show, there are 3 rounds with only 1 model. The model is initially
wearing style 1, and the program requires styles [2,2,1] to be showcased in
sequence. Dorothy can direct the model to arrive wearing style 2 underneath
style 1, so that it may be uncovered before round 1 with no work from Dorothy
herself. After the model does so and showcases style 2 for the first two rounds,
Dorothy will have to personally change the model back into style 1 for round 3.

In the second show, there are 4 rounds and 2 models. The models arrive wearing
styles 1 and 11, respectively. The program requires each round to showcase
styles 1 and 11 in alternating order. The models can simply alternate positions
from round to round, requiring no work from Dorothy.

In the third show, the two models arrive wearing styles 1 and 11, respectively,
but 8 other different styles then need to be showcased (4 by each model). Each
model can change into 1 more style by wearing it underneath their initial
outfit, but Dorothy will have to personally change them for the remaining 3
each, for a total of 6.

In the fourth show, one possible optimal way to organize the fashion show is as follows:

Initially, model 1 wears style 30 underneath style 10, model 2 wears style 30
underneath style 20, and model 3 wears style 10 underneath style 20.

For round 1, the models go in order [2,1,3]. Models 2 and 1 already fit the
program, while model 3 changes into style 10 independently.

For round 2, keep the same lineup. Models 2 and 1 each change themselves into
style 30, while Dorothy personally changes model 3 into style 20.
