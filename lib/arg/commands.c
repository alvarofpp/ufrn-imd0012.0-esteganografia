/**
* -i [input-file] | -f [format] | -m [metodo] | -o [output-file]
*/
int getParametro(int argc, char **argv, char *argumento)
{
	int i; // Contador

  for(i = 0; i < argc; i++)
  {
		if(strcmp(argv[i], argumento) == 0){
			return i+1;
		}
  }

	return 0;
}
