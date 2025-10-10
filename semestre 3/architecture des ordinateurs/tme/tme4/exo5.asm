.data
tab:	.word 4, 23, 12, 3, 8, 1
	.align 2
s:	.space 4
	.align 2
p:	.space 4
.text
	lui $8, 0x1001 	# @tab
	addiu $9, $8, 24 	# @s
	addiu $10, $9, 4	# @p
	# s = tab[3] 
	lw $11, 12($8)
	sw $11, 0($9)
	# p = tab[4]
	lw $12, 16($8)
	sw $12, 0($10)
	
	# tab[0] = s + 1
	addi $13, $11, 1
	sw $13, 0($8)
	# tab[1] = s + p
	add $13, $11, $12
	sw $13, 4($8)
	# tab[2] = tab[5]
	lw $13, 20($8)
	sw $13, 8($8)
	
	# exit()
	ori $2, $0, 10
	syscall