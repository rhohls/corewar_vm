.comment "set player num = 42"

live %32
ld %42,r2
add r1,r2,r3
sub r3,r1,r4
sub r1,r3,r5
	
sti r2,%0,%128
sti r3,%0,%128
sti r4,%0,%128
sti r5,%0,%128
sti r6,%0,%128
sti r7,%0,%128
sti r8,%0,%128
sti r9,%0,%128
sti r10,%0,%128
sti r11,%0,%128

# results
# r1: 2a (or 42)
# r2: 2a (or 42)
# r3: 54 (or 84)
# r4: 2a (or 42)
# r5: 2a (or -42)

