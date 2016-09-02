.thumb
.align 2



init_LCD:
	push {r0,r1,r2,lr}
	


	bl LCDled_on
	pop {r0,r1,r2,r7}
	bx r7

test_LCD:
	push {r0,r1,r2,lr}
	
	pop {r0,r1,r2,r7}
	bx r7

.ltorg