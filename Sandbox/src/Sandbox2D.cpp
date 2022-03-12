#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{

}

void Sandbox2D::OnAttach()
{
	ETOD_PROFILE_FUNCTION();

	m_CheckerboardTexture = ETOD::Texture2D::Create("assets/textures/Checkerboard.png");
}


void Sandbox2D::OnDetach()
{
	ETOD_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(ETOD::Timestep ts)
{
	ETOD_PROFILE_FUNCTION();

	// Updata
		m_CameraController.OnUpdata(ts);

	// Render
	{
		ETOD_PROFILE_SCOPE("Renderer Prep");
		ETOD::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		ETOD::RenderCommand::Clear();
	}

	{
		ETOD_PROFILE_SCOPE("Renderer Draw");
		ETOD::Renderer2D::BeginScene(m_CameraController.GetCamera());
		ETOD::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(-45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		ETOD::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		ETOD::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
		ETOD::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	ETOD_PROFILE_FUNCTION();

	ImGui::Begin(" Palette Demo | EToD Engine ");  // Settings
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));  // Square Color
	ImGui::End();
}

void Sandbox2D::OnEvent(ETOD::Event& e)
{
	m_CameraController.OnEvent(e);
}