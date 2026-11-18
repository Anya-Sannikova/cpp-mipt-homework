
struct color
{
    unsigned char r, g, b;
};

typedef struct color Color;

void draw_circle(Color* data, int width, int height, int x0, int y0, int r, Color c) {
    for (int j = y0 - r; j <= y0 + r; j++) {
        for (int i = x0 - r; i <= x0 + r; i++) {
            if (i >= 0 && i < width && j >= 0 && j < height) {
                int dx = i - x0;
                int dy = j - y0;
                if (dx * dx + dy * dy <= r * r) {
                    data[i + width * j] = c;
                }
            }
        }
    }
}
