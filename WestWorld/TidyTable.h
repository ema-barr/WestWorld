#ifndef TIDY_TABLE_H
#define TIDY_TABLE_H
#include "Table.h"

class TidyTable : public State<Table>
{
private:
	TidyTable() = default;
public:
	static TidyTable * Instance();
	void Enter(Table* pTable) override;
	void Execute(Table* pTable) override;
	void Exit(Table* pTable) override;
	bool OnMessage(Table*, const Telegram&) override;
};
#endif // !TIDY_TABLE_H
