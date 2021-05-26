
foo:
		PUSH	%14
		MOV 	%15,%14
@foo_body:
		ADDS	8(%14),$20,%0
		MOV 	%0,8(%14)
		MOV 	8(%14),%13
		JMP 	@foo_exit
@foo_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$0,-4(%14)
		SUBS	%15,$4,%15
		MOV 	$10,-8(%14)
		PUSH	-4(%14)
		CALL	foo
		ADDS	%15,$4,%15
		MOV 	%13,%0
		ADDS	-4(%14),%0,%0
		MOV 	%0,-4(%14)
		MOV 	-8(%14),-4(%14)
		ADDS	%15,$4,%15
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET