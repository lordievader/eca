	.file	"main.cpp"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%5d"
	.section	.text._Z11printMatrixPA20_ihh,"ax",@progbits
.global	_Z11printMatrixPA20_ihh
	.type	_Z11printMatrixPA20_ihh, @function
_Z11printMatrixPA20_ihh:
	ldi r26,lo8(5)
	ldi r27,0
	ldi r30,lo8(gs(1f))
	ldi r31,hi8(gs(1f))
	jmp __prologue_saves__+((18 - 12) * 2)
1:
/* prologue: function */
/* frame size = 5 */
/* stack size = 17 */
.L__stack_usage = 17
	movw r16,r24
	ldi r24,lo8(20)
	mov r15,r24
	ldi r25,lo8(.LC0)
	mov r12,r25
	ldi r25,hi8(.LC0)
	mov r13,r25
	ldi r18,lo8(5)
	mov r14,r18
	movw r24,r28
	adiw r24,1
	movw r10,r24
.L2:
	movw r8,r16
	ldi r25,40
	add r8,r25
	adc r9,__zero_reg__
.L3:
	movw r30,r16
	ld r24,Z
	ldd r25,Z+1
	subi r16,-2
	sbci r17,-1
	push r25
	push r24
	push r13
	push r12
	push __zero_reg__
	push r14
	push r11
	push r10
	call snprintf
	movw r22,r10
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print5printEPKc
	ldi r22,lo8(_ZZ11printMatrixPA20_ihhE3__c)
	ldi r23,hi8(_ZZ11printMatrixPA20_ihhE3__c)
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print5printEPK19__FlashStringHelper
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	cp r16,r8
	cpc r17,r9
	brne .L3
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print7printlnEv
	dec r15
	cpse r15,__zero_reg__
	rjmp .L2
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print7printlnEv
/* epilogue start */
	adiw r28,5
	ldi r30, lo8(12)
	jmp __epilogue_restores__ + ((18 - 12) * 2)
	.size	_Z11printMatrixPA20_ihh, .-_Z11printMatrixPA20_ihh
	.section	.text._Z11checkMatrixPA20_ihh,"ax",@progbits
.global	_Z11checkMatrixPA20_ihh
	.type	_Z11checkMatrixPA20_ihh, @function
_Z11checkMatrixPA20_ihh:
	push r14
	push r15
	push r16
	push r17
	push r28
	push r29
/* prologue: function */
/* frame size = 0 */
/* stack size = 6 */
.L__stack_usage = 6
	ldi r18,0
	ldi r19,0
	ldi r16,0
.L8:
	movw r26,r24
	add r26,r18
	adc r27,r19
	ldi r20,0
	ldi r21,0
	ldi r17,0
.L11:
	ld r22,X+
	ld r23,X+
	movw r30,r20
	add r30,r18
	adc r31,r19
	movw r28,r30
	subi r28,lo8(-(_ZL1C))
	sbci r29,hi8(-(_ZL1C))
	movw r30,r28
/* #APP */
 ;  63 "/home/lordievader/Projects/Arduino/eca/main.cpp" 1
	lpm r14, Z+
	lpm r15, Z
	
 ;  0 "" 2
/* #NOAPP */
	cp r22,r14
	cpc r23,r15
	breq .L9
	ldi r20,lo8(10)
	ldi r21,0
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print5printEii
	ldi r22,lo8(_ZZ11checkMatrixPA20_ihhE3__c)
	ldi r23,hi8(_ZZ11checkMatrixPA20_ihhE3__c)
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print5printEPK19__FlashStringHelper
	movw r30,r28
/* #APP */
 ;  67 "/home/lordievader/Projects/Arduino/eca/main.cpp" 1
	lpm r22, Z+
	lpm r23, Z
	
 ;  0 "" 2
/* #NOAPP */
	ldi r20,lo8(10)
	ldi r21,0
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print5printEji
	ldi r22,lo8(_ZZ11checkMatrixPA20_ihhE3__c_0)
	ldi r23,hi8(_ZZ11checkMatrixPA20_ihhE3__c_0)
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print5printEPK19__FlashStringHelper
	ldi r20,lo8(10)
	ldi r21,0
	mov r22,r16
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print5printEhi
	ldi r22,lo8(_ZZ11checkMatrixPA20_ihhE3__c_1)
	ldi r23,hi8(_ZZ11checkMatrixPA20_ihhE3__c_1)
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print5printEPK19__FlashStringHelper
	ldi r20,lo8(10)
	ldi r21,0
	mov r22,r17
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print5printEhi
	ldi r22,lo8(_ZZ11checkMatrixPA20_ihhE3__c_2)
	ldi r23,hi8(_ZZ11checkMatrixPA20_ihhE3__c_2)
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print7printlnEPK19__FlashStringHelper
	ldi r24,0
	rjmp .L10
.L9:
	subi r17,lo8(-(1))
	subi r20,-2
	sbci r21,-1
	cpi r17,lo8(20)
	breq .+2
	rjmp .L11
	subi r16,lo8(-(1))
	subi r18,-40
	sbci r19,-1
	cpi r16,lo8(20)
	breq .+2
	rjmp .L8
	ldi r24,lo8(1)
.L10:
/* epilogue start */
	in r28,__SP_L__
	in r29,__SP_H__
	ldi r30, lo8(6)
	jmp __epilogue_restores__ + ((18 - 6) * 2)
	.size	_Z11checkMatrixPA20_ihh, .-_Z11checkMatrixPA20_ihh
	.section	.text.setup,"ax",@progbits
.global	setup
	.type	setup, @function
setup:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	ldi r20,0
	ldi r21,lo8(-62)
	ldi r22,lo8(1)
	ldi r23,0
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN14HardwareSerial5beginEm
	ret
	.size	setup, .-setup
	.section	.rodata.str1.1
.LC1:
	.string	" us"
.LC2:
	.string	" ticks"
.LC3:
	.string	" ticks per multiplication"
	.section	.text.loop,"ax",@progbits
.global	loop
	.type	loop, @function
loop:
	ldi r26,lo8(-80)
	ldi r27,lo8(4)
	ldi r30,lo8(gs(1f))
	ldi r31,hi8(gs(1f))
	jmp __prologue_saves__+((18 - 16) * 2)
1:
/* prologue: function */
/* frame size = 1200 */
/* stack size = 1216 */
.L__stack_usage = 1216
	ldi r22,lo8(_ZZ4loopE3__c)
	ldi r23,hi8(_ZZ4loopE3__c)
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print7printlnEPK19__FlashStringHelper
	ldi r18,0
	ldi r19,0
	movw r16,r28
	subi r16,-33
	sbci r17,-4
.L16:
	ldi r24,0
	ldi r25,0
.L17:
	movw r20,r24
	add r20,r18
	adc r21,r19
	movw r30,r20
	subi r30,lo8(-(_ZL1A))
	sbci r31,hi8(-(_ZL1A))
/* #APP */
 ;  117 "/home/lordievader/Projects/Arduino/eca/main.cpp" 1
	lpm r22, Z+
	lpm r23, Z
	
 ;  0 "" 2
/* #NOAPP */
	movw r30,r16
	add r30,r20
	adc r31,r21
	st Z,r22
	adiw r24,1
	cpi r24,20
	cpc r25,__zero_reg__
	brne .L17
	subi r18,-20
	sbci r19,-1
	cpi r18,-112
	ldi r20,1
	cpc r19,r20
	brne .L16
	call micros
	movw r12,r22
	movw r14,r24
	ldi r25,lo8(-23)
	mov r10,r25
	ldi r25,lo8(3)
	mov r11,r25
.L18:
	movw r18,r28
	subi r18,-1
	sbci r19,-1
	movw r8,r16
.L21:
	movw r6,r16
	ldi r24,0
	ldi r25,0
.L25:
	movw r26,r6
	ldi r20,0
	ldi r21,0
	mov r4,__zero_reg__
	mov r5,__zero_reg__
.L19:
	movw r22,r8
	add r22,r20
	adc r23,r21
	movw r30,r22
	ld r23,Z
	ld r22,X
	muls r23,r22
	add r4,r0
	adc r5,r1
	clr __zero_reg__
	subi r20,-1
	sbci r21,-1
	adiw r26,20
	cpi r20,20
	cpc r21,__zero_reg__
	brne .L19
	movw r26,r18
	add r26,r24
	adc r27,r25
	st X+,r4
	st X,r5
	adiw r24,2
	ldi r31,-1
	sub r6,r31
	sbc r7,r31
	cpi r24,40
	cpc r25,__zero_reg__
	brne .L25
	subi r18,-40
	sbci r19,-1
	ldi r20,20
	add r8,r20
	adc r9,__zero_reg__
	cp r18,r16
	cpc r19,r17
	brne .L21
	ldi r21,1
	sub r10,r21
	sbc r11,__zero_reg__
	brne .L18
	call micros
	movw r18,r22
	movw r20,r24
	sub r18,r12
	sbc r19,r13
	sbc r20,r14
	sbc r21,r15
	movw r12,r18
	movw r14,r20
	ldi r20,lo8(20)
	ldi r22,lo8(20)
	movw r24,r28
	adiw r24,1
	call _Z11checkMatrixPA20_ihh
	tst r24
	breq .L23
	ldi r20,lo8(20)
	ldi r22,lo8(20)
	movw r24,r28
	adiw r24,1
	call _Z11printMatrixPA20_ihh
.L23:
	movw r24,r14
	movw r22,r12
	ldi r18,lo8(-24)
	ldi r19,lo8(3)
	ldi r20,0
	ldi r21,0
	call __udivmodsi4
	movw r12,r18
	movw r14,r20
	ldi r18,lo8(10)
	ldi r19,0
	movw r22,r14
	movw r20,r12
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print5printEmi
	ldi r22,lo8(.LC1)
	ldi r23,hi8(.LC1)
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print7printlnEPKc
	ldi r24,4
	1:
	lsl r12
	rol r13
	rol r14
	rol r15
	dec r24
	brne 1b
	ldi r18,lo8(10)
	ldi r19,0
	movw r22,r14
	movw r20,r12
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print5printEmi
	ldi r22,lo8(.LC2)
	ldi r23,hi8(.LC2)
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print7printlnEPKc
	movw r24,r14
	movw r22,r12
	ldi r18,lo8(64)
	ldi r19,lo8(31)
	ldi r20,0
	ldi r21,0
	call __udivmodsi4
	movw r22,r20
	movw r20,r18
	ldi r18,lo8(10)
	ldi r19,0
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print5printEmi
	ldi r22,lo8(.LC3)
	ldi r23,hi8(.LC3)
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print7printlnEPKc
	ldi r22,lo8(_ZZ4loopE3__c_0)
	ldi r23,hi8(_ZZ4loopE3__c_0)
	ldi r24,lo8(Serial)
	ldi r25,hi8(Serial)
	call _ZN5Print7printlnEPK19__FlashStringHelper
.L24:
	rjmp .L24
	.size	loop, .-loop
	.section	.progmem.data._ZZ4loopE3__c_0,"a",@progbits
	.type	_ZZ4loopE3__c_0, @object
	.size	_ZZ4loopE3__c_0, 5
_ZZ4loopE3__c_0:
	.string	"DONE"
	.section	.progmem.data._ZZ4loopE3__c,"a",@progbits
	.type	_ZZ4loopE3__c, @object
	.size	_ZZ4loopE3__c, 6
_ZZ4loopE3__c:
	.string	"START"
	.section	.progmem.data._ZZ11checkMatrixPA20_ihhE3__c_2,"a",@progbits
	.type	_ZZ11checkMatrixPA20_ihhE3__c_2, @object
	.size	_ZZ11checkMatrixPA20_ihhE3__c_2, 2
_ZZ11checkMatrixPA20_ihhE3__c_2:
	.string	")"
	.section	.progmem.data._ZZ11checkMatrixPA20_ihhE3__c_1,"a",@progbits
	.type	_ZZ11checkMatrixPA20_ihhE3__c_1, @object
	.size	_ZZ11checkMatrixPA20_ihhE3__c_1, 2
_ZZ11checkMatrixPA20_ihhE3__c_1:
	.string	","
	.section	.progmem.data._ZZ11checkMatrixPA20_ihhE3__c_0,"a",@progbits
	.type	_ZZ11checkMatrixPA20_ihhE3__c_0, @object
	.size	_ZZ11checkMatrixPA20_ihhE3__c_0, 3
_ZZ11checkMatrixPA20_ihhE3__c_0:
	.string	" ("
	.section	.progmem.data._ZZ11checkMatrixPA20_ihhE3__c,"a",@progbits
	.type	_ZZ11checkMatrixPA20_ihhE3__c, @object
	.size	_ZZ11checkMatrixPA20_ihhE3__c, 5
_ZZ11checkMatrixPA20_ihhE3__c:
	.string	" != "
	.section	.progmem.data._ZZ11printMatrixPA20_ihhE3__c,"a",@progbits
	.type	_ZZ11printMatrixPA20_ihhE3__c, @object
	.size	_ZZ11printMatrixPA20_ihhE3__c, 3
_ZZ11printMatrixPA20_ihhE3__c:
	.string	", "
	.section	.progmem.data._ZL1C,"a",@progbits
	.type	_ZL1C, @object
	.size	_ZL1C, 800
_ZL1C:
	.word	-126
	.word	188
	.word	479
	.word	123
	.word	-883
	.word	131
	.word	278
	.word	94
	.word	85
	.word	494
	.word	-23
	.word	-304
	.word	55
	.word	-365
	.word	102
	.word	236
	.word	-196
	.word	-166
	.word	366
	.word	154
	.word	-41
	.word	17
	.word	180
	.word	-80
	.word	-69
	.word	-178
	.word	-420
	.word	-273
	.word	-365
	.word	522
	.word	34
	.word	-447
	.word	-56
	.word	218
	.word	-25
	.word	157
	.word	-243
	.word	158
	.word	-138
	.word	-420
	.word	-481
	.word	479
	.word	-109
	.word	152
	.word	-157
	.word	155
	.word	399
	.word	128
	.word	611
	.word	303
	.word	-240
	.word	83
	.word	34
	.word	56
	.word	323
	.word	-129
	.word	-188
	.word	101
	.word	85
	.word	32
	.word	-355
	.word	577
	.word	-133
	.word	231
	.word	45
	.word	510
	.word	647
	.word	-786
	.word	-420
	.word	-223
	.word	-442
	.word	-786
	.word	66
	.word	5
	.word	-346
	.word	233
	.word	-125
	.word	337
	.word	-232
	.word	18
	.word	-491
	.word	-167
	.word	386
	.word	36
	.word	11
	.word	344
	.word	-50
	.word	-378
	.word	168
	.word	-146
	.word	-364
	.word	-359
	.word	34
	.word	44
	.word	-29
	.word	-217
	.word	52
	.word	406
	.word	439
	.word	-377
	.word	-267
	.word	-225
	.word	-132
	.word	-302
	.word	131
	.word	-1
	.word	-224
	.word	19
	.word	46
	.word	25
	.word	-426
	.word	455
	.word	277
	.word	-157
	.word	308
	.word	-145
	.word	498
	.word	-447
	.word	-133
	.word	55
	.word	290
	.word	-287
	.word	125
	.word	341
	.word	-15
	.word	-467
	.word	-227
	.word	75
	.word	-136
	.word	309
	.word	96
	.word	-28
	.word	201
	.word	-92
	.word	-325
	.word	56
	.word	-591
	.word	-146
	.word	-102
	.word	126
	.word	-235
	.word	383
	.word	316
	.word	-130
	.word	509
	.word	399
	.word	-364
	.word	-637
	.word	31
	.word	-59
	.word	137
	.word	-4
	.word	-540
	.word	-192
	.word	-318
	.word	-556
	.word	657
	.word	-319
	.word	444
	.word	-194
	.word	19
	.word	-494
	.word	305
	.word	-17
	.word	-32
	.word	-83
	.word	-244
	.word	67
	.word	297
	.word	76
	.word	-235
	.word	428
	.word	536
	.word	57
	.word	217
	.word	-27
	.word	-317
	.word	-91
	.word	126
	.word	61
	.word	214
	.word	125
	.word	54
	.word	251
	.word	-185
	.word	236
	.word	360
	.word	-332
	.word	-639
	.word	-42
	.word	-30
	.word	-549
	.word	805
	.word	98
	.word	-380
	.word	205
	.word	-225
	.word	200
	.word	-133
	.word	-74
	.word	-60
	.word	-613
	.word	-154
	.word	-542
	.word	841
	.word	-201
	.word	-718
	.word	-306
	.word	-245
	.word	333
	.word	202
	.word	279
	.word	-436
	.word	290
	.word	393
	.word	-911
	.word	120
	.word	176
	.word	136
	.word	-426
	.word	-290
	.word	206
	.word	-322
	.word	14
	.word	342
	.word	305
	.word	343
	.word	573
	.word	526
	.word	276
	.word	-337
	.word	678
	.word	21
	.word	428
	.word	985
	.word	-70
	.word	83
	.word	105
	.word	153
	.word	166
	.word	-9
	.word	-194
	.word	146
	.word	-196
	.word	763
	.word	-373
	.word	-624
	.word	-247
	.word	324
	.word	-124
	.word	-204
	.word	530
	.word	-118
	.word	-148
	.word	-69
	.word	-722
	.word	129
	.word	-129
	.word	252
	.word	-396
	.word	121
	.word	-325
	.word	1
	.word	-247
	.word	597
	.word	-31
	.word	-295
	.word	90
	.word	-35
	.word	-303
	.word	-113
	.word	429
	.word	-243
	.word	-5
	.word	-124
	.word	-25
	.word	-102
	.word	-159
	.word	54
	.word	-36
	.word	-455
	.word	169
	.word	-182
	.word	-427
	.word	180
	.word	144
	.word	-129
	.word	-302
	.word	358
	.word	-366
	.word	-76
	.word	369
	.word	-464
	.word	-238
	.word	157
	.word	-237
	.word	520
	.word	-471
	.word	66
	.word	-434
	.word	-324
	.word	159
	.word	3
	.word	-239
	.word	-132
	.word	-329
	.word	-190
	.word	330
	.word	517
	.word	-225
	.word	-474
	.word	359
	.word	-12
	.word	-720
	.word	-189
	.word	120
	.word	252
	.word	-51
	.word	108
	.word	314
	.word	-560
	.word	34
	.word	291
	.word	-242
	.word	71
	.word	353
	.word	106
	.word	-602
	.word	-253
	.word	393
	.word	-333
	.word	-458
	.word	-54
	.word	109
	.word	389
	.word	-464
	.word	201
	.word	-36
	.word	339
	.word	-231
	.word	519
	.word	-199
	.word	391
	.word	580
	.word	40
	.word	-417
	.word	-84
	.word	375
	.word	-208
	.word	98
	.word	247
	.word	300
	.word	1123
	.word	-6
	.word	-411
	.word	639
	.word	426
	.word	-518
	.word	194
	.word	32
	.word	237
	.word	-180
	.word	192
	.word	-231
	.word	-188
	.word	171
	.word	-470
	.word	-12
	.word	156
	.word	-188
	.word	-27
	.word	-78
	.word	554
	.word	-205
	.word	-31
	.word	-72
	.word	137
	.word	291
	.word	-49
	.word	-185
	.word	199
	.word	-176
	.word	66
	.word	74
	.word	-34
	.word	-395
	.word	-167
	.word	467
	.word	-300
	.word	-321
	.word	380
	.word	204
	.word	197
	.word	175
	.word	-553
	.word	743
	.word	-422
	.word	428
	.word	-326
	.word	-811
	.section	.progmem.data._ZL1A,"a",@progbits
	.type	_ZL1A, @object
	.size	_ZL1A, 400
_ZL1A:
	.byte	-6
	.byte	0
	.byte	-9
	.byte	15
	.byte	8
	.byte	0
	.byte	4
	.byte	-4
	.byte	4
	.byte	3
	.byte	9
	.byte	-3
	.byte	-12
	.byte	13
	.byte	-7
	.byte	-12
	.byte	-8
	.byte	6
	.byte	1
	.byte	-12
	.byte	-12
	.byte	7
	.byte	14
	.byte	1
	.byte	4
	.byte	7
	.byte	4
	.byte	-6
	.byte	-5
	.byte	-13
	.byte	-3
	.byte	-13
	.byte	-9
	.byte	-3
	.byte	-13
	.byte	8
	.byte	3
	.byte	10
	.byte	2
	.byte	-12
	.byte	10
	.byte	-8
	.byte	-8
	.byte	-4
	.byte	12
	.byte	7
	.byte	-15
	.byte	-9
	.byte	-2
	.byte	1
	.byte	0
	.byte	-9
	.byte	-10
	.byte	7
	.byte	4
	.byte	-15
	.byte	1
	.byte	2
	.byte	-2
	.byte	-1
	.byte	-5
	.byte	15
	.byte	-2
	.byte	8
	.byte	-2
	.byte	14
	.byte	15
	.byte	-8
	.byte	-5
	.byte	9
	.byte	-10
	.byte	-14
	.byte	-6
	.byte	-13
	.byte	6
	.byte	3
	.byte	6
	.byte	-12
	.byte	6
	.byte	15
	.byte	-6
	.byte	15
	.byte	1
	.byte	-9
	.byte	-5
	.byte	-2
	.byte	1
	.byte	-6
	.byte	8
	.byte	9
	.byte	6
	.byte	2
	.byte	-10
	.byte	-4
	.byte	6
	.byte	-9
	.byte	14
	.byte	-2
	.byte	8
	.byte	-7
	.byte	-7
	.byte	-4
	.byte	-6
	.byte	-6
	.byte	13
	.byte	15
	.byte	-3
	.byte	-7
	.byte	-11
	.byte	5
	.byte	-9
	.byte	8
	.byte	11
	.byte	8
	.byte	5
	.byte	2
	.byte	-2
	.byte	-3
	.byte	-4
	.byte	-14
	.byte	15
	.byte	-12
	.byte	2
	.byte	7
	.byte	-15
	.byte	-6
	.byte	-5
	.byte	-7
	.byte	-10
	.byte	-6
	.byte	11
	.byte	-9
	.byte	4
	.byte	4
	.byte	-15
	.byte	2
	.byte	-7
	.byte	2
	.byte	-2
	.byte	-13
	.byte	13
	.byte	9
	.byte	14
	.byte	14
	.byte	12
	.byte	-2
	.byte	9
	.byte	12
	.byte	-2
	.byte	5
	.byte	9
	.byte	13
	.byte	3
	.byte	13
	.byte	0
	.byte	11
	.byte	14
	.byte	-14
	.byte	15
	.byte	3
	.byte	-5
	.byte	-13
	.byte	-4
	.byte	-11
	.byte	-10
	.byte	4
	.byte	-1
	.byte	-7
	.byte	0
	.byte	4
	.byte	13
	.byte	-1
	.byte	-9
	.byte	7
	.byte	6
	.byte	-10
	.byte	-1
	.byte	-4
	.byte	7
	.byte	-14
	.byte	-2
	.byte	-2
	.byte	-5
	.byte	7
	.byte	-15
	.byte	9
	.byte	8
	.byte	-4
	.byte	-4
	.byte	7
	.byte	-6
	.byte	-15
	.byte	11
	.byte	-4
	.byte	-4
	.byte	-5
	.byte	10
	.byte	3
	.byte	8
	.byte	12
	.byte	7
	.byte	-3
	.byte	15
	.byte	-9
	.byte	4
	.byte	-4
	.byte	-14
	.byte	-4
	.byte	2
	.byte	-7
	.byte	1
	.byte	12
	.byte	15
	.byte	-15
	.byte	-11
	.byte	8
	.byte	0
	.byte	0
	.byte	8
	.byte	-12
	.byte	-6
	.byte	-14
	.byte	-11
	.byte	-12
	.byte	7
	.byte	11
	.byte	-13
	.byte	8
	.byte	2
	.byte	-5
	.byte	-8
	.byte	10
	.byte	-14
	.byte	-7
	.byte	12
	.byte	-14
	.byte	4
	.byte	5
	.byte	0
	.byte	3
	.byte	13
	.byte	-11
	.byte	6
	.byte	-10
	.byte	8
	.byte	-6
	.byte	-7
	.byte	-6
	.byte	-13
	.byte	-12
	.byte	8
	.byte	7
	.byte	15
	.byte	-4
	.byte	-7
	.byte	-4
	.byte	13
	.byte	-10
	.byte	0
	.byte	-10
	.byte	0
	.byte	1
	.byte	7
	.byte	-6
	.byte	-15
	.byte	-1
	.byte	-9
	.byte	10
	.byte	9
	.byte	-7
	.byte	6
	.byte	6
	.byte	3
	.byte	-7
	.byte	-8
	.byte	5
	.byte	1
	.byte	-11
	.byte	-7
	.byte	4
	.byte	-1
	.byte	2
	.byte	-6
	.byte	6
	.byte	15
	.byte	3
	.byte	6
	.byte	-1
	.byte	13
	.byte	-14
	.byte	-5
	.byte	10
	.byte	5
	.byte	4
	.byte	11
	.byte	5
	.byte	14
	.byte	-8
	.byte	-4
	.byte	4
	.byte	-5
	.byte	-2
	.byte	-11
	.byte	-9
	.byte	3
	.byte	-12
	.byte	-14
	.byte	-3
	.byte	-5
	.byte	3
	.byte	8
	.byte	7
	.byte	-2
	.byte	-2
	.byte	-6
	.byte	6
	.byte	8
	.byte	-6
	.byte	-13
	.byte	0
	.byte	-13
	.byte	7
	.byte	2
	.byte	4
	.byte	4
	.byte	6
	.byte	-6
	.byte	-10
	.byte	7
	.byte	-1
	.byte	-13
	.byte	-5
	.byte	6
	.byte	-4
	.byte	-6
	.byte	-7
	.byte	13
	.byte	-2
	.byte	12
	.byte	-12
	.byte	8
	.byte	-6
	.byte	-6
	.byte	4
	.byte	-14
	.byte	-2
	.byte	-6
	.byte	13
	.byte	-9
	.byte	11
	.byte	15
	.byte	-9
	.byte	14
	.byte	9
	.byte	4
	.byte	7
	.byte	-1
	.byte	15
	.byte	-4
	.byte	-12
	.byte	-3
	.byte	3
	.byte	13
	.byte	-7
	.byte	9
	.byte	4
	.byte	0
	.byte	-10
	.byte	-10
	.byte	12
	.byte	15
	.byte	0
	.byte	1
	.byte	14
	.byte	10
	.byte	-11
	.byte	-4
	.byte	11
	.byte	3
	.byte	-3
	.byte	6
	.byte	14
	.byte	-11
	.byte	-11
	.byte	-5
	.byte	7
	.byte	4
	.byte	5
	.byte	-1
	.byte	-14
	.byte	6
	.byte	-2
	.byte	0
	.byte	-7
	.byte	-7
	.byte	5
	.byte	-7
	.byte	15
	.byte	-14
	.byte	5
	.ident	"GCC: (Gentoo 4.9.3 p1.2, pie-0.6.3) 4.9.3"
.global __do_copy_data
