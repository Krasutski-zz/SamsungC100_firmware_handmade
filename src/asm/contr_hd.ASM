@ Samsung SGH-C100
@ Inter IC interface (IIC)

.equ CNTRLCLK,	0x40300		
.equ CNTRLRT,	0x40302	
.equ CNTRLDAT,	0x40300		
.equ RESPDAT,	0x40302		

.thumb
.align 2

set_data_0:
		@ in:	no parameters
		@ out:	no data

	push	{r0-r2}

	ldr	r0, =CNTRLDAT
	ldrh	r1, [r0]
	mov	r2, #1
	bic	r1, r2
	strh	r1, [r0]

	pop	{r0-r2}
	bx	lr

@===============================================================================
set_data_1:
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
set_clock_0:
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
set_clock_1:
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
set_rt_0:
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
set_rt_1:
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



.ltorg
