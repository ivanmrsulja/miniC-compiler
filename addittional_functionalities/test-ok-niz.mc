//OPIS: nizovi
//RETURN: 15

int main(){
	int ret, i = 0;
	int idx = 3;

	int a[5];
	
	a[idx] = 13 + 1;
	ret = a[1];
	
	a[idx]++;

	return a[idx];
}
