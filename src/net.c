#include 'net.h'

int net_send_message( net_msg_t* msg ) {

}

int _net_msg_length( net_msg_t* msg ) {
  return sizeof( struct net_msg_s ) + ( msg->length * sizeof(char) );
}
