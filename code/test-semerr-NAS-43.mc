//OPIS: inc nad function_call

int f(){
	int g = 1;
	return g;

} 

int main() {
	int b;
	int c;
	b = 1;
	c = b++;
	c = f++ + b + c + 5;
	return 0;
}

