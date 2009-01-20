/* $Id$   */
/* DO NOT EDIT - file generated by ObitTables.pl                      */
/*--------------------------------------------------------------------*/
/*;  Copyright (C)  2008                                              */
/*;  Associated Universities, Inc. Washington DC, USA.                */
/*;                                                                   */
/*;  This program is free software; you can redistribute it and/or    */
/*;  modify it under the terms of the GNU General Public License as   */
/*;  published by the Free Software Foundation; either version 2 of   */
/*;  the License, or (at your option) any later version.              */
/*;                                                                   */
/*;  This program is distributed in the hope that it will be useful,  */
/*;  but WITHOUT ANY WARRANTY; without even the implied warranty of   */
/*;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    */
/*;  GNU General Public License for more details.                     */
/*;                                                                   */
/*;  You should have received a copy of the GNU General Public        */
/*;  License along with this program; if not, write to the Free       */
/*;  Software Foundation, Inc., 675 Massachusetts Ave, Cambridge,     */
/*;  MA 02139, USA.                                                   */
/*;                                                                   */
/*;Correspondence about this software should be addressed as follows: */
/*;         Internet email: bcotton@nrao.edu.                        */
/*;         Postal address: William Cotton                            */
/*;                         National Radio Astronomy Observatory      */
/*;                         520 Edgemont Road                         */
/*;                         Charlottesville, VA 22903-2475 USA        */
/*--------------------------------------------------------------------*/
#ifndef OBITTABLECQ_H 
#define OBITTABLECQ_H 

#include "Obit.h"
#include "ObitErr.h"
#include "ObitTable.h"
#include "ObitData.h"

/*-------- Obit: Merx mollis mortibus nuper ------------------*/
/**
 * \file ObitTableCQ.h
 * ObitTableCQ class definition.
 *
 * This class is derived from the #ObitTable class.
 *
 * This class contains tabular data and allows access.
 * "AIPS CQ" table contains VLBA-like correlation parameters which are
 * used for making a number of instrumental corrections.
 * An ObitTableCQ is the front end to a persistent disk resident structure.
 * Both FITS and AIPS cataloged data are supported.
 * This class is derived from the ObitTable class. 
 *
 * This class contains tabular data and allows access.
 * "AIPS CQ" table
 * An ObitTableCQ is the front end to a persistent disk resident structure.
 * Both FITS (as Tables) and AIPS cataloged data are supported.
 *
 * \section TableDataStorage Table data storage
 * In memory tables are stored in a fashion similar to how they are 
 * stored on disk - in large blocks in memory rather than structures.
 * Due to the word alignment requirements of some machines, they are 
 * stored by order of the decreasing element size: 
 * double, float long, int, short, char rather than the logical order.
 * The details of the storage in the buffer are kept in the 
 * #ObitTableCQDesc.
 *
 * In addition to the normal tabular data, a table will have a "_status"
 * column to indicate the status of each row.
 * The status value is read from and written to (some modification) AIPS 
 * tables but are not written to externally generated FITS tables which
 * don't have these colummns.  It will be written to Obit generated tables
 * which will have these columns.
 * Status values:
 * \li status = 0 => normal
 * \li status = 1 => row has been modified (or created) and needs to be
 *                   written.
 * \li status = -1 => row has been marked invalid.
 *
 * \section ObitTableCQSpecification Specifying desired data transfer parameters
 * The desired data transfers are specified in the member ObitInfoList.
 * There are separate sets of parameters used to specify the FITS or AIPS 
 * data files.
 * In the following an ObitInfoList entry is defined by 
 * the name in double quotes, the data type code as an #ObitInfoType enum 
 * and the dimensions of the array (? => depends on application).
 * To specify whether the underlying data files are FITS or AIPS
 * \li "FileType" OBIT_int (1,1,1) OBIT_IO_FITS or OBIT_IO_AIPS 
 * which are values of an #ObitIOType enum defined in ObitIO.h.
 *
 * The following apply to both types of files:
 * \li "nRowPIO", OBIT_int, Max. Number of visibilities per 
 *     "Read" or "Write" operation.  Default = 1.
 *
 * \subsection TableFITS FITS files
 * This implementation uses cfitsio which allows using, in addition to 
 * regular FITS images, gzip compressed files, pipes, shared memory 
 * and a number of other input forms.
 * The convenience Macro #ObitTableCQSetFITS simplifies specifying the 
 * desired data.
 * Binary tables are used for storing visibility data in FITS.
 * For accessing FITS files the following entries in the ObitInfoList 
 * are used:
 * \li "FileName" OBIT_string (?,1,1) FITS file name.
 * \li "TabName"  OBIT_string (?,1,1) Table name (e.g. "AIPS CC").
 * \li "Ver"      OBIT_int    (1,1,1) Table version number
 *
 * subsection ObitTableCQAIPS AIPS files
 * The ObitAIPS class must be initialized before accessing AIPS files; 
 * this uses #ObitAIPSClassInit.
 * For accessing AIPS files the following entries in the ObitInfoList 
 * are used:
 * \li "Disk" OBIT_int (1,1,1) AIPS "disk" number.
 * \li "User" OBIT_int (1,1,1) user number.
 * \li "CNO"  OBIT_int (1,1,1) AIPS catalog slot number.
 * \li "TableType" OBIT_string (2,1,1) AIPS Table type
 * \li "Ver"  OBIT_int    (1,1,1) AIPS table version number.
 *
 * \section ObitTableCQaccess Creators and Destructors
 * An ObitTableCQ can be created using newObitTableCQValue which attaches the 
 * table to an ObitData for the object.  
 * If the output ObitTableCQ has previously been specified, including file information,
 * then ObitTableCQCopy will copy the disk resident as well as the memory 
 * resident information.
 *
 * A copy of a pointer to an ObitTableCQ should always be made using the
 * ObitTableCQRef function which updates the reference count in the object.
 * Then whenever freeing an ObitTableCQ or changing a pointer, the function
 * ObitTableCQUnref will decrement the reference count and destroy the object
 * when the reference count hits 0.
 *
 * \section ObitTableCQUsage I/O
 * Visibility data is available after an input object is "Opened"
 * and "Read".
 * I/O optionally uses a buffer attached to the ObitTableCQ or some external
 * location.
 * To Write an ObitTableCQ, create it, open it, and write.
 * The object should be closed to ensure all data is flushed to disk.
 * Deletion of an ObitTableCQ after its final unreferencing will automatically
 * close it.
 */

/*--------------Class definitions-------------------------------------*/

/** Number of characters for Table keyword */
 #define MAXKEYCHARTABLECQ 24

/** ObitTableCQ Class structure. */
typedef struct {
#include "ObitTableCQDef.h"   /* this class definition */
} ObitTableCQ;

/** ObitTableCQRow Class structure. */
typedef struct {
#include "ObitTableCQRowDef.h"   /* this class row definition */
} ObitTableCQRow;

/*----------------- Macroes ---------------------------*/
/** 
 * Macro to unreference (and possibly destroy) an ObitTableCQ
 * returns an ObitTableCQ*.
 * in = object to unreference
 */
#define ObitTableCQUnref(in) ObitUnref (in)

/** 
 * Macro to reference (update reference count) an ObitTableCQ.
 * returns an ObitTableCQ*.
 * in = object to reference
 */
#define ObitTableCQRef(in) ObitRef (in)

/** 
 * Macro to determine if an object is the member of this or a 
 * derived class.
 * Returns TRUE if a member, else FALSE
 * in = object to reference
 */
#define ObitTableCQIsA(in) ObitIsA (in, ObitTableCQGetClass())

/** 
 * Macro to unreference (and possibly destroy) an ObitTableCQRow
 * returns an ObitTableCQRow*.
 * in = object to unreference
 */
#define ObitTableCQRowUnref(in) ObitUnref (in)

/** 
 * Macro to reference (update reference count) an ObitTableCQRow.
 * returns an ObitTableCQRow*.
 * in = object to reference
 */
#define ObitTableCQRowRef(in) ObitRef (in)

/** 
 * Macro to determine if an object is the member of this or a 
 * derived class.
 * Returns TRUE if a member, else FALSE
 * in = object to reference
 */
#define ObitTableCQRowIsA(in) ObitIsA (in, ObitTableCQRowGetClass())

/*---------------Public functions---------------------------*/
/*----------------Table Row Functions ----------------------*/
/** Public: Row Class initializer. */
void ObitTableCQRowClassInit (void);

/** Public: Constructor. */
ObitTableCQRow* newObitTableCQRow (ObitTableCQ *table);

/** Public: ClassInfo pointer */
gconstpointer ObitTableCQRowGetClass (void);

/*------------------Table Functions ------------------------*/
/** Public: Class initializer. */
void ObitTableCQClassInit (void);

/** Public: Constructor. */
ObitTableCQ* newObitTableCQ (gchar* name);

/** Public: Constructor from values. */
ObitTableCQ* 
newObitTableCQValue (gchar* name, ObitData *file, olong *ver,
  		     ObitIOAccess access,
                     oint numIF,
		     ObitErr *err);

/** Public: Class initializer. */
void ObitTableCQClassInit (void);

/** Public: ClassInfo pointer */
gconstpointer ObitTableCQGetClass (void);

/** Public: Copy (deep) constructor. */
ObitTableCQ* ObitTableCQCopy  (ObitTableCQ *in, ObitTableCQ *out, 
			   ObitErr *err);

/** Public: Copy (shallow) constructor. */
ObitTableCQ* ObitTableCQClone (ObitTableCQ *in, ObitTableCQ *out);

/** Public: Convert an ObitTable to an ObitTableCQ */
ObitTableCQ* ObitTableCQConvert  (ObitTable *in);

/** Public: Create ObitIO structures and open file */
ObitIOCode ObitTableCQOpen (ObitTableCQ *in, ObitIOAccess access, 
			  ObitErr *err);

/** Public: Read a table row */
ObitIOCode 
ObitTableCQReadRow  (ObitTableCQ *in, olong iCQRow, ObitTableCQRow *row,
		     ObitErr *err);

/** Public: Init a table row for write */
void 
ObitTableCQSetRow  (ObitTableCQ *in, ObitTableCQRow *row,
		     ObitErr *err);

/** Public: Write a table row */
ObitIOCode 
ObitTableCQWriteRow  (ObitTableCQ *in, olong iCQRow, ObitTableCQRow *row,
		     ObitErr *err);

/** Public: Close file and become inactive */
ObitIOCode ObitTableCQClose (ObitTableCQ *in, ObitErr *err);

/*----------- ClassInfo Structure -----------------------------------*/
/**
 * ClassInfo Structure.
 * Contains class name, a pointer to any parent class
 * (NULL if none) and function pointers.
 */
typedef struct  {
#include "ObitTableCQClassDef.h"
} ObitTableCQClassInfo; 

/**
 * ClassInfo Structure For TableCQRow.
 * Contains class name, a pointer to any parent class
 * (NULL if none) and function pointers.
 */
typedef struct  {
#include "ObitTableCQRowClassDef.h"
} ObitTableCQRowClassInfo; 
#endif /* OBITTABLECQ_H */ 
