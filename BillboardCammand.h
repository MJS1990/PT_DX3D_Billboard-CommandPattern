#pragma once
#include "Framework.h"
#include "Pattern/Command.h"
#include "Environment/Billboard.h"
#include "Environment/Terrain.h"

class BillboardCommand : public Command
{
public:
	BillboardCommand(Billboard* b)
		: bd(b), prevBCount(0)
	{
	}
	~BillboardCommand() {}

public: 
	void Execute()
	{
		prevBCount = bd->GetAddCount();

		if (bDatas.size() == 0)
		{
			bd->CreateInstanceData(); //빌보드 인스턴스 정점데이터 갱신
			bd->CopybDatas(bDatas, prevBCount);
		}
		else
		{
			bd->AddInstanceData(bDatas);
		}
	}

	void Undo()
	{
		if (bd->GetInstanceCount() >= prevBCount)
			bd->ResizeInstanceCount(bd->GetInstanceCount() - prevBCount);
		else
			bd->SetInstanceCount(0);
	}

private:
	Billboard* bd;
	
	int prevBCount;
	vector<Vertex> bDatas;
};