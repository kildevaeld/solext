#include <solext/solext.hpp>

int main(int argc, const char **argv) {
  solext::State state(argc, argv);

  state.open_libraries(sol::lib::base);

  state.script("print(process.homedir()); print(process.argv[1])");

  return 0;
}