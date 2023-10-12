#include <MAAT.h>

#include "imgui/imgui.h"

class ExampleLayer : public MAAT::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(MAAT::VertexArray::Create());

		float vertices[3 * 7]{
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.2f, 0.2f, 0.8f, 1.0f,
			0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<MAAT::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(MAAT::VertexBuffer::Create(vertices, sizeof(vertices)));
		MAAT::BufferLayout layout = {
			{ MAAT::ShaderDataType::Float3, "a_Position" },
		{ MAAT::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<MAAT::IndexBuffer> indexBuffer;
		indexBuffer.reset(MAAT::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(MAAT::VertexArray::Create());

		float squareVertices[3 * 4]{
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,
		};

		std::shared_ptr<MAAT::VertexBuffer> squareVB;
		squareVB.reset(MAAT::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ MAAT::ShaderDataType::Float3, "a_Position" }
		});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<MAAT::IndexBuffer> squareIB;
		squareIB.reset(MAAT::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
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

		m_Shader.reset(new MAAT::Shader(vertexSrc, fragmentSrc));

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

		m_BlueShader.reset(new MAAT::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
	}

	void OnUpdate(MAAT::Timestep ts) override
	{
		if (MAAT::Input::IsKeyPressed(MAAT_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		else if (MAAT::Input::IsKeyPressed(MAAT_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (MAAT::Input::IsKeyPressed(MAAT_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;
		else if (MAAT::Input::IsKeyPressed(MAAT_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		if (MAAT::Input::IsKeyPressed(MAAT_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		if (MAAT::Input::IsKeyPressed(MAAT_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed * ts;

		MAAT::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		MAAT::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		MAAT::Renderer::BeginScene(m_Camera);

		MAAT::Renderer::Submit(m_BlueShader, m_SquareVA);
		MAAT::Renderer::Submit(m_Shader, m_VertexArray);

		MAAT::Renderer::EndScene();
	}
	
	virtual void OnImGuiRender() override
	{

	}
	
	void OnEvent(MAAT::Event& event) override
	{
	}
private:
	std::shared_ptr<MAAT::Shader> m_Shader;
	std::shared_ptr<MAAT::VertexArray> m_VertexArray;

	std::shared_ptr<MAAT::Shader> m_BlueShader;
	std::shared_ptr<MAAT::VertexArray> m_SquareVA;

	MAAT::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 2.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 100.0f;
};

class Sandbox : public MAAT::Application
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

MAAT::Application* MAAT::CreateApplication()
{
	return new Sandbox();
}