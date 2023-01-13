#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include "client.h"

using namespace std::string_literals;

Client::Client(string username, const int port) : username{ username }, socket{ ic }, port{ port } {}
void Client::connect() {
    socket.connect(tcp::endpoint(
        boost::asio::ip::make_address_v4("127.0.0.1"),
        port
    ));
    boost::system::error_code ec;
    string message = username;
    boost::asio::write(socket, boost::asio::buffer(message), ec);
}

const std::string Client::getUsername() {
    return username;
}

void Client::sendMessage(std::string message, std::string to) {
    std::string data{ getUsername() + ' ' + to + ' ' + message };
    boost::system::error_code ec;
    boost::asio::write(socket, boost::asio::buffer(data), ec); 
}