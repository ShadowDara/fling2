// Header file for the Core Module

#ifndef CORE_HPP
#define CORE_HPP

#include <string>

namespace fling
{
	namespace core
	{
		// a wrapper around std::exit to change behavior if needed easily
		void Exit(int code);

		// a wrapper around std::abort to change behavior if needed easily
		void Abort();
	} // namespace core
}

#endif // CORE_HPP
