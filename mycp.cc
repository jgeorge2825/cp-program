//header file                                                                   
//                                                                              
#include "mycp.h"

//main function                                                                 
//                                                                                                                                           
int main(int argc, char* argv[])
{

  //declares files and variables                                                
  //                                                                            
  FILE *fp1, *fp2;
  int blocksize;
  int sz;
  int nmemb;
  char* ptr;
  int n;

  //opens, reads, writes file                                                   
  //                                                                            
  fp1 = fopen(argv[1],"r");
  fp2 = fopen(argv[2],"w");

  //reading blocksize                                                           
  //                                                                            
  blocksize=atoi(argv[3]);

  //error will pop up if incorrect number of arguments                          
  //                                                                            
  if(!fp1 || !fp2 ||argc!=4)
    {
      printf("error");
        }
  
  //seeks for file size                                                         
  //                                                                            
  fseek(fp1, 0, SEEK_END);
  sz = ftell(fp1);
  rewind(fp1);

  //if statement for when blocksize is greater than sz                          
  //                                                                            
  if(blocksize>sz){
    nmemb = 1;
    blocksize = sz;
  }
  else{
    
    //calculates number of elements                                             
    //                                                                          
    nmemb = sz/blocksize;
      }

  //allocate space                                                              
  //                                                                            
  ptr = (char*)malloc(nmemb*blocksize);
  memcpy(fp2,&fp1,blocksize);

  //retrieves contents from first file and puts them into the second            
  //                                                                            
  fread(ptr,blocksize,nmemb,fp1);
  fwrite(ptr, blocksize,nmemb,fp2);

  //close and exit                                                              
  //                                                                            
  fclose(fp1);
  fclose(fp2);
  return 0;
}
