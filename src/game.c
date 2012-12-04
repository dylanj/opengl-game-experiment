#include "app.h"
#include "game.h"
#include "thread.h"

int _game_process_local_input( void *data );
int _game_process_logic( void *data );

void game_start_input_thread( settings_t *settings ) {
  thread_t *input_thread;

  input_thread = thread_create( _game_process_local_input, settings, "input" );

  settings->input_thread = input_thread;
}

void game_start_logic_thread( settings_t *settings ) {
  thread_t *logic_thread;

  logic_thread = thread_create( _game_process_logic, settings, "logic" );

  settings->logic_thread = logic_thread;
}

int _game_process_logic( void *data ) {
  game_process_logic( data ); return 0; }
void game_process_logic( settings_t *settings ) {
  log_debug( "starting logic thread" );

  while( !settings->exit_game ) {
    printf( "todo: do logic thread" );
  }

  log_debug( "exiting logic thread" );
}

int _game_process_local_input( void *data ) {
  game_process_local_input( data ); return 0; }
void game_process_local_input( settings_t *settings ) {
  log_debug( "starting input thread" );

  while( !settings->exit_game ) {
    printf( "todo: do input thread" );
  }

  log_debug( "exiting input thread" );
}

void game_update_entities() {
  // do things
}

void game_draw_entities() {
  // do things
}
