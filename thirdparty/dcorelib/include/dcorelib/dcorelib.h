// dcorelib 
// by Shadowdara MIT 2025

// Version 0.0.0

#pragma once

#ifndef DCORELIB_H
#define DCORELIB_H

#include <iostream>

// namespace for the dcore library functions
namespace dcorelib
{
	// a wrapper around std::exit to change behavior if needed easily
	void Exit(int code);

	// a wrapper around std::abort to change behavior if needed easily
	void Abort();

} // namespace core

#endif // DCORELIB_H
