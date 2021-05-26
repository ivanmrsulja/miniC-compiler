
foo:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@foo_body:
		MOV 	$5,-4(%14)
		MOV 	$1,-8(%14)
		ADDS	8(%14),-4(%14),%0
		ADDS	%0,-8(%14),%0
		MOV 	%0,12(%14)
		MOV 	12(%14),%13
		JMP 	@foo_exit
@foo_exit:
		MOV 	%14,%15
		POP 	%14
		RET
foo1:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@foo1_body:
		MOV 	8(%14),-4(%14)
		MOV 	-4(%14),%13
		JMP 	@foo1_exit
@foo1_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		PUSH	$3
		PUSH	$1
		CALL	foo
		ADDS	%15,$8,%15
		MOV 	%13,%0
		PUSH	$1
		PUSH	$1
		CALL	foo1
		ADDS	%15,$8,%15
		MOV 	%13,%1
		ADDS	%0,%1,%0
		MOV 	%0,-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET