.data
a: .word 0 # 0x1001 0000
b: .word 0 # 0x1001 0004
.text
	lui $8, 0x1001 # $8 <- 0x1001 0000
	ori $2, $0, 5
	syscall
	lui $8, 0x1001 # $8 <- 0x1001 0000
	sw $2, 0($8)
	ori $2, $0, 5
	syscall
	lui $8, 0x1001 # $8 <- 0x1001 0000
	sw $2, 4($8)
	
	lw $9, 0($8) # tmpa
	lw $10, 4($8) # tmpb
while:
	beq $9, $10, end_while
	# tmpb < tmpa -> else
	slt $11, $10, $9
	beq $11, $0, else
	subu $9, $9, $10
	j end_if
else:
	subu $10, $10, $9
end_if:
	j while
end_while:
	ori $2, $0, 1
	or $4, $0, $9
	syscall
	ori $2, $0, 10
	syscall