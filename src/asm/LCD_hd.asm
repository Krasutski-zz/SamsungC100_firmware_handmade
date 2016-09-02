@ Samsung SGH-C100
@ Liquid Crystal Display (LCD) driver

.equ LCD_base,		0x00C00000
.equ LCD_data,		0x00C80000

.equ CS_base,		0x00040000
.equ CS3_cfg,		0x00040016

.thumb
.align 2

init_LCD:
		@ Description: initialization procedure.
		@ First GPIO must be initalizated

	push	{r0,r1,lr}

	ldr	r7, =0x04028a
	mov	r1, #0x4	
	strh	r1, [r7]

	mov	r1, #0b10110001
	@bl	GPIO_set_bit	@ set GPIO D[1] (LCD_select) signal
	ldr r1,=gpio_d_cntr
	ldr r0,=0x2
	strh r0,[r1]




	ldr	r7, =CS3_cfg
	ldr	r0, =0x105
	strh	r0, [r7]

	ldr	r1, =LCD_base
	adr	r0, LCD_init_table

@LCD_init_send_pack:
@	ldrb	r7, [r0]
@	cmp	r7, #0xFF		@ EOT
@	beq	LCD_init_loop_end
@
@	add	r0, #1
@	strb	r7, [r1]
@	b	LCD_init_send_pack

	ldr	r0,=0x2C
	strb	r0,[r1]
	ldr	r0, =0x02
	strb	r0,[r1]
	ldr	r0, =0x01
	strb	r0,[r1]
	ldr	r0, =0x20
	strb	r0,[r1]
	ldr	r0, =0x05
	strb	r0,[r1]
	ldr	r0, =0x26
	strb	r0,[r1]
	ldr	r0, =0x0F
	strb	r0,[r1]
	ldr	r0, =0x10
	strb	r0,[r1]
	ldr	r0, =0x04
	strb	r0,[r1]
	ldr	r0, =0x22
	strb	r0,[r1]
	ldr	r0, =0x01	
	strb	r0,[r1]
	ldr	r0, =0x34
	strb	r0,[r1]
	ldr	r0, =0x8D 
	strb	r0,[r1]
	ldr	r0, =0x2A
	strb	r0,[r1]
	ldr	r0, =0xA8
	strb	r0,[r1]
	ldr	r0, =0x51
	strb	r0,[r1]

lf: b lf

LCD_init_loop_end:
	bl	LCDled_on

	pop	{r0,r1,r7}
	bx	r7

@===============================================================================
LCD_draw_rect:
		@ Description: drawing a rectangle to specified area
		@ in:
		@	r1 - X left (0x0 .. 0x7F)
		@	r2 - Y top (0x0 .. 0x7F)
		@	r3 - X size (0x0 .. 0x7F)
		@	r4 - Y size (0x0 .. 0x7F)
		@	r5 - videodata adress

	push	{r0,r6}

	ldr	r6, =LCD_base

	mov	r0, #0x43
	strh	r0, [r6]
	add	r1, #0x10
	strh	r1, [r6]
	add	r1, r1, r3
	sub	r1, #1
	strh	r1, [r6]

	mov	r0, #0x42
	strh	r0, [r6]
	strh	r2, [r6]
	add	r2, r2, r4
	sub	r2, #1
	strh	r2, [r6]

	ldr	r1, =LCD_data
	mul	r3, r4		@ number of pixels = X size * Y size

LCD_fill_loop:
	ldrh	r0, [r5]
	strh	r0, [r1]
	add	r5, #2
	sub	r3, #1
	bne	LCD_fill_loop

	pop	{r0,r6}
	bx	lr

@===============================================================================
@===============================================================================
LCD_white:

	push	{r0,r1,r2,lr}

	ldr	r2, =LCD_base

	mov	r0, #0x43
	strh	r0, [r2]
	mov	r1,#0x10
	strh	r1, [r2]
	mov	r1,#0x90
	strh	r1, [r2]

	mov	r0, #0x42
	strh	r0, [r2]
	mov	r1,#0x0
	strh	r1, [r2]
	mov	r1,#0x80
	strh	r1, [r2]

	ldr	r2, =LCD_data
	ldr	r1,=0x4000

lloop:
	@ldr	r0, =0xffff
	ldr	r0, =0b0000011100000000
	str	r0, [r2]
	sub	r1, #1
	bne	lloop

	pop	{r0,r1,r2,r7}
	bx	r7

@===============================================================================
LCD_contrast:
		@ Description: sets contrast level
		@ in:
		@	r1 - contrast level (0x80..0xff)

	push	{r0-r2}

	ldr	r2, =LCD_base
	mov	r0, #0x2A		@ contrast command
	strh	r0, [r2]
	strh	r1, [r2]

	pop	{r0-r2}
	bx	lr













.align 2
LCD_init_table:
	.byte	0x2C, 0x02, 0x01
	.byte	0x20, 0x05
	.byte	0x26, 0x0F
	.byte	0x10, 0x04
	.byte	0x22, 0x01	
	.byte	0x34, 0x8D 
	.byte	0x2A, 0xA8
	.byte	0x51

	.byte	0xFF	@ end of table

@ original initialization sequence:
@	.byte	0x2C, 0x02, 0x01	@ unknown
@	.byte	0x20, 0x05	@ unknown
@	.byte	0x26, 0x01	@ |
@	.byte	0x26, 0x09	@ |
@	.byte	0x26, 0x0B	@ |
@	.byte	0x26, 0x0F	@ |> bits 0..3 must be 1 for work
@	.byte	0x28, 0x00
@	.byte	0x2E, 0x45, 0x00
@	.byte	0x53, 0x00	@ palette: 0x00 -- normal, 0x01 -- inverted
@	.byte	0x10, 0x04	@ significant are bits: 2,4,5
		@ 2 - drawing order:	0 up->down & right->left
		@			1 up->down & left->right
		@ bits 4,5 has four states. Fadeind and sliding
@	.byte	0x24, 0x22, 0x30, 0x1C, 0x32, 0x0E, 0x40, 0x00
@	.byte	0x34, 0x8D	@ must be for good colors
@	.byte	0x22, 0x11	@ bits 0,1 are significant bit0 is 1 - normal contrast
@	.byte	0x2A, 0x50
@	.byte	0x43, 0x10, 0x8F
@	.byte	0x42, 0x00, 0x7F
@	.byte	0x2A, 0xA8	@ contrast level (0x80..0xff)
@	.byte	0x51		@ unknown

.ltorg
