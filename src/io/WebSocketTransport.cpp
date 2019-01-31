#include <WebSocketTransport.h>
#include <string>

WebSocketTransport::WebSocketTransport(std::string uri)
{
    mClient.init_asio();
    mClient.set_access_channels(websocketpp::log::alevel::all);
    mClient.clear_access_channels(websocketpp::log::alevel::frame_payload);
}
