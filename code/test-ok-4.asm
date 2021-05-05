
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$1,-4(%14)
		JMP	switch_1_depth_1_check

switch_1_depth_1_case_16:
		SUBS	%15,$0,%15
		MOV 	$9,-4(%14)
		JMP	switch_2_depth_2_check

switch_2_depth_2_case_18:
		SUBS	%15,$0,%15
		MOV 	$7,-4(%14)
		JMP	switch_2_depth_2_exit

switch_2_depth_2_case_17:
		SUBS	%15,$0,%15
		MOV 	$1,-4(%14)
		JMP	switch_3_depth_3_check

switch_3_depth_3_case_16:
		MOV 	$7,-4(%14)

switch_3_depth_3_skip_check:
		JMP	switch_3_depth_3_exit

switch_3_depth_3_check:
		CMPS 	-4(%14),$1
		JEQ	switch_3_depth_3_case_16

switch_3_depth_3_exit:
		JMP	switch_2_depth_2_exit

switch_2_depth_2_otherwise:
		MOV 	$7,-4(%14)
		JMP	switch_2_depth_2_exit

switch_2_depth_2_skip_check:
		JMP	switch_2_depth_2_exit

switch_2_depth_2_check:
		CMPS 	-4(%14),$9
		JEQ	switch_2_depth_2_case_17
		CMPS 	-4(%14),$44
		JEQ	switch_2_depth_2_case_18
		JMP	switch_2_depth_2_otherwise

switch_2_depth_2_exit:
		JMP	switch_1_depth_1_exit

switch_1_depth_1_case_17:
		MOV 	$17,-4(%14)
		JMP	switch_1_depth_1_exit

switch_1_depth_1_otherwise:
		MOV 	$19,-4(%14)
		JMP	switch_1_depth_1_exit

switch_1_depth_1_skip_check:
		JMP	switch_1_depth_1_exit

switch_1_depth_1_check:
		CMPS 	-4(%14),$1
		JEQ	switch_1_depth_1_case_16
		CMPS 	-4(%14),$9
		JEQ	switch_1_depth_1_case_17
		JMP	switch_1_depth_1_otherwise

switch_1_depth_1_exit:
		JMP	switch_4_depth_1_check

switch_4_depth_1_case_19:
		MOV 	$77,-4(%14)
		JMP	switch_4_depth_1_exit

switch_4_depth_1_case_21:
		MOV 	$17,-4(%14)
		JMP	switch_4_depth_1_exit

switch_4_depth_1_otherwise:
		MOV 	$18,-4(%14)
		JMP	switch_4_depth_1_exit

switch_4_depth_1_skip_check:
		JMP	switch_4_depth_1_exit

switch_4_depth_1_check:
		CMPS 	-4(%14),$7
		JEQ	switch_4_depth_1_case_19
		CMPS 	-4(%14),$19
		JEQ	switch_4_depth_1_case_21
		JMP	switch_4_depth_1_otherwise

switch_4_depth_1_exit:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET