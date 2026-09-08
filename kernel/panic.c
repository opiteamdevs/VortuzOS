// panic.c - Tratamento de Erros Fatais para o IoKeyupy (Sem dependências externas)

#include "include/kernel_utils.h"

void kernel_panic(const char* message, const char* file, int line) {
    // Desativa as interrupções imediatamente para congelar o sistema com segurança
    asm volatile("cli");

    safe_print("\n\n========================================\n");
    safe_print("     🚨 KERNEL PANIC NO VORTUZOS! 🚨     \n");
    safe_print("========================================\n");
    safe_print("O nucleo IoKeyupy encontrou um erro fatal.\n\n");
    
    safe_print("Mensagem: ");
    safe_print(message);
    safe_print("\n");

    if (file != (void*)0) {
        safe_print("Arquivo interno afetado.\n");
    }

    safe_print("Sistema travado (HALT) para proteger o hardware.\n");
    safe_print("========================================\n");

    // Trava a CPU eternamente no loop de hlt
    for (;;) {
        asm volatile("hlt");
    }
}
