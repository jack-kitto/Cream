#include <Cream.h>
#include "imgui/imgui.h"

class ExampleLayer : public Cream::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Cream::Input::IsKeyPressed(CM_KEY_TAB))
			CM_CLIENT_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Cream::Event& event) override
	{
		if (event.GetEventType() == Cream::EventType::KeyPressed)
		{
			Cream::KeyPressedEvent& e = (Cream::KeyPressedEvent&)event;
			if (e.GetKeyCode() == CM_KEY_TAB)
				CM_CLIENT_TRACE("Tab key is pressed (event)!");
			CM_CLIENT_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class CreamApp : public Cream::Application
{
public:
	CreamApp()
	{
		PushLayer(new ExampleLayer());
	}

	~CreamApp()
	{

	}

};

Cream::Application* Cream::CreateApplication()
{
	return new CreamApp();
}
