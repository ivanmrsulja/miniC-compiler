
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		SUBS	%15,$4,%15
		MOV 	$1,-16(%14)
		MOV 	$2,-8(%14)
		ADDS	-16(%14),-8(%14),%0
		MOV 	%0,-12(%14)
		SUBS	%15,$12,%15
		MOV 	$2,-20(%14)
		MOV 	$1,-24(%14)
		ADDS	-20(%14),$1,%0
		MOV 	%0,-28(%14)
		ADDS	%15,$12,%15
		ADDS	%15,$4,%15
		MOV 	-12(%14),-8(%14)
		MOV 	-8(%14),-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET