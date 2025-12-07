// dcorelib.cpp: Definiert den Einstiegspunkt für die Anwendung.

// dcorelib.cpp
// by Shadowdara MIT 2025

#include "dcorelib/dcorelib.h"

void dcorelib::Exit(int code)
{
	std::exit(code);
}

void dcorelib::Abort()
{
	std::abort();
}
