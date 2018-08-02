#ifndef FLIPPED_TABLE_H
#define FLIPPED_TABLE_H
#include "Table.h"

class FlippedTable : public State<Table>
{
private:
	FlippedTable() = default;
public:
	static FlippedTable * Instance();

	void Enter(Table* pMiner) override;
	void Execute(Table* pMiner) override;
	void Exit(Table* pMiner) override;
	bool OnMessage(Table*, const Telegram&) override;
};
#endif // !FLIPPED_TABLE_H


