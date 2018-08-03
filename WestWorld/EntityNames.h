#ifndef NAMES_H
#define NAMES_H

#include <string>

enum names {
	ent_Miner_Bob,
	ent_Elsa,
	ent_John,
	table_1,
	table_2,
	table_3
};

inline std::string GetNameOfEntity(int n) {
	switch (n) {
	case ent_Miner_Bob:
		return "Miner Bob";
	case ent_Elsa:
		return "Elsa";
	case ent_John:
		return "John";
	case table_1:
		return "first table";
	case table_2:
		return "second table";
	case table_3:
		return "third table";
	default:
		return "UNKNOWN";
	}
}

#endif // !NAMES_H

