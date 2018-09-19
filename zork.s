.name "zork"
.comment "I'M ALIIIIVE"

l2:		
		sti r1,%:live,r32
		ld	1,r3

live:	
		live %1
		zjmp %:live

