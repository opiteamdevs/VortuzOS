; boot.asm - Ponto de entrada do IoKeyupy Kernel
MBER_ALIGN     equ 1<<0               ; alinhar módulos carregados em páginas de memória
MEMINFO        equ 1<<1               ; fornecer mapa de memória
FLAGS          equ MBER_ALIGN | MEMINFO ; flags do multiboot
MAGIC          equ 0x1BADB002         ; número mágico do multiboot para o bootloader achar
CHECKSUM       -(MAGIC + FLAGS)       ; checksum para provar que somos multiboot

section .multiboot
align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

section .bss
align 16
stack_bottom:
resb 16384 ; 16 Kilobytes para a pilha do kernel
stack_top:

section .text
global start
extern kmain

start:
    ; Configura a pilha (stack) do sistema
    mov esp, stack_top

    ; Chama o kernel principal escrito em C
    call kmain

    ; Trava a CPU caso o kernel retorne por algum motivo
.hang:
    cli
    hlt
    jmp .hang
    
