//OPIS: switch propadanje
//RETURN: 12

int main(){
	int a = 0;
	switch(a){
		case 0:
			a = a + 2;
			break;
		case 1:
			a++;
	}
	
	switch(a){
		case 2:
			a++;
		case 0:
			a = a + 0;
		otherwise:
		{
			int i = 9;
			a = a + i;
		}			
	}
	return a;
}
