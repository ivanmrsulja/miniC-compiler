// OPIS: SWITCH statement semerrors
int main(){
    int aa, b;
    unsigned a = 7u;

  switch (aa){
    case 1:
      aa = aa + 5;
      break;
    case 5u:
    {
      b = 3;
    }
  }

  switch (a){
        case 1:
            aa = aa + 5;
            break;
        case 5u:
        {
            b = 3;
        }
        otherwise:
            aa = aa - 1;
  }

  switch (a){
        case 1:
            aa = aa + 5;
            break;
        case 1:
        {
            b = 3;
        }
        otherwise:
            aa = aa - 1;
  }

}