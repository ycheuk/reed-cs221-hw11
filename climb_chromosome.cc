#includ <cassert>

#include "climb_chromosome.hh"

void ClimbChromosome::mutate(){
  std::uniform_int_distribution<int> dist(0, order_.size()-1);
  auto fitness = get_fitness();

  long unsigned int parent1 = dist(generator_);
  long unsigned int parent2 = parent1 - 1;

  std::swap(order_[parent1], order_[parent2]);
}
