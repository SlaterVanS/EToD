#include <ETOD.h>
#include <ETOD/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"

class ExampleLayer : public ETOD::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.0f / 720.0f)
	{
		// ��������

		m_VertexArray = ETOD::VertexArray::Create();

		// ���㻺��

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		ETOD::Ref<ETOD::VertexBuffer> vertexBuffer = ETOD::VertexBuffer::Create(vertices, sizeof(vertices));
		ETOD::BufferLayout layout = {
			{ ETOD::ShaderDataType::Float3, "a_Position" },
			{ ETOD::ShaderDataType::Float4, "a_Color" }
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		// ��������

		uint32_t indices[3] = { 0, 1, 2 };
		ETOD::Ref<ETOD::IndexBuffer> indexBuffer = ETOD::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA = ETOD::VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		ETOD::Ref<ETOD::VertexBuffer> squareVB = ETOD::VertexBuffer::Create(squareVertices, sizeof(squareVertices));

		squareVB->SetLayout({
			{ ETOD::ShaderDataType::Float3, "a_Position" },
			{ ETOD::ShaderDataType::Float2, "a_TexCoord" }
		});

		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		ETOD::Ref<ETOD::IndexBuffer> squareIB = ETOD::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader = ETOD::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader = ETOD::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = ETOD::Texture2D::Create("assets/textures/Checkerboard.png");
		m_SlaterVanSLogoTexture = ETOD::Texture2D::Create("assets/textures/LogoBlack.png");

		std::dynamic_pointer_cast<ETOD::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<ETOD::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}


	void OnUpdate(ETOD::Timestep ts) override
	{
		// Updata
		m_CameraController.OnUpdata(ts);

		// Render
		ETOD::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		ETOD::RenderCommand::Clear();

		ETOD::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<ETOD::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<ETOD::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color",m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				ETOD::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		ETOD::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_SlaterVanSLogoTexture->Bind();
		ETOD::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		// Triangle
		// ETOD::Renderer::Submit(m_Shader, m_VertexArray);

		ETOD::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin(" Palette Demo | EToD Engine ");  // Settings
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));  // Square Color
		ImGui::End();
	}

	void OnEvent(ETOD::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}
private:
	ETOD::ShaderLibrary m_ShaderLibrary;
	ETOD::Ref<ETOD::Shader> m_Shader;
	ETOD::Ref<ETOD::VertexArray> m_VertexArray;

	ETOD::Ref<ETOD::Shader> m_FlatColorShader;
	ETOD::Ref<ETOD::VertexArray> m_SquareVA;

	ETOD::Ref<ETOD::Texture2D> m_Texture, m_SlaterVanSLogoTexture;

	ETOD::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox : public ETOD::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}

};

ETOD::Application* ETOD::CreateApplication()
{
	return new Sandbox();
}