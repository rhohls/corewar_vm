.name "the other copy"

start:
live %100
sti	r1,r1,r2		# RRR
sti	r2,%10,r3		# RDR
sti	r3,:start,r4	# RIR
sti	r1,r5,%100		# RRD
sti	r1,%41,%115		# RDD
sti	r5,:start,%130	# RID
