#pragma once
#include "cities.hh"
#include "chrmosome.hh"

class ClimbChromosome : public Chrmosome {
public:
  ClimbChrmosome(const Cities* cities_ptr) : Chrmosome(cities_ptr){}

  virtual ~ClimbChermosome() = default;

  virtual void mutate() override;

  virtual Chrmosom e* clone() const override
  {
    return new ClimbChrmosome(cities_ptr);
  }
};
