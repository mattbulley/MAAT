#pragma once

#include "MAAT/Core/Core.h"

#include "MAAT/Core/Window.h"
#include "MAAT/Core/LayerStack.h"
#include "MAAT/Events/Event.h"
#include "MAAT/Events/ApplicationEvent.h"

#include "MAAT/Core/Timestep.h"

#include "MAAT/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace MAAT {

	class Application
	{
	public:
		Application(const std::string& name = "MAAT Engine");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		inline static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be define in CLIENT
	Application* CreateApplication();
}


