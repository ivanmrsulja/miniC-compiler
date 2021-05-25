
global:
		WORD	1
foo:
		PUSH	%14
		MOV 	%15,%14
@foo_body:
@if0:
		CMPU 	8(%14),$10
		JNE 	@false0
@true0:
		ADDU	global,8(%14),%0
		MOV 	%0,global
		JMP 	@foo_exit
		ADDS	%15,$0,%15
		JMP 	@exit0
@false0:
@exit0:
		ADDU	global,8(%14),%0
		ADDU	%0,$1,%0
		MOV 	%0,global
@foo_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
		MOV	$10, -4(%14)
@main_body:
		MOV 	$0,global
		PUSH	-4(%14)
		CALL	foo
		ADDS	%15,$4,%15
		MOV 	global,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET