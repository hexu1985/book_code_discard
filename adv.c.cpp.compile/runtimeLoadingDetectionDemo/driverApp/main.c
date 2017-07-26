#define _GNU_SOURCE
#include <link.h>
#include <stdio.h>
#include <dlfcn.h>
#include "sharedLib1Functions.h"
#include "sharedLib2Functions.h"

static const char* segment_type_to_string(uint32_t type)
{
	switch(type)
	{
	case PT_NULL:         // 0
		return "Unused";
		break;
	case PT_LOAD:         // 1
		return "Loadable Program Segment";
		break;
	case PT_DYNAMIC:      //2
		return "Dynamic linking information";
		break;
	case PT_INTERP:       // 3
		return "Program interpreter";
		break;
	case PT_NOTE:         // 4
		return "Auxiliary information";
		break;
	case PT_SHLIB:        // 5
		return "Reserved";
		break;
	case PT_PHDR:         // 6
		return "Entry for header table itself";
		break;
	case PT_TLS:          // 7
		return "Thread-local storage segment";
		break;
//	case PT_NUM:          // 8		/* Number of defined types */
	case PT_LOOS:         // 0x60000000	
		return "Start of OS-specific";
		break;
	case PT_GNU_EH_FRAME: // 0x6474e550	
		return "GCC .eh_frame_hdr segment";
		break;
	case PT_GNU_STACK:    // 0x6474e551	
		return "Indicates stack executability";
		break;
	case PT_GNU_RELRO:    // 0x6474e552	
		return "Read-only after relocation";
		break;
//	case PT_LOSUNW:       // 0x6ffffffa
	case PT_SUNWBSS:      // 0x6ffffffa	
		return "Sun Specific segment";
		break;
	case PT_SUNWSTACK:    // 0x6ffffffb	
		return "Sun Stack segment";
		break;
//	case PT_HISUNW:       // 0x6fffffff
//	case PT_HIOS:         // 0x6fffffff	/* End of OS-specific */
//	case PT_LOPROC:       // 0x70000000	/* Start of processor-specific */
//	case PT_HIPROC:       // 0x7fffffff	/* End of processor-specific */	
	default:
		return "???";
	}
}

static const char* flags_to_string(uint32_t flags)
{
	switch(flags)
	{
	case 1:
		return "--x";
		break;
	case 2:
		return "-w-";
		break;
	case 3:
		return "-wx";
		break;
	case 4:
		return "r--";
		break;
	case 5:
		return "r-x";
		break;
	case 6:
		return "rw-";
		break;
	case 7:
		return "rwx";
		break;
	default:
		return "???";
		break;
	}
}

static int header_handler(struct dl_phdr_info* info, size_t size, void* data)
{
	int j;
    printf("name=%s (%d segments) address=%p\n",
            info->dlpi_name, info->dlpi_phnum, (void*)info->dlpi_addr);
    for (j = 0; j < info->dlpi_phnum; j++) {
         printf("\t\t header %2d: address=%10p\n", j,
             (void*) (info->dlpi_addr + info->dlpi_phdr[j].p_vaddr));
         printf("\t\t\t type=0x%X (%s),\n\t\t\t flags=0x%X (%s)\n",
                 info->dlpi_phdr[j].p_type, 
                 segment_type_to_string(info->dlpi_phdr[j].p_type),
                 info->dlpi_phdr[j].p_flags,
                 flags_to_string(info->dlpi_phdr[j].p_flags));
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[])
{
	// function from statically aware loaded library
	sharedLib1Function(argc);
	
	// function from run-time dynamically loaded library
    void* pLibHandle = dlopen("libdemo2.so", RTLD_GLOBAL | RTLD_NOW);
    if(NULL == pLibHandle)
    {
		printf("Failed loading libdemo2.so, error = %s\n", dlerror());
		return -1;
	}	
	PFUNC pFunc = (PFUNC)dlsym(pLibHandle, "sharedLib2Function");
	
	if(NULL == pFunc)
	{
		printf("Failed identifying the symbol \"sharedLib2Function\"\n");
		dlclose(pLibHandle);
		pLibHandle = NULL;
		return -1;
	}
	
	pFunc(argc);
	if(2 == argc)
		getchar();
		
	if(3 == argc)
		dl_iterate_phdr(header_handler, NULL);
		
	return 0;
}
