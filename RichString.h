/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_RichString
#define HEADER_RichString


#ifndef CONFIG_H
#define CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "debug.h"
#include <assert.h>
#ifdef HAVE_NCURSESW_CURSES_H
#include <ncursesw/curses.h>
#elif HAVE_NCURSES_NCURSES_H
#include <ncurses/ncurses.h>
#elif HAVE_NCURSES_H
#include <ncurses.h>
#elif HAVE_CURSES_H
#include <curses.h>
#endif

#define RICHSTRING_MAXLEN 300


#define RichString_size(this) ((this)->chlen)
#define RichString_sizeVal(this) ((this).chlen)

#define RichString_begin(this) RichString (this); (this).chlen = 0; (this).chptr = (this).chstr;
#define RichString_beginAllocated(this) (this).chlen = 0; (this).chptr = (this).chstr;
#define RichString_end(this) RichString_prune(&(this));

#ifdef HAVE_LIBNCURSESW
#define RichString_printVal(this, y, x) mvadd_wchstr(y, x, (this).chptr)
#define RichString_printoffnVal(this, y, x, off, n) mvadd_wchnstr(y, x, (this).chptr + off, n)
#define RichString_getCharVal(this, i) ((this).chptr[i].chars[0] & 255)
#define RichString_setChar(this, at, ch) do{ (this)->chptr[(at)].chars[0] = ch; } while(0)
#define CharType cchar_t
#else
#define RichString_printVal(this, y, x) mvaddchstr(y, x, (this).chptr)
#define RichString_printoffnVal(this, y, x, off, n) mvaddchnstr(y, x, (this).chptr + off, n)
#define RichString_getCharVal(this, i) ((this).chptr[i])
#define RichString_setChar(this, at, ch) do{ (this)->chptr[(at)] = ch; } while(0)
#define CharType chtype
#endif

typedef struct RichString_ {
   int chlen;
   CharType chstr[RICHSTRING_MAXLEN+1];
   CharType* chptr;
} RichString;


#ifndef MIN
#define MIN(a,b) ((a)<(b)?(a):(b))
#endif

#define charBytes(n) (sizeof(CharType) * (n)) 

#ifdef HAVE_LIBNCURSESW

extern void RichString_appendn(RichString* this, int attrs, const char* data_c, int len);

extern void RichString_setAttrn(RichString* this, int attrs, int start, int finish);

int RichString_findChar(RichString* this, char c, int start);

#else

extern void RichString_appendn(RichString* this, int attrs, const char* data_c, int len);

void RichString_setAttrn(RichString* this, int attrs, int start, int finish);

int RichString_findChar(RichString* this, char c, int start);

#endif

void RichString_prune(RichString* this);

void RichString_setAttr(RichString* this, int attrs);

extern void RichString_append(RichString* this, int attrs, const char* data);

void RichString_write(RichString* this, int attrs, const char* data);

#endif
