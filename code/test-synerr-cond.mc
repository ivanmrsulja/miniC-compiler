//OPIS: ternarni operator

int one(){
	return 1;
}

int main(){
	int a = 7;
	a = (a == 7) ? 1 : (a == 9) ? 1 : 2;
	a = (a == a) ? one() : 6;
	return 0;
}
