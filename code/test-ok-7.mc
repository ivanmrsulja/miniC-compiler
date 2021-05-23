//OPIS: switch propadanje
//RETURN: 28

int main(){
	int a,b = 12;
	a = (a == b) ? a : 0;
	a = 3 + (a == b) ? 10 : 1;
	a = a + (a == b) ? a : b + 3;
    return a;
}
