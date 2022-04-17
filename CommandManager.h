#pragma once

class CommandManager
{
public:
	CommandManager() {}
	~CommandManager() {}

public:
	void Execute(class Command* c);
	void Undo();
	void Redo();

private:
	list<class Command *> undoList; //undo를 실행할 명령 리스트
	list<class Command *> redoList; //redo를 실행할 명령 리스트
};