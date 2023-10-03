#pragma once

#include "Cream/Layer.h"

#include "Cream/Events/ApplicationEvent.h"
#include "Cream/Events/KeyEvent.h"
#include "Cream/Events/MouseEvent.h"

namespace Cream {

	class CREAM_API ImGuiLayer : public Layer
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
