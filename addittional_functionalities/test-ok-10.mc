//OPIS: while statement
//RETURN: 41

unsigned j;

int main(){
    int i, k = 0;
    j = 0u;
    while (i < 10){
        i = i + 1;
        while (j < 10u){
            i = i + 1;
            j++;
        }
        j = 0u;
        while (j < 10u){
            i = i + 1;
            j++;
            while (k < 2){
                i = i + 1;
                k++;
            }
            k = 0;
        }
    }
    return i;
}
