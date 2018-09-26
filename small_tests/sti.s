.name "the other copy"

start:
live %1
# sti	r1,r1,r2		# RRR
# sti	r1,%10,r3		# RDR
# sti	r3,:start,r4	# RIR
# sti	r1,r5,%64		# RRD
# sti	r1,%64,%64		# RDD
sti	r5,:start,%130	# RID
