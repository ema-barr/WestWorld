// WestWorld.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include "EntityNames.h"
#include "Miner.h"
#include "MinersWife.h"
#include "misc/ConsoleUtils.h"

#include <thread>
#include <chrono>
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include <algorithm>
#include "InsultQuotes.h"
#include "BarFly.h"
#include "Table.h"

int main()
{
    //create entities
	Miner Bob(ent_Miner_Bob);
	MinersWife Elsa(ent_Elsa);
	BarFly John(ent_John);
	Table table1(table_1);
	Table table2(table_2);
	Table table3(table_3);

	//set insult quotes
	std::random_shuffle(insultQuotesList.begin(), insultQuotesList.end());

	std::vector<std::string> bobInsultQuotes(insultQuotesList.begin(), insultQuotesList.begin() + 3);
	Bob.SetInsultQuotes(&bobInsultQuotes);

	std::vector<std::string> johnInsultQuotes(insultQuotesList.begin() + 3, insultQuotesList.begin() + 7);
	John.SetInsultQuotes(&johnInsultQuotes);

	std::vector<std::string> elsaInsultQuotes(insultQuotesList.begin() + 7, insultQuotesList.end());
	Elsa.SetInsultQuotes(&elsaInsultQuotes);

	//register them with the entity manager
	EntityMgr->RegisterEntity(&Bob);
	EntityMgr->RegisterEntity(&Elsa);
	EntityMgr->RegisterEntity(&John);
	EntityMgr->RegisterEntity(&table1);
	EntityMgr->RegisterEntity(&table2);
	EntityMgr->RegisterEntity(&table3);


	//simply run the miner through a few Update calls
	for (int i = 0; i < 20; ++i) {

		Bob.Update();
		Elsa.Update();
		John.Update();

		//dispatch any delayed messages
		Dispatch->DispatchDelayedMessages();

		//method to sleep thread
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
		/* oppure
			std::chrono::milliseconds timespan(800);
			std::this_thread::sleep_for(timespan);
		*/
		
	}

	//wait for a keypress before exiting
	PressAnyKeyToContinue();

	return 0;
}

