#pragma once

#include "etod.h"

class ExampleLayer : public ETOD::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(ETOD::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(ETOD::Event& e) override;
private:
	ETOD::ShaderLibrary m_ShaderLibrary;
	ETOD::Ref<ETOD::Shader> m_Shader;
	ETOD::Ref<ETOD::VertexArray> m_VertexArray;

	ETOD::Ref<ETOD::Shader> m_FlatColorShader;
	ETOD::Ref<ETOD::VertexArray> m_SquareVA;

	ETOD::Ref<ETOD::Texture2D> m_Texture, m_ChernoLogoTexture;

	ETOD::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};
