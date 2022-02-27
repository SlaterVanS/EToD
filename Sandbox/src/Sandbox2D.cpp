#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{

}

void Sandbox2D::OnAttach()
{

}


void Sandbox2D::OnDetach()
{

}

void Sandbox2D::OnUpdate(ETOD::Timestep ts)
{
	// Updata
	m_CameraController.OnUpdata(ts);

	// Render
	ETOD::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	ETOD::RenderCommand::Clear();

	ETOD::Renderer2D::BeginScene(m_CameraController.GetCamera());	
	ETOD::Renderer2D::DrawQuad({ 0.0f,0.0f }, { 1.0f,1.0f }, { 0.8f,0.2f,0.3f,1.0f });
	ETOD::Renderer2D::EndScene();

	// ETOD: Add these functions - Shader::SetMat4, Shader::SetFloat4
	//std::dynamic_pointer_cast<ETOD::OpenGLShader>(m_FlatColorShader)->Bind();
	//std::dynamic_pointer_cast<ETOD::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin(" Palette Demo | EToD Engine ");  // Settings
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));  // Square Color
	ImGui::End();
}

void Sandbox2D::OnEvent(ETOD::Event& e)
{
	m_CameraController.OnEvent(e);
}