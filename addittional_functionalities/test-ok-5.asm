
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
		MOV	$0, -4(%14)
@main_body:
		JMP	switch_1_depth_1_check

switch_1_depth_1_case_16:
		MOV 	$2,-4(%14)
		JMP	switch_1_depth_1_exit

switch_1_depth_1_skip_check:
		JMP	switch_1_depth_1_exit

switch_1_depth_1_check:
		CMPU 	-4(%14),$0
		JEQ	switch_1_depth_1_case_16

switch_1_depth_1_exit:
		JMP	switch_2_depth_1_check

switch_2_depth_1_case_17:
		SUBS	%15,$0,%15
		MOV 	$3,-4(%14)
		JMP	switch_3_depth_2_check

switch_3_depth_2_case_18:
		MOV 	$1,-4(%14)
		JMP	switch_3_depth_2_exit

switch_3_depth_2_skip_check:
		JMP	switch_3_depth_2_exit

switch_3_depth_2_check:
		CMPU 	-4(%14),$3
		JEQ	switch_3_depth_2_case_18

switch_3_depth_2_exit:
		ADDS	%15,$0,%15

switch_2_depth_1_case_20:
		SUBS	%15,$0,%15
		JMP	switch_4_depth_2_check

switch_4_depth_2_case_17:
		MOV 	$1,-4(%14)

switch_4_depth_2_otherwise:
		JMP	switch_5_depth_3_check

switch_5_depth_3_case_18:
		MOV 	$1,-4(%14)

switch_5_depth_3_skip_check:
		JMP	switch_5_depth_3_exit

switch_5_depth_3_check:
		CMPU 	-4(%14),$3
		JEQ	switch_5_depth_3_case_18

switch_5_depth_3_exit:
		JMP	switch_4_depth_2_exit

switch_4_depth_2_skip_check:
		JMP	switch_4_depth_2_exit

switch_4_depth_2_check:
		JMP	switch_4_depth_2_otherwise

switch_4_depth_2_exit:
		ADDS	%15,$0,%15

switch_2_depth_1_skip_check:
		JMP	switch_2_depth_1_exit

switch_2_depth_1_check:
		CMPU 	-4(%14),$2
		JEQ	switch_2_depth_1_case_17
		CMPU 	-4(%14),$17
		JEQ	switch_2_depth_1_case_20

switch_2_depth_1_exit:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET