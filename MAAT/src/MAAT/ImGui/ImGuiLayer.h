#pragma once

#include "MAAT/Core/Layer.h"

#include "MAAT/Events/ApplicationEvent.h"
#include "MAAT/Events/KeyEvent.h"
#include "MAAT/Events/MouseEvent.h"

namespace MAAT {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}