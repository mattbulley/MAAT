#pragma once

#include "MAAT.h"

#include "ParticleSystem.h"

class Sandbox2D : public MAAT::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(MAAT::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(MAAT::Event& e) override;
private:
	MAAT::OrthographicCameraController m_CameraController;

	// Temp
	MAAT::Ref<MAAT::VertexArray> m_SquareVA;
	MAAT::Ref<MAAT::Shader> m_FlatColorShader;

	MAAT::Ref<MAAT::Texture2D> m_AlienTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	ParticleSystem m_ParticleSystem;
	ParticleProps m_Particle;
};