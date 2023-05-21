#pragma once

#include "ETOD.h"

class Sandbox2D : public ETOD::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(ETOD::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(ETOD::Event& e) override;
private:
	ETOD::OrthographicCameraController m_CameraController;

	// Temp
	ETOD::Ref<ETOD::VertexArray> m_SquareVA;
	ETOD::Ref<ETOD::Shader> m_FlatColorShader;

	ETOD::Ref<ETOD::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};