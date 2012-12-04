#include "app.h"
#include "game.h"
#include "thread.h"

int _game_process_local_input( void *data );
int _game_process_logic( void *data );
int _game_process_video( void *data );

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

void game_start_video_thread( settings_t *settings ) {
  thread_t *video_thread;

  video_thread = thread_create( _game_process_video, settings, "video" );

  settings->video_thread = video_thread;
}

int _game_process_logic( void *data ) {
  game_process_logic( data ); return 0; }
void game_process_logic( settings_t *settings ) {
  log_debug( "starting logic thread" );

  while( !settings->exit_game ) {
    //Clear color buffer
  }

  log_debug( "exiting logic thread" );
}

int _game_process_video( void *data ) {
  game_process_video( data ); return 0; }
void game_process_video( settings_t *settings ) {
  log_debug( "starting video thread" );

  create_window( settings );

  glClearColor( 0.1f, 0.2f, 0.3f, 1.0f );

  while( !settings->exit_game ) {
    //Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );
    SDL_GL_SwapBuffers();
  }

  log_debug( "exiting video thread" );
}

int _game_process_local_input( void *data ) {
  game_process_local_input( data ); return 0; }
void game_process_local_input( settings_t *settings ) {
  log_debug( "starting input thread" );

  SDL_Event event;

  while( !settings->exit_game ) {
    while ( SDL_PollEvent(&event) ) {
      switch (event.type) {
        case SDL_MOUSEMOTION:
          printf("Mouse moved by %d,%d to (%d,%d)\n", 
          event.motion.xrel, event.motion.yrel,
          event.motion.x, event.motion.y);
          break;
        case SDL_MOUSEBUTTONDOWN:
          printf("Mouse button %d pressed at (%d,%d)\n",
            event.button.button, event.button.x, event.button.y);
          break;
        case SDL_QUIT:
          // todo: add a way to ask "whoa buddy are you sure you want to quit?"
          log_warning( "exiting game" );
          settings->exit_game = 1;
          break;
      }
    }
  }

  log_debug( "exiting input thread" );
}

void game_update_entities() {
  // do things
}

void game_draw_entities() {
  // do things
}
