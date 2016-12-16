#include <GLFW/glfw3.h>

//#include "core/GamePlatform.h"
#define LOGURU_IMPLEMENTATION 1
#include <loguru.hpp>

int get_log_level();
void test_loguru( int argc, char **argv );

int main( int argc, char **argv )
{
	test_loguru( argc, argv );
	
	GLFWwindow *window;
	
	/* Initialize the library */
	if ( !glfwInit() )
		return -1;
		
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow( 640, 480, "Hello World", NULL, NULL );
	
	if ( !window )
	{
		glfwTerminate();
		return -1;
	}
	
	/* Make the window's context current */
	glfwMakeContextCurrent( window );
	
	/* Loop until the user closes the window */
	while ( !glfwWindowShouldClose( window ) )
	{
		/* Render here */
		glClear( GL_COLOR_BUFFER_BIT );
		
		/* Swap front and back buffers */
		glfwSwapBuffers( window );
		
		/* Poll for and process events */
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}

int get_log_level()
{
	return loguru::Verbosity_4;
}

void test_loguru( int argc, char **argv )
{
	loguru::init( argc, argv );
	
	// Put every log message in "everything.log":
	loguru::add_file( "everything.log", loguru::Append, loguru::Verbosity_MAX );
	
	// Only log INFO, WARNING, ERROR and FATAL to "latest_readable.log":
	loguru::add_file( "latest_readable.log", loguru::Truncate, loguru::Verbosity_INFO );
	
	// Only show most relevant things on stderr:
	loguru::g_stderr_verbosity = 1;
	
	bool badness = false;
	int length = 10;
	int a = 5;
	int b = 5;
	
	LOG_SCOPE_F( INFO, "Will indent all log messages within this scope." );
	LOG_F( INFO, "I'm hungry for some %.3f!", 3.14159 );
	LOG_F( 2, "Will only show if verbosity is 2 or higher" );
	VLOG_F( get_log_level(), "Use vlog for dynamic log level (integer in the range 0-9, inclusive)" );
	LOG_IF_F( ERROR, badness, "Will only show if badness happens" );
	//auto fp = fopen(filename, "r");
	//CHECK_F(fp != nullptr, "Failed to open file '%s'", filename);
	CHECK_GT_F( length, 0 ); // Will print the value of `length` on failure.
	CHECK_EQ_F( a, b, "You can also supply a custom message, like to print something: %d", a + b );
}
