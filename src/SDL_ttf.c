/*
 * SDL library: SDL.c
 * version 2.0.18
 *
 * Copyright 2022 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsdl_ttf.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* TTF_Font */
static HB_GARBAGE_FUNC( hb_font_Destructor )
{
   TTF_Font ** ppFont = ( TTF_Font ** ) Cargo;

   if( * ppFont )
   {
      TTF_Font * pFont = * ppFont;
      * ppFont = NULL;
      TTF_CloseFont( pFont );
   }
}

static const HB_GC_FUNCS s_gcFontFuncs =
{
   hb_font_Destructor,
   hb_gcDummyMark
};

TTF_Font * hb_font_Param( int iParam )
{
   TTF_Font ** ppFont = ( TTF_Font ** ) hb_parptrGC( &s_gcFontFuncs, iParam );

   if( ppFont && * ppFont )
   {
      return * ppFont;
   }

   HB_ERR_ARGS();
   return NULL;
}

PHB_ITEM hb_font_ItemPut( PHB_ITEM pItem, TTF_Font * pFont )
{
   TTF_Font ** ppFont = ( TTF_Font ** ) hb_gcAllocate( sizeof( TTF_Font * ), &s_gcFontFuncs );
   * ppFont = pFont;
   return hb_itemPutPtrGC( pItem, ppFont );
}

void hb_font_Return( TTF_Font * pFont )
{
   if( pFont )
   {
      hb_font_ItemPut( hb_param( -1, HB_IT_ANY ), pFont );
   }
   else
   {
      hb_ret();
   }
}

// extern DECLSPEC const SDL_version * SDLCALL TTF_Linked_Version(void);
// extern DECLSPEC void SDLCALL TTF_GetFreeTypeVersion(int *major, int *minor, int *patch);
// extern DECLSPEC void SDLCALL TTF_GetHarfBuzzVersion(int *major, int *minor, int *patch);
// extern DECLSPEC void SDLCALL TTF_ByteSwappedUNICODE(SDL_bool swapped);

// extern DECLSPEC int SDLCALL TTF_Init(void);
HB_FUNC( TTF_INIT )
{
   hb_retni( TTF_Init() );
}

// extern DECLSPEC TTF_Font * SDLCALL TTF_OpenFont(const char *file, int ptsize);
HB_FUNC( TTF_OPENFONT )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_font_Return( TTF_OpenFont( hb_parc( 1 ), hb_parni( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// extern DECLSPEC TTF_Font * SDLCALL TTF_OpenFontIndex(const char *file, int ptsize, long index);
// extern DECLSPEC TTF_Font * SDLCALL TTF_OpenFontRW(SDL_RWops *src, int freesrc, int ptsize);
// extern DECLSPEC TTF_Font * SDLCALL TTF_OpenFontIndexRW(SDL_RWops *src, int freesrc, int ptsize, long index);
// extern DECLSPEC TTF_Font * SDLCALL TTF_OpenFontDPI(const char *file, int ptsize, unsigned int hdpi, unsigned int vdpi);
// extern DECLSPEC TTF_Font * SDLCALL TTF_OpenFontIndexDPI(const char *file, int ptsize, long index, unsigned int hdpi, unsigned int vdpi);
// extern DECLSPEC TTF_Font * SDLCALL TTF_OpenFontDPIRW(SDL_RWops *src, int freesrc, int ptsize, unsigned int hdpi, unsigned int vdpi);
// extern DECLSPEC TTF_Font * SDLCALL TTF_OpenFontIndexDPIRW(SDL_RWops *src, int freesrc, int ptsize, long index, unsigned int hdpi, unsigned int vdpi);
// extern DECLSPEC int SDLCALL TTF_SetFontSize(TTF_Font *font, int ptsize);
// extern DECLSPEC int SDLCALL TTF_SetFontSizeDPI(TTF_Font *font, int ptsize, unsigned int hdpi, unsigned int vdpi);
// extern DECLSPEC int SDLCALL TTF_GetFontStyle(const TTF_Font *font);
// extern DECLSPEC void SDLCALL TTF_SetFontStyle(TTF_Font *font, int style);
// extern DECLSPEC int SDLCALL TTF_GetFontOutline(const TTF_Font *font);
// extern DECLSPEC void SDLCALL TTF_SetFontOutline(TTF_Font *font, int outline);
// extern DECLSPEC int SDLCALL TTF_GetFontHinting(const TTF_Font *font);
// extern DECLSPEC void SDLCALL TTF_SetFontHinting(TTF_Font *font, int hinting);
// extern DECLSPEC int SDLCALL TTF_FontHeight(const TTF_Font *font);
// extern DECLSPEC int SDLCALL TTF_FontAscent(const TTF_Font *font);
// extern DECLSPEC int SDLCALL TTF_FontDescent(const TTF_Font *font);
// extern DECLSPEC int SDLCALL TTF_FontLineSkip(const TTF_Font *font);
// extern DECLSPEC int SDLCALL TTF_GetFontKerning(const TTF_Font *font);
// extern DECLSPEC void SDLCALL TTF_SetFontKerning(TTF_Font *font, int allowed);
// extern DECLSPEC long SDLCALL TTF_FontFaces(const TTF_Font *font);
// extern DECLSPEC int SDLCALL TTF_FontFaceIsFixedWidth(const TTF_Font *font);
// extern DECLSPEC char * SDLCALL TTF_FontFaceFamilyName(const TTF_Font *font);
// extern DECLSPEC char * SDLCALL TTF_FontFaceStyleName(const TTF_Font *font);
// extern DECLSPEC int SDLCALL TTF_GlyphIsProvided(TTF_Font *font, Uint16 ch);
// extern DECLSPEC int SDLCALL TTF_GlyphIsProvided32(TTF_Font *font, Uint32 ch);
// extern DECLSPEC int SDLCALL TTF_GlyphMetrics(TTF_Font *font, Uint16 ch, int *minx, int *maxx, int *miny, int *maxy, int *advance);
// extern DECLSPEC int SDLCALL TTF_GlyphMetrics32(TTF_Font *font, Uint32 ch, int *minx, int *maxx, int *miny, int *maxy, int *advance);
// extern DECLSPEC int SDLCALL TTF_SizeText(TTF_Font *font, const char *text, int *w, int *h);
// extern DECLSPEC int SDLCALL TTF_SizeUTF8(TTF_Font *font, const char *text, int *w, int *h);
// extern DECLSPEC int SDLCALL TTF_SizeUNICODE(TTF_Font *font, const Uint16 *text, int *w, int *h);
// extern DECLSPEC int SDLCALL TTF_MeasureText(TTF_Font *font, const char *text, int measure_width, int *extent, int *count);
// extern DECLSPEC int SDLCALL TTF_MeasureUTF8(TTF_Font *font, const char *text, int measure_width, int *extent, int *count);
// extern DECLSPEC int SDLCALL TTF_MeasureUNICODE(TTF_Font *font, const Uint16 *text, int measure_width, int *extent, int *count);

// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderText_Solid(TTF_Font *font, const char *text, SDL_Color fg);
HB_FUNC( TTF_RENDERTEXT_SOLID )
{
   TTF_Font * font = hb_font_Param( 1 );
   PHB_ITEM pItem;

   if( font && hb_param( 2, HB_IT_STRING ) != NULL &&
     ( pItem = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      SDL_Color fg;

      fg.r = ( Uint8 ) hb_arrayGetNI( pItem, 1 );
      fg.g = ( Uint8 ) hb_arrayGetNI( pItem, 2 );
      fg.b = ( Uint8 ) hb_arrayGetNI( pItem, 3 );
      fg.a = ( Uint8 ) hb_arrayGetNI( pItem, 4 );

      hb_surface_Return( TTF_RenderText_Solid( font, hb_parc( 2 ), fg ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUTF8_Solid(TTF_Font *font, const char *text, SDL_Color fg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUNICODE_Solid(TTF_Font *font, const Uint16 *text, SDL_Color fg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderText_Solid_Wrapped(TTF_Font *font, const char *text, SDL_Color fg, Uint32 wrapLength);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUTF8_Solid_Wrapped(TTF_Font *font, const char *text, SDL_Color fg, Uint32 wrapLength);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUNICODE_Solid_Wrapped(TTF_Font *font, const Uint16 *text, SDL_Color fg, Uint32 wrapLength);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderGlyph_Solid(TTF_Font *font, Uint16 ch, SDL_Color fg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderGlyph32_Solid(TTF_Font *font, Uint32 ch, SDL_Color fg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderText_Shaded(TTF_Font *font, const char *text, SDL_Color fg, SDL_Color bg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUTF8_Shaded(TTF_Font *font, const char *text, SDL_Color fg, SDL_Color bg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUNICODE_Shaded(TTF_Font *font, const Uint16 *text, SDL_Color fg, SDL_Color bg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderText_Shaded_Wrapped(TTF_Font *font, const char *text, SDL_Color fg, SDL_Color bg, Uint32 wrapLength);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUTF8_Shaded_Wrapped(TTF_Font *font, const char *text, SDL_Color fg, SDL_Color bg, Uint32 wrapLength);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUNICODE_Shaded_Wrapped(TTF_Font *font, const Uint16 *text, SDL_Color fg, SDL_Color bg, Uint32 wrapLength);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderGlyph_Shaded(TTF_Font *font, Uint16 ch, SDL_Color fg, SDL_Color bg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderGlyph32_Shaded(TTF_Font *font, Uint32 ch, SDL_Color fg, SDL_Color bg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderText_Blended(TTF_Font *font, const char *text, SDL_Color fg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUTF8_Blended(TTF_Font *font, const char *text, SDL_Color fg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUNICODE_Blended(TTF_Font *font, const Uint16 *text, SDL_Color fg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderText_Blended_Wrapped(TTF_Font *font, const char *text, SDL_Color fg, Uint32 wrapLength);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUTF8_Blended_Wrapped(TTF_Font *font, const char *text, SDL_Color fg, Uint32 wrapLength);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUNICODE_Blended_Wrapped(TTF_Font *font, const Uint16 *text, SDL_Color fg, Uint32 wrapLength);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderGlyph_Blended(TTF_Font *font, Uint16 ch, SDL_Color fg);
// extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderGlyph32_Blended(TTF_Font *font, Uint32 ch, SDL_Color fg);
// extern DECLSPEC int SDLCALL TTF_SetDirection(int direction); /* hb_direction_t */
// extern DECLSPEC int SDLCALL TTF_SetScript(int script); /* hb_script_t */

// extern DECLSPEC void SDLCALL TTF_CloseFont(TTF_Font *font);
HB_FUNC( TTF_CLOSEFONT )
{
   TTF_Font ** ppFont = ( TTF_Font ** ) hb_parptrGC( &s_gcFontFuncs, 1 );

   if( ppFont && *ppFont )
   {
      TTF_CloseFont( *ppFont );
      *ppFont = NULL;
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// extern DECLSPEC void SDLCALL TTF_Quit(void);
HB_FUNC( TTF_QUIT )
{
	TTF_Quit();
}

// extern DECLSPEC int SDLCALL TTF_WasInit(void);
HB_FUNC( TTF_WASINIT )
{
	hb_retni( TTF_WasInit() );
}

// extern DECLSPEC int TTF_GetFontKerningSize(TTF_Font *font, int prev_index, int index) SDL_DEPRECATED;
// extern DECLSPEC int TTF_GetFontKerningSizeGlyphs(TTF_Font *font, Uint16 previous_ch, Uint16 ch);
// extern DECLSPEC int TTF_GetFontKerningSizeGlyphs32(TTF_Font *font, Uint32 previous_ch, Uint32 ch);
// extern DECLSPEC int TTF_SetFontSDF(TTF_Font *font, SDL_bool on_off);
// extern DECLSPEC SDL_bool TTF_GetFontSDF(const TTF_Font *font);
