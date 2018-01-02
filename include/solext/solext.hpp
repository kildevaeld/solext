#pragma once
#include <sol/sol.hpp>

namespace solext {

class Module;

namespace internal {
class StatePrivate;
}

class State : public sol::state {

public:
  State();
  State(int argc, const char **args);
  ~State();

  template <typename T> void add_module() {
    std::string name = T::module_name();
    add_module(name, new T(this));
  }

  void add_module(const std::string &name, Module *module);
  void add_module(const std::string &name, const std::string &module);

protected:
  void init_process_object();

private:
  std::unique_ptr<internal::StatePrivate> d;
};

} // namespace solext