.data
val: .word 70
tab: .word 42, 69, 420, 666, 1, 2, 0, -1
.text
	lui $8, 0x1001
	ori $9, $0, 0 # n
	lw $12, 0($8)
	addiu $8, $8, 4
	# cond d'arrêt
	or $13, $0, $0
	ori $14, $0, 1
	subu $13, $13, $14
while:
	# while tab[i] != '\0'
	lw  $10, 0($8)
	beq $10, $13, end_while
	slt $11, $10, $12
	# if tab[i] < val
	beq $11, $0, end_if
	addiu $9, $9, 1
end_if:
	addiu $8, $8, 4
	j while
end_while:
	ori $2, $0, 1
	or $4, $0, $9
	syscall
	ori $2, $0, 10
	syscall