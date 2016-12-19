#include <GLFW/glfw3.h>

#define LOGURU_IMPLEMENTATION 1
#include "app/EmberApp.h"
#include "input/IMouseListener.h"
#include "input/IKeyboardListener.h"
#include "app/InputSystem.h"

int get_log_level();
void test_loguru( int argc, char **argv );

using namespace ember::core;
using namespace ember::input;
using namespace ember::app;

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
		
		virtual void VOnMove( F64 x, F64 y, F64 xRelative, F64 yRelative )
		{
			LOG_F( INFO, "Mouse moved x %f y %f xRel %f yRel %f", x, y, xRelative, yRelative );
		}
		
		virtual void VOnScroll( F64 x, F64 y )
		{
			LOG_F( INFO, "Mouse scrolled x %f y %f", x, y );
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
	
	test_loguru( argc, argv );
	
	app->Input()->Add( ( IKeyboardListener * )&k );
	app->Input()->Add( ( IMouseListener * )&m );
	
	app->Run();
	
	delete app;
	app = nullptr;
	
	return 0;
}

int get_log_level()
{
	return loguru::Verbosity_4;
}

void test_loguru( int argc, char **argv )
{
	bool badness = false;
	int length = 10;
	int a = 5;
	int b = 5;
	
	LOG_SCOPE_F( INFO, "Will indent all log messages within this scope." );
	LOG_F( INFO, "I'm hungry for some %.3f!", 3.14159 );
	LOG_F( 2, "Will only show if verbosity is 2 or higher" );
	VLOG_F( get_log_level(), "Use vlog for dynamic log level (integer in the range 0-9, inclusive)" );
	LOG_IF_F( ERROR, badness, "Will only show if badness happens" );
	CHECK_GT_F( length, 0 ); // Will print the value of `length` on failure.
	CHECK_EQ_F( a, b, "You can also supply a custom message, like to print something: %d", a + b );
}
