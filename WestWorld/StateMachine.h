#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#pragma once
#include "State.h"
#include <cassert>

template<class entity_type>
class StateMachine
{
	//a pointer to the agent that own this istance
	entity_type* m_pOwner;

	State<entity_type>* m_pCurrentState;
	
	//a record to the last state the agent was in
	State<entity_type>* m_pPreviousState;

	//this state logic is caled every time the FSM is updated
	State<entity_type>* m_pGlobalState;

public:
	StateMachine(entity_type* owner) :
		m_pOwner(owner),
		m_pCurrentState(nullptr),
		m_pPreviousState(nullptr),
		m_pGlobalState(nullptr) {}
	virtual ~StateMachine() {}

	//use these methods to initialize the FSM
	void SetCurrentState(State<entity_type>* s) { m_pCurrentState = s; }
	void SetGlobalState(State<entity_type>* s) { m_pGlobalState = s; }
	void SetPreviousState(State<entity_type>* s) { m_pPreviousState = s; }
	//call this to update FSM
	void Update()const {
		//if a global state exists, call its executed method
		if (m_pGlobalState != nullptr) {
			m_pGlobalState->Execute(m_pOwner);
		}

		//same for the current state
		if (m_pCurrentState != nullptr) {
			m_pCurrentState->Execute(m_pOwner);
		}
	}

	//change to a new state
	void ChangeState(State<entity_type>* pNewState) {
		assert(pNewState && "<StateMachine::ChangeState>: trying to change to a null state");

		//keep a record of the previous state
		m_pPreviousState = m_pCurrentState;

		//call the exit method of the existing state
		m_pCurrentState->Exit(m_pOwner);

		//change state to the new state
		m_pCurrentState = pNewState;

		//call the entry method of the new state
		m_pCurrentState->Enter(m_pOwner);
	}

	//change state back to the previous state
	void RevertToPreviousState() {
		ChangeState(m_pPreviousState);
	}

	//accessors
	State<entity_type>* CurrentState() {
		return m_pCurrentState;
	}
	State<entity_type>* GlobalState() {
		return m_pGlobalState;
	}
	State<entity_type>* PreviousState() {
		return m_pPreviousState;
	}

	//returns true if the current state's type is equal to the type of the class passed as parameter
	bool isInState(const State<entity_type>& st) const {
		return typeid(*m_pCurrentState) == typeid(st);
	}
};

#endif // !STATE_MACHINE_H
