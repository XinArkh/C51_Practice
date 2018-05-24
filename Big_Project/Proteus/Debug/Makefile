###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = AT89C51
COMPILER = "IAR for 8051 (C)"
TARGET = Debug
SHELL = C:\WINDOWS\system32\cmd.exe

## Tools general options
ASMFLAGS=-D__CORE__=1 -D__CODE_MODEL__=1 -D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=2 -D__NUMBER_OF_DPTRS__=1 -s+ -I"E:\IAR Systems\Embedded Workbench 8.0\8051\bin\..\INC" -w+ -r -v0
CCFLAGS=-e --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --dptr=16,1 --data_model=small --code_model=near --calling_convention=idata_reentrant --place_constants=data --nr_virtual_regs 8 -I "E:/IAR Systems/Embedded Workbench 8.0/8051/bin/../INC/" -I "E:/IAR Systems/Embedded Workbench 8.0/8051/bin/../INC/CLIB/" --debug -On --core=plain
LDFLAGS=-Fubrof8 -I"E:/IAR Systems/Embedded Workbench 8.0/8051/bin/../CONFIG/" -I"E:/IAR Systems/Embedded Workbench 8.0/8051/bin/../LIB/" -D_NR_OF_VIRTUAL_REGISTERS=8 -e_small_write=_formatted_write -e_medium_read=_formatted_read -D_NR_OF_BANKS=0 -D_CODEBANK_END=0 -D_CODEBANK_START=0 -D_IDATA_STACK_SIZE=0x40 -D_EXTENDED_STACK_START=0x00 -D_EXTENDED_STACK_SIZE=0x00 -D_PDATA_STACK_SIZE=0x80 -D_XDATA_STACK_SIZE=0xEFF -D_XDATA_HEAP_SIZE=0xFF -D_FAR_HEAP_SIZE=0xFFF -D_HUGE_HEAP_SIZE=0xFFF "E:/IAR Systems/Embedded Workbench 8.0/8051/bin/../LIB/CLIB/cl-pli-nsid-1e16x01.r51" -s __program_start

## Processing Tools
CC=icc8051.exe
LD=xlink.exe
ASM=a8051.exe
#  C:/Users/DELL-/Desktop/C51_Practice/Big_Project/Debug/Debug.ubf: TOOL=LD
#     C:/Users/DELL-/Desktop/C51_Practice/Big_Project/Debug/MOTOR_~1.r51: TOOL=CC
#        C:/Users/DELL-/Desktop/C51_Practice/Big_Project/Motor_Controller.c
#     C:/Users/DELL-/Desktop/C51_Practice/Big_Project/lnk51ew.xcl

# Build tree:
all:	Debug

Debug:	Debug.ubf

Debug.ubf:	MOTOR_~1.r51 ../lnk51ew.xcl 
	$(LD) $(LDFLAGS)  -o "Debug.ubf" "MOTOR_~1.r51" -f "../lnk51ew.xcl"

MOTOR_~1.r51:	../MOTOR_~1.C 
	$(CC) $(CCFLAGS)  "../Motor_Controller.c" -o "MOTOR_~1.r51" 

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf ./MOTOR_~1.d

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.ubf
	rm -rf MOTOR_~1.r51

