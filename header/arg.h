#ifndef arg_h
#define arg_h

void imprimirArgv(int argc, char **argv){
  int i;
  for(i = 0; i < argc; i++){
    printf("%s\n", argv[i]);
  }
}

#endif
