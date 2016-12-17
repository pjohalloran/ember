#include <GLFW/glfw3.h>

#define LOGURU_IMPLEMENTATION 1
#include "app/EmberApp.h"

int get_log_level();
void test_loguru( int argc, char **argv );

int main( int argc, char **argv )
{
	using namespace ember::app;
	
	EmberApp *app = new EmberApp();
	app->Initialize();
	
	test_loguru( argc, argv );
	
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
