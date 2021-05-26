
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
		MOV	$0, -8(%14)
		MOV	$0, -4(%14)
		SUBS	%15,$4,%15
		MOV	$3, -12(%14)
		SUBS	%15,$20,%15
		MOV 	$0, -16(%14)
		MOV 	$0, -20(%14)
		MOV 	$0, -24(%14)
		MOV 	$0, -28(%14)
		MOV 	$0, -32(%14)
@main_body:
		ADDS	$13,$1,%0
		MOV 	-12(%14),%1
		MULS	%1, $4, %1
		SUBS	$-16, %1, %1
		MOV 	%0, %1(%14)
		MULS	$1, $4, %0
		SUBS	$-16, %0, %0
		MOV 	%0(%14), -4(%14)
		MULS	-12(%14), $4, %0
		SUBS	$-16, %0, %0
		ADDS	%0(%14), $1, %0(%14)
		MULS	-12(%14), $4, %0
		SUBS	$-16, %0, %0
		MOV 	%0(%14), %13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET