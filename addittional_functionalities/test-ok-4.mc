//OPIS: switch statement
//RETURN: 77

int main(){
	int a;
	a = 1;
	switch(a){
		case 1:
		{
			a = 9;
			switch(a){
				case 44:
				{
					a = 7;
					
				}	
					break;
				case 9:
					{
						a = 1;
						switch(a){
							case 1:
								a = 7;
						}
					}
					break;
				otherwise:
					a = 7;
			}
		}	
			break;
		case 9:
			a = 17;
			break;
		otherwise:
			a = 19;
	}
	
	switch(a){
		case 7:
			a = 77;
			break;
		case 19:
			a = 17;
			break;
		otherwise:
			a = 18;
	}
	
	return a;
}
