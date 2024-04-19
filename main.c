/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "test.pb-c.h" // Substitua "your_package_name" pelo nome do seu pacote

typedef struct __attribute__((packed))
{
    uint8_t mac[6];
    int8_t rssi;
    uint8_t raw[26];
} hg_ble_msg_pack_t;

int siz = sizeof(hg_ble_msg_pack_t);

int main() {
    // Inicializa a mensagem protobuf
    HgBleMsgPack msg_pack = HG_BLE_MSG_PACK__INIT;
    uint8_t mac[] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
    uint8_t raw[] = {
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
        0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
        0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12,
        0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
        0x19, 0x1A
    };
    // msg_pack.mac.data = mac;
    // msg_pack.mac.len = sizeof(mac);
    // msg_pack.rssi = -60; // Exemplo de valor RSSI
    // msg_pack.raw.data = raw;
    // msg_pack.raw.len = sizeof(raw);
    msg_pack.timestamp = 0xcc00;

    // Calcula o tamanho da mensagem
    size_t msg_size = hg_ble_msg_pack__get_packed_size(&msg_pack);
    uint8_t *buffer = malloc(msg_size); // Aloca memória para armazenar a mensagem

    // Serializa a mensagem
    hg_ble_msg_pack__pack(&msg_pack, buffer);

    // Imprime os bytes no formato hexadecimal
    printf("Mensagem serializada em formato hexadecimal (%d):\n", msg_size);
    for (size_t i = 0; i < msg_size; i++) {
        printf("%02x", buffer[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(buffer);

    return 0;
}
