.name "forking live"
	
	zjmp %:end
	and  %0,%0,r2
start:
	fork %:end
	live %42
	zjmp %:start
end:
