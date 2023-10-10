#pragma once

#include "MAAT/Layer.h"

#include "MAAT/Events/ApplicationEvent.h"
#include "MAAT/Events/KeyEvent.h"
#include "MAAT/Events/MouseEvent.h"

namespace MAAT {

	class MAAT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}