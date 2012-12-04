#ifndef app_h
#define app_h

#include <SDL.h> // todo: get rid of this
#include "log.h"
#include "thread.h"

typedef struct {
  unsigned short width;
  unsigned short height;
  unsigned char bpp;
  int fullscreen;

  SDL_Surface *screen; // todo: get rid of this

  int exit_game;
  int should_exit;

  thread_t *input_thread;
  thread_t *logic_thread;

} settings_t;

settings_t settings;

int create_window( settings_t * );

#endif
