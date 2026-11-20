#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

const STram::MenuItem STram::UNIV_SPBU_PMPU = {
  "1 - Факультет ПМ-ПУ", STram::univ_spbu_pmpu, &STram::UNIV_SPBU
};
const STram::MenuItem STram::UNIV_SPBU_MATMEH = {
  "2 - Факультет МатМех", STram::univ_spbu_matmeh, &STram::UNIV_SPBU
};
const STram::MenuItem STram::UNIV_SPBU_LINGV = {
  "3 - Лингвистический факультет", STram::univ_spbu_lingv, &STram::UNIV_SPBU
};
const STram::MenuItem STram::UNIV_SPBU_GO_BACK = {
  "0 - Выйти в предыдущее меню", STram::go_back, &STram::UNIV_SPBU
};

namespace  {
  const STram::MenuItem* const univ_spbu_children[] = {
    &STram::UNIV_SPBU_GO_BACK,
    &STram::UNIV_SPBU_PMPU,
    &STram::UNIV_SPBU_MATMEH,
    &STram::UNIV_SPBU_LINGV
  };
  const int univ_spbu_size = sizeof(univ_spbu_children) / sizeof(univ_spbu_children[0]);
}

const STram::MenuItem STram::UNIV_SPBU = {
  "1 - СПБГУ", STram::show_menu, &STram::UNIV, univ_spbu_children, univ_spbu_size
};
const STram::MenuItem STram::UNIV_ITMO = {
  "2 - ИТМО", STram::univ_itmo, &STram::UNIV
};
const STram::MenuItem STram::UNIV_SPBPU = {
  "3 - Политех", STram::univ_spbpu, &STram::UNIV
};
const STram::MenuItem STram::UNIV_LETI = {
  "4 - ЛЭТИ", STram::univ_leti, &STram::UNIV
};
const STram::MenuItem STram::UNIV_GO_BACK = {
  "0 - Выйти в главное меню", STram::go_back, &STram::UNIV
};

namespace {
  const STram::MenuItem* const univ_children[] = {
    &STram::UNIV_GO_BACK,
    &STram::UNIV_SPBU,
    &STram::UNIV_ITMO,
    &STram::UNIV_SPBPU,
    &STram::UNIV_LETI
  };
  const int univ_size = sizeof(univ_children) / sizeof(univ_children[0]);
}

const STram::MenuItem STram::UNIV = {
  "1 - Посмотреть университеты Санкт-Петербурга", STram::show_menu, &STram::MAIN, univ_children, univ_size
};
const STram::MenuItem STram::STUD_ALR = {
  "0 - Я уже студент", STram::exit, &STram::MAIN
};

namespace {
  const STram::MenuItem* const main_children[] = {
    &STram::STUD_ALR,
    &STram::UNIV
  };
  const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

//STram::MenuItem STram::MAIN = {
//  nullptr, STram::show_menu, nullptr, main_children, main_size
//};
