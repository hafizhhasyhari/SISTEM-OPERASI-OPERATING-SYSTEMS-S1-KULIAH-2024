#include <iostream>
#include <string>

// Class untuk paket data
// Dibuat oleh : Hafizh H Asyhari
// Nickname : hafizhhasyhari
// Country : Indonesia.
// Year : 2024
class NetworkPacket {
public:
    std::string source;
    std::string destination;
    std::string data;

    void display() {
        std::cout << "Source: " << source << "\nDestination: " << destination << "\nData: " << data << "\n";
    }
};

// Transport Layer
class TransportLayer {
public:
    void encapsulate(NetworkPacket &packet, const std::string &data) {
        packet.data = data;
        std::cout << "Transport Layer: Data encapsulated.\n";
    }
};

// Network Layer
class NetworkLayer {
public:
    void addAddress(NetworkPacket &packet, const std::string &src, const std::string &dest) {
        packet.source = src;
        packet.destination = dest;
        std::cout << "Network Layer: Addresses added.\n";
    }
};

// Physical Layer
class PhysicalLayer {
public:
    void sendPacket(const NetworkPacket &packet) {
        std::cout << "Physical Layer: Sending packet...\n";
        packet.display();
    }
};

int main() {
    NetworkPacket packet;
    TransportLayer transportLayer;
    NetworkLayer networkLayer;
    PhysicalLayer physicalLayer;

    std::string data = "Hello from OSI Protocol Sim!";
    std::string src = "10.0.0.1";
    std::string dest = "10.0.0.2";

    std::cout << "=== OS with OSI Protocol Simulation ===\n";
    transportLayer.encapsulate(packet, data);
    networkLayer.addAddress(packet, src, dest);
    physicalLayer.sendPacket(packet);

    return 0;
}
