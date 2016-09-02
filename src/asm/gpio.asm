.thumb
.align 2

@--------------------
red:
	push {r0,r1,lr}

	ldr	r1, =gpio_a_data	@ GPIO_A_control
	ldr	r0, =red_led	@ signal A[5]
	str	r0, [r1]
	
	pop {r0,r1,r7}
	bx r7
@--------------------
@--------------------
blue:
	push {r0,r1,lr}


	ldr	r1, =gpio_a_data	@ GPIO_A_control
	ldr	r0, =blue_led	@ signal A[5]
	str	r0, [r1]

	pop {r0,r1,r7}
	bx r7
@--------------------
@--------------------
green:
	push {r0,r1,lr}

	ldr	r1, =gpio_a_data	
	ldr	r0, =green_led
	str	r0, [r1]

	
	pop {r0,r1,r7}
	bx r7
@--------------------
LCDled:
	push {r0,r1,lr}

	ldr	r1, =gpio_a_data	
	ldr	r0, =lcd_led
	str	r0, [r1]

	
	pop {r0,r1,r7}
	bx r7
@--------------------
keybled:
	push {r0,r1,lr}

	ldr	r1, =gpio_a_data	
	ldr	r0, =keyb_led
	str	r0, [r1]

	
	pop {r0,r1,r7}
	bx r7

@--------------------@--------------------
red_on:
	push {r0,r1,r2,lr}

	ldr	r1, =gpio_a_data	
	ldr	r0, =red_led	
	ldr	r2,[r1]
	orr	r0,r2
	str	r0, [r1]
	
	pop {r0,r1,r2,r7}
	bx r7
@--------------------
@--------------------
blue_on:
	push {r0,r1,r2,lr}


	ldr	r1, =gpio_a_data	@ GPIO_A_control
	ldr	r0, =blue_led	@ signal A[5]
	ldr	r2,[r1]
	orr	r0,r2
	str	r0, [r1]

	pop {r0,r1,r2,r7}
	bx r7
@--------------------
@--------------------
green_on:
	push {r0,r1,r2,lr}

	ldr	r1, =gpio_a_data	
	ldr	r0, =green_led
	ldr	r2,[r1]
	orr	r0,r2
	str	r0, [r1]

	

	
	pop {r0,r1,r2,r7}
	bx r7
@--------------------
LCDled_on:
	push {r0,r1,r2,lr}

	ldr	r1, =gpio_a_data	
	ldr	r0, =lcd_led
	ldr	r2,[r1]
	orr	r0,r2
	str	r0, [r1]

	
	
	pop {r0,r1,r2,r7}
	bx r7
@--------------------
keybled_on:
	push {r0,r1,r2,lr}

	ldr	r1, =gpio_a_data	
	ldr	r0, =keyb_led
	ldr	r2,[r1]
	orr	r0,r2
	str	r0, [r1]

	
	
	pop {r0,r1,r2,r7}
	bx r7

@--------------------@--------------------@--------------------
red_off:
	push {r0,r1,r2,lr}

	ldr	r1, =gpio_a_data	
	ldr	r0, =0x2020
	ldr	r2,[r1]
	
	eor	r2,r0
	str	r2, [r1]
	
	pop {r0,r1,r2,r7}
	bx r7
@--------------------
@--------------------
blue_off:
	push {r0,r1,r2,lr}


	ldr	r1, =gpio_a_data	@ GPIO_A_control
	ldr	r0, =0x4040	@ signal A[5]
	ldr	r2,[r1]
	eor	r2,r0
	str	r2, [r1]

	pop {r0,r1,r2,r7}
	bx r7
@--------------------
@--------------------
green_off:
	push {r0,r1,r2,lr}

	ldr	r1, =gpio_a_data	
	ldr	r0, =0x0808
	ldr	r2,[r1]
	eor	r2,r0
	str	r2, [r1]

	

	
	pop {r0,r1,r2,r7}
	bx r7
@--------------------
LCDled_off:
	push {r0,r1,r2,lr}

	ldr	r1, =gpio_a_data	
	ldr	r0, =lcd_led
	ldr	r2,[r1]
	bic	r0,r2
	strh	r0, [r1]

	
	
	pop {r0,r1,r2,r7}
	bx r7
@--------------------
keybled_off:
	push {r0,r1,r2,lr}

	ldr	r1, =gpio_a_data	
	ldr	r0, =keyb_led
	ldr	r2,[r1]
	bic	r0,r2
	strh	r0, [r1]

	
	
	pop {r0,r1,r2,r7}
	bx r7

@--------------------
white:
	push {r0,r1,lr}

	ldr	r1, =gpio_a_data	@ GPIO_A_control
	ldr	r0, =white_led	@ signal A[5]
	str	r0, [r1]
	
	pop {r0,r1,r7}
	bx r7
@--------------------
@--------------------
off_leds:
	push {r0,r1,lr}

	ldr	r1, =gpio_a_data	@ GPIO_A_control
	ldr	r0, =0x0ff
	str	r0, [r1]
	
	pop {r0,r1,r7}
	bx r7
@--------------------
init_gpio:

@init gpioA
	push {r0,r1,lr}
	
	ldr	r1, =gpio_a_data	
	ldr	r0, =0b0000000011111111
	str	r0, [r1]

	ldr	r1, =gpio_a_sel
	ldr	r0, =0x00	
	str	r0, [r1]


	ldr	r1, =gpio_a_cntr	
	ldr	r0, =0b0000001000000010	
	str	r0, [r1]


	pop {r0,r1,r7}
	bx r7

.ltorg