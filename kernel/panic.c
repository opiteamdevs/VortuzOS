// panic.c - Tratamento de Erros Fatais e Kernel Panic para o IoKeyupy

#include <stddef.h>
#include <stdint.h>

// Funções do nosso terminal VGA (definidas no kernel.c)
extern void terminal_initialize(void);
extern void terminal_writestring(const char* data);
extern uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg);
extern void terminal_set_color(uint8_t color); // Caso queira atualizar a cor global

void kernel_panic(const char* message, const char* file, int line) {
    // Desativa as interrupções para o sistema congelar com segurança
    asm volatile("cli");

    // Aqui a gente pode forçar uma limpeza ou mudar a cor se a função existir, 
    // mas vamos mandar o alerta direto no terminal atual:
    
    terminal_writestring("\n\n========================================\n");
    terminal_writestring("     🚨 KERNEL PANIC NO IOKEYUPY! 🚨     \n");
    terminal_writestring("========================================\n");
    terminal_writestring("O VortuzOS encontrou um erro fatal e parou.\n\n");
    
    terminal_writestring("Erro: ");
    terminal_writestring(message);
    terminal_writestring("\n");

    if (file != NULL) {
        terminal_writestring("Arquivo: ");
        terminal_writestring(file);
        terminal_writestring("\n");
    }

    terminal_writestring("Sistema travado para evitar danos.\n");
    terminal_writestring("Reinicie a maquina.\n");
    terminal_writestring("========================================\n");

    // Trava a CPU eternamente no loop de hlt
    for (;;) {
        asm volatile("hlt");
    }
}
