#include "stdafx.h"
#include "Scene.h"
#include "GraphicsPipeline.h"

CScene::CScene()
{
}

CScene::~CScene()
{
}

void CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}

void CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}

void CScene::BuildObjects()
{
	CMesh* textMesh = CMesh::LoadOBJToMesh("title.obj");
	


	m_nObjects = 1;
	m_ppObjects = new CGameObject * [m_nObjects];

	m_ppObjects[0] = new CGameObject();
	m_ppObjects[0]->SetMesh(textMesh);
	m_ppObjects[0]->SetPosition(-4.5f, 5.0f, -30.0f);
	m_ppObjects[0]->SetRotation(0.0f, 0.0f, 0.0f);
	m_ppObjects[0]->SetRotationSpeed(90.0, 0.0f, 0.0f);
	m_ppObjects[0]->SetColor(RGB(255, 255, 0));
}

void CScene::ReleaseObjects()
{
	for (int i = 0; i < m_nObjects; i++) if (m_ppObjects[i]) delete m_ppObjects[i];
	if (m_ppObjects) delete[] m_ppObjects;
}

void CScene::Animate(float fElapsedTime)
{
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->Animate(fElapsedTime);
}

void CScene::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	if (pCamera) CGraphicsPipeline::SetCamera(pCamera);

	for (int i = 0; i < m_nObjects; i++)
	{
		m_ppObjects[i]->Render(hDCFrameBuffer);
	}
}
