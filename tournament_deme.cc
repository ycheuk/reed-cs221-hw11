#include "tournament_deme.hh"
#include "climb_chromosome.hh"
#include "cities.hh"

#include <cassert>



Chromosome* TournamentDeme::select_parent()
{
	// Set the number of slots in the tournament
	int slots = std::pow(2, 5);	

	std::vector<Chromosome*> roster;
	roster.reserve(slots);

	// Fill all available slots in roster
	std::uniform_int_distribution<int> range(0, pop_.size() - 1);
	for(int i = 0; i < slots; i++) {
		roster.push_back(pop_.at(range(generator_)));
	}

	// Tournament loop
	std::vector<Chromosome*> nextRound;
	nextRound.reserve(roster.size());
	while(slots > 1) {


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

		roster.swap(nextRound);
		nextRound.clear();

	}

	std::cout << roster[0] << std::endl;
	return roster[0];
	
}