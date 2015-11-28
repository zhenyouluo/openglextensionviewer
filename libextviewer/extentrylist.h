// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _EXTLIST_
#define _EXTLIST_

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define LIST_SORTNAME           0x0000
#define LIST_SORTVALUE          0x0001
#define LIST_SORTPREFIX         0x0002
#define LIST_SORTREVERSED       0x8000

#define LIST_SORTNAMEREVERSED   (LIST_SORTNAME  |LIST_SORTREVERSED)
#define LIST_SORTVALUEREVERSED  (LIST_SORTVALUE |LIST_SORTREVERSED)
#define LIST_SORTPREFIXREVERSED (LIST_SORTPREFIX|LIST_SORTREVERSED)

#define SEARCH_CONSTANTS       0x0001
#define SEARCH_FUNCTIONS       0x0002

#define MATCH_BEGINNING 0x0001
#define MATCH_EXACTLY   0x0002
#define MATCH_SUBSTRING 0x0003

/*
#define LIST_GL                 0x0100
#define LIST_WGL                0x0101
*/

// ----- Match modes required for adding extension strings ------------------
/*
#define MATCH_EXACTLY   0x001
#define MATCH_BEGINNING 0x002
#define MATCH_SUBSTRING 0x003
*/
// ----- Update modes required for updating lists ---------------------------

#define UPDATE_NONE     0x000
#define UPDATE_NEWLIST  0x001

// --------------------------------------------------------------------------
// Class used for the storage of lists of extensions, functions and constants
// --------------------------------------------------------------------------

class CExtensionEntryList : virtual public CExtensionEntryListIO,
			virtual public TSortFuncs< CExtensionEntry>
{
public:

int              m_sortmode; // List sorting mode
string           m_listname; // Name of list

// ----- Constructor and destructor -----------------------------------------

CExtensionEntryList( void ) 
	{ 
	Init(); 
	};

~CExtensionEntryList( void ) 
	{ 
	Deallocate(); 
	};

// ----- Functions and procedures -------------------------------------------

void Init( void );

void Allocate( int num )
	{
	reserve(num);
	}

void Deallocate( void )
	{
	clear();
	}

void Duplicate( const CExtensionEntryList &src )
	{
	*this = src;	
	}

void SetListName( const char *pname )
        {
        m_listname = pname;
        };

void SetListName( const string &name )
        {
        m_listname = name;
        };

string &GetListName( void )
        {
        return( m_listname );
        };

int  FindName(     const string &pname );
int  FindFullName( const char *pname );
int  FindValue(  const char *pvalue );
int  FindProc(   const string &pproc );

int  Add( const string &name );
int  AddStart( const string &name, int funcstart, int conststart );

int  Add( const char *name );
int  AddNameValue( const char *name, const char *value );

void AddProtoVars( const char *pchptra, const char *pchptrc );
int  AddPrefixNameValue( const char *prefix, const char *name,
			const char *header );

int  AddPrefixNameValue( const string &prefix, const string &name, 
                         const string &header );

int  AddPrefixNameValueProto( const string &prefix, const string &name, 
                              const string &header, const string &proto );

void DeleteIndex(  unsigned int index );
int  DeleteName(  const string &name );
void DeleteRange( int start, int num );

void SetAllFlags(     int mode );
void ClearAllFlags(   int mode );
int  ClearNameFlag(   const string &name, int mode );
int  GetNameFlag(     const string &name, int mode );
int  SetNameFlag(     const string &name, int mode );
int  SetFullNameFlag( const string &name, int flag, int matchmode );
int  ClearFullNameFlag(const string &name, int flag, int matchmode );
int  ToggleNameFlag(  const string &name, int mode );
void SetIndexFlag(    unsigned int idno, int mode );
int  GetIndexFlag(    unsigned int idno, int mode );
void ClearIndexFlag(  unsigned int idno, int mode );
void ToggleIndexFlag( unsigned int idno, int mode );

void SaveState( void );
void UndoState( void );
void RedoState( void );

void SelectByName( const string &name );
void RemoveName( const string &name );
void ToggleSortMode( int mode );
void SortRange( int start, int num );

static int SortByName(           CExtensionEntry const &ptra, CExtensionEntry const &ptrb );
static int SortByNameReversed(   CExtensionEntry const &ptra, CExtensionEntry const &ptrb );
static int SortByValue(          CExtensionEntry const &ptra, CExtensionEntry const &ptrb );
static int SortByValueReversed(  CExtensionEntry const &ptra, CExtensionEntry const &ptrb );
static int SortByPrefix(         CExtensionEntry const &ptra, CExtensionEntry const &ptrb );
static int SortByPrefixReversed( CExtensionEntry const &ptra, CExtensionEntry const &ptrb );

void SetSortMode( int mode )
    {
    m_sortmode = mode;
    }

void Sort( void )
    {
    SortRange( 0, size() );
    }

int GetCount( void ) 
    {
    return( size() );
    };

void ResetConstEntry( int pos, int start, int num )
    {
    at(pos).m_conststart = start;
    at(pos).m_constnum   = num;
    };

void ResetFuncEntry( int pos, int start, int num )
    {
    at(pos).m_funcstart = start;
    at(pos).m_funcnum   = num;
    };

void IncrementConstNum( int pos )
    {
    at(pos).m_constnum++;
    };

void IncrementFuncNum( int pos )
    {
    at(pos).m_funcnum++;
    };

void AddExtensionString( const string &pextstring );
void RemoveExtensionString( const string &pextstring );

void SelectExtensionString( const string &pextstring, 
			CExtensionEntryList &ignorelist, 
			CExtensionEntryList &newlist, 
			int mode, int matchmode, int updatemode );

void UnselectExtensionString( const string &pextstring,
			int mode, int matchmode );

void SearchConstants( const string &string,
                        CHeaderFileDataSearchCallback &callback );

void SearchFunctions( const string &string,
                        CHeaderFileDataSearchCallback &callback );

void SearchString( int mode, const string &string, 
			CHeaderFileDataSearchCallback &callback );

};

#endif // _EXTLIST_
