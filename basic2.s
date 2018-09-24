.name "basic"
.comment "I'M ALIIIIVE"

l2: 
	ldi %:live,  %1, r2
	sti r2, r1, %25
	and r1,%0,r3
	
live:	live %1
		zjmp %:live