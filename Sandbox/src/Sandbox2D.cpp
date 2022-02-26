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
	m_SquareVA = ETOD::VertexArray::Create();

	float squareVertices[5 * 4] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	ETOD::Ref<ETOD::VertexBuffer> squareVB;
	squareVB.reset(ETOD::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

	squareVB->SetLayout({
		{ ETOD::ShaderDataType::Float3, "a_Position" }
	});

	m_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
	ETOD::Ref<ETOD::IndexBuffer> squareIB;
	squareIB.reset(ETOD::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
	m_SquareVA->SetIndexBuffer(squareIB);

	m_FlatColorShader = ETOD::Shader::Create("assets/shaders/FlatColor.glsl");
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

	ETOD::Renderer::BeginScene(m_CameraController.GetCamera());

	std::dynamic_pointer_cast<ETOD::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<ETOD::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	ETOD::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	ETOD::Renderer::EndScene();
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