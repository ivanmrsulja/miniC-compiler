// OPIS: ok switch i lokalne unutar bloka ugnjezdeno
int main(){
    int a = 6;
    unsigned b = 6u;

    {
        int a;
        {
            int b = 6;
            b = 7;
        }
        a = 7;
    }

    switch(a){
        case 1:
            a = 5;
            break;
        case 5:
            a = 1;
        case 2:
        {
            unsigned hg;
            a = a - 7;
            switch(b){
                case 1u:
                    hg = 1u;
                    break;
                case 5u:
                    hg = 2u;
                    break;
            }
        }
        break; /* pitaj za ovo */
    }

    {
        int a;
        {
            int b = 6;
            b = 7;
        }
        a = 7;
    }

}
