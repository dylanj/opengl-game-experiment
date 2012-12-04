#ifndef game_h
#define game_h

#include "log.h"

void game_update_entities();
void game_draw_entities();
void game_start_input_thread();
void game_start_logic_thread();
void game_start_video_thread();

void game_process_local_input( settings_t * );
void game_process_logic( settings_t * );
void game_process_video( settings_t * );

#endif

