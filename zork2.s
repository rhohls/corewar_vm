.name "zork2"
.comment "I'M ALIIIIVE"

l2: 
	live %1
	fork %:live
	and r1, %0, r3
	zjmp %:l2

live:
	and r1, %0, r3	
	zjmp %:live
