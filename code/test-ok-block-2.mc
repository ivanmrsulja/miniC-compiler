//OPIS: blokovske promenljive ugnjezdeni blokovi
//RETURN: 3

int main(){
	int a; 
	int b; 
	int c;
	
	{
		int a; 
		a = 1; 
		b = 2; 
		c = a + b;
		{
			int c, b; 
			int a; 

			c = 2;
			b = 1;
			a = c + 1;
		} 
	}
	b = c;
	a = b; 
	return a; 

}
