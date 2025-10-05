.data
.text
	# dans la question 2, on remplace 137 par 65537 -> ça crash, car 65537 ne peut pas être écrit sur 16 bits
	ori $8, $0, 137

	or $4, $0, $8
	ori $2, $0, 1
	syscall

	ori $2, $0, 10
	syscall
