#include "SDL_thread.h"
#include "app.h"
#include "log.h"
#include "thread.h"

thread_t *thread_create( int (*fn)(void *), void *data, char *thread_name ) {
  thread_t *thread = malloc( sizeof( thread_t ) );

  thread->func = fn,
  thread->data = data;
  thread->name = thread_name;

  thread->thread = SDL_CreateThread( fn, data );

  if ( thread->thread == NULL ) {
    log_error( "failed to create (%s) thread (%s)", thread_name, SDL_GetError() );
  }

  // TODO: keep track of threads automatically.

  return thread;
}

void thread_cleanup( thread_t *thread ) {
  SDL_WaitThread( thread->thread, NULL );

  log_debug( "cleaning up thread %s", thread->name );

  free( thread );
}

