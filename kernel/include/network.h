#ifndef NETWORK_H
#define NETWORK_H

#include "kernel_utils.h"

// Inicializa as interfaces de rede no boot
void net_init(void);

// Tenta iniciar a conexão via Ethernet (Procurando controladora E1000 no barramento PCI)
bool ethernet_boot_init(void);

// Simulação de handshake inicial de Wi-Fi para o kernel
bool wifi_boot_init(void);

#endif
