//OPIS: switch statement
//RETURN: 1

int main(){
	int a = 0;
	switch(a){
		case 0:
			a = 2;
	}
	
	switch(a){
		case 1:
			a = -2;
		otherwise:
		{
			switch(a){
				case 2:
					a = 1;
			}
		}
	}
	return a;
}
