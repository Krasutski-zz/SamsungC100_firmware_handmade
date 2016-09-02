@ PMU_example.asm

.arm
start:
	
	adr	lr, main+1
	bx	lr		@ set thumb mode

.thumb
main:

	bl	PMU_power_on
	bl	init_gpio
	bl	init_keyb
	
	bl	LCDled_on
	bl	init_LCD


	mov r1,#0x0	
	mov r2,#0x0	
	mov r3,#0x80	
	mov r4,#0x80
	ldr r5,=logo
	bl LCD_draw_rect

	
megaloop:
	bl getkey


@flashled\/
	bl pas
	bl red_off
	bl blue_on
	bl pas
	bl green_on
	bl pas
	bl blue_off
	bl pas
	bl red_on
	bl pas
	bl green_off
	bl pas
	bl blue_on
@flashled/\
	

	b	megaloop





.include	"IIC.asm"
.include	"IIC_hd.asm"
.include	"PMU_hd.asm"
@.include	"display.asm"
.include	"LCD_hd.asm"
.include	"delay.asm"
.include	"cx805.inc"
.include	"gpio.asm"
.include	"keypad.asm"

.align 2
logo:
	@.incbin "logo.bin"
	.incbin "ph.bin"


.ltorg
