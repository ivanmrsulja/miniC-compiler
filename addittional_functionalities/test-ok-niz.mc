//OPIS: nizovi
//RETURN: 12

int main(){
	int a[2];
	int b[2];
	int retVal = -1;
	a[0] = 10;
	{
		b[1] = 9;
		a[1] = 1;
		a[0] = 1 + 1;
	}
	retVal = a[0]++ + 1;
	retVal = a[0] + b[1];
	return retVal;
}
