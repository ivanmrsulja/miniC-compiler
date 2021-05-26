
f:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
		MOV	$1, -4(%14)
		SUBS	%15,$4,%15
		MOV	$3, -8(%14)
@f_body:
		ADDS	-4(%14),-8(%14),%0
		ADDS	%0,8(%14),%0
		MOV 	%0,%13
		JMP 	@f_exit
@f_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		PUSH	$18
		PUSH	$1
		CALL	f
		ADDS	%15,$8,%15
		MOV 	%13,%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET