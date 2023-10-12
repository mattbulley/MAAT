#pragma once

#include "Core.h"

#include "Window.h"
#include "MAAT/LayerStack.h"
#include "MAAT/Events/Event.h"
#include "MAAT/Events/ApplicationEvent.h"

#include "MAAT/ImGui/ImGuiLayer.h"

#include "MAAT/Renderer/Shader.h"
#include "MAAT/Renderer/Buffer.h"
#include "MAAT/Renderer/VertexArray.h"

#include "MAAT/Renderer/OrthographicCamera.h"

namespace MAAT {

	class MAAT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthographicCamera m_Camera;
	private:
		static Application* s_Instance;
	};

	// To be define in CLIENT
	Application* CreateApplication();
}


