.data
p: .word 0 # 0x1001 0000
q: .word 0 # 0x1001 0004
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
	
	lw $12, 0($8) # p
	lw $13, 4($8) # q
	or $10, $0, $12 # i
	ori $11, $0, 0 # somme
for:
	# i+1 > q
	addiu $14, $10, 1
	slt $15, $13, $14
	bne $15, $0, end_for
	addu $11, $11, $10 # somme += i
	addiu $10, $10, 1
	j for
end_for:
	ori $2, $0, 1
	or $4, $0, $11
	syscall
	
	ori $2, $0, 10
	syscall