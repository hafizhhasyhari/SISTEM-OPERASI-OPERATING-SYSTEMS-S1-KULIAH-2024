#include <stdio.h>
#include <string.h>

// Simulasi struktur data paket
// Dibuat oleh : Hafizh H Asyhari
// Tahun 2024, Indonesia
typedef struct {
    char source[16];
    char destination[16];
    char data[256];
} NetworkPacket;

// Transport Layer: Membungkus data dalam protokol transport
void transport_layer(const char *data, NetworkPacket *packet) {
    strcpy(packet->data, data);
    printf("Transport Layer: Data encapsulated into transport protocol.\n");
}

// Network Layer: Menambahkan alamat sumber dan tujuan
void network_layer(NetworkPacket *packet, const char *src, const char *dest) {
    strcpy(packet->source, src);
    strcpy(packet->destination, dest);
    printf("Network Layer: Packet prepared with Source [%s] and Destination [%s].\n", src, dest);
}

// Physical Layer: Mengirim data
void physical_layer(NetworkPacket *packet) {
    printf("Physical Layer: Sending packet...\n");
    printf("Packet Data:\n");
    printf("Source: %s\nDestination: %s\nData: %s\n", packet->source, packet->destination, packet->data);
}

int main() {
    NetworkPacket packet;
    char data[] = "Hello from OS with OSI!";
    char src[] = "192.168.1.1";
    char dest[] = "192.168.1.2";

    printf("=== OS with OSI Protocol ===\n");
    transport_layer(data, &packet);
    network_layer(&packet, src, dest);
    physical_layer(&packet);

    return 0;
}
