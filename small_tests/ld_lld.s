.name "load"

live %1
ld -4,r2
ld %10,r3
ld %100,r4
ld %2147483647,r5
lld 516,r6
ld 516,r7
lld %700,r8
ld %700,r9

sti r2,%0,%164
sti r3,%0,%170
sti r4,%0,%176
sti r5,%0,%182
sti r6,%0,%188
sti r7,%0,%194
sti r8,%0,%200
sti r9,%0,%206
# r1: 1 (or 1)
# r2: 1 (or 1)
# r3: a (or 10)
# r4: 64 (or 100)
# r5: 7fffffff (or 2147483647)
# r6: 0 (or 0)
# r7: 0 (or 0)
# r8: 2bc (or 700)
# r9: 0 (or 0)
