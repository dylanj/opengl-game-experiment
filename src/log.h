#include <stdio.h>
#include <stdarg.h>

#define ANSI_COLOR_ESCAPE     "\x1b["
#define ANSI_COLOR_RESET      ANSI_COLOR_ESCAPE "0m"
#define ANSI_COLOR_BLACK      ANSI_COLOR_ESCAPE "30m"
#define ANSI_COLOR_RED        ANSI_COLOR_ESCAPE "31m"
#define ANSI_COLOR_GREEN      ANSI_COLOR_ESCAPE "32m"
#define ANSI_COLOR_YELLOW     ANSI_COLOR_ESCAPE "33m"
#define ANSI_COLOR_BLUE       ANSI_COLOR_ESCAPE "34m"
#define ANSI_COLOR_PURPLE     ANSI_COLOR_ESCAPE "35m"
#define ANSI_COLOR_TURQUOISE  ANSI_COLOR_ESCAPE "36m"
#define ANSI_COLOR_GREY       ANSI_COLOR_ESCAPE "37m"
#define ANSI_COLOR_GRAY       ANSI_COLOR_ESCAPE "38m"

void _log( char*, char*, char*, va_list );
void log_error( char*, ... );
void log_debug( char*, ... );
void log_warning( char*, ... );

