#include <Cream.h>

class ExampleLayer : public Cream::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		CM_CLIENT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Cream::Event& event) override
	{
		CM_CLIENT_TRACE("{0}", event.ToString());
	}

};


class CreamApp : public Cream::Application
{
public:
	CreamApp()
	{
		CM_CLIENT_INFO("Creating CreamApp!")
		PushLayer(new ExampleLayer());
	};
	~CreamApp()
	{
	};
	static void Run() {
	};
};

Cream::Application* Cream::CreateApplication()
{
	return new CreamApp();
}
