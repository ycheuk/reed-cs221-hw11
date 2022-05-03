#include "tournament_deme.hh"
#include "climb_chromosome.hh"
#include "cities.hh"

#include <cassert>



Chromosome* TournamentDeme::select_parent()
{
	// Set the number of slots in the tournament
	int slots = std::pow(2, 7);

	// Create a roster with enough space to house chromosomes
	std::vector<Chromosome*> roster;
	roster.reserve(slots);

	// Fill all available slots in roster at random
	std::uniform_int_distribution<int> range(0, pop_.size() - 1);
	for(int i = 0; i < slots; i++) {
		roster.push_back(pop_.at(range(generator_)));
	}

	// Tournament loop
	// Create a secondary vector to store the victors of each bracket
	std::vector<Chromosome*> nextRound;
	nextRound.reserve(roster.size());
	while(slots > 1) { 	// Progress until their is one victor


		slots = slots / 2;
		// For every 2 chromosomes, pit them against each other 
		// Victor moves on to the next round
		for(long unsigned int i = 0; i < roster.size(); i += 2) {
			auto chromosome1 = roster[i];
			auto chromosome2 = roster[i + 1];
			if(chromosome1 -> get_fitness() >= chromosome2 -> get_fitness()) {
				nextRound.push_back(chromosome1);
			}else {
				nextRound.push_back(chromosome2);

			}
		}

		// Move all victors into the main roster
		roster.swap(nextRound);
		// Clear the secondary vector to store next round's victors
		nextRound.clear();

	}

	// Return the winner of the tournament
	return roster[0];
	
}