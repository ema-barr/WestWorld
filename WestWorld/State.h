#ifndef STATE_H
#define STATE_H



template<class entity_type>
class State
{
public:
	virtual ~State(){}

	//this will execute when the state is entered
	virtual void Enter(entity_type* pMiner) = 0;

	//this is called by the miner's update function each update step
	virtual void Execute(entity_type* pMiner) = 0;

	//this will execute when the state is exited
	virtual void Exit(entity_type* pMiner) = 0;
};

#endif // !STATE_H