/*
 *
 */

#include "hbsdl_ttf.ch"

PROCEDURE Main()

   LOCAL lQuit := .F.
   LOCAL pWindow
   LOCAL pRenderer
   LOCAL pOpenFont
   LOCAL pSurfaceText
   LOCAL pTextureText
   LOCAL aRectangle := { 0, 0, 400, 100 }
   LOCAL nEvent

   IF( SDL_Init( SDL_INIT_VIDEO ) != 0 )
      OutStd( e"Unable to initialize SDL: \n", SDL_GetError() )
      RETURN
   ENDIF

   pWindow := SDL_CreateWindow( "Harbour development", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 720, 450, 0 ) // 6 param SDL_WINDOW_SHOWN
   IF( pWindow == NIL )
      OutStd( e"Could not create Window: \n", SDL_GetError() )
      RETURN
   ENDIF

   pRenderer := SDL_CreateRenderer( pWindow, - 1, 0 )
   IF( pRenderer == NIL )
      OutStd( e"Could not create Renderer: \n", SDL_GetError() )
      RETURN
   ENDIF

   IF( TTF_Init() == -1 )
      OutStd( e"Could not create SDL2_ttf: \n", SDL_GetError() )
      RETURN
   ENDIF

   pOpenFont := TTF_OpenFont( "./fonts/LinLibertine_R.ttf", 96 )
   IF( pOpenFont == NIL )
      OutStd( e"Could not create Font: \n", SDL_GetError() )
      RETURN
   ENDIF

   pSurfaceText := TTF_RenderText_Solid( pOpenFont, "Harbour", { 255, 255, 255, 255 } )

   pTextureText := SDL_CreateTextureFromSurface( pRenderer, pSurfaceText )

   SDL_FreeSurface( pSurfaceText )

   DO WHILE( ! lQuit )

      SDL_WaitEvent( @nEvent )

      SWITCH( nEvent )

      CASE SDL_QUIT
         lQuit := .T.
         EXIT

      ENDSWITCH

      SDL_SetRenderDrawColor( pRenderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE )
      SDL_RenderClear( pRenderer )
      SDL_RenderCopy( pRenderer, pTextureText, { 0, 0, 400, 100 }, aRectangle )
      SDL_RenderPresent( pRenderer )

   ENDDO

   SDL_DestroyTexture( pTextureText )
   TTF_CloseFont( pOpenFont )
   TTF_Quit()
   SDL_DestroyRenderer( pRenderer )
   SDL_DestroyWindow( pWindow )
   SDL_Quit()

   RETURN
