/* $Id$ */
/*--------------------------------------------------------------------*/
/*;  Copyright (C) 2008-2019                                          */
/*;  Associated Universities, Inc. Washington DC, USA.                */
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
/*;         Internet email: bcotton@nrao.edu.                         */
/*;         Postal address: William Cotton                            */
/*;                         National Radio Astronomy Observatory      */
/*;                         520 Edgemont Road                         */
/*;                         Charlottesville, VA 22903-2475 USA        */
/*--------------------------------------------------------------------*/
/*  Define the basic components of the ObitBeamShape structure         */
/*  This is intended to be included in a class structure definition   */
/* and to be used as the template for generating new classes derived  */
/* from Obit.                                                         */
/**
 * \file ObitBeamShapeDef.h
 * ObitBeamShape structure members for this and any derived classes.
 */
#include "ObitDef.h"  /* Parent class instance definitions */
/** Gain wanted? */
gboolean doGain;
/** Use Jinc or polynomial */
gboolean doJinc;
/** Use Tabulated beam */
gboolean doTab;
/** Use VLITE beam */
gboolean doVLITE;
/** Use MeerKAT beam */
gboolean doMeerKAT;
/** Minimum desired gain */
ofloat pbmin;
/** Antenna diameter (m) */
ofloat antSize;
/** Beam angle (deg) */
ofloat beamAng;
/** Antenna pointing position (rad)*/
odouble raPnt, decPnt;
/** Reference Frequency */
odouble refFreq;
/** 1/Tabulated reference Frequency */
odouble itabRefFreq;
/** 1/Cell size of tabulated beam (deg) */
odouble icellSize;
/** Image descriptor */
ObitImageDesc *myDesc;
/** Interpolator for tabulated Beam */
ObitFInterpolate *myFI;
