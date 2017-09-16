//////////////////////////////////////////////////////////////////////
// (c) Janusz Ganczarski
// http://www.januszg.hg.pl
// JanuszG@enter.net.pl
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "materials.h"
#include <glm/vec4.hpp>

//////////////////////////////////////////////////////////////////////
// deklaracje funkcji obs³uguj¹cych rendering w OpenGL
//////////////////////////////////////////////////////////////////////
void DisplayScene();
void Reshape( int width, int height );
void InitScene();
void DeleteScene();

//////////////////////////////////////////////////////////////////////
// zmienne niezbêdne do obs³ugi ruchu myszy i klawiatury
//////////////////////////////////////////////////////////////////////
extern GLfloat left;
extern GLfloat right;
extern GLfloat bottom;
extern GLfloat top;
extern GLfloat scale;
extern GLfloat rotateX;
extern GLfloat rotateY;
extern GLfloat translateX;
extern GLfloat translateY;
extern int material;
extern glm::vec4 lightPosition;
extern bool generateMap;
extern GLenum textureFilter;
extern int depthMap;
extern int renderMode;
extern int shadowMode;

//////////////////////////////////////////////////////////////////////
// wskaŸnik naciœniêcia lewego przycisku myszy
//////////////////////////////////////////////////////////////////////
int buttonState = GLUT_UP;

//////////////////////////////////////////////////////////////////////
// po³o¿enie kursora myszy
//////////////////////////////////////////////////////////////////////
int buttonX, buttonY;

//////////////////////////////////////////////////////////////////////
// obs³uga przycisków myszy
//////////////////////////////////////////////////////////////////////
void MouseButton( int button, int state, int x, int y )
{
    if( button == GLUT_LEFT_BUTTON )
    {
        // zapamiêtanie stanu lewego przycisku myszy
        buttonState = state;

        // zapamiêtanie po³o¿enia kursora myszy
        if( state == GLUT_DOWN )
        {
            buttonX = x;
            buttonY = y;
        }
    }
}

//////////////////////////////////////////////////////////////////////
// obs³uga ruchu kursora myszy
//////////////////////////////////////////////////////////////////////
void MouseMotion( int x, int y )
{
    if( buttonState == GLUT_DOWN )
    {
        rotateY += 30 *(right - left) / glutGet( GLUT_WINDOW_WIDTH ) * (x - buttonX);
        buttonX = x;
        rotateX -= 30 *(top - bottom) / glutGet( GLUT_WINDOW_HEIGHT ) * (buttonY - y);
        buttonY = y;
        generateMap = true;
        glutPostRedisplay();
    }
}

//////////////////////////////////////////////////////////////////////
// obs³uga klawiatury
//////////////////////////////////////////////////////////////////////
void Keyboard( unsigned char key, int x, int y )
{
    switch( key )
    {
        // klawisz +
        case '+':
            scale += 0.03f;
            generateMap = true;
            break;
        // klawisz -
        case '-':
            if( scale > 0.03f )
            {
                scale -= 0.03f;
                generateMap = true;
            }
            break;
        // q
        case 'Q':
        case 'q':
            lightPosition[0] += 0.1f;
            generateMap = true;
            break;
        // a
        case 'A':
        case 'a':
            lightPosition[0] -= 0.1f;
            generateMap = true;
            break;
        // w
        case 'W':
        case 'w':
            lightPosition[1] += 0.1f;
            generateMap = true;
            break;
        // s
        case 'S':
        case 's':
            lightPosition[1] -= 0.1f;
            generateMap = true;
            break;
        // e
        case 'E':
        case 'e':
            lightPosition[2] += 0.1f;
            generateMap = true;
            break;
        // d
        case 'D':
        case 'd':
            lightPosition[2] -= 0.1f;
            generateMap = true;
            break;
    }

    // odrysowanie okna
    glutPostRedisplay();
}

//////////////////////////////////////////////////////////////////////
// obs³uga klawiszy funkcyjnych i klawiszy kursora
//////////////////////////////////////////////////////////////////////
void SpecialKeys( int key, int x, int y )
{
    switch( key )
    {
        // kursor w lewo
        case GLUT_KEY_LEFT:
            translateX -= 0.03f;
            generateMap = true;
            break;

        // kursor w górê
        case GLUT_KEY_UP:
            translateY += 0.03f;
            generateMap = true;
            break;

        // kursor w prawo
        case GLUT_KEY_RIGHT:
            translateX += 0.03f;
            generateMap = true;
            break;

        // kursor w dó³
        case GLUT_KEY_DOWN:
            translateY -= 0.03f;
            generateMap = true;
            break;

        // nastêpny materia³
        case GLUT_KEY_PAGE_DOWN:
            if( material < MTL_YELLOW_RUBBER )
                material = material + 1;
            else
                material = MTL_DEFAULT;
            break;

        // poprzedni materia³
        case GLUT_KEY_PAGE_UP:
            if( material > MTL_DEFAULT )
                material = material - 1;
            else
                material = MTL_YELLOW_RUBBER;
            break;
    }

    // odrysowanie okna
    glutPostRedisplay();
}

//////////////////////////////////////////////////////////////////////
// sta³e do obs³ugi menu kontekstowego
//////////////////////////////////////////////////////////////////////
enum
{
    // rendering sceny
    RENDER_SCENE,

    // rendering mapy cieni
    RENDER_SHADOW_MAP,

    // filtr powiêkszaj¹cy/pomniejszaj¹cy tekstury g³êbokoœci
    MIN_MAX_FILTER_NEAREST,
    MIN_MAX_FILTER_LINEAR,

    // rozmiar mapy cienia
    FRAME_BUFFER_256_256,
    FRAME_BUFFER_512_512,
    FRAME_BUFFER_1024_1024,
    FRAME_BUFFER_2048_2048,

    // filtracja mapy cienia
    SHADOW_MAP_STD = 50,
    SHADOW_MAP_PCF_3X3_AVERAGE,
    SHADOW_MAP_PCF_3X3_GAUSS,
    SHADOW_MAP_PCF_5X5_AVERAGE,
    SHADOW_MAP_PCF_5X5_GAUSS,
    SHADOW_MAP_PCF_5X5_RANDOM,
    SHADOW_MAP_PCF_5X5_POISSON,

    EXIT       // wyjœcie
};

//////////////////////////////////////////////////////////////////////
// obs³uga menu kontekstowego
//////////////////////////////////////////////////////////////////////
void Menu( int value )
{
    switch( value )
    {
        // rendering sceny
        case RENDER_SCENE:
            renderMode = RENDER_SCENE;
            break;

        // rendering mapy cieni
        case RENDER_SHADOW_MAP:
            renderMode = RENDER_SHADOW_MAP;
            break;

        // filtr powiêkszaj¹cy/pomniejszaj¹cy tekstury g³êbokoœci
        case MIN_MAX_FILTER_NEAREST:
            textureFilter = GL_NEAREST;
            break;
        case MIN_MAX_FILTER_LINEAR:
            textureFilter = GL_LINEAR;
            break;

        // rozmiar mapy cienia
        case FRAME_BUFFER_256_256:
        case FRAME_BUFFER_512_512:
        case FRAME_BUFFER_1024_1024:
        case FRAME_BUFFER_2048_2048:
            depthMap = value - FRAME_BUFFER_256_256;
            generateMap = true;
            break;

        // filtracja mapy cienia
        case SHADOW_MAP_STD:
        case SHADOW_MAP_PCF_3X3_AVERAGE:
        case SHADOW_MAP_PCF_3X3_GAUSS:
        case SHADOW_MAP_PCF_5X5_AVERAGE:
        case SHADOW_MAP_PCF_5X5_GAUSS:
        case SHADOW_MAP_PCF_5X5_RANDOM:
        case SHADOW_MAP_PCF_5X5_POISSON:
            shadowMode = value - SHADOW_MAP_STD + 3;
            break;

        // materia³
        case MTL_DEFAULT + 10:              // materia³ domyœlny
        case MTL_BRASS + 10:                // mosi¹dz
        case MTL_BRONZE + 10:               // br¹z
        case MTL_POLISHED_BRONZE + 10:      // polerowany br¹z
        case MTL_CHROME + 10:               // chrom
        case MTL_COPPER + 10:               // miedŸ
        case MTL_POLISHED_COPPER + 10:      // polerowana miedŸ
        case MTL_GOLD + 10:                 // z³oto
        case MTL_POLISHED_GOLD + 10:        // polerowane z³oto
        case MTL_PEWTER + 10:               // grafit (cyna z o³owiem)
        case MTL_SILVER + 10:               // srebro
        case MTL_POLISHED_SILVER + 10:      // polerowane srebro
        case MTL_EMERALD + 10:              // szmaragd
        case MTL_JADE + 10:                 // jadeit
        case MTL_OBSIDIAN + 10:             // obsydian
        case MTL_PEARL + 10:                // per³a
        case MTL_RUBY + 10:                 // rubin
        case MTL_TURQUOISE + 10:            // turkus
        case MTL_BRIGHT_WHITE + 10:         // jasny bia³y
        case MTL_LESS_BRIGHT_WHITE + 10:    // mniej jasny bia³y
        case MTL_WARMISH_WHITE + 10:        // ciep³y bia³y
        case MTL_COOLISH_WHITE + 10:        // zimny bia³y
        case MTL_BLACK_PLASTIC + 10:        // czarny plastik
        case MTL_CYAN_PLASTIC + 10:         // niebieskozielony plastik
        case MTL_GREEN_PLASTIC + 10:        // zielony plastik
        case MTL_RED_PLASTIC + 10:          // czerwony plastik
        case MTL_WHITE_PLASTIC + 10:        // bia³y plastik
        case MTL_YELLOW_PLASTIC + 10:       // ¿ó³ty plastik
        case MTL_BLACK_RUBBER + 10:         // czarna guma
        case MTL_CYAN_RUBBER + 10:          // niebieskozielona guma
        case MTL_GREEN_RUBBER + 10:         // zielona guma
        case MTL_RED_RUBBER + 10:           // czerwona guma
        case MTL_WHITE_RUBBER + 10:         // bia³a guma
        case MTL_YELLOW_RUBBER + 10:        // ¿ó³ta guma
            material = value - 10;
            break;

        // wyjœcie
        case EXIT:
            exit( 0 );
    }

    // odrysowanie okna
    glutPostRedisplay();
}

//////////////////////////////////////////////////////////////////////
// obs³uga renderingu sceny 3D i zamiany buforów renderingu
//////////////////////////////////////////////////////////////////////
void Display()
{
    // rendering sceny
    DisplayScene();

    // sprawdzenie b³êdów
    GLenum error = glGetError();
    switch( error )
    {
        case GL_CONTEXT_LOST:
            std::cout << "GL_CONTEXT_LOST" << std::endl;
            exit( 1 );
        case GL_INVALID_ENUM:
            std::cout << "GL_INVALID_ENUM" << std::endl;
            exit( 1 );
        case GL_INVALID_VALUE:
            std::cout << "GL_INVALID_ENUM" << std::endl;
            exit( 1 );
        case GL_INVALID_OPERATION:
            std::cout << "GL_INVALID_ENUM" << std::endl;
            exit( 1 );
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            std::cout << "GL_INVALID_ENUM" << std::endl;
            exit( 1 );
        case GL_OUT_OF_MEMORY:
            std::cout << "GL_INVALID_ENUM" << std::endl;
            exit( 1 );
        case GL_STACK_OVERFLOW:
            std::cout << "GL_STACK_OVERFLOW" << std::endl;
            exit( 1 );
        case GL_STACK_UNDERFLOW:
            std::cout << "GL_STACK_UNDERFLOW" << std::endl;
            exit( 1 );
        case GL_NO_ERROR:
            break;
    }

    // zamiana buforów koloru
    glutSwapBuffers();
}

//////////////////////////////////////////////////////////////////////
// program g³ówny
//////////////////////////////////////////////////////////////////////
int main( int argc, char *argv[] )
{
    // inicjalizacja biblioteki FreeGLUT
    glutInit( &argc, argv );

    // inicjalizacja bufora ramki
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

    // utworzenie kontekstu renderingu OpenGL
    glutInitContextVersion( 4, 1 );
    glutInitContextProfile( GLUT_CORE_PROFILE );

    // rozmiary g³ównego okna programu
    glutInitWindowSize( 500, 500 );

    // utworzenie g³ównego okna programu
    glutCreateWindow( "Mapy cieni (PCF)" );

    // inicjalizacja biblioteki GLEW
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if( GLEW_OK != err )
    {
        std::cout << "Niepoprawna inicjalizacja biblioteki GLEW" << std::endl;
        return 1;
    }

    // sprawdzenie dostêpnoœci wybranej wersji OpenGL
    if( !GLEW_VERSION_4_1 )
    {
        std::cout << "Brak OpenGL 4.1" << std::endl;
        return 1;
    }
    glGetError();

    // utworzenie podmenu "Filtr powiêkszaj¹cy/pomniejszaj¹cy tekstury g³êbokoœci"
    int menuFilter = glutCreateMenu( Menu );
    glutAddMenuEntry( "GL_NEAREST", MIN_MAX_FILTER_NEAREST );
    glutAddMenuEntry( "GL_LINEAR (PCF 2×2)", MIN_MAX_FILTER_LINEAR );

    // utworzenie podmenu "Filtracja mapy cienia"
    int menuShadowMode = glutCreateMenu( Menu );
    glutAddMenuEntry( "Brak", SHADOW_MAP_STD );
    glutAddMenuEntry( "PCF 3×3 z filtracja usredniajaca", SHADOW_MAP_PCF_3X3_AVERAGE );
    glutAddMenuEntry( "PCF 3×3 z filtracja Gaussa", SHADOW_MAP_PCF_3X3_GAUSS );
    glutAddMenuEntry( "PCF 5×5 z filtracja usredniajaca", SHADOW_MAP_PCF_5X5_AVERAGE );
    glutAddMenuEntry( "PCF 5×5 z filtracja Gaussa", SHADOW_MAP_PCF_5X5_GAUSS );
    glutAddMenuEntry( "PCF 5×5 z losowym polozeniem probek", SHADOW_MAP_PCF_5X5_RANDOM );
    glutAddMenuEntry( "PCF 5×5 z rozkladem Poissona polozenia probek", SHADOW_MAP_PCF_5X5_POISSON );

    // utworzenie podmenu "Rozmiar mapy cienia"
    int menuDepthMap = glutCreateMenu( Menu );
    glutAddMenuEntry( "256×256", FRAME_BUFFER_256_256 );
    glutAddMenuEntry( "512×512", FRAME_BUFFER_512_512 );
    glutAddMenuEntry( "1024×1024", FRAME_BUFFER_1024_1024 );
    glutAddMenuEntry( "2048×2048", FRAME_BUFFER_2048_2048 );

    // utworzenie podmenu "Materia³"
    int menuMaterial = glutCreateMenu( Menu );
    glutAddMenuEntry( "default", MTL_DEFAULT + 10 );
    glutAddMenuEntry( "Brass", MTL_BRASS + 10 );
    glutAddMenuEntry( "Bronze", MTL_BRONZE + 10 );
    glutAddMenuEntry( "Polished Bronze", MTL_POLISHED_BRONZE + 10 );
    glutAddMenuEntry( "Chrome", MTL_CHROME + 10 );
    glutAddMenuEntry( "Copper", MTL_COPPER + 10 );
    glutAddMenuEntry( "Polished Copper", MTL_POLISHED_COPPER + 10 );
    glutAddMenuEntry( "Gold", MTL_GOLD + 10 );
    glutAddMenuEntry( "Polished Gold", MTL_POLISHED_GOLD + 10 );
    glutAddMenuEntry( "Pewter", MTL_PEWTER + 10 );
    glutAddMenuEntry( "Silver", MTL_SILVER + 10 );
    glutAddMenuEntry( "Polished Silver", MTL_POLISHED_SILVER + 10 );
    glutAddMenuEntry( "Emerald", MTL_EMERALD + 10 );
    glutAddMenuEntry( "Jade", MTL_JADE + 10 );
    glutAddMenuEntry( "Obsidian", MTL_OBSIDIAN + 10 );
    glutAddMenuEntry( "Pearl", MTL_PEARL + 10 );
    glutAddMenuEntry( "Ruby", MTL_RUBY + 10 );
    glutAddMenuEntry( "Turquoise", MTL_TURQUOISE + 10 );
    glutAddMenuEntry( "Bright White", MTL_BRIGHT_WHITE + 10 );
    glutAddMenuEntry( "Less Bright White", MTL_LESS_BRIGHT_WHITE + 10 );
    glutAddMenuEntry( "Warmish White", MTL_WARMISH_WHITE + 10 );
    glutAddMenuEntry( "Coolish White", MTL_COOLISH_WHITE + 10 );
    glutAddMenuEntry( "Black Plastic", MTL_BLACK_PLASTIC + 10 );
    glutAddMenuEntry( "Cyan Plastic", MTL_CYAN_PLASTIC + 10 );
    glutAddMenuEntry( "Green Plastic", MTL_GREEN_PLASTIC + 10 );
    glutAddMenuEntry( "Red Plastic", MTL_RED_PLASTIC + 10 );
    glutAddMenuEntry( "White Plastic", MTL_WHITE_PLASTIC + 10 );
    glutAddMenuEntry( "Yellow Plastic", MTL_YELLOW_PLASTIC + 10 );
    glutAddMenuEntry( "Black Rubber", MTL_BLACK_RUBBER + 10 );
    glutAddMenuEntry( "Cyan Rubber", MTL_CYAN_RUBBER + 10 );
    glutAddMenuEntry( "Green Rubber", MTL_GREEN_RUBBER + 10 );
    glutAddMenuEntry( "Red Rubber", MTL_RED_RUBBER + 10 );
    glutAddMenuEntry( "White Rubber", MTL_WHITE_RUBBER + 10 );
    glutAddMenuEntry( "Yellow Rubber", MTL_YELLOW_RUBBER + 10 );

    // utworzenie menu kontekstowego
    glutCreateMenu( Menu );

    // dodanie pozycji do menu kontekstowego
    glutAddMenuEntry( "Rendering sceny", RENDER_SCENE );
    glutAddMenuEntry( "Rendering mapy cieni", RENDER_SHADOW_MAP );
    glutAddSubMenu( "Filtr powiekszajacy/pomniejszajacy tekstury glebokosci", menuFilter );
    glutAddSubMenu( "Filtracja mapy cienia", menuShadowMode );
    glutAddSubMenu( "Rozmiar mapy cienia", menuDepthMap );
    glutAddSubMenu( "Material", menuMaterial );
    glutAddMenuEntry( "Wyjscie", EXIT );

    // okreœlenie przycisku myszy obs³uguj¹cego menu kontekstowe
    glutAttachMenu( GLUT_RIGHT_BUTTON );

    // obs³uga przycisków myszy
    glutMouseFunc( MouseButton );

    // obs³uga ruchu kursora myszy
    glutMotionFunc( MouseMotion );

    // obs³uga klawiatury
    glutKeyboardFunc( Keyboard );

    // obs³uga klawiszy funkcyjnych i klawiszy kursora
    glutSpecialFunc( SpecialKeys );

    // inicjalizacja elementów sceny 3D
    InitScene();

    // do³¹czenie funkcji generuj¹cej scenê 3D
    glutDisplayFunc( Display );

    // do³¹czenie funkcji wywo³ywanej przy zmianie rozmiaru okna
    glutReshapeFunc( Reshape );

    // obs³uga pêtli komunikatów
    glutMainLoop();

    // usuniêcie elementów sceny 3D
    DeleteScene();

    // koniec
    return 0;
}
