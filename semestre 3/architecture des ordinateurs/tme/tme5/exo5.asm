.data
n: .word 123
.text
	lui $8, 0x1001
	lw $9, 0($8)
	
	ori $11, $0, 1
	ori $10, $0, 31
	ori $13, $0, 0
while:
	bltz $10, end_while
	srlv $12, $9, $10
	andi $12, $12, 1
	beq $12, $0, end_if
	addiu $13, $13, 1
end_if:
	subu $10, $10, $11
	j while
end_while:
	ori $2, $0, 1
	or $4, $0, $13
	syscall
	ori $2, $0, 10
	syscall