#include "log.h"

#define ERROR_PREFIX   "ERROR: "
#define WARNING_PREFIX "WARNING: "
#define DEBUG_PREFIX   "DEBUG: "

// TODO: dry this up and print prefixes

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

void _log( char *prefix, char *suffix, char *format, va_list args ) {
  if ( prefix != NULL )
    fprintf( stdout, "%s", prefix );

  vprintf( format, args );

  if ( suffix != NULL )
    fprintf( stdout, "%s", suffix );
}
