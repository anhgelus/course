.data
ch:	.asciiz "1 exemple d'exemple\n" # @ 0x1001 0000
.text
# main
	addiu $29, $29, -8
	# int i = 0
	sw $0, 4($29)
	# printf("%s", ch)
	lui $16, 0x1001
	or $4, $0, $16
	ori $2, $0, 4
	syscall
while:
	# while ch[i] != 0
	lb $9, 0($16)
	beq $9, $0, end_while
	# ch[i] = min_to_maj_char(&(ch[i]))
	sw $9, 0($29)
	or $4, $0, $16
	jal min_to_maj_ptr_char
	# i++
	addiu $16, $16, 1
	j while
end_while:
	# printf("%s", ch)
	lui $4, 0x1001
	ori $2, $0, 4
	syscall

	addiu $29, $29, 8
	ori $2, $0, 10
	syscall
	
min_to_maj_ptr_char:
	addiu $29, $29, -8
	sw $31, 4($29)
	# if ch[i] >= 'a'
	lb $8, 0($4)
	sltiu $10, $8, 'a'
	bne $10, $0, end_if
	# if ch[i] <= 'z'
	ori $10, $0, 'z'
	sltu $10, $10, $8
	bne $10, $0, end_if
	# c - 0x20
	addiu $8, $8, -0x20
	sb $8, 0($4)
end_if:
	lw $31, 4($29)
	addiu $29, $29, 8
	jr $31
