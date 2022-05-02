#include "tournament_deme.hh"
#include "climb_chromosome.hh"
#include "cities.hh"

Chromosome* TournamentDeme::select_parent()
{
	// Find the power of 2 that accommodates the most parents
	int base = 1;
	while(std::pow(base, 2) <= pop_.size()) {
		base = std::pow(base, 2);
	}

	// Randomly select enough parents to fit into the tournament
	std::vector<*Chromosome> tournamentBracket;
	tournamentBracket.reserve(base);

	for(auto i; i < base; i++) {
		std::uniform_int_distribution<int> range(0, pop_.size());
		tournamentBracket.push_back(pop_.at(range(generator_)));
	}

	// Compare every 2 chromosomes, moving the more fit one up in the tournament
	for(auto i; i < tournamentBracket.size(), i+=2) {
		auto chromosome1 = tournamentBracket[i];
		auto chromosome2 = tournamentBracket[i + 1];

		if(chromosome1 -> get_fitness() >= chrom)
	}

}