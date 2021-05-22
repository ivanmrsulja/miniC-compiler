//OPIS: void, retrun;
//RETURN: 10

unsigned global;

void foo(unsigned broj){
	if (broj == 10u){
		global = global + broj;
		return;
	}
	global = global + broj + 1u;
}

unsigned main(){
	unsigned a = 10u;
	global = 0u;
	foo(a);
	return global;
}
