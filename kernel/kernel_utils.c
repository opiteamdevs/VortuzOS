#include "kernel_utils.h"

// Endereço do buffer VGA em modo texto
#define VGA_BUFFER 0xB8000
#define VGA_MAX_COLS 80
#define VGA_MAX_ROWS 25

static u32 cursor_x = 0;
static u32 cursor_y = 0;

// safe_print: Imprime na tela de forma segura validando ponteiros e limites
void safe_print(const char* str) {
    if (str == (void*)0) {
        return; // Proteção contra ponteiro nulo (null pointer dereference)
    }

    u16* video_memory = (u16*)VGA_BUFFER;
    u8 attribute_byte = 0x0F; // Letra branca no fundo preto

    while (*str != '\0') {
        char c = *str++;

        if (c == '\n') {
            cursor_x = 0;
            cursor_y++;
        } else {
            u32 index = cursor_y * VGA_MAX_COLS + cursor_x;
            video_memory[index] = (u16)c | (u16)(attribute_byte << 8);
            cursor_x++;

            if (cursor_x >= VGA_MAX_COLS) {
                cursor_x = 0;
                cursor_y++;
            }
        }

        // Rolagem simples se passar da tela
        if (cursor_y >= VGA_MAX_ROWS) {
            cursor_y = VGA_MAX_ROWS - 1;
            // Aqui depois a gente implementa o scroll da tela inteira se quiser!
        }
    }
}

// osExecute: Prepara e agenda um novo processo no VortuzOS
i32 osExecute(const char* process_name) {
    if (process_name == (void*)0) {
        safe_print("[ERRO] osExecute: Nome de processo invalido!\n");
        return -1; // Falha
    }

    safe_print("[INFO] Iniciando novo processo no VortuzOS: ");
    safe_print(process_name);
    safe_print("\n");

    // TODO: Alocar estrutura PCB (Process Control Block) e carregar na memória
    return 0; // Sucesso simulado
}

// blockProcess: Aplica o bloqueio (Permission Denied) em processos externos maliciosos
void blockProcess(u32 process_id) {
    // Simulação de checagem de privilégio do kernel
    if (process_id < 10) {
        safe_print("[SECURITY] AVISO: Tentativa de bloquear processos do sistema negada!\n");
        return;
    }

    safe_print("[SECURITY] Processo externo isolado com sucesso. Status: PERMISSION DENIED.\n");
    // TODO: Matar o processo ou revogar as flags de acesso à memória protegida
}
