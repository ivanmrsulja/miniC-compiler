//OPIS: funkcija sa 1 i 0 parametara
//RETURN: 4
int func1(int p) {
    int k, s = 10;
    int x, b;
    int c = 2;
    x = p;
    b = 3;
    return x;
}

void foo(){
    return;
}

int main(){
	int b;
	b = func1(4);
	func1(b);
	func1(5);
	foo();
	return b;
}
