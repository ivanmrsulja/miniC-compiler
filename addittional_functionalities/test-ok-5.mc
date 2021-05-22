//OPIS: switch statement
//RETURN: 1

unsigned main(){
	unsigned a = 0u;
	switch(a){
		case 0u:
			a = 2u;
			break;
	}
	
	switch(a){
		case 2u:
			{
				a = 3u;
				switch(a){
						case 3u:
							a = 1u;
							break;
					}
				
			}
		case 17u:
		{
			switch(a){
				case 2u:
					a = 1u;
				otherwise:
					switch(a){
						case 3u:
							a = 1u;
					}
			}
		}
	}
	
	return a;
}
