//OPIS: inc nad function_call

int f(){
	int k;
	int g;
	k = 5;
	g = k;
	return g;

} 

int main() {
    int d, b, c = 0;
	
	c = f++;
	return 0;
}

