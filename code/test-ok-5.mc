//OPIS: switch statement
//RETURN: 1

unsigned main(){
	unsigned a = 0u;
	switch(a){
		case 0u:
			a = 2u;
	}
	
	switch(a){
		case 1u:
			a = 2u;
		otherwise:
		{
			switch(a){
				case 2u:
					a = 1u;
			}
		}
	}
	return a;
}
