#include "app/EmberApp.h"
#include "input/IMouseListener.h"
#include "input/IKeyboardListener.h"
#include "app/InputSystem.h"
#include "math/EmberMath.h"

using namespace ember::core;
using namespace ember::input;
using namespace ember::app;
using namespace ember::math;

class TestKeyListener : public IKeyboardListener
{
	public:
		TestKeyListener() {};
		virtual ~TestKeyListener() { }
		
		virtual I32 VGetPriority() const
		{
			return 0;
		}
		
		virtual void VOnKeyPress( I32 key )
		{
			LOG_F( INFO, "KEY PRESSED %i", key );
		}
		
		virtual void VOnKeyRelease( I32 key )
		{
			LOG_F( INFO, "KEY RELEASED %i", key );
		}
		
		virtual void VOnCharacterInput( U32 codePoint )
		{
			LOG_F( INFO, "CHAR TYPED %i", codePoint );
		}
};

class TestMouseListener : public IMouseListener
{
	public:
		TestMouseListener() {};
		virtual ~TestMouseListener() { }
		
		virtual I32 VGetPriority() const
		{
			return 0;
		}
		
		virtual void VOnButtonPress( I32 button )
		{
			LOG_F( INFO, "TEST Button PRESSED %i", button );
		}
		
		virtual void VOnButtonRelease( I32 button )
		{
			LOG_F( INFO, "TEST Button RELEASED %i", button );
		}
		
		virtual void VOnMove( const Point2 &position, const Point2 &relative )
		{
			LOG_F( INFO, "Mouse moved x %f y %f xRel %f yRel %f", position.X(), position.Y(), relative.X(), relative.Y() );
		}
		
		virtual void VOnScroll( const Point2 &position )
		{
			LOG_F( INFO, "Mouse scrolled x %f y %f", position.X(), position.Y() );
		}
		
		virtual void VOnFileDrop( const char **paths, int count )
		{
			LOG_F( INFO, "Files dropped %i", count );
		}
};

int main( int argc, char **argv )
{
	TestKeyListener k;
	TestMouseListener m;
	
	EmberApp *app = new EmberApp();
	app->Initialize();
	
	app->Input()->Add( ( IKeyboardListener * )&k );
	app->Input()->Add( ( IMouseListener * )&m );
	
	app->Run();
	
	delete app;
	app = nullptr;
	
	return 0;
}
