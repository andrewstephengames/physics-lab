/*
 * Simple raylib setup with all the jazz
*/
#include <raylib.h>

const float factor = 50;
Vector2 window = { 16*factor, 9*factor };

int main (void) {
    SetConfigFlags (FLAG_WINDOW_RESIZABLE);
    SetConfigFlags (FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    const char* text = "Hello World";
    const float fontSize = 100;
    InitWindow (window.x, window.y, text);
    while (!WindowShouldClose()) {
        window.x = GetRenderWidth();
        window.y = GetRenderHeight();
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText (
                text,
                window.x/2-(float)MeasureText(text, fontSize)/2,
                window.y/2-fontSize/2,
                fontSize,
                LIME
            );
        EndDrawing();
	if (IsKeyPressed (KEY_Q))
	    break;
    }
    CloseWindow();
    return 0;
}
