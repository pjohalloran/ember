#include <GLFW/glfw3.h>

#define LOGURU_IMPLEMENTATION 1
#include "app/EmberApp.h"
#include "input/IMouseListener.h"
#include "input/IKeyboardListener.h"
#include "app/InputSystem.h"
#include "math/EmberMath.h"

#include <database.hpp> // for the databases
#include <error.hpp> // for error handling
#include <generator.hpp> // for the generator classes
#include <string_id.hpp> // for the string_id

int get_log_level();
void test_loguru( int argc, char **argv );
void test_string_id();

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
	
	test_loguru( argc, argv );
	
	app->Input()->Add( ( IKeyboardListener * )&k );
	app->Input()->Add( ( IMouseListener * )&m );
	
	Matrix4 mat;
	mat.LoadIdentity();
	LOG_F( INFO, "matrix %s", mat.ToString() );
	
	Vector3 v;
	LOG_F( INFO, "vec %s", v.ToString() );
	
	test_string_id();
	
	app->Run();
	
	delete app;
	app = nullptr;
	
	
	return 0;
}

void test_string_id()
{
	using namespace foonathan::string_id;
	// create database to store the strings in
	// it must stay valid as long as each string_id using it
	default_database database;
	
	//=== string_id usage ===//
	// create an id
	string_id sid( "Test0815", database );
	
	LOG_F( INFO, "String = %s, hash = %lu", sid.string(), sid.hash_code() );
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
