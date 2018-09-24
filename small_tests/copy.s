.name "st test"
.comment "NB set player number as something big"
start:
	live %42
	st r1,-4
	st r1,r2		#copy player number to r2
	st r3,:start	#copy 0 over the first instruction
