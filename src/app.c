#include "app.h"

int create_window( settings_t *settings ) {
  int width      = settings->width;
  int height     = settings->height;
  int fullscreen = settings->fullscreen;
  int bpp        = settings->bpp;

  /* TODO: use SDL_HWSURFACE later */
  settings->screen = SDL_SetVideoMode( width, height, bpp, SDL_OPENGL );

  if ( settings->screen == NULL ) {
    log_error( "couldn't set video resolution (%ix%i@%i) (%s)", width, height, bpp, SDL_GetError() );
  }

  SDL_WM_SetCaption( "fishes boom engine", NULL );

  log_debug( "successfully created window (%ix%i@%i)", width, height, bpp );

  return 1;
}
