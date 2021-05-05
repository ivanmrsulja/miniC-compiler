
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
		MOV	$0, -16(%14)
@main_body:
para_1_1_init:
		MOV	$0, -4(%14)
para_1_1_body:
		CMPS 	-4(%14),$2
		JGTS	para_1_1_exit
		SUBS	%15,$0,%15
para_2_2_init:
		MOV	$0, -8(%14)
para_2_2_body:
		CMPS 	-8(%14),$2
		JGTS	para_2_2_exit
		SUBS	%15,$0,%15
para_3_3_init:
		MOV	$0, -12(%14)
para_3_3_body:
		CMPS 	-12(%14),$2
		JGTS	para_3_3_exit
		SUBS	%15,$0,%15
		ADDS	-16(%14), $1, -16(%14)
		ADDS	-12(%14), $1, -12(%14)
		JMP	para_3_3_body
para_3_3_exit:
para_4_3_init:
		MOV	$0, -12(%14)
para_4_3_body:
		CMPS 	-12(%14),$2
		JGTS	para_4_3_exit
		SUBS	%15,$0,%15
		ADDS	-16(%14), $1, -16(%14)
		ADDS	-12(%14), $1, -12(%14)
		JMP	para_4_3_body
para_4_3_exit:
		ADDS	-8(%14), $1, -8(%14)
		JMP	para_2_2_body
para_2_2_exit:
		ADDS	-4(%14), $1, -4(%14)
		JMP	para_1_1_body
para_1_1_exit:
para_5_1_init:
		MOV	$0, -12(%14)
para_5_1_body:
		CMPS 	-12(%14),$2
		JGTS	para_5_1_exit
		SUBS	%15,$0,%15
		ADDS	-16(%14), $1, -16(%14)
		ADDS	-12(%14), $1, -12(%14)
		JMP	para_5_1_body
para_5_1_exit:
		MOV 	-16(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET