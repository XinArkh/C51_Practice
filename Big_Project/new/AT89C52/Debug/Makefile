###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = AT89C52
COMPILER = "IAR for 8051 (C)"
TARGET = Debug
SHELL = C:\WINDOWS\system32\cmd.exe

## Tools general options
CCFLAGS=-e --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --dptr=16,1 --data_model=small --code_model=near --calling_convention=idata_reentrant --place_constants=data --nr_virtual_regs 8 -I "E:/IAR Systems/Embedded Workbench 8.0/8051/bin/../INC/" -I "E:/IAR Systems/Embedded Workbench 8.0/8051/bin/../INC/CLIB/" --debug -On --core=plain
LDFLAGS=-Fubrof8 -I"E:/IAR Systems/Embedded Workbench 8.0/8051/bin/../CONFIG/" -I"E:/IAR Systems/Embedded Workbench 8.0/8051/bin/../LIB/" -e_small_write=_formatted_write -e_medium_read=_formatted_read -D_NR_OF_VIRTUAL_REGISTERS=8 -D_IDATA_STACK_SIZE=0x40 -D_PDATA_STACK_SIZE=0x80 -D_EXTENDED_STACK_START=0x00 -D_EXTENDED_STACK_SIZE=0x00 -D_XDATA_STACK_SIZE=0xEFF -D_XDATA_HEAP_SIZE=0xFF "E:/IAR Systems/Embedded Workbench 8.0/8051/bin/../LIB/CLIB/cl-pli-nsid-1e16x01.r51" -s __program_start -f "E:/IAR Systems/Embedded Workbench 8.0/8051/bin/../config/devices/Atmel/lnk51ew_AT89C52.xcl"

## Processing Tools
CC=icc8051.exe
LD=xlink.exe
ASM=a8051.exe
#  C:/Users/DELL-/Desktop/C51_Practice/new/AT89C52/Debug/Debug.ubf: TOOL=LD
#     C:/Users/DELL-/Desktop/C51_Practice/new/AT89C52/Debug/main.r51: TOOL=CC
#        C:/Users/DELL-/Desktop/C51_Practice/new/AT89C52/main.c

# Build tree:
all:	Debug

Debug:	Debug.ubf

Debug.ubf:	main.r51 
	$(LD) $(LDFLAGS)  -o "Debug.ubf" "main.r51"

main.r51:	../main.c 
	$(CC) $(CCFLAGS)  "../main.c" -o "main.r51" 

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf ./main.d

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.ubf
	rm -rf main.r51

