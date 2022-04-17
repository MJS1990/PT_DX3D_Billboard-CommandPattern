#include "Framework.h"
#include "CommandManager.h"
#include "Command.h"

void CommandManager::Execute(Command* c)
{
	c->Execute();
	undoList.push_back(c);
	redoList.clear();
}

void CommandManager::Undo()
{
	if (undoList.empty() == true) return;

	undoList.back()->Undo();
	redoList.push_back(undoList.back());
	undoList.pop_back();
}

void CommandManager::Redo()
{
	if (redoList.empty() == true) return;

	redoList.back()->Execute();
	undoList.push_back(redoList.back());
	redoList.pop_back();
}