#include "log.h"

#define ERROR_PREFIX   ANSI_COLOR_RED    "ERROR: " ANSI_COLOR_RESET
#define WARNING_PREFIX ANSI_COLOR_GREEN  "WARNING: " ANSI_COLOR_RESET
#define DEBUG_PREFIX   ANSI_COLOR_BLUE "DEBUG: " ANSI_COLOR_RESET

// this is slightly terrible because the only way i can currently
// think of drying this up is by writing some code that calls
// sprintf and to do that i need to allocate some memory and i
// dont want to do that for logging. not yet at least.

void log_warning( char *format, ... ) {
  va_list args;
  va_start( args, format );
  _log(WARNING_PREFIX, "\n", format, args );
  va_end( args );
}

void log_error( char *format, ... ) {
  va_list args;
  va_start( args, format );
  _log(ERROR_PREFIX, "\n", format, args );
  va_end( args );
}

void log_debug( char *format, ... ) {
  va_list args;
  va_start( args, format );
  _log(DEBUG_PREFIX, "\n", format, args );
  va_end( args );
}

void log( char *format, ... ) {
  va_list args;
  va_start( args, format );
  _log(NULL, "\n", format, args );
  va_end( args );
}

void _log( char *prefix, char *suffix, char *format, va_list args ) {
  if ( prefix != NULL )
    fprintf( stdout, "%s", prefix );

  vprintf( format, args );

  if ( suffix != NULL )
    fprintf( stdout, "%s", suffix );
}
