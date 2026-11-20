#include "menu_functions.hpp"

#include <iostream>
#include <cstdlib>

const STram::MenuItem* STram::show_menu(const MenuItem* current) {
  for (int i = 1; i < current->children_count; i++) {
    std::cout << current->children[i]->title << std::endl;
  }
  std::cout << current->children[0]->title <<std::endl;
  std::cout << " > ";

  int user_input;
  std::cin >> user_input;
  std::cout << std::endl;

  return current->children[user_input];
}
const STram::MenuItem* STram::exit(const MenuItem* current) {
  std::exit(0);
}
const STram::MenuItem* STram::univ_leti(const MenuItem* current) {
  // TODO
  std::cout << current->title << std::endl;
  return current->parent;
}
const STram::MenuItem* STram::univ_spbpu(const MenuItem* current) {
  // TODO
  std::cout << current->title << std::endl;
  return current->parent;
}
const STram::MenuItem* STram::univ_itmo(const MenuItem* current) {
  // TODO
  std::cout << current->title << std::endl;
  return current->parent;
}
const STram::MenuItem* STram::univ_spbu_lingv(const MenuItem* current) {
  // TODO
  std::cout << current->title << std::endl;
  return current->parent;
}
const STram::MenuItem* STram::univ_spbu_matmeh(const MenuItem* current) {
  // TODO
  std::cout << current->title << std::endl;
  return current->parent;
}
const STram::MenuItem* STram::univ_spbu_pmpu(const MenuItem* current) {
  // TODO
  std::cout << current->title << std::endl;
  return current->parent;
}
const STram::MenuItem* STram::go_back(const MenuItem* current) {
  // TODO
  std::cout << current->title << std::endl;
  return current->parent->parent;
}
