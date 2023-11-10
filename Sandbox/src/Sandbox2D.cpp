#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static const uint32_t s_MapWidth = 24;
static const char* s_MapTiles =	
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWWWDDDDDDWWWWWWWWWW"
"WWWWDDDDDDDDDDDDDDWWWWWW"
"WWWDDDDDDDDDDDDDDDDDWWWW"
"WWDDDDDDDDDDDDDDDDDDDWWW"
"WDDDDDWWWDDDDDDDDDDDDWWW"
"WDDDDDWWWDDDDDDDDDDDDDWW"
"WWDDDDDDDDDDDDDDDDDDDWWW"
"WWWDDDDDDDDDDDDDDDDDWWWW"
"WWWWDDDDDDDDDDDDDDWWWWWW"
"WWWWWDDDDDDDDDDDWWWWWWWW"
"WWWWWWDDDDDDDDDDWWWWWWWW"
"WWWWWWWWWDDDWWWWWWWWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW"
;

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	MAAT_PROFILE_FUNCTION();

	MAAT::FramebufferSpecification fbSpec;
	fbSpec.Width = 1280;
	fbSpec.Height = 720;

	m_AlienTexture = MAAT::Texture2D::Create("assets/textures/alien.png");
	m_SpriteSheet = MAAT::Texture2D::Create("assets/game/textures/RPGpack_sheet_2X.png");

	m_TextureStairs = MAAT::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 0, 11 }, { 128, 128 });
	m_TextureTree = MAAT::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 2, 1 }, { 128, 128 }, { 1, 2 });

	m_MapWidth = s_MapWidth;
	m_MapHeight = strlen(s_MapTiles) / s_MapWidth;

	s_TextureMap['D']  = MAAT::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 6, 11 }, { 128, 128 });
	s_TextureMap['W']  = MAAT::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 11, 11 }, { 128, 128 });

	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
	m_Particle.LifeTime = 5.0f;
	m_Particle.Velocity = { 0.0f, 0.0f };
	m_Particle.VelocityVariation = { 3.0f, 1.0f };
	m_Particle.Position = { 0.0f, 0.0f };

	m_CameraController.SetZoomLevel(5.0f);
}

void Sandbox2D::OnDetach()
{
	MAAT_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(MAAT::Timestep ts)
{
	MAAT_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	MAAT::Renderer2D::ResetStats();
	{
		MAAT_PROFILE_SCOPE("Renderer Prep");
		MAAT::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		MAAT::RenderCommand::Clear();
	}

#if 0

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		MAAT_PROFILE_SCOPE("Renderer Draw");
		/*MAAT::Renderer2D::BeginScene(m_CameraController.GetCamera());
		MAAT::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f, 0.1f }, { 0.8f, 0.8f }, glm::radians(-45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		MAAT::Renderer2D::DrawQuad({ -1.0f, 0.0f, 0.1f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		MAAT::Renderer2D::DrawQuad({ 0.5f, -0.5f, 0.1f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		MAAT::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.1f}, { 5.0f, 5.0f }, m_AlienTexture, 1.0f, { 1.0f, 0.5f, 0.5f, 1.0f });
		//MAAT::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.1f}, { 1.0f, 1.0f }, glm::radians(rotation), m_AlienTexture, 20.0f);
		//MAAT::Renderer2D::EndScene();

		//MAAT::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.25f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.25f)
			{
				glm::vec4 color = { (x + 0.5f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f , 0.9f};
				MAAT::Renderer2D::DrawQuad({ x, y , 0.1f}, { 0.24f, 0.24f }, color);
			}
		}
		MAAT::Renderer2D::EndScene();*/
	}

#endif
	/*
	if (MAAT::Input::IsMouseButtonPressed(MAAT_MOUSE_BUTTON_LEFT))
	{
		auto [x, y] = MAAT::Input::GetMousePosition();
		auto width = MAAT::Application::Get().GetWindow().GetWidth();
		auto height = MAAT::Application::Get().GetWindow().GetHeight();
		
		auto bounds = m_CameraController.GetBounds();
		auto pos = m_CameraController.GetCamera().GetPosition();
		x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
		y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
		m_Particle.Position = { x + pos.x, y + pos.y };
		for (int i = 0; i < 5; i++)
			m_ParticleSystem.Emit(m_Particle);
		
	}
	*/

	m_ParticleSystem.OnUpdate(ts);
	m_ParticleSystem.OnRender(m_CameraController.GetCamera());

	MAAT::Renderer2D::BeginScene(m_CameraController.GetCamera());

	for (uint32_t y = 0; y < m_MapHeight; y++)
	{
		for (uint32_t x = 0; x < m_MapWidth; x++)
		{
			MAAT::Ref<MAAT::SubTexture2D> texture;
			char tileType = s_MapTiles[x + y * m_MapWidth];
			if (s_TextureMap.find(tileType) != s_TextureMap.end())
				texture = s_TextureMap[tileType];
			else
				texture = m_TextureStairs;

			//MAAT::Renderer2D::DrawQuad({ x - m_MapWidth / 2.0f, m_MapHeight - y - m_MapHeight / 2.0f, 0.5f }, { 1.0f, 1.0f }, texture);
		}
	}

	//MAAT::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.5f }, { 1.0f, 1.0f }, m_TextureStairs);
	//MAAT::Renderer2D::DrawQuad({ 1.0f, 0.0f, 0.5f }, { 1.0f, 1.0f }, m_TextureBarrel);
	//MAAT::Renderer2D::DrawQuad({ -1.0f, 0.5f, 0.5f }, { 1.0f, 2.0f }, m_TextureTree);
	MAAT::Renderer2D::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
	MAAT_PROFILE_FUNCTION();
	
	ImGui::Begin("Settings");

	auto stats = MAAT::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

	//uint32_t textureID = m_AlienTexture->GetRendererID();
	//ImGui::Image((void*)textureID, ImVec2{ 1280.0f, 720.0f }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });
	ImGui::End();
}

void Sandbox2D::OnEvent(MAAT::Event& e)
{
	m_CameraController.OnEvent(e);
}