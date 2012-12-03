#include "app.h"

int create_window( settings_t *settings ) {
  int width      = settings->width;
  int height     = settings->height;
  int fullscreen = settings->fullscreen;
  int bpp        = settings->bpp;

  int sdl_flags  = SDL_INIT_AUDIO | SDL_INIT_VIDEO;

  if ( SDL_Init( sdl_flags ) < 0 ) {
    log_error( "couldn't init sdl (%s)", SDL_GetError() );
    return 0;
  }

  /* TODO: use SDL_HWSURFACE later */
  settings->screen = SDL_SetVideoMode( width, height, bpp, SDL_SWSURFACE );

  if ( settings->screen == NULL ) {
    log_error( "couldn't set video resolution (%ix%i@%i) (%s)", width, height, bpp, SDL_GetError() );
  }

  log_debug( "successfully created window (%ix%i@%i) (%s)", width, height, bpp );

  return 1;
}
