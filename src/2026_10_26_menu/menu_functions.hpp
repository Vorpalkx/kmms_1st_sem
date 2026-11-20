#pragma once

#include "menu.hpp"

namespace STram {
  const MenuItem* show_menu(const MenuItem* current);

  const MenuItem* exit(const MenuItem* current);

  const MenuItem* univ_leti(const MenuItem* current);
  const MenuItem* univ_spbpu(const MenuItem* current);
  const MenuItem* univ_itmo(const MenuItem* current);
  const MenuItem* univ_spbu_lingv(const MenuItem* current);
  const MenuItem* univ_spbu_matmeh(const MenuItem* current);
  const MenuItem* univ_spbu_pmpu(const MenuItem* current);
  const MenuItem* go_back(const MenuItem* current);
}
