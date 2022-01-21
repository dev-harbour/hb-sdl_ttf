
#ifndef HBSDL_TTF_CH_
#define HBSDL_TTF_CH_

/* ZERO WIDTH NO-BREAKSPACE (Unicode byte order mark) */
#define UNICODE_BOM_NATIVE  0xFEFF
#define UNICODE_BOM_SWAPPED 0xFFFE

/* Set and retrieve the font style. Setting the style clears already generated glyphs, if any, from the cache. */
#define TTF_STYLE_NORMAL        0x00
#define TTF_STYLE_BOLD          0x01
#define TTF_STYLE_ITALIC        0x02
#define TTF_STYLE_UNDERLINE     0x04
#define TTF_STYLE_STRIKETHROUGH 0x08

/* Set and retrieve FreeType hinter settings. Setting it clears already generated glyphs, if any, from the cache. */
#define TTF_HINTING_NORMAL          0
#define TTF_HINTING_LIGHT           1
#define TTF_HINTING_MONO            2
#define TTF_HINTING_NONE            3
#define TTF_HINTING_LIGHT_SUBPIXEL  4

/* For compatibility with previous versions, here are the old functions */
// #define TTF_RenderText(font, text, fg, bg)  \
//     TTF_RenderText_Shaded(font, text, fg, bg)
// #define TTF_RenderUTF8(font, text, fg, bg)  \
//     TTF_RenderUTF8_Shaded(font, text, fg, bg)
// #define TTF_RenderUNICODE(font, text, fg, bg)   \
//     TTF_RenderUNICODE_Shaded(font, text, fg, bg)

/* We'll use SDL for reporting errors */
#define TTF_SetError    SDL_SetError
#define TTF_GetError    SDL_GetError

#endif /* HBSDL_TTF_CH_ */
