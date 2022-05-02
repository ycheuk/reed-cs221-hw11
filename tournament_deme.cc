#include "tournament_deme.hh"
#include "climb_chromosome.hh"
#include "cities.hh"

void TournamentDeme::compute_next_generation() 
{
	// Initialize a new vector with half the space as the old vector
	std::vector<Chromosome*> newPop;
	newPop.reserve(pop_.size() / 2);

	static std::uniform_real_distribution<double> dist(0.0, 1.0);

	for(unsigned i = 0; i < pop.size()/2; i++) {
		auto parent1 = select_parent();
		auto parent2 = select_parent();
	}

}
