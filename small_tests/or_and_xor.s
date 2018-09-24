
.name "or and xor"
	live %1
	or r2,-4,r3		# RIR expect r3 = 1
	or r1,r2,r4		# RRR expect r4 = 1
	or r1,%0,r5		# RDR expect r5 = 1
	or %1,200,r6	# DIR expect r6 = 1 
	and %1,r1,r7	# DIR expect r7 = 1
	xor %1,%0,r8	# DDR expect r8 = 1
	xor 1,1,r9 		# IIR expect r9 = 0
	or 100,%1,r10	# IDR expect r10 = 1
	or 100,r2,r11	# IRR expect r11 = 0
