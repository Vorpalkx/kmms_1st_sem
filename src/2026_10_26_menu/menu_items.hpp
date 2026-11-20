#pragma once

#include "menu.hpp"
#include "menu_functions.hpp"

namespace STram {
  MenuItem MAIN = {
    nullptr, STram::show_menu, nullptr
  };

  extern const MenuItem UNIV;
  extern const MenuItem STUD_ALR;

  extern const MenuItem UNIV_SPBU;
  extern const MenuItem UNIV_ITMO;
  extern const MenuItem UNIV_SPBPU;
  extern const MenuItem UNIV_LETI;
  extern const MenuItem UNIV_GO_BACK;

  extern const MenuItem UNIV_SPBU_PMPU;
  extern const MenuItem UNIV_SPBU_MATMEH;
  extern const MenuItem UNIV_SPBU_LINGV;
  extern const MenuItem UNIV_SPBU_GO_BACK;
}
