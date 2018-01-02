#include <csystem/csystem++.hpp>
#include <solext/module.hpp>
#include <solext/solext.hpp>

extern char **environ;

namespace solext {

namespace internal {
class StatePrivate {

public:
  StatePrivate(const char **a, int c) : argv(a), argc(c) {}

  std::vector<std::unique_ptr<Module>> modules;
  const char **argv = nullptr;
  int argc;
};
} // namespace internal

State::State() : State(0, nullptr) {}
State::State(int argc, const char **args)
    : sol::state(), d(new internal::StatePrivate(args, argc)) {
  init_process_object();
}
State::~State() {}

void State::add_module(const std::string &name, Module *module) {
  sol::table package = this->globals()["package"];
  sol::table preload = package["preload"];
  preload.set_function(name, [this, module]() {
    auto table = this->create_table();
    module->register_module(table);
    return table;
  });

  d->modules.push_back(std::unique_ptr<Module>(module));
}

void State::add_module(const std::string &name, const std::string &module) {
  sol::table package = this->globals()["package"];
  sol::table preload = package["preload"];
  preload.set_function(name, [this, module]() {
    auto table = this->script(module);
    return table;
  });
}

void State::init_process_object() {
  auto globals = this->globals();

  auto table = globals.create_named("process");

  // table["hostname"] = uvw::Utilities::OS::hostname();
  // table["homedir"] = uvw::Utilities::OS::homedir();
  // table["tmpdir"] = uvw::Utilities::OS::tmpdir();
  table.set_function("homedir", &csystem::standardpaths::home);
  table.set_function("tmpdir", &csystem::standardpaths::tmpdir);

  if (d->argv) {
    table["argv"] = std::vector<std::string>(d->argv, d->argv + d->argc);
  } else {
    table.create_named("argv");
  }

  /*int i = 1;
  char *s = *environ;
  for (; s; i++) {
    printf("%s\n", s);
    s = *(environ + i);
  }*/

  // table.set_function("cwd", &uvw::Utilities::cwd);
}

} // namespace solext