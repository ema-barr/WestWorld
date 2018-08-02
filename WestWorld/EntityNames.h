#ifndef NAMES_H
#define NAMES_H

#include <string>

enum names {
	ent_Miner_Bob,
	ent_Elsa,
	ent_John
};

inline std::string GetNameOfEntity(int n) {
	switch (n) {
	case ent_Miner_Bob:
		return "Miner Bob";
	case ent_Elsa:
		return "Elsa";
	case ent_John:
		return "John";
	default:
		return "UNKNOWN";
	}
}

#endif // !NAMES_H

