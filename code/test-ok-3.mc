//OPIS: para statement
//RETURN: 12

int main(){
	int a, i, j;
	int b = 0;
	para (a = 0 en 2){
		para(i = -2 en 0){
			b++;
		}
		para(j = -1 en 1){
			b = b + j;
		}
	}
	
	para(j = 0 en 2){
		b = b + j;
	}
	return b;
}
