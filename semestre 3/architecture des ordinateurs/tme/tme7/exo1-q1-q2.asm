.data
ch1:	.asciiz "1 exemple d'exemple\n" # @ 0x1001 0000
ch2:	.asciiz "Hello world!\n" # @ 0x1001 0015
.text
#main
	addiu $29, $29, -4
	sw $0, 0($29)
	
	# printf("%s", ch1)
	lui $4, 0x1001
	ori $2, $0, 4
	syscall
	# min_to_maj_chaine(ch1)
	addiu $29, $29, -4
	lui $4, 0x1001
	sw $4, 0($29)
	jal min_to_maj_chaine
	# printf("%s", ch1)
	lui $4, 0x1001
	ori $2, $0, 4
	syscall
	
	# printf("%s", ch2)
	lui $16, 0x1001
	addiu $16, $16, 0x15
	or $4, $0, $16
	ori $2, $0, 4
	syscall
	# min_to_maj_chaine(ch2)
	or $4, $0, $16
	sw $4, 0($29)
	jal min_to_maj_chaine
	# printf("%s", ch2)
	or $4, $0, $16
	ori $2, $0, 4
	syscall
	
	addiu $29, $29, 8
	ori $2, $0, 10
	syscall

min_to_maj_chaine:
	addiu $29, $29, -8
	sw $31, 4($29)
while:
	# while ch[i] != 0
	lb $9, 0($4)
	beq $9, $0, end_while
	# if ch[i] >= 'a'
	sltiu $10, $9, 'a'
	bne $10, $0, end_if
	# if ch[i] <= 'z'
	ori $10, $0, 'z'
	sltu $10, $10, $9
	bne $10, $0, end_if
	# ch[i] - 0x20
	addiu $9, $9, -0x20
	sb $9, 0($4)
end_if:
	addiu $4, $4, 1
	j while
end_while:
	lw $31, 4($29)
	addiu $29, $29, 8
	jr $31