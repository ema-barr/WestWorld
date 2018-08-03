#ifndef MESSAGE_TYPES_H
#define MESSAGE_TYPES_H
#include <string>

enum message_type
{
	Msg_HiHoneyImHome,
	Msg_StewReady,
	Msg_TableFlip,
	Msg_IsThereABottle,
	Msg_TableAnswer,
	Msg_MinerEntersSaloon,
	Msg_InsultQuote,
	Msg_YouAreALoser,
	Msg_HoneyILost,
	Msg_LearnNewInsultQuote,
	Msg_Fight,
	Msg_ThereWasAFight,
	Msg_Sorry
};

inline std::string MsgToStr(int msg)
{
	switch (msg)
	{
	case Msg_HiHoneyImHome:

		return "HiHoneyImHome";

	case Msg_StewReady:

		return "StewReady";

	case Msg_TableFlip:
		return "TableFlip";

	case Msg_IsThereABottle:
		return "Msg_IsThereABottle";

	case Msg_TableAnswer:
		return "Msg_TableAnswer";

	case Msg_MinerEntersSaloon:
		return "Msg_MinerEntersSaloon";

	case Msg_InsultQuote:
		return "Msg_InsultQuote";

	case Msg_YouAreALoser:
		return "Msg_YouAreALoser";

	case Msg_HoneyILost:
		return "Msg_HoneyILost";

	case Msg_LearnNewInsultQuote:
		return "Msg_LearnNewInsultQuote";

	case Msg_Fight:
		return "Msg_Fight";

	case Msg_ThereWasAFight:
		return "Msg_ThereWasAFight";

	case Msg_Sorry:
		return "Msg_Sorry";

	default:

		return "Not recognized!";
	}
}


#endif

