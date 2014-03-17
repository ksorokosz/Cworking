#include "CW_Macros_Definitions.h"

void* CW_allocate_memory( CW_uint32_t CW_memory_size, const char* CW_file, CW_uint32_t CW_line )
{
	/* Trace - it can be called in case error e.g out of memory */
	LOG( stderr, "Info: MALLOC called from %s %u", CW_file, CW_line );

	/* Allocate memory */
	void* p = malloc( CW_memory_size );
	if(p == NULL)
	{
		LOG( stderr, "Out of memory: MALLOC called from %s %u", CW_file, CW_line );
		exit(EXIT_FAILURE);
	}

	/* Initialize memory block to zero */
	memset( p, 0, CW_memory_size );

	/* Return memory block */
	return p;
}

void CW_free_memory( void** CW_pointer, const char* CW_file, CW_uint32_t CW_line )
{
	/* Trace - it can be called in case error e.g null pointer exception */
	LOG( stderr, "Info: FREE called from %s %u", CW_file, CW_line );

	/* Check if not null */
	if ( (*CW_pointer) == NULL )
	{
		LOG( stderr, "Null pointer exception: FREE called from %s %u", CW_file, CW_line );
		exit(EXIT_FAILURE);
	}

	/* Free memory */
	free( (*CW_pointer) );

	/* Reset to NULL */
	( *CW_pointer ) = NULL;
}
