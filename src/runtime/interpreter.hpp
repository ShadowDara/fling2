// Header File for the Interpreter

#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "../frontend/ast.hpp"
#include "values.hpp"

namespace fling{
	namespace runtime {
		// Function to evaluate source Code
		fling::runtime::RuntimeVal evaluate(fling::ast::Stmt* astNode);
	} // namespace fling
} // namespace fling

#endif // INTERPRETER_HPP
