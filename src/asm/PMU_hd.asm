@ Samsung SGH-C100
@ Power Management Unit (PMU)
@ Uses IIC_hd.asm and IIC.asm

.thumb
.align 2

PMU_read_register:
		@ in:
		@	r1 -- register
		@ out:
		@	r1 - byte

	push	{lr}

	@ start condition
	bl	IIC_set_data_1
	bl	IIC_set_clock_1
	bl	IIC_set_data_0
	bl	IIC_set_clock_0

	mov	r0, #0x91	@ PMU addr | read bit
	bl	IIC_send_byte

	mov	r0, r1		@ register
	bl	IIC_send_byte

	bl	IIC_get_byte	@ out: r1

	@ stop condition
	bl	IIC_set_data_0
	bl	IIC_set_clock_1
	bl	IIC_set_data_1

	pop	{r7}
	bx	r7

PMU_write_register:
		@ in:
		@	r1 -- register
		@	r2 -- value
		@ out:
		@	r1 - byte

	push	{lr}

	@ start condition
	bl	IIC_set_data_1
	bl	IIC_set_clock_1
	bl	IIC_set_data_0
	bl	IIC_set_clock_0

	mov	r0, #0x90	@ PMU addr
	bl	IIC_send_byte

	mov	r0, r1		@ register
	bl	IIC_send_byte

	mov	r0, r2		@ value
	bl	IIC_send_byte

	@ stop condition
	bl	IIC_set_data_0
	bl	IIC_set_clock_1
	bl	IIC_set_data_1

	pop	{r7}
	bx	r7





PMU_power_on:
		@ in:	no data
		@ out:	no data

	push	{r1,r2,lr}
	mov	r1, #0x3	@ PMU register
	mov	r2, #0x1	@ set bit [0] (now we don't warry about other bits)
	bl	PMU_write_register

	pop	{r1,r2,r7}
	bx	r7

PMU_power_off:
		@ in:	no data
		@ out:	no data

	push	{r1,r2,lr}
	mov	r1, #0x3        @ PMU register
	mov	r2, #0x0	@ clear bit [0] (now we don't warry about other bits)
	bl	PMU_write_register

	pop	{r1,r2,r7}
	bx	r7

.ltorg
