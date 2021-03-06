// --------------------------------------------------------------------------
// File:   io_bytearray.h
//
// Purpose: Routines to handle byteenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_BYTEARRAY_H_
#define _IO_BYTEARRAY_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemByteArray : virtual public CFileSystemPar,
				virtual public CFileSystemString
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

void ReadByteArray1D( std::ifstream &stream,
                unsigned int nx, BYTE *pdata );

void ReadByteArray2D( std::ifstream &stream,
                unsigned int nx, unsigned int ny, BYTE *pdata );

void ReadByteArray3D( std::ifstream &stream,
                unsigned int nx, unsigned int ny, unsigned int nz, BYTE *pdata );

// ----- Write routines -----------------------------------------------------

void WriteByteArray1D( std::ofstream &stream, unsigned int nx, BYTE *pdata );

void WriteNamedByteArray1D( std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, BYTE *pdata );

void WriteByteArray2D( std::ofstream &stream, unsigned int nx, unsigned int ny, BYTE *pdata );

void WriteNamedByteArray2D( std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, unsigned int ny, BYTE *pdata );

void WriteByteArray3D( std::ofstream &stream, unsigned int nx, unsigned int ny, unsigned int nz, BYTE *pdata );

void WriteNamedByteArray3D( std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, unsigned int ny, unsigned int nz, BYTE *pdata );

};

#endif	// _IO_BYTEARRAY_H_
