#include "app/EmberApp.h"

#include "events/Event.h"

using namespace ember::core;
using namespace ember::app;
using namespace ember::events;

int main( int argc, char **argv )
{
	EmberApp *app = new EmberApp();
	
	if ( !app->Initialize( argc, argv ) )
	{
		printf( "Failed to initialize the ember game engine - please check the logs for more details." );
		return 1;
	}
	
	EmberVariant vari;
	vari.SetBool( true );
	
	printf( " Bool = %i \n", vari.asBool );
	
	I32 val;
	
	if ( vari.TryGetValue( val ) )
	{
		printf( "Got I32\n" );
	}
	else
	{
		printf( "DID NOT GET I32\n" );
	}
	
	ember::events::Event myEvt( Hash( "TEST" ), 2 );
	myEvt.ArgCount;
	
	StringHash g = ember::core::Hash( "TEST" );
	
	switch ( g.hash_code() )
	{
		case "BLAH"_id:
			printf( "BLAH\n" );
			break;
			
		case "TEST"_id:
			printf( "TEST\n" );
			break;
			
		default:
			printf( "SOMETHING ELSE\n" );
			break;
	}
	
	app->Run();
	
	delete app;
	app = nullptr;
	
	return 0;
}
