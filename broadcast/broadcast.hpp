#ifndef __BD_SO_BROADCASTCENTER__
#define __BD_SO_BROADCASTCENTER__
#include <sys/socket.h>
#include <arpa/inet.h>
const int MAXDATASIZE = 256;
namespace bd_so {
	class BroadcastCenter {
		private:
		bool is_sender; /// is a caster;
		bool is_casting; /// is sending broadcast 
		bool is_receiving; /// is waiting broadcast
		void init_addr(); /// init sockets
		int socket_fd;
		struct sockaddr_in my_addr,user_addr;
		char buf[MAXDATASIZE];
		int so_broadcast = 1;
		char my_ip[12];
		public:
		BroadcastCenter(bool is_s):is_sender(is_s) {
			init_addr();
		}		
		void startSend(void); 
		void startReceiving(void);	
	};
};
#endif
