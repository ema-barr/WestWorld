#ifndef TABLE_H
#define TABLE_H
#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "Locations.h"

class Table : public BaseGameEntity
{
private:
	StateMachine<Table> * m_pStateMachine;
	location_type m_location;
	bool m_tableWithBottle;

public:
	Table(int id);
	~Table();

	void SetTableWithBottle(bool bottle);
	bool TableWithBottle() const;

	StateMachine<Table>* GetFSM()const;

	location_type Location()const;

	void Update() override;
	bool HandleMessage(const Telegram& message) override;
};
#endif // !TABLE_H


