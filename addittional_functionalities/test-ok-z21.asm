
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
		MOV	$41, -12(%14)
		MOV	$41, -8(%14)
		MOV	$41, -4(%14)
@main_body:
		ADDU	-8(%14), $1, -8(%14)
		MOV 	-8(%14),-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET