//OPIS: switch propadanje
//RETURN: 12

int main(){
	int a = 0;
	switch(a){
		case 0:
			a++;
		case 1:
			a++;
	}
	
	switch(a){
		case 2:
			a++;
		otherwise:
			a = a + 9;
	}
	return a;
}
