/**
 * @file CW_Interface_PersonalData.h
 *
 * @date 9 mar 2014
 * @author Kamil Sorokosz
 * @brief File contains personal data module which implements example interface
 */

#ifndef _CW_INTERFACE_PERSONALDATA_H__
#define _CW_INTERFACE_PERSONALDATA_H__

#include "CW_Interface_Definitions.h"
#include "CW_Interface_Types.h"
#include "CW_Interface.h"

/**
 * Data required by interface functions
 */
struct CW_Interface_Data
{
	/** User name - it is only an example */
	CW_char_t CW_name[10];

	/** User surname - it is only an example */
	CW_char_t CW_surname[10];

	/** User full name - it is only an example */
	CW_char_t CW_fullname[20];
};

/** Personal data typedef */
typedef struct CW_Interface_Data CW_Personal_Data;

/**
 * Create dump personal data
 *
 * @param CW_data - personal data
 */
void CW_PersonalData_Create_Dump( CW_Personal_Data* const CW_data );


/**
 * Interface first realization (first algorithm)
 * Full name equals name | ' ' | surname
 */
class CW_Personal_Data_First : public CW_Interface_Body
{

public:

	/**
	 * Default constructor
	 */
	CW_Personal_Data_First() {};

	/**
	 * Default destructor
	 */
	virtual ~CW_Personal_Data_First() {};

	/**
	 * Some function. Full name equals name | ' ' | surname
	 *
	 * @param CW_data - shared data
	 */
	void CW_fun( CW_Personal_Data& CW_data );

	/**
	 * Destroy shared data
	 *
	 * @param CW_data - shared data
	 * @param CW_error - error
	 */
	virtual void CW_destroy( CW_Personal_Data& CW_data );

};

/**
 * Interface second realization (second algorithm)
 * Full name equals surname | ' ' | name
 */
class CW_Personal_Data_Second : public CW_Interface_Body
{

public:

	/**
	 * Default constructor
	 */
	CW_Personal_Data_Second() {};

	/**
	 * Default destructor
	 */
	virtual ~CW_Personal_Data_Second() {};

	/**
	 * Some function. Full name equals name | ' ' | surname
	 *
	 * @param CW_data - shared data
	 */
	void CW_fun( CW_Personal_Data& CW_data );

	/**
	 * Destroy shared data
	 *
	 * @param CW_data - shared data
	 * @param CW_error - error
	 */
	virtual void CW_destroy( CW_Personal_Data& CW_data );

};

#endif /* _CW_INTERFACE_PERSONALDATA_H__ */
