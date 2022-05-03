# HW11: TSP Project Part 3 (advanced GA operators)
By [Vaughn Zaayer](https://github.com/vaughnzaayer) and [Yik Yin Cheuk](https://github.com/ycheuk)
<br />
**Note**: If you see the user "AnastasiyaV" it's me (Yik Yin)!! It's just my laptop / English name that nobody knows about!
## climb_chromosome
- Mutated based on their performance. 

## tournament_deme
- Select parents based on a tournament.
- Overwrites select_parent()
Selects a factor of two (currently 2^7) for the number of starting slots in the tournament. After filling the tournament with random chromosomes from the pop_, every 2 chromosomes will be compared to each other, with the fitter chromosome moving to the next round. The comparisons are repeated until there is only 1 victor remaining, which is returned.

# HOW TO COMPILE
- Open the directory in a terminal and type "make" to compile tsp
- To run tsp, use ./tsp {.tsv file} {Starting Population} {Mutation Rate}
- Use "make clean" to remove tsp executable and all object files