.name "basic"
.comment "I'M ALIIIIVE"

l2: 
	ldi %:live,%1, r2
	add r2,r2,r2
	sti r2,%:live,%1
	and r1,%0,r3
	
live:	live %1
		zjmp %:live