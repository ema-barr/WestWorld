// WestWorld.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include "EntityNames.h"
#include "Miner.h"
#include "MinersWife.h"
#include "misc/ConsoleUtils.h"

#include <thread>
#include <chrono>

int main()
{
    //create a miner
	Miner miner(ent_Miner_Bob);
	MinersWife wife(ent_Elsa);

	//simply run the miner through a few Update calls
	for (int i = 0; i < 20; ++i) {
		miner.Update();
		wife.Update();

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

