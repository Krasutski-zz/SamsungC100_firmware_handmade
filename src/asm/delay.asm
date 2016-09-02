@ Samsung SGH-C100
@ other function
@ pause-

.thumb
.align 2

pause:
		@ in:
		@	
		@ out:
		@	
	push	{r0,r1,r2,r3,lr}

	mov r0,#0
	mov r1,#0
	mov r2,#0
	mov r3,#0	
label1:
	add r0,#1
	cmp r0,#0xff
	bne label1
	mov r0,#0
	add r1,#1
	cmp r1,#0xff
	bne label1
	mov r1,#0
	add r2,#1
	cmp r2,#0x9
	bne label1


	pop	{r0,r1,r2,r3,r7}
	bx	r7


pas:
		@ in:
		@	
		@ out:
		@	
	push	{r0,r1,r2,r3,lr}

	mov r0,#0
	mov r1,#0
	mov r2,#0
	mov r3,#0	
label2:
	add r0,#1
	cmp r0,#0xff
	bne label2
	mov r0,#0
	add r1,#1
	cmp r1,#0xff
	bne label2



	pop	{r0,r1,r2,r3,r7}
	bx	r7


ps:
		@ in:
		@	
		@ out:
		@	
	push	{r0,lr}

	mov r0,#0
	mov r1,#0
	mov r2,#0
	mov r3,#0	
label3:
	add r0,#1
	cmp r0,#0xff
	bne label3



	pop	{r0,r7}
	bx	r7


.ltorg
