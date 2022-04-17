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
	list<class Command *> undoList; //undo�� ������ ��� ����Ʈ
	list<class Command *> redoList; //redo�� ������ ��� ����Ʈ
};