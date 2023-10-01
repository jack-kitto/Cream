#include <Cream.h>

class CreamApp : public Cream::Application
{
public:
	CreamApp()
	{
	};
	~CreamApp()
	{
	};
};

Cream::Application* Cream::CreateApplication()
{
	return new CreamApp();
}
