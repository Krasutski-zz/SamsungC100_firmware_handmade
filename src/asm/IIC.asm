@ Inter IC interface (IIC)
@ depends on iic_hd.asm	(hardware driver)

.thumb
.align 2

IIC_send_packet:
		@ in:
		@	r1 -- packet address
		@ packet structure (we mustn't use 0 or 0xff as end_of_packet
		@ symbol, because packet may contain any data char):
		@	byte 1 -- length
		@ out: no data

	push	{r0-r4, lr}
	ldrb	r2, [r1]	@ load counter with packet_length

	@ execute start condition
	bl	IIC_set_data_1
	bl	IIC_set_clock_1
	bl	IIC_set_data_0
	bl	IIC_set_clock_0

IIC_send_loop:
	add	r1, #1
	ldrb	r0, [r1]
	bl	IIC_send_byte

	sub	r2, #1		@ dec counter
	bne	IIC_send_loop

	@ exit transmission, execute stop condition
	bl	IIC_set_data_0
	bl	IIC_set_clock_1
	bl	IIC_set_data_1

	pop	{r0-r4, r7}
	bx	r7

@===============================================================================
IIC_get_byte:
		@ in: no parameters
		@ out:
		@	r1 -- received byte

	push	{r0,lr}

	bl	IIC_set_data_1

	mov	r1, #0		@ byte for result
	mov	r7, #7		@ counter

1:
	bl	IIC_set_clock_1

	bl	IIC_get_data
	cmp	r0, #0
	beq	2f

	mov	r0, #1
	lsl	r0, r7
	orr	r1, r0

2:
	bl	IIC_set_clock_0

	sub	r7, #1
	bge	1b

	@ generate acknowledge-related clock pulse
	bl	IIC_set_data_1
	bl	IIC_set_clock_1
	bl	IIC_set_clock_0

	pop	{r0,r7}
	bx	r7

@===============================================================================
IIC_send_byte:
		@ in:
		@	 r0 -- byte to write
		@ out: no data

	push	{lr}
	mov	r7, #7		@ counter

IIC_send_byte_loop:
	mov	r3, r0
	asr	r3, r7
	mov	r4, #1
	tst	r3, r4
	beq	1f

	bl	IIC_set_data_1
	b	2f

1:
	bl	IIC_set_data_0

2:
	@ generate clock pulse
	bl	IIC_set_clock_1
	bl	IIC_set_clock_0

	sub	r7, #1
	bge	IIC_send_byte_loop

	@ generate acknowledge-related clock pulse
	bl	IIC_set_data_1
	bl	IIC_set_clock_1
	bl	IIC_set_clock_0

	pop	{r7}
	bx	r7

.ltorg
