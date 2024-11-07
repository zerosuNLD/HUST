#include "Client/Client.h"
#include "Router/Router.h"

#define POST 8080
#define POST_VIEW 3001
#define localhost "127.0.0.1"

#define MAX_ThanhVien 100

int main() {
	Client client(localhost, POST);

	Router router = Router(client, POST_VIEW);
	router.start();

	return 0;
}
