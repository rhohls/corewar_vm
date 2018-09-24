start:
live %33
ldi r1,%4,r2		# RDR
ldi r1,r2,r3		# RRR
ldi %70,%30,r4		# DDR
ldi %4,r1,r5		# DRR
ldi :start,%0,r6	# IDR
ldi	:start,r6,r7	# IRR

# r1: 1 (or 1)
# r2: 5 (or 5)
# r3: 6 (or 6)
# r4: 64 (or 100)
# r5: 5 (or 5)
# r6: ff0000 (or 16711680)
# r7: 1fe0000 (or 33423360)
# r8: 0 (or 0)
# r9: 0 (or 0)
