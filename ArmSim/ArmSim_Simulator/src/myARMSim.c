#include "myARMSim.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
extern void pipelined_simulator( char *,unsigned int );
extern int read_word(char *, unsigned int ) ;
extern void write_word(char *, unsigned int , unsigned int );
int ldr=0,ldr_pseudo=0,str=0,str_pseudo=0,add=0,sub=0,cmp=0,mul=0,bne=0,bge=0,b=0,bl=0,mov=0,orr=0,and1=0,mnv=0,swi_exit1=0; 
//Register file
static unsigned int R[16];
//flags
static int N,C,V,Z;
//memory
static unsigned char MEM[4000];
static unsigned char DMEM[4000];
static int line_count=0;
static int error_count=0;
static unsigned int Tcycles=0;
//intermediate datapath and control path signals
static unsigned int fetch_inst=0;
static unsigned int instruction_word;
static unsigned int operand1;
static unsigned int operand2;
static unsigned int destination;
static unsigned int opcode; 
static unsigned int f;
static unsigned int address=0;

struct label
{
char label[30];
int address;
};
static struct label lbl[30];

void show_state()
{ for (int i = 0; i < 16; ++i)
{
  printf("R%d=%x\t",i,R[i] );
}printf("\n");
for (int i = 0; i < 400; i+=4)
{
  printf("%d\t",DMEM[i] );
}
printf("\n");
}

void parlatency(char* file_name)
{ FILE *fp;
  fp = fopen(file_name, "r");
  if(fp == NULL) {
    printf("Error opening input latency file\n");
    exit(1);
  }int i,i1=0,i2=0,error_count1=0,line_count=0;
  char temp[6];
  char line[256];
  while (fgets(line, sizeof(line), fp)) 
   {
    
        int len=strlen(line);
         i=0;i1=0;
         while(line[i]!='\0' && line[i]!='#')
        {
           i++;
        } 
  
        if (i!=len) line[i]='\0';
        char* s[12]={""};
        char* tok;
        tok=strtok(line," =;\n\t"); 
        while(tok!=NULL)
       {
        s[i1]=tok;i1++;
       // printf("%s\n",tok );
        tok = strtok (NULL, " =;\n\t");
       }//printf("\n");
        line_count++;
       if (s[0]!="")
       { if (s[2]!=NULL)
         {error_count1++;
            printf("only one instruction latency can be written in one line \n");
         }else
        {   if(!strcmp(s[0],"ldr") || !strcmp(s[0],"LDR") || !strcmp(s[0],"Ldr"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : ldr has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : ldr instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           ldr=10*ldr + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"str") || !strcmp(s[0],"STR") || !strcmp(s[0],"Str"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : str has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : str instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           str=10*str + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"ldr_pseudo") || !strcmp(s[0],"LDR_PSEUDO") || !strcmp(s[0],"Ldr_Pesudo"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : ldr_pseudo has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : ldr_pseudo instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           ldr_pseudo=10*ldr_pseudo + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"str_pseudo") || !strcmp(s[0],"STR_PSEUDO") || !strcmp(s[0],"Str_Pseudo"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : str_pseudo has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : str_pseudo instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           str_pseudo=10*str_pseudo + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"add") || !strcmp(s[0],"ADD") || !strcmp(s[0],"Add"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : add has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : add instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           add=10*add + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"sub") || !strcmp(s[0],"SUB") || !strcmp(s[0],"Sub"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : sub has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : sub instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           sub=10*sub + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"cmp") || !strcmp(s[0],"CMP") || !strcmp(s[0],"Cmp"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : cmp has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : cmp instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           cmp=10*cmp + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"mul") || !strcmp(s[0],"MUL") || !strcmp(s[0],"Mul"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : mul has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : mul instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           mul=10*mul + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"bne") || !strcmp(s[0],"BNE") || !strcmp(s[0],"Bne"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : bne has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : bne instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           bne=10*bne + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"bge") || !strcmp(s[0],"BGE") || !strcmp(s[0],"Bge"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : bge has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : bge instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           bge=10*bge + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"b") || !strcmp(s[0],"B"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : branch has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : branch instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           b=10*b + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"bl") || !strcmp(s[0],"BL") || !strcmp(s[0],"Bl"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : bl has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : bl instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           bl=10*bl + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"mov") || !strcmp(s[0],"MOV") || !strcmp(s[0],"Mov"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : mov has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : mov instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           mov=10*mov + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"ORR") || !strcmp(s[0],"orr") || !strcmp(s[0],"Orr"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : orr has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : orr instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           orr=10*orr + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"and") || !strcmp(s[0],"AND") || !strcmp(s[0],"And"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : and has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : and instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           and1=10*and1 + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"mnv") || !strcmp(s[0],"MNV") || !strcmp(s[0],"Mnv"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : mnv has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : mnv instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           mnv=10*mnv + s[1][i]-'0';
                        }
                    }
            }
           }else if(!strcmp(s[0],"swi_exit") || !strcmp(s[0],"SWI_EXIT") || !strcmp(s[0],"Swi_Exit"))
           {  if (s[1]==NULL)
            { error_count1++;
             printf("Error in line=%d : swi_exit has no latency specified\n",line_count );
            }else
            { int nott=0,st=strlen(s[1]);
              for (int i = 0; i < st; ++i)
              {
                if(s[1][i]>57 || s[1][i]<48) {nott=1;break;}
              }
                if (nott==1)
                {   error_count1++;
                  printf("Error in line=%d : swi_exit instruction has non-numeric latency\n",line_count );
                }else{ for (int i = 0; i < st; ++i)
                        {
                           swi_exit1=10*swi_exit1 + s[1][i]-'0';
                        }
                    }
            }
           }else{
            error_count1++;
            printf("Error in line=%d : unable to parse instruction type\n",line_count );
           }
        }      
       }

   }  
  if (error_count1!=0)
  {
    printf("Please fix errors in latency file and re-run the program \n");exit(1);
  }
 if (ldr==0)
  {
    ldr=20;
  }
  if (ldr_pseudo==0)
   {
     ldr_pseudo=1;
   } 
  if (str==0)
  {
    str=20;
  }
  if (str_pseudo==0)
  {
    str_pseudo=1;
  }
  if (add==0)
  {
    add=1;
  }
  if (sub==0)
  {
    sub=1;
  }
  if (cmp==0)
  {
    cmp=1;
  }
  if (mul==0)
  {
    mul=5;
  }
  if (bne==0)
  {
    bne=2;
  }
  if (bge==0)
  {
    bge=2;
  }
  if (b==0)
  {
    b=2;
  }
  if (bl==0)
  {
    bl=2;
  }
  if (mov==0)
  {
    mov=1;
  }
  if (mnv==0)
  {
    mnv=1;
  }
  if (orr==0)
  {
    orr=1;
  }
  if (and1==0)
  {
    and1=1;
  }
  if (swi_exit1==0)
  {
    swi_exit1=100;
  }
}




void run_armsim() {
  pipelined_simulator(MEM,address);
}

//reads from the instruction memory and updates the instruction register
void fetch() {
  instruction_word = read_word(MEM, R[15]);
 // printf("FETCH: Fetch instruction 0x%x from address 0x%x\n", instruction_word, R[15]);
  R[15]+=4;fetch_inst++;
  //FETCH:Fetch instruction 0xE3A0200A from address 0x0
}


//reads the instruction register, reads operand1, operand2 fromo register file, decides the operation to be performed in execute stage
void decode() {
  if(instruction_word==0xEF000011)swi_exit();
  f=(instruction_word&0x0C000000)>>26;
  unsigned int Rn, Rd, i, op2;
  if(f==0){
    opcode = (instruction_word&0x01E00000)>>21;
    Rn = (instruction_word&0x000F0000)>>16;
    Rd = (instruction_word&0x0000F000)>>12;
    operand1 = R[Rn];
    i = (instruction_word&0x02000000)>>25;
    if(i==0){ //Register
      op2 = (instruction_word&0xF);
      operand2 = R[op2];
    }else{ //Immediate
      op2 = (instruction_word&0xFF);
      operand2 = op2;
    }
    destination = Rd;
    if ( opcode==4)
     {Tcycles+=add; }
    if (opcode==2)
      {Tcycles+=sub;}
    if (opcode==5)
      {Tcycles+=mul;}
    if (opcode==10)
      {Tcycles+=cmp;}
    if (opcode==13)
      {Tcycles+=mov;}
    if (opcode==0)
      {Tcycles+=and1;}
    if (opcode==12)
      {Tcycles+=orr;}      
    if (opcode==15)
      {Tcycles+=mnv;}

  }else if(f==1){  //LDR/STR
    opcode = (instruction_word&0x03F00000)>>20;
    Rn = (instruction_word&0x000F0000)>>16;
    Rd = (instruction_word&0x0000F000)>>12;
    destination = Rd;
    if(Rn==14)
    {operand1 = instruction_word&0x00000FFF;
      if(opcode==24) Tcycles+=str_pseudo;
      else Tcycles+=ldr_pseudo;}
    else if (Rn==15)
     {operand1=-1;Tcycles+=ldr_pseudo;}
    else
    {   if((R[Rn]+instruction_word&0x00000FFF)>=4000)
         {printf("segmentation fault:accessing memory other then assigned\n");
          exit(1); }    
        operand1=R[Rn]+instruction_word&0x00000FFF;
     if (opcode==24)
      {Tcycles+=str;}
      if (opcode==25)
      {Tcycles+=ldr;}
    }
      
  }else if(f==2){  //Branch
      opcode = (instruction_word&0xF0000000)>>28;
      if (opcode==10 || opcode==12 || opcode==13)
      {Tcycles+=bge;}
      else if (opcode==1  || opcode==0 )
      {Tcycles+=bne;}
      else if (opcode==11)
      {Tcycles+=bl;}
      else Tcycles+=b;
    opcode = (instruction_word&0xF0000000)>>28;
    operand2 = (instruction_word&0xFFFFFF);
   
  }
}
//executes the ALU operation based on ALUop
void execute() {
  //printf("EXECUTE: ");
  if(f==0){
    if(opcode==0){ //AND
      //printf("AND %d and %d\n", operand1, operand2);
      operand1 = operand1&operand2;
    }else if(opcode==4){ //ADD
      //printf("ADD %d and %d\n", operand1, operand2);
      operand1 = operand1+operand2;
    }else if(opcode==2){ //SUB
      //printf("SUB %d and %d\n", operand1, operand2);
      operand1 = operand1-operand2;
    }else if(opcode==10){ //CMP
      //printf("CMP %d and %d\n", operand1, operand2);
      Z=0; N=0;
      destination=13;
      if(operand1-operand2==0){
        Z=1;
        //printf("EXECUTE: Z updated to 1\n");
      }
      if(operand1-operand2<0){
        N=1;
        //printf("EXECUTE: N updated to 1\n");
      }
    }else if(opcode==12){ //ORR
      //printf("OR %d and %d\n", operand1, operand2);
      operand1 = operand1|operand2;
    }else if(opcode==13){ //MOV
      //printf("No execute operation\n");
      operand1 = operand2;
    }else if(opcode==15){ //MNV
      //printf("MNV %d\n", operand2);
      operand1 = ~operand2;
    }else if (opcode==5){//MUL
      operand1=operand1*operand2;
    }

  }else if(f==1){
    //printf("No execute operation\n");
  }else if(f==2){
    operand1 = 0;
    if(opcode==0){ //EQ
      if(Z)operand1 = 1;
    }else if(opcode==1){ //NE
      if(!Z)operand1 = 1;
    }else if(opcode==11){ //LT is L
          operand1 = 1;
    }else if(opcode==13){ //LE
      if(N||Z)operand1 = 1;
    }else if(opcode==12){ //GT
      if(!N)operand1 = 1;
    }else if(opcode==10){ //GE
      if(!N&&Z)operand1 = 1;
    }else if(opcode==14){ //AL
      operand1 = 1;
    }
    if(operand1==1){
     //operand 2 is itself the address where we have to go
      R[15]=operand2;
      if (opcode==11)
      {
        R[14]=R[15];
      }
     
    }
  }
}
// it is used to set the reset values
//reset all registers and memory content to 0
void reset_proc() {
  int i;
  for(i=0;i<=15;i++){
    R[i]=0;
  }
  for(i=0; i<4000; i++){
    MEM[i]=0;
    DMEM[i]=0;
  }
  R[13]=4000;
}

//load_program_memory reads the input memory, and populates the instruction 
// memory
void load_program_memory(char *file_name) {
  FILE *fp;
  fp = fopen(file_name, "r");
  if(fp == NULL) {
    printf("Error opening input asm file\n");
    exit(1);
  }int i,i1=0,i2=0,end=0,label_count=0,last,lbl_count=30,inst_count=0;
  char temp[6];
  char line[256];
  while (fgets(line, sizeof(line), fp)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) 
           
           }*/
         int len=strlen(line);
        i=0;i1=0;
         while(line[i]!='\0' && line[i]!='@')
        {
           i++;
        } 
  
        if (i!=len) line[i]='\0';
        char* s[12]={""};
        char * tok;
        tok=strtok(line," ,\n\t"); 
        while(tok!=NULL)
       {
        s[i1]=tok;i1++;
       // printf("%s\n",tok );
        tok = strtok (NULL, " ,\n\t");
       }//printf("\n");
        line_count++;
        
        if(i2==1)
         i2=2;

        if (!strcmp(s[0],".text"))
          {i2=1;if(s[1]!=NULL) {printf("Error:in line no=%d .text should not be followed by anything other than comments\n",line_count);exit(1);}}
        
        if(i2==3)
         i2=4;

        if(!strcmp(s[0],".data"))
        {  i2=3;if(s[1]!=NULL) {printf("Error:in line no=%d .data should not be followed by anything other than comments\n",line_count);exit(1);}
        }

       

       
       last=strlen(s[0]);
      if(s[0][last-1]==':' && i2==2)
       { s[0][last-1]='\0';
        


       if ((s[0][0]<='Z' && s[0][0]>='A') || (s[0][0]<='z' && s[0][0]>='a'))
                 {  int nott=0;
                   
                  for (int i = 1; i < last-1; ++i)
                 {
                   if(!((s[0][i]>='0' && s[0][i]<='9') || (s[0][i]<='Z' && s[0][i]>='A') || (s[0][i]<='z' && s[0][i]>='a')) )
                     nott=1;                       
                 }
                  if (nott==1)
                  {
                   printf("Error: label is not in correct format in line:%d\n",line_count);
                  exit(1);  }
                  

                  }else{ 
                         printf("Error: label is not in correct format in line:%d\n",line_count);
                        exit(1);   }
                        
            




        for (int i = 0; i < label_count; ++i)
        {  
           if(!strcmp(s[0],lbl[i].label)) {
            printf("multiple label of same Name:%s\n",s[0] );exit(1);
          }
        }
        strcpy(lbl[label_count].label,s[0]);
          lbl[label_count].address=4*inst_count;
         label_count++;
         if(s[1]!=NULL)
          inst_count++;
           if(label_count==30)
          {printf("label_count limit reached\n");exit(1);}

       }

       else if(i2==2 && s[0]!="" &&  s[0][strlen(s[0])-1]!=':')
         inst_count++;
         if(i2>=3 && !strcmp(s[0],".end")) end=1;
    }
    if(i2==0) {printf("Error: .text not detected please put .text in starting of new line with no character before .text in new line.\n"); exit(1);}
    if(i2==2) {printf("Error: .data not detected please put .data in starting of new line with no character before .data in new line.\n"); exit(1);}
    if(end!=1) {printf("Error: end of program is not detected please put .end in new line without any thing before it in newline\n"); exit(1);}
    i=0;i1=0;i2=0;line_count=0;
  fclose(fp);
  fp = fopen(file_name, "r");
  while (fgets(line, sizeof(line), fp)) {
        
         int len=strlen(line);line_count++;
        i=0;i1=0;
         while(line[i]!='\0' && line[i]!='@')
        {
           i++;
        } 
  
        if (i!=len) line[i]='\0';
        char* s[12]={""};
        char * tok;
        tok=strtok(line," ,\n\t"); 
        while(tok!=NULL)
       {
        s[i1]=tok;i1++;
        tok = strtok (NULL, " ,\n\t");
       }
        
        if(i2==1)
         i2=2;

        if (!strcmp(s[0],".text"))
          i2=1;
        
        if(i2==3)
         i2=4;

        
        if(!strcmp(s[0],".data"))
          i2=3;

        
      
      if(i2==2) partext(s);       
    }
    fclose(fp);

    
    if (error_count!=0)
    {
      printf("Total number of errors:%d please fix them to continue\n",error_count );
    exit(1);}

if (read_word(MEM,address-4)!=0xEF000011)
    {
      printf("Error: non terminating program please put swi swi_exit at the end of text section of program\n");
      exit(1); }

// FILE *fp;
  fp = fopen("inst.txt", "w");
  if(fp == NULL) {
    printf("Error opening inst.txt file for writing\n");
    return;
  }
  
  for(i=0; i < address; i = i+4){
    fprintf(fp, "%x\n", read_word(MEM, i));
  }
  fclose(fp);

}




void partext(char* s[])
{ unsigned int instruction;int len=strlen(s[0]);

  if (s[0]!="")
  {   


    if (s[0][len-1]==':')
    { 
     if(s[1]==NULL){ 
     
       }else if(!strcmp(s[1],"swi") || !strcmp(s[1],"SWI"))
       {if (s[3]!=NULL)
       { error_count++;
         printf("Error: ideally there should be no instruction after swi_exit command. line:%d\n",line_count);
       }else if(s[2]==NULL)
       {
        error_count++;
        printf("Error: swi command not complete in line:%d\n",line_count);
       }else{ if (!strcmp(s[2],"swi_exit") || !strcmp(s[2],"SWI_EXIT") || !strcmp(s[2],"SWI_Exit"))
               {
                  write_word(MEM, address, 0xEF000011);
                  address+=4;
               }else{error_count++;
                  printf("Error:right now only swi_exit command can be execute so put swi swi_exit in line:%d\n",line_count );
               }
               


       }

       }else if(!strcmp(s[1],"add") || !strcmp(s[1],"ADD"))
      {  if(s[2]==NULL || s[3]==NULL || s[4] == NULL)
         {error_count++;
          printf("ADD instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[5]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51 ))
                    {int Rd; if(strlen(s[2])==2) Rd = (int)s[2][1]-'0';
                      if(strlen(s[2])==3) Rd=(s[2][1]-'0')*10 + s[2][2]-'0';
                     
                     if (s[3][0]=='r' || s[3][0]=='R')
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) ||(s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<51))
                    { int R1 ;if(strlen(s[3])==2) R1 = (int)s[3][1]-'0';
                        if(strlen(s[3])==3) R1=(s[3][1]-'0')*10 + s[3][2]-'0';

                    if (s[4][0]=='r' || s[4][0]=='R')//for register as second oprand
                 {    if((s[4][1]>=48 && s[4][1]<58 && strlen(s[4])==2) || (s[4][1]==49 && strlen(s[4])==3 && s[4][2]>=48 && s[4][2]<51))
                    { int R2 ;if(strlen(s[4])==2) R2= (int)s[4][1]-'0';
                       if(strlen(s[4])==3) R2=(s[4][1]-'0')*10 + s[4][2]-'0';

                     //printf("%d %d %d %x here\n",Rd,R1,R2,(14<<28)|(4<<21)|(R1<<16)|(Rd<<12)|(R2) );
                     write_word(MEM, address, (14<<28)|(4<<21)|(R1<<16)|(Rd<<12)|(R2));
                     address+=4;
                    // instruction here
                    }else{error_count++;
                  printf(" register R2 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[4][0]=='#'){  len=strlen(s[4]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[4][il+1]>57 || s[4][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[4][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                    write_word(MEM, address, (14<<28)|(1<<25)|(4<<21)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("operand 2 is not valid in line: %d\n",line_count );
                 } 
                     


                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }

      }else if(!strcmp(s[1],"sub") || !strcmp(s[1],"SUB"))
      {if(s[2]==NULL || s[3]==NULL || s[4] == NULL)
         {error_count++;
          printf("SUB instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[5]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51 ))
                     {int Rd; if(strlen(s[2])==2) Rd = (int)s[2][1]-'0';
                      if(strlen(s[2])==3) Rd=(s[2][1]-'0')*10 + s[2][2]-'0';
                     
                     if (s[3][0]=='r' || s[3][0]=='R')
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) ||(s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<51))
                    { int R1 ;if(strlen(s[3])==2) R1 = (int)s[3][1]-'0';
                        if(strlen(s[3])==3) R1=(s[3][1]-'0')*10 + s[3][2]-'0';

                    if (s[4][0]=='r' || s[4][0]=='R')//for register as second oprand
                 {    if((s[4][1]>=48 && s[4][1]<58 && strlen(s[4])==2) || (s[4][1]==49 && strlen(s[4])==3 && s[4][2]>=48 && s[4][2]<51))
                    { int R2 ;if(strlen(s[4])==2) R2= (int)s[4][1]-'0';
                       if(strlen(s[4])==3) R2=(s[4][1]-'0')*10 + s[4][2]-'0';

                     //printf("%d %d %d\n",Rd,R1,R2 );
                    write_word(MEM, address, (14<<28)|(2<<21)|(R1<<16)|(Rd<<12)|(R2));
                     address+=4;

                    // instruction here
                    }else{error_count++;
                  printf(" register R2 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[4][0]=='#'){  len=strlen(s[4]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[4][il+1]>57 || s[4][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[4][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                   write_word(MEM, address, (14<<28)|(1<<25)|(2<<21)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("operand 2 is not valid in line: %d\n",line_count );
                 } 
                     


                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }

      }else if(!strcmp(s[1],"LDR") || !strcmp(s[1],"ldr"))
      {  if(s[2]==NULL)
        {error_count++;
          printf("LDR instruction in line:%d is not complete\n",line_count );
        }else{  if(s[3]!=NULL && s[3][0]=='[')
                { 
                  if ( s[5]!=NULL)
                  {error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else  if ((s[3][1]=='r' || s[3][1]=='R'))
                       {   if((s[3][2]>=48 && s[3][2]<58 && strlen(s[3])==3) ||((s[3][2]>=48 && s[3][2]<58 && strlen(s[3])==4 && s[3][3]==']'))||(s[3][2]==49 && strlen(s[3])==4 && s[3][3]>=48 && s[3][3]<52)||(s[3][2]==49 && strlen(s[3])==5 && s[3][3]>=48 && s[3][3]<52 && s[3][4]==']'))
                      { int R1 ;if(strlen(s[3])==3 || (strlen(s[3])==4 && s[3][3]==']')) R1 = (int)s[3][2]-'0';
                            if(strlen(s[3])==5 || (strlen(s[3])==4 && s[3][3]!=']')) R1=(s[3][2]-'0')*10 + s[3][3]-'0';
                         
                    if ((s[2][0]=='r' || s[2][0]=='R') )
                    {   if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51))
                      { int Rd ;if(strlen(s[2])==2) Rd = (int)s[2][1]-'0';
                            if(strlen(s[2])==3) Rd=(s[2][1]-'0')*10 + s[2][2]-'0';
                       
                       if (s[4]!=NULL && s[4][0]=='#' && s[4][strlen(s[4])-1]==']')
                       { len=strlen(s[4]);

                if(len<=5 && len>=3){int imm=0; for(int il=0;il<len-2;il++){
                    if(s[4][il+1]>57 || s[4][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-2;il++)
                      imm=(s[4][il+1]-'0')+10*imm;
                  }
                  if(imm>3999) printf("Error in line:%d is =>Immediate cann't be greater than 3999\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                    write_word(MEM, address, (14<<28)|(1<<26)|(25<<20)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;

                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 }else{ 
                         if (s[4]==NULL)
                         {
                          write_word(MEM, address, (14<<28)|(1<<26)|(25<<20)|(R1<<16)|(Rd<<12));
                           address+=4;
                           //instruction code here
                         }else{
                          error_count++;
                         printf("Error: ldr instruction is not right in line:%d\n",line_count);
                         }
                       }
                         
                          
                      }else{error_count++;
                        printf("In ldr instruction destination register is not valid in line:%d\n",line_count );
                      } 
                      
                      }else{error_count++;
                        printf("In ldr instruction destination register is not valid in line:%d\n",line_count );
                      }   


                      }else{error_count++;
                        printf("register R1 is not valid.Error in line:%d\n",line_count);
                      }
                                       
                    }else{error_count++;
                     printf("register R1 is not valid Error in line_count:%d\n",line_count);
                    }                   

                 }else if (s[3]!=NULL && s[3][0]=='='){
                  if ( s[4]!=NULL)
                  {error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );}
                  else{ 

                  if ((s[2][0]=='r' || s[2][0]=='R') )
                    {   if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51))
                      { int Rd ;if(strlen(s[2])==2) Rd = (int)s[2][1]-'0';
                        
                        if(strlen(s[2])==3) Rd=(s[2][1]-'0')*10 + s[2][2]-'0';
                        

                  if (s[3][1]=='#')
                {

               len=strlen(s[3]);

                if(len<=5 && len>=3){int imm=0; for(int il=1;il<len-1;il++){
                    if(s[3][il+1]>57 || s[3][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=1;il<len-1;il++)
                      imm=(s[3][il+1]-'0')+10*imm;
                  }
                  if(imm>3999) printf("Error in line:%d is =>Immediate cann't be greater than 3999\n",line_count );
                  else {//printf("%d %d\n",Rd,imm );
                    write_word(MEM, address, (14<<28)|(1<<26)|(25<<20)|(14<<16)|(Rd<<12)|(imm));
                     address+=4;             
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 }else{  if ((s[3][1]<='Z' && s[3][1]>='A') || (s[3][1]<='z' && s[3][1]>='a'))
                 {  int nott=0;
                   
                  for (int i = 2; i < strlen(s[3]); ++i)
                 {
                   if(!((s[3][i]>='0' && s[3][i]<='9') || (s[3][i]<='Z' && s[3][i]>='A') || (s[3][i]<='z' && s[3][i]>='a')) )
                     nott=1;                       
                 }
                  if (nott==1)
                  {error_count++;
                   printf("label not valid Error in line:%d\n",line_count);
                  }else{
                    //instruction here
                    write_word(MEM,address, (14<<28)|(1<<26)|(25<<20)|(15<<16)|(Rd<<12));
                    address+=4;
                  }

                  }else{ error_count++;
                         printf("Error: ldr instruction is not right in line:%d\n",line_count);
                        }
                            }
                       
                         
                          
                      }else{error_count++;
                        printf("In ldr instruction destination register is not valid in line:%d\n",line_count );
                      } 
                      
                      }else{error_count++;
                        printf("In ldr instruction destination register is not valid in line:%d\n",line_count );
                      } 


                  }

                 }else{error_count++;
                   printf("LDR instruction doesn't match any format\n");
                 }
                  
        }
           
      }else if(!strcmp(s[1],"str") || !strcmp(s[1],"STR"))
      {  
      

       if(s[2]==NULL)
        {error_count++;
          printf("Str instruction in line:%d is not complete\n",line_count );
        }else{  if(s[3]!=NULL && s[3][0]=='[')
                { 
                  if ( s[5]!=NULL)
                  {error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else  if ((s[3][1]=='r' || s[3][1]=='R') )
                    {   if((s[3][2]>=48 && s[3][2]<58 && strlen(s[3])==3) ||((s[3][2]>=48 && s[3][2]<58 && strlen(s[3])==4 && s[3][3]==']'))||(s[3][2]==49 && strlen(s[3])==4 && s[3][3]>=48 && s[3][3]<52)||(s[3][2]==49 && strlen(s[3])==5 && s[3][3]>=48 && s[3][3]<52 && s[3][4]==']'))
                      { int R1 ;if(strlen(s[3])==3 || (strlen(s[3])==4 && s[3][3]==']') ) R1 = (int)s[3][2]-'0';
                            if(strlen(s[3])==4 || (strlen(s[3])==4 && s[3][3]!=']')) R1=(s[3][2]-'0')*10 + s[3][3]-'0';
                         
                    if ((s[2][0]=='r' || s[2][0]=='R') )
                    {   if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<54))
                      { int Rd ;if(strlen(s[2])==2) Rd = (int)s[2][1]-'0';
                            if(strlen(s[2])==3) Rd=(s[2][1]-'0')*10 + s[2][2]-'0';
                       
                       if (s[4]!=NULL && s[4][0]=='#' && s[4][strlen(s[4])-1]==']')
                       { 
                         




               len=strlen(s[4]);

                if(len<=5 && len>=3){int imm=0; for(int il=0;il<len-2;il++){
                    if(s[4][il+1]>57 || s[4][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-2;il++)
                      imm=(s[4][il+1]-'0')+10*imm;
                  }
                  if(imm>3999) printf("Error in line:%d is =>Immediate cann't be greater than 3999\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                   write_word(MEM, address, (14<<28)|(1<<26)|(24<<20)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 }else{ 
                         if (s[4]==NULL)
                         {
                           write_word(MEM, address, (14<<28)|(1<<26)|(24<<20)|(R1<<16)|(Rd<<12));
                           address+=4;
                            //put instruction code here                          
                         }else{
                         error_count++;
                         printf("Error: str instruction is not right in line:%d\n",line_count);
                           }
                      }
                         
                          
                      }else{error_count++;
                        printf("In str instruction destination register is not valid in line:%d\n",line_count );
                      } 
                      
                      }else{error_count++;
                        printf("In str instruction destination register is not valid in line:%d\n",line_count );
                      }   


                      }else{error_count++;
                        printf("register R1 is not valid.Error in line:%d\n",line_count);
                      }
                                       
                    }else{error_count++;
                     printf("register R1 is not valid Error in line_count:%d\n",line_count);
                    }                   

                 }else if (s[3]!=NULL && s[3][0]=='='){
                  if ( s[4]!=NULL)
                  {error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );}
                  else{ 

                  if ((s[2][0]=='r' || s[2][0]=='R') )
                    {   if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<54))
                      { int Rd ;if(strlen(s[2])==2) Rd = (int)s[2][1]-'0';
                        
                        if(strlen(s[2])==3) Rd=(s[2][1]-'0')*10 + s[2][2]-'0';
                        

                  if (s[3][1]=='#')
                {

               len=strlen(s[3]);

                if(len<=5 && len>=3){int imm=0; for(int il=1;il<len-1;il++){
                    if(s[3][il+1]>57 || s[3][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=1;il<len-1;il++)
                      imm=(s[3][il+1]-'0')+10*imm;
                  }
                  if(imm>3999) printf("Error in line:%d is =>Immediate cann't be greater than 3999\n",line_count );
                  else {//printf("%d %d\n",Rd,imm );
                    write_word(MEM, address, (14<<28)|(1<<26)|(24<<20)|(14<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 }else{ error_count++;
                         printf("Error: str instruction is not right in line:%d\n",line_count);
                       }
                       
                         
                          
                      }else{error_count++;
                        printf("In str instruction destination register is not valid in line:%d\n",line_count );
                      } 
                      
                      }else{error_count++;
                        printf("In str instruction destination register is not valid in line:%d\n",line_count );
                      } 


                  }

                 }else{error_count++;
                   printf("str instruction doesn't match any format\n");
                 }
                  
        }



    }else if(!strcmp(s[1],"MUL") || !strcmp(s[1],"mul"))//change add with carry
      {if(s[2]==NULL || s[3]==NULL || s[4] == NULL)
         {error_count++;
          printf("MUL instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[5]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51 ))
                    {int Rd; if(strlen(s[2])==2) Rd = (int)s[2][1]-'0';
                      if(strlen(s[2])==3) Rd=(s[2][1]-'0')*10 + s[2][2]-'0';
                     
                     if (s[3][0]=='r' || s[3][0]=='R')
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) ||(s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<51))
                    { int R1 ;if(strlen(s[3])==2) R1 = (int)s[3][1]-'0';
                        if(strlen(s[3])==3) R1=(s[3][1]-'0')*10 + s[3][2]-'0';

                    if (s[4][0]=='r' || s[4][0]=='R')//for register as second oprand
                 {    if((s[4][1]>=48 && s[4][1]<58 && strlen(s[4])==2) || (s[4][1]==49 && strlen(s[4])==3 && s[4][2]>=48 && s[4][2]<51))
                    { int R2 ;if(strlen(s[4])==2) R2= (int)s[4][1]-'0';
                       if(strlen(s[4])==3) R2=(s[4][1]-'0')*10 + s[4][2]-'0';

                     //printf("%d %d %d\n",Rd,R1,R2 );
                    write_word(MEM, address, (14<<28)|(5<<21)|(R1<<16)|(Rd<<12)|(R2));
                     address+=4;
                    // instruction here
                    }else{error_count++;
                  printf(" register R2 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[4][0]=='#'){  len=strlen(s[4]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[4][il+1]>57 || s[4][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[4][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                    write_word(MEM, address, (14<<28)|(1<<25)|(5<<21)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("operand 2 is not valid in line: %d\n",line_count );
                 } 
                     


                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }
        
      }else if(!strcmp(s[1],"and") || !strcmp(s[1],"AND"))
      {if(s[2]==NULL || s[3]==NULL || s[4] == NULL)
         {error_count++;
          printf("AND instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[5]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51 ))
                    {int Rd; if(strlen(s[2])==2) Rd = (int)s[2][1]-'0';
                      if(strlen(s[2])==3) Rd=(s[2][1]-'0')*10 + s[2][2]-'0';
                     
                     if (s[3][0]=='r' || s[3][0]=='R')
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) ||(s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<51))
                    { int R1 ;if(strlen(s[3])==2) R1 = (int)s[3][1]-'0';
                        if(strlen(s[3])==3) R1=(s[3][1]-'0')*10 + s[3][2]-'0';

                    if (s[4][0]=='r' || s[4][0]=='R')//for register as second oprand
                 {    if((s[4][1]>=48 && s[4][1]<58 && strlen(s[4])==2) || (s[4][1]==49 && strlen(s[4])==3 && s[4][2]>=48 && s[4][2]<51))
                    { int R2 ;if(strlen(s[4])==2) R2= (int)s[4][1]-'0';
                       if(strlen(s[4])==3) R2=(s[4][1]-'0')*10 + s[4][2]-'0';

                     //printf("%d %d %d\n",Rd,R1,R2 );
                     write_word(MEM, address, (14<<28)|(R1<<16)|(Rd<<12)|(R2));
                     address+=4;
                    // instruction here
                    }else{error_count++;
                  printf(" register R2 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[4][0]=='#'){  len=strlen(s[4]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[4][il+1]>57 || s[4][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[4][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                     write_word(MEM, address, (14<<28)|(1<<25)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("operand 2 is not valid in line: %d\n",line_count );
                 } 
                     


                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }
        
      }else if(!strcmp(s[1],"OR") || !strcmp(s[1],"or"))
      {if(s[2]==NULL || s[3]==NULL || s[4] == NULL)
         {error_count++;
          printf("OR instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[5]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51 ))
                    {int Rd; if(strlen(s[2])==2) Rd = (int)s[2][1]-'0';
                      if(strlen(s[2])==3) Rd=(s[2][1]-'0')*10 + s[2][2]-'0';
                     
                     if (s[3][0]=='r' || s[3][0]=='R')
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) ||(s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<51))
                    { int R1 ;if(strlen(s[3])==2) R1 = (int)s[3][1]-'0';
                        if(strlen(s[3])==3) R1=(s[3][1]-'0')*10 + s[3][2]-'0';

                    if (s[4][0]=='r' || s[4][0]=='R')//for register as second oprand
                 {    if((s[4][1]>=48 && s[4][1]<58 && strlen(s[4])==2) || (s[4][1]==49 && strlen(s[4])==3 && s[4][2]>=48 && s[4][2]<51))
                    { int R2 ;if(strlen(s[4])==2) R2= (int)s[4][1]-'0';
                       if(strlen(s[4])==3) R2=(s[4][1]-'0')*10 + s[4][2]-'0';

                     //printf("%d %d %d\n",Rd,R1,R2 );
                     write_word(MEM, address, (14<<28)|(12<<21)|(R1<<16)|(Rd<<12)|(R2));
                     address+=4;
                    // instruction here
                    }else{error_count++;
                  printf(" register R2 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[4][0]=='#'){  len=strlen(s[4]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[4][il+1]>57 || s[4][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[4][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                  write_word(MEM, address, (14<<28)|(1<<25)|(12<<21)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("operand 2 is not valid in line: %d\n",line_count );
                 } 
                     


                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }
        
      }else if(!strcmp(s[1],"cmp") || !strcmp(s[1],"CMP"))
      {if(s[2]==NULL || s[3]==NULL)
         {error_count++;
          printf("CMP instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[4]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<54 ))
                    {int Rd; if(strlen(s[2])==2) Rd = (int)s[2][1]-'0';
                      if(strlen(s[2])==3) Rd=(s[2][1]-'0')*10 + s[2][2]-'0';
                     
                     if (s[3][0]=='r' || s[3][0]=='R')
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) ||(s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<54))
                    { int R1 ;if(strlen(s[3])==2) R1 = (int)s[3][1]-'0';
                        if(strlen(s[3])==3) R1=(s[3][1]-'0')*10 + s[3][2]-'0';
                      
                      write_word(MEM, address, (14<<28)|(10<<21)|(Rd<<16)|(R1));
                       address+=4;
                     
                    //instruction goes here

                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[3][0]=='#'){  len=strlen(s[3]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[3][il+1]>57 || s[3][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[3][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d\n",Rd,imm );
                   write_word(MEM, address, (14<<28)|(1<<25)|(10<<21)|(Rd<<16)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("in CMP instruction register/Immediate is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                 } 

         }
        
      }else if(!strcmp(s[1],"mov") || !strcmp(s[1],"MOV"))
      {if(s[2]==NULL || s[3]==NULL)
         {error_count++;
          printf("MOV instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[4]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51 ))
                    {int Rd; if(strlen(s[2])==2) Rd = (int)s[2][1]-'0';
                      if(strlen(s[2])==3) Rd=(s[2][1]-'0')*10 + s[2][2]-'0';
                     
                     if (s[3][0]=='r' || s[3][0]=='R')
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) ||(s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<54))
                    { int R1 ;if(strlen(s[3])==2) R1 = (int)s[3][1]-'0';
                        if(strlen(s[3])==3) R1=(s[3][1]-'0')*10 + s[3][2]-'0';
                    
                     write_word(MEM, address, (14<<28)|(13<<21)|(Rd<<12)|(R1));
                     address+=4;
                     
                    //instruction goes here

                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[3][0]=='#'){  len=strlen(s[3]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[3][il+1]>57 || s[3][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[3][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d\n",Rd,imm );
                   write_word(MEM, address, (14<<28)|(1<<25)|(13<<21)|(Rd<<12)|(imm));
                     address+=4;   
                 
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("in CMP instruction register/Immediate is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }
        
      }else if(!strcmp(s[1],"MNV") || !strcmp(s[1],"mnv"))
      {if(s[2]==NULL || s[3]==NULL)
         {error_count++;
          printf("MNV instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[4]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51 ))
                    {int Rd; if(strlen(s[2])==2) Rd = (int)s[2][1]-'0';
                      if(strlen(s[2])==3) Rd=(s[2][1]-'0')*10 + s[2][2]-'0';
                     
                     if (s[3][0]=='r' || s[3][0]=='R')
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) ||(s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<54))
                    { int R1 ;if(strlen(s[3])==2) R1 = (int)s[3][1]-'0';
                        if(strlen(s[3])==3) R1=(s[3][1]-'0')*10 + s[3][2]-'0';
                     
                    write_word(MEM, address, (14<<28)|(15<<21)|(Rd<<12)|(R1));
                     address+=4;
                    //instruction goes here

                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[3][0]=='#'){  len=strlen(s[3]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[3][il+1]>57 || s[3][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[3][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d\n",Rd,imm );
                  write_word(MEM, address, (14<<28)|(1<<25)|(15<<21)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("in CMP instruction register/Immediate is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }
        
      }else if(!strcmp(s[1],"b") || !strcmp(s[1],"B"))
      { if(s[2]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[3]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[2],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
            write_word(MEM, address, (14<<28)|(2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;

          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[2],line_count );
         }
        }
        
        }
        
      }else if(!strcmp(s[1],"bge") || !strcmp(s[1],"BGE"))
      {if(s[2]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[3]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[2],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         {// printf("%d\n",lblno );
            write_word(MEM, address, (10<<28)|(2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[2],line_count );
         }
        }
        
        }
        
      }else if(!strcmp(s[1],"BL") || !strcmp(s[1],"bl"))
      {if(s[2]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[3]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[2],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
            write_word(MEM, address, (11<<28)|(2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;
           //blt is bl
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[2],line_count );
         }
        }
        
        }
        
      }else if(!strcmp(s[1],"bgt") || !strcmp(s[1],"BGT"))
      {if(s[2]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[3]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[2],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
            write_word(MEM, address, (12<<28)|(2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;          
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[2],line_count );
         }
        }
        
        }
        
      }else if(!strcmp(s[1],"BLE") || !strcmp(s[1],"ble"))
      {if(s[2]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[3]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[2],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
           write_word(MEM, address, (13<<28)|(2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[2],line_count );
         }
        }
        
        }
        
      }else if(!strcmp(s[1],"BNE") || !strcmp(s[1],"bne"))
      {if(s[2]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[3]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[2],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
            write_word(MEM, address, (1<<28)|(2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;         
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[2],line_count );
         }
        }
        
        }
        
      }else if(!strcmp(s[1],"BEQ") || !strcmp(s[1],"beq"))
      {if(s[2]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[3]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[2],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
            write_word(MEM, address, (2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;          
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[2],line_count );
         }
        }
        
        }
        
      }else
      { error_count++;
        printf("Error:unable to identify instruction in line no:%d\n",line_count);
      }


    }else if(!strcmp(s[0],"swi") || !strcmp(s[0],"SWI"))
       {if (s[2]!=NULL)
       { error_count++;
         printf("Error: ideally there should be no instruction after swi_exit command. line:%d\n",line_count);
       }else if(s[1]==NULL)
       {
        error_count++;
        printf("Error: swi command not complete in line:%d\n",line_count);
       }else{ if (!strcmp(s[1],"swi_exit") || !strcmp(s[1],"SWI_EXIT") || !strcmp(s[1],"SWI_Exit"))
               {  
                write_word(MEM, address, 0xEF000011);
                address+=4;

               //instruction
               }else{error_count++;
                  printf("Error:right now only swi_exit command can be execute so put swi swi_exit in line:%d\n",line_count );
               }
               


       }

       }else if(!strcmp(s[0],"add") || !strcmp(s[0],"ADD"))
      {  if(s[1]==NULL || s[2]==NULL || s[3] == NULL)
         {error_count++;
          printf("ADD instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[4]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[1][0]=='r' || s[1][0]=='R')
                 {    if((s[1][1]>=48 && s[1][1]<58 && strlen(s[1])==2) ||(s[1][1]==49 && strlen(s[1])==3 && s[1][2]>=48 && s[1][2]<51 ))
                    {int Rd; if(strlen(s[1])==2) Rd = (int)s[1][1]-'0';
                      if(strlen(s[1])==3) Rd=(s[1][1]-'0')*10 + s[1][2]-'0';
                     
                     if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51))
                    { int R1 ;if(strlen(s[2])==2) R1 = (int)s[2][1]-'0';
                        if(strlen(s[2])==3) R1=(s[2][1]-'0')*10 + s[2][2]-'0';

                    if (s[3][0]=='r' || s[3][0]=='R')//for register as second oprand
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) || (s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<51))
                    { int R2 ;if(strlen(s[3])==2) R2= (int)s[3][1]-'0';
                       if(strlen(s[3])==3) R2=(s[3][1]-'0')*10 + s[3][2]-'0';

                     //printf("%d %d %d\n",Rd,R1,R2 );
                    write_word(MEM, address, (14<<28)|(4<<21)|(R1<<16)|(Rd<<12)|(R2));
                     address+=4;
                    // instruction here
                    }else{error_count++;
                  printf(" register R2 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[3][0]=='#'){  len=strlen(s[3]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[3][il+1]>57 || s[3][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[3][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                    write_word(MEM, address, (14<<28)|(1<<25)|(4<<21)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("operand 2 is not valid in line: %d\n",line_count );
                 } 
                     


                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }

      }else if(!strcmp(s[0],"sub") || !strcmp(s[0],"SUB"))
      {if(s[1]==NULL || s[2]==NULL || s[3] == NULL)
         {error_count++;
          printf("SUB instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[4]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[1][0]=='r' || s[1][0]=='R')
                 {    if((s[1][1]>=48 && s[1][1]<58 && strlen(s[1])==2) ||(s[1][1]==49 && strlen(s[1])==3 && s[1][2]>=48 && s[1][2]<51 ))
                     {int Rd; if(strlen(s[1])==2) Rd = (int)s[1][1]-'0';
                      if(strlen(s[1])==3) Rd=(s[1][1]-'0')*10 + s[1][2]-'0';
                     
                     if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51))
                    { int R1 ;if(strlen(s[2])==2) R1 = (int)s[2][1]-'0';
                        if(strlen(s[2])==3) R1=(s[2][1]-'0')*10 + s[2][2]-'0';

                    if (s[3][0]=='r' || s[3][0]=='R')//for register as second oprand
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) || (s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<51))
                    { int R2 ;if(strlen(s[3])==2) R2= (int)s[3][1]-'0';
                       if(strlen(s[3])==3) R2=(s[3][1]-'0')*10 + s[3][2]-'0';

                     //printf("%d %d %d\n",Rd,R1,R2 );
                    write_word(MEM, address, (14<<28)|(2<<21)|(R1<<16)|(Rd<<12)|(R2));
                     address+=4;
                    // instruction here
                    }else{error_count++;
                  printf(" register R2 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[3][0]=='#'){  len=strlen(s[3]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[3][il+1]>57 || s[3][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[3][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                    write_word(MEM, address, (14<<28)|(1<<25)|(2<<21)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("operand 2 is not valid in line: %d\n",line_count );
                 } 
                     


                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }

      }else if(!strcmp(s[0],"LDR") || !strcmp(s[0],"ldr"))
      {  if(s[1]==NULL)
        {error_count++;
          printf("LDR instruction in line:%d is not complete\n",line_count );
        }else{  if(s[2]!=NULL  && s[2][0]=='[')
                { 
                  if ( s[4]!=NULL)
                  {error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else  if ((s[2][1]=='r' || s[2][1]=='R') )
                    {   if((s[2][2]>=48 && s[2][2]<58 && strlen(s[2])==3)|| (s[2][2]>=48 && s[2][2]<58 && strlen(s[2])==4 && s[2][3]==']') ||(s[2][2]==49 && strlen(s[2])==4 && s[2][3]>=48 && s[2][3]<52)||(s[2][2]==49 && strlen(s[2])==5 && s[2][3]>=48 && s[2][3]<52 && s[2][4]==']'))
                      { int R1 ;if(strlen(s[2])==3 ||(strlen(s[2])==4 && s[2][3]==']')) R1 = (int)s[2][2]-'0';
                            if(strlen(s[2])==5 ||(strlen(s[2])==4 && s[2][3]!=']')) R1=(s[2][2]-'0')*10 + s[2][3]-'0';
                         
                    if ((s[1][0]=='r' || s[1][0]=='R') )
                    {   if((s[1][1]>=48 && s[1][1]<58 && strlen(s[1])==2) ||(s[1][1]==49 && strlen(s[1])==3 && s[1][2]>=48 && s[1][2]<51))
                      { int Rd ;if(strlen(s[1])==2) Rd = (int)s[1][1]-'0';
                            if(strlen(s[1])==3) Rd=(s[1][1]-'0')*10 + s[1][2]-'0';
                       
                       if (s[3]!=NULL && s[3][0]=='#' && s[3][strlen(s[3])-1]==']')
                       { 
                         




               len=strlen(s[3]);

                if(len<=5 && len>=3){int imm=0; for(int il=0;il<len-2;il++){
                    if(s[3][il+1]>57 || s[3][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-2;il++)
                      imm=(s[3][il+1]-'0')+10*imm;
                  }
                  if(imm>3999) printf("Error in line:%d is =>Immediate cann't be greater than 3999\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                    write_word(MEM, address, (14<<28)|(1<<26)|(25<<20)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 






                       }else{ 

                          if (s[3]==NULL)
                          {write_word(MEM, address, (14<<28)|(1<<26)|(25<<20)|(R1<<16)|(Rd<<12));
                           address+=4;
                            //put instruction code here
                            
                          }else{
                        error_count++;
                         printf("Error: ldr instruction is not right in line:%d\n",line_count);
                       }}
                         
                          
                      }else{error_count++;
                        printf("In ldr instruction destination register is not valid in line:%d\n",line_count );
                      } 
                      
                      }else{error_count++;
                        printf("In ldr instruction destination register is not valid in line:%d\n",line_count );
                      }   


                      }else{error_count++;
                        printf("register R1 is not valid.Error in line:%d\n",line_count);
                      }
                                       
                    }else{error_count++;
                     printf("register R1 is not valid Error in line_count:%d\n",line_count);
                    }                   

                 }else if (s[2]!=NULL && s[2][0]=='='){
                  if ( s[3]!=NULL)
                  {error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );}
                  else{ 

                  if ((s[1][0]=='r' || s[1][0]=='R') )
                    {   if((s[1][1]>=48 && s[1][1]<58 && strlen(s[1])==2) ||(s[1][1]==49 && strlen(s[1])==3 && s[1][2]>=48 && s[1][2]<51))
                      { int Rd ;if(strlen(s[1])==2) Rd = (int)s[1][1]-'0';
                        
                        if(strlen(s[1])==3) Rd=(s[1][1]-'0')*10 + s[1][2]-'0';
                        

                  if (s[2][1]=='#')
                {

               len=strlen(s[2]);

                if(len<=5 && len>=3){int imm=0; for(int il=1;il<len-1;il++){
                    if(s[2][il+1]>57 || s[2][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=1;il<len-1;il++)
                      imm=(s[2][il+1]-'0')+10*imm;
                  }
                  if(imm>3999) printf("Error in line:%d is =>Immediate cann't be greater than 3999\n",line_count );
                  else {//printf("%d %d\n",Rd,imm );
                   write_word(MEM, address, (14<<28)|(1<<26)|(25<<20)|(14<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 }else{  if ((s[2][1]<='Z' && s[2][1]>='A') || (s[2][1]<='z' && s[2][1]>='a'))
                 {  int nott=0;
                   
                  for (int i = 2; i < strlen(s[2]); ++i)
                 {
                   if(!((s[2][i]>='0' && s[2][i]<='9') || (s[2][i]<='Z' && s[2][i]>='A') || (s[2][i]<='z' && s[2][i]>='a')) )
                     nott=1;                       
                 }
                  if (nott==1)
                  {error_count++;
                   printf("label not valid Error in line:%d\n",line_count);
                  }else{
                    //instruction here
                    write_word(MEM,address, (14<<28)|(1<<26)|(25<<20)|(15<<16)|(Rd<<12)|(0));
                    address+=4;
                  }

                  }else{ error_count++;
                         printf("Error: ldr instruction is not right in line:%d\n",line_count);
                        }
                        
                       }
                       
                         
                          
                      }else{error_count++;
                        printf("In ldr instruction destination register is not valid in line:%d\n",line_count );
                      } 
                      
                      }else{error_count++;
                        printf("In ldr instruction destination register is not valid in line:%d\n",line_count );
                      } 


                  }

                 }else{error_count++;
                   printf("LDR instruction doesn't match any format\n");
                 }
                  
        }
           
      }else if(!strcmp(s[0],"str") || !strcmp(s[0],"STR"))
      {  
      

       if(s[1]==NULL)
        {error_count++;
          printf("Str instruction in line:%d is not complete\n",line_count );
        }else{  if(s[2]!=NULL && s[2][0]=='[')
                { 
                  if ( s[4]!=NULL)
                  {error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else  if ((s[2][1]=='r' || s[2][1]=='R') )
                    {   if((s[2][2]>=48 && s[2][2]<58 && strlen(s[2])==3)|| (s[2][2]>=48 && s[2][2]<58 && strlen(s[2])==4 && s[2][3]==']') ||(s[2][2]==49 && strlen(s[2])==4 && s[2][3]>=48 && s[2][3]<52)||(s[2][2]==49 && strlen(s[2])==5 && s[2][3]>=48 && s[2][3]<52 && s[2][4]==']'))
                      { int R1 ;if(strlen(s[2])==3 ||(strlen(s[2])==4 && s[2][3]==']')) R1 = (int)s[2][2]-'0';
                            if(strlen(s[2])==5 ||(strlen(s[2])==4 && s[2][3]!=']')) R1=(s[2][2]-'0')*10 + s[2][3]-'0';
                         
                    if ((s[1][0]=='r' || s[1][0]=='R') )
                    {   if((s[1][1]>=48 && s[1][1]<58 && strlen(s[1])==2) ||(s[1][1]==49 && strlen(s[1])==3 && s[1][2]>=48 && s[1][2]<54))
                      { int Rd ;if(strlen(s[1])==2) Rd = (int)s[1][1]-'0';
                            if(strlen(s[1])==3) Rd=(s[1][1]-'0')*10 + s[1][2]-'0';
                       
                       if (s[3]!=NULL && s[3][0]=='#' && s[3][strlen(s[3])-1]==']')
                       { 
                         




               len=strlen(s[3]);

                if(len<=5 && len>=3){int imm=0; for(int il=0;il<len-2;il++){
                    if(s[3][il+1]>57 || s[3][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-2;il++)
                      imm=(s[3][il+1]-'0')+10*imm;
                  }
                  if(imm>3999) printf("Error in line:%d is =>Immediate cann't be greater than 3999\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                   write_word(MEM, address, (14<<28)|(1<<26)|(24<<20)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                  }else{ 

                          if (s[3]==NULL)
                          {write_word(MEM, address, (14<<28)|(1<<26)|(24<<20)|(R1<<16)|(Rd<<12));
                           address+=4;
                            //put instruction code here
                            
                          }else{
                        error_count++;
                         printf("Error: ldr instruction is not right in line:%d\n",line_count);
                       }}
                         
                          
                      }else{error_count++;
                        printf("In str instruction destination register is not valid in line:%d\n",line_count );
                      } 
                      
                      }else{error_count++;
                        printf("In str instruction destination register is not valid in line:%d\n",line_count );
                      }   


                      }else{error_count++;
                        printf("register R1 is not valid.Error in line:%d\n",line_count);
                      }
                                       
                    }else{error_count++;
                     printf("register R1 is not valid Error in line_count:%d\n",line_count);
                    }                   

                 }else if (s[2]!=NULL && s[2][0]=='='){
                  if ( s[3]!=NULL)
                  {error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );}
                  else{ 

                  if ((s[1][0]=='r' || s[1][0]=='R') )
                    {   if((s[1][1]>=48 && s[1][1]<58 && strlen(s[1])==2) ||(s[1][1]==49 && strlen(s[1])==3 && s[1][2]>=48 && s[1][2]<54))
                      { int Rd ;if(strlen(s[1])==2) Rd = (int)s[1][1]-'0';
                        
                        if(strlen(s[1])==3) Rd=(s[1][1]-'0')*10 + s[1][2]-'0';
                        

                  if (s[2][1]=='#')
                {

               len=strlen(s[2]);

                if(len<=5 && len>=3){int imm=0; for(int il=1;il<len-1;il++){
                    if(s[2][il+1]>57 || s[2][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=1;il<len-1;il++)
                      imm=(s[2][il+1]-'0')+10*imm;
                  }
                  if(imm>3999) printf("Error in line:%d is =>Immediate cann't be greater than 3999\n",line_count );
                  else {//printf("%d %d\n",Rd,imm );
                   write_word(MEM, address, (14<<28)|(1<<26)|(24<<20)|(13<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 }else{ error_count++;
                         printf("Error: str instruction is not right in line:%d\n",line_count);
                       }
                       
                         
                          
                      }else{error_count++;
                        printf("In str instruction destination register is not valid in line:%d\n",line_count );
                      } 
                      
                      }else{error_count++;
                        printf("In str instruction destination register is not valid in line:%d\n",line_count );
                      } 


                  }

                 }else{error_count++;
                   printf("str instruction doesn't match any format\n");
                 }
                  
        }



    }else if(!strcmp(s[0],"MUL") || !strcmp(s[0],"mul"))//change add with carry
      {if(s[1]==NULL || s[2]==NULL || s[3] == NULL)
         {error_count++;
          printf("MUL instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[4]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[1][0]=='r' || s[1][0]=='R')
                 {    if((s[1][1]>=48 && s[1][1]<58 && strlen(s[1])==2) ||(s[1][1]==49 && strlen(s[1])==3 && s[1][2]>=48 && s[1][2]<51 ))
                    {int Rd; if(strlen(s[1])==2) Rd = (int)s[1][1]-'0';
                      if(strlen(s[1])==3) Rd=(s[1][1]-'0')*10 + s[1][2]-'0';
                     
                     if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51))
                    { int R1 ;if(strlen(s[2])==2) R1 = (int)s[2][1]-'0';
                        if(strlen(s[2])==3) R1=(s[2][1]-'0')*10 + s[2][2]-'0';

                    if (s[3][0]=='r' || s[3][0]=='R')//for register as second oprand
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) || (s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<51))
                    { int R2 ;if(strlen(s[3])==2) R2= (int)s[3][1]-'0';
                       if(strlen(s[3])==3) R2=(s[3][1]-'0')*10 + s[3][2]-'0';

                     //printf("%d %d %d\n",Rd,R1,R2 );
                    write_word(MEM, address, (14<<28)|(5<<21)|(R1<<16)|(Rd<<12)|(R2));
                     address+=4;
                    // instruction here
                    }else{error_count++;
                  printf(" register R2 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[3][0]=='#'){  len=strlen(s[3]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[3][il+1]>57 || s[3][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[3][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                    write_word(MEM, address, (14<<28)|(1<<25)|(5<<21)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("operand 2 is not valid in line: %d\n",line_count );
                 } 
                     


                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }
        
      }else if(!strcmp(s[0],"and") || !strcmp(s[0],"AND"))
      {if(s[1]==NULL || s[2]==NULL || s[3] == NULL)
         {error_count++;
          printf("AND instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[4]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[1][0]=='r' || s[1][0]=='R')
                 {    if((s[1][1]>=48 && s[1][1]<58 && strlen(s[1])==2) ||(s[1][1]==49 && strlen(s[1])==3 && s[1][2]>=48 && s[1][2]<51 ))
                    {int Rd; if(strlen(s[1])==2) Rd = (int)s[1][1]-'0';
                      if(strlen(s[1])==3) Rd=(s[1][1]-'0')*10 + s[1][2]-'0';
                     
                     if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51))
                    { int R1 ;if(strlen(s[2])==2) R1 = (int)s[2][1]-'0';
                        if(strlen(s[2])==3) R1=(s[2][1]-'0')*10 + s[2][2]-'0';

                    if (s[3][0]=='r' || s[3][0]=='R')//for register as second oprand
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) || (s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<51))
                    { int R2 ;if(strlen(s[3])==2) R2= (int)s[3][1]-'0';
                       if(strlen(s[3])==3) R2=(s[3][1]-'0')*10 + s[3][2]-'0';

                     //printf("%d %d %d\n",Rd,R1,R2 );
                    write_word(MEM, address, (14<<28)|(R1<<16)|(Rd<<12)|(R2));
                     address+=4;
                    // instruction here
                    }else{error_count++;
                  printf(" register R2 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[3][0]=='#'){  len=strlen(s[3]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[3][il+1]>57 || s[3][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[3][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                    write_word(MEM, address, (14<<28)|(1<<25)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("operand 2 is not valid in line: %d\n",line_count );
                 } 
                     


                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }
        
      }else if(!strcmp(s[0],"OR") || !strcmp(s[0],"or"))
      {if(s[1]==NULL || s[2]==NULL || s[3] == NULL)
         {error_count++;
          printf("OR instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[4]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[1][0]=='r' || s[1][0]=='R')
                 {    if((s[1][1]>=48 && s[1][1]<58 && strlen(s[1])==2) ||(s[1][1]==49 && strlen(s[1])==3 && s[1][2]>=48 && s[1][2]<51 ))
                    {int Rd; if(strlen(s[1])==2) Rd = (int)s[1][1]-'0';
                      if(strlen(s[1])==3) Rd=(s[1][1]-'0')*10 + s[1][2]-'0';
                     
                     if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<51))
                    { int R1 ;if(strlen(s[2])==2) R1 = (int)s[2][1]-'0';
                        if(strlen(s[2])==3) R1=(s[2][1]-'0')*10 + s[2][2]-'0';

                    if (s[3][0]=='r' || s[3][0]=='R')//for register as second oprand
                 {    if((s[3][1]>=48 && s[3][1]<58 && strlen(s[3])==2) || (s[3][1]==49 && strlen(s[3])==3 && s[3][2]>=48 && s[3][2]<51))
                    { int R2 ;if(strlen(s[3])==2) R2= (int)s[3][1]-'0';
                       if(strlen(s[3])==3) R2=(s[3][1]-'0')*10 + s[3][2]-'0';

                     //printf("%d %d %d\n",Rd,R1,R2 );
                    write_word(MEM, address, (14<<28)|(12<<21)|(R1<<16)|(Rd<<12)|(R2));
                     address+=4;
                    // instruction here
                    }else{error_count++;
                  printf(" register R2 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[3][0]=='#'){  len=strlen(s[3]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[3][il+1]>57 || s[3][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[3][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d %d\n",Rd,R1,imm );
                    write_word(MEM, address, (14<<28)|(1<<25)|(12<<21)|(R1<<16)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("operand 2 is not valid in line: %d\n",line_count );
                 } 
                     


                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }
        
      }else if(!strcmp(s[0],"cmp") || !strcmp(s[0],"CMP"))
      {if(s[1]==NULL || s[2]==NULL)
         {error_count++;
          printf("CMP instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[3]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[1][0]=='r' || s[1][0]=='R')
                 {    if((s[1][1]>=48 && s[1][1]<58 && strlen(s[1])==2) ||(s[1][1]==49 && strlen(s[1])==3 && s[1][2]>=48 && s[1][2]<54 ))
                    {int Rd; if(strlen(s[1])==2) Rd = (int)s[1][1]-'0';
                      if(strlen(s[1])==3) Rd=(s[1][1]-'0')*10 + s[1][2]-'0';
                     
                     if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<54))
                    { int R1 ;if(strlen(s[2])==2) R1 = (int)s[2][1]-'0';
                        if(strlen(s[2])==3) R1=(s[2][1]-'0')*10 + s[2][2]-'0';
                     write_word(MEM, address, (14<<28)|(10<<21)|(Rd<<16)|(R1));
                       address+=4;
                     
                    //instruction goes here

                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[2][0]=='#'){  len=strlen(s[2]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[2][il+1]>57 || s[2][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[2][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d\n",Rd,imm );
                    write_word(MEM, address, (14<<28)|(1<<25)|(10<<21)|(Rd<<16)|(imm));
                       address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("in CMP instruction register/Immediate is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                 } 

         }
        
      }else if(!strcmp(s[0],"mov") || !strcmp(s[0],"MOV"))
      {if(s[1]==NULL || s[2]==NULL)
         {error_count++;
          printf("MOV instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[3]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[1][0]=='r' || s[1][0]=='R')
                 {    if((s[1][1]>=48 && s[1][1]<58 && strlen(s[1])==2) ||(s[1][1]==49 && strlen(s[1])==3 && s[1][2]>=48 && s[1][2]<51 ))
                    {int Rd; if(strlen(s[1])==2) Rd = (int)s[1][1]-'0';
                      if(strlen(s[1])==3) Rd=(s[1][1]-'0')*10 + s[1][2]-'0';
                     
                     if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<54))
                    { int R1 ;if(strlen(s[2])==2) R1 = (int)s[2][1]-'0';
                        if(strlen(s[2])==3) R1=(s[2][1]-'0')*10 + s[2][2]-'0';
                      write_word(MEM, address, (14<<28)|(13<<21)|(Rd<<12)|(R1));
                      address+=4;
                     
                    //instruction goes here

                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[2][0]=='#'){  len=strlen(s[2]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[2][il+1]>57 || s[2][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[2][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d\n",Rd,imm );
                    write_word(MEM, address, (14<<28)|(1<<25)|(13<<21)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("in CMP instruction register/Immediate is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }
        
      }else if(!strcmp(s[0],"MNV") || !strcmp(s[0],"mnv"))
      {if(s[1]==NULL || s[2]==NULL)
         {error_count++;
          printf("MNV instruction in line:%d is not complete\n",line_count );
         }else{
                 if(s[3]!=NULL)
                 { error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
                 }else if (s[1][0]=='r' || s[1][0]=='R')
                 {    if((s[1][1]>=48 && s[1][1]<58 && strlen(s[1])==2) ||(s[1][1]==49 && strlen(s[1])==3 && s[1][2]>=48 && s[1][2]<51 ))
                    {int Rd; if(strlen(s[1])==2) Rd = (int)s[1][1]-'0';
                      if(strlen(s[1])==3) Rd=(s[1][1]-'0')*10 + s[1][2]-'0';
                     
                     if (s[2][0]=='r' || s[2][0]=='R')
                 {    if((s[2][1]>=48 && s[2][1]<58 && strlen(s[2])==2) ||(s[2][1]==49 && strlen(s[2])==3 && s[2][2]>=48 && s[2][2]<54))
                    { int R1 ;if(strlen(s[2])==2) R1 = (int)s[2][1]-'0';
                        if(strlen(s[2])==3) R1=(s[2][1]-'0')*10 + s[2][2]-'0';
                     
                     write_word(MEM, address, (14<<28)|(15<<21)|(Rd<<12)|(R1));
                     address+=4;
                     
                    //instruction goes here

                    }else{error_count++;
                  printf("register R1 is not valid in line: %d\n",line_count );
                                          }

                 }else if (s[2][0]=='#'){  len=strlen(s[2]);

                if(len<=4 && len>=2){int imm=0; for(int il=0;il<len-1;il++){
                    if(s[2][il+1]>57 || s[2][il+1]<48){error_count++;imm=1;
                  printf("Immediate is not valid in line: %d\n",line_count );
                      break;
                    }
                  }
                  if (imm==0)
                  {
                    for(int il=0;il<len-1;il++)
                      imm=(s[2][il+1]-'0')+10*imm;
                  }
                  if(imm>255) printf("Error in line:%d is =>Immediate cann't be greater than 8 bit number\n",line_count );
                  else {//printf("%d %d\n",Rd,imm );
                  write_word(MEM, address, (14<<28)|(1<<25)|(15<<21)|(Rd<<12)|(imm));
                     address+=4;
                    //put instruction code here
                  }
                  }else{error_count++;
                  printf("Immediate is not valid in line: %d\n",line_count );
                   }

                 

                 }else{
                  error_count++;
                  printf("in CMP instruction register/Immediate is not valid in line: %d\n",line_count );
                 } 


                    }else{error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                                          }

                 }else{
                  error_count++;
                  printf("destination register is not valid in line: %d\n",line_count );
                 } 

         }
        
      }else if(!strcmp(s[0],"b") || !strcmp(s[0],"B"))
      { if(s[1]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[2]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[1],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
            write_word(MEM, address, (14<<28)|(2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;         
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[1],line_count );
         }
        }
        
        }
        
      }else if(!strcmp(s[0],"bge") || !strcmp(s[0],"BGE"))
      {if(s[1]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[2]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[1],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
            write_word(MEM, address, (10<<28)|(2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;         
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[1],line_count );
         }
        }
        
        }
        
      }else if(!strcmp(s[0],"BL") || !strcmp(s[0],"bl"))
      {if(s[1]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[2]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[1],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
            write_word(MEM, address, (11<<28)|(2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;          
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[1],line_count );
         }
        }
        
        }
        
      }else if(!strcmp(s[0],"bgt") || !strcmp(s[0],"BGT"))
      {if(s[1]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[2]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[1],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
            write_word(MEM, address, (12<<28)|(2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;          
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[1],line_count );
         }
        }
        
        }
        
      }else if(!strcmp(s[0],"BLE") || !strcmp(s[0],"ble"))
      {if(s[1]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[2]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[1],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
            write_word(MEM, address, (13<<28)|(2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;          
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[1],line_count );
         }
        }
        
        }
        
      }else if(!strcmp(s[0],"BNE") || !strcmp(s[0],"bne"))
      {if(s[1]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[2]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[1],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
            write_word(MEM, address, (1<<28)|(2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;          
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[1],line_count );
         }
        }
        
        }
        
      }else if(!strcmp(s[0],"BEQ") || !strcmp(s[0],"beq"))
      {if(s[1]==NULL)
        {error_count++;
          printf("Branch instruction in line:%d is not complete\n",line_count);

        }else{

        if(s[2]!=NULL){error_count++;
                   printf("Error:only one instruction is allowed in one line. Error in line:%d\n",line_count );
        }else{ int f=0,lblno=-1;  for (int i = 0; i < 30; ++i)
        {
          if(!strcmp(s[1],lbl[i].label))
           { f=1;lblno=i;break;}
        }
         if(f==1)
         { //printf("%d\n",lblno );
            write_word(MEM, address, (2<<26)|(2<<24)|(lbl[lblno].address));
            address+=4;
          //instruction here
         }else{error_count++;
          printf("didn't find the lable:%s in program any where. Error in line :%d\n",s[1],line_count );
         }
        }
        
        }
        
      }else
      { error_count++;
        printf("Error:unable to identify instruction in line no:%d\n",line_count);
      }




  }
 
 } //end of partext() 




//writes the data memory in "data_out.txt" file
void write_data_memory() {
  unsigned int i;
  FILE *fp;
  fp = fopen("data_out.txt", "w");
  if(fp == NULL) {
    printf("Error opening dataout.txt file for writing\n");
    return;
  }
  
  for(i=0; i < 400; i = i+4){
    fprintf(fp, "%x %x\n", i, read_word(DMEM, i));
  }
  fclose(fp);
}

//should be called when instruction is swi_exit
void swi_exit() {
  write_data_memory();
  show_state();
  Tcycles+=swi_exit1;
   printf("\nTotal executed instruction=%d\n",fetch_inst );
  printf("Total cycles count=%d\n",Tcycles );
  printf("Cycles per Instruction(CPI)=%f\n",(float)Tcycles/(float)fetch_inst );
  printf("Instructions per cycle(i.e inverse of CPI)=%f\n",(float)fetch_inst/(float)Tcycles );    
  // printf("\nTotal executed instruction(i.e inverse of CPI)=%f\n",(float)fetch_inst/(float)Tcycles );    
  printf("Exextion Time(wrt 2 GHz Processor)=%fms\n",(float)2*Tcycles/1000000.0 );    
  exit(0);
}



//perform the memory operation
void mem() {
   if(f==1){
    if(opcode==25){ //LDR
      if(operand1==-1)
      {
       operand1=0;
      }else{unsigned int data = read_word(DMEM, operand1);
      
      operand1 = data; }
      
    }else if(opcode==24){ //STR
      write_word(DMEM, operand1, R[destination]);
      
    }
  }
 
}
//writes the results back to register file
void write_back() {
 
  if(f==0){
      if (destination!=13)
      { R[destination] = operand1;
      
      }
  }else if(f==1){
    if(opcode==25){
      R[destination] = operand1;

    }
  }
}



