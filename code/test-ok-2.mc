//OPIS: void, retrun;
//RETURN: 10

unsigned global;

void foo(unsigned broj){
	global = global + broj;
}

unsigned main(){
	unsigned a = 10u;
	global = 0u;
	foo(a);
	return global;
}
