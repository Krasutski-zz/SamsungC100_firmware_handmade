.thumb
.align 2

@---------------------------
init_keyb:
	push {r0,r1,lr}
	
	ldr	r2, =0x40800	@ keyb control
	ldr	r0, =0x00	@ 0-output strobe
	strh	r0, [r2]	@save 

	ldr	r2, =0x40802	@ Strobe data key
	ldr	r0, =0x00
	strh	r0, [r2]	@save 

	pop {r0,r1,r7}
	bx r7
@---------------------------

getkey:
	push {r0,r1,lr}

	ldr r1,=0x40804
	ldr r0,[r1]
	cmp r0,#0x1f
	beq ret

	
	cmp r0,#0x1e
	beq row1

	cmp r0,#0x1d
	beq row2

	cmp r0,#0x1b
	beq row3

	cmp r0,#0x17
	beq pwkey

ret:

	pop {r0,r1,r7}
	bx r7


row1:
	bl LCDled
	bl pause
	bl PMU_power_off
	b ret
row2:

	

	b ret
row3:
	
	b ret

pwkey:
	@bl off_leds
	b ret




.ltorg