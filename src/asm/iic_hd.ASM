@ Samsung SGH-C100
@ Inter IC interface (IIC)

.equ SDA,	0x40300		@ Serial DAta register
.equ SCL,	0x40302		@ Serial CLock register

.thumb
.align 2

IIC_set_data_0:
		@ in:	no parameters
		@ out:	no data

	push	{r0-r2}

	ldr	r0, =SDA
	ldrh	r1, [r0]
	mov	r2, #1
	bic	r1, r2
	strh	r1, [r0]

	pop	{r0-r2}
	bx	lr

@===============================================================================
IIC_set_data_1:
		@ in:	no parameters
		@ out:	no data

	push	{r0-r2}

	ldr	r0, =SDA
	ldrh	r1, [r0]
	mov	r2, #1
	orr	r1, r2
	strh	r1, [r0]

	pop	{r0-r2}
	bx	lr


@===============================================================================
IIC_set_clock_0:
		@ in:	no parameters
		@ out:	no data

	push	{r0-r2}

	ldr	r0, =SCL
	ldrh	r1, [r0]
	mov	r2, #1
	bic	r1, r2
	strh	r1, [r0]

	pop	{r0-r2}
	bx	lr

@===============================================================================
IIC_set_clock_1:
		@ in:	no parameters
		@ out:	no data

	push	{r0-r2}

	ldr	r0, =SCL
	ldrh	r1, [r0]
	mov	r2, #1
	orr	r1, r2
	strh	r1, [r0]

	pop	{r0-r2}
	bx	lr

@===============================================================================
IIC_get_data:
		@ in:	no parameters
		@ out:	r0 -- SDA state (0/1 equ low/high)

	push	{r1}

	ldr	r0, =SDA
	ldrh	r0, [r0]
	mov	r1, #2
	and	r0, r1
	lsl	r0, #1

	pop	{r1}
	bx	lr

.ltorg
