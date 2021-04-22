// OPIS: break unutar bloka
int main(){
    int a = 6;
    unsigned b = 6u;


    switch(a){
        case 1:
            a = 5;
            break;
        case 5:
            a = 1;
        case 2:
        {
        break;
    	}
    }

}
