#includ <cassert>

#include "climb_chromosome.hh"

void
ClimbChromosome::mutate()
{
  static std::uniform_int_distribution<usigned> dist(0, order_.size() - 1);
  auto fitness = get_fitness();

  const int idx = dist(generator_);
  const int prev = idx > 0? idx - 1 : order_.size() - 1;
  const int next = (idx + 1) % (order_.size() - 1);

  // Swap with prev first:
  std::swap(order_[idx], order_[prev]);
  if (fitness > get_fitness()) { //the swap worsend the fitness, then undo
    std::swap(order_[idx], order_[prev]);
  } else {
    fitness = get_fitness();
  }
  // Now swap with next:
  std::swap(order_[idx], order_[next]);
  if (fitness > get_fitness()) {
    std::swap(order_[idx], order_[next]);
  }
  assert(is_valid());
}
