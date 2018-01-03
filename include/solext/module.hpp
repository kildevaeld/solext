#pragma once
#include <sol/sol.hpp>
/*
namespace sol {
class state_view;
class table;
} // namespace sol*/

namespace solext {

#define E_MODULE                                                               \
public:                                                                        \
  static const char *module_name();

#define E_REGISTER_MODULE(SETTINGS_CLASS, GROUP_NAME)                          \
  const char *SETTINGS_CLASS::module_name() { return GROUP_NAME; }

class Module {

public:
  Module(sol::state *state) : m_state(state) {}
  virtual ~Module() {}

  virtual void register_module(sol::table &table) = 0;

  sol::state &vm() const { return *m_state; }

private:
  sol::state *m_state;
};
}