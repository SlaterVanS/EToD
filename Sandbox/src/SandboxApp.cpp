#include <ETOD.h>

#include "imgui/imgui.h"

class ExampleLayer : public ETOD::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		// 顶点数组

		m_VertexArray.reset(ETOD::VertexArray::Create());

		// 顶点缓存

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<ETOD::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(ETOD::VertexBuffer::Create(vertices, sizeof(vertices)));
		ETOD::BufferLayout layout = {
			{ ETOD::ShaderDataType::Float3, "a_Position" },
			{ ETOD::ShaderDataType::Float4, "a_Color" }
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		// 索引缓冲

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<ETOD::IndexBuffer> indexBuffer;
		indexBuffer.reset(ETOD::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(ETOD::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};

		std::shared_ptr<ETOD::VertexBuffer> squareVB;
		squareVB.reset(ETOD::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

		squareVB->SetLayout({
			{ ETOD::ShaderDataType::Float3, "a_Position" }
		});

		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<ETOD::IndexBuffer> squareIB;
		squareIB.reset(ETOD::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
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

		m_Shader.reset(new ETOD::Shader(vertexSrc, fragmentSrc));

		std::string blueShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";

		std::string blueShaderFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

		m_BlueShader.reset(new ETOD::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
	}


	void OnUpdate(ETOD::Timestep ts) override
	{
		if (ETOD::Input::IsKeyPressed(ETOD_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;

		else if (ETOD::Input::IsKeyPressed(ETOD_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (ETOD::Input::IsKeyPressed(ETOD_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;

		else if (ETOD::Input::IsKeyPressed(ETOD_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		if (ETOD::Input::IsKeyPressed(ETOD_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed * ts;

		if (ETOD::Input::IsKeyPressed(ETOD_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed * ts;


		//ETOD_INFO("实例层::更新"); // ExampleLayer::Update
		ETOD::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		ETOD::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		ETOD::Renderer::BeginScene(m_Camera);
		ETOD::Renderer::Submit(m_BlueShader, m_SquareVA);
		ETOD::Renderer::Submit(m_Shader, m_VertexArray);

		ETOD::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{

	}

	void OnEvent(ETOD::Event& event) override
	{
	}
private:
	std::shared_ptr<ETOD::Shader> m_Shader;
	std::shared_ptr<ETOD::VertexArray> m_VertexArray;

	std::shared_ptr<ETOD::Shader> m_BlueShader;
	std::shared_ptr<ETOD::VertexArray> m_SquareVA;

	ETOD::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;
};

class Sandbox : public ETOD::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

ETOD::Application* ETOD::CreateApplication()
{
	return new Sandbox();
}