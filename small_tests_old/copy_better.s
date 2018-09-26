.name "st test"
.comment "NB set player number as something big"
start:
	live %42
	st r1,-4			
	st r1,r2			#copy player number to r2
	sti r3,:start,%1	#copy  to live correctly
