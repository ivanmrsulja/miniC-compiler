
j:
		WORD	1
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
		MOV	$0, -8(%14)
		MOV	$0, -4(%14)
@main_body:
		MOV 	$0,j
while_1_depth_1:
		CMPS 	-4(%14),$10
		JGES	end_while_1_depth_1
		SUBS	%15,$0,%15
		ADDS	-4(%14),$1,%0
		MOV 	%0,-4(%14)
while_2_depth_2:
		CMPU 	j,$10
		JGEU	end_while_2_depth_2
		SUBS	%15,$0,%15
		ADDS	-4(%14),$1,%0
		MOV 	%0,-4(%14)
		ADDU	j, $1, j
		ADDS	%15,$0,%15
		JMP	while_2_depth_2
end_while_2_depth_2:
		MOV 	$0,j
while_3_depth_2:
		CMPU 	j,$10
		JGEU	end_while_3_depth_2
		SUBS	%15,$0,%15
		ADDS	-4(%14),$1,%0
		MOV 	%0,-4(%14)
		ADDU	j, $1, j
while_4_depth_3:
		CMPS 	-8(%14),$2
		JGES	end_while_4_depth_3
		SUBS	%15,$0,%15
		ADDS	-4(%14),$1,%0
		MOV 	%0,-4(%14)
		ADDS	-8(%14), $1, -8(%14)
		ADDS	%15,$0,%15
		JMP	while_4_depth_3
end_while_4_depth_3:
		MOV 	$0,-8(%14)
		ADDS	%15,$0,%15
		JMP	while_3_depth_2
end_while_3_depth_2:
		ADDS	%15,$0,%15
		JMP	while_1_depth_1
end_while_1_depth_1:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET