.name "live loop"
live:
	live %42
	ld 10,r2
	zjmp %:live
	ld 10,r2
	zjmp %:live
