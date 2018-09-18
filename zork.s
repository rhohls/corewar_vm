.name "zork"
.comment "I'M ALIIIIVE"

l2:		
		sti r1,%:live,%-1
		ld	1,r3

live:	
		live %1
		zjmp %:live

