#include "raylib.h"


const int WINDOW_WIDTH_ORIGIN{0};
const int WINDOW_WIDTH{800};
const int WINDOW_HEIGHT_ORIGIN{0};
const int WINDOW_HEIGHT{450};
const char *WINDOW_TITLE{"Ashfaque's Window"};
const int TARGET_FPS{60};
const char *GAME_OVER{"Game Over!"};
const int GAME_OVER_FONT_SIZE{20};


int main() {
    InitWindow(WINDOW_WIDTH,WINDOW_HEIGHT,WINDOW_TITLE);

    int circle_x{200};
    int circle_y{200};
    const int CIRCLE_RADIUS{25};

    // Circle Edges
    int l_circle_x{circle_x-CIRCLE_RADIUS};
    int r_circle_x{circle_x+CIRCLE_RADIUS};
    int u_circle_y{circle_y-CIRCLE_RADIUS};
    int b_circle_y{circle_y+CIRCLE_RADIUS};

    int axe_x{400};
    int axe_y{0};
    const int RECTANGLE_WIDTH{50};
    const int RECTANGLE_HEIGHT{50};

    // Axe Edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x+RECTANGLE_WIDTH};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y+RECTANGLE_HEIGHT};

    int direction{10};

    bool collision_with_axe{
                    (b_axe_y >= u_circle_y)
                and (u_axe_y <= b_circle_y)
                and (r_axe_x >= l_circle_x)
                and (l_axe_x <= r_circle_x)
    };

    SetTargetFPS(TARGET_FPS);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        if(collision_with_axe){
            DrawText(GAME_OVER,WINDOW_WIDTH/2,WINDOW_HEIGHT/2,GAME_OVER_FONT_SIZE,RED);
        } else {

            // Update the edges

            l_circle_x=circle_x-CIRCLE_RADIUS;
            r_circle_x=circle_x+CIRCLE_RADIUS;
            u_circle_y=circle_y-CIRCLE_RADIUS;
            b_circle_y=circle_y+CIRCLE_RADIUS;

            l_axe_x=axe_x;
            r_axe_x=axe_x+RECTANGLE_WIDTH;
            u_axe_y=axe_y;
            b_axe_y=axe_y+RECTANGLE_HEIGHT;

            // Update collision with Axe
            collision_with_axe=(b_axe_y >= u_circle_y)
            and (u_axe_y <= b_circle_y)
            and (r_axe_x >= l_circle_x)
            and (l_axe_x <= r_circle_x);

            DrawCircle(circle_x,circle_y,CIRCLE_RADIUS,BLUE);

            if(IsKeyDown(KEY_D) and circle_x < WINDOW_WIDTH){
                circle_x+=10;
            }

            if(IsKeyDown(KEY_A) and circle_x > WINDOW_WIDTH_ORIGIN){
                circle_x-=10;
            }

            DrawRectangle(axe_x,axe_y,RECTANGLE_WIDTH,RECTANGLE_HEIGHT,RED);

            axe_y+=direction;

            if(axe_y > WINDOW_HEIGHT or axe_y < WINDOW_HEIGHT_ORIGIN) {
                direction=-direction;
            }

        }

        EndDrawing();

    }

    return 0;
}
