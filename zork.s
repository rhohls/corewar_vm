.name "zork"
.comment "I'M ALIIIIVE"

l2: 
	live %1			#5 -0
	fork %:live		#3 -8
	and r1, %0, r3	#8 -16
	zjmp %:l2		#3 -19

live:	#19
	and r1, %0, r3	
	zjmp %:live
