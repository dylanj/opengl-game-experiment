#include <SDL.h>
#include "log.h"

typedef struct {
  unsigned short width;
  unsigned short height;
  unsigned char bpp;
  int fullscreen;

  SDL_Surface *screen;

} settings_t;

int create_window( settings_t * );
