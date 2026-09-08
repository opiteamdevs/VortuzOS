#include "../include/kernel_utils.h"
#include "../include/network.h"

// Função para ler portas de E/S do hardware (Port I/O)
static inline u32 pci_read_config(u8 bus, u8 slot, u8 func, u8 offset) {
    // Comunicação básica com o barramento PCI para achar a placa de rede
    // (Endereço padrão de configuração PCI: 0xCF8 e 0xCFC)
    return 0; 
}

void net_init(void) {
    safe_print("[NET] Inicializando subsistema de rede do VortuzOS...\n");

    if (ethernet_boot_init()) {
        safe_print("[NET] Ethernet conectada e pronta no boot! 🌐\n");
    } else {
        safe_print("[NET] AVISO: Nenhuma interface Ethernet compativel encontrada.\n");
        
        // Se não achar cabo, tenta o fallback para Wi-Fi
        if (wifi_boot_init()) {
            safe_print("[NET] Modulo Wi-Fi inicializado com sucesso! 📶\n");
        } else {
            safe_print("[NET] ERRO: Nenhuma conexao de rede disponivel no boot.\n");
        }
    }
}

bool ethernet_boot_init(void) {
    safe_print("[NET] Escaneando barramento PCI por controladoras Ethernet (Intel E1000)...\n");
    
    // Aqui no futuro a gente mapeia os registradores MMIO da placa de rede
    // Para começar, vamos simular que o driver detectou a interface física:
    bool placa_encontrada = true; 

    if (placa_encontrada) {
        safe_print("[NET] Chipset Ethernet mapeado com sucesso no espaco de memoria!\n");
        return true;
    }
    
    return false;
}

bool wifi_boot_init(void) {
    safe_print("[NET] Tentando inicializar driver de Wi-Fi generico...\n");
    // Inicialização do firmware da placa wireless
    return false;
}
