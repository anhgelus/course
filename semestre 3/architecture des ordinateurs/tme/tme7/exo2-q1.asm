.data
.text
# main
	addiu $29, $29, -36
	sw $0, 32($29) # i = 0
	# ch1 = 0($29)
	# ch2 = 16($29)
	
	or $16, $0, $29
	addiu $17, $29, 16
	
	ori $2, $0, 8
	or $4, $0, $16
	ori $5, $0, 16
	syscall
	
	ori $2, $0, 8
	or $4, $0, $17
	ori $5, $0, 16
	syscall
	
	# printf("%s", ch1)
	or $4, $0, $16
	ori $2, $0, 4
	syscall
	# min_to_maj_chaine(ch1)
	addiu $29, $29, -4
	or $4, $0, $16
	sw $4, 0($29)
	jal min_to_maj_chaine
	# printf("%s", ch1)
	or $4, $0, $16
	ori $2, $0, 4
	syscall
	
	# printf("%s", ch2)
	or $4, $0, $17
	ori $2, $0, 4
	syscall
	# min_to_maj_chaine(ch2)
	or $4, $0, $17
	sw $4, 0($29)
	jal min_to_maj_chaine
	# printf("%s", ch2)
	or $4, $0, $17
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
