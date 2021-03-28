// OPIS: ok switch
int main(){
    int a = 6;
    switch(a){
        case 1:
            a = 5;
            break;
        case 5:
            a = 1;
        case 2:
        {
            a = a - 7;
        }
        break; /* pitaj za ovo */
    }
}