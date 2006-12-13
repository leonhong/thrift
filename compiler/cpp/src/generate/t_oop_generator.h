#ifndef T_OOP_GENERATOR_H
#define T_OOP_GENERATOR_H

#include "globals.h"
#include "t_generator.h"

/**
 * Class with utility methods shared across common object oriented languages.
 * Specifically, most of this stuff is for C++/Java.
 *
 * @author Mark Slee <mcslee@facebook.com>
 */
class t_oop_generator : public t_generator {
 public:
  t_oop_generator(t_program* program) :
    t_generator(program) {}

  /**
   * Scoping, using curly braces!
   */

  void scope_up(std::ostream& out) {
    indent(out) << "{" << std::endl;
    indent_up();
  }

  void scope_down(std::ostream& out) {
    indent_down();
    indent(out) << "}" << std::endl;
  }

  /**
   * Generates a comment about this code being autogenerated, using C++ style
   * comments, which are also fair game in Java / PHP, yay!
   *
   * @return C-style comment mentioning that this file is autogenerated.
   */
  std::string autogen_comment() {
    return
      std::string("/**\n") +
      " * Autogenerated by Thrift\n" +
      " *\n" +
      " * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING\n" +
      " */\n";
  }
};

#endif

