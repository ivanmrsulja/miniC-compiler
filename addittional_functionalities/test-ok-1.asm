
oduzmi:
		PUSH	%14
		MOV 	%15,%14
@oduzmi_body:
		SUBS	%15,$4,%15
		MOV	$0, -4(%14)
		ADDS	%15,$4,%15
		SUBS	8(%14),12(%14),%0
		MOV 	%0,%13
		JMP 	@oduzmi_exit
@oduzmi_exit:
		MOV 	%14,%15
		POP 	%14
		RET
saberi:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
		MOV	$9, -4(%14)
@saberi_body:
		SUBS	%15,$16,%15
		MOV 	$4,-8(%14)
		MOV 	$3,-12(%14)
		MOV 	$2,-16(%14)
		MOV 	$1,-20(%14)
		SUBS	%15,$8,%15
		MOV	$8, -28(%14)
		MOV	$8, -24(%14)
		PUSH	-16(%14)
		PUSH	-4(%14)
		CALL	oduzmi
		ADDS	%15,$8,%15
		MOV 	%13,%0
		MOV 	%0,16(%14)
		PUSH	-20(%14)
		PUSH	-28(%14)
		CALL	oduzmi
		ADDS	%15,$8,%15
		MOV 	%13,%0
		MOV 	%0,8(%14)
		ADDS	%15,$8,%15
		MOV 	$0,-4(%14)
		ADDS	%15,$16,%15
		ADDS	8(%14),12(%14),%0
		ADDS	%0,16(%14),%0
		MOV 	%0,%13
		JMP 	@saberi_exit
@saberi_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
		MOV	$5, -8(%14)
		MOV	$5, -4(%14)
@main_body:
		SUBS	%15,$4,%15
		MOV	$2, -12(%14)
		ADDS	-4(%14),-12(%14),%0
		MOV 	%0,-4(%14)
		ADDS	%15,$4,%15
		ADDS	$2,$1,%0
		PUSH	%0
		PUSH	-8(%14)
		PUSH	-4(%14)
		CALL	saberi
		ADDS	%15,$12,%15
		MOV 	%13,%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET