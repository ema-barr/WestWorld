#ifndef NAMES_H
#define NAMES_H

#pragma once
#include <string>

enum names{
	ent_Miner_Bob,
	ent_Elsa
};

inline std::string GetNameOfEntity(int n) {
	switch (n) {
	case ent_Miner_Bob:
		return "Miner Bob";
	case ent_Elsa:
		return "Elsa";
	default:
		return "UNKNOWN";
	}
}

#endif // !NAMES_H

