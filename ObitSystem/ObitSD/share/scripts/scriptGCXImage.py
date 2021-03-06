# Program to make an image from OTF data and CLEAN it
import OTF, Image, OErr, OSystem

# Init Obit
err=OErr.OErr()
ObitSys=OSystem.OSystem  ("Python", 1, 103, 1, ["None"], 1, ["../PythonData/"], 1, 0, err)
OErr.printErrMsg(err, "Error with Obit startup")

# Files
disk = 1
inFile   = "GCXbandCalOTF.fits "        # input OTF data
dirtFile = "!GCXTest.fits"              # output dirty image file
beamFile = "DirtyBeam.fits"             # input dirty beam image
#cleanFile= "!GCXXClean.fits"            # output CLEAN image

# Set data
inData = OTF.newPOTF("Input data", inFile, disk, 1, err)
OErr.printErrMsg(err, "Error creating input data object")

# Imaging parameters
OTF.ImageInput["InData"]  = inData
OTF.ImageInput["disk"]    = disk
OTF.ImageInput["OutName"] = dirtFile
OTF.ImageInput["ra"]  = 265.00           # Center RA
OTF.ImageInput["dec"] = -28.75          # Center Dec
OTF.ImageInput["xCells"] = 20.0 / 3600.0   # "X" cell spacing, deg
OTF.ImageInput["yCells"] = 20.0 / 3600.0   # "Y" cell spacing, deg
OTF.ImageInput["nx"] = 1000                # number of cells in X
OTF.ImageInput["ny"] = 1000                # number of cells in X
OTF.ImageInput["gainuse"] = 0              # Which cal table to apply, -1 = none
OTF.ImageInput["flagver"] = -1             # Which flag table to apply, -1 = none


# Make image
OTF.input(OTF.ImageInput)
Dirty = OTF.makeImage(err)

# Shutdown Obit
OErr.printErr(err)
