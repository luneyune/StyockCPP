#ifndef STYOCKCPP_COMPILER_SRC_TYPES_HPP_
#define STYOCKCPP_COMPILER_SRC_TYPES_HPP_
#include <stack>
#include <vector>
#include <memory>
#include <unordered_map>

class iCommand;
class iCompiler;

using spp_stack = std::stack<int, std::vector<int>>;
using spp_command_ptr = std::unique_ptr<iCommand>;
using spp_compiler = std::unordered_map<std::string, std::function<spp_command_ptr(std::vector<int>)>>;

#endif