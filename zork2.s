.name "zork"
.comment "I'M ALIIIIVE"

l2: 
	live %2
	fork %:live
	and r1, %0, r3
	zjmp %:l2

live:
	zjmp %:live
