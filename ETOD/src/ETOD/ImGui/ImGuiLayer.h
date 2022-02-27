#pragma once

#include "ETOD/Core/Layer.h"

#include "ETOD/Events/ApplicationEvent.h"
#include "ETOD/Events/KeyEvent.h"
#include "ETOD/Events/MouseEvent.h"

namespace ETOD {

	class ETOD_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		//virtual void OnImGuiRender() override;  //”“≤‡UI

		void Begin();
		void End();

	/*private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);*/
	private:
		float m_Time = 0.0f;
	};
}