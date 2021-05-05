
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
		MOV	$0, -4(%14)
@main_body:
		JMP	switch_1_depth_1_check

switch_1_depth_1_case_16:
		ADDS	-4(%14), $1, -4(%14)

switch_1_depth_1_case_17:
		ADDS	-4(%14), $1, -4(%14)

switch_1_depth_1_skip_check:
		JMP	switch_1_depth_1_exit

switch_1_depth_1_check:
		CMPS 	-4(%14),$0
		JEQ	switch_1_depth_1_case_16
		CMPS 	-4(%14),$1
		JEQ	switch_1_depth_1_case_17

switch_1_depth_1_exit:
		JMP	switch_2_depth_1_check

switch_2_depth_1_case_18:
		ADDS	-4(%14), $1, -4(%14)

switch_2_depth_1_otherwise:
		ADDS	-4(%14),$9,%0
		MOV 	%0,-4(%14)
		JMP	switch_2_depth_1_exit

switch_2_depth_1_skip_check:
		JMP	switch_2_depth_1_exit

switch_2_depth_1_check:
		CMPS 	-4(%14),$2
		JEQ	switch_2_depth_1_case_18
		JMP	switch_2_depth_1_otherwise

switch_2_depth_1_exit:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET