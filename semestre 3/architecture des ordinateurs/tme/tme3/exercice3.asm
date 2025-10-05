.data
.text
	# on récupère les deux entiers
	ori $2, $0, 5
	syscall
	or $9, $0, $2

	ori $2, $0, 5
	syscall
	or $10, $0, $2

	# on gère la division
	div $9, $10
	mflo $11
	mfhi $12

	or $4, $0, $11
	ori $2, $0, 1
	syscall

	or $4, $0, $12
	syscall

	# on mult le quotient par $10 pour reconstruire le nombre
	multu $11, $10
	# on récupère la valeur et on y ajoute le reste
	mflo $13
	addu $13, $13, $12

	or $4, $0, $13
	syscall

	ori $2, $0, 10
	syscall