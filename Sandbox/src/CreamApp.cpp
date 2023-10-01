#include <Cream.h>

class CreamApp : public Cream::Application
{
public:
	CreamApp()
	{
		CM_CLIENT_INFO("Creating CreamApp!")
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
