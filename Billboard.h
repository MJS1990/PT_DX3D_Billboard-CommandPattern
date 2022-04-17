#pragma once

#include "../Pattern/Command.h"

class Billboard
{
public:
	Billboard(class Terrain* terrain);
	~Billboard();

	void Update();
	void Render();
	
	void Undo();
	
	void CreateInstanceData(); //�ν��Ͻ� ���� ����

	//�ν��Ͻ� ���� ������ ���� �Լ�
	int GetAddCount() { return addCount; }
	int GetInstanceCount() { return instanceCount; }

	void ResizeInstanceCount(int count) //execute
	{
		instanceCount = count;
		bDatas.resize(instanceCount);
	}

	void SetInstanceCount(int count) { instanceCount = count; }
	void AddInstanceData(vector<Vertex> datas);
	void CopybDatas(vector<Vertex>& datas, UINT count);
	
private:
	bool useBillboard;

	Shader* shader;

	class Terrain* terrain;

	VertexSize instanceVertex; //�ν��Ͻ� ��ü �߽���

	//0->�����̵� instancePos. 1->�� �ν��Ͻ��� ����
	ID3D11Buffer* vertexBuffer[2];


	float terrainHeight;
	UINT terrainX, terrainZ;

	D3DXVECTOR3 pickedPos; //���콺 ���� ��ŷ ��ġ��
	class Ray* ray;

	D3DXVECTOR3* terrainPositions;
	VertexTextureNormalTangent* tVertices; //���� ������

private:
	int instanceCount; //������ ��ü���� �� ����
	int addCount; //���콺�� �ѹ��� �߰���ų �������� ����
	D3DXMATRIX worlds[30];
	Texture* texture; 

	ID3D11Buffer* worldBuffer;

	Vertex* instance;

	vector<Vertex> bDatas;

	float terrainY[256][256];
	
	bool useUndo;
};