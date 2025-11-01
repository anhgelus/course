.data
ch: .asciiz "Bonjour, je suis une licorne avec des pouvoirs magiques :D" # len(ch) 58
.text
	lui $8, 0x1001
	ori $9, $0, 0 # n
while:
	lb  $10, 0($8)
	beq $10, $0, end_while
	addiu $9, $9, 1
	addiu $8, $8, 1
	j while
end_while:
	ori $2, $0, 1
	or $4, $0, $9
	syscall
	ori $2, $0, 10
	syscall