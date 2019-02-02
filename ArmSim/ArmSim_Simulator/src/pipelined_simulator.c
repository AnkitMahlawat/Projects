// Matthew Husted
// Pipeline Simulator
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern int ldr,ldr_pseudo,str,str_pseudo,add,sub,cmp,mul,bne,bge,b,bl,mov,orr,and1,mnv,swi_exit1;
#define NUMMEMORY 65536 /* maximum number of data words in memory */
#define NUMREGS 16 /* number of machine registers */
#define MAXLINELENGTH 1000
int Z=0,N=0;
#define AND 0
#define SUB 2
#define ADD 4
#define MUL 5
#define CMP 10
#define ORR 12
#define MOV 13
#define MVN 15
#define STR 24
#define LDR 25
#define BEQ 32
#define BNE 33
#define BGE 42
#define BL 43
#define BGT 44
#define BLE 45
#define B 46
#define EXIT 0xEF000011
// #define JALR 5  /* didn't implement */

#define NOOPINSTRUCTION 0x1F000000
#define TRUE 1
#define FALSE 0

typedef struct IFIDStruct {
    int instr;
    int pcPlus1;
    int h1;
} IFIDType;

typedef struct IDEXStruct {
    int instr;
    int pcPlus1;
    int readRegA;
    int readRegB;
    int offset;
    int h2;
} IDEXType;

typedef struct EXMEMStruct {
    int instr;
    int branchTarget;
    int aluResult;
    int readRegB;
} EXMEMType;

typedef struct MEMWBStruct {
    int instr;
    int writeData;
} MEMWBType;

typedef struct WBENDStruct {
    int instr;
    int writeData;
} WBENDType;

typedef struct stateStruct {
    int pc;
    int instrMem[NUMMEMORY];
    char dataMem[NUMMEMORY];
    int reg[NUMREGS];
    int numMemory;
    IFIDType IFID;
    IDEXType IDEX;
    EXMEMType EXMEM;
    MEMWBType MEMWB;
    WBENDType WBEND;
    int cycles; /* number of cycles run so far */
} stateType;

void printState(stateType *);
int field0(int);
int field1(int);
int field2(int);
int opcode(int);
void printInstruction(int);

int convertNum(int);

int read_word(char *mem, unsigned int address) {
  int *data;
  data =  (int*) (mem + address);
  return *data;
}

void write_word(char *mem, unsigned int address, unsigned int data) {
  int *data_p;
  data_p = (int*) (mem + address);
  *data_p = data;
}


void pipelined_simulator( char instrMem[],int size)
{
	freopen("output.txt","w",stdout);
	int tempRegA,ldrA; // used for forwarding
	int tempRegB,ldrB;
	int EXcycle,MEMcycle,tcycles,fcycles,instruction_count=0,h0=3;
	bool change;
	
	stateType state;
	stateType newState;
	
	// sets all registers to zero '0'
	int i;
	for (i = 0; i < NUMREGS; i++)
		state.reg[i] = 0;
		
	
	/* read in the entire machine-code file into memory */
	for (state.numMemory = 0; state.numMemory < (size/4);state.numMemory++) {
		 state.instrMem[state.numMemory]=read_word( instrMem,(4*state.numMemory));
     }
	
	
	int j;
	for (j = 0; j < state.numMemory; j++) {
		printf("instrMem[%d] = %x\n", j, state.instrMem[j]);
	}
	printf("%d memory words\n",j);
	printf("\tinstruction memory:\n");
	for (j = 0; j < state.numMemory; j++) {
		printf("\t\tinstruction[ %d ] ", j);
		printInstruction(state.instrMem[j]);
		//printf("\n");
	}
	
	// initialize all instructions to NOOP
	state.IFID.instr = NOOPINSTRUCTION;
	state.IDEX.instr = NOOPINSTRUCTION;
	state.EXMEM.instr = NOOPINSTRUCTION;
	state.MEMWB.instr = NOOPINSTRUCTION;
	state.WBEND.instr = NOOPINSTRUCTION;
	state.reg[13] = 4000;
	state.pc = 0;
	state.cycles = 0;
	
	
	while (1) {
	    
		if (state.cycles > 9999999)
			exit(0); // infinite loop
	    
	    if ( opcode(state.MEMWB.instr) != NOOPINSTRUCTION )
		{
			instruction_count++;
		}

		/* check for EXIT */
		if (opcode(state.MEMWB.instr) == EXIT) {
	    	printf("machine halted\n");
	    	printf("total of %d cycles executed\n", state.cycles);
	    	printf("Total executed instruction=%d\n",instruction_count );
            printf("Cycles per Instruction(CPI)=%f\n",(float)(state.cycles)/(float)instruction_count );
            printf("Instructions per cycle(i.e inverse of CPI)=%f\n",(float)instruction_count/(float)(state.cycles) );    
            printf("Exextion Time(wrt 2 GHz Processor)=%fms\n",(float)2*(state.cycles)/1000000.0 );    
            exit(0);
		}

		newState = state;
		newState.cycles++;
         
		/* --------------------- IF stage --------------------- */
		
		
        newState.IFID.h1 = h0;
		newState.IFID.instr = state.instrMem[state.pc];
		newState.IFID.pcPlus1 = state.pc + 1;
		++newState.pc;
		if (opcode(state.instrMem[state.pc]) == B)
		{
			newState.pc = (state.instrMem[state.pc]&0xFFFFFF)/4;
		}else if (opcode(state.instrMem[state.pc]) == BL)
		{   
			newState.pc = (state.instrMem[state.pc]&0xFFFFFF)/4;
			newState.reg[14] = (state.instrMem[state.pc]&0xFFFFFF)/4;
		}
         		
         if ((opcode(state.instrMem[state.pc])>30)&&((opcode(state.instrMem[state.pc])<50)))
          { 
          	if ((h0 == 3)||(h0 == 2) )
            {
          	   newState.pc = (state.instrMem[state.pc]&0xFFFFFF)/4;
            }	
          } 


		/* --------------------- ID stage --------------------- */
				
		
    	newState.IDEX.h2 = state.IFID.h1;    
		newState.IDEX.instr = state.IFID.instr;
		newState.IDEX.pcPlus1 = state.IFID.pcPlus1;
		newState.IDEX.readRegA = state.reg[field0(state.IFID.instr)];
		newState.IDEX.readRegB = state.reg[field1(state.IFID.instr)];
		newState.IDEX.offset = field2(state.IFID.instr);
		
		// stalls for LDR	
		if ((opcode(state.IDEX.instr) == LDR) && 
				((field0(state.IFID.instr) == field1(state.IDEX.instr) && 
				opcode(state.IFID.instr) < 13 ) || 
				(field2(state.IFID.instr) == field1(state.IDEX.instr) &&
				 opcode(state.IFID.instr) < 20 && 
				  (state.IFID.instr>>25&0x1)==0)))
		{
			newState.IDEX.instr = NOOPINSTRUCTION;
			newState.pc--;
			newState.IFID.pcPlus1--;
			newState.IFID.instr = state.IFID.instr;
		}		
						
		/* --------------------- EX stage --------------------- */
		
		newState.EXMEM.instr = state.IDEX.instr;
	      change = FALSE;
        if ((opcode(state.IDEX.instr) > 30) &&(opcode(state.IDEX.instr) < 50)) // branch prediction
		{
			if ((opcode(state.IDEX.instr) == BEQ && Z == 1) ||
				(opcode(state.IDEX.instr) == BNE && Z == 0) ||
				(opcode(state.IDEX.instr) == BLE && (Z == 1 || N == 1)) ||
				(opcode(state.IDEX.instr) == BGE &&  N == 0) ||
				(opcode(state.IDEX.instr) == BGT &&  (Z == 0 && N == 0)))
			{  
				if ((state.IDEX.h2 == 1 )||(state.IDEX.h2 == 0 )) {
				    if(h0!=3) h0++;
				    change = TRUE;
				    newState.pc = (state.IDEX.instr&0xFFFFFF)/4;
				    newState.IFID.instr = NOOPINSTRUCTION;
				    newState.IDEX.instr = NOOPINSTRUCTION;
			    }else{
                      if(h0!=3) h0++;
			    }

				
			}else if((opcode(state.IDEX.instr) > 30) &&(opcode(state.IDEX.instr) < 50)){
                if ((state.IDEX.h2 == 2)||(state.IDEX.h2 == 3))
                {   if(h0!=0) h0--;
				    change = TRUE;
				    newState.pc = state.IDEX.pcPlus1;
				    newState.IFID.instr = NOOPINSTRUCTION;
				    newState.IDEX.instr = NOOPINSTRUCTION;
                }else{
                	if(h0!=0) h0--;
                }
			}
		}
		
        // start forwarding
		if ((field0(state.IDEX.instr) == field1(state.EXMEM.instr)) && (opcode(state.EXMEM.instr) != CMP && opcode(state.EXMEM.instr) < 20) && (opcode(state.IDEX.instr) < 13))
		{
		  tempRegA = state.EXMEM.aluResult;
		}else if ((field0(state.IDEX.instr) == field1(state.MEMWB.instr)) && (opcode(state.MEMWB.instr) != CMP && opcode(state.MEMWB.instr) != STR && opcode(state.MEMWB.instr) < 30) && (opcode(state.IDEX.instr) < 13 ))
		{
		  tempRegA = state.MEMWB.writeData; 	
		}else if(opcode(state.IDEX.instr) < 13 )
		{  
          tempRegA = state.reg[field0(state.IDEX.instr)];
		}
		


		if ((field2(state.IDEX.instr) == field1(state.EXMEM.instr)) && ((state.IDEX.instr>>25&1)==0 && opcode(state.IDEX.instr) < 20) && (opcode(state.EXMEM.instr) != CMP && opcode(state.EXMEM.instr) < 20))
		{
		  tempRegB = state.EXMEM.aluResult;
		}else if((field2(state.IDEX.instr) == field1(state.MEMWB.instr) && ((state.IDEX.instr>>25&1)==0 && opcode(state.IDEX.instr) < 20)) && (opcode(state.MEMWB.instr) != CMP && opcode(state.MEMWB.instr) != STR && opcode(state.MEMWB.instr) < 30))
		{
          tempRegB = state.MEMWB.writeData; 
		}else if(opcode(state.IDEX.instr) < 20)
		{
          if ((state.IDEX.instr>>25&1)== 0)
          {
          	tempRegB = state.reg[field2(state.IDEX.instr)];
          }else 
          {
            tempRegB = (state.IDEX.instr & 0xFFF) ;
          }
           
		}
		//end forwarding

		newState.EXMEM.branchTarget = state.IDEX.offset + state.IDEX.pcPlus1;	
		newState.EXMEM.readRegB = tempRegB;
	
		if (opcode(state.IDEX.instr) == AND)
		{
			newState.EXMEM.aluResult  = (tempRegA & tempRegB) ;
		}
		else if (opcode(state.IDEX.instr) == ADD)
		{
			newState.EXMEM.aluResult  = tempRegA + tempRegB;
		}		
		else if (opcode(state.IDEX.instr) == ORR)
		{
			newState.EXMEM.aluResult  = (tempRegA | tempRegB);
		}		
		else if (opcode(state.IDEX.instr) == SUB)
		{
			newState.EXMEM.aluResult  = (tempRegA - tempRegB);
		}		
		else if (opcode(state.IDEX.instr) == MUL)
		{
			newState.EXMEM.aluResult  = (tempRegA * tempRegB);
		}
		else if (opcode(state.IDEX.instr) == CMP)
		{   
			if (tempRegA == tempRegB)
			{Z = 1;}
			else 
			{Z = 0;}	
			if (tempRegA < tempRegB)
			{N = 1;}
			else
			{N = 0;}	
		}else if (opcode(state.IDEX.instr) == MOV)
		{
			newState.EXMEM.aluResult  =  tempRegB;
		}else if (opcode(state.IDEX.instr) == MVN)
		{
			newState.EXMEM.aluResult  =  ~(tempRegB);
		}		
		
		
		/* --------------------- MEM stage --------------------- */

		

		newState.MEMWB.instr = state.EXMEM.instr;
		
		
		// else 

		//ldr str forwarding
        if ((opcode(state.EXMEM.instr) == LDR) && 
        	(field0(state.EXMEM.instr) == field1(state.MEMWB.instr)) && 
        	(opcode(state.MEMWB.instr) < 30) && 
        	(opcode(state.MEMWB.instr) != CMP && 
        	opcode(state.MEMWB.instr) != STR) && 
        	((state.EXMEM.instr>>16&0xF) < 14 ))
        {
        	ldrA = state.MEMWB.writeData;
        }else if((opcode(state.EXMEM.instr) == LDR) && ((state.EXMEM.instr>>16&0xF) < 14 ))
        {
            ldrA = state.reg[field0(state.EXMEM.instr)];
        }else if ((opcode(state.EXMEM.instr) == STR) && 
        	      (field0(state.EXMEM.instr) == field1(state.MEMWB.instr)) && 
        	      (opcode(state.MEMWB.instr) < 30) && 
        	      (opcode(state.MEMWB.instr) != CMP && 
        	       opcode(state.MEMWB.instr) != STR) && 
        	      ((state.EXMEM.instr>>16&0xF) < 14 ))
        {
        	ldrA = state.MEMWB.writeData;
        }else if((opcode(state.EXMEM.instr) == STR) && ((state.EXMEM.instr>>16&0xF) < 14 ))
        {
            ldrA = state.reg[field0(state.EXMEM.instr)];
        }
        
        if ((opcode(state.EXMEM.instr) == STR) && 
        	(field1(state.EXMEM.instr) == field1(state.MEMWB.instr)) && 
        	(opcode(state.MEMWB.instr) < 30) && 
        	(opcode(state.MEMWB.instr) != CMP && 
        	opcode(state.MEMWB.instr) != STR))
        {
        	ldrB = state.MEMWB.writeData;
        }else if (opcode(state.EXMEM.instr) == STR)
        {
        	ldrB = state.reg[field1(state.EXMEM.instr)];
        }
        //end forwarding
      
	    if ((opcode(state.EXMEM.instr) == LDR) && ((state.EXMEM.instr>>16&0xF) < 14 ))
		{	
			newState.MEMWB.writeData = read_word(state.dataMem,ldrA + (state.EXMEM.instr&0xFFF));
		}
		else if(opcode(state.EXMEM.instr) == LDR && ((state.EXMEM.instr>>16&0xF) == 14 ))
		{
			newState.MEMWB.writeData = read_word(state.dataMem,(state.EXMEM.instr&0xFFF));
		}
		else if(opcode(state.EXMEM.instr) == LDR)
		{
			newState.MEMWB.writeData = (state.EXMEM.instr&0xFFF);
		}else if ((opcode(state.EXMEM.instr) == STR) && ((state.EXMEM.instr>>16&0xF) < 14 ))
		{	
		    write_word(newState.dataMem , (ldrA + (state.EXMEM.instr&0xFFF)) , ldrB );
		}else if (opcode(state.EXMEM.instr) == STR)
		{	
			write_word(newState.dataMem , (state.EXMEM.instr&0xFFF) , ldrB);
		}
	    else if(opcode(newState.MEMWB.instr) <30 && opcode(newState.MEMWB.instr) != CMP && opcode(newState.MEMWB.instr) != STR)
		{
			newState.MEMWB.writeData = state.EXMEM.aluResult;
		}
		

		
		/* --------------------- WB stage --------------------- */

		


		newState.WBEND.instr = state.MEMWB.instr;
		newState.WBEND.writeData = state.MEMWB.writeData;
		
		if (opcode(state.MEMWB.instr) < 30 && opcode(state.MEMWB.instr) != CMP && opcode(state.MEMWB.instr) != STR)
		{
			newState.reg[field1(state.MEMWB.instr)] = state.MEMWB.writeData;
		}
		
		
		
		/* --------------------- End stages --------------------- */
		
		newState.reg[15]=newState.pc;
     
       if (opcode(state.EXMEM.instr) == LDR)
       {
       	 MEMcycle = ldr;
       }else if (opcode(state.EXMEM.instr) == STR)
       {
         MEMcycle = str;
       }else{
       	 MEMcycle = 1;
       }
       if(opcode(state.IDEX.instr) == AND)
       {
         EXcycle = and1;
       }else if (opcode(state.IDEX.instr) == SUB)
       {
       	 EXcycle = sub;
       }else if (opcode(state.IDEX.instr) == ADD)
       {
       	 EXcycle = add;
       }else if (opcode(state.IDEX.instr) == MUL)
       {
       	 EXcycle = mul;
       }else if (opcode(state.IDEX.instr) == CMP)
       {
       	 EXcycle = cmp;
       }else if (opcode(state.IDEX.instr) == ORR)
       {
       	 EXcycle = orr;
       }else if (opcode(state.IDEX.instr) == MVN)
       {
       	 EXcycle = mnv;
       }else if ((opcode(state.IDEX.instr) == BNE || opcode(state.IDEX.instr) == BEQ) && change)
       {
       	 EXcycle = bne;
       }else if ((opcode(state.IDEX.instr) == BLE || opcode(state.IDEX.instr) == BGT || opcode(state.IDEX.instr) == BGE)  && change)
       {
       	 EXcycle = bge;
       }else
       {
       	 EXcycle = 1;
       }
       if (opcode(state.instrMem[state.pc]) == B)
       { 
       	 tcycles = b;
       }else if (opcode(state.instrMem[state.pc]) == BL)
       {
       	 tcycles = bl;
       }else
       { 
       	 tcycles = 1;
       }
       

       if (EXcycle>MEMcycle){
       	if (EXcycle>tcycles) fcycles = EXcycle ;
       	else fcycles = tcycles;
       }else{
       	if (MEMcycle>=tcycles) fcycles = MEMcycle;
       	else fcycles = tcycles;
       }
       for (int i = 0; i < (fcycles - 1); ++i)
       {
       	printState(&state );
        newState.cycles ++;
       }


		state = newState; /* this is the last statement before end of the loop.
			    	It marks the end of the cycle and updates the
			    	current state with the values calculated in this
			    	cycle */
		printState(&state);

	}

   
}


void
printState(stateType *statePtr)
{
    int i;
    printf("\n@@@\nstate after cycle %d ends\n", statePtr->cycles );
    printf("\tpc %d\n", statePtr->pc);

    printf("\tdata memory:\n");
	for (i=0; i<=400; i+=4) {
	    printf("\t\tdataMem[ %d ] %x\n", i/4, *(statePtr->dataMem+i));
	}
    printf("\tregisters:\n");
	for (i=0; i<NUMREGS; i++) {
	    printf("\t\treg[ %d ] %d\n", i, statePtr->reg[i]);
	}
    printf("\tIFID:\n");
	printf("\t\tinstruction ");
	printInstruction(statePtr->IFID.instr);
	printf("\t\tpcPlus1 %d\n", statePtr->IFID.pcPlus1);
    printf("\tIDEX:\n");
	printf("\t\tinstruction ");
	printInstruction(statePtr->IDEX.instr);
	printf("\t\tpcPlus1 %d\n", statePtr->IDEX.pcPlus1);
	printf("\t\treadRegA %d\n", statePtr->IDEX.readRegA);
	printf("\t\treadRegB %d\n", statePtr->IDEX.readRegB);
	printf("\t\toffset %d\n", statePtr->IDEX.offset);
    printf("\tEXMEM:\n");
	printf("\t\tinstruction ");
	printInstruction(statePtr->EXMEM.instr);
	printf("\t\tbranchTarget %d\n", statePtr->EXMEM.branchTarget);
	printf("\t\taluResult %d\n", statePtr->EXMEM.aluResult);
	printf("\t\treadRegB %d\n", statePtr->EXMEM.readRegB);
    printf("\tMEMWB:\n");
	printf("\t\tinstruction ");
	printInstruction(statePtr->MEMWB.instr);
	printf("\t\twriteData %d\n", statePtr->MEMWB.writeData);
    printf("\tWBEND:\n");
	printf("\t\tinstruction ");
	printInstruction(statePtr->WBEND.instr);
	printf("\t\twriteData %d\n", statePtr->WBEND.writeData);
}

int
field0(int instruction)
{
    return( (instruction>>16) & 0xF);
}

int
field1(int instruction)
{
    return( (instruction>>12) & 0xF);
}

int
field2(int instruction)
{
    return(instruction & 0xFFF);
}

int opcode(int instruction)
{   int Fbit = (instruction>>26)&0x3;
	if(Fbit == 0)
    return((instruction>>21)&0xF);
	if(Fbit == 1)
    return((instruction>>20)&0x3F);
	if(Fbit == 2)
    return(((instruction>>28)&0xF)|(2<<4));
    if (instruction == EXIT)
    {
    	return(EXIT);
    }
    if (instruction == NOOPINSTRUCTION)
    {
    	return(NOOPINSTRUCTION);
    }
    printf("Error opcode not found\n");
    exit(0);
}

void
printInstruction(int instr)
{
    char opcodeString[10];
    if (opcode(instr) == ADD) {
	printf("%s\n", "add");
    } else if (opcode(instr) == AND && (instr>>28) == 14) {
	printf("%s\n", "and");
    } else if (opcode(instr) == LDR) {
	printf("%s\n", "ldr");
    } else if (opcode(instr) == STR) {
	printf("%s\n", "str");
    } else if (opcode(instr) == MUL) {
	printf("%s\n", "mul");
    } else if (instr == EXIT) {
	printf("%s\n", "swi_exit");
    } else if (opcode(instr) == SUB) {
	printf("%s\n", "sub");
    } else if (opcode(instr) == CMP) {
	printf("%s\n", "cmp");
    } else if (opcode(instr) == ORR) {
	printf("%s\n", "or");
    } else if (opcode(instr) == MOV) {
	printf("%s\n", "mov");
    } else if (opcode(instr) == MVN) {
	printf("%s \n", "mvn");
    } else if (opcode(instr) == BEQ) {
	printf("%s\n", "beq <label>");
    } else if (opcode(instr) == BNE) {
	printf("%s\n", "bne <label>");
    } else if (opcode(instr) == BL) {
	printf("%s\n", "bl <label>");
    } else if (opcode(instr) == BLE) {
	printf("%s\n", "ble <label>");
    } else if (opcode(instr) == BGT) {
	printf("%s\n", "bgt <label>");
    } else if (opcode(instr) == BGE) {
	printf("%s\n", "bge <label>");
    } else if (opcode(instr) == B) {
    printf("%s\n", "b <label>");
    } else {
	printf("No instruction\n");
    }
    
}

int
convertNum(int num)
{
	/* convert a 16-bit number into a 32-bit Sun integer */
	if (num & (1<<15) ) {
	    num -= (1<<16);
	}
	return(num);
}
