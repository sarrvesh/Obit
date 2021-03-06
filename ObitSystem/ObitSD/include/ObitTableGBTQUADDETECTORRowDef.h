/* $Id:  $  */
/* DO NOT EDIT - file generated by ObitSDTables.pl                    */
/*--------------------------------------------------------------------*/
/*;  Copyright (C)  2009                                              */
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
/*  Define the basic components of the ObitTableSNRow structure       */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableGBTQUADDETECTORRowDef.h
 * ObitTableGBTQUADDETECTORRow structure members for derived classes.
 */
#include "ObitTableRowDef.h"  /* Parent class definitions */
/** Modified Julian Date of time sample taken; */
odouble  dmjd;
/** Channel 1 raw voltage */
ofloat  ch1Voltage;
/** Channel 3 raw voltage */
ofloat  ch3Voltage;
/** Channel 4 raw voltage */
ofloat  ch4Voltage;
/** Channel 5 raw voltage */
ofloat  ch5Voltage;
/** Calculated feed-arm motion in the X Axis, in arcseconds */
ofloat  X_Axis;
/** Calculated feed-arm motion in the Z Axis, in arcseconds */
ofloat  Z_Axis;
/** Sample time-stamp for channel 1 data, as MJD */
odouble  T1;
/** Sample time-stamp for channel 3 data, as MJD */
odouble  T3;
/** Sample time-stamp for channel 4 data, as MJD */
odouble  T4;
/** Sample time-stamp for channel 5 data, as MJD */
odouble  T5;
/** Median estimate of GDAQ clock offset */
odouble  MedianClockOffset;
/** status 0=normal, 1=modified, -1=flagged */
olong  status;
