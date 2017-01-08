#include "app/EmberApp.h"

using namespace ember::core;
using namespace ember::app;

int main( int argc, char **argv )
{
	EmberApp *app = new EmberApp();
	
	if ( !app->Initialize( argc, argv ) )
	{
		printf( "Failed to initialize the ember game engine - please check the logs for more details." );
		return 1;
	}
	
	app->Run();
	
	delete app;
	app = nullptr;
	
	return 0;
}
