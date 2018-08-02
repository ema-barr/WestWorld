#ifndef MESSAGE_TYPES_H
#define MESSAGE_TYPES_H
#include <string>

enum message_type
{
	Msg_HiHoneyImHome,
	Msg_StewReady,
	Msg_TableFlip,
	Msg_MinerEntersSaloon,
	Msg_InsultQuote,
	Msg_YouAreALoser,
	Msg_HoneyILost,
	Msg_LearnNewInsultQuote
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

	default:

		return "Not recognized!";
	}
}


#endif

