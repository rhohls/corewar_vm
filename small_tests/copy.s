.name "st test"
.comment "NB set player number as something big"
start:
	live %42
	st r1,-4		#cp player num to pc + player num
	st r1,r2		#copy player num into where pc is
	st r3,:start	#copy 0 to pc
