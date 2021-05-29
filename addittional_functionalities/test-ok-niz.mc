//OPIS: nizovi
//RETURN: 31

int main(){
	int ind, i = 0;
	int broj = 1;

	int a[5];
	
	a[ind] = a[3] + 13;
	a[ind]++;
	
	a[1] = a[0] + broj + 1 + a[0];
	
	while (i < 10) {
		a[i] = a[i] + i;
		i++;
	}
	
	return a[1];
}
