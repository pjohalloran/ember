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
	
	myEvt[0].handle = "ARG1"_id;
	myEvt[0].SetBool( true );
	
	myEvt[1].handle = "ARG2"_id;
	myEvt[1].SetBool( false );
	
	printf( "Arg 1 bool = %i\n", myEvt[0].asBool );
	printf( "Arg 2 bool = %i\n", myEvt[1].asBool );
	
	EmberVariant tryArg;
	
	if ( myEvt.TryGet( "ARG1"_id, tryArg ) )
	{
		printf( "TryGetArg 1 bool = %i\n", tryArg.asBool );
	}
	
	if ( myEvt.TryGet( "ARG2"_id, tryArg ) )
	{
		printf( "TryGetArg 2 bool = %i\n", tryArg.asBool );
	}
	
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
