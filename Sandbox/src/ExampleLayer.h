#pragma once

#include "MAAT.h"

class ExampleLayer : public MAAT::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(MAAT::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(MAAT::Event& e) override;
private:
	MAAT::ShaderLibrary m_ShaderLibrary;
	MAAT::Ref<MAAT::Shader> m_Shader;
	MAAT::Ref<MAAT::VertexArray> m_VertexArray;

	MAAT::Ref<MAAT::Shader> m_FlatColorShader;
	MAAT::Ref<MAAT::VertexArray> m_SquareVA;

	MAAT::Ref<MAAT::Texture2D> m_Texture, m_ChernoLogoTexture;

	MAAT::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};