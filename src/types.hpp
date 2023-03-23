#ifndef STYOCKCPP_COMPILER_SRC_TYPES_HPP_
#define STYOCKCPP_COMPILER_SRC_TYPES_HPP_
#include <stack>
#include <vector>
#include <memory>

class iCommand;
class iCompiler;

using spp_stack = std::stack<int, std::vector<int>>;
using spp_command_ptr = std::unique_ptr<iCommand>;
using spp_compiler_ptr = std::unique_ptr<iCompiler>;

#endif