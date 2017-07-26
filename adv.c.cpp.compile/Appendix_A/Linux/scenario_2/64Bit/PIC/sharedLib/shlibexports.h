// Variables intended for export
int nShlibExportedVariable  = 0;

// Functions intended for export (ABI functions)
int shlib_abi_initialize(int x, int y);
int shlib_abi_uninitialize(void);
int shlib_abi_reinitialize(int x, int y);
