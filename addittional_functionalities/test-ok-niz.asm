
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
		MOV 	$0, -4(%14)
		MOV 	$0, -8(%14)
		SUBS	%15,$8,%15
		MOV 	$0, -12(%14)
		MOV 	$0, -16(%14)
		SUBS	%15,$4,%15
		MOV	$-1, -20(%14)
@main_body:
		MOV 	$10,-4(%14)
		SUBS	%15,$0,%15
		MOV 	$-16, %3
		MOV 	$9, %3(%14)
		MOV 	$1,-8(%14)
		ADDS	$1,$1,%0
		MOV 	%0,-4(%14)
		ADDS	%15,$0,%15
		ADDS	-4(%14),$1,%0
		ADDS	-4(%14), $1, -4(%14)
		MOV 	%0,-20(%14)
		ADDS	-4(%14),-16(%14),%0
		MOV 	%0,-20(%14)
		MOV 	-20(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET
