#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <string>

class WebSocketTransport {

    typedef websocketpp::client<websocketpp::config::asio_client> client;
    typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

    private:
        client mClient;

    public:
        WebSocketTransport(std::string uri);

        void send();
        void run();
};
