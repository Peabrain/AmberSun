	xdef	_ChunkyToPlanar
	xdef	_PlanarScreenPtr
	xdef	_CnkBufferPtr

_ChunkyToPlanar:
	movem.l	d2-d7/a2-a6,-(sp)
	move.l	_PlanarScreenPtr,a1
	move.l	_CnkBufferPtr,a0

	move.w	#160-1,d0
.CnkLoop2:
	swap	d0

	move.w	#192/32-1,d0
.CnkLoop1:
	move.l	(a0),d4		; d0 = a70,b70,c70,d70
	move.l	16(a0),d5	; d1 = A70,B70,C70,D70
	move.l	d4,d2
	move.l	d5,d3
	and.l	#$ffff0000,d4
	eor.l	d4,d2
	and.l	#$0000ffff,d5
	eor.l	d5,d3
	swap	d3
	or.l	d3,d4		; d4 = a70,b70,A70,B70
	swap	d2
	or.l	d2,d5		; d5 = c70,d70,C70,D70
;	addq.l	#4,a0

	move.l	4(a0),d6	; d0 = e70,f70,g70,h70
	move.l	20(a0),d7	; d1 = E70,F70,G70,H70
	move.l	d6,d2
	move.l	d7,d3
	and.l	#$ffff0000,d6
	eor.l	d6,d2
	and.l	#$0000ffff,d7
	eor.l	d7,d3
	swap	d3
	or.l	d3,d6
	move.l	d6,a4		; a4 = e70,f70,E70,F70
	swap	d2
	or.l	d2,d7
	move.l	d7,a5		; a5 = g70,h70,G70,H70
;	addq.l	#4,a0

	move.l	12(a0),d6	; d0 = m70,n70,o70,p70
	move.l	28(a0),d7	; d1 = M70,N70,O70,P70
	move.l	d6,d2
	move.l	d7,d3
	and.l	#$ffff0000,d6
	eor.l	d6,d2
	and.l	#$0000ffff,d7
	eor.l	d7,d3
	swap	d3
	or.l	d3,d6
	move.l	d6,a2		; a2 = m70,n70,M70,N70
	swap	d2
	or.l	d2,d7
	move.l	d7,a3		; a3 = o70,p70,O70,P70

	move.l	8(a0),d6		; d0 = i70,j70,k70,l70
	move.l	24(a0),d7	; d1 = I70,J70,K70,L70
	move.l	d6,d2
	move.l	d7,d3
	and.l	#$ffff0000,d6
	eor.l	d6,d2
	and.l	#$0000ffff,d7
	eor.l	d7,d3
	swap	d3
	or.l	d3,d6		; d6 = i70,j70,I70,J70
	swap	d2
	or.l	d2,d7		; d7 = k70,l70,K70,L70
	add.l	#32,a0

	move.l	d4,d2
	and.l	#$00ff00ff,d2
	eor.l	d2,d4
	move.l	d6,d3
	and.l	#$ff00ff00,d3
	eor.l	d3,d6
	lsr.l	#8,d3
	or.l	d3,d4
	lsl.l	#8,d2
	or.l	d2,d6

	exg	d4,a4		; a4 = a70,i70,A70,I70
	exg	d6,a2		; a2 = b70,j70,B70,J70

	move.l	d5,d2
	and.l	#$00ff00ff,d2
	eor.l	d2,d5
	move.l	d7,d3
	and.l	#$ff00ff00,d3
	eor.l	d3,d7
	lsr.l	#8,d3
	or.l	d3,d5
	lsl.l	#8,d2
	or.l	d2,d7

	exg	d5,a5		; a5 = c70,k70,C70,K70
	exg	d7,a3		; a3 = d70,l70,D70,L70

	move.l	d4,d2
	and.l	#$00ff00ff,d2
	eor.l	d2,d4
	move.l	d6,d3
	and.l	#$ff00ff00,d3
	eor.l	d3,d6
	lsr.l	#8,d3
	or.l	d3,d4		; d4 = e70,m70,E70,M70
	lsl.l	#8,d2
	or.l	d2,d6		; d6 = g70,o70,G70,O70

	move.l	d5,d2
	and.l	#$00ff00ff,d2
	eor.l	d2,d5
	move.l	d7,d3
	and.l	#$ff00ff00,d3
	eor.l	d3,d7
	lsr.l	#8,d3
	or.l	d3,d5		; d5 = f70,n70,F70,N70
	lsl.l	#8,d2
	or.l	d2,d7		; d7 = h70,p70,H70,P70

	exg		a4,d5
	exg		a2,d7

	move.l	d5,d2
	and.l	#$0f0f0f0f,d2
	eor.l	d2,d5
	move.l	d4,d3
	and.l	#$f0f0f0f0,d3
	eor.l	d3,d4
	lsr.l	#4,d3
	or.l	d3,d5		; d5 = f70,n70,F70,N70
	lsl.l	#4,d2
	or.l	d2,d4		; d7 = h70,p70,H70,P70

	move.l	d7,d2
	and.l	#$0f0f0f0f,d2
	eor.l	d2,d7
	move.l	d6,d3
	and.l	#$f0f0f0f0,d3
	eor.l	d3,d6
	lsr.l	#4,d3
	or.l	d3,d7		; d5 = f70,n70,F70,N70
	lsl.l	#4,d2
	or.l	d2,d6		; d7 = h70,p70,H70,P70

	exg	d5,a5
	exg	d4,a4
	exg	d7,a3
	exg	d6,a2

	move.l	d5,d2
	and.l	#$0f0f0f0f,d2
	eor.l	d2,d5
	move.l	d4,d3
	and.l	#$f0f0f0f0,d3
	eor.l	d3,d4
	lsr.l	#4,d3
	or.l	d3,d5		; d5 = f70,n70,F70,N70
	lsl.l	#4,d2
	or.l	d2,d4		; d7 = h70,p70,H70,P70

	move.l	d7,d2
	and.l	#$0f0f0f0f,d2
	eor.l	d2,d7
	move.l	d6,d3
	and.l	#$f0f0f0f0,d3
	eor.l	d3,d6
	lsr.l	#4,d3
	or.l	d3,d7		; d5 = f70,n70,F70,N70
	lsl.l	#4,d2
	or.l	d2,d6		; d7 = h70,p70,H70,P70

	exg	a5,d7
	exg	a4,d6

	move.l	d7,d2
	and.l	#$33333333,d2
	eor.l	d2,d7
	move.l	d5,d3
	and.l	#$cccccccc,d3
	eor.l	d3,d5
	lsr.l	#2,d3
	or.l	d3,d7		; d7 = acegikmoACEGIKMO/67
	lsl.l	#2,d2
	or.l	d2,d5		; d5 = acegikmoACEGIKMO/45

	move.l	d6,d2
	and.l	#$33333333,d2
	eor.l	d2,d6
	move.l	d4,d3
	and.l	#$cccccccc,d3
	eor.l	d3,d4
	lsr.l	#2,d3
	or.l	d3,d6		; d6 = acegikmoACEGIKMO/23
	lsl.l	#2,d2
	or.l	d2,d4		; d4 = acegikmoACEGIKMO/01


	exg	d7,a3		; a3 = acegikmoACEGIKMO/67
	exg	d5,a5		; a5 = acegikmoACEGIKMO/45
	exg	d6,a2		; a2 = acegikmoACEGIKMO/23
	exg	d4,a4		; a4 = acegikmoACEGIKMO/01

	move.l	d7,d2
	and.l	#$33333333,d2
	eor.l	d2,d7
	move.l	d5,d3
	and.l	#$cccccccc,d3
	eor.l	d3,d5
	lsr.l	#2,d3
	or.l	d3,d7		; d7 = bdfhjlnpBDFHJKNP/67
	lsl.l	#2,d2
	or.l	d2,d5		; d5 = bdfhjlnpBDFHJKNP/45

	move.l	d6,d2
	and.l	#$33333333,d2
	eor.l	d2,d6
	move.l	d4,d3
	and.l	#$cccccccc,d3
	eor.l	d3,d4
	lsr.l	#2,d3
	or.l	d3,d6		; d6 = bdfhjlnpBDFHJKNP/23
	lsl.l	#2,d2
	or.l	d2,d4		; d4 = bdfhjlnpBDFHJKNP/01

	exg	a2,d5		; d5 = acegikmoACEGIKMO/23
	exg	a4,d7		; d7 = acegikmoACEGIKMO/01

	move.l	d7,d2
	and.l	#$55555555,d2
	eor.l	d2,d7
	move.l	d4,d3
	and.l	#$aaaaaaaa,d3
	eor.l	d3,d4
	lsr.l	#1,d3
	or.l	d3,d7		; Plane 1
	lsl.l	#1,d2
	or.l	d2,d4		; Plane 0

	move.l	d4,(a1)
	move.l	d7,40(a1)

	move.l	d5,d2
	and.l	#$55555555,d2
	eor.l	d2,d5
	move.l	d6,d3
	and.l	#$aaaaaaaa,d3
	eor.l	d3,d6
	lsr.l	#1,d3
	or.l	d3,d5		; Plane 3
	lsl.l	#1,d2
	or.l	d2,d6		; Plane 2

	move.l	d6,40*2(a1)
	move.l	d5,40*3(a1)

	exg	a2,d5		; d5 = acegikmoACEGIKMO/23
	exg	a4,d7		; d7 = acegikmoACEGIKMO/01
	exg	a3,d4		; d5 = acegikmoACEGIKMO/23
	exg	a5,d6		; d7 = acegikmoACEGIKMO/01

	move.l	d6,d2
	and.l	#$55555555,d2
	eor.l	d2,d6
	move.l	d5,d3
	and.l	#$aaaaaaaa,d3
	eor.l	d3,d5
	lsr.l	#1,d3
	or.l	d3,d6		; Plane 5
	lsl.l	#1,d2
	or.l	d2,d5		; Plane 4

	move.l	d5,40*4(a1)
	move.l	d6,40*5(a1)

	move.l	d4,d2
	and.l	#$55555555,d2
	eor.l	d2,d4
	move.l	d7,d3
	and.l	#$aaaaaaaa,d3
	eor.l	d3,d7
	lsr.l	#1,d3
	or.l	d3,d4		; Plane 7
	lsl.l	#1,d2
	or.l	d2,d7		; Plane 6

	move.l	d7,40*6(a1)
	move.l	d4,40*7(a1)
	addq.l	#4,a1

	dbf	d0,.CnkLoop1
	add.l	#296,a1
	swap	d0
	dbf	d0,.CnkLoop2
.exit:
	movem.l	(sp)+,d2-d7/a2-a6
	rts
	EVEN
_CnkBufferPtr:
	dc.l	0
_PlanarScreenPtr:
	dc.l	0
