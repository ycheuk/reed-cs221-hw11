#pragma once

# include "deme.hh"

class TournamentDeme : public Deme{
public:
  TournamentDeme(const Cities* cities_ptr, unsigned pop_size, double mut_rate);
  ~TournamentDeme();

protected:
  virtual Chrmosome* select_parent();
};
