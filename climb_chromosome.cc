#include <cassert>

#include "climb_chromosome.hh"

void ClimbChromosome::mutate(){
  std::uniform_int_distribution<int> dist(0, order_.size()-1);
  auto fitness1 = get_fitness(); 

  long unsigned int parent1 = dist(generator_);
  long unsigned int parent2 = parent1 - 1;
  if (parent1 == 0){
    parent2 = order_.size()-1;
  }
  std::swap(order_[parent1], order_[parent2]);

  auto fitness2 = get_fitness();
  std::swap(order_[parent1], order_[parent2]);
  auto parent3 = parent1 + 1;
  if (parent1 == order_.size()-1){
    parent3 = 0;
  }
  std::swap(order_[parent1], order_[parent3]);

  auto fitness3 = get_fitness();
  if (fitness1 > fitness2){
    if(fitness1 > fitness3){
      std::swap(order_[parent1], order_[parent3]);
    }
  }
  else{
    if(fitness2 > fitness3){ 
      std::swap(order_[parent1], order_[parent2]);
      std::swap(order_[parent1], order_[parent3]);
    }
  }
}

