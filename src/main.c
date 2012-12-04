#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <X11/Xlib.h>

#include "log.h"
#include "app.h"
#include "game.h"

int main(int argc, char *argv[])
{
  settings_t *settings = malloc( sizeof( settings_t ) );

  settings->width      = 800;
  settings->height     = 600;
  settings->bpp        = 24;
  settings->fullscreen = 1;

  settings->exit_game  = 0;
  settings->should_exit = 0;

  XInitThreads();
  int sdl_flags  = SDL_INIT_EVERYTHING;

  if ( SDL_Init( sdl_flags ) < 0 ) {
    log_error( "couldn't init sdl (%s)", SDL_GetError() );
    return 0;
  }

  //main
  //input thread
  //video thread
  //network thread
  //audio thread

  game_start_video_thread( settings );
  if ( !settings->video_thread )
    settings->exit_game = 1;

  game_start_input_thread( settings );
  if ( !settings->input_thread )
    settings->exit_game = 1;

  game_start_logic_thread( settings );
  if ( !settings->logic_thread )
    settings->exit_game = 1;

  log_debug( "all threads spawned" );
  /* while ( !settings->exit_game ) { */
  /*   game_process_local_input(); */
  /*   game_update_entities(); */
  /*   game_draw_entities(); */
  /* } */

  thread_cleanup( settings->video_thread );
  thread_cleanup( settings->input_thread );
  thread_cleanup( settings->logic_thread );

  return 0;
}

/*
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    struct sockaddr_in serv_addr; 

    if(argc != 2)
    {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    } 

    memset(recvBuff, '0',sizeof(recvBuff));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000); 

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return 1;
    } 

    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("\n Error : Connect Failed \n");
       return 1;
    } 

    while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
        recvBuff[n] = 0;
        if(fputs(recvBuff, stdout) == EOF)
        {
            printf("\n Error : Fputs error\n");
        }
    } 

    if(n < 0)
    {
        printf("\n Read error \n");
    } 

    return 0;
}
*/

