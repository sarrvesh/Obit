/* $Id$ */
/*--------------------------------------------------------------------*/
/*;  Copyright (C) 2020                                               */
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
/*;  Correspondence this software should be addressed as follows:     */
/*;         Internet email: bcotton@nrao.edu.                         */
/*;         Postal address: William Cotton                            */
/*;                         National Radio Astronomy Observatory      */
/*;                         520 Edgemont Road                         */
/*;                         Charlottesville, VA 22903-2475 USA        */
/*--------------------------------------------------------------------*/
/*  Define the basic components of the ObitUVImagerMF structure       */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitUVImagerMFDef.h
 * ObitUVImagerMF structure members for this and any derived classes.
 */
#include "ObitUVImagerDef.h"  /* Parent class definitions */
/** Secondary input UV data (U pol or Q/U pol pair)     */
ObitUV *uvdata2;
/** secondary selected/calibrated/edited/Weighted UV data to be imaged       */
ObitUV *uvwork2;
/** Secondary Image mosaic to be produced */
ObitImageMosaic *mosaic2;
/** Number of polarizations images, 1 or 2 */
olong noPolImage;
/** Which polarization being manipulated, 1 or 2 */
olong whichPol;
/** Maximum beam order Spectral index only = 1, plus curvature = 2 */
olong maxOrder;
/** Max. IF center fractional bandwidth */
ofloat maxFBW;
