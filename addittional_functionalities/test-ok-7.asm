
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
		MOV	$12, -8(%14)
		MOV	$12, -4(%14)
@main_body:
		CMPS 	-4(%14),-8(%14)
		JNE 	second_choice_1
		MOV	$10, %0
		JMP	cond_end_1
second_choice_1:
		MOV	$1, %0
cond_end_1:
		ADDS	$3,%0,%0
		MOV 	%0,-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET